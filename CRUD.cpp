#include <iostream>
#include <fstream>

using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1, nota2, nota3, nota4;
    float promedio;
    string resultado;
};

void calcularPromedio(Estudiante* estudiante) {
    estudiante->promedio = (estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4) / 4.0;
    estudiante->resultado = (estudiante->promedio > 60) ? "Aprobado" : "Reprobado";
}

int main() {
    ofstream archivo("notas.dat", ios::binary | ios::app);
    ifstream lectura("notas.dat", ios::binary);

    int opcion;
    do {
        cout << "1. Crear estudiante" << endl;
        cout << "2. Leer estudiantes" << endl;
        cout << "3. Actualizar estudiante" << endl;
        cout << "4. Eliminar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Estudiante nuevoEstudiante;
                cout << "Ingrese el ID: ";
                cin >> nuevoEstudiante.id;
                cout << "Ingrese los nombres: ";
                cin >> nuevoEstudiante.nombres;
                cout << "Ingrese los apellidos: ";
                cin >> nuevoEstudiante.apellidos;
                cout << "Ingrese la nota 1: ";
                cin >> nuevoEstudiante.nota1;
                cout << "Ingrese la nota 2: ";
                cin >> nuevoEstudiante.nota2;
                cout << "Ingrese la nota 3: ";
                cin >> nuevoEstudiante.nota3;
                cout << "Ingrese la nota 4: ";
                cin >> nuevoEstudiante.nota4;
                calcularPromedio(&nuevoEstudiante);
                archivo.write(reinterpret_cast<char*>(&nuevoEstudiante), sizeof(Estudiante));
                break;
            }
            case 2: {
                Estudiante estudiante;
                while (lectura.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
                    cout << "ID: " << estudiante.id << endl;
                    cout << "Nombres: " << estudiante.nombres << endl;
                    cout << "Apellidos: " << estudiante.apellidos << endl;
                    cout << "Nota 1: " << estudiante.nota1 << endl;
                    cout << "Nota 2: " << estudiante.nota2 << endl;
                    cout << "Nota 3: " << estudiante.nota3 << endl;
                    cout << "Nota 4: " << estudiante.nota4 << endl;
                    cout << "Promedio: " << estudiante.promedio << endl;
                    cout << "Resultado: " << estudiante.resultado << endl;
                    cout << "-------------------" << endl;
                }
                break;
            }
            case 3: {
                int idActualizar;
                cout << "Ingrese el ID del estudiante a actualizar: ";
                cin >> idActualizar;
                Estudiante estudiante;
                ofstream temporal("temporal.dat", ios::binary);
                while (lectura.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
                    if (estudiante.id == idActualizar) {
                        cout << "Ingrese el nuevo promedio: ";
                        cin >> estudiante.promedio;
                        if (estudiante.promedio > 60) {
                            estudiante.resultado = "Aprobado";
                        } else {
                            estudiante.resultado = "Reprobado";
                        }
                    }
                    temporal.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
                }
                lectura.close();
                temporal.close();
                remove("notas.dat");
                rename("temporal.dat", "notas.dat");
                lectura.open("notas.dat", ios::binary);
                break;
            }
            case 4: {
                int idEliminar;
                cout << "Ingrese el ID del estudiante a eliminar: ";
                cin >> idEliminar;
                Estudiante estudiante;
                ofstream temporal("temporal.dat", ios::binary);
                while (lectura.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
                    if (estudiante.id != idEliminar) {
                        temporal.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
                    }
                }
                lectura.close();
                temporal.close();
                remove("notas.dat");
                rename("temporal.dat", "notas.dat");
                lectura.open("notas.dat", ios::binary);
                break;
            }
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
        }
    } while (opcion != 5);

    archivo.close();
    lectura.close();

    return 0;
}

