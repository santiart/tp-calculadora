#include <stdio.h>
#include <stdlib.h>

float obtenerDivision(float x, float y)
{
    float division;
    if(y!=0)
    {
        division=(float)x/y;

    }
    else{
        printf("no se puede dividir por 0 \n" );
    }
        return division;
}


int obtenerFactorial(int x)
{
    int i;
    int resultadof=1;
    for(i=1;i<=x;i++)
    {
        resultadof=resultadof*i;
    }

    return resultadof;
}


float obtenerMultiplicacion(float x, float y)
{
    float multiplicacion;
    multiplicacion=(float)x*y;
    return multiplicacion;
}


float obtenerResta(float x, float y)
{
    float resta;
    resta=(float)x-y;
    return resta;
}

float obtenerSuma(float x, float y)
{
    float suma;
    suma=(float)x+y;
    return suma;
}
