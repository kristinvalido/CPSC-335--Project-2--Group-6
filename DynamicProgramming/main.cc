#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

/* Example:

Enter number of rows: 8
Enter number of columns: 9
Enter the matrix elements:
......X.X
X........
...X...X.
..X....X.
.X....X..
....X....
..X.....X
.........
102 paths available to the end of the pitch

 */

using namespace std;
int rows, cols;

int soccer_dyn_prog(vector<vector<char>> F)
{
  // corner case: initial cell is not passible
  if (F[0][0] == 'X')
  {
    return 0;
  }

  // A = new r*c matrix initialized to zeroes
  vector<vector<int>> A(rows, vector<int>(cols, 0));
  int above;
  int from_left;

  // base case: first square is passable
  A[0][0] = 1;

  // general cases
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (F[i][j] == 'X')
      {              // opponent is there
        A[i][j] = 0; // path not possible
        continue;    // goes to next for loop iteration
      }
      above = from_left = 0; // initialize both
      if (i > 0 && F[i - 1][j] == '.')
      { // space above is passible AND current space is passable
        above = A[i - 1][j];
      }
      if (j > 0 && F[i][j - 1] == '.')
      {
        from_left = A[i][j - 1];
      }
      A[i][j] += above + from_left;
    }
  }
  return A[rows - 1][cols - 1];
}

int main()
{
  cout << "Enter number of rows: ";
  cin >> rows;
  cout << "Enter number of columns: ";
  cin >> cols;

  // Using a 2D vector
  vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
  char c;
  cin.ignore(); // clear input buffer before reading matrix

  cout << "Enter the matrix elements:\n";
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cin >> c;
      matrix[i][j] = c;
    }
  }

  // start calculating time
  auto start = std::chrono::high_resolution_clock::now();
  // run the algorithm, print the result
  cout << soccer_dyn_prog(matrix) << " paths available to the end of the pitch" << endl;
  // end calculating time
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Execution time: " << std::setprecision(10) << duration.count() << " microseconds" << std::endl;
  return 0;
}
