#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct supplier
{
	char id[9];
	char name[25];
	char address[40];
	long int balance;
};

void new_supplier()
{
	struct supplier new_supplier,check_id;
	FILE *enter_supplier_file=fopen("Suppliers record.txt","ab+");
	FILE *check_supplier_id=fopen("Suppliers record.txt","rb");
	char ch,end;
	
	if(enter_supplier_file==NULL||check_supplier_id==NULL)
	{
		perror("Can't open Supplier Record File");
		exit(1);
	
	}
	else
	{
		do
		{
			enter_supplier_file=fopen("Suppliers record.txt","ab+");
			check_supplier_id=fopen("Suppliers record.txt","rb");
			
			do
			{
				system("cls");
				
				fseek(check_supplier_id,0,SEEK_SET);
				
				printf("Enter the unique User ID of new Supplier: ");
				fflush(stdin);
				gets(new_supplier.id);
				
				while(fread(&check_id,sizeof(check_id),1,check_supplier_id)!=0)
				{
					if(strcmp(new_supplier.id,check_id.id)==0)
					{
						printf("Entered ID not Available! Try again\n");
						sleep(2);
						break;
					}
					
				}
				
			}while(!feof(check_supplier_id));
			
			printf("Enter the Name of New Supplier: ");
			fflush(stdin);
			gets(new_supplier.name);
			
			printf("Enter address: ");
			fflush(stdin);
			gets(new_supplier.address);
			
			printf("Enter Opening Balance(if any) else enter 0(zero): ");
			scanf("%ld",&new_supplier.balance);
		
			fwrite(&new_supplier,sizeof(new_supplier),1,enter_supplier_file);		//Write the New supplier record in file
		
			printf("\n\nSUPPLIER ADDED SUCCESSFULLY\n");
			
			printf("\n\nAdd more Suppliers(y/n): ");
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
	
			fclose(enter_supplier_file);
			fclose(check_supplier_id);
	
		}while(end!='y');
		
	}
	
	getch();
//	return 0;
}

