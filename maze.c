#include <math.h>
#include <string.h>
#include <stdio.h>
//declaring functions
int leftPath(int*);
int rightPath(int*);
int upPath(int*);
int downPath(int*);
//declaring global variables/pointers
//initial starting position for user within the maze
int row = 3;
int col = 0;
int *ptr_row = &row;
int *ptr_col = &col;
int main(void)
{
    int x = 23;
    char move;
    int l, r, u, d;

//declaring the maze as double array
    int maze[7][7] = {  {0 , 0 , 1 , 1 , 1 , 0, 0},
                        {0 , 1 , 1 , 0 , 1 , 1, 0},
                        {0 , 1 , 0 , 0 , 0 , 1, 0},
                        {7 , 1 , 0 , 1 , 1 , 1, 0},
                        {0 , 0 , 1 , 1 , 0 , 0, 0},
                        {0 , 0 , 1 , 0 , 1 , 1, 1},
                        {0 , 0 , 1 , 1 , 1 , 0, 1} };
    //printing introduction/interface of game
    printf("\n");
    printf("           *******WELCOME TO THE MAZE!*******            \n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("|The rules are simple: You can either go left, right, up, or down.|\n");
    printf("|Enter L to go left. Enter R to go right. Enter U to go up. Enter D to go down.|\n");
    printf("\n");
    printf("\n");
    printf("Here is the layout of the maze->\n");  
    printf("\n");
    //printing out maze
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            printf("| %d |", maze[i][j]);
        }
        printf("\n");
    }
    //printing instructions of game
    printf("\n");
    printf("|The maze will be updated and shown as you move through the maze.|\n");
    printf("|Starting positon is the 7 in the maze, the end point is the 1 in the lower right corner.|\n");
    printf("|The 1s are the paths in the maze, the 0s are walls/deadends. You only have %d moves to reach the end of the maze.|\n", x);
    printf("GOOD LUCK!\n");
    printf("\n");
    //user inputting first move
    printf("enter your move:\n");
    scanf("%c", &move);

//while loop going through the amount of moves needed to go through maze
while(x > 0)
 {
    //conditionals for each move
    if(move == 'L' || move == 'l')
    {
        l = leftPath(ptr_col);
        // this conditional is incase the user inputs goes beyond the maze
        if(l < 0)
        {
            printf("invalid move, try again!");
        }
        else
        //if move is within maze, it will set that move with 7
        {
            maze[row][l] = 7;
        }

    }
    else if(move == 'R' || move == 'r')
    {
        r = rightPath(ptr_col);
        // this conditional is incase the user inputs goes beyond the maze
        if(r > 6)
        {
            printf("invalid move, try again!");
        }
        else
        //if move is within maze, it will set that move with 7
        {
            maze[row][r] = 7;
        }
    
    
    }
    else if(move == 'U' || move == 'u')
    {
        u = upPath(ptr_row);
        // this conditional is incase the user inputs goes beyond the maze
        if(u < 0)
        {
            printf("invalid move, try again!");
        }
        else
        //if move is within maze, it will set that move with 7
        {
            maze[u][col] = 7;
        }

    }
    else
    {
         d = downPath(ptr_row);
         // this conditional is incase the user inputs goes beyond the maze
        if(d > 6)
        {
            printf("invalid move, try again!");
        }
        else
        //if move is within maze, it will set that move with 7
        {
            maze[d][col] = 7;
        }
    }
    //conditional and loop when the user reaches the end of the maze
    if(row == 6 && col == 6)
    {
        //prints out completed maze one last time
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                  printf("| %d |", maze[i][j]);
            }
        printf("\n");
        }
        //the ending statements for the maze
        printf("******You just reached finish the maze!******\n");
        printf("Thank you for playing :)");
        break;
    }
    //for loop that prints maze
    //shows the progression of the user
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            printf("| %d |", maze[i][j]);
        }
        printf("\n");
    }
    //after the previous move has been completed, the next move is entered
    printf("enter your next move:");
    scanf (" %c", &move);
    //decrements amount of moves
    x--;
  }
}

//functions that create and save the move users entered
//using pointer to change the actual value of col and row

int leftPath(int *col)
{
    //decrements value of column, allowing user to move left 
     *col = *col - 1;
     return *col;
}
int rightPath(int *col)
{
    //increments value of column, allowing user to move right
    *col = *col + 1;
    return *col;

}
int upPath(int *row)
{
    //decrements value of row, allowing user to move up
    *row = *row - 1;
    return *row;
}
int downPath(int *row)
{
    //increments value of row, allowing user to move down
    *row = *row + 1;
    return *row;

}