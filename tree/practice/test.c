#include <stdio.h>

int main()
{
	int a[10];
	int i = 0;
	int ch;
	while ((ch = fgetc(stdin)) != '\n') {
		if (ch == ' ' || ch == ',')
			continue;
		ungetc(ch, stdin);
		scanf("%d", &a[i++]);
	}
           
	for(int j=0;j<i;j++)
	{
	    printf("%d ",a[j]);
	}
	return 0;
}

