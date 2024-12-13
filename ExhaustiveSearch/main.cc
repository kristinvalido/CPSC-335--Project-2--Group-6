#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>

int soccer_exhaustive(std::vector<std::vector<char>> &field)
{
  int rows = field.size();
  int cols = field[0].size();
  int counter = 0;           // path counter
  int len = rows + cols - 2; // max path length

  // base case
  if (field[0][0] == 'X' || field[rows - 1][cols - 1] == 'X')
  {
    return 0;
  }
  else
  {
    for (int path = 0; path < pow(2, len); ++path)
    {
      int r = 0, c = 0;                      // row and column indices
      for (int step = 0; step < len; ++step) // for k from 0 𝑡𝑜 𝑙𝑒𝑛 − 1 inclusive:
      {
        int bit = (path >> step) & 1; // bit = (bits >> 𝑘) & 1
        if (bit == 1)
        {
          ++c; // go right
        }
        else
        {
          ++r; // go down
        }
        // out of bounds
        if (r >= rows || c >= cols || field[r][c] == 'X')
        {
          r = rows;
          break;
        }
        // if candidate stays inside the grid, never crosses an X cell, and ends at (𝑟 − 1, 𝑐 − 1):
        if (r == rows - 1 && c == cols - 1)
        {
          ++counter;
        }
      }
    }
  }
  return counter;
}

int main()
{
  int rows, cols;
  // input
  std::cout << "Enter the number of rows: ";
  std::cin >> rows;
  std::cout << "Enter the number of columns: ";
  std::cin >> cols;

  // 2D vector to store the "soccer field"
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
  std::cout << "Calculating..." << std::endl;

  // start calculating time
  auto start = std::chrono::high_resolution_clock::now();

  int paths = soccer_exhaustive(field);
  // end calculating time
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  std::cout << "Execution time: " << std::setprecision(10) << duration.count() << " microseconds" << std::endl;
  std::cout << "The number of valid paths is " << paths << std::endl;

  return 0;
}
