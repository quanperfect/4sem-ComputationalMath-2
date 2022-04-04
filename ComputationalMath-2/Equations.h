#pragma once

#include <math.h>
#include <vector>

#ifndef EQUATIONS_H

#define EQUATIONS_H

int chooseEquation() {
	int choice;
	std::cout << "Equations: " << std::endl;
	std::cout << "[1] cos(x) - x*exp(x) = y" << std::endl;
	std::cout << "[2] sin(x) - x = y" << std::endl;
	std::cout << "[3] x^2 - 6*x + 8 = y" << std::endl;

	std::cout << "Please choose one of the equations: ";
	std::cin >> choice;
	std::cout << "-------------------" << std::endl;
	
	return choice;
}

void printSystem() {
	std::cout << "System of equations:\n{\n";
	std::cout << "x^2 + x*y - 10 = 0" << std::endl;
	std::cout << "y + 3*x*y^2 - 57 = 0" << std::endl;
	std::cout << "}\n";
}

double f1(double x) {
	return (cos(x) - x * exp(x));
}
double g1(double x) {
	return (cos(x) / exp(x));
}
double f2(double x) {
	return (sin(x) - x);
}
double g2(double x) {
	return (sin(x));
}
double f3(double x) {
	return (x * x - 6 * x + 8);
}
double g3(double x) {
	return ((x * x + 8) / 6);
}
//#define f1(x) ( cos(x)-x*exp(x) )
//#define g1(x) ( cos(x) / exp(x) )
//#define f2(x) ( sin(x) - x )
//#define g2(x) ( sin(x) )
//#define f3(x) (x * x - 6 * x + 8)
//#define g3(x) ((x * x + 8) / 6)

//#define system_equation1(x,y) (x * x - y - 1)
//#define system_equation2(x,y) (x - y*y + 1)

#define system_equation1(x,y) (x*x + x*y - 10)
#define system_equation2(x,y) (y + 3*x*y*y - 57)
#define transformed_s_equation1(x,y) ( std::sqrt(10 - x*y) )
#define transformed_s_equation2(x,y) ( std::sqrt( (57-y)/(3*x) ) )


//std::vector<std::vector<double>> calculateSystemJacobian(double x, double y) {
//	std::vector<std::vector<double>> jacobian;
//	std::vector<double> jacobianRow;
//	jacobianRow.push_back(2 * x);
//	jacobianRow.push_back(-1);
//	jacobian.push_back(jacobianRow);
//	jacobianRow.clear();
//	jacobianRow.push_back(1);
//	jacobianRow.push_back(-2 * y);
//	jacobian.push_back(jacobianRow);
//
//	return jacobian;
//}
#endif // !

