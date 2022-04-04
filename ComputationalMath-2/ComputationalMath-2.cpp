#include <iostream>
#include "Methods.h"
#include "Equations.h"

int main() {

	std::cout << "Non-linear equation & system of equations solver." << std::endl;
	std::cout << "Using methods: bisection method, fixed point iteration, fixed point interation for systems." << std::endl;

	int taskNumber = 1;
	std::cout << "-------------------" << std::endl;
	std::cout << "What task do you want to solve?" << std::endl;
	std::cout << "[1] solve a non-linear equation" << std::endl;
	std::cout << "[2] solve a system of non-linear equations" << std::endl;
	std::cout << "Enter task number: ";
	std::cin >> taskNumber;
	std::cout << "-------------------" << std::endl;



	if (taskNumber == 1) {
		int choosedEquation = chooseEquation();

		methodResult firstRoot, secondRoot;
		double delta;
		firstRoot = solveWithBisectionMethod(choosedEquation);
		secondRoot = solveWithFixedPointIterationMethod(choosedEquation);

		if (firstRoot.isSolved && secondRoot.isSolved) {
			delta = fabs(firstRoot.root - secondRoot.root);
			std::cout << std::endl;
			std::cout << "Difference (delta) between two methods results (roots): " << delta << std::endl;
		}
		else {
			std::cout << "One of the equations was not solved, difference (delta) between roots cannot be found." << std::endl;
		}
	}
	else if (taskNumber == 2) {
		printSystem();
		solveSystemWithIterationMethod(1);
	}
	else {
		std::cout << "No task chosen." << std::endl;
	}	

	return 0;
}