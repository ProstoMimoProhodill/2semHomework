#include "util.h"
#include <math.h>
#include "polynomialDynamicArray.h"

#include <string.h>
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

struct Polynomial *createPolynomial()
{
    struct Polynomial *polynomial=malloc(sizeof(struct Polynomial));
    int currType=0, n=0;
    printf("    Input size of P(x) (from 0) : ");
    scanf("%d", &n);
    printf("    Input type (0-int, 1-float) : ");
    scanf("%d", &currType);
    polynomial->n = n;
    (currType==0)?(polynomial->dataType=INT):(polynomial->dataType=DOUBLE);

    polynomial->data = NULL;
    if(polynomial->dataType==INT){
        for(int i=0;i<=polynomial->n;i++){
            int element;
            printf("        Input int : ");
            scanf("%d", &element);
            polynomial = pushElementInDynamicArray(polynomial, &element);
        }
    }else if(polynomial->dataType==DOUBLE){
        for(int i=0;i<=polynomial->n;i++){
            float element;
            printf("        Input float : ");
            scanf("%f", &element);
            polynomial = pushElementInDynamicArray(polynomial, &element);
        }
    }
    return polynomial;
}


struct Polynomial *pushElementInDynamicArray(struct Polynomial *dynamicArray, void *element)
{
    int i;
    struct Polynomial *result;

    if(dynamicArray->dataType==INT){
        (_msize(dynamicArray->data)==-1)?(i=0):(i = (_msize(dynamicArray->data))/(sizeof(int)) );

        if(i>0){
            dynamicArray->data = realloc(dynamicArray->data, (i+1)*sizeof(int));
        }

        result = (struct Polynomial *)malloc( _msize(dynamicArray) + sizeof(int) );
        result->data = realloc(dynamicArray->data, (i+1)*sizeof(int));
        int *p = (int *)realloc(dynamicArray->data, (i+1)*sizeof(int));
        *(p+i) = *(int *)element;
        memcpy(result->data, (void *)p, (i+1)*sizeof(int));
    }else if(dynamicArray->dataType==DOUBLE){
        (_msize(dynamicArray->data)==-1)?(i=0):(i = (_msize(dynamicArray->data))/(sizeof(float)) );

        if(i>0){
            dynamicArray->data = realloc(dynamicArray->data, (i+1)*sizeof(float));
        }

        result = (struct Polynomial *)malloc( _msize(dynamicArray) + sizeof(float) );
        result->data = realloc(dynamicArray->data, (i+1)*sizeof(float));
        float *p = (float *)realloc(dynamicArray->data, (i+1)*sizeof(float));
        *(p+i) = *(float *)element;
        memcpy(result->data, (void *)p, (i+1)*sizeof(float));
    }

    result->dataType = dynamicArray->dataType;
    result->n = dynamicArray->n;
    return result;
}

void *getElementFromDynamicArray(struct Polynomial *dynamicArray, int i)
{
    void *result;
    if(dynamicArray->dataType==INT){
        int *p = (int *)dynamicArray->data;
        result = (int *)(p+i);
    }else if(dynamicArray->dataType==DOUBLE){
        float *p = (float *)dynamicArray->data;
        result = (float *)(p+i);
    }
    return result;
}

void outputPolynomial(struct Polynomial *polynomial)
{
    if(polynomial->dataType==INT){
        int *p = (int *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            printf("        int n: %d, a: %d  \n",i,*(int *)(p+i));
        }
    }else{
        float *p = (float *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            printf("        double n: %d, a: %f  \n",i,*(float *)(p+i));
        }
    }
}

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{
    struct Polynomial *result = malloc(sizeof(polynomial1) + sizeof(polynomial2));

    /*
    int n = max(polynomial1->n, polynomial2->n);
    result->n = malloc(sizeof(int));
    result->n = n;

    if((polynomial1->dataType==INT)&&(polynomial2->dataType==INT)){
        result->dataType = INT;
    }else if((polynomial1->dataType==DOUBLE)||(polynomial2->dataType==DOUBLE)){
        result->dataType = DOUBLE;
    }

    for(int i=0;i<=max(polynomial1->n, polynomial2->n);i++)
    {
        if(polynomial1->n!=polynomial2->n){
            for(int d=0;d<max(polynomial1->n, polynomial2->n)-min(polynomial1->n, polynomial2->n);d++){
                if()
            }
        }



    }

    system("pause");

    */
    return result;
}

struct Polynomial *polynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{

}


struct Polynomial *polynomialMultiplicationByScalarFunction(struct Polynomial *polynomial, struct Scalar *scalar)
{
    struct Polynomial *result = malloc(_msize(polynomial));
    result->data = NULL;
    result->n = polynomial->n;
    result->dataType = polynomial->dataType;

    for(int i=0;i<=polynomial->n;i++){
        void *data;
        if(polynomial->dataType==INT){
            if(scalar->scalarType==INT){
                int p = (*(int *)scalar->scalarData)*(*(int *)getElementFromDynamicArray(polynomial, i));
                data = &p;
            }else if(scalar->scalarType==DOUBLE){
                result->dataType = DOUBLE;
                float p = (*(float *)scalar->scalarData)*(*(int *)getElementFromDynamicArray(polynomial, i));
                data = &p;
            }
        }else if(polynomial->dataType==DOUBLE){
            if(scalar->scalarType==INT){
                float p = (*(int *)scalar->scalarData)*(*(float *)getElementFromDynamicArray(polynomial, i));
                data = &p;
            }else if(scalar->scalarType==DOUBLE){
                float p = (*(float *)scalar->scalarData)*(*(float *)getElementFromDynamicArray(polynomial, i));
                data = &p;
            }
        }
        result = pushElementInDynamicArray(result, data);
    }
    return result;
}


struct Scalar *polynomialResultForVariableFunction(struct Polynomial *polynomial, struct Scalar *X)
{

}


struct Polynomial *polynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size)
{

}


void polynomialAddition()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();

    printf("pol1\n");
    outputPolynomial(polynomial1);
    printf("pol2\n");
    outputPolynomial(polynomial2);

    struct Polynomial *result = polynomialAdditionFunction(polynomial1, polynomial2);
    outputPolynomial(result);
}


void polynomialMultiplication()
{

}


void polynomialMultiplicationByScalar()
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
    printf("\n    P(x) :\n");
    outputPolynomial(polynomial);
    printf("\n    A*P(x) :\n");
    outputPolynomial(result);
}


void polynomialResultForVariable()
{

}


void polynomialComposition()
{

}

