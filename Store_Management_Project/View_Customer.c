#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
//#include "new customer.c"
struct customer
{
	char id[9];
	char name[25];
	char address[40];
	long int balance;
};

int main()
{
	FILE *view_customer_file=fopen("Customers record.txt","rb");
	struct customer view_customer;
	char search_id[9];
	char ch;
	register int i;
	
	if(view_customer_file==NULL)
	{
		system("cls");
		
		printf("No Previous customers data exists\n");
		printf("Press 1-> Want to add customers\n");
		printf("Press any other key -> Go to back screen\n");
		
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
//				new_customer();
				break;

			default:
				
				printf("\nINVALID KEY PRESSED! Press a Valid key");
				printf("\a");
				sleep(2);
		}
		
	}
	else
	{
		printf("How do you want to view record?\n");
		printf("Press 1-> Search by ID Individually\n");
		printf("Press any other key-> Show all together");
		
		fflush(stdin);
		ch=getch();
		
		switch(ch)
		{
			case '1':
				
				do
				{
					system("cls");
					
					fseek(view_customer_file,0,SEEK_SET);
					
					printf("Enter ID of Customer whose data is to be viewed: ");
					
					fflush(stdin);
					gets(search_id);
			
					while(fread(&view_customer,sizeof(view_customer),1,view_customer_file)!=0)
					{
						if(strcmp(view_customer.id,search_id)==0)
						{
							system("cls");
							printf("Current Record of entered ID customer..\n\n");
							printf("ID          : %s\n",view_customer.id);
							printf("Name        : %s\n",view_customer.name);
							printf("Address     : %s\n",view_customer.address);
							printf("Balance     : %ld\n",view_customer.balance);
					
							break;
						}
					}
					if(feof(view_customer_file))
					{
						printf("\nINVALID ID ENTERED!  No such ID exists, Try again...");
					}
					else
					{
						printf("\nPress Esc key to go back else press any other key to search for another customer");
						fflush(stdin);
						ch=getch();
					}
			
					sleep(2);
				}while(ch!=27);		//Loop continue till Esc key pressed
				
				break;
				
			default:
			
				printf("\n\n   ID     PASSWORD     NAME                          ADDRESS                              BALANCE\n\n");
				while(fread(&view_customer,sizeof(view_customer),1,view_customer_file)!=0)
				{
					printf("%-9s %-30s %-40s %ld\n",view_customer.id,view_customer.name,view_customer.address,view_customer.balance);
					i++;
					
					if(i==20)
					{
						printf("\n\n\n\n\n\n\t\t\t\t\tPress any key to continue watching next record....");
						fflush(stdin);
						getch();
						
						i=0;
						
					}
				}
		}
		
	}
	getch();
	return 0;
}

