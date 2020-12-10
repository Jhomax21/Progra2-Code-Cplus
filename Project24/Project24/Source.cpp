#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

int* agregarFinal(int* vector, int* N, int elemento) {
	int* Aux = new int[*N + 1];
	for (int i = 0; i < *N; i++) {
		Aux[i] = vector[i];
	}
	Aux[*N] = elemento;
	*N = *N + 1;
	return Aux;
}

int* agregarInicio(int* vector, int* N, int elemento) {
	int* Aux = new int[*N + 1];
	for (int i = 0; i < *N; i++) {
		Aux[i] = vector[i];
	}
	for (int i = 1; i < *N; i++) {
		Aux[i + 1] = vector[i];
	}
	Aux[1] = elemento;
	*N = *N + 1;
	return Aux;
}

void ordenar(int* vector, int* N) {
	for (int i = 0; i < *N; i++) {
		for (int j = i + 1; j < *N; j++) {
			if (vector[i] < vector[j]) {
				swap(vector[i], vector[j]);
			}
		}
	}
}

int* eliminar(int* vector, int* N, int pos) {
	int* Aux = new int[*N - 1];
	for (int i = 0; i < pos; i++) {
		Aux[i] = vector[i];
	}
	for (int i = pos + 1; i < *N; i++) {
		Aux[i - 1] = vector[i];
	}
	*N = *N - 1;
	return Aux;
}

void listar(int* vector, int* N) {
	for (int i = 0; i < *N; i++) {
		cout << "vector[" << i << "] = " << vector[i] << endl;
	}
}

void menu() {
	cout << "-----MENU-----" << endl;
	cout << "1 - LISTAR ELEMENTOS" << endl;
	cout << "2 - AGREGAR AL FINAL" << endl;
	cout << "3 - ELIMINAR EN POSICION" << endl;
	cout << "4 - AGREGAR AL INICIO" << endl;
	cout << "5 - ORDENAR DE  MAYOR A MENOR" << endl;
}

void main() {
	int* N = new int;
	*N = 0;
	int* vector = NULL;
	int elemento, pos;

	int tecla;
	while (true) {
		Console::Clear();
		menu();
		cout << "Opcion: ";
		cin >> tecla;
		Console::Clear();
		switch (tecla)
		{
		case 1:
			cout << "1 - LISTAR ELEMENTOS" << endl;
			listar(vector, N);
			break;
		case 2:
			cout << "2 - AGREGAR AL FINAL" << endl;
			cout << "Ingrese un elemento: ";
			cin >> elemento;
			vector = agregarFinal(vector, N, elemento);
			break;
		case 3:
			cout << "3 - ELIMINAR EN POSICION" << endl;
			cout << "Ingrese la posicion a eliminar: " << endl;
			cin >> pos;
			vector = eliminar(vector, N, pos);
			cout << "Elemento eliminado..." << endl;
			break;
		case 4:
			cout << "4 - AGREGAR AL INICIO" << endl;
			cout << "Ingrese un elemento: ";
			cin >> elemento;
			vector = agregarInicio(vector, N, elemento);
			break;
		case 5:
			cout << "5 - ORDENAR DE  MAYOR A MENOR" << endl;
			ordenar(vector, N);
			listar(vector, N);
			break;
		}
		cout << "Presione una tecla para continuar..." << endl;
		_getch();
	}

	_getch();
}