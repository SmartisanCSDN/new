#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void change(char* str, int size)
{
	int src = strlen(str) - 1;
	int goal = size;
	while (src >= 0)
	{
		if (str[src] == ' ')
		{
			str[--goal] = '0';
			str[--goal] = '2';
			str[--goal] = '%';
		}
		else
			str[--goal] = str[src];
		--src;
	}
	strcpy(str, str + goal, size - goal);
}


int main()
{
	char str[] = "Hello word ABC";
	charge(str, sizeof(str));
	printf("%s\n", str);
	return 0;
}
