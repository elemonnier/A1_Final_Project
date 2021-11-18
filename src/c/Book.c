#include "Book.h"

struct Book* createBook(char* cutted[]){
    struct Book* new = (struct Book*)malloc(sizeof(struct Book));
    new->author = cutted[0];
    new->name = cutted[1];
    new->page = cutted[2];
    new->genre = cutted[3];
    return new;
}
struct ListBook*  createListBook(struct Book* B){
    struct ListBook* new = (struct ListBook*)malloc(sizeof(struct ListBook));
    new->next = NULL;
    new->book = B;
    return new;
}
bool isBookEmpty(struct Book* B){
    return B == NULL;
}
void displayBook(struct Book* B){
    if(!isBookEmpty(B)) {
        printf("book = %s by %s in %s and %s pages\n",B->name,B->author,B->genre,B->page);
    }
    else{
        printf("Votre livre est vide");
    }
}
void displayListBook(struct ListBook* L){
    if(L!=NULL){
        while(L!=NULL){
            displayBook(L->book);
            L = L->next;
        }
        printf("\n");
    }
    else{
        printf("vide\n");
    }
}
bool isListBookEmpty(struct ListBook* L){
    if(L != NULL) {
        if (L->book == NULL || L->next == NULL) {
            return true;
        }
        return false;
    }
    return true;
}
struct ListBook* insertBookinListAuthor(struct ListBook* L, struct Book* B){
    struct ListBook* newList = createListBook(B);


    if(L==NULL){
        L = newList;
        L->book = B;
        L->next = NULL;
        return L;
    }

    struct ListBook* newBook=createListBook(B);
    struct ListBook* ptrCell = L;
    char* title = B->name;
    int i=0;

    while(i<strlen(title) && i<strlen(ptrCell->book->name) && title[i]>=ptrCell->book->name[i]){
        while(i<strlen(title) && i<strlen(ptrCell->book->name) && title[i]==ptrCell->book->name[i]){
            i++;
        }
        if(ptrCell->next == NULL){
            if(title[i]>=ptrCell->book->name[i]){
                ptrCell->next = newBook;
                return L;
            }
            if(title[i]< ptrCell->book->name[i]){
                if(L->next == NULL){
                    struct ListBook* tpm0 = getLast(L,B);
                    L =tpm0;
                    return L;
                }
                struct ListBook* tmp1 = getLast(L,B);
                tmp1->next = newBook;
                newBook->next = ptrCell;
                return L;
            }
        }
        if(title[i] < ptrCell->book->name[i]){
            struct ListBook* tmp2 = getPrevious(L,ptrCell);
            newBook->next = ptrCell;
            tmp2->next = newBook;
            return L;
        }
        if(title[i] >= ptrCell->book->name[i]){
            ptrCell = ptrCell->next;
            i=0;
        }
        if(ptrCell->next == NULL){
            newBook->next = L;
            L = newBook;
            return L;
        }
    }
}


struct ListBook* getPrevious(struct ListBook* main, struct ListBook* search){
    struct ListBook* ptr = main;
        while (ptr->next != search && ptr->next ==NULL) {
            ptr = ptr->next;
        }
        return ptr;
}
struct ListBook* getLast(struct ListBook* listBook, struct Book* B){
    struct ListBook* ptr =listBook;
    if (ptr->next == NULL){
        struct ListBook* new = createListBook(B);
        new->next=ptr;
        listBook =new;
        return listBook;
    }
    while (ptr->next->next != NULL){
        ptr =ptr ->next;
    }
    return listBook;
}

void deleteListBookAuthor(struct ListBook* L){
    if(L != NULL) {

        struct ListBook *temp = L;
        while (temp->next != NULL) {
            temp = temp->next;
            if (L->book != NULL) {
                free(L->book->author);
                free(L->book->name);
                free(L->book->genre);
                free(L->book->page);
                free(L->book);
                L->book = NULL;
            }
            free(L);
            L = temp;
        }
        if (L->next == NULL) {
            free(L->book->author);
            free(L->book->name);
            free(L->book->genre);
            free(L->book->page);
            free(L->book);
            L->book = NULL;
            free(L);
            L=NULL;
        }

    }
}