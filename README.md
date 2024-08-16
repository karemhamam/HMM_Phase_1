## Heap Memory Manager (HMM)

### Introduction

The Heap Memory Manager (HMM) is a simple implementation of dynamic memory allocation in user space without any kernel dependencies. It simulates a heap using a statically allocated array and manages memory allocation and deallocation using custom functions. This implementation is primarily for educational purposes and helps understand the basics of memory management.

### Features

- Provides dynamic memory allocation through `void *HmmAlloc(size_t size)`.
- Allows freeing allocated memory through `void HmmFree(void *ptr)`.
- Uses a large statically allocated array to simulate the heap.
- Manages memory blocks using a linked list of block headers.
- merge adjacent free blocks to reduce fragmentation.
- Minimizes overhead by reducing the increments/decrements of the simulated program break.

### Design

1. **Heap Simulation:**
   - A statically allocated array (`heap`) of size 1 MB simulates the heap.
   - A pointer (`program_break`) simulates the program break, initially pointing to the beginning of the heap.

2. **Block Header:**
   - Each memory block is preceded by a block header containing the size, a free flag, and a pointer to the next block.
   - The block header structure (`block_header`) is defined as:
     ```c
     typedef struct block_header {
         size_t size;
         int free;
         struct block_header *next;
     } block_header;
     ```

3. **Memory Allocation (HmmAlloc):**
   - Checks for size zero and returns `NULL` if requested size is zero.
   - Traverses the free list to find a suitable free block using the first-fit strategy.
   - If no suitable block is found, checks if expanding the heap would exceed the allocated heap space.
   - If there is sufficient space, creates a new block at the current `program_break`, initializes the block header, updates the free list, and increments the `program_break`.
   - Returns a pointer to the memory region just after the block header.

4. **Memory Deallocation (HmmFree):**
   - Checks if the pointer is `NULL` and returns if it is.
   - Calculates the block header address from the pointer and marks the block as free.
   - Traverses the free list to coalesce adjacent free blocks to reduce fragmentation.

### Flowcharts

#### Flowchart for `HmmAlloc`

![HmmAlloc](https://github.com/user-attachments/assets/01a11334-a79f-448e-a9a7-d153e5be979e)


#### Flowchart for `HmmFree`

## Installation

1. Clone the repository and compile the code: git clone (https://github.com/karemhamam/HMM_Phase_1/tree/master)

## Contributing

Contributions are welcome! 
If you have suggestions for new features or improvements, feel free to open an issue or submit a pull request.

## License

mahamedhamam15@gmail.com

