#include"SqBiTree.h"

void SBTreeTest1()
{
	SBTree T;
	SBTreeInit(&T);
	SBTreeCreate(&T);

	if (!SBTreeEmpty(&T))
	{
		printf("������Ϊ %d \n",SBTreeDepth(&T));
		printf("�������ڵ�Ϊ %c \n",SBTreeRoot(&T));
	}
	else
	{
		printf("����Ϊ�� �޸�\n");
	}
	T.p.level = 3;
	T.p.order = 4;
	SBTElemType e = 0;
	SBTreeValue(&T, T.p, &e);
	printf("�� %d �� �� %d ��Ԫ����: %c \n", T.p.level, T.p.order, e);
	SBTreeAssgin(&T, T.p, 'M');
	SBTreeValue(&T, T.p, &e);
	printf("�� %d �� �� %d ��Ԫ�ظ�Ϊ: %c \n", T.p.level, T.p.order,e);




}

void SBTreeTest2()
{
	SBTree T;
	SBTreeInit(&T);
	SBTreeCreate(&T);

	if (!SBTreeEmpty(&T))
	{
		printf("������Ϊ %d \n", SBTreeDepth(&T));
		printf("�������ڵ�Ϊ %c \n", SBTreeRoot(&T));
	}
	else
	{
		printf("����Ϊ�� �޸�\n");
	}
	T.p.level = 2;
	T.p.order = 1;
	SBTElemType e = 0;
	SBTreeValue(&T, T.p, &e);
	printf("�� %d �� �� %d ��Ԫ����: %c \n", T.p.level, T.p.order, e);
	printf("%c ��˫���� %c \n", e, SBTreeParent(&T, e));
	printf("%c �������� %c \n",e,SBTreeLeftChild(&T,e));
	printf("%c ���Һ����� %c \n", e, SBTreeRightChild(&T, e));
	printf("%c �����ֵ��� %c \n", e, SBTreeRightSibling(&T, e));
	printf("%c �����ֵ��� %c \n", e, SBTreeLeftSibling(&T, e));

	printf("ǰ�����: ");
	SBTreePreOrderTraverse(&T);
	printf("�������: ");
	SBTreeInOrderTraverse(&T);
	printf("�������: ");
	SBTreePostOrderTraverse(&T);
	printf("�������: ");
	SBTreeLevelOrderTraverse(&T);

	SBTreeDestroy(&T);
	if (!SBTreeEmpty(&T))
	{
		printf("�����ĸ�Ϊ %c \n",SBTreeRoot(&T));
	}
	else
	{
		printf("����Ϊ�� �޸�\n");
	}

}
 
int main()
{
	//SBTreeTest1();
	SBTreeTest2();
	return 0;
}