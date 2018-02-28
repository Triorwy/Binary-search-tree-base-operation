#include"BinarySearchTree.h"


void Test()
{
	BSTreeNode *tree = NULL;
	BSTreeInsert(&tree, 4);
	BSTreeInsert(&tree, 2);
	BSTreeInsert(&tree, 1);
	BSTreeInsert(&tree, 3);
	BSTreeInsert(&tree, 5);
	BSTreeInsert(&tree, 2);
	const BSTreeNode *node = BSTreeFindR(tree, 1);
	printf("Find 1 ?%d\n", node->_data);
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTreeNode *tree = NULL;
	int len = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < len; i++)
	{
		BSTreeInsertR(&tree, a[i]);
	}
	BSTreeInOrder(tree); 
	printf("\n"); 

	BSTreeRemoveR(&tree, 4);
	BSTreeRemoveR(&tree, 8);
	BSTreeRemoveR(&tree, 3);
	BSTreeRemoveR(&tree, 7);
	BSTreeRemoveR(&tree, 5);


	BSTreeInOrder(tree);
	printf("\n");
//测试用例
	BSTreeRemove(&tree, 0);
	BSTreeRemove(&tree, 1); 
	BSTreeRemove(&tree, 2); 
	BSTreeRemove(&tree, 3); 
	BSTreeRemove(&tree, 4); 
	BSTreeRemove(&tree, 5); 
	BSTreeRemove(&tree, 6); 
	BSTreeRemove(&tree, 7); 
	BSTreeRemove(&tree, 8); 
	BSTreeRemove(&tree, 9);

	BSTreeInOrder(tree);
	printf("\n");
}

int main()
{
	//Test();
	TestBSTree();
	system("pause");
	return 0;
}
