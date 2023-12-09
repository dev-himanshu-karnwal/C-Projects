#include<stdio.h>
#include<conio.h>
int main()
{
	int acc_no=123456,bal,tran;
	char name[15];
	char ch;
	do
	{
		printf("\n\nSelect any of the option: \n");
		printf("\nPress 1 for creating new account:\n");
		printf("Press 2 for Withdrawing money:\n");
		printf("Press 3 for Depositing money:\n");
		printf("Press any other key for exit:\n");
		ch=getch();
		
		switch(ch)
		{
			case '1':
				printf("Enter your Name:");
				scanf("%s",&name);
				printf("Your Account number is: %d\n",acc_no);
				printf("Enter your Opening balance: ");
				scanf("%d",&bal);
				printf("Congratulations, %s Your Account has been successfully created.....",name);
				break;
			case '2':
				printf("Enter your Account number\n");
				scanf("%d",&acc_no);
				if(acc_no==123456)
				{
					printf("Enter the Amount you want to withdraw: ");
					scanf("%d",&tran);
					if(tran>bal)
					{
						printf("\nInsufficient balance");
					}
					else
					{
						bal=bal-tran;
						printf("\nCongratulations, %s You have successfully withdrawn --->%d<---",name,tran);
						printf("\nYour updated balance is %d",bal);
					}
					break;
				}
				else
				{
					printf("\nInvalid account number.....");
				}
			case '3':
				printf("Enter your Account number\n");
				scanf("%d",&acc_no);
				if(acc_no==123456)
				{
					printf("Enter the Amount you want to deposit: ");
					scanf("%d",&tran);
					bal=bal+tran;
					printf("\nCongratulations, %s You have successfully deposited --->%d<---",name,tran);
					printf("\nYour updated balance is %d",bal);
					break;
				}
				else
				{
					printf("\nInvalid account number.....");
				}
			default:
				printf("\nYou have Presssed a Random key\nSo, Good bye.....");			
		}
	}while((ch=='1')||(ch=='2')||(ch=='3'));
	getch();
	return 0;
}
