#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

struct Coefficient;
struct Polynomial;

struct Polynomial *createPolynomial(int num);
void showPolynomial(struct Polynomial *polynomial);

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);
struct Polynomial *polynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);
struct Polynomial *polynomialMultiplicationByScalarFunction(struct Polynomial *polynomial, int psize, struct Coefficient *scalar);
struct Polynomial *polynomialResultForVariableFunction(struct Polynomial *polynomial, int psize, void *X);
struct Polynomial *polynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);

void polynomialAddition();
void polynomialMultiplication();
void polynomialMultiplicationByScalar();
void polynomialResultForVariable();
void polynomialComposition();

#endif
