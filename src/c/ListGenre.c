#include "ListGenre.h"

struct Genre* createEmptyGenre(){
    struct Genre* new = (struct Genre*)malloc(sizeof(struct Genre));
    if(new!= NULL) {
        new->next = NULL;
        //new->NameGenre;
        new->liste = NULL;
    }
    return new;
}

bool isGenreEmpty(struct Genre* G){
    return G == NULL;

}
char* tolowerCaseString(char* letter){
    for(int i=0; i< strlen(letter);i++) {
        if (letter[i] >= 65 && letter[i] <= 90) {
            letter[i] = (char)(letter[i] + 32);
        }
    }
    return letter;
}
void insertBookinGenre(struct Genre* G, struct Book* B){
    struct Genre* ptr = G;

    if(G->liste == NULL){
        G->NameGenre=B->genre;
        G->liste = insertBookinListGenre(G->liste,B);
    } else if(strcmp(G->NameGenre,B->genre)==0){
        if(G->liste->book->name == NULL){
            G->liste=NULL;
        }
        G->liste = insertBookinListGenre(G->liste,B);
    } else{
        if(ptr->next == NULL){
            ptr->next = createEmptyGenre();
        }
        insertBookinGenre(ptr->next,B);
    }
}
struct ListBook* moveToPosition(struct ListBook* listBooks, struct Book* book) { //Permet de se rendre à la position désirée dans une liste chainée
    if(listBooks->next == NULL){
        return listBooks;
    } else {
        if(strcmp(book->author, listBooks->next->book->author)<0){
            return listBooks;
        } else {
            return moveToPosition(listBooks->next, book);
        }
    }
}
struct ListBook* insertBookinListGenre(struct ListBook* L, struct Book* B){
    struct ListBook* pointer = L;
    struct ListBook* newListBooks;
    struct ListBook* tmp_pointer;

    if((newListBooks = createListBook(B)) == NULL){
        free(newListBooks);
        return L;
    }

    if(L==NULL){
        return newListBooks;
    } else if(strcmp(B->author, L->book->author)<0 || strcmp(B->author, L->book->author)==0){
        tmp_pointer=L;
        L= newListBooks;
        L->next=tmp_pointer;
    } else {
        pointer=moveToPosition(pointer, B);
        if(pointer==NULL){
            tmp_pointer=pointer;
            newListBooks->next=tmp_pointer;
        } else {
            tmp_pointer = pointer->next;
            newListBooks->next=tmp_pointer;
            pointer->next=newListBooks;
        }
    }
    return L;


}
void deleteGenre(struct Genre* G){
    if(G != NULL) {
        struct Genre*temp = G;
        while (temp->next != NULL) {
            temp = temp->next;
            if (G->liste != NULL) {
                deleteListBookGenre(G->liste);
                G->liste = NULL;
            }
            free(G);
            G = temp;
        }
        if (G->next == NULL) {
            deleteListBookGenre(G->liste);
            G->liste = NULL;
        }
        free(G);
    }
}
void deleteListBookGenre(struct ListBook* L){
    if(L != NULL) {
        struct ListBook *temp = L;
        while (temp->next != NULL) {
            temp = temp->next;
            if (L->book != NULL) {
                L->book = NULL;
            }
            free(L);
            L = temp;
        }
        if (L->next == NULL) {
            L->book = NULL;
        }
        free(L);
    }
}
void MatchBookofGenre(char* nameGenre,struct Genre* G){
    struct Genre* ptr = G;
    while(ptr->NameGenre != nameGenre && ptr->next == NULL){
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        printf("ce genre n'existe pas");
    }
    else{
        printf("%s =\n",ptr->NameGenre);
        displayBookList(ptr->liste);
    }
}

void displayCategoriesList(struct Genre* listCategories){
    while(listCategories!=NULL){
        printf("> %s :\n\n", listCategories->NameGenre);
        displayBookList(listCategories->liste);
        listCategories=listCategories->next;
    }
}

void displayBookList(struct ListBook* listBooks){
    while(listBooks!=NULL){
        struct Book* book=listBooks->book;
        printf("      Author: %s\n", book->author);
        printf("      Title: %s\n", book->name);
        printf("      Number of pages: %s\n", book->page);
        printf("      Category: %s\n", book->genre);
        printf("\n");
        listBooks=listBooks->next;
    }
}

void searchBook(struct Genre* G, char* NameBook, FILE* result){

}

void searchByGenre(struct Genre* G, char* NameGenre, FILE* result){
    while (G !=NULL){
        if(strcasecmp(NameGenre, G->NameGenre)==0) {
            while (G->liste != NULL) {
                fprintf(result, "%s", G->liste->book->author);
                fputs(";", result);
                fprintf(result, "%s", G->liste->book->name);
                fputs(";", result);
                fprintf(result, "%s", G->liste->book->page);
                fputs(";", result);
                fprintf(result, "%s", G->liste->book->genre);
                fputs("\r\n", result);

                G->liste = G->liste->next;
            }
        }
        G=G->next;
    }
}