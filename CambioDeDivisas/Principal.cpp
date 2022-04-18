#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <functional>
using namespace std;
void Menu(string TipoMoneda, long dineroInicial);
void LecturaMonedas();

void comparacion() {
	int n;
	float cambio = 1.5;
	float bancoA = 1.3;
	float bancoB = 1.2;
	float bancoC = 1.1;
	cout << endl << "-------------------------------------------------------------------------------" << endl << endl;
	cout << "1. Banco Interbak" << endl;
	cout << "2. Banco MiBanco" << endl;
	cout << "3. Banco CityBank" << endl;
	cout << endl << "-------------------------------------------------------------------------------" << endl << endl;
	cout << "Ingrese el numero del banco con el cual desea comparar: ";
	cin >> n;
	switch (n) {
	case 1:
		cout << endl<< "En comparacion con el banco Interbak, la ganacia obtenida es del %" << (cambio / 100) - (bancoA / 100) << endl;
		break;
	case 2:
		cout << endl << "En comparacion con el banco MiBanco, la ganacia obtenida es del %" << (cambio / 100) - (bancoB / 100) << endl;
		break;
	case 3:
		cout << endl << "En comparacion con el banco CityBank, la ganacia obtenida es del %" << (cambio / 100) - (bancoC / 100) << endl;
		break;
	}
	cout << endl << "-------------------------------------------------------------------------------" << endl << endl;
	cout << "Para regresar al menu principal presione cualquier tecla...";
	getch();
}

void LecturaMonedas() {
	ifstream archivo;
	string texto;
	archivo.open("MONEDAS.txt", ios::in);
	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo.";
		system("pause");
	}
	while (!archivo.eof()) {
		getline(archivo, texto);
		cout << texto << endl;
	}
	archivo.close();
	getch();
}

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
struct DineroMoneda
{
	long dineroInicial;
	string TipoMoneda;
};
int main()
{
	struct DineroMoneda finanza;
	long dineroInicial = 0;
	string TipoMoneda;
	cout << endl << "-------------------------------------------------------------------------------" << endl << endl;
	cout << " Desarrollado por:\n";
	cout << "	Sebastian Pacheco Astiguetta\n";
	cout << "	Ivan Jeanpierre La Madrid Lozano\n";
	cout << "	Sofia Beatriz Allca Urbano\n";
	cout << endl << "-------------------------------------------------------------------------------" << endl << endl;
	cout << "Ingrese la cantidad de dinero con la que desea operar.\n(Tipos de moneda valida: USD, EUR, PEN, RUB, MXN, JPY, AUD, CAD)"<<endl;
	do {
		cout << "Tipo de moneda: "; cin >> TipoMoneda;
	} while (TipoMoneda != "USD" && TipoMoneda != "EUR" && TipoMoneda != "PEN" && TipoMoneda != "RUB" &&
		TipoMoneda != "MXN" && TipoMoneda != "JPY" && TipoMoneda != "AUD" && TipoMoneda != "CAD");
	cout << "Ingrese la cantidad de dinero inicial: "; cin >> dineroInicial;
	system("cls");
	finanza = {dineroInicial, TipoMoneda};
	finanza.TipoMoneda = TipoMoneda;
	finanza.dineroInicial = dineroInicial;
	Menu(finanza.TipoMoneda, finanza.dineroInicial);
	return 0;
};

void Menu(string TipoMoneda, long dineroInicial)
{
	Lista<SaldoTotal> dinero;
	long Saldo = dineroInicial;
	string Moneda = TipoMoneda;
	dinero.push_back(SaldoTotal(Moneda, Saldo));
	short opMenu = 1;
	//Imprime el valor inicial
	dinero.print([](SaldoTotal val) {cout << val.toString() << endl; });
	//ERROR: No imprime el valor inicial consultado en main

	int opcion;
	cout << endl << "-------------------------------Cambio de divisas-------------------------------" << endl;
	cout << endl << " 1.- Realizar un cambio de divisa inmediato" << endl; //hecho
	cout << " 2.- Modificar las monedas en caso se desee cambiar su valor" << endl; //hecho
	cout << " 3.- Ingresar la cantidad de dinero inicial del programa." << endl;
	cout << " 4.- Redondeo a enteros los cambios que estan en decimal." << endl;
	cout << " 5.- Mostrar la lista de monedas a poder cambiar." << endl;
	cout << " 6.- Realizar la transacción del cambio." << endl;
	cout << " 7.- Abrir una nueva cuenta, y elegir la moneda base de la cuenta." << endl; //hecho
	cout << " 8.- Depositar cierta cantidad de dinero en la cuenta." << endl;
	cout << " 9.- Comparacion del porcentaje de ganancias con el banco." << endl;
	cout << " 10.- Mostrar el historial de transacciones de la cuenta." << endl; // hecho
	cout << " 11.- Mover la cantidad de dinero ingresada por el usuario a otra cuenta." << endl;
	cout << " 12.- Mostrar el dinero guardado en la cuenta." << endl;
	cout << " 13.- Ajustes." << endl;
	cout << endl << "-------------------------------------------------------------------------------" << endl;
	cout << endl << " Escoga un opcion: ";

	do {
		cin >> opcion;
		if (opcion < 1 || opcion > 13) cout << "Opcion " << opcion << " invalida. Ingrese nueva opcion: ";
	} while (opcion < 1 || opcion > 13);

	switch (opcion)
	{
	case 1:
		system("CLS");
		cambiodivisa(Saldo, Moneda, dinero);
		break;
	case 2:
		system("CLS");
		listamonedas();
		break;
	case 3:
		system("CLS");
		LecturaMonedas();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		system("CLS");
		nuevacuenta(Moneda);
		break;
	case 8:
		break;
	case 9:
		system("CLS");
		comparacion();
		break;
	case 10:
		system("CLS");
		historial();
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		ajustes();
		break;
	default:
		break;
	}
	system("cls");
	Menu(Moneda, Saldo);
}