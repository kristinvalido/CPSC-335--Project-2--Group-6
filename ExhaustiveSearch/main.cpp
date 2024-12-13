#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

// the grid is gonna be 8 rows x 9 columns 

// recurisve function that generates valid paths
int gen_paths(int grid[][9], int row , int col){

  // if reached final destination which is grid[7][8] 
  if (row == 7 && col == 8){
    return 1;
  }
  // check current position has an opponent or if it's out of bounds
  if (grid[row][col] == 1 || row >= 8 || col >= 9){
    return 0;
  }
  int count = 0;
  count = count + gen_paths(row + 1, col);
  count = count + gen_paths(row, col+1);
  return count;
  
}

//function implementation
int soccer_exhaustive( )
{
  // in this grid, the opponents are going to equal 1, if the cell is safe to travel then it's gonna equal 0
  // it doesn't say anywhere that we have to ask the user for how many columns or rows or how many opponents there needs to be 
  // lets just say im following the example and gonna make it an 8 x 9 grid and with the same number of opponents (12)
  
  // this is gonna create the 8 x 9 grid and set it all to 0's
  int field[8][9] = {0};

  // this is gonna add the "opponents" to the grid and lets just say were adding 
  num_opp = 0;
  while (num_opp <= 12)
  {
    int rand_row = rand() % (9); // gives me random number between 0 and 8
    int rand_col = rand() % (10); // gives me random number between 0 and 9
    if ( field[rand_row][rand_col] == 0){
      // this is adding the opponent to the grid
      field[rand_row][rand_col] = 1;
      ++num_opp; // if an opponent was successfully added to the field then it increases
    }
  }

  // this is the code that's going to traverse the field now and find valid paths
  // if the start and end points are blocked thn no valid paths 
  if(field[0][0] == 1 || field[7][8] == 1){
    return 0;
  }
  int valid_paths = gen_paths(field, 0, 0);
  
  return valid_paths;
  
    
  }
  

int main()
{
  cout << "The grid is 8 x 9" << endl;
  int paths = soccer_exhaustive( );
  cout << "The number of valid paths is " << paths;
}
  
