#include <iostream>

void printReversed(int* arr, int index) {
	if (index < 0) {
		return;
	}

	std::cout << arr[index] << " ";
	printReversed(arr, index - 1);
}

int main() {
	int n = 0;
	std::cout << "n = ";
	std::cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	printReversed(arr, n - 1);
	std::cout << "\n";

	std::cout << "Cleaning up memory...\n";
	delete[] arr;
	std::cout << "Done! \n";

	return 0;
}
