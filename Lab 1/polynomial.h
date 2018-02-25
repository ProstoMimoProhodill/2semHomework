#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

struct Coefficient;
struct Polynomial;

struct Polynomial *createPolynomial(int num);
struct Coefficient *getData();
void showPolynomial(struct Polynomial *polynomial);

//void polynomialAddition();
struct A *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);
void polynomialMultiplication(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
void polynomialMultiplicationByScalar(struct Polynomial *polynomial, void *scalar);
void polynomialResultForVariable(struct Polynomial *polynomial, void *X);
void polynomialComposition(struct Polynomial *polynomial1, struct Polynomial *polynomial2);

//int polynomialResultInt(struct Polynomial *polynomial, int x);
#endif

