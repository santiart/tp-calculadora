#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int i=0;
    char id[500];
    char nombre[500];
    char horasTrabajadas[500];
    char sueldo[500];
    int n=0;


    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    while(!feof(pFile))
    {
        Employee* unEmpleado=employee_new();
        if(unEmpleado!=NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

            unEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);///puede que falten validaciones

            ll_add(pArrayListEmployee,(Employee*)unEmpleado);
            n++;
        }
        else
        {
            printf("no se a podido asignar memoria para el empleado n%d",n);
            break;
        }

    }
    return n;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
