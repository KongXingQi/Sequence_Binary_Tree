#include"SqBiTree.h"


// 打印这个字符
void SBTreePrint(SBTElemType c)
{
	printf("%c ",c);
}

// 初始化这个二叉树
void SBTreeInit(SBTree* SBT)
{
	SBT->p.level = SBT->p.order = NIL;
	int i = 0;
	for (i = 0; i < MAX_TREE_SIZE; i++)
	{
		SBT->nodes[i] = NIL;
	}

}

//构造一个二叉树
void SBTreeCreate(SBTree* SBT)
{
	assert(SBT);
	int n = 0,i;
	printf("请输入总节点个数: 节点个数 <%d  ",MAX_TREE_SIZE);
	scanf("%d",&n);
	printf("注意如果需要跳过该位置请输入 0 \n");
	assert(n<= MAX_TREE_SIZE) ;
	SBTElemType tmp;
	for (i = 0; i < n; i++)
	{

		fflush(stdin);
		printf("请输入第 %d 个节点的数据:>",i+1 );
		scanf("%c",&tmp);
		if (tmp != '0')
		{
			SBT->nodes[i] = tmp;
		}

		printf("\n");

	}

}

//检测此树是否为空 
bool SBTreeEmpty(SBTree* SBT)
{
	assert(SBT);


	if (SBT->nodes[0] == NIL) //根节点无值 就以为值此树为空    无根 则无树
	{ 
		return true; 
	}
	else
	{
		return false;
	}

}

//返回树的深度
int SBTreeDepth(SBTree* SBT)
{
	int n, i;
	i = MAX_TREE_SIZE-1;
	while (SBT->nodes[i] == NIL) //就证明找到了此树的最后一个元素
	{
		i--;
	}
	n = i + 1; // n表示总共有多少个元素
	i = 1; // i 表示行

	while (n > (int)pow(2,i)-1)
	{
		i++;
	}
	
	return i;


}

//返回树的根节点
SBTElemType SBTreeRoot(SBTree* SBT)
{
	assert(SBT);
	assert(SBT->nodes[0] != NIL);

	return SBT->nodes[0];
}


int PositionFind(SBTree* SBT, Position p)
{


	int lev = p.level - 1;
	int ord = p.order - 1;
	int i = 0;

	while (lev--)
	{
		i = i * 2 + 1;
	}

	i += ord;
	return i;
}


//用e返回此结点(层，本层序号)的值  
void SBTreeValue(SBTree* SBT, Position p, SBTElemType* e)
{
	assert(SBT);
	assert(p.level <= SBTreeDepth(SBT));//层数不能大于树深度
	assert(p.order <= (int)pow(2, p.level-1)); //序号不能大于本层最大节点个数

	int i = PositionFind(SBT, p);

	*e = SBT->nodes[i];

}

//把当前位置（层，本层序号）的值 赋值为val
void SBTreeAssgin(SBTree* SBT, Position p, SBTElemType val)
{
	assert(SBT);
	assert(p.level <= SBTreeDepth(SBT));//层数不能大于树深s
	assert(p.order <= (int)pow(2, p.level - 1)); //序号不能大于本层最大节点个数
	
	int i = PositionFind(SBT, p);

	if (SBT->nodes[(int)(i + 1) / 2 - 1] == NIL)//不能给双亲为 空的 叶子赋值
	{
		assert(0);
	}

	if (val == NIL && (SBT->nodes[2 * i + 1] != NIL || SBT->nodes[2 * i + 2] != NIL))//不能给有叶子双亲赋空值 
	{
		assert(0);
	}

	SBT->nodes[i] = val;

}


//如果找到了e 则返回下标 找不到返回 -1
int FindE(SBTree* SBT, SBTElemType e)
{
	//因为根节点无双亲
	int i = 1;
	for (i = 1; i < MAX_TREE_SIZE; i++) // 
	{
		if (SBT->nodes[i] == e)
		{
			return i;
		}
	}

	return -1;
}

//返回e的双亲节点 若无返回 空 ~ NIl
SBTElemType SBTreeParent(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if (i != -1)  // 
	{
		return SBT->nodes[(i + 1) / 2 - 1];
	}
	else
	{
		return NIL;
	}
}



