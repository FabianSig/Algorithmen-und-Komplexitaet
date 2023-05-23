#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)  fp = stdin;

    char l[500];

    while (fgets(l, sizeof(l), fp)) {
        printf("%d\n", atoi(l) * 2);
    }
    fclose(fp);
}
