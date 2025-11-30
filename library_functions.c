#include "library.h" 

struct books bookrecords;
struct student studentrecords;
FILE *file_pointer;

/* ---------- ISSUE BOOK ---------- */
void issue_book() {
    clearScreen();
    printf("<<----- Issue Book ----->>\n\n");

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(studentrecords.issue_date, "%02d/%02d/%d",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    tm.tm_mday += 10;
    mktime(&tm);

    sprintf(studentrecords.due_date, "%02d/%02d/%d",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    printf("Enter Book ID: ");
    scanf("%d", &studentrecords.id);
    getchar();

    file_pointer = fopen("books.txt", "rb");
    if (!file_pointer) {
        printf("No books available.\n");
        return;
    }

    int found = 0;

    while (fread(&bookrecords, sizeof(bookrecords), 1, file_pointer) == 1) {
        if (bookrecords.id == studentrecords.id) {
            strcpy(studentrecords.book_name, bookrecords.book_name);
            found = 1;
            break;
        }
    }

    fclose(file_pointer);

    if (!found) {
        printf("Book not found.\n");
        return;
    }

    file_pointer = fopen("issue.txt", "ab");

    printf("Enter Student Name: ");
    fgets(studentrecords.student_name, 100, stdin);
    trim(studentrecords.student_name);

    printf("Enter Student Class: ");
    fgets(studentrecords.student_class, 20, stdin);
    trim(studentrecords.student_class);

    printf("Enter Student Roll No: ");
    scanf("%d", &studentrecords.student_rollno);
    getchar();

    fwrite(&studentrecords, sizeof(studentrecords), 1, file_pointer);
    fclose(file_pointer);

    printf("\nBook Issued Successfully!\n");
    printf("Issue Date: %s\n", studentrecords.issue_date);
    printf("Due Date : %s\n", studentrecords.due_date);
}
/* ---------- ADD BOOK ---------- */

void add_book() {
    clearScreen();
    printf("<<----- Add New Book ----->>\n\n");

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(bookrecords.date, "%02d/%02d/%d",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    file_pointer = fopen("books.txt", "ab");

    printf("Enter Book Name: ");
    fgets(bookrecords.book_name, 100, stdin);
    trim(bookrecords.book_name);

    printf("Enter Book ID: ");
    scanf("%d", &bookrecords.id);
    getchar();

    printf("Enter Author Name: ");
    fgets(bookrecords.author_name, 100, stdin);
    trim(bookrecords.author_name);

    fwrite(&bookrecords, sizeof(bookrecords), 1, file_pointer);
    fclose(file_pointer);

    printf("\nBook Added Successfully!\n");
}

/* ---------- DELETE BOOK ---------- */

void delete_book() {
    clearScreen();
    printf("<<----- Delete Book ----->>\n\n");

    int id, found = 0;

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    getchar();

    file_pointer = fopen("books.txt", "rb");
    if (!file_pointer) {
        printf("No books found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "wb");

    while (fread(&bookrecords, sizeof(bookrecords), 1, file_pointer) == 1) {
        if (bookrecords.id == id)
            found = 1;
        else
            fwrite(&bookrecords, sizeof(bookrecords), 1, temp);
    }

    fclose(file_pointer);
    fclose(temp);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        printf("Book deleted successfully.\n");
    else
        printf("Book not found.\n");
}
/* ---------- DISPLAY BOOKS LIST ---------- */

void display_books_list() {
    clearScreen();
    printf("<<----- Books List ----->>\n\n");

    file_pointer = fopen("books.txt", "rb");
    if (!file_pointer) {
        printf("No books available.\n");
        return;
    }

    printf("%-10s %-30s %-20s %-12s\n",
           "ID", "Book Name", "Author", "Added Date");

    while (fread(&bookrecords, sizeof(bookrecords), 1, file_pointer) == 1) {
        printf("%-10d %-30s %-20s %-12s\n",
               bookrecords.id, bookrecords.book_name,
               bookrecords.author_name, bookrecords.date);
    }

    fclose(file_pointer);
}

/* ---------- ISSUED BOOKS LIST ---------- */

void issued_books_list() {
    clearScreen();
    printf("<<----- Issued Books ----->>\n\n");

    file_pointer = fopen("issue.txt", "rb");
    if (!file_pointer) {
        printf("No books issued yet.\n");
        return;
    }

    printf("%-10s %-30s %-10s %-10s %-30s %-12s %-12s\n",
           "ID", "Student Name", "Class", "Roll",
           "Book Name", "Issue Date", "Due Date");

    while (fread(&studentrecords, sizeof(studentrecords), 1, file_pointer) == 1) {
        printf("%-10d %-30s %-10s %-10d %-30s %-12s %-12s\n",
               studentrecords.id, studentrecords.student_name,
               studentrecords.student_class, studentrecords.student_rollno,
               studentrecords.book_name, studentrecords.issue_date,
               studentrecords.due_date);
    }

    fclose(file_pointer);
}


