#include"BinarySearchTree.h"
void TestInsert()
{
	int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int i = 0;
	BSTreeNode *stree = NULL;
	BSTreeNode* pos = NULL;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		BSTreeInsert(&stree, arr[i]);
	}
	BSTreeInorder(&stree);
	printf("\n");
	//BSTreeInsert_R(&stree, 25);
	//BSTreeInorder(&stree);
	//printf("\n");
	//BSTreeInsert_R(&stree, 36);
	//BSTreeInorder(&stree);
	//printf("\n");
	//BSTreeInsert_R(&stree, 99);
	//BSTreeInorder(&stree);
	//printf("\n");
	BSTreeRemove(&stree, 45);
	BSTreeInorder(&stree);
	printf("\n");
	//pos = BSTreeFind_R(*(&stree), 17);
	//if (pos != NULL)
	//{
	//	printf("�ҵ���\n");
	//	//printf("%d\n", pos->_data);//Ϊʲô��ӡ������pos ��ֵ
	//}
	//BSTreeRemove(&stree, 31);
	//BSTreeInorder(&stree);
	//printf("\n");
}
int main()
{
	TestInsert();
	//free(NULL);
	system("pause");
	return 0;
}