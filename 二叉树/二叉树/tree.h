#ifndef _TREE_H_
#define _TREE_H_


#include"common.h"

//��������
typedef char TNDataType;  


//���ڵ�����
typedef struct TreeNode  
{
	TNDataType data;
	struct TreeNode * leftChild;  //����ָ��
	struct TreeNode * rightChild;  //�Һ���ָ��
}TreeNode;


//������
typedef struct Tree  
{
	TreeNode * root;  //ָ����ڵ��ָ��
}Tree;


//��ʼ����
void TreeInit(Tree * pt);



//���������
void TreeCreate(Tree * pt);
//ǰ��������������
TreeNode * TreeCreate_before();


//ʹ���ַ������������
void TreeCreate_str(Tree * pt, char * str);
//ʹ���ַ���ǰ��������������
TreeNode * TreeCreate_str_before(char * str, int * pindex);


//�ݻٶ�����
void TreeDestory(Tree * pt);
void TreeDestory_again(TreeNode ** pptn);





//���������
void TreeBeforeOrder(Tree * pt);
void Order_before(TreeNode * ptn);


//���������
void TreeBetweenOrder(Tree * pt);
void Order_between(TreeNode * ptn);


//���������
void TreeBehindOrder(Tree * pt);
void Order_behind(TreeNode * ptn);


//��α���
void TreeLevelOrder(Tree * pt);





//��ڵ����
int TreeNodeSize(Tree * pt);
//���������ڵ����
int Order_Size(TreeNode * ptn);


//��Ҷ�ӽڵ����
int TreeLeafSize(Tree * pt);
//���������Ҷ�ӽڵ����
void Order_LeafSize(TreeNode * ptn, int * count);


//���������
int TreeLevelKSize(Tree * pt);
int Order_LevelSize(TreeNode * ptn);


//����Ԫ��
TreeNode * TreeFind(Tree * pt, TNDataType x);
//�����������
TreeNode * Order_Find(TreeNode * ptn, TNDataType x);


//���Ҹ��ڵ�
TreeNode * TreeFindFather(Tree * pt, TNDataType x);
//�����������
TreeNode * Order_FindFather(TreeNode * ptn, TNDataType x);


//������
void TreeCopy(Tree * newTree, Tree * pt);
//�����������
TreeNode * Order_Copy(TreeNode * ptn);


//�ж��������Ƿ���ͬ
bool TreeEqual(Tree * pt1, Tree * pt2);
//��������ж�
bool Order_Equal(TreeNode * ptn1, TreeNode * ptn2);




//�ǵݹ�ǰ�����
void TreeBeforeOrder_S(Tree* pt);

//�ǵݹ��������
void TreeBetweenOrder_S(Tree* pt);

//�ǵݹ�������
void TreeBehindOrder_S(Tree* pt);





















// ��������k��ڵ����
int BinaryTreeLevelKSize(TreeNode* root, int k);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(TreeNode* root);











#endif //_TREE_H_


