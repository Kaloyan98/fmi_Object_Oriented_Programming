#include <iostream>

const int MAX_LENGTH = 100;

int** getTransponsedMatrix(int** matrix, int n, int m) {
	int **transponsedMatrix = 0;
	transponsedMatrix = new int*[n];
	for (int i = 0; i < n; i++) {
		transponsedMatrix[i] = new int[n];
		for (int j = 0; j < m; j++) {
			transponsedMatrix[i][j] = matrix[j][i];
		}
	}

	return transponsedMatrix;
}

void deleteArr(int** arr, int n) {
	std::cout << "Cleaning up memory...\n";
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	std::cout << "Done!\n";
}

void printMatrix(int** arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	int n = 0, m = 0;
	std::cout << "Enter rows and columns and then array elements: \n";
	std::cin >> n;
	std::cin >> m;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << "Input matrix: \n";
	printMatrix(matrix, n, m);

	int** transposedMatrix = getTransponsedMatrix(matrix, m, n);
	std::cout << "Transposed matrix: \n";
	printMatrix(transposedMatrix, m, n);

	deleteArr(matrix, n);
	deleteArr(transposedMatrix, m);

	return 0;
}
