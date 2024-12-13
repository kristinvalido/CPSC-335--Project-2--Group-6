#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Dimensions of the matrix
    const int rows = 16;
    const int cols = 16;

    // Seed the random number generator
    srand(time(0));

    // Create and print the random matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Randomly choose between '.' and 'X'
            char randomChar = (rand() % 2 == 0) ? '.' : 'X';
            cout << randomChar;
        }
        cout << endl;  // Move to the next row
    }

    return 0;
}
