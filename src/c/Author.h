#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Book.h"

#define MAX_LENGTH 28 //car alphabet + '\''+ ' '
#define charToIndex(c) ((int)(c-'a'))

#ifndef PROGC_ARBREAUTEUR_H
#define PROGC_ARBREAUTEUR_H


struct NodeAuthor{
    char letterName;
    bool isAuthor;
    struct NodeAuthor* son[MAX_LENGTH];
    struct ListBook* bibliographie;
};

struct NodeAuthor* createEmptyNodeAuthor(char letter);//OK

void insertNodeAuthor(struct NodeAuthor* A, struct Book* B);//OK

void deleteNodeAuthor(struct NodeAuthor*A);//OK
//elle va supprimer tout l'arbre

void deleteListBookAuthor(struct ListBook* L);

void displayBookinAuthor(struct NodeAuthor* A,char* NameAuthor);//a modifier pour qu'i ecrive dans le result

void displayAllAuthor(struct NodeAuthor* A,char* wordAccum,int level);//OK
//ca les display dans l'ordre alphabetique

bool isNodeAuthorEmpty(struct NodeAuthor* A);

void searchAuthor(struct NodeAuthor* A, char* NameAuthor,FILE* result);

void MatchBookofAuthor(char* nameAuthor,struct NodeAuthor* A);







#endif //PROGC_ARBREAUTEUR_H
