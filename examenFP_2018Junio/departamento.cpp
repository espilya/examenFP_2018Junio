#include "departamento.h"

void inicializar(tDepartamento &dep, const string id) {
	dep.cont = 0;
	dep.id = id;
	dep.empleados = new tPtrEmpleado[MAX_EMPLEADOS];

	//creacion de los empleados en el array d.
	for (int i = 0; i < MAX_EMPLEADOS; i++) {
		dep.empleados[i] = new tEmpleado;
		dep.empleados[i]->num = i;
		dep.empleados[i]->ptrContrato = new tContrato;
	}
}

void liberar(tDepartamento &dep) {
	for (int i = 0; i < MAX_EMPLEADOS; i++)
		delete dep.empleados[i];
	delete[] dep.empleados;
}


int buscarEmpleado(tDepartamento &dep, const string NIF) {
	bool encontrado = false;
	int i = 0;
	while (i < MAX_EMPLEADOS && !encontrado) {
		if (dep.empleados[i]->ptrContrato->nif == NIF)
			encontrado = true;
		else
			i++;
	}
	if (encontrado)
		return i;
	else
		return -1;
}



void  insertarEmpleado(const tListaContratos &lista, tDepartamento &dep, bool &ok) {
	int linea, num;
	mostrarContratos(lista);
	cout << "Introduce el numero de linea del contrato:\n>";
	cin >> linea; linea--;
	if (dep.cont < MAX_EMPLEADOS && buscarEmpleado(dep, lista.contrato[linea]->nif) == -1) {
		dep.empleados[dep.cont]->ptrContrato = lista.contrato[linea];
		cout << "Numero para el empleado:\n>";
		cin >> num;
		dep.empleados[dep.cont]->num = num;
		dep.cont++;
	}
	else
		ok = false;
}


void mostrarEmpleado(tEmpleado empleado) {
	cout << left << setw(40) << empleado.ptrContrato->nombre  << "num: " << empleado.num << '\n';
}

void mostrarDepartamento(const tDepartamento &DEP, int i = 0) {
	cout << i+1 << '.' << " ";
	mostrarEmpleado(*DEP.empleados[i]);
	if (i < DEP.cont - 1)
		mostrarDepartamento(DEP, ++i);
}


