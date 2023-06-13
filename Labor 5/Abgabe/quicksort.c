#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 256

long long GetUSecClock(){
    clock_t cputime = clock();
    return (long long) cputime * 1000000/CLOCKS_PER_SEC;
}

int quicksort_part(int *arr, int low, int high){

    int tmp;

    int pivotindex = (low+high)/2;
    int pivotvalue = arr[pivotindex];

    tmp = arr[high];
    arr[high] = arr[pivotindex];
    arr[pivotindex] = tmp;

    int sp = low;

    for(int su = low; su < high; su++){
        if(arr[su]<pivotvalue){
            tmp = arr[sp];
            arr[sp++] = arr[su];
            arr[su] = tmp;
        }
    }

    tmp = arr[sp];
    arr[sp] = arr[high];
    arr[high] = tmp;

    return sp;

}


void quicksort(int *arr, int lo, int hi){

    int pivotindex;

    if(lo < hi){
        pivotindex = quicksort_part(arr, lo, hi);
        quicksort(arr, lo, pivotindex - 1);
        quicksort(arr, pivotindex + 1, hi);
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
    quicksort(list, 0, size);
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
