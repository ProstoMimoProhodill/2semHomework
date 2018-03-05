#include "polynomialList.h"
#include "util.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Coefficient
{
    void *coefficientData;
    type coefficientType;
};

struct PolynomialList
{
    int n;
    struct Coefficient coefficient;
    struct PolynomialList *next;
};

struct PolynomialList *createlistPolynomial(int num)
{
    type currentType;
    struct PolynomialList *head = NULL;
    for(int i=0;i<=num;i++)
    {
        struct PolynomialList *link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
        struct Coefficient *data = (struct Coefficient *)malloc(sizeof(struct Coefficient));
        struct Coefficient *savedata = (struct Coefficient *)malloc(sizeof(struct Coefficient));

        struct Coefficient *result = (struct Coefficient *)malloc(sizeof(struct Coefficient));
        char datastr[100];
        printf("        Input integer or float:  ");
        scanf("%s",&datastr);

        type dataType = INT;
        for(int i=0;datastr[i]!='\0';i++)
        {
            if(datastr[i]=='.')
            {
                dataType = DOUBLE;
                break;
            }
        }

        if(dataType==DOUBLE)
        {
            result->coefficientType = DOUBLE;
            float a = atof(datastr);
            result->coefficientData = &a;
        }else if(dataType==INT){
            result->coefficientType = INT;
            int a = atoi(datastr);
            result->coefficientData = &a;
        }

        data = result;

        if(i==0){
            if(data->coefficientType == DOUBLE){
                currentType = DOUBLE;
            }else{
                currentType = INT;
            }
        }else{
            if(data->coefficientType != currentType){
                printf("    Error: You can input only one type...try again\n");
                system("pause");
                return;
            }
        }

        void *ptr;
		if(data->coefficientType == DOUBLE){
            currentType = DOUBLE;
            float a = *((float *)(data->coefficientData));
			ptr = &a;
        }else{
            currentType = INT;
            int a = *((int *)(data->coefficientData));
			ptr = &a;
        }

        (savedata->coefficientData) = ptr;

        link->n = i;
        link->coefficient.coefficientData = malloc(sizeof(data->coefficientType));
        memcpy((link->coefficient.coefficientData), (savedata->coefficientData), sizeof(struct Coefficient));
        link->coefficient.coefficientType = data->coefficientType;
        link->next = head;
        head = link;

        free(data);
        free(savedata);
    }
    return head;
}


void showPolynomial(struct PolynomialList *polynomial)
{
    struct PolynomialList *current = NULL;
    current = polynomial;
    while (current != NULL) {
        if(current->coefficient.coefficientType == DOUBLE)
        {
            float a = *((float *)(current->coefficient.coefficientData));
            printf("        double n: %d, a: %f  \n", current->n, a);
        }else{
            int a = *((int *)(current->coefficient.coefficientData));
            printf("        int n: %d, a: %d  \n", current->n, a);
        }
        current = current->next;
    }
}


struct PolynomialList *listPolynomialAdditionFunction(struct PolynomialList *polynomial1, struct PolynomialList *polynomial2, int p1Size, int p2Size)
{
    struct PolynomialList *current1 = polynomial1;
    struct PolynomialList *current2 = polynomial2;
    struct PolynomialList *result = NULL;

