//ºóÐòºÍÖÐÐò»Ö¸´¶þ²æÊ÷
Tree* TreeRegain_Bh(char* behind, char* between)
{
	Tree* newTree = (Tree*)malloc(sizeof(Tree));
	assert(newTree != NULL);
	TreeInit(newTree);
	int len = strlen(behind);
	newTree->root = recursion_Bh(behind, between, len);
	return newTree;
}
//µÝ¹é
TreeNode* recursion_Bh(char* behind, char* between, int len)
{
	if (len == 0)
	{
		return NULL;
	}
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node != NULL);
	node->data = *(behind + len - 1);
	int index = 0;
	while (between[index] != *(behind + len - 1))
	{
		index++;
	}

	node->rightChild = recursion_Bh(behind + index, between + index + 1, len - index - 1);
	node->leftChild = recursion_Bh(behind, between, index);
	return node;
}