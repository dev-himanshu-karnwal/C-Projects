/*			COMPLETE STORE MANAGEMENT PROJECT 	

							-By Himanshu
							2021BCA076 
							BCA 2nd sem
							TIMT, YNR

FILES used:				Customers record.txt	
						Suppliers record.txt	
						Shopkeeper record.txt	
						Purchases Information.txt	
						Purchases transaction.txt	
						Sales Information.txt	
						Sales transaction.txt	
						Inventory record.txt
*/
						
						
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void homepage(void);
void password_input(char *);
void new_customer(void);
void new_supplier(void);
void enter_update_personal(void);
void view_supplier(void);
void view_customer(void);
void new_purchase(void);
void new_sale(void);
void pay_supplier(void);
void receive_customer_payment(void);
void check_inventory(void);
void view_purchase(void);
void view_sale(void);

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
	short day;
	short month;
	short year;
};

struct TIME
{
	short hour;
	short minute;
	char med[5];
};

struct transaction_info
{
	char id[9];
	unsigned int invoice;
	unsigned int items;
	struct DATE date;
	struct TIME time;
	char mode[6];
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

struct shopkeeper new_shopkeeper;

/********************************************************************************************************************************************************************************/

int main()
{
	
	char confirm_exit;
	char function_to_do,function_to_do_detail;
	char password_entered[9];
	homepage();
	enter_update_personal();		//to first time initialise the shopkeeper info,id & password
	
	do
	{
		system("cls");
		
		printf("Enter your Password: ");
		password_input(password_entered);
		if(strcmp(password_entered,new_shopkeeper.password)==0)
		{
			do
			{
				system("cls");
		
				printf("What to do?\t(Press corresponding Number key)\n");
				printf("1. New Purchase/Sale\n");
				printf("2. View old Transaction\n");
				printf("3. Add new Customer/Supplier\n");
				printf("4. View Supplier/Customer Record\n");
				printf("5. Make Payment to Supplier/Customer\n");
				printf("6. Check Inventory\n");
				printf("7. Update Personal Records\n");
				printf("\"Esc\" To EXIT\n\n");
						
				fflush(stdin);
				function_to_do=getch();
				
				system("cls");
						
				switch(function_to_do)
				{
					case '1':							//New Purchase/Sale
					
						do
						{
							system("cls");
							
							printf("1. Enter new Purchase \n");
							printf("2. Enter new Sale \n");
							printf("\"Esc\" To go Back\n\n");
							
							fflush(stdin);
							function_to_do_detail=getch();
							
							system("cls");
							
							switch(function_to_do_detail)
							{
								case '1':									//Enter new Purchase
									
									new_purchase();
									
									break;
										
								case '2':									//Enter new Sale 
									
									new_sale();
										
									break;
									
								case 27:
									
									break;
											
								default:
											
									printf("\nINVALID KEY PRESSED! Press a Valid key");
									printf("\a");
									sleep(2);
											 
							}
									
									
						}while(function_to_do_detail!=27);
								
						break;
									
					case '2':							//View old Transaction
									
						do
						{
							system("cls");
							
							printf("1. View Purchase \n");
							printf("2. View new Sale \n");
							printf("\"Esc\" To go Back\n\n");
									
							fflush(stdin);
							function_to_do_detail=getch();
								
							system("cls");
										
							switch(function_to_do_detail)
							{
								case '1':									//View Old Purchase
									
									view_purchase();
									
									break;
										
								case '2':									//View Old Sale 
									
									view_sale();
								
									break;
									
								case 27:
									
									break;
									
								default:
									
									printf("\nINVALID KEY PRESSED! Press a Valid key");
									printf("\a");
									sleep(2);
										
							}
							
						
						}while(function_to_do_detail!=27);
						
						break;
						
					case '3':										//New customer/supplier			
						
						do
						{
							system("cls");
					
							printf("1. Enter new Customer \n");
							printf("2. Enter new Supplier \n");
							printf("\"Esc\" To go Back\n\n");
							
							fflush(stdin);
							function_to_do_detail=getch();
							
							system("cls");
									
							switch(function_to_do_detail)
							{
								case '1':									//Enter new customer
									
									new_customer();
											
									break;
											
								case '2':									//Enter new supplier
											
									new_supplier();
											
									break;
									
								case 27:
									
									break;
											
								default:
											
									printf("\nINVALID KEY PRESSED! Press a Valid key");
									printf("\a");
									sleep(2);
										
							}
									
									
						}while(function_to_do_detail!=27);
						
						break;
							
					case '4':							//View Supplier/Customer Record
								
						do
						{
							system("cls");
									
							printf("1. View Supplier Record\n");
							printf("2. View Customer Record\n");
							printf("\"Esc\" To go Back\n\n");
									
							fflush(stdin);
							function_to_do_detail=getch();
									
							system("cls");
									
							switch(function_to_do_detail)
							{
								case '1':									//View supplier Record
										
									view_supplier();
										
									break;
											
								case '2':									//View Customer Record
												
									view_customer();
											
									break;
									
								case 27:
									
									break;
											
								default:
												
									printf("\nINVALID KEY PRESSED! Press a Valid key");
									printf("\a");
									sleep(2);
											
							}
																			
						}while(function_to_do_detail!=27);
									
						break;
								
					case '5':							//Make Payment to Supplier/Customer
								
						do
						{
							system("cls");
								
							printf("1. Payment to Supplier\n");
							printf("2. Payment to Customer\n");
							printf("\"Esc\" To go Back\n\n");
									
							fflush(stdin);
							function_to_do_detail=getch();
									
							system("cls");
									
							switch(function_to_do_detail)
							{
								case '1':									//Change Supplier Record
											
									pay_supplier();
										
									break;
											
								case '2':									//Change Customer Record
											
									receive_customer_payment();
											
									break;
									
								case 27:
									
									break;
											
								default:
											
									printf("\nINVALID KEY PRESSED! Press a Valid key");
									printf("\a");
									sleep(2);
											
							}
									
									
						}while(function_to_do_detail!=27);
							
						break;
								
					case '6':							//Check Current Stock/Inventory
								
						system("cls");
								
						check_inventory();
								
						break;
									
					case '7':							//Update Personal Records
						
						system("cls");
								
						enter_update_personal();
									
						break;
									
					case 27:			//Esc key			
			
						do
						{
							system("cls");
							printf("Confirm EXIT (Y/N) : ");
							confirm_exit=getch();
					
							switch(confirm_exit)
							{
								case 'y':
								case 'Y':
									printf("\n\n\n................................................Program Exitted................................................");
									exit(0);
						
								case 'n':
								case 'N':
									break;
							
								default:
									printf("\nINVALID KEY PRESSED! Press a Valid key");
									printf("\a");
									sleep(2);
							
							}
						
						}while(confirm_exit!='n' && confirm_exit!='N');
					
						break;
		
					default:

											
						printf("\nINVALID KEY PRESSED! Press a Valid key");
						printf("\a");
						sleep(2);
					
				}
								
			}while(1);		//Shopkeeper Home screen i.e. Menu screen 
						
			break;				//To Exit Password enter loop
		}
		else			//If wrong password entered
		{
			printf("\nINCORRECT PASSWORD! Input again\n\a");
			sleep(2);
		}
			
	}while(1);
	
	
	getch();
	return 0;
}

/********************************************************************************************************************************************************************************/

void homepage(void)
{
	int i,j,len;
	
	for(i=1;i<=52;i++)
	{
		for(j=1;j<=197;j++)
		{
			if(i==25 && j==70)					//Prints Home Page Information
			{
				len = printf("WELCOME  TO  THE  STORE  MANAGEMENT  SYSTEM  PROJECT");
				j += len;							//j =  initial position + length of string printed = New starting position of j 
			}
			else if(i==30 && j==110)
			{
				len = printf("-By Himanshu");
				j += len;							//j =  initial position + length of string printed = New starting position of j 
			}
			else if(i==47 && j==67)
			{
				len = printf("<-----------------(Press any key to START)----------------->");
				j += len;
			}
			
			if(i==1||j==197||j==1||i==52)		//Prints boundry around console of default size
				putchar('*');
			else
				putchar(' ');
				
		}
	}
	
	getch();
	
}

/********************************************************************************************************************************************************************************/

void password_input(char *password_entered)
{
	
	scanf("%8s",password_entered);
	
}

/********************************************************************************************************************************************************************************/

void new_customer()
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
			
