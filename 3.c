#include "./lib/cheader.h"

// time O(m * n)
// space O(1)

bool Find(int matrix[][4], int rows, int cols, int number) {

	bool found = false;

	if (matrix != NULL && rows > 0 && cols > 0) {
		int row = 0;
		int col = cols - 1;

		while(row < rows && col >= 0) {
			if (matrix[row][col] == number)
			{
				found = true;
				break;
			}
			else if(matrix[row][col] > number)
				col--;
			else
				row++;
		}

	}

	return found;
}

int main() {
	int input[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	printf("%d", Find(input, 4, 4, 17));
}
