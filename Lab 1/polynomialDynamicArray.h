#ifndef POLYNOMIALDYNAMICARRAY_H_
#define POLYNOMIALDYNAMICARRAY_H_

struct Polynomial;
struct Polynomial *createPolynomial();
void outputPolynomial(struct Polynomial *polynomial);

struct Polynomial *getData();
struct Polynomial *pushElementInDynamicArray(struct Polynomial *dynamicArray, void *element);
void *getElementFromDynamicArray(struct Polynomial *dynamicArray, int i);

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
struct Polynomial *polynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
//struct Polynomial *polynomialMultiplicationByScalarFunction(struct Polynomial *polynomial, int psize, struct Coefficient *scalar);
//struct Coefficient *polynomialResultForVariableFunction(struct Polynomial *polynomial, int psize, struct Coefficient *X);
struct Polynomial *polynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);

void polynomialAddition();
void polynomialMultiplication();
void polynomialMultiplicationByScalar();
void polynomialResultForVariable();
void polynomialComposition();

#endif

