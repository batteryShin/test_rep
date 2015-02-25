#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEST_CASE 20
#define SAMPLE_MAX 200000
#define MAX_VALUE 2

int main(void)
{
    int i, j;
    int test_case = TEST_CASE;
    int sample_num = SAMPLE_MAX;
    int max_value = MAX_VALUE;

    printf("%d\n", test_case);
    for(i=0; i<test_case; i++) {
        sample_num = rand()%SAMPLE_MAX+1;
        for(j = 0; j < sample_num; j++) {
            if( rand()%max_value==1 ) {
                printf("%c", 'F');
            } else {
                printf("%c", 'M');
            }
        }
        printf("\n");

        sample_num += rand()%SAMPLE_MAX+1; 
        if(sample_num>SAMPLE_MAX)   sample_num=SAMPLE_MAX;

        for(j = 0; j < sample_num; j++) {
            if( rand()%max_value==1 ) {
                printf("%c", 'F');
            } else {
                printf("%c", 'M');
            }
        }
        printf("\n");
    }
}