				printf("Enter the unique User ID of new Customer(<=8 characters): ");
				fflush(stdin);
				scanf("%8s",new_customer.id);
				
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
	
}

/********************************************************************************************************************************************************************************/

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
				
				printf("Enter the unique User ID of new Supplier(<=8 characters): ");
				fflush(stdin);
				scanf("%8s",new_supplier.id);
				
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
	
}

/********************************************************************************************************************************************************************************/

void enter_update_personal(void)
{
	
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
		
		printf("\n\nSHOPKEEPER INFORMATION UPDATED SUCCESSFULLY\n");
		
		sleep(2);
		
		fclose(enter_shopkeeper_file);
	
	}
	else
	{
		do
		{
			
			enter_shopkeeper_file=fopen("Shopkeeper record.txt","rb+");
			
			system("cls");
			
			fread(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);		//Read the New shopkeeper record from file
			
			printf("Current Information of Shopkeeper..\n\n");
			printf("Password    : %s\n",new_shopkeeper.password);
			printf("Name        : %s\n",new_shopkeeper.name);
			printf("Address     : %s\n\n",new_shopkeeper.address);
			
			printf("What do you want to update(Click corresponding Number Key):\n");
			printf("1. Password\n");
			printf("2. Name\n");
			printf("3. Address\n");
			printf("If You do not want to update anything then, Press \"Esc\" to go to Menu page): ");
			
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
					sleep(2);
					
					break;
				
				case '2':
					
					
					printf("Enter new Name: ");
					
					fflush(stdin);
					gets(new_shopkeeper.name);
					
					fseek(enter_shopkeeper_file,0,SEEK_SET);
					fwrite(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);
					printf("User Name updated\n");
					sleep(2);
					
					break;
				
				case '3':
					
					printf("Enter new Address: ");
					
					fflush(stdin);
					gets(new_shopkeeper.address);
					
					fseek(enter_shopkeeper_file,0,SEEK_SET);
					fwrite(&new_shopkeeper,sizeof(new_shopkeeper),1,enter_shopkeeper_file);
					printf("User Address updated\n");
					sleep(2);
					
					break;
				
				case 27:
					
					break;
					
					
				default:
					
					printf("\nINVALID KEY PRESSED! Press a Valid key");
					printf("\a");
					sleep(2);
					
			}
			
			
			fclose(enter_shopkeeper_file);
		
		}while(what_to_change!=27);
		
	}
	
}

