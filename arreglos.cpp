#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    
    int id[n];
    string nombres[n];
    string apellidos[n];
    float nota1[n], nota2[n], nota3[n], nota4[n];
    
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese id de estudiante " << i+1 << ": ";
        cin >> id[i];
        cout << "Ingrese nombre del estudiante " << i+1 << ": ";
        cin >> nombres[i];
        cout << "Ingrese apellido del estudiante " << i+1 << ": ";
        cin >> apellidos[i];
        cout << "Ingrese  nota 1 del estudiante " << i+1 << ": ";
        cin >> nota1[i];
        cout << "Ingrese nota 2 del estudiante " << i+1 << ": ";
        cin >> nota2[i];
        cout << "Ingrese nota 3 del estudiante " << i+1 << ": ";
        cin >> nota3[i];
        cout << "Ingrese nota 4 del estudiante " << i+1 << ": ";
        cin >> nota4[i];
    }
    
    for (int i = 0; i < n; ++i) {
        float promedio = (nota1[i] + nota2[i] + nota3[i] + nota4[i]) / 4.0;
        cout << "Estudiante: " << nombres[i] << " " << apellidos[i] << " (ID: " << id[i] << ")" << endl;
        cout << "Promedio: " << promedio << endl;
        if (promedio > 60) {
            cout << "Estudiante aprobado!!" << endl;
        } else {
            cout << "Estudiante reprobado" << endl;
        }
    }
    
    return 0;
}

