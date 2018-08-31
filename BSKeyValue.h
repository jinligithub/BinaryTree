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

int BSTreeInsert(BSTreeNode**pptree, BSKeyType key, BSValueType value);//插入
int BSTreeRemove(BSTreeNode**pptree, BSKeyType key, BSValueType value);//删除
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSKeyType key);//查找
BSTreeNode* BSTree(BSTreeNode** pptree, BSKeyType key, BSValueType value);//查找


void BSTreeDretory(BSTreeNode** pptree);//销毁函数
void BSTreeInorder(BSTreeNode**pptree);//中序遍历