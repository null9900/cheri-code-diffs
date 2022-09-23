#include <stdio.h>

int main(void) {

    int pointer_size = 32;

    const char *spaces="                                         "; 
    const char *dashes="-----------------------------------------";

    printf("+%.*s+\n", pointer_size, dashes);
    for(int i=1; i<pointer_size/2+1; ++i)
    {
        printf("|%.*s\\%.*s/%.*s|\n", i-1, spaces, pointer_size-2*i, spaces,i-1, spaces);
    }

    printf("|%.*sX%.*s|\n", pointer_size/2, spaces, pointer_size/2, spaces);

    for(int i=pointer_size/2+1; i<pointer_size; ++i)
    {
        printf("|%.*s/%.*s\\%.*s|\n", pointer_size-i-1, spaces, 2*(i-pointer_size/2)-1, spaces, pointer_size-i-1, spaces);
    }
    printf("+%.*s+\n", pointer_size, dashes);

    return 0;
}
