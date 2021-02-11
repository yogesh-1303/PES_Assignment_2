#include "cbfifo.c"
#include<assert.h>

//#define NDEBUG


void test_cbfifo()
{
  char my_buf[128];
  size_t bytes_enq_deq;
  
  bytes_enq_deq = cbfifo_enqueue(&my_buf,15);
  bytes_enq_deq = cbfifo_enqueue(&my_buf,100);
  bytes_enq_deq = cbfifo_enqueue(&my_buf,15);
  printf("bytes enqueued = %zu\n",bytes_enq_deq);
  bytes_enq_deq = cbfifo_enqueue(&my_buf,-1);
  assert(bytes_enq_deq == -1);
  bytes_enq_deq = cbfifo_dequeue(&my_buf,15);
  assert(bytes_enq_deq == -1);
  bytes_enq_deq = cbfifo_enqueue(NULL,100);
  assert(bytes_enq_deq == -1);
  bytes_enq_deq = cbfifo_enqueue(NULL,20);
  assert(bytes_enq_deq == -1);
  
}
