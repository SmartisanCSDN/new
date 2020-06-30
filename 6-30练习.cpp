#include<iostream>
#include<vector>
using namespace std;

//现在有一个用来存放整数的Hash表，Hash表的存储单位称为桶，每个桶能放3个整数，
//当一个桶中要放的元素超过3个时，则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。此Hash表的基桶数目为素数P，Hash表的hash函数对P取模。代码定义如下：

#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node *next;
};
bucket_node hash_table[P];

//现在假设hash_table已经初始化好了，insert_new_element()函数目的是把一个新得值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。

int Insert_new_element(int new_element)
{
	int index = new_element % P;
	bucket_node* insert_node = &hash_table[index];

	while (insert_node->next != nullptr)
		insert_node = insert_node->next;

	if (insert_node->data[0] == NULL_DATA)
		insert_node->data[0] = new_element;
	else if (insert_node->data[1] == NULL_DATA)
		insert_node->data[1] = new_element;
	else if (insert_node->data[2] == NULL_DATA)
		insert_node->data[2] = new_element;
	else
	{
		insert_node->next = new bucket_node;
		insert_node->next->data[0] = new_element;
		insert_node->next->data[1] = NULL_DATA;
		insert_node->next->data[2] = NULL_DATA;
		insert_node->next->next = nullptr;
	}
	return 0;
}
int main()
{
	for (int i = 0; i < P; ++i)
	{
		hash_table[i].data[0] = -1;
		hash_table[i].data[1] = -1;
	}
	/*int array[] = {15,14,21,87,96,293,35,24,149,19,63,16,103,77,5,153,145,356,51,68,705,453 };
	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
	{
	Insert_new_element(array[i]);
	}*/
	return 0;
}