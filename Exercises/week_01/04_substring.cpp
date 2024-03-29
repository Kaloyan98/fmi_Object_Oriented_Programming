#include <iostream>

int myStrLen(const char* str) {
  if (str == nullptr) {
    return -1;
  }

	int index = 0;
	while (str[index]) {
		index++;
	}

	return index;
}

bool doExist(const char* str, const char* subStr) {
  if (str == nullptr || subStr == nullptr) {
    return false;
  }

	int strLength = myStrLen(str);
	int subStrLength = myStrLen(subStr);
	bool doSubStrExists;
	int index = 0;

	for (int i = 0; i <= strLength - subStrLength; i++) {
		doSubStrExists = true;
		for (int j = 0; j < subStrLength; j++) {
			if (subStr[j] != str[i]) {
				doSubStrExists = false;
				break;
			} else {
				i++;
			}
		}

		// if this is true it means that the text contains the word!
		if (doSubStrExists) {
			return true;
		}
	}

	return false;
}

int main() {
	char text[100] = "Hello OOP world!";
	char word[100] = "OOP";

	std::cout << doExist(text, word) << "\n";
	std::cout << doExist("A", "B") << "\n";
	std::cout << doExist("Hello", "eo") << "\n";
	std::cout << doExist("Hello", "Hello") << "\n";

	return 0;
}
