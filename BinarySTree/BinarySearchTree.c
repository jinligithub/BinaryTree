#include"BinarySearchTree.h"
//非递归

//sou索二叉树的插入
BSTreeNode* BuyBSTreeNode(BSDataType x)//创建一个节点
{
	//应该申请一个节点的大小，而不是一个BSDataType
	//BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSDataType));
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_data = x;
	return node;
}
int BSTreeInsert(BSTreeNode**pptree, BSDataType x)
{
	BSTreeNode* cur = NULL;
	BSTreeNode* parent = NULL;
	//空二叉树
	if ((*pptree) == NULL)
	{
		*pptree = BuyBSTreeNode(x);
		return 1;
	}
	cur = *pptree;
	//非空二叉树
	while (cur)
	{
		if (cur->_data > x)//根节点大于X在左边插入
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < x)//根节点小于X在右边插入
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return 0;
		}
	}
	if (parent->_data<x)//大于父节点
	{
		parent->_right = BuyBSTreeNode(x);
	}
	else//小于父节点
	{
		parent->_left = BuyBSTreeNode(x);
	}
	return 1;
	
}
//收索二叉树的删除
int BSTreeRemove(BSTreeNode**pptree, BSDataType x)
{
	BSTreeNode*cur = NULL;
	BSTreeNode*parent = NULL;
	cur = *pptree;
	while (cur)
	{
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			//删除节点
		{
			if (cur->_left == NULL)//删除节点的左子树为空
			{
				if (parent = NULL)//判断cur的父节点为空
				{
					*pptree = cur->_right;
				}
				else
				{
					if (cur == parent->_right)
					{
						parent->_right = cur->_right;
					}
					else
					{
						parent->_left = cur->_right;
					}
				}
			}
			else if (cur->_right == NULL)//右子树为空
			{
				if (parent == NULL)//判断cur的父节点为空
				{
					*pptree = cur->_left;
				}
				else
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
			}
			else//左右都不为空
			{
				BSTreeNode*replace = cur->_right;//创建一个要删除的节点的代替节点
				while (replace->_left)//去左边找最小值
				{
					replace = replace->_left;
				}
				cur->_data = replace->_data;//把要删除的节点赋值为代替节点的值
				return BSTreeRemove(&cur->_right, replace->_data);//利用递归的方法删除代替的节点
			}
			free(cur);
			return 1;

		}
	}
}
//收索二叉树的查找
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSDataType x)
{
	BSTreeNode* cur = *pptree;
	while (cur)
	{
		if (cur->_data < x)//根节点小于x，在右边找
		{
			cur = cur->_right;
		}
		else if (cur->_data > x)//根节点大于x，在左边找
		{
			cur = cur->_left;
		}
		else//找到了
		{
			return cur;
		}
	}
	return NULL;//没找到
}


//递归
int BSTreeInsert_R(BSTreeNode**pptree, BSDataType x)
{
	if ((*pptree) == NULL)//空树
	{
		*pptree = BuyBSTreeNode(x);
		return 1;
	}
	if ((*pptree)->_data > x)//根节点大于x，在左边找
		return BSTreeInsert_R(&(*pptree)->_left, x);
	else if ((*pptree)->_data < x)//根节点小于x,在右边找
		return BSTreeInsert_R(&(*pptree)->_right, x);
	else
		return 0;
}

int BSTreeRemove_R(BSTreeNode**pptree, BSDataType x)
{
	if (*pptree == NULL)
	{
		return -1;
	}
	if ((*pptree)->_data > x)//根节点大于x，在左边找
		return BSTreeRemove_R(&((*pptree)->_left), x);
	else if ((*pptree)->_data < x)//根节点小于x,在右边找
		return BSTreeRemove_R(&((*pptree)->_right), x);
	else//删除节点
	{
		BSTreeNode* del = *pptree;
		if ((*pptree)->_left == NULL)//左子树为空
		{
			*pptree = (*pptree)->_right;
			free(del);
		}
		else if((*pptree)->_right == NULL)//右子树为空
		{
			*pptree = (*pptree)->_left;
			free(del);
		}
		else//都不为空
		{
			BSTreeNode* replace = (*pptree)->_right;//创建一个要删除的节点的代替节点
			while (replace->_left)//在左子树找一个最小值
			{
				replace = replace->_left;
			}
			(*pptree)->_data = replace->_data;//把要删除的节点赋值为代替节点的值
			return BSTreeRemove_R(&(*pptree)->_right,  replace->_data);//利用递归删除节点
		}
	}
	return 1;
}


BSTreeNode* BSTreeFind_R(BSTreeNode** pptree, BSDataType x)
{
	if (*pptree == NULL)//空树
	{
		return NULL;
	}
	if ((*pptree)->_data > x)//根节点小于要查找的值
		return BSTreeFind_R(&(*pptree)->_right, x);
	else if ((*pptree)->_data < x)//根节点大于要查找的值
		return BSTreeFind_R(&(*pptree)->_left, x);
	else//找到了
		return *pptree;

}

//中序遍历

void BSTreeInorder(BSTreeNode**pptree)//左 根 右
{
	if ((*pptree) == NULL)
	{
		return;
	}
	if ((*pptree)->_left != NULL)
		BSTreeInorder(&(*pptree)->_left);
	printf("%d ", (*pptree)->_data);
	if ((*pptree)->_right != NULL)
		BSTreeInorder(&(*pptree)->_right);
}