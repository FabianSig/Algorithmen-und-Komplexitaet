#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 256

long long GetUSecClock(){
    clock_t cputime = clock();
    return (long long) cputime * 1000000/CLOCKS_PER_SEC;
}

void bubblesort(int *arr, int size){
    int tmp;
    int swapped = 1;

    while(swapped){

        swapped = 0;

        for(int i = 0; i < size; i++){
            if(arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = 1;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    FILE *in = stdin;
    char line[MAXLINE];

    int size = 0;
    int *list = malloc( 100000* sizeof (int));

    long long time1, time2;



    if (argc > 2) {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2) {
        in = fopen(argv[1], "r");
        if (!in) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }


//Einlesen
    while (fgets(line, sizeof(line), in) != NULL) {
        list[size++] = atoi(line);
    }

    list = realloc(list, size * sizeof(int));

    time1 = GetUSecClock();
    bubblesort(list, size);
    time2 = GetUSecClock();

    for(int i = 0; i < size; i++){
        printf("%d\n", list[i]);
    }

    printf("Sortiert in %d ms", (time2-time1) / 1000);


    if (in != stdin) {
        fclose(in);
    }

    exit(EXIT_SUCCESS);
}
