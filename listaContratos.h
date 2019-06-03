#ifndef _listaContratos
#define _listaContratos
#include "listaTareas.h"

const string fileContratos = "contratos.txt";

typedef struct {
	string nombre;
	string nif;
	double sueldo;
	tListaTareas lista;
} tContrato;
typedef tContrato *tPtrContrato;
const int MAX_C = 100;
typedef struct {
	tPtrContrato contrato[MAX_C];
	int cont;
}tListaContratos;

void cargarContratos(tListaContratos &lista, tPrioridades &prioridades, bool &ok);
void  insertarContratos(tListaContratos &lista, int i, tContrato &contrato);
void mostrarContratos(const tListaContratos &lista);
void seleccionarContratos(tListaContratos &lista); // lo hice dirrectamente en 'insertarEmpleado'
void liberar(tListaContratos &lista);

#endif // _listaContratos
