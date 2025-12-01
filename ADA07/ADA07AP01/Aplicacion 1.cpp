#include <iostream>
#include <string>

using namespace std;

// --- 1. Estados ---
const int VACIO = 0;
const int OCUPADO = 1;
const int BORRADO = 2; 

// --- 2. Estructuras de Datos ---

struct Estudiante {
    int matricula;
    string nombre;
    string carrera;

    Estudiante() {
        matricula = -1;
        nombre = "";
        carrera = "";
    }

    Estudiante(int m, string n, string c) {
        matricula = m;
        nombre = n;
        carrera = c;
    }
};

struct Celda {
    Estudiante estudiante;
    int estado;

    Celda() {
        estado = VACIO; 
    }
};

// --- 3.Tabla Hash ---

class RegistroEstudiantes {
private:
    Celda* tabla;        
    int CAPACIDAD_TABLA;
    int totalRegistrados;

public:
    RegistroEstudiantes(int capacidad) {
        this->CAPACIDAD_TABLA = capacidad;
        this->totalRegistrados = 0;
        
        tabla = new Celda[CAPACIDAD_TABLA]; 
    }

    // Función Hash: H(k) = K mod N
    int funcionHash(int matricula) {
        return matricula % CAPACIDAD_TABLA;
    }

    bool agregarEstudiante(int matricula, string nombre, string carrera) {
        if (totalRegistrados >= CAPACIDAD_TABLA) {
            cout << "Error: La tabla esta llena." << endl;
            return false;
        }

        int indice = funcionHash(matricula);
        int indiceInicial = indice;

        // Sondeo Lineal
        while (tabla[indice].estado == OCUPADO) {
            if (tabla[indice].estudiante.matricula == matricula) {
                cout << "Error: La matricula " << matricula << " ya existe." << endl;
                return false;
            }
            indice++;
            if (indice == CAPACIDAD_TABLA) indice = 0;
            if (indice == indiceInicial) return false;
        }

        tabla[indice].estudiante = Estudiante(matricula, nombre, carrera);
        tabla[indice].estado = OCUPADO;
        totalRegistrados++;
        cout << "--> Estudiante registrado con exito en la posicion " << indice << "." << endl;
        return true;
    }

    void buscarEstudiante(int matricula) {
        int indice = funcionHash(matricula);
        int indiceInicial = indice;

        while (tabla[indice].estado != VACIO) {
            if (tabla[indice].estado == OCUPADO && tabla[indice].estudiante.matricula == matricula) {
                cout << "\n--- ESTUDIANTE ENCONTRADO ---" << endl;
                cout << "Posicion: " << indice << endl;
                cout << "Matricula: " << tabla[indice].estudiante.matricula << endl;
                cout << "Nombre:    " << tabla[indice].estudiante.nombre << endl;
                cout << "Carrera:   " << tabla[indice].estudiante.carrera << endl;
                cout << "-----------------------------" << endl;
                return;
            }
            indice++;
            if (indice == CAPACIDAD_TABLA) indice = 0;
            if (indice == indiceInicial) break;
        }

        cout << "--> No se encontro ningun estudiante con matricula " << matricula << "." << endl;
    }

    void eliminarEstudiante(int matricula) {
        int indice = funcionHash(matricula);
        int indiceInicial = indice;

        while (tabla[indice].estado != VACIO) {
            if (tabla[indice].estado == OCUPADO && tabla[indice].estudiante.matricula == matricula) {
                tabla[indice].estado = BORRADO; // Solo marcamos como borrado
                totalRegistrados--;
                cout << "--> Estudiante con matricula " << matricula << " eliminado correctamente." << endl;
                return;
            }
            indice++;
            if (indice == CAPACIDAD_TABLA) indice = 0;
            if (indice == indiceInicial) break;
        }

        cout << "--> Error: No se puede eliminar, la matricula no existe." << endl;
    }

    void mostrarTabla() {
        cout << "\n--- ESTADO DE LA MEMORIA (TABLA HASH) ---" << endl;
        for (int i = 0; i < CAPACIDAD_TABLA; i++) {
            cout << "[" << i << "] ";
            if (tabla[i].estado == VACIO) {
                cout << "LIBRE";
            } else if (tabla[i].estado == OCUPADO) {
                cout << "OCUPADO: " << tabla[i].estudiante.matricula << " - " << tabla[i].estudiante.nombre;
            } else {
                cout << "BORRADO (Disponible)";
            }
            cout << endl;
        }
        cout << "------------------------------------------\n";
    }

    ~RegistroEstudiantes() {
        delete[] tabla;
    }
};

int main() {
    int tamanioTabla;
    cout << "Bienvenido al Sistema de Gestion Escolar." << endl;
    cout << "Ingrese el tamanio de la tabla: ";
    cin >> tamanioTabla;

    RegistroEstudiantes sistema(tamanioTabla);

    int opcion;
    do {
        cout << "\n\n======= MENU PRINCIPAL =======" << endl;
        cout << "1. Agregar Estudiante" << endl;
        cout << "2. Buscar Estudiante" << endl;
        cout << "3. Eliminar Estudiante" << endl;
        cout << "4. Ver Estado de la Tabla" << endl;
        cout << "5. Salir" << endl;
        cout << "==============================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        int matTemp;
        string nomTemp, carrTemp;

        switch (opcion) {
            case 1: // Agregar
                cout << "\n--- NUEVO REGISTRO ---" << endl;
                cout << "Ingrese Matricula (numeros): ";
                cin >> matTemp;
                
                cin.ignore(); 
                
                cout << "Ingrese Nombre Completo: ";
                getline(cin, nomTemp);
                
                cout << "Ingrese Carrera: ";
                getline(cin, carrTemp);
                
                sistema.agregarEstudiante(matTemp, nomTemp, carrTemp);
                break;

            case 2: // Buscar
                cout << "\n--- BUSQUEDA ---" << endl;
                cout << "Ingrese Matricula a buscar: ";
                cin >> matTemp;
                sistema.buscarEstudiante(matTemp);
                break;

            case 3: // Eliminar
                cout << "\n--- BAJA DE ALUMNO ---" << endl;
                cout << "Ingrese Matricula a eliminar: ";
                cin >> matTemp;
                sistema.eliminarEstudiante(matTemp);
                break;

            case 4: // Ver Tabla
                sistema.mostrarTabla();
                break;

            case 5: // Salir
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 5);

    return 0;
}