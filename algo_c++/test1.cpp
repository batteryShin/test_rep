#include <stdio.h>
#include <stdlib.h>

int **func(int n);

int main(void) {
    int **ap;
    ap = func(3);
    printf("%d%d%d", sizeof(ap), sizeof(*ap), sizeof(**ap));
    return 0;
}

int **func(int n) {
    int **ap;
    int i;
    ap = (int **) calloc(n, sizeof(int *));
    for (i = 0; i < n; i++) {
        ap[i] = (int *) calloc(4, sizeof(int));
    }
    return ap;
}