/********************************************************************************************************************************************************************************/

void view_supplier(void)
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
				
				fclose(view_supplier_file);
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
					scanf("%8s",search_id);
			
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
						sleep(2);
					}
					else
					{
						printf("\nPress Esc key to go back else press any other key to search for another supplier");
						
						fflush(stdin);
						ch=getch();
					}
			
				}while(ch!=27);		//Loop continue till Esc key pressed
				
				break;
			
			default:
			
				fseek(view_supplier_file,0,SEEK_SET);
			   
				printf("\n\n   ID     NAME                           ADDRESS                              BALANCE\n\n");
				while(fread(&view_supplier,sizeof(view_supplier),1,view_supplier_file)!=0)
				{
					printf("%-9s %-30s %-48s %ld\n",view_supplier.id,view_supplier.name,view_supplier.address,view_supplier.balance);
					i++;
					
					if(i==20)
					{
						printf("\n\n\n\t\t\t\t\tPress any key to continue watching next record....");
						getch();
						i=0;
					}
				}
				
				printf("\n\n\n\t\t\t\t\tPress any key to Go back....");
				getch();
				
		}
		
		fclose(view_supplier_file);
	}
	
}

/********************************************************************************************************************************************************************************/

void view_customer(void)
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
		
		fflush(stdin);
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
				new_customer();
				break;

			default:
				
				fclose(view_customer_file);
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
					system("cls");
					
					fseek(view_customer_file,0,SEEK_SET);
					
					printf("Enter ID of Customer whose data is to be viewed: ");
					
					fflush(stdin);
					scanf("%8s",search_id);
			
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
			
				printf("\n\n   ID       NAME                        ADDRESS                                        BALANCE\n\n");
				while(fread(&view_customer,sizeof(view_customer),1,view_customer_file)!=0)
				{
					printf("%-9s %-30s %-48s %ld\n",view_customer.id,view_customer.name,view_customer.address,view_customer.balance);
					
					i++;
					
					if(i==20)
					{
						printf("\n\n\n\n\n\n\t\t\t\t\tPress any key to continue watching next record....");
						fflush(stdin);
						getch();
						
						i=0;
						
					}
				}
				
				printf("\n\n\n\t\t\t\t\tPress any key to Go back....");
				getch();
		}
		
	}
	
}

