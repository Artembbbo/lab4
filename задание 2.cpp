#include <iostream>
#include <cstdlib>
int** make(int, int);
void enter_elements(int, int**&, int, int);
void find_max(int, int**&);
int sum_triangle(int, int**&);
void clear_array(int, int**&);
void output_matrix(int, int**&);
int main()
{
	int n = 0;
	int a = 0;
	int b = 0;
	std::cout << "Enter matrix size\n";
	std::cin >> n;
	std::cout << "Enter range for random numbers\n";
	std::cin >> a >> b;
	if (n > 0) {
		int row = n;
		int col = n;
		make(row, col);
		int** matrix = make(row, col);
		enter_elements(n, matrix, a, b);
		output_matrix(n, matrix);
		find_max(n, matrix);
		std::cout << "sum in triangle" << " " << sum_triangle(n, matrix);
		clear_array(n, matrix);
	}
	else std::cout << "wrong size";
}

int** make(int row, int col)
{

	int** matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	return matrix;
}
void enter_elements(int n, int**& matrix, int a, int b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = std::rand() % (b - a + 1) + a;
		}
	}
}
void find_max(int n, int**& matrix) {
	int max = INT32_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[j][i] > max) {
				max = matrix[j][i];
			}
		}
		if (max < 0) {
			std::cout << "max element in neg col" << i + 1 << " " << max << " ";
		}
		else std::cout << "in col" << " " << i + 1 << " " << "positive element" << " ";
		max = INT32_MIN;
	}
}
int sum_triangle(int n, int**& matrix) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0 + i; j < n; j++) {
			if (matrix[i][j] < 0) {
				sum += matrix[i][j];
			}

		}
	}
	return sum;
}
void clear_array(int n, int**& matrix) {
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
void output_matrix(int n, int**& matrix) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

}
