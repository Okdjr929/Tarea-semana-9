
#include <iostream> //libreria estandar de entrada y salida
using namespace std; // espacio o salto de linea

struct Nodo { // define un nodo
    int dato; // almacena el valor
    Nodo* siguiente; // puntero al siguiente 
};

class PilaDinamica { // usa nodos enlazados dinamicamente
private:
    Nodo* cima; // apunta al nodo en la cima de la pila

public: 
    // Constructor
    PilaDinamica() : cima(nullptr) {} // inicia la pila con cima apuntando a nullptr, que significa que esta vacia

    // Destructor
    ~PilaDinamica() { // se llama automaticamnente cuando el objeto se destrulle
        while (cima != nullptr) { //libera la memoria de todos los nodos eliminados uno por uno
            pop();
        }
    }

    // Método push
    void push(int valor) {
        Nodo* nuevo = new Nodo; // crea un nuevo nodo en memoria dinamica
        nuevo->dato = valor; // asigna el valor recibido
        nuevo->siguiente = cima; // el nuevo nodo apunta a la antigua cima
        cima = nuevo;            // actualiza la cima a este nuevo nodo
    }

    // Método pop
    int pop() {
        if (cima == nullptr) { // si la pila esta vacia muestra un mensaje y retirna -1
            cout << "Pila vacía (underflow)." << endl;
            return -1; // valor de error
        }
        Nodo* temp = cima;
        int valor = temp->dato;
        cima = cima->siguiente; // la nueva cima es el siguiente nodo
        delete temp;            // libera la memoria del nodo
        return valor;
    }

    // Método peek
    int peek() const {
        if (cima == nullptr) {
            cout << "Pila vacía." << endl; // si la pila esta vacia informa y retorna -1
            return -1;
        }
        return cima->dato; // si no retorna el valor del nodo en la cima sin eliminarlo 
    }
};

int main() {
    PilaDinamica pila; // crea un objeto pila de la clase pilaDinamica
    pila.push(100); // inserta 3 elementos en la pila 300 seria la cima seguidos de 200 y luego de 300
    pila.push(200);
    pila.push(300);

    cout << "Elemento en la cima: " << pila.peek() << endl;     // debería mostrar 300
    cout << "Elemento eliminado:  " << pila.pop() << endl;      // debería mostrar 300
    cout << "Elemento eliminado:  " << pila.pop() << endl;      // debería mostrar 200
    cout << "Elemento en la cima: " << pila.peek() << endl;     // debería mostrar 100
}