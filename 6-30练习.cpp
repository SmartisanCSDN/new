#include<iostream>
#include<vector>
using namespace std;

//������һ���������������Hash��Hash��Ĵ洢��λ��ΪͰ��ÿ��Ͱ�ܷ�3��������
//��һ��Ͱ��Ҫ�ŵ�Ԫ�س���3��ʱ����Ҫ���µ�Ԫ�ش�������Ͱ�У�ÿ�����ͰҲ�ܷ�3��Ԫ�أ�
//������Ͱʹ��������������Hash��Ļ�Ͱ��ĿΪ����P��Hash���hash������Pȡģ�����붨�����£�

#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node *next;
};
bucket_node hash_table[P];

//���ڼ���hash_table�Ѿ���ʼ�����ˣ�insert_new_element()����Ŀ���ǰ�һ���µ�ֵ����hash_table�У�
//Ԫ�ز���ɹ�ʱ����������0�����򷵻�-1����ɺ�����

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