//返回e的左孩子节点 若无返回 空 ~ NIl
SBTElemType SBTreeLeftChild(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if ( i != -1)  //找到该位置
	{
		if (SBT->nodes[2 * i + 1] != NIL)// 是否有数据
		{
			return SBT->nodes[2 * i + 1]; //
		}
		else
		{
			return NIL;
		}

	}
	else
	{
		return NIL;
	}
}

//返回e的右孩子节点 若无返回 空 ~ NIl
SBTElemType SBTreeRightChild(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if (i != -1) //找到该位置
	{
		if (SBT->nodes[2 * i + 2] != NIL) // 是否有数据
		{
			return SBT->nodes[2 * i + 2]; //

		}
		else
		{
			return NIL;
		}
	}
	else
	{
		return NIL;
	}
}

//返回e的左兄弟节点 若无返回 空 ~ NIl
SBTElemType SBTreeLeftSibling(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if (i != -1) //找到该位置
	{
		if ( i % 2 == 0)//只有下标为偶数的时候才有左兄弟
		{
			return SBT->nodes[i - 1];
		}
		else
		{
			return NIL;
		}
	}
	else
	{
		return NIL;
	}

}

//返回e的右兄弟节点 若无返回 空 ~ NIl
SBTElemType SBTreeRightSibling(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if (i != -1) //找到该位置
	{
		if (i % 2 != 0)//只有下标为奇数的时候才有右边兄弟
		{
			return SBT->nodes[i + 1];
		}
		else
		{
			return NIL;
		}
	}
	else
	{
		return NIL;
	}
}

//递归先序遍历（根 左 右）
void PreTraverse(SBTree* SBT,int e)
{
	SBTreePrint(SBT->nodes[e]); // 根
	if (SBT->nodes[(2 * e) + 1] != NIL) //左子树不为空
	{
		PreTraverse(SBT, 2 * e + 1);
	}
	if (SBT->nodes[(2 * e) + 2] != NIL)
	{
		PreTraverse(SBT, 2 * e + 2);
	}

}
//先序遍历树
void  SBTreePreOrderTraverse(SBTree* SBT)
{
	assert(SBT);
	//必须手动把第个传过去 否则无法进行递归遍历
	PreTraverse(SBT,0);
	printf("\n");
}


//递归中序遍历 (左   根  右)
void InTraverse(SBTree* SBT, int e)
{

	if (SBT->nodes[2 * e + 1] != NIL)
	{
		InTraverse(SBT, 2 * e + 1);
	}

	SBTreePrint(SBT->nodes[e]);

	if (SBT->nodes[2 * e + 2] != NIL)
	{
		InTraverse(SBT, 2 * e + 2);

	}

}

//中序遍历
void SBTreeInOrderTraverse(SBTree* SBT)
{
	assert(SBT);
	//必须手动把第个传过去 否则无法进行递归遍历
	InTraverse(SBT, 0);
	printf("\n");
}


//递归后序遍历 (左   右  根)
void PostTraverse(SBTree* SBT, int e)
{

	if (SBT->nodes[2 * e + 1] != NIL)
	{
		PostTraverse(SBT, 2 * e + 1);
	}


	if (SBT->nodes[2 * e + 2] != NIL)
	{
		PostTraverse(SBT, 2 * e + 2);

	}

	SBTreePrint(SBT->nodes[e]);


}
//后续遍历
void SBTreePostOrderTraverse(SBTree* SBT)
{

	assert(SBT);
	//必须手动把第个传过去 否则无法进行递归遍历
	PostTraverse(SBT, 0);
	printf("\n");

}

//层序遍历
void SBTreeLevelOrderTraverse(SBTree* SBT)
{
	int i = MAX_TREE_SIZE-1;
	while (SBT->nodes[i] == NIL)
	{
		i--;
	}

	int k = 0;
	for (k = 0; k <= i; k++)
	{
		if (SBT->nodes[k] != NIL)
		{
			printf("%c ", SBT->nodes[k]);
		}
	}
	printf("\n");


}


//清空二叉树 == 销毁
void SBTreeDestroy(SBTree* SBT)
{
	SBT->p.level = NIL;
	SBT->p.order = NIL;

	int i = MAX_TREE_SIZE;
	while (SBT->nodes[i] == NIL)
	{
		i--;
	}

	int k = 0;
	for (k = 0; k <= i; k++)
	{
		if (SBT->nodes[k] != NIL)
		{
			SBT->nodes[k] = NIL;
		}
	}

}