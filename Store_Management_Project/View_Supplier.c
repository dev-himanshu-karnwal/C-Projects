#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"new supplier.c"
/*struct supplier
{
	char id[9];
	char name[25];
	char address[40];
	long int balance;
};*/


int main()
{
	FILE *view_supplier_file=fopen("Suppliers record.txt","rb");
	struct supplier view_supplier;
	char search_id[9];
	char ch;
	register int i;
	
	if(view_supplier_file==NULL)
	{
		system("cls");
		
		fclose(view_supplier_file);
			
		printf("No Previous suppliers data exists\n");
		printf("Press 1-> Want to add suppliers\n");
		printf("Press any other key -> Go to back screen\n");
		
		fflush(stdin);
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
				new_supplier();
				break;
				
			default:
				
				return;
				
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
					fseek(view_supplier_file,0,SEEK_SET);
					
					system("cls");
			
					printf("Enter ID of Supplier whose data is to be viewed: ");
					fflush(stdin);
					gets(search_id);
			
					while(fread(&view_supplier,sizeof(view_supplier),1,view_supplier_file)!=0)
					{
	
						if(strcmp(view_supplier.id,search_id)==0)
						{
							system("cls");
							printf("Current Record of entered ID supplier..\n\n");
							printf("ID          : %s\n",view_supplier.id);
							printf("Name        : %s\n",view_supplier.name);
							printf("Address     : %s\n",view_supplier.address);
							printf("Balance     : %ld\n",view_supplier.balance);
					
							break;
						}
					}
					if(feof(view_supplier_file))
					{
						printf("\nINVALID ID ENTERED!  No such ID exists, Try again...");
					}
					else
					{
						printf("\nPress Esc key to go back else press any other key to search for another supplier");
						
						fflush(stdin);
						ch=getch();
					}
			
					sleep(2);
				}while(ch!=27);		//Loop continue till Esc key pressed
				
				break;
			
			default:
			
				fseek(view_supplier_file,0,SEEK_SET);
			   
				printf("\n\n   ID     NAME                           ADDRESS                                 BALANCE\n\n");
				while(fread(&view_supplier,sizeof(view_supplier),1,view_supplier_file)!=0)
				{
					printf("%-9s %-30s %-40s %ld\n",view_supplier.id,view_supplier.name,view_supplier.address,view_supplier.balance);
					i++;
					
					if(i==20)
					{
						printf("\n\n\n\t\t\t\t\tPress any key to continue watching next record....");
						getch();
						i=0;
					}
				}
				
		}
		
		fclose(view_supplier_file);
	}
	
	getch();
	return 0;
}

