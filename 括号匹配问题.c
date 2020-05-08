typedef struct StackNode
{
	char ch;
	struct StackNode * Link;
}StackNode;

typedef struct Stack
{
	StackNode * top;
}Stack;

StackNode * ByeNode(char ch)
{
	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
	assert(p != NULL);
	p->ch = ch;
	p->Link = NULL;
	return p;
}

void StackPush(Stack *ps, char ch)
{
	assert(ps != NULL);
	StackNode *p = ByeNode(ch);
	if (ps->top == NULL)
		ps->top = p;
	else
	{
		p->Link = ps->top;
		ps->top = p;
	}
}
bool StackPop(Stack *ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		return false;
	else
	{
		StackNode *p = ps->top;
		ps->top = ps->top->Link;
		free(p);
		return true;
	}
}
bool isValid(char * s)
{
	Stack mystack;
	mystack.top = NULL;
	for (int i = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) == '(' || *(s + i) == '[' || *(s + i) == '{')
			StackPush(&mystack, *(s + i));
		else if (*(s + i) == ')')
		{
			if (mystack.top == NULL)
				return false;
			else if (mystack.top->ch == '(')
				StackPop(&mystack);
			else
				return false;
		}
		else if (*(s + i) == ']')
		{
			if (mystack.top == NULL)
				return false;
			else if (mystack.top->ch == '[')
				StackPop(&mystack);
			else
				return false;
		}
		else if (*(s + i) == '}')
		{
			if (mystack.top == NULL)
				return false;
			else if (mystack.top->ch == '{')
				StackPop(&mystack);
			else
				return false;
		}
	}
	if (mystack.top == NULL)
		return true;
	else
		return false;
}