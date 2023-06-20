#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 256

long long GetUSecClock(){
    clock_t cputime = clock();
    return (long long) cputime * 1000000/CLOCKS_PER_SEC;
}

int* mergsort(int *arr, int size){

    if(size <= 1 ) return arr;

    int size_arr1 = (size/2);
    int size_arr2 = (size-(size/2));

    int *arr1 = malloc(sizeof(int)*size_arr1);
    int *arr2 = malloc(sizeof(int)*size_arr2);

    for(int i = 0; i < size_arr1; i++){
        arr1[i] = arr[i];
    }

    for(int i = 0; i < size_arr2; i++){

        arr2[i] = arr[i + size_arr1];
    }

    mergsort(arr1, size_arr1);
    mergsort(arr2, size_arr2);

    int e1 = 0;
    int e2 = 0;

    for(int i = 0; i < size; i++){
        if(e1 >= size_arr1) arr[i] = arr2[e2++];
        else if(e2 >= size_arr2) arr[i] = arr1[e1++];
        else if(arr1[e1] <= arr2[e2]) arr[i] = arr1[e1++];
        else arr[i] = arr2[e2++];
    }

    return arr;
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
    int * array = mergsort(list, size);
    time2 = GetUSecClock();

    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }

    printf("Sortiert in %d ms", (time2-time1) / 1000);


    if (in != stdin) {
        fclose(in);
    }

    exit(EXIT_SUCCESS);
}
