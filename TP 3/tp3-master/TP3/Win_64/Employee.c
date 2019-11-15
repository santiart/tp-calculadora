#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Employee.h"
#include "biblioAgus.h"


Employee* employee_new()
{
    Employee* retornarEmploye;

    retornarEmploye=(Employee*) calloc(sizeof(Employee),1);

    return retornarEmploye;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* retornarEmpleado=employee_new();

    employee_setId(retornarEmpleado,atoi(idStr));
    employee_setNombre(retornarEmpleado,nombreStr);///falta validacion
    employee_setHorasTrabajadas(retornarEmpleado,atoi(horasTrabajadasStr));
    employee_setSueldo(retornarEmpleado,atoi(sueldo));


        return retornarEmpleado;

  /// /*falta validacion*/


}

int employee_setId(Employee* this,int id)
{
    int retorno=1;

    if(id>=0)
    {
        this->id=id;
    }
    else
    {
        retorno=0;
    }
    return retorno;



}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=1;

    strcpy(this->nombre,nombre);



    return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=1;

    if(horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
    }
    else
    {
        retorno=0;
    }
    return retorno;

}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=1;

    if(sueldo>=0)
    {
        this->sueldo=sueldo;
    }
    else
    {
        retorno=0;
    }
    return retorno;

}

int employee_getNombre(Employee* this,char* nombre)
{
    getString("Ingrese el nombre del nuevo empleado : ",nombre,1,50);

    strcpy(this->nombre,nombre);

    return 1;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
     getInt("Ingrese las horas trabajadas del nuevo empleado : ",horasTrabajadas,1,400000000);

     this->horasTrabajadas=*horasTrabajadas;



     return 1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
     getInt("Ingrese el sueldo del nuevo empleado : ",sueldo,1,4000000000000);

     this->sueldo=*sueldo;

     return 1;
}

int employee_getId(Employee* this,int* id)
{
    this->id=(*id+1);

    return 1;
}
