#include <string.h>
#include <ctype.h>
#include "ListBStack.h"

int EvalRPNExp(char exp[])
{
	int expLen = strlen(exp);

	Stack stack;
	StackInit(&stack);

	char tok;
	int op1, op2;
	int i = 0,idx=0;

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
			SPush(&stack, tok-'0');
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}

		}
	}
	return SPop(&stack);
}