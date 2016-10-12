// MetodosOrdenamiento.cpp: archivo de proyecto principal.

#include "stdafx.h"

using namespace System;
using namespace std;

int cont = 0;

struct nodo {
	int dato;
	struct nodo* siguiente;
};
typedef nodo* Tlista;
Tlista lista = NULL;
Tlista lista0 = NULL, lista1 = NULL, lista2 = NULL,
lista3 = NULL, lista4 = NULL, lista5 = NULL, lista6 = NULL,
lista7 = NULL, lista8 = NULL, lista9 = NULL;

void menu();
void insertar_inicio(Tlista &lista, int dato);
void insertar_final(Tlista &lista);
void Insercion(Tlista &lista, int elemento);
void Intercambio(Tlista &lista);
void burbuja(Tlista &lista);
void Seleccion(Tlista &lista);
void shell(Tlista &lista);

int pot(int base, int exp);
void insertarLista0(Tlista &lista0);
void insertarLista1(Tlista &lista1);
void insertarLista2(Tlista &lista2);
void insertarLista3(Tlista &lista3);
void insertarLista4(Tlista &lista4);
void insertarLista5(Tlista &lista5);
void insertarLista6(Tlista &lista6);
void insertarLista7(Tlista &lista7);
void insertarLista8(Tlista &lista8);
void insertarLista9(Tlista &lista9);
void Radix(Tlista &lista);
void llenar(Tlista &lista, Tlista listaNum);
void insertar(Tlista &lista);

int tamanio(Tlista lista);
int dato(Tlista lista, int tamanio);
void intercambiar(Tlista &lista, int pos, int datoero);
void quickSort(Tlista lista, int primero, int ultimo);

void mostrar(Tlista &lista);


int main()
{
	menu();
}

void menu() {
	int opcion = 0, elemento;
	system("cls");
	int opc;
	cout << "\t\t\tษออออออออออออออออออออออออออป" << endl;
	cout << "\t\t\tบ        ORDENAMIENTO      บ" << endl;
	cout << "\t\t\tฬออออออออออออออออออออออออออน" << endl;
	cout << "\t\t\tบ                          บ" << endl;
	cout << "\t\t\tบ    1.Insertar Datos      บ" << endl;
	cout << "\t\t\tบ    2.Burbuja             บ" << endl;
	cout << "\t\t\tบ    3.Insercion           บ" << endl;
	cout << "\t\t\tบ    4.Intercambio         บ" << endl;
	cout << "\t\t\tบ    5.Seleccion           บ" << endl;
	cout << "\t\t\tบ    6.ShellSort           บ" << endl;
	cout << "\t\t\tบ    7.QuickSort           บ" << endl;
	cout << "\t\t\tบ    8.RadixSort           บ" << endl;
	cout << "\t\t\tบ    9.Mostrar             บ" << endl;
	cout << "\t\t\tบ    10.Salir              บ" << endl;
	cout << "\t\t\tบ                          บ" << endl;
	cout << "\t\t\tศออออออออออออออออออออออออออผ" << endl;

	cout << "\t\t\tIngrese una opcion : ";
	cin >> opc;
	cout << endl;
	switch (opc) {
	case 1:
		insertar_final(lista);
		break;
	case 2:
		burbuja(lista);
		break;
	case 3:
		system("cls");
		int opc1;
		cout << "\t\t\tษออออออออออออออออออออออออออป" << endl;
		cout << "\t\t\tบ  ORDENAMIENTO INSERCION  บ" << endl;
		cout << "\t\t\tฬออออออออออออออออออออออออออน" << endl;
		cout << "\t\t\tบ                          บ" << endl;
		cout << "\t\t\tบ    1.Insertar Datos      บ" << endl;
		cout << "\t\t\tบ    2.Mostrar ordenado    บ" << endl;
		cout << "\t\t\tบ    3.Salir               บ" << endl;
		cout << "\t\t\tบ                          บ" << endl;
		cout << "\t\t\tศออออออออออออออออออออออออออผ" << endl;

		cout << "\t\t\tIngrese una opcion : ";
		cin >> opc1;
		cout << endl;
		switch (opc1) {
		case 1: cout << "Ingrese elemento :";
			cin >> elemento;
			Insercion(lista, elemento);
			break;
		case 2: mostrar(lista);
			break;
		case 3: cout << "Salir" << endl;
			break;
		default: cout << "Opcion incorrecta" << endl;
			break;

		}

	case 4:
		Intercambio(lista);
		break;
	case 5:
		Seleccion(lista);
		break;
	case 6:
		shell(lista);
		break;
	case 7:
		quickSort(lista, 1, tamanio(lista));
		break;
	case 8:
		Radix(lista);
		break;
	case 9:
		mostrar(lista);
		break;
	case 10:
		system("EXIT");
		break;
	default:cout << "Opcion invalida" << endl;
		menu();
		break;
	}
}


void insertar_inicio(Tlista &lista, int dato) {
	Tlista nuevo;
	nuevo = new(struct nodo);
	nuevo->dato = dato;
	nuevo->siguiente = NULL;
	lista = nuevo;

}

