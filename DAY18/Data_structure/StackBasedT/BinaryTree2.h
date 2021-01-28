#ifndef _BINARY_TREE2_H_
#define _BINARY_TREE2_H_

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

/*** BTreeNode 관련 연산들 ****/
BTreeNode* MakeExpTree(char exp[]);
BTreeNode* MakeBTreeNode(void);

int EvaluateExpTree(BTreeNode* bt);

typedef void VisitFuncPtr(int data);
void ShowPrefixTypeExp(BTreeNode* bt,VisitFuncPtr action);
void ShowInfixTypeExp(BTreeNode* bt,VisitFuncPtr action);
void ShowPostfixTypeExp(BTreeNode* bt,VisitFuncPtr action);

BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);


void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
void PostorderTraverse(BTreeNode* bt);
void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);

#endif