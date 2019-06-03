#ifndef _listaTareas
#define _listaTareas
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
#define log 1


const string filePrioridades = "prioridades.txt";

const int MAX_TAREA = 15;

typedef struct {
	int tabla[MAX_TAREA][MAX_TAREA];
	int x;
	int y;
} tPrioridades;

typedef struct{
	int codigo;
	string descripcion;
	double horasMes;
} tTarea;

typedef tTarea tArrTarea[MAX_TAREA];
typedef struct {
	tArrTarea tareas;
	int cont;
}tListaTareas;

void cargarTareas(tTarea &tareas, ifstream &file, const tPrioridades &prioridades);
void cargarPrioridades(tPrioridades &prioridades, bool &ok);
double calcularTiempo(tTarea &tareas, const tPrioridades &prioridades);
void mostrarTareas(const tListaTareas &listaTareas);


#endif // _listaTareas

