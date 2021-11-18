#include "Book.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef PROGC_LISTGENRE_H
#define PROGC_LISTGENRE_H

struct Genre{
    char* NameGenre;
    struct ListBook* liste;
    struct Genre* next;
};


bool isGenreEmpty(struct Genre* G);//OK

struct Genre* createEmptyGenre();//OK

struct ListBook* insertBookinListGenre(struct ListBook* L, struct Book* B);//OK
//la fonction est differend de insertBookinListAuteur car le trie est en fct de l'auteur ici

void insertBookinGenre(struct Genre* G, struct Book* B);//OK

void deleteListBookGenre(struct ListBook* L);

void deleteGenre(struct Genre* G);
//supprimer toute la liste chainée

void searchByGenre(struct Genre* G, char* NameGenre, FILE* result);

void searchBook(struct Genre* G, char* NameBook, FILE* result);

void MatchBookofGenre(char* nameGenre,struct Genre* G);//a modifier pour ecrir dans le result

void displayCategoriesList(struct Genre* listCategories);//OK

void displayMatchBookofGenre(char* nameGenre,struct Genre* G);//OK


#endif //PROGC_LISTGENRE_H
