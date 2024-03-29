#include <string.h>
#include <iostream>
#include "Student.h"

Student::Student() : fn(0), grades(nullptr), maxGradesCount(0), gradesCount(0) {
	this->setName("N/A");
}

Student::Student(int fn, const char* name, int maxGradesCount) : gradesCount(0) {
	this->setFn(fn);
	this->setName(name);
	this->maxGradesCount = maxGradesCount;
	this->grades = new Grade[maxGradesCount];
}

Student::~Student() {
	delete[] this->grades;
}

void Student::setFn(int fn) {
	if (fn < 0) {
		std::cout << "Wrong fn!\n";
		this->fn = 0;
		return;
	}

	this->fn = fn;
}

int Student::getFn() const {
	return this->fn;
}

void Student::setName(const char* name) {
	strcpy_s(this->name, name);
}

const char* Student::getName() const {
	return this->name;
}

int Student::getMaxGradesCount() const {
	return this->maxGradesCount;
}

int Student::getGradesCount() const {
	return this->gradesCount;
}

void Student::addGrade(Grade g) {
	if (gradesCount >= maxGradesCount) {
		// Resize grades array with x2 more length
		Grade* temp = this->grades;
		this->grades = new Grade[this->maxGradesCount * 2];
		for (int i = 0; i < this->gradesCount; i++) {
			this->grades[i] = temp[i];
		}
		this->maxGradesCount *= 2;
		delete[] temp;
		std::cout << "*Info: -> Grades resized! New max grades count: " << this->maxGradesCount << "\n";
	}
	this->grades[gradesCount] = g;
	gradesCount++;
}

double Student::getAverage() const {
	double sum = 0;
	if (this->gradesCount == 0) {
		return 0;
	}

	for (int i = 0; i < this->gradesCount; i++) {
		sum += this->grades[i].getGrade();
	}
	return sum / this->gradesCount;
}

double Student::getAverage(const char* subject) const {
	double sum = 0;
	double count = 0;
	for (int i = 0; i < this->gradesCount; i++) {
		// Compare given subject and current grade subject
		if (strcmp(this->grades[i].getSubject(), subject) == 0) {
			sum += this->grades[i].getGrade();
			count++;
		}
	}

	if (count == 0) {
		std::cout << "No such subject exists: " << subject << "\n";
		return 0;
	}

	return sum / count;
}

void Student::print() const {
	std::cout << this->getName() << " - FN:" << this->getFn() << "\n";
}

void Student::printGrades() const {
	std::cout << "--Marks:\n";
	if (this->gradesCount == 0) {
		std::cout << "No marks! \n";
	}

	for (int i = 0; i < this->gradesCount; i++) {
		std::cout << "---->";
		this->grades[i].print();
	}
}

void Student::printAll() const {
	this->print();
	this->printGrades();
}
