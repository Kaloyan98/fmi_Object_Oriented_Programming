#include <iostream>

int* getArr(int L) {
	int* arr = new int[L];
	for (int i = 0; i < L; i++) {
		arr[i] = i + 1;
	}

	return arr;
}

int main() {
	int L = 0;
	std::cin >> L;

	int* arr = getArr(L);
	for (int i = 0; i < L; i++) {
		std::cout << arr[i] << "\n";
	}

	std::cout << "Cleaning up memory...\n";
	delete[] arr;
	std::cout << "Done! \n";

	return 0;
}
