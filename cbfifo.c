#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<malloc.h>

#ifndef _CBFIFO_H_
#define _CBFIFO_H_ 

#define capacity 128

struct cbfifo_s			//circular buffer structure
{
  char  buffer[128];
  uint8_t read, write;
  size_t max_len;
  size_t len;	
  bool is_full; 
 
};

static struct cbfifo_s a;	//cicular buffer structure instance

//following function enqueues an element to the circular buffer
//takes the pointer to data and number of bytes to enqueue as arguments
//returns actual number of bytes enqueued
 
size_t cbfifo_enqueue(void *buf, size_t nbytes)
{
  char *buff = (char *) buf;
  int i=0;  
  if(nbytes < 0)
	return -1;
  
  else
    {
      if(buff == NULL)
	return -1;

      else
      {
        if((a.read == a.write)&&(a.is_full==1))		//Buffer Full
        {
          a.write = 0; a.read = 0; a.is_full = 0; a.len = 0;	
          return 0;				
        }

        else
	{
	  if(nbytes > (capacity) - (a.len))   //if nbytes > remaining size of buf
	    nbytes = (capacity) - (a.len);
	  else
	    nbytes = nbytes;
	  
	  for(i=0;i<nbytes;i++)			//writing to the buffer
	  {
	    a.buffer[a.write] =  buff[i];
	    a.write = (a.write + 1) & (capacity-1);
	    a.len++;
	    //printf("***len = %zu\n", a.len);
	  }
	  //printf("enq*length = %zu\n", a.len);
   	  return nbytes;
	}
      }
   
    }
}


//following function enqueues an element to the circular buffer
//takes the pointer to data and number of bytes to enqueue as arguments
//returns actual number of bytes enqueued

size_t cbfifo_dequeue(void *buf, size_t nbytes)
{
  char *buff = (char *) buf;
  int i=0;  
  if(nbytes < 0)
	return -1;
  
  else
    {
      if(buff == NULL)
	return -1;

      else
      {
        if((a.read == a.write)&&((a.is_full==0)||(a.is_full==1)))		
        {
          a.write = 0; a.read = 0; a.is_full = 0; a.len = 0;	
          return 0;				
        }
	else
	{
	  if(nbytes > (a.len))		//if nbytes > length of buffer
	    nbytes = (a.len);
	  else
	    nbytes = nbytes;
	  
	  for(i=0;i<nbytes;i++)		//reading from the buffer
	  {
	    buff[i] = a.buffer[a.read];
	    a.read = (a.read + 1);
	    a.len--;
	    //printf("**len = %zu\n", a.len);
	  }
	  //printf("***len = %zu\n", a.len);
	  return nbytes;
	}
      }
    
    }

}

//Returns current size of the buffer

size_t cbfifo_length()
{
  return a.len;
}

//Returns capacity of the buffer

size_t cbfifo_capacity()
{
  return capacity;
}

#endif
