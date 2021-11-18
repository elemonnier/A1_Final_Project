#include "Mediatheque.h"
#include <time.h>

int main() {


    float time;
    clock_t t1,t2;


    struct NodeAuthor* TreeAuthor = createEmptyNodeAuthor('#');
    struct Genre* ListGenre = createEmptyGenre();
    char wordAccum[MAX_LENGTH];
    FILE* doc = fopen("BD.txt","r");

    initMediatheque(TreeAuthor,ListGenre,doc);//la base de donnée

    FILE* request = fopen("../../transfere/request.txt", "r");

    while(request == NULL){

        printf("pas de request\n");
        request = fopen("../../transfere/request.txt", "r");

    }
    printf("request trouvé\n");
    t1 =clock();

    FILE * result;
    result = ReadRequest(request,TreeAuthor,ListGenre);

    t2 = clock();
    time = (float)(t2-t1)/CLOCKS_PER_SEC;//pour avoir le temps on fait dont une difference
    sendResults(result,time);
    remove("../../transfere/request.txt");
    remove("../../transfere/result.txt");
    remove("../../transfere/ready.txt");

    main();
}