#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef char* BSKeyType;
typedef char* BSValueType;
typedef struct BsTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSKeyType key;
	BSValueType value;

}BSTreeNode;

int BSTreeInsert(BSTreeNode**pptree, BSKeyType key, BSValueType value);//����
int BSTreeRemove(BSTreeNode**pptree, BSKeyType key, BSValueType value);//ɾ��
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSKeyType key);//����
BSTreeNode* BSTree(BSTreeNode** pptree, BSKeyType key, BSValueType value);//����


void BSTreeDretory(BSTreeNode** pptree);//���ٺ���
void BSTreeInorder(BSTreeNode**pptree);//�������