#include <stdio.h>
#include "BinaryTree2.h"

void ShowData(int data)
{
	if (data >= 0 && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
int main(void)
{
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("���� ǥ����� ���� : ");
	ShowPrefixTypeExp(eTree, ShowData);
	printf("\n");

	printf("���� ǥ����� ���� : ");
	ShowInfixTypeExp(eTree, ShowData);
	printf("\n");

	printf("���� ǥ����� ���� : ");
	ShowPostfixTypeExp(eTree, ShowData);
	printf("\n");

	printf("������ : %d \n", EvaluateExpTree(eTree));

	return 0;

}