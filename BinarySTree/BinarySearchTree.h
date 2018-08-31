#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//收索二叉树插入删除查找递归与非递归的实现

typedef int BSDataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSDataType _data;
}BSTreeNode;

//非递归
int BSTreeInsert(BSTreeNode**pptree, BSDataType x);//收索二叉树的插入
int BSTreeRemove(BSTreeNode**pptree, BSDataType x);//收索二叉树的删除
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSDataType x);//收索二叉树的查找

//递归
int BSTreeInsert_R(BSTreeNode**pptree, BSDataType x);
int BSTreeRemove_R(BSTreeNode**pptree, BSDataType x);
BSTreeNode* BSTreeFind_R(BSTreeNode** pptree, BSDataType x);

void BSTreeDretory(BSTreeNode** pptree);//销毁函数
void BSTreeInorder(BSTreeNode**pptree);//中序遍历

