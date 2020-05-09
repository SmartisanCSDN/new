typedef struct Queue
{
	int * data;
	int head;
	int tail;
	int capacity;
	int capacity_t;
}Queue;


typedef struct Stack
{
	Queue * StackQueue;
	Queue * fuzhuQueue;
} Stack;


int myStackPop(Stack* obj)
{
	assert(obj != NULL);
	if (obj->StackQueue->head == obj->StackQueue->tail)
	{
		printf("Õ»¿Õ£¡\n");
		return 0;
	}
	else
	{
		int value = 0;
		while ((obj->StackQueue->head + 1) % obj->StackQueue->capacity_t != obj->StackQueue->tail)
		{
			obj->fuzhuQueue->data[obj->fuzhuQueue->tail] = obj->StackQueue->data[obj->StackQueue->head];
			obj->StackQueue->head = (obj->StackQueue->head + 1) % obj->StackQueue->capacity_t;
			obj->fuzhuQueue->head = (obj->fuzhuQueue->head + 1) % obj->fuzhuQueue->capacity_t;
		}
		value = obj->StackQueue->data[obj->StackQueue->head];
		obj->StackQueue->head = (obj->StackQueue->head + 1) % obj->StackQueue->capacity_t;
		while (obj->fuzhuQueue->head != obj->StackQueue->tail)
		{
			obj->StackQueue->data[obj->StackQueue->tail] = obj->fuzhuQueue->data[obj->fuzhuQueue->head];
			obj->fuzhuQueue->head = (obj->fuzhuQueue->head + 1) % obj->fuzhuQueue->capacity_t;
			obj->StackQueue->head = (obj->StackQueue->head + 1) % obj->StackQueue->capacity_t;
		}
		return value;
	}
}