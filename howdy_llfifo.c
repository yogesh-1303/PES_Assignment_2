typedef struct element_s {
  void *data;
  struct element_s *next;
} element_t;

typedef struct llfifo_s {
  element_t *head;
  int length;
  int capacity;
} llfifo_t;


llfifo_t *llfifo_create(int capacity)
{
  llfifo_t *fifo = (llfifo_t *) malloc(sizeof(llfifo_t));
  if (fifo == NULL)
    return NULL;

  fifo->head = NULL;
  fifo->length = 0;
  fifo->capacity = 0;

  return fifo;
}


int llfifo_enqueue(llfifo_t *fifo, void *element)
{
  if (fifo == NULL)
    return -1;

  element_t *el = (element_t *) malloc(sizeof(element_t));
  if (el == NULL)
    return -1;

  el->data = element;
  el->next = NULL;

  if (fifo->head == NULL) {
    fifo->head = el;
  } else {
    element_t *this = fifo->head;
    while (this->next != NULL)
      this = this->next;

    // this points to the last element already on the linked list
    this->next = el;
  }

  fifo->length++;
  fifo->capacity++;

  return fifo->length;
}

