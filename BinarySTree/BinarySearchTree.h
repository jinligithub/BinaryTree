#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//��������������ɾ�����ҵݹ���ǵݹ��ʵ��

typedef int BSDataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSDataType _data;
}BSTreeNode;

//�ǵݹ�
int BSTreeInsert(BSTreeNode**pptree, BSDataType x);//�����������Ĳ���
int BSTreeRemove(BSTreeNode**pptree, BSDataType x);//������������ɾ��
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSDataType x);//�����������Ĳ���

//�ݹ�
int BSTreeInsert_R(BSTreeNode**pptree, BSDataType x);
int BSTreeRemove_R(BSTreeNode**pptree, BSDataType x);
BSTreeNode* BSTreeFind_R(BSTreeNode** pptree, BSDataType x);

void BSTreeDretory(BSTreeNode** pptree);//���ٺ���
void BSTreeInorder(BSTreeNode**pptree);//�������

