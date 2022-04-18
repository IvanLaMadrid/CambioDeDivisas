#include "pch.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <functional>
using namespace System;
using namespace std;

template <class Generico>

class Nodo {
public:
	Generico valor;
	Nodo <Generico>* sig;
	Nodo(Generico val) {
		valor = val;
		sig = nullptr;
	}
};

template <class Generico>

class Lista {
	Nodo<Generico>* ini;
	Nodo<Generico>* fin;
	size_t cant;
public:
	Lista() {
		ini = fin = nullptr;
		cant = 0;
	}

	void push_front(Generico val) { //Al frente
		Nodo<Generico>* n = new Nodo<Generico>(val);
		if (cant == 0)
			ini = n;
		else {
			n->sig = ini;
			ini = n;
		}
		++cant;			
	}

	void push_back(Generico val) { //Al ultimo
		Nodo<Generico>* nuevo = new Nodo<Generico>(val);
		if (ini == nullptr)
			ini = fin = nuevo;
		else {
			fin->sig = nuevo;
			fin = nuevo;
		}
		cant++;
	}

	void print(function<void(Generico)> print) { //Imprimir
		Nodo<Generico>* aux = ini;
		while (aux->sig != nullptr) {
			print(aux->valor);
			aux = aux->sig;
		}
	}
};

class SaldoTotal {
public:
	string MONEDA;
	long CANTIDAD;
	SaldoTotal(string MONEDA = "", long CANTIDAD = 0) :MONEDA(MONEDA), CANTIDAD(CANTIDAD) {}
	string toString() {
		return MONEDA + " " + to_string(CANTIDAD);
	}
};

//--------------------------------------
void cambiodivisa(long Saldo, string Moneda, Lista<SaldoTotal> dinero) {
	//
}

void listamonedas() {
	/*
	Leera el archivo MONEDAS.txt y lo imprimira
	*/
	ifstream listado;
	string Tipo;
	int valor;
	//Si no abre
	if (listado.fail()) {
		cout << "Hubo un error al abrir el archivo, presione cualquier tecla para regresar al menu...";
		char tecla = getch();
		return;
	}

	//Mostrar la lista
	listado.open("MONEDAS.txt", ios::in);
	if (listado.is_open()) {
		listado >> Tipo >> valor;
		cout << Tipo << ": " << valor << endl;
	}
	cout << "Presione cualquier tecla para volver al menu...";
	char tecla = getch();
	listado.close();
		//ERROR: No muestra ninguna moneda
}

void nuevacuenta(string Moneda) {
	/*
	Abrirá el archivo CUENTAS.txt y preguntará al usuario cuánto dinero almacenar en una cuenta,
	luego añadirá una nueva línea en el archivo txt con los datos.
	*/

	ofstream cuenta;
	long deposito;
	cuenta.open("CUENTAS.txt", ios::in);

	if (cuenta.fail()) {
		cout << "Hubo un error al abrir el archivo, presione cualquier tecla para regresar al menu...";
		char tecla = getch();
		return;
	}
	if (cuenta.is_open()) {
		cout << "Cuanto desea depositar?"; cin >> deposito;
		cuenta << Moneda << deposito;
	}
}

void historial() {
	/*
	Leerá el contenido del archivo HISTORIAL.txt y lo imprimirá en la consola
	*/

	ifstream historial;
	string valor;
	historial.open("HISTORIAL.txt", ios::in);
	
	//Si el archivo no abre
	if (historial.fail()) {
		cout << "Hubo un error al abrir el archivo, presione cualquier tecla para regresar al menu...";
		char tecla = getch();
		return;
	}
	if (historial.is_open()) {

	}
	while (historial >> valor) {
		cout << endl;
	}
	cout << "Presione cualquier tecla para volver al menu...";
	char tecla = getch();
	historial.close();
}

void deleteHistorial() {
	/*
	Debe borrar todo el contenido del archivo
	*/

	ofstream historial;
	historial.open("HISTORIAL.txt", ios::out | ios::trunc);
	historial.close();
}

void modificarMoneda() {
	/*
	Leerá todo el contenido del archivo MONEDAS.txt y los almacenará en una lista (tipo de moneda
	y su valor según el archivo). Luego el usuario eligirá entre las monedas y cambiará su valor,
	para luego sobreescribir el archivo por completo con los nuevos datos.*/

	ofstream moneda;
	string tipo;
	long nuevoValor;
	moneda.open("MONEDAS.txt", ios::out);
	//Leer las monedas y valor

	//Pregunta al usuario cual cambiar
	cout << "USD, EUR, PEN, RUB, MEX, JPY, AUD, CAD\n";
	cout << "Ingrese la moneda que desea modificar: "; cin >> tipo;
	cout << "Ingrese el nuevo valor de la moneda: "; cin >> nuevoValor;

	//Modifica la moneda

	//Cierra el archivo
	moneda.close();
		//ERROR: A partir de aqui el programa entra en un loop infinito
}

void eliminarCuentas() {
	/*
	Debe borrar todo el contenido del archivo
	*/

	ofstream cuentas;
	cuentas.open("CUENTAS.txt", ios::out | ios::trunc);
	cuentas.close();
}

void ajustes() {
	short opAjustes = 0;
	cout << "--------------AJUSTES--------------\n";
	cout << "1. Eliminar el historial\n";
	cout << "2. Modificar el valor de una moneda manualmente\n";
	cout << "3. Eliminar las cuentas de ahorros\n";
	cout << "4. Volver a la pantalla principal\n";
	do {
		cin >> opAjustes;
		if (opAjustes < 1 || opAjustes > 4) cout << "Opcion " << opAjustes << " invalida. Ingrese nueva opcion: ";
	} while (opAjustes < 1 || opAjustes > 4);
	switch (opAjustes) {
	case 1:
		deleteHistorial();
		break;
	case 2:
		modificarMoneda();
		break;
	case 3:
		eliminarCuentas();
		break;
	case 4:
		system("cls");
		return;
	}
	system("cls");

}

void Menu(string TipoMoneda, long dineroInicial) {
	Lista<SaldoTotal> dinero;
	long Saldo = dineroInicial;
	string Moneda = TipoMoneda;
	dinero.push_back(SaldoTotal(Moneda, Saldo));
	short opMenu=1;
	//Imprime el valor inicial
	dinero.print([](SaldoTotal val) {cout << val.toString() << endl; });
		//ERROR: No imprime el valor inicial consultado en main

	//Menu
	cout << "\nAHORROSEGURO - Cambio de divisas\n";
	cout << "Desarrollado por:\n";
	cout << "	Integrante1\n\n";
	cout << "	Integrante2\n\n";
	cout << "	Integrante3\n\n";
	cout << "---------LISTA DE ACCIONES---------\n";
	cout << "1. Realiza un cambio de divisa inmediato\n";
	cout << "2. Mostrar la lista de monedas a cambiar y su valor\n";
	cout << "3. Abre una nueva cuenta de ahorros\n";
	cout << "4. Mostrar el historial de transacciones\n";
	cout << "5. Ajustes (Avanzado)\n";
	cout << "6. Salir\n";
	//Pide ingresar la opcion
	cout << "\nNota: Si es su primera vez ejecutando el programa, recomendamos revisar los ajustes.\nOpcion:";
	
	do {
		cin >> opMenu;
		if (opMenu < 1 || opMenu > 6) cout << "Opcion " << opMenu << " invalida. Ingrese nueva opcion: ";
	} while (opMenu < 1 || opMenu > 6);
	switch (opMenu) {
	case 1:
		cambiodivisa(Saldo, Moneda, dinero);
		break;
	case 2:
		listamonedas();
		break;
	case 3:
		nuevacuenta(Moneda);
		break;
	case 4:
		historial();
		break;
	case 5:
		ajustes();
		break;
	case 6:
		return;
	}
	system("cls");
	
	Menu(Moneda, Saldo);
}

int main() {
	long dineroInicial = 0;
	string TipoMoneda;
	cout << "Antes de iniciar el programa, ingrese la cantidad de dinero con la que desea operar.\n(Tipos de moneda valida: USD, EUR, PEN, RUB, MXN, JPY, AUD, CAD)";
	cout << "\nNota: El valor no permanecerá para futuras ejecuciones, pero sí las cuentas que usted\nabra, por lo que recomendamos almacenarlas en una.\n";
	do {
		cout << "Tipo de moneda: "; cin >> TipoMoneda;
	} while (TipoMoneda != "USD" && TipoMoneda != "EUR" && TipoMoneda != "PEN" && TipoMoneda != "RUB" &&
		TipoMoneda != "MXN" && TipoMoneda != "JPY" && TipoMoneda != "AUD" && TipoMoneda != "CAD");
	
	cout << "Cantidad de dinero: "; cin >> dineroInicial;

	system("cls");
	Menu(TipoMoneda, dineroInicial);

	return 0;
}