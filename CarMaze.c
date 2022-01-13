#include <stdio.h>
#include <string.h>


/*
############################
Function to take maze input
############################
*/
void inputMaze(char maze[], int maxX, int maxY){
   for(int i=0; i < maxY; i++){
      printf("\n Input row %d: ", i);
      char dummy[maxX*maxY]; 
      scanf("%s", &dummy);
      
      int cnt = 0;
      
      for(int d=0; d<strlen(dummy);d++){
         if(!(dummy[d] == 'S' || dummy[d] == 'D' || dummy[d] == '.' || dummy[d] == '#')) cnt++;
      }

      if(cnt>0){
         printf("Enter S, D, . or #");
         i--;
      }
      
      else{
         if(strlen(dummy) != maxX) {
         printf("Enter %d characters!", maxX);
         i-- ; }

         else {
            for(int j=0;j<maxX;j++){
               maze[i*maxX+j] = dummy[j];   
            }
         }

      cnt = 0;
      for(int d=0; d<strlen(maze);d++){
         if(maze[d] == 'S')cnt++;
      }

      if(cnt>1){
            printf("S can be entered only once!");
            i--;
         }   
      }
      }
   }


/*
############################
Function to print maze
############################
*/
void printMaze(char maze[], int maxX, int maxY){
   for(int i=0; i < maxY; i++){
      for(int j=0; j<maxX; j++) {
         printf("%c", maze[i*maxX + j]);
      }
      printf("\n");
   }
}


/*
########################################
Function to find starting point of maze 
########################################
*/
int findStart(char maze[], int maxX, int maxY){
   int start = -1;
   char s = 'S';
   for(int i=0; i<maxY; i++){
      for(int j=0; j<maxX; j++){
         if(maze[i*maxX + j] == s){
            start = i*maxX+j;
            }
      }
   }
   
   if(start==-1) printf("Maze contains no starting point!");
   
   return start;
    
}


/*
############################################
DFS algorithm to find maze path from S to D
############################################
*/
int findPath(char maze[], int maxX, int maxY, int x, int y){
   
   char goal = 'D';
   char block = '#';
   char visited = '+';
   

   if(maze[y*maxX + x] == goal) return 1;   //Check Goal
   
   if(x >= maxX || x < 0 || y >= maxY || y < 0) return 0;  //Check bounds
   
   if(maze[y*maxX + x] == block) return 0;  // Check Block
 
   if(maze[y*maxX + x] == visited) return 0; // Check if visited already

   if(maze[y*maxX + x] != 'S') maze[y*maxX + x] = visited; //Mark as visited


   if (findPath(maze, maxX, maxY, x, y-1) == 1) return 1; //North
   if (findPath(maze, maxX, maxY, x+1, y) == 1) return 1; //East
   if (findPath(maze, maxX, maxY, x, y+1) == 1) return 1; //South
   if (findPath(maze, maxX, maxY, x-1, y) == 1) return 1; //West

   if(maze[y*maxX + x] != 'S') maze[y*maxX + x] = '.';  //Unmark for backtracking
   
   return 0;

}


/*
############################
Main function
############################
*/
void main() {
   
   int maxX, maxY, start, xStart, yStart, goalReached;

   printf("Number of rows?");
   scanf("%d", &maxY);
   printf("Number of columns?");
   scanf("%d", &maxX);

   if(maxX * maxY > 300) printf("Number of cells exceeds maximum!");

   else printf("%d rows and %d columns", maxY, maxX);

   char maze[maxX * maxY];
   inputMaze(maze, maxX, maxY);
   printMaze(maze, maxX, maxY);
   
   
   start = findStart(maze, maxX, maxY);

   if(start!=-1){
   
   xStart = (start) % maxX;
   yStart = (start) / maxX;
   
   printf("%c is at (%d, %d) \n", maze[yStart*maxX + xStart], xStart, yStart);
   
   goalReached = findPath(maze, maxX, maxY, xStart, yStart);
   

   if(goalReached == 0) printf("Path not found!");
   
   else {
      printf("Path found! \n");
      printf("Maze:\n");
      printMaze(maze, maxX, maxY);
      }
   }
   
}
