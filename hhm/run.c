/* *******************************************************
   * @File                 : run.c
   * @Author               : mohamed bahget hamam
   * @gmail                : mahamedhamam15@gmail.com
   *******************************************************
*/


/* **************** Include section start *************** */

#include <stdio.h>                                   // includes the standard input/output header.
#include <stdlib.h>                                  // includes the standard library header.
#include "hhm.h"                                     // icludes the header file which has functions declarations.

/* **************** Include section End *************** */

#define NUM_ALLOCS (100)
#define MAX_ALLOC_SIZE (1024)

/* **************** main section start *****************/

int main() 
{
    void *allocations[NUM_ALLOCS];                   // array of pointers to allocate memory blocks.

    /* random allocations */
    for (int i = 0; i < NUM_ALLOCS; i++) 
    {
        size_t size = rand() % MAX_ALLOC_SIZE;       // generate random size between 0 and 1023.
        allocations[i] = HmmAlloc(size);             // calls HmmAlloc.

        if (allocations[i] == NULL) 
        {
            printf("Allocation failed at %d\n", i);  // print a message if allocation fails.
        }
    }

    /* random frees */
    for (int i = 0; i < NUM_ALLOCS; i++) 
    {
        if (allocations[i] != NULL) 
        {
            HmmFree(allocations[i]);                // calls HmmFree.
        }
    }

    printf("Test completed.\n");                    // print a complition message.
    return 0;
}

/* **************** main section end ******************/


/* *******************************************************
    User                Date               time
   *******************************************************
   kareem hamam         14 aug 2024        06 : 20 pm
*/

