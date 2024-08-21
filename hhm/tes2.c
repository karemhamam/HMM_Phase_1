#include <stdio.h>
#include <stdlib.h>
#include "hhm.h"

void test_allocation_failure();

void test_allocation_failure() {
    void* ptr = HmmAlloc(1e9); // Large allocation to force failure
    if (ptr != NULL) {
        printf("Allocation succeeded unexpectedly\n");
        HmmFree(ptr);
    } else {
        printf("Allocation failure test passed\n");
    }
}

int main() {
    test_allocation_failure();
    return 0;
}
