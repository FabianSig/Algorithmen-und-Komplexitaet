#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {

    FILE *fp = fopen(argv[1], "r");
    int count = 0;

    if (fp == NULL)  fp = stdin;

    char buffer[50][500];

    char l[500];

    while (fgets(l, sizeof(l), fp)) {

        strcpy(buffer[count++], l);
    }
    fclose(fp);

    while(count >= 0){
        printf("%s", buffer[count--]);
    }
}
