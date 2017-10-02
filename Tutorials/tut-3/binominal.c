/*tutorial number 3*/
#include<stdio.h>
#include<math.h>

long factorial(long num);
long fun(long n, long r);

int main () 
{
	int n;
	printf("\nBinominal expansion (a + b)n:");
	printf("\nWrite n = ");
	scanf("%d", &n);
	if (n == 0){
		printf("\n1\n");
		return 0;
	}
	for(int r = 0; r <= n; ++r){
		printf("(%d * a^%d * b^%d) + ", fun(n,r), n-r, r);
	}

	return 0;
}

long factorial(long num)
{
	if (num < 2) return 1;
	return num * factorial(num-1);
}

long fun(long n, long r)
{
	return factorial(n)/(factorial(r)*factorial((n-r)));
}
