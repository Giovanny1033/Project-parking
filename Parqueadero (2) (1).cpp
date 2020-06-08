#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <ctime>
#include <string>

using namespace std;

struct Vehiculo {
    time_t Ingreso;
    time_t Salida;
    bool Estado; //Identifica si el camnpo esta vacio (true) o lleno (false)
    string Placa;
    string Nombre;
    int Telefono;
    Vehiculo(){
    	
    	Estado = true;
    	
	}
    
}
Vehiculo[40];

struct Servicio
{
    int cantidadFraccion;
    double valorFraccion;
	void RegistrarServicio();
	int VerificarCampos();
	void DescargarServicio();
	bool VerificarPlacas(string);
	void MostrarParqueaderos();
	Servicio(){
		
		cantidadFraccion = 1;
		valorFraccion = 80;
		
	}
	
};

int opc;
//void vehiculo::	
int main() {
    Servicio Planilla;
   
    do { 
        cout << "-----------------------------------------" <<endl;
        cout << "Bienvenido al parqueadero." <<endl;
        cout << "-----------------------------------------" <<endl;
        cout << "1. Entrar vehiculo " << endl;
        cout << "2. Sacar vehiculo " << endl;
        cout << "3. Mostrar campos de parqueo " << endl;
        cout << "4. Salir " << endl << endl;
        
        cout<< "Indique una opcion: ";
        cin >> opc;
        switch (opc) {
            int Tiempo, Valor;
        case 1:
            Planilla.RegistrarServicio();
            break;

        case 2:
            Planilla.DescargarServicio();
            break;

        case 3:
            Planilla.MostrarParqueaderos();
            break;
            
        case 4:
            exit(0);
            break;
        }
    } while (opc != 4);

    return 0;
}

int Servicio::VerificarCampos() {
    int campo = 0;
    bool estado;
    
    do {
        campo++;
        estado = Vehiculo[campo].Estado;
    } while (campo < 39 && !estado);
    
    if (!estado) {
        campo = 0;
    }
    
    return campo;
}

// returnar true si esta repetida y false si no se encontro la placa.
bool Servicio::VerificarPlacas(string placa) {
    int j = 0;
    bool encontrado = false;
    
    do {
        j++;
        if (Vehiculo[j].Placa == placa) {
           encontrado = true; 
        }
    } while(j < 39);

    return encontrado;
}

void Servicio::MostrarParqueaderos() {
    for(int i=1; i<=40; i++) {
        cout << "Campo: " << i << endl;
        
        if(Vehiculo[i].Estado){
            cout << "Vacio" << endl;    
        } else {
            cout << "Ocupado" <<endl;
        }
        
        cout << "-----------------------------------------" << endl;
    }
}

void Servicio::RegistrarServicio() {
    string placa = "";
    bool placaExiste = false;
    
    int campo = VerificarCampos();
    
    if (campo == 0) {
        cout << "No hay cupos disponibles" << endl;    
    } 
    else
    {
        fflush(stdin);
        cout << " - Introduzca la placa: ";
        cin >>  placa;
        
        placaExiste = VerificarPlacas(placa);
        
        if (!placaExiste) {
            Vehiculo[campo].Placa = placa;
            
            cout << "**** Por favor parquee en el campo: " << campo << endl;
            fflush(stdin);
            cout << " - Introduzca nombre del propietario: ";
            cin >>  Vehiculo[campo].Nombre;
            fflush(stdin);
            cout << " - Introduzca numero de telefono: ";
            cin >> Vehiculo[campo].Telefono;
            
            Vehiculo[campo].Ingreso = time(0);
            Vehiculo[campo].Estado = false;
            
            cout << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Recibo de parqueo" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Ingreso a parqueadero: " << ctime(&Vehiculo[campo].Ingreso) << endl;
            cout << "Campo de parqueo numero: " << campo << endl;
            cout << "Propietario: " << Vehiculo[campo].Nombre << endl;
            cout << "Placa: " << Vehiculo[campo].Placa << endl;
            cout << "Telefono: " << Vehiculo[campo].Telefono << endl;
        }
        else
        {
            cout<<"Placa ya existe \n";   
        }
    }
}

void Servicio::DescargarServicio() {
    bool encontrado = false;
    int z = 0;
    string placaId;
    double totalPagar = ((difftime(Vehiculo[z].Salida, Vehiculo[z].Ingreso)/60) / cantidadFraccion) * valorFraccion;
    
    fflush(stdin);
    cout << " - Indique la placa de su vehiculo: ";
    cin >> placaId;
    
    do {
        z++;
        
        if (Vehiculo[z].Placa == placaId) {
            encontrado = true;
            Vehiculo[z].Salida = time(0);
            //totalPagar = ((Vehiculo[z].Salida - Vehiculo[z].Ingreso) / cantidadFraccion) * valorFraccion; 
            totalPagar = 145;
            cout << "Parqueadero #: " << z << endl;
            cout << "Hora salida: " << ctime(&Vehiculo[z].Salida) << endl;
            Vehiculo[z].Estado=false;
        }
    } while(z < 39 && !encontrado);
    
    if (!encontrado) {
        cout << "Vehiculo no encontrado" << endl;
    }
    else
    {
        cout << "Debe pagar un total de: " << totalPagar << endl;
    }
}
