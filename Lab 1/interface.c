#include "interface.h"
#include "polynomialList.h"
#include "polynomialDynamicArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void test()
{
    polynomialMultiplication();
}

void menu(int startTo)
{
    int again  = 1;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    void undefined()
    {
        SetConsoleTextAttribute(hConsole, 79);
        printf("Error: Undefined command \nTry again...\n");
        SetConsoleTextAttribute(hConsole, 8);
        system("pause");
        system("cls");
        again = 1;
    }

    while(again)
    {
        again = 0;
        int a = 0;

        if(startTo==0)
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 12);
            printf("/menu/\n");
            SetConsoleTextAttribute(hConsole, 8);
            printf(">1 P1(x)+P2(x) \n");
            printf(">2 P1(x)*P2(x) \n");
            printf(">3 P1(P2(x))   \n");
            printf(">4 P(x)*a      \n");
            printf(">5 P(x) =      \n");
            printf(">6 Tests       \n");
            printf(">7 Exit        \n");
            scanf("%d",&a);
        }else{
            a = startTo;
        }

        switch (a)
        {
            case 1:
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("/menu/P1(x)+P2(x)/\n");
                SetConsoleTextAttribute(hConsole, 8);
                printf(">1 Dynamic array    \n");
                printf(">2 List             \n");
                printf(">3 Back             \n");
                scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/P1(x)+P2(x)/Dynamic array/ \n");
                        SetConsoleTextAttribute(hConsole, 8);
                        polynomialAddition();
                        system("pause");
                        menu(0);
                        break;
                    case 2:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/P1(x)+P2(x)/List/  \n");
                        SetConsoleTextAttribute(hConsole, 8);
                        listPolynomialAddition();
                        system("pause");
                        menu(0);
                        break;
                    case 3:
                        menu(0);
                        break;
                    default:
                        undefined();
                        break;
                }
                break;
            case 2:
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("/menu/P1(x)*P2(x)/\n");
                SetConsoleTextAttribute(hConsole, 8);
                printf(">1 Dynamic array    \n");
                printf(">2 Back             \n");
                scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/P1(x)*P2(x)/Dynamic array/ \n");
                        SetConsoleTextAttribute(hConsole, 8);
                        polynomialMultiplication();
                        system("pause");
                        menu(0);
                        break;
                    case 2:
                        menu(0);
                        break;
                    default:
                        undefined();
                        break;
                }
                break;
            case 3:
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("/menu/P1(P2(x))/\n");
                SetConsoleTextAttribute(hConsole, 8);
                printf(">1 Dynamic array    \n");
                printf(">2 Back             \n");
                scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/P1(P2(x))/Dynamic array/ \n");
                        SetConsoleTextAttribute(hConsole, 8);
                        polynomialMultiplication();
                        system("pause");
                        menu(0);
                        break;
                    case 2:
                        menu(0);
                        break;
                    default:
                        undefined();
                        break;
                }
                break;
            case 4:
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("/menu/P(x)*a/\n");
                SetConsoleTextAttribute(hConsole, 8);
                printf(">1 Dynamic array    \n");
                printf(">2 List             \n");
                printf(">3 Back             \n");
                scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/P(x)*a/Dynamic array/ \n");
                        SetConsoleTextAttribute(hConsole, 8);
                        polynomialMultiplicationByScalar();
                        system("pause");
                        menu(0);
                        break;
                    case 2:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/P(x)*a/List/  \n");
                        SetConsoleTextAttribute(hConsole, 8);
                        listPolynomialMultiplicationByScalar();
                        system("pause");
                        menu(0);
                        break;
                    case 3:
                        menu(0);
                        break;
                    default:
                        undefined();
                        break;
                }
                break;
            case 5:
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("/menu/P(x) = /\n");
                SetConsoleTextAttribute(hConsole, 8);
                printf(">1 Dynamic array    \n");
                printf(">2 Back             \n");
                scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/P(x) = /Dynamic array/ \n");
                        SetConsoleTextAttribute(hConsole, 8);
                        polynomialResultForVariable();
                        system("pause");
                        menu(0);
                        break;
                    case 2:
                        menu(0);
                        break;
                    default:
                        undefined();
                        break;
                }
                break;
            case 6:
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("/menu/Tests/\n");
                SetConsoleTextAttribute(hConsole, 8);
                printf(">1 P1(x)+P2(x)      \n");
                printf(">2 P1(x)*P2(x)      \n");
                printf(">3 P(x)*a           \n");
                printf(">4 P(x) =           \n");
                printf(">5 Back             \n");
                scanf("%d",&a);
                switch (a)
                {
                    case 1:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("/menu/Tests/P1(x)+P2(x)/\n");
                        SetConsoleTextAttribute(hConsole, 8);
                        printf(">1 Input  \n");
                        printf(">2 Random \n");
                        printf(">3 Back   \n");
                        scanf("%d",&a);
                        switch (a)
                        {
                            case 1:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P1(x)+P2(x)/Input/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 2:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P1(x)+P2(x)/Random/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 3:
                                menu(5);
                                break;
                            default:
                                undefined();
                                break;
                        }
                        break;
                    case 2:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf(">/menu/Tests/P1(x)*P2(x)/\n");
                        SetConsoleTextAttribute(hConsole, 8);
                        printf(">1 Input \n");
                        printf(">2 Random \n");
                        printf(">3 Back   \n");
                        scanf("%d",&a);
                        switch (a)
                        {
                            case 1:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P1(x)*P2(x)/Input/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 2:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P1(x)*P2(x)/Random/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 3:
                                menu(5);
                                break;
                            default:
                                undefined();
                                break;
                        }
                        break;
                    case 3:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf(">/menu/Tests/P(x)*a/\n");
                        SetConsoleTextAttribute(hConsole, 8);
                        printf(">1 Input \n");
                        printf(">2 Random \n");
                        printf(">3 Back   \n");
                        scanf("%d",&a);
                        switch (a)
                        {
                            case 1:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P(x)*a/Input/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 2:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P(x)*a/Random/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 3:
                                menu(5);
                                break;
                            default:
                                undefined();
                                break;
                        }
                        break;
                    case 4:
                        system("cls");
                        SetConsoleTextAttribute(hConsole, 12);
                        printf(">/menu/Tests/P(x) = /\n");
                        SetConsoleTextAttribute(hConsole, 8);
                        printf(">1 Input \n");
                        printf(">2 Random \n");
                        printf(">3 Back   \n");
                        scanf("%d",&a);
                        switch (a)
                        {
                            case 1:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P(x) = /Input/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 2:
                                system("cls");
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("/menu/Tests/P(x) = /Random/\n");
                                SetConsoleTextAttribute(hConsole, 8);
                                system("pause");
                                menu(0);
                                break;
                            case 3:
                                menu(5);
                                break;
                            default:
                                undefined();
                                break;
                        }
                        break;
                    case 5:
                        menu(0);
                        break;
                    default:
                        undefined();
                        break;
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                undefined();
                break;
        }
    }
}
