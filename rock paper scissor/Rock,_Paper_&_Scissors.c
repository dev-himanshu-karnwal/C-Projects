#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define PRINT_LINE for(i=0;i<100;i++)putchar('_');

void print_rules_and_instructions(void);
void view_menu(void);
int match_choices(void);

char computer_choice;
char user_choice;
unsigned int computer_wins;
unsigned int user_wins;
int i;

int main()
{
	short int result;
	time_t t;
	srand(time(&t));
	restart:
	print_rules_and_instructions();
	
	do
	{
		printf("Your Choice: ");
		user_choice=getch();
		
		switch (user_choice)
		{
			case '1':				// '1' is used for Rock
				printf("Rock");
				break;
			case '2':				// '2' is used for Paper
				printf("Paper");
				break;
			case '3':				// '3' is used for Scissor
				printf("Scissor");
				break;
			default:
				i=1;
				view_menu();
				
		}
		if(i==0)				//Block executed if choice made by user
		{
			computer_choice=(char)((rand()%3)+'1');		//rand() gives random number....created to 1/2/3 by modulus and add 1
			printf("\t\t\t\t\t\tComputer Choice:");
			switch (computer_choice)
			{
				case '1':				// '1' is used for Rock
					printf("Rock\n");
					break;
				case '2':				// '2' is used for Paper
					printf("Paper\n");
					break;
				case '3':				// '3' is used for Scissor
					printf("Scissor\n");
					break;
			}
			
			result=match_choices();
			switch (result)
			{
				case 0:
					puts("\t\t\t\t\tTIE");
					break;
				case 1:
					puts("\t\t\t\t\tYou Win");
					break;
				case -1:
					puts("\t\t\t\t\tComputer Win");
					break;
			}
			PRINT_LINE;
			putchar('\n');
		}
		i=0;
	}while(1);
	
	getch();
	return 0;
}
void print_rules_and_instructions(void)
{
	
	puts("\t\t\t\tThis is \"ROCK PAPER SCISSOR GAME\" Between You and Computer\n");
	puts("\t\t\t\t\t\t..........RULES..........");
	puts("At the same time You and Computer chooses one from rock/paper/scissor");
	puts("If both choose same then its a Tie\nElse,\tRock wins over Scissor\n\tScissor wins over Paper\n\tPaper wins over Rock");
	puts("\n\t\t\t\t\t\t.......INSTRUCTIONS.......");
	puts("Press\t'1' for Rock\n\t'2 for Paper\n\t'3' for Scissor\n\t and any other key to view Menu");
	puts("Press any key to start game");
	getch();
	puts("\n<------------------------------GAME STARTS------------------------------>\n\n");

}
void view_menu(void)
{
	char ch;
	do
	{
		printf("\n\nPress\t1 to view leaderboard\n\t2 to Continue game\n\t3 to Restart\n\tany other key to Exit");
		ch=getch();
		switch(ch)
		{
			case '1':
				printf("\n\nYour Score \t= %d points\n",user_wins);
				printf("Computer Score \t= %d points\n",computer_wins);
				if(user_wins==computer_wins)
					printf("Equal points : Draw till now\n");
				else if(user_wins>computer_wins)
					printf("You leading by %d points\n",user_wins-computer_wins);
				else
					printf("Computer leading by %d points\n",computer_wins-user_wins);
				break;	
			case '2':
				putchar('\n');
				PRINT_LINE;
				putchar('\n');
				break;
			case '3':
				user_wins=0;
				computer_wins=0;
				puts("\n<------------------------------GAME RESTARTS------------------------------>\n\n");
				break;
			default:
				printf("\n----------------------------------------------EXIT----------------------------------------------\n\n");
				exit(0);
		}
	}while(ch=='1'||ch=='3'||ch=='3');
}
int match_choices()
{
	
	if(user_choice==computer_choice)
	{
		return 0;		//Tie
	}
	else if((user_choice=='1' && computer_choice=='2')||(user_choice=='2' && computer_choice=='3')||(user_choice=='3' && computer_choice=='1'))
	{
		computer_wins++;
		return -1;		//Computer wins
	}
	else
	{
		user_wins++;
		return 1;		//User wins
	}
	
}
