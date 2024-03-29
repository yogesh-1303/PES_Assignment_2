#include "llfifo.c"
#include<stdio.h>
#include<assert.h>

//#define NDEBUG

void test_llfifo()
{
  int len;
  llfifo_t *my_fifo = llfifo_create(5);
  assert(my_fifo!=NULL);
 

  char *str = NULL;
  len = llfifo_enqueue(my_fifo, "sleepy");
  assert(len==1);
  printf("length =   %d\n",p->length);
  len = llfifo_enqueue(my_fifo, "ralphie");
  assert(len==2);
  printf("length =   %d\n",p->length);

  str = (char *)llfifo_dequeue(my_fifo);
  assert(str!=NULL);

  p->capacity = 0;
  str = (char *)llfifo_dequeue(my_fifo);
  assert(str==NULL); 
}






