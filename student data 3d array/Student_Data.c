#include<stdio.h>
#include<conio.h>
#include<string.h>
void update(char A[5][5][20]);
void view(char A[5][5][20]);
int main()
{
	char A[5][5][20];
	register int i,j,k;
	char ch;
	for(i=0;i<5;i++)
	{
		printf("\n\nEnter the following Information for student-%d:\n\n",i);
		printf("Enter the Roll No. of student: ");
		gets(A[i][0]);
		printf("Enter the Name of student: ");
		gets(A[i][1]);
		printf("Enter the Father's Name of student: ");
		gets(A[i][2]);
		printf("Enter the Mother's name of student: ");
		gets(A[i][3]);
		printf("Enter the Phone No. of student: ");
		gets(A[i][4]);
	}
	system("cls");
	printf("..........All data Entered SUCCESSFULLY..........\n");
	do
	{
		
		printf("\nChoose from the following:\n");
		printf("Press 1 to update Data\n");
		printf("Press 2 to View Data\n");
		printf("Press any other key to exit:  ");
		fflush(stdin);
		ch=getche();
		switch(ch)
		{
			case'1':
				update(A);
				break;
			case '2':
				view(A);
				break;
			default:
				printf("\n\n\n..........................NIKL TYM SRR........................");
		}
	}while((ch=='1')||(ch=='2'));
	
	return 0;
}
void update(char A[5][5][20])
{
	register int i=0;
	int comp;
	char temp[10];
	char ch;
	printf("\nEnter the Roll no of student whose data is to be modified: ");
	gets(temp);
	do
	{
		comp = strcmp(temp,A[i++][0]);
	}while(comp!=0 && i<5);i--;
	if(comp==0)
	{
		do
		{
			printf("\nPress 1 to update Name\n");
			printf("Press 2 to update Father's Name\n");
			printf("Press 3 to update Mother's Name\n");
			printf("Press 4 to update Phone No.\n");
			printf("Press any other key to back:\n");
			fflush(stdin);
			ch=getche();
			switch(ch)
			{
				case '1':
					printf("\nEnter Name: ");
					gets(A[i][1]);
					printf("Updated Successfully\n");
					break;
				case '2':
					printf("\nEnter Father's Name: ");
					gets(A[i][2]);
					printf("Updated Successfully\n");
					break;
				case '3':
					printf("\nEnter Mother's Name: ");
					gets(A[i][1]);
					printf("Updated Successfully\n");
					break;
				case '4':
					printf("\nEnter Mobile No.: ");
					gets(A[i][1]);
					printf("Updated Successfully\n");
					break;
				default:
					return;
			}
			
		}while((ch=='1')||(ch=='2')||(ch=='3')||(ch=='4'));
	}
	else
	{
		printf("Invalid Roll no. Try again: \n");
		update(A);
	}
}
void view(char A[5][5][20])
{
	char ch;
	char temp[10];
	register int i=0;
	int comp;
	printf("\n\nChoose from the following:\n");
	printf("Press 1 to view all Roll no.'s data\n");
	printf("Press 2 to view Individual Roll no.'s data\n");
	printf("Press any other key to go back: ");
	fflush(stdin);
	ch=getche();
	switch(ch)
	{
		case '1':
			printf("All Roll no.'s Data is as Follows\n\n\n");
			for(i=0;i<5;i++)
			{
				printf("Roll No.: \t\t\t%s\n",A[i][0]);
				printf("Name:\t\t\t%s\n",A[i][1]);
				printf("Father's Name:\t\t\t%s\n",A[i][2]);
				printf("Mother's Name:\t\t\t%s\n",A[i][3]);
				printf("Phone Number:\t\t\t%s\n\n",A[i][4]);
			}
			break;
		case '2':
			printf("\nEnter Roll no. whose data is to be viewed: ");
			gets(temp);
			do
			{
				comp = strcmp(temp,A[i++][0]);
			}while(comp!=0 && i<5);i--;
			if(comp==0)
			{
				printf("Roll No.: \t\t\t%s\n",A[i][0]);
				printf("Name:\t\t\t%s\n",A[i][1]);
				printf("Father's Name:\t\t\t%s\n",A[i][2]);
				printf("Mother's Name:\t\t\t%s\n",A[i][3]);
				printf("Phone Number:\t\t\t%s\n\n",A[i][4]);
			}
			else
			{
				printf("Invalid Roll no. Try again: \n");
				view(A);
			}
			break;
	}
}
