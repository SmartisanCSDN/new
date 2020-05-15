#define _CRT_SECURE_NO_WARNINGS 1

#include"tree.h"


int main()
{
	Tree myTree;
	TreeInit(&myTree);
	char str[] = "ABC##DE##F##G#H##";
	TreeCreate_str(&myTree, str);
	TreeBeforeOrder_S(&myTree);
	TreeBetweenOrder_S(&myTree);
	TreeBehindOrder_S(&myTree);
	return 0;
}