/* *******************************************************
   * @File                 : hhm.c
   * @Author               : mohamed bahget hamam
   * @gmail                : mahamedhamam15@gmail.com
   *******************************************************
*/


/* **************** Include section start *************** */

#include <stdint.h>                                         // includes the standard ineger types header.
#include <stdio.h>                                          // includes the standard input/output header.
#include <string.h>                                         // includes the string manipulation functions.
#include "hhm.h"                                            // icludes the header file which has functions declarations.

/* **************** Include section End *************** */


/* **************** macros section start *************** */

#define HEAP_SIZE 1024 * 1024                               // 1 MB heap size.

#define BLOCK_HEADER_SIZE sizeof(block_header)              // difine the size of block header.

/* **************** macros section End *************** */


/* **************** Definition section start *************** */

static uint8_t heap[HEAP_SIZE];                             // array of bytes representing the heap space.

static uint8_t *program_break = heap;                       // pointer to the end of the heap.

typedef struct block_header                                 // structure to manage memory blocks.
{
    size_t size;                                            // the size of the block.
    int free;                                               // flag to indicate the block is free or not.
    struct block_header *next;                              // pointer to the next block.

} block_header;

static block_header *free_list = NULL;                      // pointer to the linked list of free blocks.

void *HmmAlloc(size_t size) 
{
    if (size == 0) return NULL;                             // to chack is the requested size is 0.

    block_header *current = free_list;                      // pointer to traverse the free list.
    block_header *prev = NULL;                              // pointer to track the previous block.

    /* First Fit Algorithm */
    while (current != NULL) {
        if (current->free && current->size >= size) 
        {
            current->free = 0;                              // suitable block found.
            return (void *)(current + 1);
        }
        prev = current;
        current = current->next;
    }

    /* No suitable block found, expand heap. */
    if ((program_break + BLOCK_HEADER_SIZE + size) >= (heap + HEAP_SIZE))
    {
        return NULL;                                         // heap overflow.
    }

    block_header *new_block = (block_header *)program_break; // create a new block header.
    new_block->size = size;                                  // sets the block's size.
    new_block->free = 0;                                     // marks is as allocated.
    new_block->next = NULL;                                  // sets the next pointer to null.

    if (prev != NULL)
    {
        prev->next = new_block;                               // link the prev. to the new block.
    } else 
    {
        free_list = new_block;                                // set it to point to the new block.
    }

    program_break += BLOCK_HEADER_SIZE + size;                // move the program break to the end of the new allocated block.
    return (void *)(new_block + 1);                           //return a pointer to the memory region after the block header.
} 

void HmmFree(void *ptr)
{
    if (ptr == NULL) return;                                  // return if the pointer is null.

    block_header *block = (block_header *)ptr - 1;            // calculate the block header address.
    block->free = 1;                                          // mark the block as free.

    /* merge adjacent free blocks. */
    block_header *current = free_list;
    while (current != NULL && current->next != NULL) 
    {
        if (current->free && current->next->free) 
        {
            current->size += BLOCK_HEADER_SIZE + current->next->size;
            current->next = current->next->next;
        } else 
        {
            current = current->next;
        }
    }
}


/* ************** Definition section End *************** */


/* *******************************************************
    User                Date               time
   *******************************************************
   kareem hamam         14 aug 2024        06 : 20 pm
*/

