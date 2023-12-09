#include<conio.h>
#include<stdio.h>

int main()
{
	char more=20,ch;
	int num,up = 0,lo = 0,n,mup = 0,mlo = 0,count=0;
	printf("Enter the Number to play:");
	scanf("%d",&num);
	printf("\nDo you want to give any hint range to the player?\n");
	printf("Press '1' if you want, \nOtherwise press any other key");
	ch=getch();
	switch(ch)
	{
		case '1':
			printf("\n\nEnter the uppermost range : ");
			scanf("%d",&up);
			printf("\nEnter the lowermost range : ");
			scanf("%d",&lo);		
			printf("\nDo you want to give more special hint range to the player?\n");
			printf("Press '1' if you want, \nOtherwise press any other key");
			ch=getch();
			
			switch(ch)
			{
				case '1':
					printf("\nEnter that more specified upper range that you want to give: ");
					scanf("%d",&mup);
					printf("\nEnter that more specified lower range that you want to give: ");
					scanf("%d",&mlo);
					break;
				default: 
					printf("\nSo, you choose to make it harder");
			}
			break;
			default: 
			printf("\nSo, you choose to make it hardest");
	}
	printf("\n\n<------The game starts, Hand over it to player------>");
	printf("\nPress any key to start");
	ch=getch();
	
	printf("\n\n\n<------The game starts------>");
	if((lo!=0)&&(up!=0))
	{
		printf("\nThe number lies between %d to %d\n",lo,up);
	}
	printf("\nChoose and Enter any number: ");
	do
	{
		scanf("%d",&n);
		count++;
		if(n<num)
		{
			if(n<lo)
			{
				printf("\nWhere are you going read the range carefully......Try Again: ");
			}
			else if(n<mlo)
			{
				printf("\nYou are far behind than target.....Try Again: ");
			}
			else
			{
				printf("\nYou are just behind than target.....Try Again:  ");
			}
		}
		else if(n>num)
		{
			if(n>up)
			{
				printf("\nWhere are you going read the range carefully.......Try Again:  ");
			}
			if(n>mup)
			{
				printf("\nYou have gone far away than target.....Try Again:  ");
			}
			else
			{
				printf("\nYou are just above than target.....Try Again:  ");
			}
		}
		else
		{
			printf("\n\nCONGRATULATIONS!!!!You made it..........in %d try/tries\n\n\n\n",count);
		}
	}while(n!=num);
	getch();
	return 0;
}

