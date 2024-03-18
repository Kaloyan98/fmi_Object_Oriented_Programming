#include <iostream>

void deleteArr(int** arr, int n) {
	std::cout << "Cleaning up memory...\n";
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	std::cout << "Done!\n";
}

int main() {
	int n = 5;
	int m = 9;

	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			arr[i][j] = i + j;
			std::cout << arr[i][j] << " ";
		}

	  std::cout << "\n";
	}

	deleteArr(arr, n);

	return 0;
}
