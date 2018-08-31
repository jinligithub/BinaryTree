#include"BSKeyValue.h"
void InitMyDict(BSTreeNode**pdict)
{
	assert(pdict);
	BSTreeInsert(pdict, "china", "中国");//字符串存在代码区
	BSTreeInsert(pdict, "love", "爱");
	BSTreeInsert(pdict, "you", "你");
	BSTreeInsert(pdict, "forever", "永远");
}
void InitMyDict_Ch(BSTreeNode**pdict_Ch)
{
	assert(pdict_Ch);
	BSTreeInsert(pdict_Ch, "中国", "china");
	BSTreeInsert(pdict_Ch,  "爱", "love");
	BSTreeInsert(pdict_Ch, "你", "you");
	BSTreeInsert(pdict_Ch, "永远", "forever");
}
int main()
{

	int i = 0;
	//建立数组存放自己要查询的单词
	char buf[20] = { 0 };
	BSTreeNode*mydict = NULL;
	BSTreeNode*mydict_Ch = NULL;
	BSTreeNode* ret = NULL;
	//往词典里添加内容
	InitMyDict(&mydict);
	InitMyDict_Ch(&mydict_Ch);
	//中序遍历词典
	BSTreeInorder(&mydict);
	//输入要查找的词汇
	printf("请输入要查找的词汇(please input what's your find word):\n");
	scanf("%s", &buf);
	//printf("请输入要查找的语言（中文：0  英文：1）\n");
	//scanf("%d\n", &i);
	//if (i == 1)
	//{
	//	ret = BSTreeFind(&mydict, buf);
	//	if (ret != NULL)
	//		printf("%s\n", ret->value);
	//	else
	//		printf("没有找到这个词\n");
	//}
	//else
	//{
		ret = BSTreeFind(&mydict, buf);
		if (ret != NULL)
			printf("%s\n", ret->value);
		else
			printf("没有找到这个单词\n");
	//}
	system("pause");
	return 0;
}