#include <stdio.h>
#include "IFtoPF.h"
#include "Cal.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%d \n", EvalRPNExp(exp1));
	printf("%d \n", EvalRPNExp(exp2));
	printf("%d \n", EvalRPNExp(exp3));

	return 0;
}