#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <chrono>

int rows, cols;

// recurisve function that generates valid paths
int gen_paths(std::vector<std::vector<char>> &grid, int row, int col)
{
  // If reached final destination
  if (row == grid.size() - 1 && col == grid[0].size() - 1)
  {
    return 1;
  }

  //  if the current position is out of bounds or has an oponent
  if (row >= grid.size() || col >= grid[0].size() || grid[row][col] == 1)
  {
    return 0;
  }

  // Calculate paths by moving down and right
  int count = 0;
  count += gen_paths(grid, row + 1, col); // Move down
  count += gen_paths(grid, row, col + 1); // Move right

  return count;
}

// function implementation
int soccer_exhaustive(std::vector<std::vector<char>> &field)
{
  int rows = field.size();
  int cols = field[0].size();

  // Check if start and end points are blocked
  if (field[0][0] == 1 || field[rows - 1][cols - 1] == 1)
  {
    return 0;
  }

  // Calculate valid paths
  int valid_paths = gen_paths(field, 0, 0);

  return valid_paths;
}

int main()
{

  std::cout << "Enter the number of rows: ";
  std::cin >> rows;
  std::cout << "Enter the number of columns: ";
  std::cin >> cols;

  std::vector<std::vector<char>> field(rows, std::vector<char>(cols, ' '));
  char c;
  std::cin.ignore(); // clear input buffer before reading matrix

  std::cout << "Enter the matrix: " << std::endl;
  // parse the matrix
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      std::cin >> c;
      field[i][j] = c;
    }
  }

  // start calculating time
  auto start = std::chrono::high_resolution_clock::now();

  int paths = soccer_exhaustive(field);
  std::cout << "The number of valid paths is " << paths;
}
