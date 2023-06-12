#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256


typedef struct lin_list {
    char *payload;
    struct lin_list *next;
} LinListCell, *LinList_p;


LinList_p LinListAllocCell(char *payload) {
/* fill in here, hint: use malloc and strdup*/
    LinList_p test = malloc(sizeof(LinListCell));
    test->next = NULL;
    test->payload = strdup(payload);
    return test;
}


void LinListFreeCell(LinList_p junk) {
    free(junk->payload);
    free(junk);
}


void LinListFree(LinList_p junk) {
    LinList_p next;

    while (junk) {
        next = junk->next;
        LinListFreeCell(junk);
        junk = next;
    }
}


LinList_p LinListInsertFirst(LinList_p *anchor, LinList_p newcell) {
/* fill in here*/
    newcell->next = *anchor;
    *anchor = newcell;
    return *anchor;
}


LinList_p LinListExtractFirst(LinList_p *anchor) {
/* fill in here*/
    if (*anchor == NULL) return NULL;
    LinList_p first = *anchor;
    *anchor = first->next;
    first->next = NULL;
    return first;
}




int main(int argc, char *argv[]) {
    FILE *in = stdin;
    char line[MAXLINE];
    LinList_p l1 = NULL, l2 = NULL, handle;
    char *inp;

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


/* fill in here*/

//Einlesen
    while (fgets(line, sizeof(line), in) != NULL) {
        LinList_p newC = LinListAllocCell(line);
        LinListInsertFirst(&l1, newC);
    }

    printf("Sorted:\n");
//Sort
    int swapped;
    LinList_p p1 = l1;
    LinList_p p2 = l1->next;
    char tmp[MAXLINE];
    while(p2){
        if(strcmp(p1->payload, p2->payload) > 0){
            p1->next = p2->next;
            LinListInsertFirst(&l1, p2);
            p1 = l1;
            p2 = l1->next;
        }

        else{
            p1 = p1->next;
            p2 = p2->next;
        }

    }


// print
    handle = l1;
    while(handle->next != NULL) {
        printf("%s", handle->payload);
        handle = handle->next;
    }
    printf("%s", handle->payload);
/* ende gelände */
    LinListFree(l2);

    LinListFree(l1);

    if (in != stdin) {
        fclose(in);
    }

    exit(EXIT_SUCCESS);
}
