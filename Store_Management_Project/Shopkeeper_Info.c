#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct shopkeeper
{
	char password[9];
	char name[25];
	char address[40];
};

int main()
{
	struct shopkeeper new_shopkeeper;
	char what_to_change;
	FILE *enter_shopkeeper_file=fopen("Shopkeeper record.txt","rb+");
	
	if(enter_shopkeeper_file==NULL)
	{
		enter_shopkeeper_file=fopen("Shopkeeper record.txt","wb");
		
		system("cls");
		
		printf("No previous Shopkeeper record! Enter New\n\n");
		
		printf("Enter Password: ");
		fflush(stdin);
		scanf("%8s",new_shopkeeper.password);
		
		printf("Enter the Name of New Shopkeeper: ");
		fflush(stdin);
		gets(new_shopkeeper.name);
		
		printf("Enter address: ");
		fflush(stdin);
		gets(new_shopkeeper.address);
		
		fwrite(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);		//Write the New shopkeeper record in file
		
		printf("\n\nSHOPKEEPER INFORMATION SUCCESSFULLY\n");
		
		fclose(enter_shopkeeper_file);
	
	}
	else
	{
		do
		{
			
			enter_shopkeeper_file=fopen("Shopkeeper record.txt","rb+");
			
			system("cls");
			
			fread(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);		//Read the New shopkeeper record from file
			
			printf("Current Information..\n\n");
			printf("Password    : %s\n",new_shopkeeper.password);
			printf("Name        : %s\n",new_shopkeeper.name);
			printf("Address     : %s\n\n",new_shopkeeper.address);
			
			printf("What do you want to change(Click corresponding Number Key):\n");
			printf("1. Password\n");
			printf("2. Name\n");
			printf("3. Address\n");
			printf("  \"Esc\" To go Back: ");
			
			fflush(stdin);
			what_to_change=getche();
			
			printf("\n\n\n");
			switch(what_to_change)
			{
				
				case '1':
					
					
					printf("Enter new Password: ");
					
					fflush(stdin);
					gets(new_shopkeeper.password);
					
					fseek(enter_shopkeeper_file,0,SEEK_SET);
					fwrite(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);
					printf("User Password updated\n");
					
					break;
				
				case '2':
					
					
					printf("Enter new Name: ");
					
					fflush(stdin);
					gets(new_shopkeeper.name);
					
					fseek(enter_shopkeeper_file,0,SEEK_SET);
					fwrite(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);
					printf("User Name updated\n");
					
					break;
				
				case '3':
					
					printf("Enter new Address: ");
					
					fflush(stdin);
					gets(new_shopkeeper.address);
					
					fseek(enter_shopkeeper_file,0,SEEK_SET);
					fwrite(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);
					printf("User Address updated\n");
					
					break;
				
				case 27:
					
					break;
					
					
				default:
					
					printf("\nINVALID KEY PRESSED! Press a Valid key");
					printf("\a");
					
			}
			
			sleep(2);
			
			fclose(enter_shopkeeper_file);
		
		}while(what_to_change!=27);
		
	}
	getch();
	return 0;
	
}


