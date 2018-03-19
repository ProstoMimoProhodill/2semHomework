#include "util.h"
#include "tests.h"
#include "interface.h"
#include "polynomialList.h"
#include "polynomialDynamicArray.h"

#include <stdio.h>
#include <stdlib.h>

struct Polynomial
{
    void *data;
    type dataType;
    int n;
};

struct Scalar
{
    void *scalarData;
    type scalarType;
};

void testInputPolynomialAddition()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();
    struct Polynomial *result = polynomialAdditionFunction(polynomial1, polynomial2);

    printf("\n    P1(x) : \n");
    outputPolynomial(polynomial1);
    printf("\n    P2(x) : \n");
    outputPolynomial(polynomial2);
    printf("\n    P1(x)+P2(x) : \n");
    outputPolynomial(result);

    free(polynomial1);
    free(polynomial2);
    free(result);
}


void testInputPolynomialComposition()
{

}


void testInputPolynomialMultiplication()
{

}


void testInputPolynomialMultiplicationByScalar()
{

}


void testInputPolynomialResultForVariable()
{

}


void testRandomPolynomialAddition()
{
    struct Polynomial *polynomial1 = createRandomPolynomial();
    struct Polynomial *polynomial2 = createRandomPolynomial();
    struct Polynomial *result = polynomialAdditionFunction(polynomial1, polynomial2);

    printf("\n    P1(x) : \n");
    outputPolynomial(polynomial1);
    printf("\n    P2(x) : \n");
    outputPolynomial(polynomial2);
    printf("\n    P1(x)+P2(x) : \n");
    outputPolynomial(result);

    free(polynomial1);
    free(polynomial2);
    free(result);
}


void testRandomPolynomialComposition()
{
    struct Polynomial *polynomial1 = createRandomPolynomial();
    struct Polynomial *polynomial2 = createRandomPolynomial();
    struct Polynomial *result = polynomialCompositionFunction(polynomial1, polynomial2);

    printf("\n    P1(x) : \n");
    outputPolynomial(polynomial1);
    printf("\n    P2(x) : \n");
    outputPolynomial(polynomial2);
    printf("\n    P1(P2(x)) : \n");
    outputPolynomial(result);

    free(polynomial1);
    free(polynomial2);
    free(result);
}


void testRandomPolynomialMultiplication()
{
    struct Polynomial *polynomial1 = createRandomPolynomial();
    struct Polynomial *polynomial2 = createRandomPolynomial();
    struct Polynomial *result = polynomialMultiplicationFunction(polynomial1, polynomial2);

    printf("\n    P1(x) : \n");
    outputPolynomial(polynomial1);
    printf("\n    P2(x) : \n");
    outputPolynomial(polynomial2);
    printf("\n    P1(x)*P2(x) : \n");
    outputPolynomial(result);

    free(polynomial1);
    free(polynomial2);
    free(result);
}


void testRandomPolynomialMultiplicationByScalar()
{
    struct Polynomial *polynomial = createRandomPolynomial();
    struct Scalar *scalar = (struct Scalar *)malloc(sizeof(struct Scalar));

    printf("    Input value of scalar : ");
    char datastr[100];
    scanf("%s",&datastr);
    type dataType = INT;
    for(int i=0;datastr[i]!='\0';i++){
        if(datastr[i]=='.'){
            dataType = DOUBLE;
            break;
        }
    }

    if(dataType==INT){
        scalar->scalarType = INT;
        int p = atoi(datastr);
        scalar->scalarData = malloc(sizeof(int));
        memcpy(scalar->scalarData, &p, sizeof(int));
    }else if(dataType==DOUBLE){
        scalar->scalarType = DOUBLE;
        float p = atof(datastr);
        scalar->scalarData = malloc(sizeof(float));
        memcpy(scalar->scalarData, &p, sizeof(float));
    }

    struct Polynomial *result = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    result = polynomialMultiplicationByScalarFunction(polynomial, scalar);

    printf("\n    A*P(x) :\n");
    outputPolynomial(result);

    free(polynomial);
    free(scalar);
    free(result);
}


void testRandomPolynomialResultForVariable()
{
    struct Polynomial *polynomial = createRandomPolynomial();
    struct Scalar *X = (struct Scalar *)malloc(sizeof(struct Scalar));

    printf("    Input value of X : ");
    char datastr[100];
    scanf("%s",&datastr);
    type dataType = INT;
    for(int i=0;datastr[i]!='\0';i++){
        if(datastr[i]=='.'){
            dataType = DOUBLE;
            break;
        }
    }

    if(dataType==INT){
        X->scalarType = INT;
        int p = atoi(datastr);
        X->scalarData = malloc(sizeof(int));
        memcpy(X->scalarData, &p, sizeof(int));
    }else if(dataType==DOUBLE){
        X->scalarType = DOUBLE;
        float p = atof(datastr);
        X->scalarData = malloc(sizeof(float));
        memcpy(X->scalarData, &p, sizeof(float));
    }

    struct Scalar *result = (struct Scalar *)malloc(sizeof(struct Scalar));
    result = polynomialResultForVariableFunction(polynomial, X);

    if(X->scalarType==INT){
        printf("\n    P( %d ) = ",*(int *)X->scalarData);
    }else if(X->scalarType==DOUBLE){
        printf("\n    P( %f ) = ",*(float *)X->scalarData);
    }

    if(result->scalarType==INT){
        printf("%d\n",*(int *)result->scalarData);
    }else if(result->scalarType==DOUBLE){
        printf("%f\n",*(float *)result->scalarData);
    }

    free(polynomial);
    free(X);
    free(result);
}


void testLogPolynomialAddition()
{
    for(int i=0;i<=2;i++){
       printf("/menu/Tests/P1(x)+P2(x)/Random/test %d/\n",i);
       struct Polynomial *polynomial1 = createRandomPolynomial();
       struct Polynomial *polynomial2 = createRandomPolynomial();

       struct Polynomial *result = polynomialAdditionFunction(polynomial1, polynomial2);

       free(polynomial1);
       free(polynomial2);
       free(result);
    }

}


void testLogPolynomialComposition()
{
    for(int i=0;i<=10;i++){
        printf("/menu/Tests/P1(P2(x)) /Random/test %d/\n",i);
    }

}


void testLogPolynomialMultiplication()
{
    for(int i=0;i<=10;i++){
        printf("/menu/Tests/P1(x)*P2(x) /Random/test %d/\n",i);
    }

}


void testLogPolynomialMultiplicationByScalar()
{
    for(int i=0;i<=10;i++){
        printf("/menu/Tests/P(x)*a /Random/test %d/\n",i);
    }

}


void testLogPolynomialResultForVariable()
{
    for(int i=0;i<=10;i++){
       printf("/menu/Tests/P(x) = /Random/test %d/\n",i);
    }

}