/********************************************************************************************************************************************************************************/

void new_purchase(void)
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
		purchase_info.invoice=1;
	}
	else
	{
		fclose(purchase_info_file);
		purchase_info_file=fopen("Purchases Information.txt","ab+");
		
		fseek(purchase_info_file,(-sizeof(purchase_info)),SEEK_END);
		
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
		
		fflush(stdin);
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
				new_supplier();
				break;
				
			default:
				
				fclose(view_supplier_file);
				fclose(purchase_info_file);
				fclose(inventory_file);
				
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
			scanf("%8s",purchase_info.id);
				
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
		scanf("%hd:%hd",&purchase_info.time.hour,&purchase_info.time.minute);
		
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
		scanf("%hd/%hd/%hd",&purchase_info.date.day,&purchase_info.date.month,&purchase_info.date.year);
		
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
					fseek(inventory_file,-(sizeof(read_item)),SEEK_CUR);
				}
			
				strcpy(read_item.product,purchase_item.product);
				
				fwrite(&read_item,sizeof(read_item),1,inventory_file);
			
				printf("Enter Price: ");
				scanf("%lf",&purchase_item.price);
				
				printf("\n\nConfirm Item\n");
				printf("Press 'Y' -> Yes\n");
				printf("Press 'N' -> Make Changes  ");
				do
				{
					
					end=getch();
					switch(end)
					{
						case 'y':
						case 'Y':
								
							end='y';
							break;
						
						case 'n':
						case 'N':
						
							end='n';					
							break;
					}
				}while( end!='y' && end!='n');
			
			}while( end!='y');
			
			purchase_transaction_file=fopen("Purchases transaction.txt","ab+");
			
			fseek(purchase_transaction_file,0,SEEK_END);
			
			fwrite(&purchase_item,sizeof(purchase_item),1,purchase_transaction_file);
			
						
			system("cls");
			
			printf("Product        :    %s\n",purchase_item.product);
			printf("Quantity       :    %u\n",purchase_item.quantity);
			printf("Price          :    %.2lf\n",purchase_item.price);
			
			printf("Product Total  :    %.2lf\n",purchase_item.quantity*purchase_item.price);
			
			invoice_total+=(purchase_item.quantity*purchase_item.price);
			printf("\nInvoice Total  :    %.2lf",invoice_total);
			
			end='\0';
			
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
					printf("Date                 :%hd/%hd/%hd\n",purchase_info.date.day,purchase_info.date.month,purchase_info.date.year);
					printf("Time                 :%hd/%hd %s\n",purchase_info.time.hour,purchase_info.time.minute,purchase_info.time.med);
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
		
		out='\0';
		
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
	
}

/********************************************************************************************************************************************************************************/

