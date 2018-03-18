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

    polynomial->n = n;
    polynomial->data = NULL;

    char datastr[100];
    printf("         Input integer or float : ");
    scanf("%s",&datastr);
    type dataType = INT;
    for(int i=0;datastr[i]!='\0';i++){
        if(datastr[i]=='.'){
            dataType = DOUBLE;
            break;
        }
    }

    if(dataType==INT){
        polynomial->dataType=INT;
        int element = atoi(datastr);
        polynomial = pushElementInDynamicArray(polynomial, &element);
    }else if(dataType==DOUBLE){
        polynomial->dataType=DOUBLE;
        float element = atof(datastr);
        polynomial = pushElementInDynamicArray(polynomial, &element);
    }

    if(polynomial->dataType==INT){
        for(int i=1;i<=polynomial->n;i++){
            int element;
            printf("                      Input int : ");
            scanf("%d", &element);
            polynomial = pushElementInDynamicArray(polynomial, &element);
        }
    }else if(polynomial->dataType==DOUBLE){
        for(int i=1;i<=polynomial->n;i++){
            float element;
            printf("                    Input float : ");
            scanf("%f", &element);
            polynomial = pushElementInDynamicArray(polynomial, &element);
        }
    }
    return polynomial;
}


struct Polynomial *pushElementInDynamicArray(struct Polynomial *polynomial, void *element)
{
    int i;
    struct Polynomial *result;

    if(polynomial->dataType==INT){
        (_msize(polynomial->data)==-1)?(i=0):(i = (_msize(polynomial->data))/(sizeof(int)) );

        if(i>0){
            polynomial->data = realloc(polynomial->data, (i+1)*sizeof(int));
        }

        result = (struct Polynomial *)malloc( _msize(polynomial) + sizeof(int) );
        result->data = realloc(polynomial->data, (i+1)*sizeof(int));
        int *p = (int *)realloc(polynomial->data, (i+1)*sizeof(int));
        *(p+i) = *(int *)element;
        memcpy(result->data, (void *)p, (i+1)*sizeof(int));
    }else if(polynomial->dataType==DOUBLE){
        (_msize(polynomial->data)==-1)?(i=0):(i = (_msize(polynomial->data))/(sizeof(float)) );

        if(i>0){
            polynomial->data = realloc(polynomial->data, (i+1)*sizeof(float));
        }

        result = (struct Polynomial *)malloc( _msize(polynomial) + sizeof(float) );
        result->data = realloc(polynomial->data, (i+1)*sizeof(float));
        float *p = (float *)realloc(polynomial->data, (i+1)*sizeof(float));
        *(p+i) = *(float *)element;
        memcpy(result->data, (void *)p, (i+1)*sizeof(float));
    }

    result->dataType = polynomial->dataType;
    result->n = polynomial->n;
    return result;
}


struct Polynomial *changeElementInDynamicArray(struct Polynomial *polynomial, int i, void *element)
{
    struct Polynomial *result = (struct Polynomial *)malloc(_msize(polynomial));
    if(polynomial->dataType==INT){
        result->data = realloc(polynomial->data, _msize(polynomial->data));
        int *p = (int *)realloc(polynomial->data, _msize(polynomial->data));
        *(p+i) = *(int *)element;
        memcpy(result->data, (void *)p, _msize(polynomial->data));
    }else if(polynomial->dataType==DOUBLE){
        result->data = realloc(polynomial->data, _msize(polynomial->data));
        float *p = (float *)realloc(polynomial->data, _msize(polynomial->data));
        *(p+i) = *(float *)element;
        memcpy(result->data, (void *)p, _msize(polynomial->data));
    }
    result->dataType = polynomial->dataType;
    result->n = polynomial->n;
    return result;
}


