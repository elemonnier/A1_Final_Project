#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#ifndef PROGC_BOOK_H
#define PROGC_BOOK_H

struct Book{
    char* name;
    char* genre;
    char* author;
    char* page;

};

struct ListBook{
    struct Book* book;
    struct ListBook* next;
};

struct Book* createBook(char* cutted[]);//OK

struct ListBook* createListBook(struct Book* B);//OK

bool isListBookEmpty(struct ListBook* L);//OK

struct ListBook* insertBookinListAuthor(struct ListBook* L, struct Book* B);//voir fonction mat

struct ListBook* getLast(struct ListBook* L, struct Book* book);//voir si garder

struct ListBook* getPrevious(struct ListBook* main, struct ListBook* search);

void displayBook(struct Book* B);

void displayListBook(struct ListBook* L);

void displayBookList(struct ListBook* listBooks);


#endif //PROGC_BOOK_H
