#include"BSKeyValue.h"
//�ǵݹ�

//sou���������Ĳ���
BSTreeNode* BuyBSTreeNode(BSKeyType key, BSValueType value)//����һ���ڵ�
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
	//�ն�����,�����һ����ֵΪ���ڵ�
	if ((*pptree) == NULL)
	{
		*pptree = BuyBSTreeNode(key, value);
		return 1;
	}

	//�ǿն�����
	while (cur)
	{
		if (strcmp(cur->key, key)>0)//���ڵ����key����߲���
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->key, key)<0)//���ڵ�С��key���ұ߲���
		{
			parent = cur;
			cur = cur->_right;
		}
		else//����Ԫ���Ѵ���
		{
			return 0;
		}
	}
	if (strcmp(parent->key, key)<0)//���ڸ��ڵ�
	{
		parent->_right = BuyBSTreeNode(key, value);
	}
	else//С�ڸ��ڵ�
	{
		parent->_left = BuyBSTreeNode(key, value);
	}
	return 1;

}
//����
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSKeyType key)
{
	BSTreeNode* cur = *pptree;
	while (cur)
	{
		if (strcmp(cur->key, key)<0)//���ڵ㵥�ʵĳ���С��Ҫ���ҵ���key�ĳ��ȣ����ұ���
		{
			cur = cur->_right;
		}
		else if (strcmp(cur->key, key)>0)//���ڵ㵥�ʵĳ��ȴ���Ҫ���ҵ���key�ĳ��ȣ��������
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}
	return NULL;//û���ҵ�
}


//�������

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