void insertar_final(Tlista &lista) {
	cout << "Ingrese el dato que desee agregar :";
	int dato;
	cin >> dato;

	Tlista p, q = lista;
	p = new(struct nodo);
	p->dato = dato;
	p->siguiente = NULL;

	if (lista == NULL) {
		insertar_inicio(lista, dato);
	}
	else {
		while (q->siguiente != NULL) {
			q = q->siguiente;
		}
		q->siguiente = p;
	}
	system("PAUSE");
	system("cls");
	menu();
}

void mostrar(Tlista &lista) {
	Tlista p = lista;
	cout << "La lista es la siguiente  : " << endl;
	while (p != NULL) {
		cout << p->dato << " ";
		p = p->siguiente;
	}
	cout << endl;
	system("PAUSE");
	system("cls");
	menu();
}

void burbuja(Tlista &lista) {
	Tlista p = lista, q = lista;
	int aux;
	while (q != NULL) {
		while (p->siguiente != NULL) {
			if (p->dato > p->siguiente->dato) {
				aux = p->dato;
				p->dato = p->siguiente->dato;
				p->siguiente->dato = aux;
			}
			p = p->siguiente;
		}
		p = lista;
		q = q->siguiente;
	}

	cout << "LISTA ORDENADA!!" << endl;
	system("PAUSE");
	system("cls");
	menu();
}

void Insercion(Tlista &lista, int elem) {
	int num;
	Tlista nuevo, inicio = lista;
	nuevo = new(struct nodo);
	nuevo->dato = elem;
	nuevo->siguiente = NULL;

	if (lista == NULL)
		lista = nuevo;
	else {
		Tlista aux = lista, fin = NULL;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;
		aux->siguiente
			= nuevo;
		fin = nuevo;
		while (inicio->siguiente != NULL) {
			if (fin->dato<inicio->dato) {
				num = fin->dato;
				fin->dato = inicio->dato;
				inicio->dato = num;
			}
			inicio = inicio->siguiente;
		}
	}
	cout << "ELEMENTO REGISTRADO!!" << endl;

	system("pause");
	system("cls");
	menu();

}

void Intercambio(Tlista &lista) {
	Tlista p = lista, q = NULL;
	while (p->siguiente != NULL) {
		q = p->siguiente;
		while (q != NULL) {
			int aux;
			if (p->dato > q->dato) {
				aux = p->dato;
				p->dato = q->dato;
				q->dato = aux;
			}
			q = q->siguiente;
		}
		p = p->siguiente;
	}
	cout << "LISTA ORDENADA!!!" << endl;
	system("pause");
	system("cls");
	menu();
}

void Seleccion(Tlista &lista) {
	Tlista q = lista, p = lista;
	int min;
	Tlista aux = NULL;
	bool encontrado = true;
	do {
		encontrado = false;
		min = q->dato;
		p = q->siguiente;
		do {
			if (min>p->dato) {
				aux = p;
				min = aux->dato;
			}
			p = p->siguiente;
		} while (p != NULL);
		aux->dato = q->dato;
		q->dato = min;
		q = q->siguiente;
	} while (q->siguiente != NULL);

	cout << "LISTA ORDENADA!!!" << endl;
	system("pause");
	system("cls");
	menu();
}


void shell(Tlista &lista) {
	Tlista p = lista, q = lista;
	int elementos = cont, aux;
	int n = elementos / 2;
	while (n != 0) {
		int i = 1;
		bool inter = false;
		while (i <= n) {
			q = q->siguiente;
			i++;
		}
		while (q != NULL) {
			if (p->dato > q->dato) {
				aux = p->dato;
				p->dato = q->dato;
				q->dato = aux;
				inter = true;
			}
			p = p->siguiente;
			q = q->siguiente;
		}
		p = lista;
		q = lista;
		n = n / 2;
		if (n == 0 && inter == true)
			n = 1;
	}
	cout << "ELEMENTOS ORDENADOS" << endl;
	system("PAUSE");
	system("cls");
	menu();
}

//radix

