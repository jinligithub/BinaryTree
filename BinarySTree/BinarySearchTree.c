#include"BinarySearchTree.h"
//�ǵݹ�

//sou���������Ĳ���
BSTreeNode* BuyBSTreeNode(BSDataType x)//����һ���ڵ�
{
	//Ӧ������һ���ڵ�Ĵ�С��������һ��BSDataType
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
	//�ն�����
	if ((*pptree) == NULL)
	{
		*pptree = BuyBSTreeNode(x);
		return 1;
	}
	cur = *pptree;
	//�ǿն�����
	while (cur)
	{
		if (cur->_data > x)//���ڵ����X����߲���
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < x)//���ڵ�С��X���ұ߲���
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return 0;
		}
	}
	if (parent->_data<x)//���ڸ��ڵ�
	{
		parent->_right = BuyBSTreeNode(x);
	}
	else//С�ڸ��ڵ�
	{
		parent->_left = BuyBSTreeNode(x);
	}
	return 1;
	
}
//������������ɾ��
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
			//ɾ���ڵ�
		{
			if (cur->_left == NULL)//ɾ���ڵ��������Ϊ��
			{
				if (parent = NULL)//�ж�cur�ĸ��ڵ�Ϊ��
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
			else if (cur->_right == NULL)//������Ϊ��
			{
				if (parent == NULL)//�ж�cur�ĸ��ڵ�Ϊ��
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
			else//���Ҷ���Ϊ��
			{
				BSTreeNode*replace = cur->_right;//����һ��Ҫɾ���Ľڵ�Ĵ���ڵ�
				while (replace->_left)//ȥ�������Сֵ
				{
					replace = replace->_left;
				}
				cur->_data = replace->_data;//��Ҫɾ���Ľڵ㸳ֵΪ����ڵ��ֵ
				return BSTreeRemove(&cur->_right, replace->_data);//���õݹ�ķ���ɾ������Ľڵ�
			}
			free(cur);
			return 1;

		}
	}
}
//�����������Ĳ���
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSDataType x)
{
	BSTreeNode* cur = *pptree;
	while (cur)
	{
		if (cur->_data < x)//���ڵ�С��x�����ұ���
		{
			cur = cur->_right;
		}
		else if (cur->_data > x)//���ڵ����x���������
		{
			cur = cur->_left;
		}
		else//�ҵ���
		{
			return cur;
		}
	}
	return NULL;//û�ҵ�
}


//�ݹ�
int BSTreeInsert_R(BSTreeNode**pptree, BSDataType x)
{
	if ((*pptree) == NULL)//����
	{
		*pptree = BuyBSTreeNode(x);
		return 1;
	}
	if ((*pptree)->_data > x)//���ڵ����x���������
		return BSTreeInsert_R(&(*pptree)->_left, x);
	else if ((*pptree)->_data < x)//���ڵ�С��x,���ұ���
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
	if ((*pptree)->_data > x)//���ڵ����x���������
		return BSTreeRemove_R(&((*pptree)->_left), x);
	else if ((*pptree)->_data < x)//���ڵ�С��x,���ұ���
		return BSTreeRemove_R(&((*pptree)->_right), x);
	else//ɾ���ڵ�
	{
		BSTreeNode* del = *pptree;
		if ((*pptree)->_left == NULL)//������Ϊ��
		{
			*pptree = (*pptree)->_right;
			free(del);
		}
		else if((*pptree)->_right == NULL)//������Ϊ��
		{
			*pptree = (*pptree)->_left;
			free(del);
		}
		else//����Ϊ��
		{
			BSTreeNode* replace = (*pptree)->_right;//����һ��Ҫɾ���Ľڵ�Ĵ���ڵ�
			while (replace->_left)//����������һ����Сֵ
			{
				replace = replace->_left;
			}
			(*pptree)->_data = replace->_data;//��Ҫɾ���Ľڵ㸳ֵΪ����ڵ��ֵ
			return BSTreeRemove_R(&(*pptree)->_right,  replace->_data);//���õݹ�ɾ���ڵ�
		}
	}
	return 1;
}


BSTreeNode* BSTreeFind_R(BSTreeNode** pptree, BSDataType x)
{
	if (*pptree == NULL)//����
	{
		return NULL;
	}
	if ((*pptree)->_data > x)//���ڵ�С��Ҫ���ҵ�ֵ
		return BSTreeFind_R(&(*pptree)->_right, x);
	else if ((*pptree)->_data < x)//���ڵ����Ҫ���ҵ�ֵ
		return BSTreeFind_R(&(*pptree)->_left, x);
	else//�ҵ���
		return *pptree;

}

//�������

void BSTreeInorder(BSTreeNode**pptree)//�� �� ��
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