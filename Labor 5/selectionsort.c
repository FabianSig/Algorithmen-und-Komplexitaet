#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 256

long long GetUSecClock(){
    clock_t cputime = clock();
    return (long long) cputime * 1000000/CLOCKS_PER_SEC;
}

void selection_sort(int *arr, int size){

    int min_i;
    int tmp;

    for(int i = 0; i < size; i++){
        min_i = i;

        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min_i]) min_i = j;
        }

        tmp = arr[min_i];
        arr[min_i] = arr[i];
        arr[i] = tmp;
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
    selection_sort(list, size);
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
