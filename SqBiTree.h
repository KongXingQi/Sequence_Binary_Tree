#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

#define MAX_TREE_SIZE 50
#define NIL 0 //��Ч������


typedef char SBTElemType;

typedef struct
{
	int level, order; /* ���Ĳ�,�������(��������������) */

}Position;

typedef struct
{

	SBTElemType nodes[MAX_TREE_SIZE];
	Position p;
}SBTree;

//------------------------------------------------------------------------------------------------

// ��ӡ����ַ�
void SBTreePrint(SBTElemType c);

// ��ʼ�����������
void SBTreeInit(SBTree* SBT);

//����һ��������
void SBTreeCreate(SBTree* SBT);


//�������Ƿ�Ϊ��
bool SBTreeEmpty(SBTree* SBT);

//�����������
int SBTreeDepth(SBTree* SBT);

//�������ĸ��ڵ�
SBTElemType SBTreeRoot(SBTree* SBT);

//��e���ش˽��(�㣬�������)��ֵ  
void SBTreeValue(SBTree* SBT, Position p,SBTElemType* e);

//�ѵ�ǰλ�ã��㣬������ţ���ֵ ��ֵΪval
void SBTreeAssgin(SBTree* SBT,Position p,SBTElemType val);


//����e��˫�׽ڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeParent(SBTree* SBT,SBTElemType e);

//����e�����ӽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeLeftChild(SBTree* SBT, SBTElemType e);

//����e���Һ��ӽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeRightChild(SBTree* SBT, SBTElemType e);

//����e�����ֵܽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeLeftSibling(SBTree* SBT, SBTElemType e);

//����e�����ֵܽڵ� ���޷��� �� ~ NIl
SBTElemType SBTreeRightSibling(SBTree* SBT, SBTElemType e);


//���������
void  SBTreePreOrderTraverse(SBTree* SBT);

//�������
void SBTreeInOrderTraverse(SBTree* SBT);

//��������
void SBTreePostOrderTraverse(SBTree* SBT);

//�������
void SBTreeLevelOrderTraverse(SBTree* SBT);



//��ն�����
void SBTreeDestroy(SBTree* SBT);

//------------------------------------------------------------------------------------------
//����ҵ���e �򷵻��±� �Ҳ������� -1
int FindE(SBTree* SBT, SBTElemType e);

//�Ѳ��� ���к� �������� λ�� 
int PositionFind(SBTree* SBT, Position p);
