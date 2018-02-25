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

struct Polynomial *createList(int num)
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


void showList(struct Polynomial *polynomial)
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


void polynomialAddition()
{
    int p1Size = 0, p2Size = 0;
    printf("    Input size of P1(x) (from 0) : ");
    scanf("%d",&p1Size);
    struct Polynomial *polynomial1 = createList(p1Size);
    printf("    Input size of P2(x) (from 0) : ");
    scanf("%d",&p2Size);
    struct Polynomial *polynomial2 = createList(p2Size);
    printf("\n");

    struct Polynomial *current1 = polynomial1;
    struct Polynomial *current2 = polynomial2;


    printf("    P1(x) : \n");
    showList(polynomial1);
    printf("\n    P2(x) : \n");
    showList(polynomial2);
    printf("\n");


    if(polynomial1->coefficient.coefficientType==polynomial2->coefficient.coefficientType){
        for(int i=min(p1Size, p2Size);i>=0;i--)
        {

            if((p1Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr1 = current1->coefficient.coefficientData;
                    if(current1->coefficient.coefficientType==DOUBLE){
                        printf("    double n: %d, a: %f  \n", max(p1Size, p2Size)-d, (*((float *)ptr1)) );
                    }else{
                        printf("    int n: %d, a: %d  \n", max(p1Size, p2Size)-d, (*((int *)ptr1)) );
                    }
                    current1 = current1->next;
                }
            }else if((p2Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr2 = current2->coefficient.coefficientData;
                    if(current2->coefficient.coefficientType==DOUBLE){
                        printf("    double n: %d, a: %f  \n", max(p1Size, p2Size)-d, (*((float *)ptr2)) );
                    }else{
                        printf("    int n: %d, a: %d  \n", max(p1Size, p2Size)-d, (*((int *)ptr2)) );
                    }
                    current2 = current2->next;
                }
            }

            void *ptr1 = current1->coefficient.coefficientData;
            void *ptr2 = current2->coefficient.coefficientData;

            if((current1->coefficient.coefficientType == DOUBLE)&&(current2->coefficient.coefficientType == DOUBLE)){
                printf("    double n: %d, a: %f  \n", i, (*((float *)ptr1)) + (*((float *)ptr2)) );
            }else if((current1->coefficient.coefficientType == INT)&&(current2->coefficient.coefficientType == INT)){
                printf("    int n: %d, a: %d  \n", i, (*((int *)ptr1)) + (*((int *)ptr2)) );
            }

            current1 = current1->next;
            current2 = current2->next;
        }
    }else{
        for(int i=min(p1Size, p2Size);i>=0;i--)
        {

            if((p1Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr1 = current1->coefficient.coefficientData;
                    if(current1->coefficient.coefficientType==DOUBLE){
                        printf("    double n: %d, a: %f  \n", max(p1Size, p2Size)-d, (*((float *)ptr1)) );
                    }else{
                        printf("    int n: %d, a: %d  \n", max(p1Size, p2Size)-d, (*((int *)ptr1)) );
                    }
                    current1 = current1->next;
                }
            }else if((p2Size==max(p1Size, p2Size)&&(i==min(p1Size, p2Size)))){
                for(int d=0;d<(max(p1Size, p2Size)-min(p1Size, p2Size));d++){
                    void *ptr2 = current2->coefficient.coefficientData;
                    if(current2->coefficient.coefficientType==DOUBLE){
                        printf("    double n: %d, a: %f  \n", max(p1Size, p2Size)-d, (*((float *)ptr2)) );
                    }else{
                        printf("    int n: %d, a: %d  \n", max(p1Size, p2Size)-d, (*((int *)ptr2)) );
                    }
                    current2 = current2->next;
                }
            }

            void *ptr1 = current1->coefficient.coefficientData;
            void *ptr2 = current2->coefficient.coefficientData;

            float p1,p2;

            if(current1->coefficient.coefficientType==INT){
                p1 = (float)(*((int *)ptr1));
                p2 = (*((float *)ptr2));
            }else if(current2->coefficient.coefficientType==INT){
                p1 = (*((float *)ptr1));
                p2 = (float)(*((float *)ptr2));
            }

            printf("    double n: %d, a: %f  \n", i, p1 + p2 );

            current1 = current1->next;
            current2 = current2->next;
        }
    }
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

