#include <stdio.h>
int main()
{
	int n;
	double fact(double n);
	scanf("%d", &n);
	printf("%g\n", fact(n));
	return 0;
}

double fact(double n)
{
	int i;
	double sum = 1, a = 0;

	for (i = 1; i <= n; i++)
	{
		sum *= i;
		a += 1 / sum;
	}
	return a;
}