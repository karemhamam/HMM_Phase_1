#include <stdio.h>
#include <stdlib.h>
#include "hhm.h"

void test_basic_allocation() ;

void test_basic_allocation() 
{
    void* ptr = HmmAlloc(100); 
    if (ptr == NULL) {
        printf("Allocation failed\n");
        return;
    }
    HmmFree(ptr); 
    printf("Basic allocation and deallocation test passed\n");
}

int main() {
    test_basic_allocation();
    return 0;
}
