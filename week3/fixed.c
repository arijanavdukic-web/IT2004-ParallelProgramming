
#include <stdlib.h>

int main(int argc, char *argv[]){
    int ipos = 0;
    int ival = 0;//Fixed initialize values
    int *iarray = (int *) malloc(10*sizeof(int));

    // Fixed: check that malloc succeeded before using the pointer
    if (iarray == NULL) return 1;

    if (argc == 2) ival = atoi(argv[1]);

    // Fixed: out of bounds(i<=10)
    for (int i = 0; i < 10; i++){ iarray[i] = ipos; }

    // Fixed: out of bounds
    for (int i = 0; i < 10; i++){
        if (ival == iarray[i]) ipos = i;
    }

    // Fixed: memory leak
    free(iarray);

    return 0;
}
