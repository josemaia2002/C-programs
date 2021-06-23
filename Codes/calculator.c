/*
calculator.c
---------------------------------------------------------------------------------------------------
   author: José Maia da Silva Neto
   e-mail : maianeto2014@gmail.com
---------------------------------------------------------------------------------------------------
    This is a simple calculator that asks the user to enter the operation and the operands
*/


#include <stdio.h>
#include <stdlib.h>

float multiplication(float, float);
float division(float, float);
float addition(float, float);
float subtraction(float, float);

int main()
{
    float a, b, result;
    char operation;

    printf("Choose an operation and define the operands\n");
    scanf("%s%f%f", &operation, &a, &b);


    switch(operation)
    {
    case 'm':
        {
        result = multiplication(a, b);
        printf("%f", result);
        break;
        }
    case 'd':
        {
        result = division(a, b);
        printf("%f", result);
        break;
        }
    case 'a':
        {
        result = addition(a, b);
        printf("%f", result);
        break;
        }
    case 's':
        {
        result = subtraction
        (a, b);
        printf("%f", result);
        break;
        }
    default:
        printf("\n ERROR");
    }
    return 0;
}


float multiplication(float x, float y)
{
    return(x*y);
}

float division(float x, float y)
{
    return(x/y);
}

float addition(float x, float y)
{
    return(x+y);
}

float subtraction(float x, float y)
{
    return(x-y);
}
