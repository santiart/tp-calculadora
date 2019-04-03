#include <stdio.h>
#include <stdlib.h>

float obtenerDivision(int x, int y)
{
    float resta;
    if(y!=0)
    {
        resta=(float)x/y;

    }
    else{
        printf("no se puede dividir por 0 \n" );
    }
        return resta;
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


int obtenerMultiplicacion(int x, int y)
{
    int multiplicacion;
    multiplicacion=x*y;
    return multiplicacion;
}


int obtenerResta(int x, int y)
{
    int resta;
    resta=x-y;
    return resta;
}

int obtenerSuma(int x, int y)
{
    int suma;
    suma=x+y;
    return suma;
}
