#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ================================
// Estructura de atributos
// ================================
struct Atributos {
    string tipo;
    string valor;
    string ambito;
    int linea;

    Atributos() {}
    Atributos(string tipo, string valor, string ambito, int linea)
        : tipo(tipo), valor(valor), ambito(ambito), linea(linea) {}
};

// ================================
// Nodo para colisiones
// ================================
struct Nodo {
    string clave;
    Atributos atributos;
    Nodo* siguiente;

    Nodo(string c, Atributos atr) : clave(c), atributos(atr), siguiente(NULL) {}
};

// ================================
// Clase Tabla Hash
// ================================
class TablaHash {
private:
    vector<Nodo*> tabla;
    int capacidad;

    int hashFunction(const string& clave) const {
        unsigned long hash = 0;
        for (size_t i = 0; i < clave.size(); i++) {
            hash = (hash * 31 + clave[i]) % capacidad;
        }
        return hash;
    }

public:
    TablaHash(int cap = 20) : capacidad(cap) {
        tabla.resize(capacidad, NULL);
    }

    // Agregar / actualizar
    void agregar(const string& clave, const Atributos& atributos) {
        int indice = hashFunction(clave);
        Nodo* actual = tabla[indice];

        while (actual != NULL) {
            if (actual->clave == clave) {
                actual->atributos = atributos;
                cout << "Identificador actualizado.\n";
                return;
            }
            actual = actual->siguiente;
        }

        Nodo* nuevo = new Nodo(clave, atributos);
        nuevo->siguiente = tabla[indice];
        tabla[indice] = nuevo;

        cout << "Identificador agregado.\n";
    }

    // Buscar
    Atributos* buscar(const string& clave) {
        int indice = hashFunction(clave);
        Nodo* actual = tabla[indice];

        while (actual != NULL) {
            if (actual->clave == clave) {
                return &actual->atributos;
            }
            actual = actual->siguiente;
        }
        return NULL;
    }

    // Eliminar
    bool eliminar(const string& clave) {
        int indice = hashFunction(clave);
        Nodo* actual = tabla[indice];
        Nodo* anterior = NULL;

        while (actual != NULL) {
            if (actual->clave == clave) {
                if (anterior == NULL)
                    tabla[indice] = actual->siguiente;
                else
                    anterior->siguiente = actual->siguiente;

                delete actual;
                cout << "Identificador eliminado.\n";
                return true;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        cout << "Identificador no encontrado.\n";
        return false;
    }

    // Mostrar tabla
    void mostrarTabla() const {
        cout << "\n=== TABLA DE SÍMBOLOS ===\n";
        for (int i = 0; i < capacidad; i++) {
            cout << "[" << i << "]: ";
            Nodo* actual = tabla[i];
            while (actual != NULL) {
                cout << "(" << actual->clave
                     << " | tipo=" << actual->atributos.tipo
                     << ", ambito=" << actual->atributos.ambito
                     << ", linea=" << actual->atributos.linea
                     << ") -> ";
                actual = actual->siguiente;
            }
            cout << "NULL\n";
        }
    }
};

// ================================
// Menú Principal
// ================================
int main() {
    TablaHash tabla(10);
    int opcion;

    do {
        cout << "\n===== MENU TABLA DE SIMBOLOS =====\n";
        cout << "1. Agregar identificador\n";
        cout << "2. Buscar identificador\n";
        cout << "3. Eliminar identificador\n";
        cout << "4. Mostrar tabla\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string clave, tipo, valor, ambito;
            int linea;

            cout << "Clave (nombre del identificador): ";
            getline(cin, clave);

            cout << "Tipo: ";
            getline(cin, tipo);

            cout << "Valor: ";
            getline(cin, valor);

            cout << "Ámbito: ";
            getline(cin, ambito);

            cout << "Linea declaracion: ";
            cin >> linea;
            cin.ignore();

            tabla.agregar(clave, Atributos(tipo, valor, ambito, linea));
        }

        else if (opcion == 2) {
            string clave;
            cout << "Ingrese la clave a buscar: ";
            getline(cin, clave);

            Atributos* encontrado = tabla.buscar(clave);

            if (encontrado != NULL) {
                cout << "\nIdentificador encontrado:\n";
                cout << "Tipo: " << encontrado->tipo << endl;
                cout << "Valor: " << encontrado->valor << endl;
                cout << "Ámbito: " << encontrado->ambito << endl;
                cout << "Línea: " << encontrado->linea << endl;
            } else {
                cout << "Identificador no encontrado.\n";
            }
        }

        else if (opcion == 3) {
            string clave;
            cout << "Ingrese la clave a eliminar: ";
            getline(cin, clave);

            tabla.eliminar(clave);
        }

        else if (opcion == 4) {
            tabla.mostrarTabla();
        }

    } while (opcion != 5);

    cout << "Saliendo...\n";
    return 0;
}
