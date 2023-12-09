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

struct shopkeeper
{
	char password[9];
	char name[25];
	char address[40];
};

struct DATE
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct TIME
{
	unsigned short hour;
	unsigned short minute;
	char med[5];
};

struct transaction_info
{
	char id[9];
	unsigned int invoice;
	struct DATE date;
	struct TIME time;
	char mode[6];
	unsigned int items;
};

struct transaction_item
{
	char product[30];
	unsigned int quantity;
	double price;	
};

struct inventory_stock
{
	char product[30];
	unsigned int quantity;
};

int main()
{
	
	
	FILE *purchase_info_file=fopen("Purchases Information.txt","rb");
	FILE *view_supplier_file=fopen("Suppliers record.txt","rb+");
	FILE *purchase_transaction_file;
	FILE *inventory_file=fopen("Inventory record.txt","rb+");
	struct transaction_info purchase_info;
	struct transaction_item purchase_item;
	struct inventory_stock read_item;
	struct supplier view_supplier;
	char ch,end,out;
	unsigned short len;
	register int i;
	double invoice_total;
	
	
	if(purchase_info_file==NULL)
	{
		fclose(purchase_info_file);
		purchase_info_file=fopen("Purchases Information.txt","ab");
					getch();
		purchase_info.invoice=1;
	}
	else
	{
		fclose(purchase_info_file);
		purchase_info_file=fopen("Purchases Information.txt","ab+");
		
		fseek(purchase_info_file,-sizeof(purchase_info),SEEK_END);
		
		fread(&purchase_info,sizeof(purchase_info),1,purchase_info_file);
		
		purchase_info.invoice++;
	}
	
	if(inventory_file==NULL)
	{
		fclose(inventory_file);
		inventory_file=fopen("Inventory record.txt","wb+");
	}
	
	if(view_supplier_file==NULL)
	{
		system("cls");
			
		printf("No Previous suppliers data exists\n");
		printf("Press 1-> Want to add suppliers\n");
		printf("Press any other key -> Go to back screen\n");
		
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
//				new_supplier();
				break;
				
			default:
				
				fclose(view_supplier_file);
				return;
				
		}
		
	}
	
	do
	{
		
		do
		{
			system("cls");
			
			invoice_total=0;
			purchase_info.items=1;
			
			printf("Enter Supplier ID: ");
			
			fflush(stdin);
			scanf("%s",purchase_info.id);
				
			fseek(view_supplier_file,0,SEEK_SET);
			
			while(fread(&view_supplier,sizeof(view_supplier),1,view_supplier_file)!=0)
			{
				if(strcmp(view_supplier.id,purchase_info.id)==0)
				{
					i=0;		
					break;
				}
			}
			if(feof(view_supplier_file))
			{
				printf("  INVALID ID ENTERED!  No such ID exists, Try again...");
				sleep(2);
						
			}
		}while(i!=0);
		
		printf("Enter the Time (in hh:mm format): ");
		scanf("%hu/%hu",&purchase_info.time.hour,&purchase_info.time.minute);
		
		printf("In AM or PM(a/p): ");
		
		do
		{
			ch=getch();
			
			switch(ch)
			{
				case 'a':
				case 'A':
					
					puts("A.M.");
					strcpy(purchase_info.time.med,"A.M.");
					i=0;
					
					break;
					
				case 'p':
				case 'P':
					
					puts("P.M.");
					strcpy(purchase_info.time.med,"P.M.");
					i=0;
					
					break;
					
				default:
					
					len=printf("Press either 'A' or 'P'");
					sleep(1);
					
					for(i=0;i<len;i++)
					{
						printf("\b");
					}
					for(i=0;i<len;i++)
					{
						printf(" ");
					}
					for(i=0;i<len;i++)
					{
						printf("\b");
					}
					
			}
		}while(i!=0);
		
		printf("Enter the Date (in dd/mm/yyyy format): ");
		fflush(stdin);
		scanf("%hu/%hu/%hu",&purchase_info.date.day,&purchase_info.date.month,&purchase_info.date.year);
		
		printf("Enter Mode of Purchase: ");
		len=printf("Press '1'-> Cash / Press '2'-> Credit: ");
		
		do
		{	
			fflush(stdin);
			ch=getch();
		
			if(ch=='1'||ch=='2')
			{
				for(i=0;i<len;i++)
				{
					printf("\b");
				}
				for(i=0;i<len;i++)
				{
					printf(" ");
				}
					for(i=0;i<len;i++)
				{
					printf("\b");
				}
				
				if(ch=='1')
				{
					strcpy(purchase_info.mode,"Cash");
					puts("Cash");
				}
				else
				{
					strcpy(purchase_info.mode,"Credit");
					puts("Credit");				
				}
			}
			else
			{
				len=printf("Press either '1' or '2'");
				sleep(1);
				
				for(i=0;i<len;i++)
				{
					printf("\b");
				}
				for(i=0;i<len;i++)
				{
					printf(" ");
				}
				for(i=0;i<len;i++)
				{
					printf("\b");
				}
			}
		
		}while(ch!='1' && ch!='2');
		
		printf("\nAll Info. entered correctly.......Press any key to continue adding Items");
		getch();
		
		do
		{			
			system("cls");
			
			printf("Enter Item Name: ");
			gets(purchase_item.product);
			strlwr(purchase_item.product);
			
			printf("Enter Quantity: ");
			scanf("%u",&purchase_item.quantity);
			
			fseek(inventory_file,0,SEEK_SET);
			
			while(fread(&read_item,sizeof(read_item),1,inventory_file)!=0)
			{
				if(strcmp(read_item.product,purchase_item.product)==0)
				{
					printf("%d\n",read_item.quantity);
					break;
				}
			}
			
			if(feof(inventory_file))
			{
				read_item.quantity = purchase_item.quantity;
				fseek(inventory_file,0,SEEK_END);
			}
			else
			{
				read_item.quantity += purchase_item.quantity;
				fseek(inventory_file,-sizeof(read_item),SEEK_CUR);
			}
			
			strcpy(read_item.product,purchase_item.product);
			
			fwrite(&read_item,sizeof(read_item),1,inventory_file);
			
			printf("Enter Price: ");
			scanf("%lf",&purchase_item.price);
			
			purchase_transaction_file=fopen("Purchases transaction.txt","ab+");
			
			fwrite(&purchase_item,sizeof(purchase_item),1,purchase_transaction_file);
			
						
			system("cls");
			
			printf("Product        :    %s\n",purchase_item.product);
			printf("Quantity       :    %u\n",purchase_item.quantity);
			printf("Price          :    %.2lf\n",purchase_item.price);
			
			printf("Product Total  :    %.2lf\n",purchase_item.quantity*purchase_item.price);
			
			invoice_total+=(purchase_item.quantity*purchase_item.price);
			printf("\nInvoice Total  :    %.2lf",invoice_total);
			
			printf("\n\n\nAdd more Items(y/n): ");
			do
			{
				fflush(stdin);
				ch=getch();
				
				if(ch=='y'||ch=='Y')
				{
					purchase_info.items++;
					break;
				}
				else if(ch=='N'||ch=='n')
				{
					system("cls");
					
					printf("Invoice Saved Successfully\n\n");
					
					printf("Invoice No.          :%u\n",purchase_info.invoice);
					printf("Date                 :%hu/%hu/%hu\n",purchase_info.date.day,purchase_info.date.month,purchase_info.date.year);
					printf("Time                 :%hu/%hu %s\n",purchase_info.time.hour,purchase_info.time.minute,purchase_info.time.med);
					printf("Supplier ID          :%s\n",purchase_info.id);
					printf("Supplier Name        :%s\n",view_supplier.name);
					printf("Mode                 :%s\n",purchase_info.mode);
					printf("Purchase Items       :%u\n",purchase_info.items);
					printf("Invoice Total        :%.2lf\n",invoice_total);
					
					end='y';
					break;
				}
			}while(1);
	
			
		}while(end!='y');
		
		if(strcmp(purchase_info.mode,"Credit")==0)
		{
			view_supplier.balance+=invoice_total;
			
			fseek(view_supplier_file,-sizeof(view_supplier),SEEK_CUR);
			
			fwrite(&view_supplier,sizeof(view_supplier),1,view_supplier_file);
		}
		
		fseek(purchase_info_file,0,SEEK_END);
		
		fwrite(&purchase_info,sizeof(purchase_info),1,purchase_info_file);
		
		
		printf("\n\n\n\t\t\t\tAdd another Purchase Invoice(y/n):");
		
		do
		{
			fflush(stdin);
			ch=getch();
			
			if(ch=='y'||ch=='Y')
			{
				purchase_info.invoice++;
				break;
			}
			else if(ch=='N'||ch=='n')
			{
				
				system("cls");
				out='y';
				break;
			}
		}while(1);
	
	}while(out!='y');
	
	fclose(purchase_info_file);
	fclose(view_supplier_file);
	fclose(inventory_file);
	
	getch();
	return 0;
}
