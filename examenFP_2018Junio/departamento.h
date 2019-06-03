#ifndef _departamento
#define _departamento
#include"listaContratos.h"

const int MAX_EMPLEADOS = 50;
typedef struct {
	int num;
	tPtrContrato ptrContrato;
} tEmpleado;

typedef tEmpleado *tPtrEmpleado;

typedef struct {
	string id;
	int cont;
	tPtrEmpleado *empleados;
}tDepartamento;

/*.Dado un identificador, devuelve un departamento vacío.*/
void inicializar(tDepartamento &dep, const string id);

/*.Libera la memoria dinámica utilizada con un departamento*/
void liberar(tDepartamento &dep);

/*.Busca un empleado en un departamento usando el nif.Devuelve
- 1 si no lo encuentra.*/
int buscarEmpleado(tDepartamento &dep, string nif);

/*.Se inserta un empleado nuevo con respecto a un contrato que
se selecciona mostrando al usuario la lista de contratos.El empleado no se inserta si
ya existe su nif en el departamento.En ese caso no se hace nada. La inserción se
realiza al final del departamento.*/
void  insertarEmpleado(const tListaContratos &lista, tDepartamento &dep, bool &ok);

/*.Dado un empleado muestra sus datos en una línea según el
formato dado.*/
void mostrarEmpleado(tEmpleado empleado);

/*.Muestra toda la información de un departamento
siguiendo el formato dado.Debe implementarse utilizando una función recursiva.*/
void mostrarDepartamento(const tDepartamento &DEP, int i);


#endif // !_departamento

