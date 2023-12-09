#include <stdio.h>
#include <conio.h>
#define WIN 1
#define NO_RESULT 0

void initialise_block(void);
void print_instrutions(void);
void print_block(void);
int update_check(char input);

char block[9];
char turn;
short int turn_counter = 1;

int main()
{
    char first_player_name[25], second_player_name[25];
    char input;
    short int result = NO_RESULT;

    initialise_block();
    print_instrutions();

    printf("Enter 1st player Name: ");
    gets(first_player_name);
    printf("Enter 2nd player Name: ");
    gets(second_player_name);
    puts("\n\n--------------------------Press any key to continue--------------------------");
    getch();
    do
    {
        system("cls");
        printf("%s - O\t\t%s - X\n\n", first_player_name, second_player_name);

        if (result == NO_RESULT)
        {
            if (turn_counter % 2)
            {
                printf("%s's Turn\n\n\n", first_player_name);
                turn = 'O';
            }
            else
            {
                printf("%s's Turn\n\n\n", second_player_name);
                turn = 'X';
            }
            print_block();
            input = getch();
            result = update_check(input);
        }
        if (result == WIN)
        {
            system("cls");
            print_block();

            if (turn == 'O')
                printf("\n\nO i.e. %s wins.....", first_player_name);
            else
                printf("\n\nX i.e. %s wins.....", second_player_name);
            break;
        }

    } while (turn_counter != 10);
    if (turn_counter == 10)
    {
        system("cls");
        print_block();
        printf("\n\nGame tied......");
    }

    getch();
    return 0;
}

void initialise_block(void)
{
    int i;
    for (i = 0; i < 9; i++)
        block[i] = '1' + i;
}

void print_instrutions(void)
{
    puts("..............................................INSTRUCTIONS..............................................\n");
    puts("All the blocks are represented by a unique character(1-9)");
    puts("Press the same key to get your symbol (O or X)");
    puts("Player whose first three symbols are in a single line either horizontally, Vertically or Diagonally wins\n");
}

void print_block(void)
{
    int i;
    for (i = 0; i < 9; i += 3)
    {
        printf("\n   %c   |   %c   |   %c\n", block[i + 0], block[i + 1], block[i + 2]);
        if (i != 6)
            printf("_____________________");
    }
}

int update_check(char input)
{
    int i, j;

    if (block[input - '1'] == 'O' || block[input - '1'] == 'X')
    {
        printf("\a");
        return NO_RESULT;
    }

    for (i = 1; i < 10; i++)
    {
        if (input == i + '0')
            break;
    }
    if (i == 10)
    {
        printf("\a");
        return NO_RESULT;
    }

    block[input - '1'] = turn;

    for (i = 0, j = 0; i < 9; i += 3, j++)
    {
        if ((block[j + 0] == block[j + 3] && block[j + 3] == block[j + 6]) || (block[i + 0] == block[i + 1] && block[i + 2] == block[i + 1]))
        {
            return WIN;
        }
    }

    if ((block[0] == block[4] && block[4] == block[8]) || (block[2] == block[4] && block[4] == block[6]))
        return WIN;

    turn_counter++;

    return NO_RESULT;
}