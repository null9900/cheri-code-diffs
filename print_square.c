#include <stdio.h>

static int get_pointer_size_in_bits(){
    // size in bytes
    int size = sizeof(void*);
    // check if pointer size is 32 bit or 64 bits
    if(size*8==32){
        printf("%s","This program supports 32 bit machines");
        return 32;
    }else{
        printf("%s","This program supports 64 bits machines"); 
        return 64;
    }
}

int main(void) {

    int pointer_size = get_pointer_size_in_bits();

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
