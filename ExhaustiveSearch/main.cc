#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vetcor>

using namespace std;

// the grid is gonna be 8 rows x 9 columns 

// recurisve function that generates valid paths
int gen_paths(vector<vector<int>> grid, int row , int col){

  // if reached final destination which is grid[7][8] 
  if (row ==  && col == 8){
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
int soccer_exhaustive( int rows, int col)
{
  // in this grid, the opponents are going to equal 1, if the cell is safe to travel then it's gonna equal 0
  // it doesn't say anywhere that we have to ask the user for how many columns or rows or how many opponents there needs to be 
  // lets just say im following the example and gonna make it an 8 x 9 grid and with the same number of opponents (12)
  
  // this is gonna create the row x col grid and set it all to 0's
  vector<vector<int>> field(row,vector<int>(col,0));

  // this is gonna add the "opponents" to the grid and lets just say were adding 
  while (num_opp <= 12)
  {
    int rand_row = rand() % (row +1 ); // gives me random number between 0 and row + 1 
    int rand_col = rand() % (col +1 ); // gives me random number between 0 and col + 1
    if ( field[rand_row][rand_col] == 0){
      // this is adding the opponent to the grid
      field[rand_row][rand_col] = 1;
      ++num_opp; // if an opponent was successfully added to the field then it increases
    }
  }

  // this is the code that's going to traverse the field now and find valid paths
  // if the start and end points are blocked thn no valid paths 
  if(field[0][0] == 1 || field[row-1][col-1] == 1){
    return 0;
  }
  
  int valid_paths = gen_paths(field, 0, 0);
  
  return valid_paths;
  
    
  }
  

int main()
{
  int rows;
  int col;
  cout << "Enter the number of rows that you want: ";
  cin >> rows;
  cout << "Enter the number of columns you want: ";
  cin >> col;
  int paths = soccer_exhaustive(rows, col);
  cout << "The number of valid paths is " << paths;
}
  
