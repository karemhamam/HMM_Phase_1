#include <stdio.h>
#include <stdlib.h>
#include "hhm.h"


void test_fragmentation() ;

void test_fragmentation() {
    void* ptr1 = HmmAlloc(200);
    void* ptr2 = HmmAlloc(100);
    void* ptr3 = HmmAlloc(50);
    
    HmmFree(ptr2);
    HmmFree(ptr1);
    
    void* ptr4 = HmmAlloc(150); // Should reuse freed space if properly managed
    if (ptr4 != NULL) {
        printf("Fragmentation test passed\n");
        HmmFree(ptr3);
        HmmFree(ptr4);
    } else {
        printf("Fragmentation test failed\n");
    }
}

int main() {
    test_fragmentation();
    return 0;
}
