#include <iostream>
using namespace std;

class PilaEstatica {
private:
	static const int MAX = 10; //Tamaño fijo de la pila.
	int arr[MAX]; // Arreglo para almacenar los elementos de la pila.
	int top; //Indice del último elemento isnertado.

public:
	PilaEstatica() : top(-1) { } // Constructor: inicializa top en -1 (pila vacía).

	//Método para insertar un elemento en la pila.
	bool push(int valor) {
		if (top >= MAX - 1) { // Verifica si la pila está llena.
			cout << "Pila esta llena (overflow)." << endl; // Muestra mensaje de desbordamiento.
			return false; // No se pudo isnertar.
		}
		arr[++top] = valor; //Incremento top e inserta el valor.
		return true; // Inserción exitosa.
	}

	//Método para eliminar y devolver el elemento de la cima de la pila.
	int pop() {
		if (top < 0) { //Verifica si la pila está vacía.
			cout << "Pila esta vacia (underflow)." << endl; // Muestra mensaje de pila vacía.
			return -1; //Valor de error.
		}
		return arr[top--]; //Devuelve el elemento y decrementa top.
	}
	
	//Método para ver (sin eliminar) el elemento de la cima de la pila.
	int peek() const {
		if (top < 0) { // Verifica si la pila está vacía.
			cout << "Pila vacia." << endl; // Muestra mensaje de pila vacía.
			return -1; // Retorna -1 como valor de error.
		} 
		return arr[top]; // Retorna el elemento en la cima de la pila.
	}
};

int main() {
	PilaEstatica pila; // Crea un objeto pila de tipo PilaEstatica.

	pila.push(10); // Inserta el número 10 en la pila
	pila.push(20); // Inserta el número 20 en la pila.
	pila.push(30); // Inserta el número 30 en la pila.
	cout << "Elemento en la cima: " << pila.peek() << endl; //Debería mostrar 30.
	cout << "Elemento eliminado: " << pila.pop() << endl; //30.
	cout << "Elemento eliminado: " << pila.pop() << endl; //20.
	return 0;
}