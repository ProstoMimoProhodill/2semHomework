#ifndef POLYNOMIALLIST_H_
#define POLYNOMIALLIST_H_

struct Coefficient;
struct PolynomialList;

struct PolynomialList *createlistPolynomial(int num);
void showPolynomial(struct PolynomialList *polynomial);

struct PolynomialList *listPolynomialAdditionFunction(struct PolynomialList *polynomial1, struct PolynomialList *polynomial2, int p1Size, int p2Size);
struct PolynomialList *listPolynomialMultiplicationFunction(struct PolynomialList *polynomial1, struct PolynomialList *polynomial2, int p1Size, int p2Size);
struct PolynomialList *listPolynomialMultiplicationByScalarFunction(struct PolynomialList *polynomial, int psize, struct Coefficient *scalar);
struct Coefficient *listPolynomialResultForVariableFunction(struct PolynomialList *polynomial, int psize, struct Coefficient *X);
struct PolynomialList *listPolynomialCompositionFunction(struct PolynomialList *polynomial1, struct PolynomialList *polynomial2, int p1Size, int p2Size);

void listPolynomialAddition();
void listPolynomialMultiplication();
void listPolynomialMultiplicationByScalar();
void listPolynomialResultForVariable();
void listPolynomialComposition();

#endif

