#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef _LLFIFO_H_
#define _LLFIFO_H_


typedef struct llfifo			//defining the data structure
  {	
	char *data;
	struct llfifo *next;
		
  }llfifo_l;

typedef struct llfifo_s			//a structure holding other parameters

{
	int length;
	int capacity;
	struct llfifo_s *head, *first, *last;
	llfifo_l *el, *front, *rear;
	
}llfifo_t;

llfifo_t *p;

//Following function creates a linear fifo which is empty initially
//takes capacity in the argument and returns a pointer to created fifo instance

llfifo_t *llfifo_create(int capacity)
{	
		
	
	p= (llfifo_t *) malloc (sizeof(llfifo_t));
	p->capacity = capacity;
	p->head = NULL;
	p->length =0;
	//printf("capacity = %d\n\n", p->capacity);
	 
	
	

	if(capacity <= 0)             //error = negative or zero capacity
	 p=NULL;

	else
  {
	for(int i=1;i<=capacity;i++)	//creating an empty fifo
	{
	
	p->el = (llfifo_l *) malloc (sizeof (llfifo_l)); 
	if (i==1)
		p->first = (llfifo_t *)p->el; //keeping track of first addr
	else
		p->last = (llfifo_t *)p->el;
	
	
	}	
  }		
	//printf("el = %p\n", p->el);
	return p;
	
}

//----------------------------------------------------------------------------//

//folllowing function enqueues an element to the fifo
//takes fifo in question and element to be enqueued as arguments
//Returns A new length of fifo on success and -1 on failure

int llfifo_enqueue(llfifo_t *fifo, void *element)
{		
  	
  if(p->length <= p->capacity)			//if length < created length
	{

	if(p->head == NULL)			//if fifo is empty
	{
	  p->head = p->first;
	  //printf("head = %p\n", p->first);
	  //front and rear to move forward keeping track of 2 elements as a time
	  p->front =  (llfifo_l *)p->first;
	  p->rear = (llfifo_l *)p->first;
	  p->front->data = (char *) element;
	  p->front->next = p->rear->next = NULL;
//printf("element = %s\t,front = %p\t,rear=%p\n", p->rear->data,p->front,p->rear);
	  p->length = 1;
	  p->rear+=2;
	}
	else				//if fifo is not empty
	{
	  
	  p->front->next = p->rear;
	  p->rear->data = (char *) element;
	  p->rear->next = NULL;
//printf("element = %s\t,front = %p\t,rear=%p\n", p->rear->data,p->front,p->rear);
	  p->front+=2;
	  p->rear+=2;
	  p->length++;
	
	}
}

  else							//if capacity exceeds
	{
	  p->rear= (llfifo_l *)malloc(sizeof(llfifo_l));
	  p->rear->data = (char *) element;
	  p->front->next = p->rear;
//printf("element = %s\t,front = %p\t,rear=%p\n", p->rear->data,p->front,p->rear);
	  p->front = p->rear;
	  p->length++;
	  p->capacity++;
	}
	//printf("length =  %d\n", p->length);
	return p->length;
}

//dequeues a fifo element
void *llfifo_dequeue(llfifo_t *fifo)
{
	char *a = NULL;
	if(p->capacity == 0)    //if fifo is empty
	  return NULL;
	else
	{	
	  if(p->capacity >= p->length) //if length < capacity
	  {
	    p->length--;
	    p->capacity--;
	    p->front->next = NULL;   //put secong last element's next ptr to NULL
	    p->front -= 2;	     
	    a = p->rear->data;	     //load the data dequeued
  	    p->rear -=2 ;
	  }
	  else
	  {
	    p->length--;
	    p->front->next = NULL;
	    p->front -= 2;
	    a = p->rear->data;
  	    p->rear -=2 ;
	  }
	 return a;	
	}
}

//returns length of the fifo
int llfifo_length(llfifo_t *fifo)
{
	return p->length;
}

//returns capacity of the fifo
int llfifo_capacity(llfifo_t *fifo)
{
	return p->capacity;
}

void llfifo_destroy(llfifo_t *fifo)
{
  for(int i=0;i<=p->capacity;i++)
    { 
	free(p->first);
	p->first += 2;
    }
}



#endif
