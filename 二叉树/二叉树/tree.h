#ifndef _TREE_H_
#define _TREE_H_


#include"common.h"

//数据类型
typedef char TNDataType;  


//树节点类型
typedef struct TreeNode  
{
	TNDataType data;
	struct TreeNode * leftChild;  //左孩子指针
	struct TreeNode * rightChild;  //右孩子指针
}TreeNode;


//树类型
typedef struct Tree  
{
	TreeNode * root;  //指向跟节点的指针
}Tree;


//初始化树
void TreeInit(Tree * pt);



//构造二叉树
void TreeCreate(Tree * pt);
//前序遍历构造二叉树
TreeNode * TreeCreate_before();


//使用字符串构造二叉树
void TreeCreate_str(Tree * pt, char * str);
//使用字符串前序遍历构造二叉树
TreeNode * TreeCreate_str_before(char * str, int * pindex);


//摧毁二叉树
void TreeDestory(Tree * pt);
void TreeDestory_again(TreeNode ** pptn);





//先序遍历法
void TreeBeforeOrder(Tree * pt);
void Order_before(TreeNode * ptn);


//中序遍历法
void TreeBetweenOrder(Tree * pt);
void Order_between(TreeNode * ptn);


//后序遍历法
void TreeBehindOrder(Tree * pt);
void Order_behind(TreeNode * ptn);


//层次遍历
void TreeLevelOrder(Tree * pt);





//求节点个数
int TreeNodeSize(Tree * pt);
//先序遍历求节点个数
int Order_Size(TreeNode * ptn);


//求叶子节点个数
int TreeLeafSize(Tree * pt);
//先序遍历求叶子节点个数
void Order_LeafSize(TreeNode * ptn, int * count);


//求树的深度
int TreeLevelKSize(Tree * pt);
int Order_LevelSize(TreeNode * ptn);


//查找元素
TreeNode * TreeFind(Tree * pt, TNDataType x);
//先序遍历查找
TreeNode * Order_Find(TreeNode * ptn, TNDataType x);


//查找父节点
TreeNode * TreeFindFather(Tree * pt, TNDataType x);
//先序遍历查找
TreeNode * Order_FindFather(TreeNode * ptn, TNDataType x);


//拷贝树
void TreeCopy(Tree * newTree, Tree * pt);
//先序遍历复制
TreeNode * Order_Copy(TreeNode * ptn);


//判断两颗树是否相同
bool TreeEqual(Tree * pt1, Tree * pt2);
//先序遍历判断
bool Order_Equal(TreeNode * ptn1, TreeNode * ptn2);




//非递归前序遍历
void TreeBeforeOrder_S(Tree* pt);

//非递归中序遍历
void TreeBetweenOrder_S(Tree* pt);

//非递归后序遍历
void TreeBehindOrder_S(Tree* pt);





















// 二叉树第k层节点个数
int BinaryTreeLevelKSize(TreeNode* root, int k);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(TreeNode* root);











#endif //_TREE_H_


