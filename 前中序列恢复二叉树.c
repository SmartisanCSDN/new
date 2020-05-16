//Ç°ÐòºÍÖÐÐò»Ö¸´¶þ²æÊ÷
Tree* TreeRegain_Bf(char* before, char* between)
{
	Tree* newTree = (Tree*)malloc(sizeof(Tree));
	assert(newTree != NULL);
	TreeInit(newTree);
	int len = strlen(before);
	newTree->root = recursion_Bf(before, between, len);
	return newTree;
}
//µÝ¹é
TreeNode* recursion_Bf(char* before, char*between, int len)
{
	if (len == 0)
	{
		return NULL;
	}
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node != NULL);
	node->data = *before;
	int index = 0;
	while (between[index] != *before)
	{
		index++;
	}
	node->leftChild = recursion_Bf(before + 1, between, index);
	node->rightChild = recursion_Bf(before + index + 1, between + index + 1, len - index - 1);
	return node;
}