    if(polynomial1->coefficient.coefficientType==polynomial2->coefficient.coefficientType){
        for(int i=min(p1Size, p2Size);i>=0;i--)
        {
            struct PolynomialList *link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
            struct Coefficient *savedata = (struct Coefficient *)malloc(sizeof(struct Coefficient));

            if((p1Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr1 = current1->coefficient.coefficientData;
                    if(current1->coefficient.coefficientType==DOUBLE){
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr1;
                        link->coefficient.coefficientType = DOUBLE;
                    }else{
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr1;
                        link->coefficient.coefficientType = INT;
                    }
                    current1 = current1->next;
                    link->next = result;
                    result = link;
                    link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
                }
            }else if((p2Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr2 = current2->coefficient.coefficientData;
                    if(current2->coefficient.coefficientType==DOUBLE){
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr2;
                        link->coefficient.coefficientType = DOUBLE;
                    }else{
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr2;
                        link->coefficient.coefficientType = INT;
                    }
                    current2 = current2->next;
                    link->next = result;
                    result = link;
                    link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
                }
            }

            void *ptr1 = current1->coefficient.coefficientData;
            void *ptr2 = current2->coefficient.coefficientData;

            void *data;

            if((current1->coefficient.coefficientType == DOUBLE)&&(current2->coefficient.coefficientType == DOUBLE)){
                float a = ((*((float *)ptr1)) + (*((float *)ptr2)));
                data = &a;
                link->n = i;
                link->coefficient.coefficientType = DOUBLE;
            }else if((current1->coefficient.coefficientType == INT)&&(current2->coefficient.coefficientType == INT)){
                int a = ((*((int *)ptr1)) + (*((int *)ptr2)));
                data = &a;
                link->n = i;
                link->coefficient.coefficientType = INT;
            }

            (savedata->coefficientData) = data;
            link->coefficient.coefficientData = malloc(sizeof(struct Coefficient));
            memcpy((link->coefficient.coefficientData), (savedata->coefficientData), sizeof(struct Coefficient));

            current1 = current1->next;
            current2 = current2->next;

            link->next = result;
            result = link;

            free(savedata);
        }
    }else{
        for(int i=min(p1Size, p2Size);i>=0;i--)
        {
            struct PolynomialList *link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
            struct Coefficient *savedata = (struct Coefficient *)malloc(sizeof(struct Coefficient));

            if((p1Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr1 = current1->coefficient.coefficientData;
                    if(current1->coefficient.coefficientType==DOUBLE){
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr1;
                        link->coefficient.coefficientType = DOUBLE;
                    }else{
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr1;
                        link->coefficient.coefficientType = INT;
                    }
                    current1 = current1->next;
                    link->next = result;
                    result = link;
                    link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
                }
            }else if((p2Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr2 = current2->coefficient.coefficientData;
                    if(current2->coefficient.coefficientType==DOUBLE){
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr2;
                        link->coefficient.coefficientType = DOUBLE;
                    }else{
                        link->n = max(p1Size, p2Size)-d;
                        link->coefficient.coefficientData = ptr2;
                        link->coefficient.coefficientType = INT;
                    }
                    current2 = current2->next;
                    link->next = result;
                    result = link;
                    link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
                }
            }

            void *ptr1 = current1->coefficient.coefficientData;
            void *ptr2 = current2->coefficient.coefficientData;
            void *data;

            float p1,p2;

            if(current1->coefficient.coefficientType==INT){
                p1 = (float)(*((int *)ptr1));
                p2 = (*((float *)ptr2));

                float a = p1 + p2;
                data = &a;
                link->n = i;
                link->coefficient.coefficientType = DOUBLE;
            }else if(current2->coefficient.coefficientType==INT){
                p1 = (*((float *)ptr1));
                p2 = (float)(*((int *)ptr2));

                float a = p1 + p2;
                data = &a;
                link->n = i;
                link->coefficient.coefficientType = DOUBLE;
            }

            (savedata->coefficientData) = data;
            link->coefficient.coefficientData = malloc(sizeof(struct Coefficient));
            memcpy((link->coefficient.coefficientData), (savedata->coefficientData), sizeof(struct Coefficient));

            current1 = current1->next;
            current2 = current2->next;

            link->next = result;
            result = link;

            free(savedata);
        }
    }
    return result;
}

struct PolynomialList *listPolynomialMultiplicationFunction(struct PolynomialList *polynomial1, struct PolynomialList *polynomial2, int p1Size, int p2Size)
{
    struct PolynomialList *result = NULL;
    return result;
}

struct PolynomialList *listPolynomialMultiplicationByScalarFunction(struct PolynomialList *polynomial, int psize, struct Coefficient *scalar)
{
    struct PolynomialList *result = NULL;
    struct PolynomialList *current = polynomial;

    for(int i=0;i<=psize;i++)
    {
        struct PolynomialList *link = (struct PolynomialList *)malloc(sizeof(struct PolynomialList));
        struct Coefficient *savedata = (struct Coefficient *)malloc(sizeof(struct Coefficient));

        void *ptr;
		if(scalar->coefficientType == DOUBLE){
            if(current->coefficient.coefficientType == DOUBLE){
                float a = *((float *)(current->coefficient.coefficientData));
                float s = *((float *)(scalar->coefficientData));
                link->coefficient.coefficientType = DOUBLE;
                float res = a*s;
                ptr = &res;
            }else{
                float a = (float)(*((int *)(current->coefficient.coefficientData)));
                float s = *((float *)(scalar->coefficientData));
                link->coefficient.coefficientType = DOUBLE;
                float res = a*s;
                ptr = &res;
            }
        }else{
            if(current->coefficient.coefficientType == DOUBLE){
                float a = *((float *)(current->coefficient.coefficientData));
                float s = (float)(*((int *)(scalar->coefficientData)));
                link->coefficient.coefficientType = DOUBLE;
                float res = a*s;
                ptr = &res;
            }else{
                int a = (*((int *)(current->coefficient.coefficientData)));
                int s = (*((int *)(scalar->coefficientData)));
                link->coefficient.coefficientType = INT;
                int res = a*s;
                ptr = &res;
            }
        }

        (savedata->coefficientData) = ptr;

        link->n = current->n;
        link->coefficient.coefficientData = malloc(sizeof(scalar->coefficientType));
        memcpy((link->coefficient.coefficientData), (savedata->coefficientData), sizeof(struct Coefficient));
        link->next = result;
        result = link;

        current = current->next;
        free(savedata);
    }
    return result;
}

