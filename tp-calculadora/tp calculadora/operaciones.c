#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

float obtenerDivision(float x, float y)//funcion de division
{
    float division;
    if(y!=0)//impedimos que la persona ponga como divisor 0
    {
        division=(float)x/y;

    }
    else{
        printf("no se puede dividir por 0 \n" );
    }
        return division;
}


int obtenerFactorial(int x)//funcion de factoreo
{
    //igualamos i y resultadof para que no se contemple un 0 como numero a factorear
    int i;
    int resultadof=1;
    for(i=1;i<=x;i++)
    {
        resultadof=resultadof*i;
    }

    return resultadof;
}


float obtenerMultiplicacion(float x, float y)//funcion de multiplicacion
{
    float multiplicacion;
    multiplicacion=(float)x*y;
    return multiplicacion;
}


float obtenerResta(float x, float y)//funcion de resta
{
    float resta;
    resta=(float)x-y;
    return resta;
}

float obtenerSuma(float x, float y)//funcion de suma
{
    float suma;
    suma=(float)x+y;
    return suma;
}
