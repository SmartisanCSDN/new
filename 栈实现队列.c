typedef struct stack
{
	int * data;
	int top;
}stack;


typedef struct
{
	stack * Queuestack;
	stack * fuzhustack;
} MyQueue;


/** Initialize your data structure here. */


MyQueue* myQueueCreate(int k)
{
	MyQueue * myQueue = (MyQueue *)malloc(sizeof(MyQueue));
	assert(myQueue != NULL);
	myQueue->Queuestack = (stack *)malloc(sizeof(stack));
	assert(myQueue->Queuestack != NULL);
	myQueue->Queuestack->data = (int *)malloc(sizeof(int)* k);
	myQueue->Queuestack->top = 0;
	myQueue->fuzhustack = (stack *)malloc(sizeof(stack));
	assert(myQueue->fuzhustack != NULL);
	myQueue->fuzhustack->data = (int *)malloc(sizeof(int)* k);
	myQueue->fuzhustack->top = 0;
	return myQueue;
}


/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	assert(obj != NULL);
	obj->Queuestack->data[obj->Queuestack->top] = x;
	obj->Queuestack->top++;
}


/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	assert(obj != NULL);
	int value;
	if (obj->Queuestack->top == 0)
		printf("¶Ó¿Õ£¡\n");
	else
	{
		while (obj->Queuestack->top > 1)
		{
			obj->Queuestack->top--;
			obj->fuzhustack->data[obj->fuzhustack->top] = obj->Queuestack->data[obj->Queuestack->top];
			obj->Queuestack->data[obj->Queuestack->top] = 0;
			obj->fuzhustack->top++;
		}
		obj->Queuestack->top--;
		value = obj->Queuestack->data[obj->Queuestack->top];
		obj->Queuestack->data[obj->Queuestack->top] = 0;
		while (obj->fuzhustack->top > 0)
		{
			obj->fuzhustack->top--;
			obj->Queuestack->data[obj->Queuestack->top] = obj->fuzhustack->data[obj->fuzhustack->top];
			obj->fuzhustack->data[obj->fuzhustack->top] = 0;
			obj->Queuestack->top++;
		}
	}
}


/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	return obj->Queuestack->data[0];
}


/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	return obj->Queuestack->top;
}


void myQueueFree(MyQueue* obj)
{
	assert(obj != NULL);
	free(obj->Queuestack->data);
	free(obj->Queuestack);
	free(obj->fuzhustack->data);
	free(obj->fuzhustack);
	free(obj);
}