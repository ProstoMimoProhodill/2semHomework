#include "polynomial.h"
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

struct Polynomial
{
    int n;
    struct Coefficient coefficient;
    struct Polynomial *next;
};

struct Coefficient *getData()
{
    struct Coefficient *result = (struct Coefficient *)malloc(sizeof(struct Coefficient));
    char data[100];
    printf("    Input integer or float:  ");
    scanf("%s",&data);

    type dataType = INT;
    for(int i=0;data[i]!='\0';i++)
    {
        if(data[i]=='.')
        {
            dataType = DOUBLE;
            break;
        }
    }

    if(dataType==DOUBLE)
    {
        result->coefficientType = DOUBLE;
        float a = atof(data);
        result->coefficientData = &a;
    }else if(dataType==INT){
        result->coefficientType = INT;
        int a = atoi(data);
        result->coefficientData = &a;
    }

    return result;
}

struct Polynomial *createPolynomial(int num)
{
    type currentType;
    struct Polynomial *head = NULL;
    for(int i=0;i<=num;i++)
    {
        struct Polynomial *link = (struct Polynomial *)malloc(sizeof(struct Polynomial));
        struct Coefficient *data = (struct Coefficient *)malloc(sizeof(struct Coefficient));
        struct Coefficient *savedata = (struct Coefficient *)malloc(sizeof(struct Coefficient));
        data = getData();

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


void showPolynomial(struct Polynomial *polynomial)
{
    struct Polynomial *current = NULL;
    current = polynomial;
    while (current != NULL) {
        if(current->coefficient.coefficientType == DOUBLE)
        {
            float a = *((float *)(current->coefficient.coefficientData));
            printf("    double n: %d, a: %f  \n", current->n, a);
        }else{
            int a = *((int *)(current->coefficient.coefficientData));
            printf("    int n: %d, a: %d  \n", current->n, a);
        }
        current = current->next;
    }
}


struct A *polynomialAdditionFunction(struct Polynomial *polynomial1, struct Polynomial *polynomial2, int p1Size, int p2Size)
{
    struct Polynomial *current1 = polynomial1;
    struct Polynomial *current2 = polynomial2;
    struct Polynomial *result = NULL;

    if(polynomial1->coefficient.coefficientType==polynomial2->coefficient.coefficientType){
        for(int i=min(p1Size, p2Size);i>=0;i--)
        {
            struct Polynomial *link = (struct Polynomial *)malloc(sizeof(struct Polynomial));
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
                    link = (struct Polynomial *)malloc(sizeof(struct Polynomial));
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
                    link = (struct Polynomial *)malloc(sizeof(struct Polynomial));
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
        }
    }else{
        for(int i=min(p1Size, p2Size);i>=0;i--)
        {
            struct Polynomial *link = (struct Polynomial *)malloc(sizeof(struct Polynomial));
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
                    link = (struct Polynomial *)malloc(sizeof(struct Polynomial));
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
                    link = (struct Polynomial *)malloc(sizeof(struct Polynomial));
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
        }
    }
    return result;
}

void polynomialMultiplication(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{

}

void polynomialMultiplicationByScalar(struct Polynomial *polynomial, void *scalar)
{

}

void polynomialResultForVariable(struct Polynomial *polynomial, void *X)
{

}

void polynomialComposition(struct Polynomial *polynomial1, struct Polynomial *polynomial2)
{

}

