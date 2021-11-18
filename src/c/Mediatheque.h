#include "Author.h"
#include "ListGenre.h"

#define MAXSIZE 250
#ifndef PROGC_MEDIATHEQUE_H
#define PROGC_MEDIATHEQUE_H


void cut(char* Ligne[], char* fullString, int size,int nbr);//OK

void initMediatheque(struct NodeAuthor* A,struct Genre* G,FILE* file);//OK
//va mettre tout les BD du .txt dans notre mediathèque
//il insere dans l'arbre d'Auteur & dans la list de Genre

FILE* ReadRequest(FILE* file, struct NodeAuthor* TreeAuthor, struct Genre* ListGenre);

void sendResults(FILE* result,float time);

#endif //PROGC_MEDIATHEQUE_H