void new_sale(void)
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
				
				new_customer();
				break;
				
			default:
				
				fclose(view_customer_file);
				fclose(sale_info_file);
				fclose(inventory_file);
				
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
			scanf("%8s",sale_info.id);
				
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
		scanf("%hd/%hd",&sale_info.time.hour,&sale_info.time.minute);
		
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
		scanf("%hd/%hd/%hd",&sale_info.date.day,&sale_info.date.month,&sale_info.date.year);
		
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
			do
			{
			
				do
				{	
					
					system("cls");
					
					printf("Enter Item Name: ");
					fflush(stdin);
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
					if(feof(inventory_file))
					{
						printf("No Such Product Exists");
						sleep(2);
					}
					
				}while(feof(inventory_file));
			
				printf("Enter Quantity: ");
				do
				{
					fflush(stdin);
					
					scanf("%u",&sale_item.quantity);
					
					if(feof(inventory_file))
					{
						read_item.quantity = sale_item.quantity;
						
						fseek(inventory_file,0,SEEK_END);
							
					break;
					}
					else
					{
						if(((int)read_item.quantity-(int)sale_item.quantity)<0)
						{
							len = printf(" Not enough stock");
							
							sleep(1);
					
							system("cls");
							
							printf("Enter Item Name: %s\n",sale_item.product);
							printf("Enter Quantity: ");
								
						}
						else
						{
							read_item.quantity -= sale_item.quantity;
							
							break;
						}
						fseek(inventory_file,-sizeof(read_item),SEEK_CUR);
					}	
			
				}while(1);
				
				strcpy(read_item.product,sale_item.product);
				
				fwrite(&read_item,sizeof(read_item),1,inventory_file);
				
				printf("Enter Price: ");
				scanf("%lf",&sale_item.price);
			
			
				printf("\n\nConfirm Item\n");
				printf("Press 'Y' -> Yes\n");
				printf("Press 'N' -> Make Changes  ");
				do
				{
					
					end=getch();
					switch(end)
					{
						case 'y':
						case 'Y':
								
							end='y';
							break;
						
						case 'n':
						case 'N':
						
							end='n';					
							break;
					}
				}while( end!='y' && end!='n');
			
			}while( end!='y');
			
			sale_transaction_file=fopen("Sales transaction.txt","ab+");
			
			fseek(sale_transaction_file,0,SEEK_END);
			
			fwrite(&sale_item,sizeof(sale_item),1,sale_transaction_file);
			
			
			system("cls");
			
			printf("Product        :    %s\n",sale_item.product);
			printf("Quantity       :    %u\n",sale_item.quantity);
			printf("Price          :    %.2lf\n",sale_item.price);
			
			printf("Product Total  :    %.2lf\n",sale_item.quantity*sale_item.price);
			
			invoice_total+=(sale_item.quantity*sale_item.price);
			printf("\nInvoice Total  :    %.2lf",invoice_total);
			
			end='\0';
			
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
					printf("Date                 :%hd/%hd/%hd\n",sale_info.date.day,sale_info.date.month,sale_info.date.year);
					printf("Time                 :%hd/%hd %s\n",sale_info.time.hour,sale_info.time.minute,sale_info.time.med);
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
		
		out='\0';
		
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
	
}

/********************************************************************************************************************************************************************************/

void pay_supplier(void)
{
	
	FILE *view_supplier_file=fopen("Suppliers record.txt","rb");
	struct supplier view_supplier;
	char search_id[9];
	char ch;
	long unsigned payment;
	int confirm_payment;
	
	
	if(view_supplier_file==NULL)
	{
		system("cls");
		
		fclose(view_supplier_file);
			
		printf("No Previous suppliers data exists\n");
		printf("Press 1-> Want to add suppliers\n");
		printf("Press any other key -> Go to back screen\n");
		
		fflush(stdin);
		ch=getch();
			
		switch(ch)
		{
			case '1':
				
				new_supplier();
				break;
				
			default:
				
				fclose(view_supplier_file);
				return;
				
		}
		
	}
	else
	{
		do
		{
			fseek(view_supplier_file,0,SEEK_SET);
			
			system("cls");
		
			printf("Enter ID of Supplier whose payment is to made: ");
			fflush(stdin);
			scanf("%8s",search_id);
		
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
					
					
					printf("\n\nPress any key to continue making Payment...");
					getch();
					break;
				}
			}
			if(feof(view_supplier_file))
			{
				printf("\nINVALID ID ENTERED!  No such ID exists, Try again...");
				sleep(2);
			}
			else
				break;
			
		}while(ch!=27);		//Loop continue till Esc key pressed
		
		do
		{
			
			system("cls");
				
				
			printf("How much Payment you want to make:  ");
			scanf("%lu",&payment);
		
			printf("\nPrevious Balance  : %ld\n",view_supplier.balance);
			printf("Payment made      : %ld\n\n",payment);
			getch();
			
			if(view_supplier.balance<payment)
			{
				printf("\nIt is less than Supplier's Balance\n");
				printf("Press 1             -> Change Amount\n");
				printf("Press any other key -> Continue with paying entered amount i.e. %lu and keep it as advance:",payment);
				
				fflush(stdin);
				ch=getche();
				
				switch(ch)
				{
					case '1':
						
						confirm_payment=0;
						break;
					
					default:
						
						confirm_payment=1;					
				}
			}
			else
			{
				confirm_payment=1;
			}
			if(confirm_payment==1)
			{
				view_supplier.balance -= payment;
				
				fseek(view_supplier_file,-sizeof(view_supplier),SEEK_CUR);
				fwrite(&view_supplier,sizeof(view_supplier),1,view_supplier_file);
				printf("\n\nUpdated Balance : %ld\n",view_supplier.balance);
				getch();
//				fseek(view_supplier_file,-sizeof(view_supplier),SEEK_CUR);
				fread(&view_supplier,sizeof(view_supplier),1,view_supplier_file);
				printf("\n\nUpdated Balance : %ld\n",view_supplier.balance);
				getch();
				
				
			}
		
		}while(confirm_payment!=1);
		
	}
	
	fclose(view_supplier_file);
}

