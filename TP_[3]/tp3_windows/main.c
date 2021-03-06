#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Biblioteca.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
#define CANTIDAD_EMPLEADOS 1000
int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int bandera=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
		puts("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
		puts("3. Alta de empleado");
		puts("4. Modificar datos de empleado");
		puts("5. Baja de empleado");
		puts("6. Listar empleados");
		puts("7. Ordenar empleados");
		puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
		puts("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
		puts("10. Salir");
    	utn_getNumeroInt (&option, "Ingrese una opcion:\n", "Error, opcion invalidad\n", 1, 10, 2);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0)
                {
                	printf("se cargaron los datos\n");
                	bandera=1;
                }
                else
                {
                	puts("No hay datos que guardados");
                }
                break;
            case 2:
            	if(controller_loadFromBinary("data.bin", listaEmpleados)==0)
            	{
            		puts("Se cargo en binario");
            		bandera=1;
            	}
            	else
            	{
            		puts("Error, No hay datos que guardar");
            	}
            	break;
            case 3:
            	//alta de empleados
            	if(controller_addEmployee(listaEmpleados)==0)
            	{
            		puts("Se cargo correctamente el empleado");
            	}
            	else
            	{
            		puts("No se pudo carfar el empleado");
            	}
            	break;
            case 4:
            	if(controller_editEmployee(listaEmpleados)==0)
            	{
            		puts("Se modifico correctamente");
            	}
            	else
            	{
            		puts("No se pudo modificar");
            	}
            	break;
            case 5:
            	if(controller_removeEmployee(listaEmpleados)==0)
            	{
            		puts("Se elimino correctamente el empleado");
            	}
            	else
            	{
            		puts("No se pudo eliminar");
            	}
            	break;
            case 6:
            	if(controller_ListEmployee(listaEmpleados)==0)
            	{
            		puts("Se listo correctamente");
            	}
            	else{
            		puts("No hay nada que listar");
            	}
            	break;
            case 7:
            	if(controller_sortEmployee(listaEmpleados)==0)
            	{
            		puts("Se ordeno correctamente");
            	}
            	else
            	{
            		puts("No hay nada que ordenar");
            	}
            	break;
            case 8:
            	if(controller_saveAsText("data.csv", listaEmpleados)==0)
            	{
            		puts("salio guardar en text bien");
            	}
            	else
            	{
            		puts("No se pudo guardar");
            	}
            	break;
            case 9:
            	if(controller_saveAsBinary("data.bin",listaEmpleados)==0)
            	{
            		puts("Salio guardar en binario todo bien");
            	}
            	else
            	{
            		puts("Algo salio mal guardar binario");
            	}
            	break;
            case 10:
            	puts("Salir");
            	break;
        }
    }while(option != 10);
    return 0;
}

