# Binary-search-tree-base-operation
Binary search tree Insert and Find Delete

#pragma once

#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode *_left;
	struct BSTreeNode *_right;
	DataType _data;

}BSTreeNode;

int BSTreeInsert(BSTreeNode **ppTree, DataType x);//插入一个节点
const BSTreeNode *BSTreeFind(BSTreeNode *tree, DataType x);//查找一个节点
void BSTreeInOrder(BSTreeNode *tree);//中序遍历
int BSTreeRemove(BSTreeNode **ppTree,DataType x);//删除某个节点

/////////////////////////////////////////////////////// 
// 递归 
int BSTreeInsertR(BSTreeNode** ppTree, DataType x);
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x);
int BSTreeRemoveR(BSTreeNode** ppTree, DataType x);
