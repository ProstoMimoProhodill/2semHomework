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
    struct Polynomial *guess = guessPolynomial(result->n);

    printf("\n    P1(x)+P2(x) : \n");
    outputPolynomial(result);

    for(int i=0;i<=result->n;i++){
        if(result->dataType==INT){
            if(*(int *)get(guess, i)== *(int *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }else if(result->dataType==DOUBLE){
            if(*(float *)get(guess, i)== *(float *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }
    }

    free(polynomial1);
    free(polynomial2);
    free(result);
}

void testInputPolynomialComposition()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();
    struct Polynomial *result = polynomialCompositionFunction(polynomial1, polynomial2);
    struct Polynomial *guess = guessPolynomial(result->n);

    printf("\n    P1(P2(x)) : \n");
    outputPolynomial(result);

    for(int i=0;i<=result->n;i++){
        if(result->dataType==INT){
            if(*(int *)get(guess, i)== *(int *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }else if(result->dataType==DOUBLE){
            if(*(float *)get(guess, i)== *(float *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }
    }

    free(polynomial1);
    free(polynomial2);
    free(result);
}

void testInputPolynomialMultiplication()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();
    struct Polynomial *result = polynomialMultiplicationFunction(polynomial1, polynomial2);
    struct Polynomial *guess = guessPolynomial(result->n);

    printf("\n    P1(x)*P2(x) : \n");
    outputPolynomial(result);

    for(int i=0;i<=result->n;i++){
        if(result->dataType==INT){
            if(*(int *)get(guess, i)== *(int *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }else if(result->dataType==DOUBLE){
            if(*(float *)get(guess, i)== *(float *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }
    }

    free(polynomial1);
    free(polynomial2);
    free(result);
}

void testInputPolynomialMultiplicationByScalar()
{
    struct Polynomial *polynomial = createPolynomial();
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
    struct Polynomial *guess = guessPolynomial(result->n);

    printf("\n    A*P(x) :\n");
    outputPolynomial(result);

    for(int i=0;i<=result->n;i++){
        if(result->dataType==INT){
            if(*(int *)get(guess, i)== *(int *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }else if(result->dataType==DOUBLE){
            if(*(float *)get(guess, i)== *(float *)get(result, i)){
                printf("        Status[%d] - Ok\n",i);
            }else{
                printf("        Status[%d] - Failed\n",i);
            }
        }
    }

    free(polynomial);
    free(scalar);
    free(result);
}


void testInputPolynomialResultForVariable()
{
    struct Polynomial *polynomial = createPolynomial();
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

    struct Scalar *result = polynomialResultForVariableFunction(polynomial, X);

    void *guess;
    printf("\n    Guess polynomial : ");
    if(result->scalarType==INT){
        scanf("%d", guess);
    }else if(result->scalarType==DOUBLE){
        scanf("%f", guess);
    }

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

    if(result->scalarType==INT){
        if(*(int *)guess == *(int *)result->scalarData){
                printf("    Status - Ok\n");
            }else{
                printf("    Status - Failed\n");
            }
    }else if(result->scalarType==DOUBLE){
        if(*(float *)guess == *(float *)result->scalarData){
                printf("    Status - Ok\n");
            }else{
                printf("    Status - Failed\n");
            }
    }

    free(polynomial);
    free(X);
    free(result);
}






void testRandomPolynomialAddition()
{

}

void testRandomPolynomialComposition()
{

}

void testRandomPolynomialMultiplication()
{

}

void testRandomPolynomialMultiplicationByScalar()
{

}

void testRandomPolynomialResultForVariable()
{

}
