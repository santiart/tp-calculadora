#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "menu.h"
//bibliotecas personales

int main()
{
    float num1=0;//primer operando
    float num2=0;//segundo operando
    int opcion;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorial;
    int resultadoFactorial2;
    int flagnumeros=0;//bandera para los numeros
    int flagcalculos=0;//bandera para los calculos
    int flag=0;//bandera para realizar los calculos

    do
    {
        printf("              :: C A L C U L A D O R A ::              \n");
        printf("\n\n");

        opcion=Opcion(num1,num2);
        switch(opcion)
        {
        case 1://ingreso del primer numero
            flagnumeros=1;
            fflush(stdin);
            printf("ingrese el primer numero: ");
            scanf("%f",&num1);
            break;
        case 2://ingreso del segundo numero

            flag=1;
            if(flagnumeros==1) //si no se ingresa un primer numero, impedimos el ingreso del segundo
            {
                fflush(stdin);
                printf("ingrese el segundo numero: ");
                scanf("%f",&num2);
                break;
            }
            else
            {
                printf("ERROR, primero ingrese la opcion 1...");
                break;
            }
        case 3://calculo de las operaciones
            flagcalculos=1;
            if(flag==1) //impedir la ejecucion de los calculos si no se ingresaron los dos operandos
            {
                resultadoSuma=obtenerSuma(num1,num2);
                resultadoResta=obtenerResta(num1,num2);
                resultadoMultiplicacion=obtenerMultiplicacion(num1,num2);
                resultadoFactorial2=obtenerFactorial(num2);
                resultadoDivision=obtenerDivision(num1,num2);
                resultadoFactorial=obtenerFactorial(num1);
            }
            else
            {
                printf("ERROR, ingrese primero los dos operandos...");
                break;
            }
            break;
        case 4://mostrar las respuestas de los calculos
            if(flagcalculos==1)//si no presiona la opcion 3, no se van a ejecutar ni se mostraran los calculos
            {
                printf("\n el resultado de la suma %.2f+%.2f es: %.2f",num1,num2,resultadoSuma);
                printf("\n el resultado de la resta %.2f-%.2f es: %.2f",num1,num2,resultadoResta);
                printf("\n el resultado de la multiplicacion %.2f*%.2f es: %.2f",num1,num2,resultadoMultiplicacion);
                if((num1>0)&&(num2>0))
                {
                    printf("\n el resultado factorial de %.0f es: %d ",num1,resultadoFactorial);
                    printf("\n y el resultado factorial de %.0f es: %d",num2,resultadoFactorial2);
                    break;
                }
                else
                {
                    printf("\n ERROR, no se puede factorizar un numero si este es 0 o menor a 0");
                }
                if(num2!=0)
                {
                    printf("\n el resultado de la division %.2f/%.2f es: %.2f",num1,num2,resultadoDivision);
                    break;
                }
                else
                {
                    printf("\n ERROR, no se puede realizar la division con divisor 0...");
                    //ningun calculo se mpostrara si el segundo operando es 0
                    break;
                }
            }
            else
            {
                printf("ERROR, primero elija la opcion 3...");
                break;
            }
            break;
        case 5://opcion de salida
            printf("\n pulse ENTER para salir... \n");

        }
        printf("\n");
        system("pause");
        system("cls");
        //limpiar la pantalla despues de ejecutar una opcion
    }
    while(opcion!=5); //ejecutar el programa hasta que se seleccione la opcion de salida (5)
    return 0;
}