void insertarLista0(Tlista &lista0, int num) {
	Tlista p = lista0;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista0 == NULL) {
		lista0 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista1(Tlista &lista1, int num) {
	Tlista p = lista1;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista1 == NULL) {
		lista1 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista2(Tlista &lista2, int num) {
	Tlista p = lista2;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista2 == NULL) {
		lista2 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista3(Tlista &lista3, int num) {
	Tlista p = lista3;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista3 == NULL) {
		lista3 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista4(Tlista &lista4, int num) {
	Tlista p = lista4;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista4 == NULL) {
		lista4 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista5(Tlista &lista5, int num) {
	Tlista p = lista5;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista5 == NULL) {
		lista5 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista6(Tlista &lista6, int num) {
	Tlista p = lista6;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista6 == NULL) {
		lista6 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista7(Tlista &lista7, int num) {
	Tlista p = lista7;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista7 == NULL) {
		lista7 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista8(Tlista &lista8, int num) {
	Tlista p = lista8;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista8 == NULL) {
		lista8 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

void insertarLista9(Tlista &lista9, int num) {
	Tlista p = lista9;
	Tlista nuevo = new(struct nodo);
	nuevo->dato = num;
	nuevo->siguiente = NULL;
	if (lista9 == NULL) {
		lista9 = nuevo;
		nuevo->siguiente = NULL;
	}
	else {
		while (p->siguiente != NULL)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
}

int pot(int base, int exp) {
	int resp = 1, i;
	if (exp == 0)
		return 1;
	else {
		for (i = 1; i <= exp; i++)
			resp = 10 * resp;
		return resp;
	}

}

void Radix(Tlista &lista) {
	Tlista p = lista;
	bool seguir = false;
	int r, n = 1;
	while (p != NULL || seguir == true) {
		seguir = false;
		p = lista;
		while (p != NULL) {
			r = (p->dato%pot(10, n)) / pot(10, n - 1);
			if (r != 0)
				seguir = true;
			switch (r) {
			case 0: insertarLista0(lista0, p->dato); break;
			case 1: insertarLista1(lista1, p->dato); break;
			case 2: insertarLista2(lista2, p->dato); break;
			case 3: insertarLista3(lista3, p->dato); break;
			case 4: insertarLista4(lista4, p->dato); break;
			case 5: insertarLista5(lista5, p->dato); break;
			case 6: insertarLista6(lista6, p->dato); break;
			case 7: insertarLista7(lista7, p->dato); break;
			case 8: insertarLista8(lista8, p->dato); break;
			case 9: insertarLista9(lista9, p->dato); break;
			}
			p = p->siguiente;
		}
		insertar(lista);
		n = n + 1;
	}
	cout << "ELEMENTOS ORDENADOS !!!" << endl;
	system("PAUSE");
	system("cls");
	menu();
}

void llenar(Tlista &lista, Tlista listaNum) {
	Tlista aux = listaNum;
	while (aux != NULL) {
		Tlista p = lista;
		Tlista nuevo = new(struct nodo);
		nuevo->dato = aux->dato;
		nuevo->siguiente = NULL;
		if (lista == NULL) {
			lista = nuevo;
			nuevo->siguiente = NULL;
		}
		else {
			while (p->siguiente != NULL)
				p = p->siguiente;
			p->siguiente = nuevo;
		}
		aux = aux->siguiente;
	}
}

void insertar(Tlista &lista) {
	lista = NULL;
	if (lista0 != NULL) {
		llenar(lista, lista0);
		lista0 = NULL;
	}
	if (lista1 != NULL) {
		llenar(lista, lista1);
		lista1 = NULL;
	}
	if (lista2 != NULL) {
		llenar(lista, lista2);
		lista2 = NULL;
	}
	if (lista3 != NULL) {
		llenar(lista, lista3);
		lista3 = NULL;
	}
	if (lista4 != NULL) {
		llenar(lista, lista4);
		lista4 = NULL;
	}
	if (lista5 != NULL) {
		llenar(lista, lista5);
		lista5 = NULL;
	}
	if (lista6 != NULL) {
		llenar(lista, lista6);
		lista6 = NULL;
	}
	if (lista7 != NULL) {
		llenar(lista, lista7);
		lista7 = NULL;
	}
	if (lista8 != NULL) {
		llenar(lista, lista8);
		lista8 = NULL;
	}
	if (lista9 != NULL) {
		llenar(lista, lista9);
		lista9 = NULL;
	}
}


int dato(Tlista lista, int tamanio) {
	int c = 1;
	while (c != tamanio) {
		lista = lista->siguiente;
		c++;
	}
	return lista->dato;
}

void intercambiar(Tlista &lista, int pos, int datoero) {
	Tlista aux = lista;
	int c = 1;
	while (c != pos) {
		aux = aux->siguiente;
		c++;
	}
	aux->dato = datoero;
}

void quickSort(Tlista lista, int primero, int ultimo) {
	int i, j, central, pivote;
	central = (primero + ultimo) / 2;
	pivote = dato(lista, central);
	i = primero;
	j = ultimo;
	do {
		while (dato(lista, i)<pivote)
			i++;
		while (dato(lista, j)>pivote)
			j--;
		if (i <= j) {
			int aux;
			aux = dato(lista, i);
			intercambiar(lista, i, dato(lista, j));
			intercambiar(lista, j, aux);
			i++;
			j--;
		}
	} while (i <= j);

	if (primero<j)
		quickSort(lista, primero, j);
	if (i<ultimo)
		quickSort(lista, i, ultimo);

	cout << "LISTA ORDENADA!!" << endl;
	system("PAUSE");
	system("cls");
	menu();
}

int tamanio(Tlista lista) {
	int c = 1;
	while (lista->siguiente != NULL) {
		lista = lista->siguiente;
		c++;
	}
	return c;
}
