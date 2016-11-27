#include <stdio.h>
#include <stdlib.h>

int main()
{
	int test;
	scanf("%d",&test);
	printf("%d\n",test);
	time_t t;
	srand((unsigned) time(&t));
	while(test--)
	{
		int i, n;
		n = 5; printf("%d\n",n);
		for( i = 0 ; i < n ; i++ )
			printf("%d ", rand() % 10); printf("\n");
	}
	return(0);
}