/********************************************************************************************************************************************************************************/

void receive_customer_payment(void)
{
	
	FILE *view_customer_file=fopen("Customers record.txt","rb");
	struct customer view_customer;
	char search_id[9];
	char ch;
	long unsigned payment;
	int confirm_payment;
	
	
	if(view_customer_file==NULL)
	{
		system("cls");
		
		fclose(view_customer_file);
			
		printf("No Previous customers data exists\n");
		printf("Press 1-> Want to add customers\n");
		printf("Press any other key -> Go to back screen\n");
		
		fflush(stdin);
		ch=getch();
			
		switch(ch)
		{
			case '1':
				
				new_customer();
				break;
				
			default:
				
				fclose(view_customer_file);
				return;
				
		}
		
	}
	else
	{
		do
		{
			fseek(view_customer_file,0,SEEK_SET);
			
			system("cls");
		
			printf("Enter ID of Customer whose payment is to received: ");
			fflush(stdin);
			scanf("%8s",search_id);
		
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
					
					printf("\n\nPress any key to continue making Payment...");
					getch();
					break;
				}
			}
			if(feof(view_customer_file))
			{
				printf("\nINVALID ID ENTERED!  No such ID exists, Try again...");
				sleep(2);
			}
			
		}while(ch!=27);		//Loop continue till Esc key pressed
		
		do
		{
			
			system("cls");
				
			printf("How much Receipt you want to enter:  ");
			scanf("%lu",&payment);
		
			printf("\nPrevious Balance  : %ld\n",view_customer.balance);
			printf("Payment made      : %ld\n\n",payment);
		
			if(view_customer.balance<payment)
			{
				printf("\nIt is less than Customer's Balance\n");
				printf("Press 1				-> Change Amount\n");
				printf("Press any other key -> Continue with paying entered amount i.e. %lu and keep it as advance:",payment);
				
				fflush(stdin);
				ch=getche();
				
				switch(ch)
				{
					case '1':		
						
						confirm_payment=0;
						break;
					
					default:
						
						confirm_payment=1;								
				}
			}
			else
			{
				confirm_payment=1;
			}
			if(confirm_payment=1)
			{
				view_customer.balance-=payment;
				printf("\n\nUpdated Balance : %ld\n",view_customer.balance);
			}
		
		}while(confirm_payment!=1);
		
	}
	
}


/********************************************************************************************************************************************************************************/

void check_inventory(void)
{
	
	FILE *inventory_file=fopen("Inventory record.txt","rb+");
	struct inventory_stock item;
	int i=0;
	char ch;
	
	system("cls");
	
	if(inventory_file==NULL)
	{
		fclose(inventory_file);
		
		system("cls");
		
		printf("No Previous Inventories data exists\n");
		printf("Press 1-> Want to add Purchase to add Inventory\n");
		printf("Press any other key -> Go to back screen\n");
		
		fflush(stdin);
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
				new_purchase();
				break;

			default:
				
				printf("\a");
				fclose(inventory_file);
				return;
		}
		
	}
	
	printf("\t\t\t\tInventory Stock is as follows\n\n");
	
	fseek(inventory_file,0,SEEK_SET);
	
	
	while(fread(&item,sizeof(item),1,inventory_file)!=0)
	{
		if(i%10==0)
		{
			if(i!=0)
			{
				printf("\n\n\n\t\t\t\tPress any key to watch next record.....");
				getch();
			}
			system("cls");
			printf("\t\t\tPRODUCT NAME\t\t\t\tQUANTITY PRESENT\n\n");
		}
		
		printf("\t%30s\t\t\t\t\t%u\n",item.product,item.quantity);
		
	
		i++;
	}
	
	printf("Press any key to go back......");
	getch();
	
	
}

