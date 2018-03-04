#ifndef POLYNOMIALLIST_H_
#define POLYNOMIALLIST_H_

struct Coefficient;
struct Polynomial;

struct Polynomial *createPolynomial(int num);
void showPolynomial(struct Polynomial *polynomial);

struct Polynomial *listPolynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);
struct Polynomial *listPolynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);
struct Polynomial *listPolynomialMultiplicationByScalarFunction(struct Polynomial *polynomial, int psize, struct Coefficient *scalar);
struct Coefficient *listPolynomialResultForVariableFunction(struct Polynomial *polynomial, int psize, struct Coefficient *X);
struct Polynomial *listPolynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);

void listPolynomialAddition();
void listPolynomialMultiplication();
void listPolynomialMultiplicationByScalar();
void listPolynomialResultForVariable();
void listPolynomialComposition();

#endif

