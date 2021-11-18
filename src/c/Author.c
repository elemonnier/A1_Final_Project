#include "Author.h"

struct NodeAuthor* createEmptyNodeAuthor(char letter){
    struct NodeAuthor *new = (struct NodeAuthor*) malloc(sizeof(struct NodeAuthor));
    new->letterName = letter;
    new->isAuthor = false;
    new->bibliographie = NULL;
    for (int i = 0; i <MAX_LENGTH; i++) {
        new->son[i] = NULL;
    }
    return new;
}
char tolowerCase(char letter){
    if(letter >= 65 && letter <= 90){
        return (char) (letter + 32);
    }
    return letter;
}
int chartoIndex(char l){
    if(l==' '){
        return 27;
    }
    if(l=='\''){
        return 26;
    }
    if(l-'a' >=0 && l-'a'<=26){
        return l-'a';
    }
    return l;
}

void insertNodeAuthor(struct NodeAuthor* A, struct Book* B) {
    for (int i = 0; i < strlen(B->author); i++) {
        if (A->son[chartoIndex(tolowerCase(B->author[i]))] == NULL) {
            A->son[chartoIndex(tolowerCase(B->author[i]))] = createEmptyNodeAuthor(B->author[i]);
        }
        A = A->son[chartoIndex(tolowerCase(B->author[i]))];
    }
    A->isAuthor = true;
    if(isListBookEmpty(A->bibliographie)){
        A->bibliographie = createListBook(B);

    } else {
        A->bibliographie = insertBookinListAuthor(A->bibliographie, B);
    }
}

void deleteNodeAuthor(struct NodeAuthor*A){
    if(A!=NULL){
        for(int i = 0;i<MAX_LENGTH;i++){
            if(A->isAuthor){
                deleteListBookAuthor(A->bibliographie);
                A->bibliographie = NULL;
                A->isAuthor = false;
            }
            if(A->son[i]!=NULL){
                deleteNodeAuthor(A->son[i]);
                A->isAuthor = false;
            }
            }
        free(A);
        }
}
void displayAllAuthor(struct NodeAuthor* A,char* wordAccum,int level){
    if (A->isAuthor) {
        for (int j = 0; j < level; j++){
            printf("%c", wordAccum[j]);
        }
        printf("\n");
    }
    for (int i = 0; i <MAX_LENGTH; i++){
        if (A->son[i]!=NULL) {
            wordAccum[level] = A->son[i]->letterName;
            displayAllAuthor(A->son[i], wordAccum, level + 1);
        }
    }
}
void displayBookinAuthor(struct NodeAuthor* A,char* NameAuthor){


}
bool isNodeAuthorEmpty(struct NodeAuthor* A){
    if(A!=NULL){
        if(A->letterName == NULL){
            return true;
        }
        return false;
    }
    return true;
}
void MatchBookofAuthor(char* NameAuthor,struct NodeAuthor* A){
    if(!isNodeAuthorEmpty(A)) {
        for (int i = 0; i < strlen(NameAuthor); i++) {
            if (A->son[chartoIndex(tolowerCase(NameAuthor[i]))] == NULL) {
                printf("cet autheur n'exhiste pas dans l'arbre\n");
            }
            A = A->son[chartoIndex(tolowerCase(NameAuthor[i]))];
        }
        printf("cet auteur a ecrit\n");
        displayListBook(A->bibliographie);
    }
}
void searchAuthor(struct NodeAuthor* A, char* NameAuthor,FILE* result){
    for(int i =0;i< strlen(NameAuthor);i++){
        if(A->son[chartoIndex(NameAuthor[i])]==NULL){
            char* msg = "pas l'auteur dans le trie";
            fprintf(result, "%s", msg);
        }
        A=A->son[chartoIndex(NameAuthor[i])];
    }
    if(A->isAuthor){
        while (A->bibliographie != NULL) {
            fprintf(result, "%s", A->bibliographie->book->author);
            fputs(";", result);
            fprintf(result, "%s", A->bibliographie->book->name);
            fputs(";", result);
            fprintf(result, "%s", A->bibliographie->book->page);
            fputs(";", result);
            fprintf(result, "%s", A->bibliographie->book->genre);
            fputs("\n", result);
            A->bibliographie = A->bibliographie->next;
        }
    }
}
