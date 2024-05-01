#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void reset_board();
void print_board();
int checkfree_space();
void player_move();
char check_winner();
void cumputer_move();


void print_winner(char);


int main()
{
    char winner = ' ';
    srand(time(0));

    reset_board();
    while(winner == ' ' && checkfree_space() !=0)
    {
        print_board();
        player_move();
        winner = check_winner();
        if (winner != ' ' || checkfree_space() == 0)
        {
            break;
        }

        cumputer_move();
        winner = check_winner();
        if (winner != ' ' || checkfree_space() == 0)
        {
            break;
        }
    
    }
    
    print_board();
    print_winner(winner);


    return 0;
}

void reset_board()
{
    for(int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void print_board()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkfree_space()
{
    int free_spaces = 9;
    for (int i =0;i<3;i++)
    {
        for (int j =0;j<3;j++)
        {
            if (board[i][j] != ' ')
            {
                free_spaces--;
            }
        }
    }
    return free_spaces;
}
void player_move()
{
    int x,y;
    do{
        printf("Enter raw #(1-3) :");
        scanf("%d",&x);
        x--;

        printf("Enter column #(1-3) :");
        scanf("%d",&y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid move :\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }while (board[x][y] != ' ');

    
        
}


void cumputer_move()
{
    

        int x,y;
        if(checkfree_space() > 0)
        {
            do 
            {
                x = rand() % 3;
                y = rand() % 3;

            }while (board[x][y] != ' ');

            board[x][y] = COMPUTER;
        }
        else{
            print_winner(' ');

        }
}
char check_winner()
{
    // check row
    // board[column][raw]
    for (int i = 0; i< 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] )
        {
            return board[i][0];
        }
    }
    // check column
    for (int i = 0; i< 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] )
        {
            return board[0][i];
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] )
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] )
    {
        return board[0][2];
    }
    return  ' ';


}


void print_winner(char winner)
{
    if(winner == PLAYER)
    {
        printf("You win!!!\n");
    }
    else if(winner == COMPUTER)
    {
        printf("You loose!!!\n");
    }
    else    
    {
        printf("it's tie!!!\n");
    }
}