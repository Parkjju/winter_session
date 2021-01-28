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

	printf("전위 표기법의 수식 : ");
	ShowPrefixTypeExp(eTree, ShowData);
	printf("\n");

	printf("중위 표기법의 수식 : ");
	ShowInfixTypeExp(eTree, ShowData);
	printf("\n");

	printf("후위 표기법의 수식 : ");
	ShowPostfixTypeExp(eTree, ShowData);
	printf("\n");

	printf("연산결과 : %d \n", EvaluateExpTree(eTree));

	return 0;

}