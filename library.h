#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Structures
struct books {
    int id;
    char date[12]; //when the book was added
    char book_name[100];
    char author_name[100];
};
struct student {
    int id;
    char student_name[100];
    int student_rollno;
    char student_class[20];
    char book_name[100];
    char issue_date[12];
    char due_date[12];
};
//Global variables
extern struct books bookrecords;
extern struct student studentrecords;
extern FILE *file_pointer;
//Functions
void clearScreen();
void trim(char *s);

void add_book();
void delete_book();
void display_books_list();
void issue_book();
void issued_books_list();
#endif
