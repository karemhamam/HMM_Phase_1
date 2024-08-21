#include <stdio.h>
#include <stdlib.h>
#include "hhm.h"

void test_memory_leak() ;

void test_memory_leak() {
    for (int i = 0; i < 1000; i++) {
        void* ptr = HmmAlloc(10);
        if (ptr == NULL) {
            printf("Memory leak test failed\n");
            return;
        }
        // Do not free ptr intentionally to simulate memory leak
    }
    printf("Memory leak test completed (check with a memory analysis tool)\n");
}

int main() {
    test_memory_leak();
    return 0;
}
