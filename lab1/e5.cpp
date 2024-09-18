#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class FechaYHora {
private:
    tm fechaHora;
public:
    FechaYHora() {
        time_t t = time(nullptr);
        fechaHora = *localtime(&t);
    }
    void mostrarFechaHora() const {
        cout << fechaHora.tm_mday << "/" << fechaHora.tm_mon + 1 << "/"
             << fechaHora.tm_year + 1900 << " " << fechaHora.tm_hour << ":"
             << fechaHora.tm_min << endl;
    }
    void posponerDias(int dias) {
        fechaHora.tm_mday += dias;
        mktime(&fechaHora);
    }
    void adelantarDias(int dias) {
        fechaHora.tm_mday -= dias;
        mktime(&fechaHora);
    }
};
class CitaMedica {
private:
    int numCita;
    string nombrePaciente;
    FechaYHora fechaYHora;
    int numAsegurado;
    string motivos[5];
    int numMotivos;
public:
    CitaMedica(int _numCita, const string& _nombrePaciente, int _numAsegurado)
        : numCita(_numCita), nombrePaciente(_nombrePaciente), numAsegurado(_numAsegurado), numMotivos(0) {}
    void posponerCita(int dias) {
        fechaYHora.posponerDias(dias);
    }
    void adelantarCita(int dias) {
        fechaYHora.adelantarDias(dias);
    }
    void agregarMotivo(const string& motivo) {
        if (numMotivos < 5) {
            motivos[numMotivos] = motivo;
            numMotivos++;
        } else {
            cout << "No se pueden agregar mas motivos, el limite es 5" << endl;
        }
    }
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
    cita.agregarMotivo("Consulta general");
    cita.agregarMotivo("Chequeo de presion arterial");
    cita.mostrarCita();
    cout << endl;
    cita.posponerCita(3);
    cout << "Cita pospuesta por 3 dias" << endl;
    cita.mostrarCita();
    cout << endl;
    cita.adelantarCita(2);
    cout << "Cita adelantada por 2 dias" << endl;
    cita.mostrarCita();
    return 0;
}
