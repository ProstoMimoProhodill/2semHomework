#ifndef POLYNOMIALDYNAMICARRAY_H_
#define POLYNOMIALDYNAMICARRAY_H_

struct Polynomial;
struct Scalar;

struct Polynomial *createPolynomial();
void outputPolynomial(struct Polynomial *polynomial);
void *getElementFromDynamicArray(struct Polynomial *dynamicArray, int i);
struct Polynomial *pushElementInDynamicArray(struct Polynomial *dynamicArray, void *element);

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
struct Polynomial *polynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
struct Polynomial *polynomialMultiplicationByScalarFunction(struct Polynomial *polynomial, struct Scalar *scalar);
struct Scalar *polynomialResultForVariableFunction(struct Polynomial *polynomial, struct Scalar *X);
struct Polynomial *polynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size);

void polynomialAddition();
void polynomialMultiplication();
void polynomialMultiplicationByScalar();
void polynomialResultForVariable();
void polynomialComposition();

#endif

