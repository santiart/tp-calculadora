#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "biblioAgus.h"
#include "parser.h"
#define ECANT 1000



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* ARCHIVO;
    int tam;

    ARCHIVO=fopen(path,"r");

    if(ARCHIVO==NULL)
    {
        printf("no se a podido abrir el archivo");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("archivo abierto existosamente ");

        tam=parser_EmployeeFromText(ARCHIVO,pArrayListEmployee);

        //controller_ListEmployee(pArrayListEmployee);



        printf("\n\nSe han cargado %d empleados\n",tam);

        fclose(ARCHIVO);

    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    fopen(path,"r");


    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* unEmpleado= employee_new();
    Employee* auxEmpleado= employee_new();

    char* nombre=(char* ) malloc(sizeof(char)*50);
    int horasTrabajadas;
    int sueldo;
    int i;
    int tam;
    int idMax=0;


    ///employee_getId(unEmpleado,&id);  //comparar id con i en un for si i<id falta ese i
    tam=ll_len(pArrayListEmployee);

    for(i=0;i<tam;i++)
    {
        auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

        if(auxEmpleado->id>idMax)
        {
            idMax=auxEmpleado->id;
        }
    }

    printf("Empleado n:%d\n",(idMax+1));
    employee_getId(unEmpleado,&idMax);
    employee_getNombre(unEmpleado,nombre);
    employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);
    employee_getSueldo(unEmpleado,&sueldo);

    ll_add(pArrayListEmployee,unEmpleado);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int id;
    int i;
    int flag=0;
    int tam=ll_len(pArrayListEmployee);
    char* nombre=(char* ) malloc(sizeof(char)*50);
    int horasTrabajadas;
    int sueldo;
    Employee* unEmpleado = employee_new();

    getInt("Ingrese el id del empleado que desea modificar :",&id,1,tam);

    for(i=0;i<tam;i++)
    {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

        if(unEmpleado->id==id)
        {
            unEmpleado=ll_pop(pArrayListEmployee,i);
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
         system("cls");
        printf("Empleado encontrado exitosamente\n\n");

        do
        {
             printf("id---nombre---horas trabajadas----sueldo\n");

             mostrarEmpleado(unEmpleado);

            getInt("1. Nombre\
                   \n2. Horas trabajadas\
                   \n3.Sueldo\
                   \n4.Salir\n\n",&opcion,1,4);

                   switch(opcion)
                   {
                        case 1:
                            employee_getNombre(unEmpleado,nombre);
                            break;
                        case 2:
                            employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);
                            break;
                        case 3:
                            employee_getSueldo(unEmpleado,&sueldo);
                            break;
                   }

                   system("pause");
                   system("cls");
        }while(opcion!=4);

        ll_push(pArrayListEmployee,i,unEmpleado);
    }
    else
    {
        printf("id de empleado inexistente\n");
    }


}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char opcion[5]={" "};
    int id;
    int i;
    int flag=0;
    int tam=ll_len(pArrayListEmployee);
    Employee* unEmpleado = employee_new();

    getInt("Ingrese el id del empleado que desea eliminar :",&id,1,tam);

    for(i=0;i<tam;i++)
    {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

        if(unEmpleado->id==id)
        {
            unEmpleado=ll_get(pArrayListEmployee,i);
            flag=1;
            break;
        }
    }

    if(flag)
    {
        printf("\n\nid---nombre---horas trabajadas----sueldo\n");
        mostrarEmpleado(unEmpleado);

        while((strcmp(opcion,"si")) && (strcmp(opcion,"no")))
        {
            getString("\nDesea eliminar este empleado (ingrese si o no)?\n\n",opcion,2,2);
        }

        if(strcmp(opcion,"si")==0)
        {
            ll_remove(pArrayListEmployee,i);

            printf("\nEmpleado eliminado exitosamente\n");

        }
    }

    system("pause");
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len = ll_len(pArrayListEmployee);
    int i;



    printf("id---nombre---horas trabajadas----sueldo\n");
    for(i = 0; i < len; i++)
    {
        Employee* aux = (Employee*)ll_get(pArrayListEmployee, i);

        mostrarEmpleado(aux);

       // printf("%d%10s%8d%20d\n\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    }
}

void mostrarEmpleado(Employee* unEmpleado)
{
    printf("%d%10s%8d%20d\n\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->horasTrabajadas, unEmpleado->sueldo);
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    FILE* ARCHIVO;
    int i;
    int tam;
    Employee* unEmpleado;
    ARCHIVO=fopen(path,"w");
    if(ARCHIVO==NULL)
    {
        printf("Error.no se a podido abrir el archivo");
        exit(EXIT_FAILURE);
    }
    else
    {
        tam=ll_len(pArrayListEmployee);
        for(i=0;i<tam;i++)
        {
           unEmpleado=employee_new();
           unEmpleado=ll_get(pArrayListEmployee,i);

           fprintf(ARCHIVO,"%d,%s,%d,%d\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->horasTrabajadas,unEmpleado->sueldo);
        }
        fclose(ARCHIVO);
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* ARCHIVO;
    Employee* unEmpleado=employee_new();

    ARCHIVO=fopen(path,"wb");

    if(ARCHIVO==NULL)
    {
        printf("no se a podido guardar el archivo");
    }
    else
    {
        while(!feof(ARCHIVO))
        {
           // fwrite()
        }

    }

    return 1;
}



