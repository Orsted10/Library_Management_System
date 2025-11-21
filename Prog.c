#include <stdio.h>
#include <string.h>  // Include header for string functions

struct Student {
    char name;
    int age;
    char info;  // Changed from char to char array
};

void printProfile(struct Student s) {
    printf("------ Student Profile ------\n");
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Info: %s\n", s.info);
    printf("-----------------------------\n");
}

int main() {
    struct Student student;

    // Use strcpy to assign strings
    strcpy(student.name, "Arjun Singh");
    student.age = 20;
    strcpy(student.info, "Computer Science Major, enjoys robotics and music.");

    printProfile(student);

    return 0;
}
