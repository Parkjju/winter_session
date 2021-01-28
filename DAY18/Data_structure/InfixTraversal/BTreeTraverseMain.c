#include <stdio.h>
#include "btree.h"

void ShowData(int);
void DelNode(BTreeNode*);

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	InorderTraverse(bt1,ShowData);
	printf("\n");
	PreorderTraverse(bt1, ShowData);
	printf("\n");
	PostorderTraverse(bt1,ShowData);
	printf("\n");

	DeleteTree(bt1, DelNode);
	return 0;
}

void ShowData(int data)
{
	printf("%d \n", data);
}

void DelNode(BTreeNode* dbt)
{
	int rdata = dbt->data;
	free(dbt);
	printf("Data Deleted ! : %d \n",rdata);
}