/********************************************************************************************************************************************************************************/

void view_purchase(void)
{
	
	FILE *purchase_info_file=fopen("Purchases Information.txt","rb");
	FILE *purchase_transaction_file=fopen("Purchases transaction.txt","rb");
	FILE *view_supplier_file=fopen("Suppliers record.txt","rb+");
	struct transaction_info purchase_info;
	struct supplier view_supplier;
	struct transaction_item purchase_item;
	unsigned int invoice; 
	unsigned int i;
	double invoice_total;
	unsigned transactions=0;
	char ch;
	
	if(purchase_info_file==NULL)
	{
		system("cls");
		
		printf("No Previous Purchase data exists\n");
		printf("Press 1-> Want to add Purchase\n");
		printf("Press any other key -> Go to back screen\n");
		
		fflush(stdin);
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
				new_purchase();
				break;

			default:
				
				fclose(purchase_info_file);
				return;
		}
		
	}
	
	
			do
			{
				system("cls");
				
				transactions=0;
				
				fseek(purchase_info_file,0,SEEK_SET);
				
				printf("Enter Invoice Number which is to be viewed: ");
				
				fflush(stdin);
				scanf("%u",&invoice);
			
				while(fread(&purchase_info,sizeof(purchase_info),1,purchase_info_file)!=0)
				{
					
					if(invoice==purchase_info.invoice)
					{
						fseek(view_supplier_file,0,SEEK_SET);
						
						while(fread(&view_supplier,sizeof(view_supplier),1,view_supplier_file)!=0)
						{
							if(strcmp(view_supplier.id,purchase_info.id)==0)
							{
								break;
							}
						}
									
						system("cls");
						
						printf("Invoice Details of entered Invoice Number..\n\n");
						printf("Supplier ID          : %s\n",purchase_info.id);
						printf("Supplier Name        : %s\n",view_supplier.name);
						printf("Address              : %s\n",view_supplier.address);
						printf("Invoice No.          : %u\n",purchase_info.invoice);
						printf("Total Items          : %u\n",purchase_info.items);
						printf("Date                 : %hd/%hd/%hd\n",purchase_info.date.day,purchase_info.date.month,purchase_info.date.year);
						printf("Time                 : %hd/%hd %s\n",purchase_info.time.hour,purchase_info.time.minute,purchase_info.time.med);
						printf("Mode                 : %s\n",purchase_info.mode);

						printf("\n\n\n\n\n\n\n\t\t\t\t\tPress any key to Watch The items");
						getch();
						
						transactions=sizeof(purchase_item)*transactions;
						
						fseek(purchase_transaction_file,transactions,SEEK_SET);						
						
						for(i=0;i<purchase_info.items;i++)
						{
							
							fread(&purchase_item,sizeof(purchase_item),1,purchase_transaction_file);
							
							if(i%11==0)
							{
								if(i!=0)
								{
									printf("\n\n\n\t\t\t\t\tPress any key to watch next Records.....");
									getch();
								}
								
								system("cls");
								
								printf("Item No.\tProduct Name\t\t\t\t\tQuantity\t\tPrice\t\t\tProduct Total\n\n");
							}
							
							printf("%d\t\t%s\t\t\t\t\t\t%u\t\t\t%.2lf\t\t\t%.2lf\n",i+1,purchase_item.product,purchase_item.quantity,purchase_item.price,purchase_item.quantity*purchase_item.price);
							
							invoice_total+=(purchase_item.quantity*purchase_item.price);
						}
						
						printf("\n\nInvoice Total: %.2lf\n\n",invoice_total);
						
						break;
					
					}
					transactions +=  purchase_info.items;
					
				}
				if(feof(purchase_info_file))
				{
					printf("\nINVALID Invoice Number ENTERED! Try again...");
					sleep(2);
				}
				else
				{
					printf("\nPress Esc key to go back else press any other key to search for another Invoice");
					fflush(stdin);
					ch=getch();
				}
		
			}while(ch!=27);		//Loop continue till Esc key pressed
		
	
}

