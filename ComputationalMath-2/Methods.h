#pragma once

#include <iostream>
#include <math.h>
#include "Equations.h"

//#define function(x) f2(x)
//#define gfunction(x) g2(x)

int equationId = 1;

struct methodResult {
	bool isSolved = false;
	double root;
};

double function(double x) {
	if (equationId == 1) {
		return f1(x);
	}
	if (equationId == 2) {
		return f2(x);
	}
	if (equationId == 3) {
		return f3(x);
	}
	else {
		return f1(x);
	}
}

double gfunction(double x) {
	if (equationId == 1) {
		return g1(x);
	}
	if (equationId == 2) {
		return g2(x);
	}
	if (equationId == 3) {
		return g3(x);
	}
	else {
		return g1(x);
	}
}

methodResult solveWithBisectionMethod(int equationNumber) {
	equationId = equationNumber;
	std::cout << "Bisection Method" << std::endl;
	double leftGuess, rightGuess, epsilon;

	//todo
	//std::cout << setprecision(6) << std::fixed;

	std::cout << "Enter left guess: ";
	std::cin >> leftGuess;	
	std::cout << "Enter right guess: ";
	std::cin >> rightGuess;
	std::cout << "Enter tolerable error (epsilon): ";
	std::cin >> epsilon;

	if (function(leftGuess) * function(rightGuess) >= 0)
	{
		std::cout << "You have not assumed right guesses\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return solveWithBisectionMethod(equationNumber);
	}

	double middleGuess = leftGuess;

	//while ((rightGuess - leftGuess) >= epsilon) {
	while (fabs(function(rightGuess) - function(leftGuess)) >= epsilon) {
		// Find middle point
		middleGuess = (leftGuess + rightGuess) / 2;
		
		// Check if middle point is root
		if (function(middleGuess) == 0.0)
			break;
		// Decide the side to repeat the steps
		else if (function(middleGuess) * function(leftGuess) < 0)
			rightGuess = middleGuess;
		else
			leftGuess = middleGuess;
	}

	std::cout << "The value of root is: " << middleGuess << std::endl;
	std::cout << std::endl;
	
	return {true, middleGuess};
}

methodResult solveWithFixedPointIterationMethod(int equationNumber) {
	equationId = equationNumber;

	std::cin.clear();
	std::cin.ignore(256, '\n');

	int iterationCounter = 1;
	int maxAmountOfIterations;

	double x1, x2, epsilon;

	std::cout << "Enter start guess: ";
	std::cin >> x1;

	std::cout << "Enter tolerable error (epsilon): ";
	std::cin >> epsilon;

	std::cout << "Enter maximum iterations amount: ";
	std::cin >> maxAmountOfIterations;

	x2 = x1;
	while (fabs(function(x2)) > epsilon) {
		x2 = gfunction(x1);

		iterationCounter++;

		if (iterationCounter > maxAmountOfIterations) {
			std::cout << "No solution. Method diverges." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			return { false, 0 };
		}

		x1 = x2;
	}

	std::cout << "The value of root is: " << x2 << std::endl;

	return { true, x2 };
}

// Fixed Point Iteration Method
std::vector<methodResult> solveSystemWithIterationMethod(int systemId) {
	double guessX, guessY, epsilon;
	int iterationCounter = 1;
	int maxAmountOfIterations;

	std::cout << "Enter initial (guess) X: ";
	std::cin >> guessX;
	std::cout << "Enter initial (guess) Y: ";
	std::cin >> guessY;
	std::cout << "Enter tolerable error (epsilon): ";
	std::cin >> epsilon;
	std::cout << "Enter maximum iterations amount: ";
	std::cin >> maxAmountOfIterations;

	double previousX = guessX;
	double previousY = guessY;
	double currentX = guessX;
	double currentY = guessY;
	while (fabs(system_equation1(currentX, currentY)) > epsilon || fabs(system_equation2(currentX, currentY)) > epsilon) {
		iterationCounter++;
		currentX = transformed_s_equation1(previousX, previousY);
		currentY = transformed_s_equation2(currentX, previousY);

		if (iterationCounter > maxAmountOfIterations) {
			std::cout << "No solution. Method diverges." << std::endl;
			return { {false, 0} , { false, 0 } };
		}

		previousX = currentX;
		previousY = currentY;
	}
	
	if (!(std::isnan(currentX)) && !(std::isnan(currentY))) {
		std::cout << "The roots are: { " << currentX << " ; " << currentY << " }" << std::endl;
		return { {true, currentX}, {true, currentY} };
	}
	else {
		std::cout << "No solution. Method diverges." << std::endl;
		return { {false, 0} , { false, 0 } };
	}
}