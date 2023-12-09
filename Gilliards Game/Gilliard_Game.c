//<----------------------------------------------GILLIARD GAME------------------------------------------>

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int move=0;
void print(int A[4][4]);
void getarrow(int *row,int *col,int A[4][4]);
int check(int A[4][4]);
int main()
{
	int A[4][4]={			
					{1,4,15,7},
					{8,10,2,11},
					{14,3,6,13},
					{12,9,5,16}
				};
	int row,col;
	row=col=3;
	print(A);
	getarrow(&row,&col,A);
	while(check(A)==0)
	{
		system("cls");
		print(A);
		getarrow(&row,&col,A);
	}
	printf("\n\n\nThe Number of Moves were: %d",move);
	
	return 0;
}
void print(int A[4][4])
{
	register int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(A[i][j]==16)
				printf(" \t");
			else
				printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void getarrow(int *row,int *col,int A[4][4])
{
	int temp;
	again:
	switch (getch())
	{
		case 'W':    // key up(W)
		case 'w':
			if(*row==3)
			{
				printf("\a");
        		goto again;
			}
			else 
			{
				A[*row][*col]=A[++(*row)][*col];
				A[*row][*col]=16;
				move++;
			}
			break;
    	case 'S':    // key down(S)
    	case 's':
    		if(*row==0)
    		{
				printf("\a");
        		goto again;
			}
			else
    		{
    			A[*row][*col]=A[--(*row)][*col];
				A[*row][*col]=16;
				move++;
			}
    	    break;
    	case 'D':    // key right(D)
    	case 'd':
    		if(*col==0)
    		{
				printf("\a");
        		goto again;
			}
			else
    		{
    			A[*row][*col]=A[*row][--(*col)];
    			A[*row][*col]=16;
    			move++;
			}
        	break;
    	case 'A':    // key left(A)
    	case 'a':
    		if(*col==3)
    		{
				printf("\a");
        		goto again;
			}
			else
    		{
    			A[*row][*col]=A[*row][++(*col)];
    			A[*row][*col]=16;
    			move++;
			}
        	break;
        case 27:		//Esc key
        	printf("\nMoves till now: %d",move);
        	exit(0);
        	break;
        default:
        	printf("\a");
        	goto again;
        	break;
	}
}
int check(int A[4][4])
{
	register int i,j,k=1;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(A[i][j]!=k++)
				return 0;
		}
	}
	return 1;
}
