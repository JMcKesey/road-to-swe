#include <unistd.h>
#include <stdio.h>

#define ALIGNMENT 8 // use alignment size of 8 for performance
// adding alignment-1 to size ensures it won't be a multiple of 8
// use ~ [Bitwise NOT] flips 1s to 0s vice versa
// performing & [Bitwise AND] with size somehow return the nearest
// ALIGNMENT multiple of size
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))
// size_t is usually 8 bytes but we ALIGN it to be sure 
#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

/*
 * in   : number of bytes we want to allocate
 * out  : ptr to the location of the newly allocated memory
 * */
void *malloc(size_t size)
{
  // calculating block size
  size_t blk_size = ALIGN(size + SIZE_T_SIZE);
  // requesting memory from system using the sbrk system call
  size_t *header = sbrk(blk_size);
  // store block in header and change least sig bit to 1
  *header = blk_size | 1;
  // return ptr to the memory after the header, 1 means allocated
  return (char *)header + SIZE_T_SIZE;
}

void free(void *ptr)
{
  // cast to char for fine-grained byte manipulation, we substract
  // SIZE_T_SIZE to get to the start of the header then cast to size_t *
  size_t *header = (size_t *)((char *)ptr - SIZE_T_SIZE);
  // deference header and apply bitwise AND with NOT LSB 1
  // to mark the area of memory as free(LSB of 0)
  // recall: 0 & 1 = 0 0 & 0 = 0
  *header = *header & ~1L;
}

// implementation is naive because:
// there's no coalescing(merging adjacent free blocks) which leads to fragmentation
int main()
{
  int *arr = malloc(10 * sizeof(int));
  
  int i;
  for(i=0; i<10; ++i)
  {
    arr[i] = i;
  }

  for(i=0; i<10; ++i)
  {
    printf("%d\n", arr[i]);
  }

  // used valgrind to profile memory of this program with and
  // without the free to see how memory is allocated and freed
  free(arr);
}

