#include"listaContratos.h"

void liberar(tListaContratos &lista) {
	for (int i = 0; i < lista.cont; i++) {
		delete lista.contrato[i];
	}
}

void cargarContratos(tListaContratos &lista, tPrioridades &prioridades, bool &ok) {
	ifstream file; file.open(fileContratos);
	lista.cont = 0;
	if (file.is_open()) {
		int n, m;  char x;
		file >> n;  file.get(x);
		for (int i = 0; i < n; i++) {
			tContrato contrato;
			getline(file, contrato.nombre);
			file >> contrato.nif;
			file >> contrato.sueldo;
			file >> m; 
			contrato.lista.cont = m;
			for (int j = 0; j < m; j++) {
				file >> contrato.lista.tareas[j].codigo; file.get(x);
				getline(file, contrato.lista.tareas[j].descripcion);
				contrato.lista.tareas[j].horasMes = calcularTiempo(contrato.lista.tareas[j], prioridades);
			}

			insertarContratos(lista, i, contrato);
			lista.cont++;
		}
		ok = true;
	}
	else
		ok = false;
	file.close();
}

void insertarContratos(tListaContratos &lista, int i, tContrato &contrato) {
	tPtrContrato tempContrato;
	
	if(i == 0)
		lista.contrato[0] = new tContrato(contrato);
	else {
		if (contrato.nif > lista.contrato[i-1]->nif) {

			lista.contrato[i] = new tContrato(contrato);

		}
		else {
			lista.contrato[i] = new tContrato;
			*lista.contrato[i] = *lista.contrato[i - 1];
			*lista.contrato[i - 1] = contrato;
		}
	}
}

void mostrarContratos(const tListaContratos &lista) {
	for (int i = 0; i < lista.cont; i++) {
		cout << i+1 << ". " << left << setw(40) << lista.contrato[i]->nombre << lista.contrato[i]->nif << " "
			<< " (" << lista.contrato[i]->lista.cont << ") " <<fixed << setprecision(2) << lista.contrato[i]->sueldo << '\n';
	}
}
void seleccionarContratos(tListaContratos &lista) {} // lo hice dirrectamente en 'insertarEmpleado'