/********************************************************************************************************************************************************************************/

void view_sale(void)
{
	
	FILE *sale_info_file=fopen("Sales Information.txt","rb");
	FILE *sale_transaction_file=fopen("Sales transaction.txt","rb");
	FILE *view_customer_file=fopen("Customers record.txt","rb+");
	struct transaction_info sale_info;
	struct customer view_customer;
	struct transaction_item sale_item;
	unsigned int invoice;
	unsigned int i;
	double invoice_total;
	unsigned transactions=0;
	char ch;
	
	if(sale_info_file==NULL)
	{
		system("cls");
		
		printf("No Previous Sale data exists\n");
		printf("Press 1-> Want to add Purchase\n");
		printf("Press any other key -> Go to back screen\n");
		
		fflush(stdin);
		ch=getche();
			
		switch(ch)
		{
			case '1':
				
				new_sale();
				break;

			default:
				
				fclose(sale_info_file);
				return;
		}
		
	}
			
			do
			{
				system("cls");
				
				transactions=0;
				
				fseek(sale_info_file,0,SEEK_SET);
				
				printf("Enter Invoice Number which is to be viewed: ");
				
				fflush(stdin);
				scanf("%u",&invoice);
			
				while(fread(&sale_info,sizeof(sale_info),1,sale_info_file)!=0)
				{
					
					if(invoice==sale_info.invoice)
					{
						fseek(view_customer_file,0,SEEK_SET);
						
						while(fread(&view_customer,sizeof(view_customer),1,view_customer_file)!=0)
						{
							if(strcmp(view_customer.id,sale_info.id)==0)
							{
								break;
							}
						}
									
						system("cls");
						
						printf("Invoice Details of entered Invoice Number..\n\n");
						printf("Customer ID          : %s\n",sale_info.id);
						printf("Customer Name        : %s\n",view_customer.name);
						printf("Address              : %s\n",view_customer.address);
						printf("Invoice No.          : %u\n",sale_info.invoice);
						printf("Total Items          : %u\n",sale_info.items);
						printf("Date                 : %hd/%hd/%hd\n",sale_info.date.day,sale_info.date.month,sale_info.date.year);
						printf("Time                 : %hd/%hd %s\n",sale_info.time.hour,sale_info.time.minute,sale_info.time.med);
						printf("Mode                 : %s\n",sale_info.mode);

						printf("\n\n\n\n\n\n\n\t\t\t\t\tPress any key to Watch The items");
						getch();
						
						transactions=sizeof(sale_item)*transactions;
						
						fseek(sale_transaction_file,transactions,SEEK_SET);						
						
						for(i=0;i<sale_info.items;i++)
						{
							
							fread(&sale_item,sizeof(sale_item),1,sale_transaction_file);
							
							if(i%11==0)
							{
								if(i!=0)
								{
									printf("\n\n\n\t\t\t\t\tPress any key to watch next Records.....");
									getch();
								}
								
								system("cls");
								
								printf("Item No.\tProduct Name\t\t\t\t\tQuantity\t\tPrice\t\t\tProduct Total\n\n");
							}
							
							printf("%d\t\t%s\t\t\t\t\t\t%u\t\t\t%.2lf\t\t\t%.2lf\n",i+1,sale_item.product,sale_item.quantity,sale_item.price,sale_item.quantity*sale_item.price);
							
							invoice_total+=(sale_item.quantity*sale_item.price);
						}
						
						printf("\n\nInvoice Total: %.2lf\n\n",invoice_total);
						
						break;
					
					}
					transactions +=  sale_info.items;
					
				}
				if(feof(sale_info_file))
				{
					printf("\nINVALID Invoice Number ENTERED! Try again...");
					sleep(2);
				}
				else
				{
					printf("\nPress Esc key to go back else press any other key to search for another Invoice");
					fflush(stdin);
					ch=getch();
				}
		
			}while(ch!=27);		//Loop continue till Esc key pressed
			
	
}

/********************************************************************************************************************************************************************************/


