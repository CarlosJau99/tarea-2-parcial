#include <iostream>

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
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante* estudiantes = new Estudiante[n];

    // Solicitar datos de cada estudiante
    for (int i = 0; i < n; ++i) {
        Estudiante* estudiante = estudiantes + i; // Apuntador a cada estudiante
        cout << "Ingrese el ID del estudiante " << i + 1 << ": ";
        cin >> estudiante->id;
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiante->nombres;
        cout << "Ingrese el apellido del estudiante " << i + 1 << ": ";
        cin >> estudiante->apellidos;
        cout << "Ingrese la nota 1 del estudiante " << i + 1 << ": ";
        cin >> estudiante->nota1;
        cout << "Ingrese la nota 2 del estudiante " << i + 1 << ": ";
        cin >> estudiante->nota2;
        cout << "Ingrese la nota 3 del estudiante " << i + 1 << ": ";
        cin >> estudiante->nota3;
        cout << "Ingrese la nota 4 del estudiante " << i + 1 << ": ";
        cin >> estudiante->nota4;

        // Calcular promedio y resultado
        calcularPromedio(estudiante);
    }

    // Mostrar información de cada estudiante
    for (int i = 0; i < n; ++i) {
        Estudiante* estudiante = estudiantes + i; // Apuntador a cada estudiante
        cout << "Estudiante: " << estudiante->nombres << " " << estudiante->apellidos << " (ID: " << estudiante->id << ")" << endl;
        cout << "Promedio: " << estudiante->promedio << endl;
        cout << "Resultado: " << estudiante->resultado << endl;
        cout << "-------------------" << endl;
    }

    delete[] estudiantes;

    return 0;
}

