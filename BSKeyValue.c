#include"BSKeyValue.h"
//非递归

//sou索二叉树的插入
BSTreeNode* BuyBSTreeNode(BSKeyType key, BSValueType value)//创建一个节点
{
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (node == NULL)
	{
		perror("use malloc for node");
		exit(EXIT_FAILURE);
	}
	node->_left = NULL;
	node->_right = NULL;
	node->key = key;
	node->value = value;
	return node;
}
int BSTreeInsert(BSTreeNode**pptree, BSKeyType key, BSValueType value)
{
	BSTreeNode *cur = *pptree;
	BSTreeNode* parent = NULL;
	//空二叉树,插入第一个我值为根节点
	if ((*pptree) == NULL)
	{
		*pptree = BuyBSTreeNode(key, value);
		return 1;
	}

	//非空二叉树
	while (cur)
	{
		if (strcmp(cur->key, key)>0)//根节点大于key在左边插入
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->key, key)<0)//根节点小于key在右边插入
		{
			parent = cur;
			cur = cur->_right;
		}
		else//插入元素已存在
		{
			return 0;
		}
	}
	if (strcmp(parent->key, key)<0)//大于父节点
	{
		parent->_right = BuyBSTreeNode(key, value);
	}
	else//小于父节点
	{
		parent->_left = BuyBSTreeNode(key, value);
	}
	return 1;

}
//查找
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSKeyType key)
{
	BSTreeNode* cur = *pptree;
	while (cur)
	{
		if (strcmp(cur->key, key)<0)//根节点单词的长度小于要查找单词key的长度，在右边找
		{
			cur = cur->_right;
		}
		else if (strcmp(cur->key, key)>0)//根节点单词的长度大于要查找单词key的长度，在左边找
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}
	return NULL;//没有找到
}


//中序遍历

void BSTreeInorder(BSTreeNode**pptree)
{
	if ((*pptree) == NULL)
	{
		return;
	}
	if ((*pptree)->_left != NULL)
		BSTreeInorder(&(*pptree)->_left);
	printf("%s: %s ", (*pptree)->key, (*pptree)->value);
	if ((*pptree)->_right != NULL)
		BSTreeInorder(&(*pptree)->_right);
}