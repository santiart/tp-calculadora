#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
//bibliotecas personales

int main()
{
    int num1;//primer operando
    int num2;//segundo operando
    int opcion;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorial;
    int resultadoFactorial2;
    int flagnumeros=0;//bandera para los numeros
    int flagcalculos=0;//bandera para los calculos
    int flag=0;//bandera para realizar los calculos

    do{
    printf("              :: C A L C U L A D O R A ::              \n");
    printf("\n\n");
    printf("Elija una Opcion:                                      \n");
    printf(" 1_Ingresar primer numero     2_ingresar segundo numero\n");
    printf(" 3_realizar calculos          4_mostrar resultados     \n");
    printf(" 5_salir                                               \n");
    fflush(stdin);
    scanf("%d",&opcion);
    switch(opcion){
        case 1://ingreso del primer numero
            flagnumeros=1;
            fflush(stdin);
            printf("ingrese el primer numero: ");
            scanf("%d",&num1);
            break;
        case 2://ingreso del segundo numeroint obtenerSuma(int x, int y)
{
    int suma;
    suma=x+y;
    return suma;
}

            flag=1;
            if(flagnumeros==1){//si no se ingresa un primer numero, impedimos el ingreso del segundo
            fflush(stdin);
            printf("ingrese el segundo numero: ");
            scanf("%d",&num2);
            break;
            }
            else{
                printf("error, primero ingrese la opcion 1...");
                break;
            }
        case 3://calculo de las operaciones
            flagcalculos=1;
            if(flag==1){//impedir la ejecucion de los calculos si no se ingresaron los dos operandos
                if(num2!=0){
                resultadoSuma=obtenerSuma(num1,num2);
                resultadoResta=obtenerResta(num1,num2);
                resultadoMultiplicacion=obtenerMultiplicacion(num1,num2);
                resultadoDivision=obtenerDivision(num1,num2);
                resultadoFactorial=obtenerFactorial(num1);
                resultadoFactorial2=obtenerFactorial(num2);
                break;
                }
                else{
                printf("error, el segundo operando no puede ser 0");
                break;
                }
            break;
            }
            else{
                printf("error, ingrese primero los dos operandos...");
                break;
            }
            break;
        case 4://mostrar las respuestas de los calculos
            if(flagcalculos==1)//si no presiona la opcion 3, no se van a ejecutar ni se mostraran los calculos
            {
                printf("\n el resultado de la suma %d+%d es: %d",num1,num2,resultadoSuma);
                printf("\n el resultado de la resta %d-%d es: %d",num1,num2,resultadoResta);
                printf("\n el resultado de la multiplicacion %d*%d es: %d",num1,num2,resultadoMultiplicacion);
                printf("\n el resultado de la division %d/%d es: %.2f",num1,num2,resultadoDivision);
                printf("\n el resultado factorial de %d es: %d ",num1,resultadoFactorial);
                printf("y el resultado factorial de %d es: %d",num2,resultadoFactorial2);
                break;
            }
            else
            {
                printf("error, primero elija la opcion 3...");
                break;
            }
            break;
        case 5://opcion de salida
            printf("\n pulse ENTER para salir... \n");

    }
    printf("\n");
    system("pause");
    system("cls");
    //limpiar la pantalla despues de ejecutar una operacion
    }while(opcion!=5);//ejecutar el programa hasta que se seleccione la opcion de salida (5)
    return 0;
}
