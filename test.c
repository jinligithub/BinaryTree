#include"BSKeyValue.h"
void InitMyDict(BSTreeNode**pdict)
{
	assert(pdict);
	BSTreeInsert(pdict, "china", "�й�");//�ַ������ڴ�����
	BSTreeInsert(pdict, "love", "��");
	BSTreeInsert(pdict, "you", "��");
	BSTreeInsert(pdict, "forever", "��Զ");
}
void InitMyDict_Ch(BSTreeNode**pdict_Ch)
{
	assert(pdict_Ch);
	BSTreeInsert(pdict_Ch, "�й�", "china");
	BSTreeInsert(pdict_Ch,  "��", "love");
	BSTreeInsert(pdict_Ch, "��", "you");
	BSTreeInsert(pdict_Ch, "��Զ", "forever");
}
int main()
{

	int i = 0;
	//�����������Լ�Ҫ��ѯ�ĵ���
	char buf[20] = { 0 };
	BSTreeNode*mydict = NULL;
	BSTreeNode*mydict_Ch = NULL;
	BSTreeNode* ret = NULL;
	//���ʵ����������
	InitMyDict(&mydict);
	InitMyDict_Ch(&mydict_Ch);
	//��������ʵ�
	BSTreeInorder(&mydict);
	//����Ҫ���ҵĴʻ�
	printf("������Ҫ���ҵĴʻ�(please input what's your find word):\n");
	scanf("%s", &buf);
	//printf("������Ҫ���ҵ����ԣ����ģ�0  Ӣ�ģ�1��\n");
	//scanf("%d\n", &i);
	//if (i == 1)
	//{
	//	ret = BSTreeFind(&mydict, buf);
	//	if (ret != NULL)
	//		printf("%s\n", ret->value);
	//	else
	//		printf("û���ҵ������\n");
	//}
	//else
	//{
		ret = BSTreeFind(&mydict, buf);
		if (ret != NULL)
			printf("%s\n", ret->value);
		else
			printf("û���ҵ��������\n");
	//}
	system("pause");
	return 0;
}