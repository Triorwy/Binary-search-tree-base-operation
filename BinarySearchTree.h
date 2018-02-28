# Binary-search-tree-base-operation
Binary search tree Insert and Find Delete

#include"BinarySearchTree.h"

BSTreeNode *BuyBSTreeNode(DataType x)//创建新节点
{
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	assert(node);
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

int BSTreeInsert(BSTreeNode **ppTree, DataType x)//插入一个节点
{
	BSTreeNode *cur = *ppTree;
	if ((*ppTree) == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 0;
	}
	while (cur)
	{
		if ((cur)->_data > x)
		{
			if ((cur)->_left == NULL)
			{
				(cur)->_left = BuyBSTreeNode(x);
				return 0;
			}
			else
			{
				cur = (cur)->_left;
			}
		}
		else if ((cur)->_data < x)
		{
			if ((cur)->_right == NULL)
			{
				(cur)->_right = BuyBSTreeNode(x);
				return 0;
			}
			else
			{
				(cur) = (cur)->_right;
			}
		}
		else
		{
			return -1;
		}
	}
	return 0;
}
const BSTreeNode *BSTreeFind(BSTreeNode *tree, DataType x)//查找一个节点
{
	assert(tree);
	while (tree)
	{
		if (tree->_data > x)
		{
			tree = tree->_left;
		}
		else if (tree->_data < x)
		{
			tree = tree->_right;
		}
		else
		{
			return tree;
		}
	}
	return NULL;
}
void BSTreeInOrder(BSTreeNode *tree)//中序遍历
{
	if (tree == NULL)
	{
		return;
	}
	BSTreeInOrder(tree->_left);
	printf("%d ", tree->_data);
	BSTreeInOrder(tree->_right);
}
int BSTreeRemove(BSTreeNode **ppTree, DataType x)//删除某个节点
{
	assert(*ppTree);
	BSTreeNode *cur = *ppTree;
	BSTreeNode *parent = cur;
	BSTreeNode *sub = NULL;
	
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
		{
			BSTreeNode *del = cur;//删除节点
			if (cur->_left == NULL)//左为空
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_right;
				}
				else if (parent->_right == cur)
				{
					parent->_right = cur->_right;
				}
				else
				{
					*ppTree = cur->_right;
				}
				
			}
			else if (cur->_right == NULL)//右为空
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_left;
				}
				else if (parent->_right == cur)
				{
					parent->_right = cur->_left;
				}
				else
				{
					*ppTree = cur->_left;
				}
				
			}
			else if (cur->_left != NULL && cur->_right != NULL)//左右都不为空
			{
				parent = cur;
				sub = cur->_right;
				while (sub->_left)
				{
					parent = sub;
					sub = sub->_left;
				}
				cur->_data = sub->_data;
				del = sub;
				if (parent->_left == sub)
				{
					parent->_left = sub->_right;
				}
				else
				{
					parent->_right = sub->_right;
				}
			}
			free(del);
			del = NULL;
			return 0;
		}
	}
	return -1;
}

int BSTreeInsertR(BSTreeNode** ppTree, DataType x)
{
	BSTreeNode *cur = *ppTree;
	if ((*ppTree) == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 0;
	}
	if ((cur)->_data > x)
	{
		BSTreeInsertR(&(cur)->_left, x);
	}
	else if ((cur)->_data < x)
	{
		BSTreeInsertR(&(cur)->_right, x);
	}
	else
	{
		return -1;
	}
	return 0;
}
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x)
{
	assert(tree);
	while (tree)
	{
		if (tree->_data > x)
		{
			return BSTreeFindR(tree->_left, x);
		}
		else if (tree->_data < x)
		{
			return BSTreeFindR(tree->_right, x);

		}
		else
		{
			return tree;
		}
	}
	return NULL;

}
int BSTreeRemoveR(BSTreeNode** ppTree, DataType x)
{
	BSTreeNode *del = NULL;
	if (*ppTree == NULL)
	{
		return -1;
	}
	if ((*ppTree)->_data > x)
	{
		BSTreeRemoveR(&((*ppTree)->_left), x);
	}
	else if ((*ppTree)->_data < x)
	{
		BSTreeRemoveR(&((*ppTree)->_right), x);
	}
	else
	{
		BSTreeNode *cur = *ppTree;
		del = cur;
		if (cur->_left == NULL)
		{
			*ppTree = cur->_right;
		}
		else if (cur->_right == NULL)
		{
			*ppTree = cur->_left;
		}
		else
		{
			BSTreeNode* sub = cur->_right;
			while (sub->_left)
			{
				sub = sub->_left;
			}
			cur->_data = sub->_data;
			del = sub;
			return BSTreeRemoveR(&((*ppTree)->_right), sub->_data);	
		}
		free(del);
		del = NULL;
		return 0;
	}


}
