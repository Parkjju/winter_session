#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree2.h"
#include "LBS.h"

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	BTreeNode* pnode;
	int i = 0;

	for (i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
			SetData(pnode, exp[i] - '0');
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
	return 0;
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void ShowPrefixTypeExp(BTreeNode* bt, VisitFuncPtr action)
{
	PreorderTraverse(bt, action);
}
void ShowInfixTypeExp(BTreeNode* bt,VisitFuncPtr action)
{
	InorderTraverse(bt, action);
}
void ShowPostfixTypeExp(BTreeNode* bt,VisitFuncPtr action)
{
	PostorderTraverse(bt, action);
}

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}