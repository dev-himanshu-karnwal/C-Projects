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
	
	
	FILE *sale_info_file=fopen("Sale Information.txt","rb");
	FILE *view_customer_file=fopen("Customers record.txt","rb+");
	FILE *sale_transaction_file;
	FILE *inventory_file=fopen("Inventory record.txt","rb+");
	struct transaction_info sale_info;
	struct transaction_item sale_item;
	struct inventory_stock read_item;
	struct customer view_customer;
	char ch,end,out;
	unsigned short len;
	register int i;
	double invoice_total;
	
	
	if(sale_info_file==NULL)
	{
		fclose(sale_info_file);
		sale_info_file=fopen("Sales Information.txt","ab");
					getch();
		sale_info.invoice=1;
	}
	else
	{
		fclose(sale_info_file);
		sale_info_file=fopen("Sales Information.txt","ab+");
		
		fseek(sale_info_file,-sizeof(sale_info),SEEK_END);
		
		fread(&sale_info,sizeof(sale_info),1,sale_info_file);
		
		sale_info.invoice++;
	}
	
	if(inventory_file==NULL)
	{
		fclose(inventory_file);
		inventory_file=fopen("Inventory record.txt","wb+");
	}
	
	if(view_customer_file==NULL)
	{
		system("cls");
			
		printf("No Previous Customers data exists\n");
		printf("Press 1-> Want to add customers\n");
		printf("Press any other key -> Go to back screen\n");
		
		fflush(stdin);
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
//				new_customer();
				break;
				
			default:
				
				fclose(view_customer_file);
				return;
				
		}
		
	}
	
	do
	{
		
		do
		{
			system("cls");
			
			invoice_total=0;
			sale_info.items=1;
			
			printf("Enter Customer ID: ");
			
			fflush(stdin);
			scanf("%s",sale_info.id);
				
			fseek(view_customer_file,0,SEEK_SET);
			
			while(fread(&view_customer,sizeof(view_customer),1,view_customer_file)!=0)
			{
				if(strcmp(view_customer.id,sale_info.id)==0)
				{
					i=0;		
					break;
				}
			}
			if(feof(view_customer_file))
			{
				printf("  INVALID ID ENTERED!  No such ID exists, Try again...");
				sleep(2);
						
			}
		}while(i!=0);
		
		printf("Enter the Time (in hh:mm format): ");
		scanf("%hu/%hu",&sale_info.time.hour,&sale_info.time.minute);
		
		printf("In AM or PM(a/p): ");
		
		do
		{
			ch=getch();
			
			switch(ch)
			{
				case 'a':
				case 'A':
					
					puts("A.M.");
					strcpy(sale_info.time.med,"A.M.");
					i=0;
					
					break;
					
				case 'p':
				case 'P':
					
					puts("P.M.");
					strcpy(sale_info.time.med,"P.M.");
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
		scanf("%hu/%hu/%hu",&sale_info.date.day,&sale_info.date.month,&sale_info.date.year);
		
		printf("Enter Mode of Sale: ");
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
					strcpy(sale_info.mode,"Cash");
					puts("Cash");
				}
				else
				{
					strcpy(sale_info.mode,"Credit");
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
			gets(sale_item.product);
			strlwr(sale_item.product);
			
			fseek(inventory_file,0,SEEK_SET);
			
			while(fread(&read_item,sizeof(read_item),1,inventory_file)!=0)
			{
				if(strcmp(read_item.product,sale_item.product)==0)
				{
					break;
				}
			}
			
			printf("Enter Quantity: ");
			do
			{
				scanf("%u",&sale_item.quantity);
				
				if(feof(inventory_file))
				{
					read_item.quantity = sale_item.quantity;
					fseek(inventory_file,0,SEEK_END);
				}
				else
				{
					if(read_item.quantity - sale_item.quantity <0)
					{
						len = printf(" Not enough stock");
						
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
					else
					{
						read_item.quantity -= sale_item.quantity;
						
					}
					fseek(inventory_file,-sizeof(read_item),SEEK_CUR);
				}
			
			}while(read_item.quantity - sale_item.quantity <0);
			
			strcpy(read_item.product,sale_item.product);
			
			fwrite(&read_item,sizeof(read_item),1,inventory_file);
			
			printf("Enter Price: ");
			scanf("%lf",&sale_item.price);
			
			sale_transaction_file=fopen("Sales transaction.txt","ab+");
			
			fwrite(&sale_item,sizeof(sale_item),1,sale_transaction_file);
			
						
			system("cls");
			
			printf("Product        :    %s\n",sale_item.product);
			printf("Quantity       :    %u\n",sale_item.quantity);
			printf("Price          :    %.2lf\n",sale_item.price);
			
			printf("Product Total  :    %.2lf\n",sale_item.quantity*sale_item.price);
			
			invoice_total+=(sale_item.quantity*sale_item.price);
			printf("\nInvoice Total  :    %.2lf",invoice_total);
			
			printf("\n\n\nAdd more Items(y/n): ");
			do
			{
				fflush(stdin);
				ch=getch();
				
				if(ch=='y'||ch=='Y')
				{
					sale_info.items++;
					break;
				}
				else if(ch=='N'||ch=='n')
				{
					system("cls");
					
					printf("Invoice Saved Successfully\n\n");
					
					printf("Invoice No.          :%u\n",sale_info.invoice);
					printf("Date                 :%hu/%hu/%hu\n",sale_info.date.day,sale_info.date.month,sale_info.date.year);
					printf("Time                 :%hu/%hu %s\n",sale_info.time.hour,sale_info.time.minute,sale_info.time.med);
					printf("Customer ID          :%s\n",sale_info.id);
					printf("Customer Name        :%s\n",view_customer.name);
					printf("Mode                 :%s\n",sale_info.mode);
					printf("Sale Items    		 :%u\n",sale_info.items);
					printf("Invoice Total        :%.2lf\n",invoice_total);
					
					end='y';
					break;
				}
			}while(1);
	
			
		}while(end!='y');
		
		if(strcmp(sale_info.mode,"Credit")==0)
		{
			view_customer.balance+=invoice_total;
			
			fseek(view_customer_file,-sizeof(view_customer),SEEK_CUR);
			
			fwrite(&view_customer,sizeof(view_customer),1,view_customer_file);
		}
		
		fseek(sale_info_file,0,SEEK_END);
		
		fwrite(&sale_info,sizeof(sale_info),1,sale_info_file);
		
		
		printf("\n\n\n\t\t\t\tAdd another Sale Invoice(y/n):");
		
		do
		{
			fflush(stdin);
			ch=getch();
			
			if(ch=='y'||ch=='Y')
			{
				sale_info.invoice++;
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
	
	fclose(sale_info_file);
	fclose(view_customer_file);
	fclose(inventory_file);
	
	getch();
	return 0;
}