struct Coefficient *listPolynomialResultForVariableFunction(struct PolynomialList *polynomial, int psize, struct Coefficient *X)
{
    struct Coefficient *result;
    struct PolynomialList *current = polynomial;
    return result;
}

struct PolynomialList *listPolynomialCompositionFunction(struct PolynomialList *polynomial1, struct PolynomialList *polynomial2, int p1Size, int p2Size)
{
    struct PolynomialList *result = NULL;
    return result;
}

void listPolynomialAddition()
{
    int p1Size = 0, p2Size = 0;
    printf("    Input size of P1(x) (from 0) : ");
    scanf("%d",&p1Size);
    struct PolynomialList *polynomial1 = createlistPolynomial(p1Size);
    printf("    Input size of P2(x) (from 0) : ");
    scanf("%d",&p2Size);
    struct PolynomialList *polynomial2 = createlistPolynomial(p2Size);
    printf("\n");
    struct PolynomialList *result = listPolynomialAdditionFunction(polynomial1, polynomial2, p1Size, p2Size);

    printf("    P1(x) : \n");
    showPolynomial(polynomial1);
    printf("\n    P2(x) : \n");
    showPolynomial(polynomial2);
    printf("\n    P1(x)+P2(x) : \n");
    showPolynomial(result);
}


void listPolynomialMultiplication()
{

}

void listPolynomialMultiplicationByScalar()
{
    int pSize = 0;
    printf("    Input size of P(x) (from 0) : ");
    scanf("%d",&pSize);
    struct PolynomialList *polynomial = createlistPolynomial(pSize);
    printf("    Input value of scalar : \n");

    struct Coefficient *resultData = (struct Coefficient *)malloc(sizeof(struct Coefficient));
    char datastr[100];
    printf("        Input integer or float:  ");
    scanf("%s",&datastr);

    type dataType = INT;
    for(int i=0;datastr[i]!='\0';i++)
    {
        if(datastr[i]=='.')
        {
            dataType = DOUBLE;
            break;
        }
    }

    if(dataType==DOUBLE)
    {
        resultData->coefficientType = DOUBLE;
        float a = atof(datastr);
        resultData->coefficientData = &a;
    }else if(dataType==INT){
        resultData->coefficientType = INT;
        int a = atoi(datastr);
        resultData->coefficientData = &a;
    }

    struct Coefficient *scalar =  resultData;
    struct PolynomialList *result = listPolynomialMultiplicationByScalarFunction(polynomial, pSize, scalar);

    printf("    P(x) : \n");
    showPolynomial(polynomial);
    printf("\n    A*P(x) : \n");
    showPolynomial(result);
}

void listPolynomialResultForVariable()
{
    int pSize = 0;
    printf("    Input size of P(x) (from 0) : ");
    scanf("%d",&pSize);
    struct PolynomialList *polynomial = createlistPolynomial(pSize);
    printf("    Input X : \n");

    struct Coefficient *resultData = (struct Coefficient *)malloc(sizeof(struct Coefficient));
    char datastr[100];
    printf("        Input integer or float:  ");
    scanf("%s",&datastr);

    type dataType = INT;
    for(int i=0;datastr[i]!='\0';i++)
    {
        if(datastr[i]=='.')
        {
            dataType = DOUBLE;
            break;
        }
    }

    if(dataType==DOUBLE)
    {
        resultData->coefficientType = DOUBLE;
        float a = atof(datastr);
        resultData->coefficientData = &a;
    }else if(dataType==INT){
        resultData->coefficientType = INT;
        int a = atoi(datastr);
        resultData->coefficientData = &a;
    }

    struct Coefficient *X =  resultData;
    struct Coefficient *result = listPolynomialResultForVariableFunction(polynomial, pSize, X);

    printf("    P(x) : \n");
    showPolynomial(polynomial);
    printf("\n    P(x) for X : \n");
    showPolynomial(result);
}


void listPolynomialComposition()
{

}
