#include <iostream>
#include <string>
#include <ctime>
using namespace std;
//struct fecha y hora
struct FechaYHora {
    tm fechaHora;
    //constructor para fecha y hora actual
    void establecerFechaHoraActual() {
        time_t t = time(nullptr);
        fechaHora = *localtime(&t);
    }
    //mostrar la fecha y hora
    void mostrarFechaHora() const {
        cout << fechaHora.tm_mday << "/" << fechaHora.tm_mon + 1 << "/"
             << fechaHora.tm_year + 1900 << " " << fechaHora.tm_hour << ":"
             << fechaHora.tm_min << endl;
    }
    //posponer la cita
    void posponerDias(int dias) {
        fechaHora.tm_mday += dias;
        mktime(&fechaHora);  // Recalcular la fecha
    }
    void adelantarDias(int dias) {
        fechaHora.tm_mday -= dias;
        mktime(&fechaHora); 
    }
};
//struct para cita medica
struct CitaMedica {
    int numCita;
    string nombrePaciente;
    FechaYHora fechaYHora;
    int numAsegurado;
    string motivos[5];  // Arreglo de 5 motivos
    int numMotivos;
    //constructor para inicializar la cita medica
    CitaMedica(int _numCita, string _nombrePaciente, int _numAsegurado)
        : numCita(_numCita), nombrePaciente(_nombrePaciente), numAsegurado(_numAsegurado), numMotivos(0) {
        fechaYHora.establecerFechaHoraActual();
    }
    //pospone la cita
    void posponerCita(int dias) {
        fechaYHora.posponerDias(dias);
    }
    //adelanta la cita
    void adelantarCita(int dias) {
        fechaYHora.adelantarDias(dias);
    }
    //agrega un motivo
    void agregarMotivo(const string& motivo) {
        if (numMotivos < 5) {
            motivos[numMotivos] = motivo;
            numMotivos++;
        } else {
            cout << "No se pueden agregar mas motivos, el limite es 5" << endl;
        }
    }
    //mostrar detalles de la cita
    void mostrarCita() const {
        cout << "Numero de Cita: " << numCita << endl;
        cout << "Nombre del Paciente: " << nombrePaciente << endl;
        cout << "Numero de Asegurado: " << numAsegurado << endl;
        cout << "Fecha y Hora de la Cita: ";
        fechaYHora.mostrarFechaHora();
        cout << "Motivos de la Cita: ";
        for (int i = 0; i < numMotivos; i++) {
            cout << motivos[i] << "; ";
        }
        cout << endl;
    }
};
int main() {
    // Crear una cita medica
    CitaMedica cita(12345, "Juan Perez", 987654);
    // Agregar motivos
    cita.agregarMotivo("Consulta general");
    cita.agregarMotivo("Chequeo de presion arterial");
    // Mostrar la cita
    cita.mostrarCita();
    cout << endl;
    // Posponer la cita por 3 dias
    cita.posponerCita(3);
    cout << "Cita pospuesta por 3 dias" << endl;
    cita.mostrarCita();
    cout << endl;
    // Adelantar la cita por 2 dias
    cita.adelantarCita(2);
    cout << "Cita adelantada por 2 dias" << endl;
    cita.mostrarCita();
    return 0;
}