void *getElementFromDynamicArray(struct Polynomial *polynomial, int i)
{
    void *result;
    if(polynomial->dataType==INT){
        int *p = (int *)polynomial->data;
        result = (int *)(p+i);
    }else if(polynomial->dataType==DOUBLE){
        float *p = (float *)polynomial->data;
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

void graphicalOutputPolynomial(struct Polynomial *polynomial)
{
    if(polynomial->dataType==INT){
        int *p = (int *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            if(i==0){
                printf("        = %d",*(int *)(p+i));
            }else{
                if(i%3==0){
                    if(*(int *)(p+i)==0){
                        printf(" + \n        + 0");
                    }else if(*(int *)(p+i)>0){
                        printf(" + \n        + %dX^%d", *(int *)(p+i),i);
                    }else if(*(int *)(p+i)<0){
                        printf(" - \n        - %dX^%d", abs(*(int *)(p+i)),i);
                    }
                }else{
                    if(*(int *)(p+i)==0){
                        printf(" + 0");
                    }else if(*(int *)(p+i)>0){
                        printf(" + %dX^%d", *(int *)(p+i),i);
                    }else if(*(int *)(p+i)<0){
                        printf(" - %dX^%d", abs(*(int *)(p+i)),i);
                    }
                }
            }
        }
    }else{
        float *p = (float *)polynomial->data;
        for(int i=0;i<=polynomial->n;i++){
            if(i==0){
                printf("        = %f",*(float *)(p+i));
            }else{
                if(i%3==0){
                    if(*(float *)(p+i)==0){
                        printf(" + \n        + 0");
                    }else if(*(float *)(p+i)>0){
                        printf(" + \n        + %fX^%d", *(float *)(p+i),i);
                    }else if(*(float *)(p+i)<0){
                        printf(" + \n        + (%f)X^%d", *(float *)(p+i),i);
                    }
                }else{
                    if(*(float *)(p+i)==0){
                        printf(" + 0");
                    }else if(*(float *)(p+i)>0){
                        printf(" + %fX^%d", *(float *)(p+i),i);
                    }else if(*(float *)(p+i)<0){
                        printf(" + (%f)X^%d", *(float *)(p+i),i);
                    }
                }
            }
        }
    }

    printf("\n\n");
}

struct Polynomial *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{
    struct Polynomial *result;
    if(max(polynomial1->n, polynomial2->n)==polynomial1->n){
        result = (struct Polynomial *)malloc(_msize(polynomial1));
    }else if(max(polynomial1->n, polynomial2->n)==polynomial2->n){
        result = (struct Polynomial *)malloc(_msize(polynomial2));
    }

    result->n = max(polynomial1->n, polynomial2->n);
    result->data = NULL;

    for(int i=0;i<=min(polynomial1->n, polynomial2->n);i++)
    {
        if(polynomial1->dataType==INT){
            if(polynomial2->dataType==INT){
                result->dataType=INT;
                int p = (*(int *)getElementFromDynamicArray(polynomial1,i)) + (*(int *)getElementFromDynamicArray(polynomial2,i));
                result = pushElementInDynamicArray(result, &p);
            }else if(polynomial2->dataType==DOUBLE){
                result->dataType=DOUBLE;
                float p = (*(int *)getElementFromDynamicArray(polynomial1,i)) + (*(float *)getElementFromDynamicArray(polynomial2,i));
                result = pushElementInDynamicArray(result, &p);
            }
        }else if(polynomial1->dataType==DOUBLE){
            if(polynomial2->dataType==INT){
                result->dataType=DOUBLE;
                float p = (*(float *)getElementFromDynamicArray(polynomial1,i)) + (*(int *)getElementFromDynamicArray(polynomial2,i));
                result = pushElementInDynamicArray(result, &p);
            }else if(polynomial2->dataType==DOUBLE){
                result->dataType=DOUBLE;
                float p = (*(float *)getElementFromDynamicArray(polynomial1,i)) + (*(float *)getElementFromDynamicArray(polynomial2,i));
                result = pushElementInDynamicArray(result, &p);
            }
        }
    }

    for(int i=min(polynomial1->n, polynomial2->n)+1;i<=max(polynomial1->n, polynomial2->n);i++)
    {
        if(polynomial1->dataType==INT){
            if(polynomial2->dataType==INT){
                result->dataType=INT;
                int p;
                if(max(polynomial1->n, polynomial2->n)==polynomial1->n){
                    p = (*(int *)getElementFromDynamicArray(polynomial1,i));
                }else if(max(polynomial1->n, polynomial2->n)==polynomial2->n){
                    p = (*(int *)getElementFromDynamicArray(polynomial2,i));
                }
                result = pushElementInDynamicArray(result, &p);
            }else if(polynomial2->dataType==DOUBLE){
                result->dataType=DOUBLE;
                float p;
                if(max(polynomial1->n, polynomial2->n)==polynomial1->n){
                    p = (float)(*(int *)getElementFromDynamicArray(polynomial1,i));
                }else if(max(polynomial1->n, polynomial2->n)==polynomial2->n){
                    p = (*(float *)getElementFromDynamicArray(polynomial2,i));
                }
                result = pushElementInDynamicArray(result, &p);
            }
        }else if(polynomial1->dataType==DOUBLE){
            if(polynomial2->dataType==INT){
                result->dataType=DOUBLE;
                float p;
                if(max(polynomial1->n, polynomial2->n)==polynomial1->n){
                    p = (*(float *)getElementFromDynamicArray(polynomial1,i));
                }else if(max(polynomial1->n, polynomial2->n)==polynomial2->n){
                    p = (float)(*(int *)getElementFromDynamicArray(polynomial2,i));
                }
                result = pushElementInDynamicArray(result, &p);
            }else if(polynomial2->dataType==DOUBLE){
                result->dataType=DOUBLE;
                float p;
                if(max(polynomial1->n, polynomial2->n)==polynomial1->n){
                    p = (*(float*)getElementFromDynamicArray(polynomial1,i));
                }else if(max(polynomial1->n, polynomial2->n)==polynomial2->n){
                    p = (*(float *)getElementFromDynamicArray(polynomial2,i));
                }
                result = pushElementInDynamicArray(result, &p);
            }
        }
    }
    return result;
}

struct Polynomial *polynomialMultiplicationFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{
    struct Polynomial *result;

    if(polynomial1->dataType==INT){
        if(polynomial2->dataType==INT){
            result = malloc((polynomial1->n + polynomial2->n)*sizeof(int));
            result->dataType = INT;
        }else if(polynomial2->dataType==DOUBLE){
            result = malloc((polynomial1->n + polynomial2->n)*sizeof(float));
            result->dataType = DOUBLE;
        }
    }else if(polynomial1->dataType==DOUBLE){
        if(polynomial2->dataType==INT){
            result = malloc((polynomial1->n + polynomial2->n)*sizeof(float));
            result->dataType = DOUBLE;
        }else if(polynomial2->dataType==DOUBLE){
            result = malloc((polynomial1->n + polynomial2->n)*sizeof(float));
            result->dataType = DOUBLE;
        }
    }

    result->n = (polynomial1->n + polynomial2->n);
    result->data = NULL;

    for(int i=0;i<=result->n;i++){
        int k = 0;
        result = pushElementInDynamicArray(result, &k);
    }

    for(int i=0;i<=polynomial1->n;i++){
        for(int j=0;j<=polynomial2->n;j++){
            if(polynomial1->dataType==INT){
                if(polynomial2->dataType==INT){
                    int a = *(int *)getElementFromDynamicArray(polynomial1, i);
                    int b = *(int *)getElementFromDynamicArray(polynomial2, j);
                    int c = *(int *)getElementFromDynamicArray(result, i+j) + (a*b);
                    result = changeElementInDynamicArray(result, i+j , &c);
                }else if(polynomial2->dataType==DOUBLE){
                    int a = *(int *)getElementFromDynamicArray(polynomial1, i);
                    float b = *(float *)getElementFromDynamicArray(polynomial2, j);
                    float c = *(float *)getElementFromDynamicArray(result, i+j) + (a*b);
                    result = changeElementInDynamicArray(result, i+j , &c);
                }
            }else if(polynomial1->dataType==DOUBLE){
                if(polynomial2->dataType==INT){
                    float a = *(float *)getElementFromDynamicArray(polynomial1, i);
                    int b = *(int *)getElementFromDynamicArray(polynomial2, j);
                    float c = *(float *)getElementFromDynamicArray(result, i+j) + (a*b);
                    result = changeElementInDynamicArray(result, i+j , &c);
                }else if(polynomial2->dataType==DOUBLE){
                    float a = *(float *)getElementFromDynamicArray(polynomial1, i);
                    float b = *(float *)getElementFromDynamicArray(polynomial2, j);
                    float c = *(float *)getElementFromDynamicArray(result, i+j) + (a*b);
                    result = changeElementInDynamicArray(result, i+j , &c);
                }
            }
        }
    }
    return result;
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
    struct Scalar *result = (struct Scalar *)malloc(sizeof(struct Scalar));

    int k = 0;
    void *data = &k;

    for(int i=0;i<=polynomial->n;i++){
        if(polynomial->dataType==INT){
            if(X->scalarType==INT){
                result->scalarType = INT;

                int p = *(int *)data + ((*(int *)getElementFromDynamicArray(polynomial, i))*pow(*(int *)X->scalarData, i));
                data = malloc(sizeof(int));
                memcpy(data, &p, sizeof(int));

            }else if(X->scalarType==DOUBLE){
                result->scalarType = DOUBLE;

                float p = *(float *)data + ((*(int *)getElementFromDynamicArray(polynomial, i))*pow(*(float *)X->scalarData, i));
                data = malloc(sizeof(float));
                memcpy(data, &p, sizeof(float));
            }
        }else if(polynomial->dataType==DOUBLE){
            if(X->scalarType==INT){
                result->scalarType = DOUBLE;

                float p = *(float *)data + ((*(float *)getElementFromDynamicArray(polynomial, i))*pow(*(int *)X->scalarData, i));
                data = malloc(sizeof(float));
                memcpy(data, &p, sizeof(float));
            }else if(X->scalarType==DOUBLE){
                result->scalarType = DOUBLE;

                float p = *(float *)data + ((*(float *)getElementFromDynamicArray(polynomial, i))*pow(*(float *)X->scalarData, i));
                data = malloc(sizeof(float));
                memcpy(data, &p, sizeof(float));
            }
        }
    }

    if(result->scalarType==INT){
        result->scalarData = malloc(sizeof(int));
        memcpy(result->scalarData, data, sizeof(int));
    }else if(result->scalarType==DOUBLE){
        result->scalarData = malloc(sizeof(float));
        memcpy(result->scalarData, data, sizeof(float));
    }
    return result;
}


struct Polynomial *polynomialCompositionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{
    struct Polynomial *polynomialToPower(struct Polynomial *polynomial, int k)
    {
        struct Polynomial *result;
        return result;
    }

    struct Polynomial *result;
    return result;
}


void polynomialAddition()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();
    struct Polynomial *result = polynomialAdditionFunction(polynomial1, polynomial2);

    printf("\n    P1(x)+P2(x) : \n");
    graphicalOutputPolynomial(result);

    free(polynomial1);
    free(polynomial2);
    free(result);
}


void polynomialMultiplication()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();
    struct Polynomial *result = polynomialMultiplicationFunction(polynomial1, polynomial2);

    printf("\n    P1(x)*P2(x) : \n");
    graphicalOutputPolynomial(result);

    free(polynomial1);
    free(polynomial2);
    free(result);
}


void polynomialComposition()
{
    struct Polynomial *polynomial1 = createPolynomial();
    struct Polynomial *polynomial2 = createPolynomial();
    struct Polynomial *result = polynomialCompositionFunction(polynomial1, polynomial2);

    printf("\n    P1(P2(x)) : \n");
    graphicalOutputPolynomial(result);

    free(polynomial1);
    free(polynomial2);
    free(result);
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

    printf("\n    A*P(x) :\n");
    graphicalOutputPolynomial(result);

    free(polynomial);
    free(scalar);
    free(result);
}


void polynomialResultForVariable()
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
