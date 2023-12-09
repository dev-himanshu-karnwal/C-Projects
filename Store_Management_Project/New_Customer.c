#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct customer
{
	char id[9];
	char name[25];
	char address[40];
	long int balance;
};
int main()
{

	struct customer new_customer,check_id;
	FILE *enter_customer_file=fopen("Customers record.txt","ab+");
	FILE *check_customer_id=fopen("Customers record.txt","rb");
	char ch,end;
	
	if(enter_customer_file==NULL||check_customer_id==NULL)
	{
		perror("Can't open Customer Record File");
		exit(1);
	
	}
	else
	{
		do
		{
			enter_customer_file=fopen("Customers record.txt","ab+");
			check_customer_id=fopen("Customers record.txt","rb");
			
			do
			{
				system("cls");
			
				fseek(check_customer_id,0,SEEK_SET);
			
				printf("Enter the unique User ID of new Customer: ");
				fflush(stdin);
				gets(new_customer.id);
				
				while(fread(&check_id,sizeof(check_id),1,check_customer_id)!=0)
				{
					
					if(strcmp(new_customer.id,check_id.id)==0)
					{
						printf("Entered ID not Available! Try again\n");
						sleep(2);
						break;
					}
					
				}
				
			}while(!feof(check_customer_id));
						
			printf("Enter the Name of New Customer: ");
			fflush(stdin);
			gets(new_customer.name);
			
			printf("Enter address: ");
			fflush(stdin);
			gets(new_customer.address);
			
			printf("Enter Opening Balance(if any) else enter 0(zero): ");
			scanf("%ld",&new_customer.balance);
			
			fwrite(&new_customer,sizeof(new_customer),1,enter_customer_file);		//Write the New customer record in file
			
			printf("\n\nCUSTOMER ADDED SUCCESSFULLY\n");
			
			printf("\n\nAdd more Customers(y/n): ");
			do
			{
				fflush(stdin);
				ch=getch();
				
				if(ch=='y'||ch=='Y')
				{
					break;
				}
				else if(ch=='N'||ch=='n')
				{
					end='y';
					break;
				}
			}while(1);
	
			fclose(enter_customer_file);
			fclose(check_customer_id);
		
		}while(end!='y');
		
	}
	
	getch();
	return 0;
}

