#include "Mediatheque.h"

void initMediatheque(struct NodeAuthor* A,struct Genre* G,FILE* file){
    if(file==NULL) {
        printf("\nerror");
    }
    struct Book* book;
    int i = 1;
    while(!feof(file)){
        printf("%d\n",i);
        i++;
        char* cutted[4];
        char buffer[200];
        fgets(buffer, 200, file);
        cut(cutted,buffer,strlen(buffer),4);

        book = createBook(cutted);

        insertNodeAuthor(A,book);
        insertBookinGenre(G,book);

    }
    fclose(file);
}

void cut(char* Ligne[], char* fullString, int size,int nbr){
    int iteration = 0, level=0;
    for(int i = 0; i <nbr; i++){
        while(fullString[iteration]!=';' && iteration < size-2){
            iteration++;
        }
        Ligne[i] = (char*)malloc(iteration*sizeof(char));
        for(int u = 0; u < iteration-level; u++){
            Ligne[i][u]=fullString[level+u];
        }
        iteration++;
        level = iteration;
    }
}

FILE* ReadRequest(FILE* file, struct NodeAuthor* TreeAuthor, struct Genre* ListGenre){

    FILE * result = fopen("../../transfere/result.txt","w");
    char line[MAXSIZE];
    if (file ==NULL){
        printf("Error\n");
    } else {
        fgets(line, MAXSIZE, file);
        char *PremPart = strtok(line, ";");
        char *DeuxPart = strtok(NULL, ";");
        char *TroisPart = strtok(NULL, ";");
        char *QuatrePart = strtok(NULL, ";");
        char *CinqPart = strtok(NULL, ";");
//---------------------------DELETE-MEDIA--------------------------------------------
        if(strcmp(PremPart, "delete")==0){
            deleteNodeAuthor(TreeAuthor);
            TreeAuthor = NULL;
            deleteGenre(ListGenre);
            ListGenre = NULL;
            //baisle succes avec temps
        }
//-------------------------------VISUALISER -----------------------------------------
        if(strcmp(PremPart,"print")==0){
        //comme display all author;
        }
        if(strcmp(PremPart,""))
//-----------------------SEARCH BY ......-----------------------------------------
        if (strcmp(PremPart, "searchBy")== 0){

            if (strcmp(DeuxPart,"Auteur")==0) {
                searchAuthor(TreeAuthor,TroisPart,result);//Return les livres associé à l'auteur associé à la recherche
                return result;
            }
//            if (strcmp(DeuxPart,"Titre")==0){
//                struct Book* bookSearch = searchBook(ListGenre,TroisPart,file);//Return les caractéristiques du livre associé au nom du livre
//            }
            if (strcmp(DeuxPart,"Genre")==0){
                searchByGenre(ListGenre, TroisPart,result);//Return la liste de livre associé au genre écrit dans la barre
                return result;
            }

            if (strcmp(TroisPart, "Auteur")!= 0 && strcmp(TroisPart, "Livre")!=0 && strcmp(TroisPart, "Genre")!=0)
                printf("Ce que vous écrivez n'existe pas dans la Médiathèque !");
        }


//--------------------------------INSERT BOOK------------------------------------------------------

            if (strcmp(PremPart, "newBook")== 0){
                char* cutted[4];
                cutted[0] = DeuxPart;
                cutted[1] = TroisPart;
                cutted[2] = QuatrePart;
                cutted[3] = CinqPart;
                struct Book* book = createBook(cutted);

                insertNodeAuthor(TreeAuthor,book);
                insertBookinGenre(ListGenre,book);
                char* msg = "success";
                fprintf(result, "%s", msg);
                return result;
            }
            remove("../../transfere/request.txt");
    }
}

void sendResults(FILE* result,float time){//créer le fichier result
//    fseek(result,0,0);
//    fprintf(result,"%f",time);
//    fputs("\n",result);
    FILE* ready = fopen("../../transfere/ready.txt","w");
}