#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "ListBStack.h"

int Priority(char tok)
{
	switch (tok)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int Priority_of_two(char op1, char op2)
{
	if (Priority(op1) > Priority(op2))
		return 1;
	else if (Priority(op1) < Priority(op2))
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	int expLen = strlen(exp);
	Stack stack;
	char* convExp = (char*)malloc(expLen + 1);

	memset(convExp, 0, sizeof(char) * expLen + 1);
	int i, idx = 0;
	char tok, popOp;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
			convExp[idx++] = tok;
		else
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok);
				break;
			case ')':
			{
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			}
			case '+':
			case '-':
			case '*':
			case '/':
			{
				while (!SIsEmpty(&stack) && Priority_of_two(SPeek(&stack), tok) >= 0)
				{
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok);
				break;
			}

			}

		}
	}

	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);
	strcpy(exp, convExp);
	free(convExp);
}