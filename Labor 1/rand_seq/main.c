#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXNUM 1000

int main(int argc, char *argv[]) {

    time_t ti;

    srand((unsigned) time(&ti));

    for(int i = 0 ; i < atoi(argv[1]) ; i++ ) {
        printf("%d\n", rand() % MAXNUM);
    }

    return 0;
}

