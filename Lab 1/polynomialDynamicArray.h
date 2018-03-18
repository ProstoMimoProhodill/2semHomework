#ifndef POLYNOMIALDYNAMICARRAY_H_
#define POLYNOMIALDYNAMICARRAY_H_

struct Polynomial;
struct Scalar;

struct Polynomial *createPolynomial();
struct Polynomial *pushElementInDynamicArray(struct Polynomial *polynomial, void *element);
struct Polynomial *changeElementInDynamicArray(struct Polynomial *polynomial, int i, void *element);
void *getElementFromDynamicArray(struct Polynomial *polynomial, int i);
void graphicalOutputPolynomial(struct Polynomial *polynomial);
void outputPolynomial(struct Polynomial *polynomial);

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
struct Polynomial *polynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
struct Polynomial *polynomialMultiplicationByScalarFunction(struct Polynomial *polynomial, struct Scalar *scalar);
struct Polynomial *polynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2);
struct Scalar *polynomialResultForVariableFunction(struct Polynomial *polynomial, struct Scalar *X);

void polynomialAddition();
void polynomialMultiplication();
void polynomialMultiplicationByScalar();
void polynomialResultForVariable();
void polynomialComposition();

#endif

