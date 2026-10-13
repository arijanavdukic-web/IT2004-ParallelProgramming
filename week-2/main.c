#include <stdlib.h>

int main(int argc, char *argv[]) {
    int ipos = 0;//wasnt initialized
    int ival = 0;//wasnt initialized
    int *iarray = (int *) malloc(10*sizeof(int));

    if (argc == 2) ival = atoi(argv[1]);

    for (int i = 0; i<10; i++){//Fixed bounds

        iarray[i] = ipos; }

    for (int i = 0; i<10; i++) {//Fixed bounds
        if (ival == iarray[i]) ipos = i;
    }

    free(iarray);
    return 0;
}