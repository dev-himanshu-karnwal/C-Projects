// To check weather entered credit card number is valid or not...
#include<stdio.h>
int main()
{
	int card[17];
	int *p,i,sum=0;
	printf("Enter credit card number:\n");
	for(p=card,i=0;p<card+16;p++,i++)
	{
		scanf("%1d",p);
		if(i%2==0)
		{
			*p*=2;
			if(*p>9)
			{
				*p-=9;
			}
		}
		sum+=*p;
	}
	for(p=card,i=0;p<card+16;p++)
	{
		printf("\n%d",*p);
	}
	if(sum%10==0)
	{
		printf("\nValid");
	}
	return 0;
}
