/*first practical*/
#include<stdio.h>

int main()
{
	int option, num1, num2, result;
	printf("\nSimple Calculator: ");
	printf("\nSelect what you want to do");
	printf("\n1-Addition\n2-Subtraction\n3-Multiplication\n4-Division\n");
	scanf("%d", &option);
	printf("First number: ");
	scanf("%d", &num1);
	printf("Second number: ");
	scanf("%d", &num2);
	
	switch(option)
	{
		case 1:
			result = num1+num2;
			break;
		case 2:
			result = num1-num2;
			break;
		case 3:
			result = num1*num2;	
			break;
		case 4:
			result = num1 / num2;
			break;
	}

	printf("Result is %d\n", result);
	return 0;
}
