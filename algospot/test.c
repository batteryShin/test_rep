#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s1[1] = {"abc"};
    char *s2 = "abc";

    printf("%d\n", sizeof(*s1));
    printf("%d\n", sizeof(*s2));
}
