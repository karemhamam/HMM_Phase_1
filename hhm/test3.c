#include <stdio.h>
#include <stdlib.h>
#include "hhm.h"

void test_multiple_allocations() ;

void test_multiple_allocations() {
    void* ptr1 = HmmAlloc(50);
    void* ptr2 = HmmAlloc(100);
    void* ptr3 = HmmAlloc(150);
    
    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) 
    {
        printf("One or more allocations failed\n");
        return;
    }

    HmmFree(ptr1);
    HmmFree(ptr2);
    HmmFree(ptr3);
    
    printf("Multiple allocations test passed\n");
}

int main() {
    test_multiple_allocations();
    return 0;
}
