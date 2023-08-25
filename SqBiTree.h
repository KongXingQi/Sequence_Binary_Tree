#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

#define MAX_TREE_SIZE 50
#define NIL 0 //无效的数据


typedef char SBTElemType;

typedef struct
{
	int level, order; /* 结点的层,本层序号(按满二叉树计算) */

}Position;

typedef struct
{

	SBTElemType nodes[MAX_TREE_SIZE];
	Position p;
}SBTree;

//------------------------------------------------------------------------------------------------

// 打印这个字符
void SBTreePrint(SBTElemType c);

// 初始化这个二叉树
void SBTreeInit(SBTree* SBT);

//构造一个二叉树
void SBTreeCreate(SBTree* SBT);


//检测此树是否为空
bool SBTreeEmpty(SBTree* SBT);

//返回树的深度
int SBTreeDepth(SBTree* SBT);

//返回树的根节点
SBTElemType SBTreeRoot(SBTree* SBT);

//用e返回此结点(层，本层序号)的值  
void SBTreeValue(SBTree* SBT, Position p,SBTElemType* e);

//把当前位置（层，本层序号）的值 赋值为val
void SBTreeAssgin(SBTree* SBT,Position p,SBTElemType val);


//返回e的双亲节点 若无返回 空 ~ NIl
SBTElemType SBTreeParent(SBTree* SBT,SBTElemType e);

//返回e的左孩子节点 若无返回 空 ~ NIl
SBTElemType SBTreeLeftChild(SBTree* SBT, SBTElemType e);

//返回e的右孩子节点 若无返回 空 ~ NIl
SBTElemType SBTreeRightChild(SBTree* SBT, SBTElemType e);

//返回e的左兄弟节点 若无返回 空 ~ NIl
SBTElemType SBTreeLeftSibling(SBTree* SBT, SBTElemType e);

//返回e的右兄弟节点 若无返回 空 ~ NIl
SBTElemType SBTreeRightSibling(SBTree* SBT, SBTElemType e);


//先序遍历树
void  SBTreePreOrderTraverse(SBTree* SBT);

//中序遍历
void SBTreeInOrderTraverse(SBTree* SBT);

//后续遍历
void SBTreePostOrderTraverse(SBTree* SBT);

//层序遍历
void SBTreeLevelOrderTraverse(SBTree* SBT);



//清空二叉树
void SBTreeDestroy(SBTree* SBT);

//------------------------------------------------------------------------------------------
//如果找到了e 则返回下标 找不到返回 -1
int FindE(SBTree* SBT, SBTElemType e);

//把层数 序列号 穿过来找 位置 
int PositionFind(SBTree* SBT, Position p);
