#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hhm.h"

void test_alignment() ;

void test_alignment() {
    void* ptr = HmmAlloc(64); // 64 bytes should be aligned
    if (ptr == NULL) {
        printf("Allocation failed\n");
        return;
    }

    uintptr_t address = (uintptr_t)ptr;
    if (address % 8 == 0) { // Check for 8-byte alignment
        printf("Alignment test passed\n");
    } else {
        printf("Alignment test failed\n");
    }

    HmmFree(ptr);
}

int main() {
    test_alignment();
    return 0;
}
