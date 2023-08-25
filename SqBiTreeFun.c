#include"SqBiTree.h"


// ��ӡ����ַ�
void SBTreePrint(SBTElemType c)
{
	printf("%c ",c);
}

// ��ʼ�����������
void SBTreeInit(SBTree* SBT)
{
	SBT->p.level = SBT->p.order = NIL;
	int i = 0;
	for (i = 0; i < MAX_TREE_SIZE; i++)
	{
		SBT->nodes[i] = NIL;
	}

}

//����һ��������
void SBTreeCreate(SBTree* SBT)
{
	assert(SBT);
	int n = 0,i;
	printf("�������ܽڵ����: �ڵ���� <%d  ",MAX_TREE_SIZE);
	scanf("%d",&n);
	printf("ע�������Ҫ������λ�������� 0 \n");
	assert(n<= MAX_TREE_SIZE) ;
	SBTElemType tmp;
	for (i = 0; i < n; i++)
	{

		fflush(stdin);
		printf("������� %d ���ڵ������:>",i+1 );
		scanf("%c",&tmp);
		if (tmp != '0')
		{
			SBT->nodes[i] = tmp;
		}

		printf("\n");

	}

}

//�������Ƿ�Ϊ�� 
bool SBTreeEmpty(SBTree* SBT)
{
	assert(SBT);


	if (SBT->nodes[0] == NIL) //���ڵ���ֵ ����Ϊֵ����Ϊ��    �޸� ������
	{ 
		return true; 
	}
	else
	{
		return false;
	}

}

//�����������
int SBTreeDepth(SBTree* SBT)
{
	int n, i;
	i = MAX_TREE_SIZE-1;
	while (SBT->nodes[i] == NIL) //��֤���ҵ��˴��������һ��Ԫ��
	{
		i--;
	}
	n = i + 1; // n��ʾ�ܹ��ж��ٸ�Ԫ��
	i = 1; // i ��ʾ��

	while (n > (int)pow(2,i)-1)
	{
		i++;
	}
	
	return i;


}

//�������ĸ��ڵ�
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


//��e���ش˽��(�㣬�������)��ֵ  
void SBTreeValue(SBTree* SBT, Position p, SBTElemType* e)
{
	assert(SBT);
	assert(p.level <= SBTreeDepth(SBT));//�������ܴ��������
	assert(p.order <= (int)pow(2, p.level-1)); //��Ų��ܴ��ڱ������ڵ����

	int i = PositionFind(SBT, p);

	*e = SBT->nodes[i];

}

//�ѵ�ǰλ�ã��㣬������ţ���ֵ ��ֵΪval
void SBTreeAssgin(SBTree* SBT, Position p, SBTElemType val)
{
	assert(SBT);
	assert(p.level <= SBTreeDepth(SBT));//�������ܴ�������s
	assert(p.order <= (int)pow(2, p.level - 1)); //��Ų��ܴ��ڱ������ڵ����
	
	int i = PositionFind(SBT, p);

	if (SBT->nodes[(int)(i + 1) / 2 - 1] == NIL)//���ܸ�˫��Ϊ �յ� Ҷ�Ӹ�ֵ
	{
		assert(0);
	}

	if (val == NIL && (SBT->nodes[2 * i + 1] != NIL || SBT->nodes[2 * i + 2] != NIL))//���ܸ���Ҷ��˫�׸���ֵ 
	{
		assert(0);
	}

	SBT->nodes[i] = val;

}


//����ҵ���e �򷵻��±� �Ҳ������� -1
int FindE(SBTree* SBT, SBTElemType e)
{
	//��Ϊ���ڵ���˫��
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

//����e��˫�׽ڵ� ���޷��� �� ~ NIl
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



//����e�����ӽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeLeftChild(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if ( i != -1)  //�ҵ���λ��
	{
		if (SBT->nodes[2 * i + 1] != NIL)// �Ƿ�������
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

//����e���Һ��ӽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeRightChild(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if (i != -1) //�ҵ���λ��
	{
		if (SBT->nodes[2 * i + 2] != NIL) // �Ƿ�������
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

//����e�����ֵܽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeLeftSibling(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if (i != -1) //�ҵ���λ��
	{
		if ( i % 2 == 0)//ֻ���±�Ϊż����ʱ��������ֵ�
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

//����e�����ֵܽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeRightSibling(SBTree* SBT, SBTElemType e)
{
	assert(SBT);
	int i = FindE(SBT, e);
	if (i != -1) //�ҵ���λ��
	{
		if (i % 2 != 0)//ֻ���±�Ϊ������ʱ������ұ��ֵ�
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

//�ݹ������������ �� �ң�
void PreTraverse(SBTree* SBT,int e)
{
	SBTreePrint(SBT->nodes[e]); // ��
	if (SBT->nodes[(2 * e) + 1] != NIL) //��������Ϊ��
	{
		PreTraverse(SBT, 2 * e + 1);
	}
	if (SBT->nodes[(2 * e) + 2] != NIL)
	{
		PreTraverse(SBT, 2 * e + 2);
	}

}
//���������
void  SBTreePreOrderTraverse(SBTree* SBT)
{
	assert(SBT);
	//�����ֶ��ѵڸ�����ȥ �����޷����еݹ����
	PreTraverse(SBT,0);
	printf("\n");
}


//�ݹ�������� (��   ��  ��)
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

//�������
void SBTreeInOrderTraverse(SBTree* SBT)
{
	assert(SBT);
	//�����ֶ��ѵڸ�����ȥ �����޷����еݹ����
	InTraverse(SBT, 0);
	printf("\n");
}


//�ݹ������� (��   ��  ��)
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
//��������
void SBTreePostOrderTraverse(SBTree* SBT)
{

	assert(SBT);
	//�����ֶ��ѵڸ�����ȥ �����޷����еݹ����
	PostTraverse(SBT, 0);
	printf("\n");

}

//�������
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


//��ն����� == ����
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