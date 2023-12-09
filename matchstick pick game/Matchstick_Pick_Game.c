#include <stdio.h>
#include <conio.h>

int main()
{
	unsigned short ms=21,pick;
	printf("	RULES FOR THIS MATCHSTICK GAME ARE:\n\n");
	printf("->	There are 21 mathsticks.\n");
	printf("->	You have to Pick 1,2,3 or 4 matchsticks.\n");
	printf("->	After you picks, I will pick in the same way.\n");
	printf("->	It continues till the matchsticks are over.\n");
	printf("->	Whoever picks the last matchstick loses the game.\n");
	while(ms>1)
	{
		printf("\n\nThere are %hu matchsticks remaining.\n",ms);
		printf("Pick your choice: ");
		scanf("%hd",&pick);
		if(pick>0&&pick<5)
		{
			printf("\nMy choice is: %hu",5-pick);
			ms=ms-5;
		}
		else
		{
			printf("\nInvalid choice. Do it again\n");
		}
	}
	printf("\nThere is %hu matchstick remaining which you have to pick.\n",ms);
	printf("\n\nCONGRATULATIONS....I win....");
	getch();
	return 0;
}
