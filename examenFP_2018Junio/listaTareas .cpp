#include "listaTareas.h"

void cargarPrioridades(tPrioridades &prioridades, bool &ok) {
	ifstream file;
	file.open(filePrioridades);
	if (file.is_open()) {
		int i = 0;
		while (i < 5) {
			for (int j = 0; j < 7; j++) {
				file >> prioridades.tabla[i][j]; //anyo, tipoTareas
			}
			i++;
		}
		ok = true;
	}
	else
		ok = false;	
}

void mostrarTareas(const tListaTareas &listaTareas){
	cout << "La lista de tareas es:\n";
	cout << listaTareas.tareas->codigo << "  " << left << setw(40) << listaTareas.tareas->descripcion 
		<< listaTareas.tareas->horasMes << endl;
}

void cargarTareas(tTarea &tareas, ifstream &file, const tPrioridades &prioridades) {

	file >> tareas.codigo; 
	cout << tareas.codigo << endl;
	getline(file, tareas.descripcion);
	cout << tareas.descripcion << endl;
	tareas.horasMes = calcularTiempo(tareas, prioridades);

}

double calcularTiempo(tTarea &tareas, const tPrioridades &prioridades) {
	long double media = 0;
	for (int i= 0; i < 5; i++) 
		media *= prioridades.tabla[i][tareas.codigo]; //anyo, tipoTareas
	media = floor(media);
	return (double)media;
}