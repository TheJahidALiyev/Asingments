#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);
   
    return 0;
}

int solveMaze(char **maze, const int HT, const int WD, int x, int y){

    // solve recursively
    // however you might want to mark wrong paths with some other character
    // your functions should be able to solve other such mazes
    // pay attention to the bounds of the arrays
    // make sure you don't enter an infinite recursion

	if(y < 0 || x < 0 || x > HT - 1 || y > WD - 1 )
		return 0;  //in order to check the  boundaries of maze, we write this code 
	if(maze[x][y] == '#' || maze[x][y] == '.')
		return 0;  //in case of confronting with '#' or '.', the programs returns 0 and stop    
	if(maze[x][y] == '*')
		return 1;  //if we find the smybol '*', the program and the process of recursion  will stop

	maze[x][y] = '.';   //if the abovementioned conditions are false, we should mark our visited points


    //To check all possible ways to reach destination
	if(solveMaze(maze, HT, WD, x+1, y)) return 1; //checks the north
	else if(solveMaze(maze, HT, WD, x-1, y)) return 1; // checks the east
	else if(solveMaze(maze, HT, WD, x, y+1)) return 1; // checks the south
	else if(solveMaze(maze, HT, WD, x, y-1)) return 1; // checks the west

    //if the way is wrong, it puts a blank space(unmark the visited point) and try another way
	maze[x][y] = ' ';
	return 0;
}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
}
