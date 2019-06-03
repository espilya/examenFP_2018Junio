
#include "departamento.h"

using namespace std;


const int N = 50;



int menu();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tDepartamento dpto;
	tListaContratos lista;
	tPrioridades prioridades;
	tEmpleado empleado;
	string id, nif;
	int opcion, pos = -1;
	bool ok = false;
	cargarPrioridades(prioridades, ok);
	if (ok) {
		cargarContratos(lista, prioridades, ok);
		if (ok) {
			cout << "Identificador del departamento: ";
			cin >> id;
			cout << endl;
			inicializar(dpto, id);
			do {
				opcion = menu();
				switch (opcion) {
				case 1:
					insertarEmpleado(lista, dpto, ok);
					if (!ok)
						cout << "Error al insertar el empleado." << endl;
					break;
				case 2:
					cout << "Nif del empleado: ";
					cin >> nif;
					cout << endl;
					pos = buscarEmpleado(dpto, nif);
					if (pos != -1)
						mostrarTareas(dpto.empleados[pos]->ptrContrato->lista);
					else
						cout << "El empleado no existe." << endl;
					cout << endl;
					break;
				case 3:
					if (dpto.cont != 0) {
						cout << "Los empleados son : " << endl;
						mostrarDepartamento(dpto, 0);
					}
					else 
						cout << "No hay empleados." << endl;
					cout << endl;
					break;
				}
			} while (opcion != 0);
			liberar(lista);
			liberar(dpto);
		}
		else 
			cout << "Error al cargar la lista de contratos." << endl;
	}
	else 
		cout << "Error al cargar las prioridades." << endl;
	return 0;
} // main

int menu() {
	cout << "1.Insertar enpleado en el nuevo departamento.\n"
		<< "2.Mostrar las tareas de un empleado.\n"
		<< "3.Mostrar los empleados actuales del departamento.\n"
		<< "0.Salir.\n";
	cout << "Elige opcion:\n>";
	int op;
	while (cin >> op && (op < 0 && op > 3)) {
		cout << "Opcion incorrecta. Prueba de nuevo.\n>";
	}
	return op;
}