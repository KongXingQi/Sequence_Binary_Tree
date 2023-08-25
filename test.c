#include"SqBiTree.h"

void SBTreeTest1()
{
	SBTree T;
	SBTreeInit(&T);
	SBTreeCreate(&T);

	if (!SBTreeEmpty(&T))
	{
		printf("此树根为 %d \n",SBTreeDepth(&T));
		printf("此树根节点为 %c \n",SBTreeRoot(&T));
	}
	else
	{
		printf("此树为空 无根\n");
	}
	T.p.level = 3;
	T.p.order = 4;
	SBTElemType e = 0;
	SBTreeValue(&T, T.p, &e);
	printf("第 %d 层 第 %d 个元素是: %c \n", T.p.level, T.p.order, e);
	SBTreeAssgin(&T, T.p, 'M');
	SBTreeValue(&T, T.p, &e);
	printf("第 %d 层 第 %d 个元素改为: %c \n", T.p.level, T.p.order,e);




}

void SBTreeTest2()
{
	SBTree T;
	SBTreeInit(&T);
	SBTreeCreate(&T);

	if (!SBTreeEmpty(&T))
	{
		printf("此树根为 %d \n", SBTreeDepth(&T));
		printf("此树根节点为 %c \n", SBTreeRoot(&T));
	}
	else
	{
		printf("此树为空 无根\n");
	}
	T.p.level = 2;
	T.p.order = 1;
	SBTElemType e = 0;
	SBTreeValue(&T, T.p, &e);
	printf("第 %d 层 第 %d 个元素是: %c \n", T.p.level, T.p.order, e);
	printf("%c 的双亲是 %c \n", e, SBTreeParent(&T, e));
	printf("%c 的左孩子是 %c \n",e,SBTreeLeftChild(&T,e));
	printf("%c 的右孩子是 %c \n", e, SBTreeRightChild(&T, e));
	printf("%c 的右兄弟是 %c \n", e, SBTreeRightSibling(&T, e));
	printf("%c 的左兄弟是 %c \n", e, SBTreeLeftSibling(&T, e));

	printf("前序遍历: ");
	SBTreePreOrderTraverse(&T);
	printf("中序遍历: ");
	SBTreeInOrderTraverse(&T);
	printf("后序遍历: ");
	SBTreePostOrderTraverse(&T);
	printf("层序遍历: ");
	SBTreeLevelOrderTraverse(&T);

	SBTreeDestroy(&T);
	if (!SBTreeEmpty(&T))
	{
		printf("此树的根为 %c \n",SBTreeRoot(&T));
	}
	else
	{
		printf("此树为空 无根\n");
	}

}
 
int main()
{
	//SBTreeTest1();
	SBTreeTest2();
	return 0;
}