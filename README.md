# PES_Assignment_2
PRINCIPLES OF EMBEDDED SYSTEMS – ASSIGNMENT  2



1. PROGRAMMING ENVIRONMENT:

The program is written the in Linux environment using gcc compiler and GDB debugger. The language used is C with the help of terminal as command line interface for compiling, debugging, etc. Virtual box inside a Windows operating system was used for accessing Linux environment.

2. FILE SYSTEM:

The program is completed using different files linked together. Following files are used.

llfifo.c – containg all the functions of linear linked list
cbfifo.c - containg all the functions of circular buffer
test_llfifo.c – contains testing function for llfifo.c
test_cbfifo.c – contains testing function for cbfifo.c
llfifo.h – contains prototypes of llfifo.c functions
cbfifo.h – contains prototypes of cbfifo.c functions
main.c – conatins main function
makefile

3. CODE DESCRIPTION:

The below description will be a filewise description of codes:

a. llfifo.c:

Code in this file define a structure for linked lists which is made private by defining it inside another structure concerned with the parameters of the linked list.
Then Following functions are defined:

1) llfifo_t *llfifo_create(int capacity)

This function basically creates a space for linked list in the memory using dynamic allocation of memory. The space is however empty and not filled with any data. A globel pointer to an instance of the parent structure is used to pass values between functions.This function one by one creates an empty space for specified number of linked list elements (capacity) and also keeps track of the first and last memory address.

2) int llfifo_enqueue(llfifo_t *fifo, void *element)

This function enqueues an element into the linked list created in previous function. It first checks for whether the list is empty. The function enqueues each element by using two pointers (p->front and p->rear) which sequentially progress keeping track of two elements at a time. When to write in the memory, the data is put using p->rear and p->rear->next starts pointing to NULL after  enqueueing. The p->front->next starts pointing to p->rear and hence the element is enqueued.
The values of front and rear are retained and passed between functions using global pointer instance (p) of the parent structure (llfifo_s). If there are slots remaining in the memory created using llfifo_create, the elements are simply added without using malloc otherwise, malloc is used to define new space for the element.

3)void *llfifo_dequeue(llfifo_t *fifo)

This function operates similar to the previous one however it dequeues an element from the list. It first checks for an empty list and if that is not the case, it reads an element. The element is removed using again front and rear pointers which keep track of the locations. One the data is read, the pointers are decremented to shift one memory location early and total length of the list is decreased.

4) int llfifo_length(llfifo_t *fifo); int llfifo_capacity(llfifo_t *fifo)

Above functions return the current length and capacity of the list.

5)void llfifo_destroy(llfifo_t *fifo)

This function frees up the space allocated dynamically for the linked list.

b. cbfifo.c

A structure for creating parameters of the circular buffer is defined at the start along with its global instance.

The code contains following functions:

1) size_t cbfifo_enqueue(void *buf, size_t nbytes)

This function enqueues the data into the circular buffer. The number of bytes are specified by the caller. If the specified number of bytes are larger than the remaining length of the buffer, only the bytes equal to the remaining length of the buffer are enqueued and rest are dropped. Full data is enqueued if the number of bytes are less than the remaining length of the buffer. The write pointer is used to keep track of the slots that are already full and which one is next available. The length is increased when each byte gets written.

Here is the essential part of the function:

for(i=0;i<nbytes;i++)
{
a.buffer[a.write] =  buff[i];
a.write = (a.write + 1) & (capacity-1);
a.len++; }


2)size_t cbfifo_dequeue(void *buf, size_t nbytes)

This function dequeues the number of bytes specified from the circular buffer. If the number of bytes are more than the length of the buffer, the bytes only up till the length are read. With each read, the read pointer is incremented and length is decreased by one.

Here is the essential part of the function:

for(i=0;i<nbytes;i++)		//reading from the buffer
{
buff[i] = a.buffer[a.read];
a.read = (a.read + 1);
a.len--;
}


3)size_t cbfifo_length() ; size_t cbfifo_capacity()

Above functions keep track of the circular buffer length and returns capacity respectively.

c) test_llfifo.c ; test_cbfifo.c

Above files test the llfifo.c and cbfifo.c file functions respectively. The files use assert() funtion to determine the success of a test with the different functions and cases.

d)llfifo.h ; cbfifo.h

These files contain the descriptions and prototypes of the functions used in llfifo.c and cbfifo.c

e) main.c

This is the program’s main function file which calls all the test functions.

f) Makefile

Makefile finally is used to compile, link, and build all different files.
