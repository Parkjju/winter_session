#include <stdio.h>
#include "btree.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* btree = (BTreeNode*)malloc(sizeof(BTreeNode));
	btree->left = NULL;
	btree->right = NULL;
	return btree;
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

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left,action);
	PostorderTraverse(bt->right,action);
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

BTreeNode* DeleteTree(BTreeNode* bt,DelFuncPtr action)
{
	BTreeNode* rpos = bt;
	if (bt == NULL)
		return;
	DeleteTree(bt->left, action);
	DeleteTree(bt->right, action);
	action(bt);
	return rpos;
}