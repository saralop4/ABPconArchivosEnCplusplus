#include <iostream>//para usar el cout y el cin
#include <cstdlib> //para usar el system "pause"
#include <vector>  // para usar listas
#include <windows.h> // para usar la funcion beep

using namespace std;
//-------funciones---------------------
int mostrarmenu();
void consultar_pacientes_registrados();
//--------estructuras---------------------------
struct Asignar {
	string nomb;
	int ident;
	string fecha;
	string hora;
	void mostrar_datoss() {
		cout << "==========================================" << endl;
		cout << "--------PACIENTE-------" << endl;
		cout << "NOMBRE: " << nomb << endl;
		cout << "IDENTIFICACION: " << ident << endl;
		cout << "FECHA: " << fecha << endl;
		cout << "HORA: " << hora << endl;
	}
};
struct Valorconsul {
	float con;
	float sin;
};
struct Tipoconsulta {
	int consul;
};
struct medico {
	string nombre;
	string titulo;
};
struct Paciente {
	int id;
	string nombre;
	int edad;
	string fecha_naci;
	string genero;
	string correo;
	string cel1, cel2;
	string descrip;
	struct medico dir_medic; // estructura anidada
	struct Tipoconsulta tipoconsul;
	struct Valorconsul val;
	void mostrar_datos() {  //usamos esta funcion para mostrar los datos de Pacientes
		cout << "==========================================" << endl;
		cout << "--------PACIENTE-------" << endl;
		cout << "IDENTIFICACION: " << id << endl;
		cout << "NOMBRE COMPLETO: " << nombre << endl;
		cout << "EDAD: " << edad << endl;
		cout << "FECHA DE NACIMIENTO: " << fecha_naci << endl;
		cout << "GENERO: " << genero << endl;
		cout << "CELULAR 1: " << cel1 << endl;
		cout << "CELULAR 2: " << cel2 << endl;
		cout << "DESCRIPCION: " << descrip << endl;
		cout << "-------DOCTOR-------- " << endl;
		cout << "MEDICO: " << dir_medic.nombre << endl;
		cout << "ESPECIALIDAD: " << dir_medic.titulo << endl;

	}
};

	int opc, respuesta, i = 0, j = 1;
	double var1 = 0, var2 = 0;
	float ganancias = 0;
	int atendidos = 0;
	
	vector<Asignar> listacitas;
	Asignar asig;
	vector<Paciente> listaproductos; //creamos una lista
	Paciente p; //declaramos una variable p de tipo Paciente
//--------------------------------------------------
int main() {

	p.dir_medic.nombre = "JAVIER SANJUANELO ROBLES"; // inicializamos las varibles de structuras nombre y titulo
	p.dir_medic.titulo = "GINECOLOGO"; // y ala vez se almacena en la lista
	p.val.con = 160000;
	p.val.sin = 120000;






	cout << "**************************************" << endl;
	cout << "***BIENVENIDO A MEDICAL SOFT S.J.F***" << endl;
	cout << "***************************************" << endl;

	do {
		opc = mostrarmenu(); //segun lo que se almacene aqui se ejecuta el switch
		system("cls"); //limpiar pantalla

		 /*usamos un bucle para nuestra condicion multiple para facilitar al admin
		 realizar varias operaciones sin que el programa se cierre y tenga que volver a ingresar*/

		switch (opc) { // utilizamos este condicional multiple para realizar una operacion segun lo que se necesite


		case 1:
			//este caso es para registrar los pacientes que ingresan en el dia
			cout << "===========================================" << endl;
			cout << "===========REGISTRO DE PACIENTES===========" << endl;
			cout << "===========================================" << endl;
			//dir_medic.nombre="javier sanjuanelo robles";

			do {

				cout << "-------PACIENTE #: " << j++ << "-------\n";
				Beep(500, 500);
				cout << "Identificacion: ";
				cin >> p.id; // se usa el vector pacientes y en la posicion i se guarda la identificacion
				cin.ignore(); // usamos esta funcion para limpiar el buffer

				cout << "Nombre Completo: ";
				getline(cin, p.nombre);

				cout << "Edad: ";
				cin >> p.edad;
				cin.ignore();

				cout << "Fecha Nacimiento: ";
				getline(cin, p.fecha_naci);

				cout << "Genero: ";
				getline(cin, p.genero);

				cout << "Correo: ";
				getline(cin, p.correo);

				cout << "Celular 1: ";
				cin >> p.cel1;


				cout << "Celular 2: ";
				cin >> p.cel2;
				cin.ignore();

				cout << "Descripcion: ";
				getline(cin, p.descrip);

				cout << "-------DOCTOR-------- " << endl;
				cout << "MEDICO: " << p.dir_medic.nombre << endl;
				cout << "ESPECIALIDAD: " << p.dir_medic.titulo << endl;


				do {
					cout << "--------TIPO DE CONSULTA-------\n";
					cout << "1. General Con Radiografia: \n";
					cout << "2. General Sin Radiografia: \n";
					cout << " Escoja 1/2 : "; cin >> p.tipoconsul.consul;
					cout << "\n";
				} while (p.tipoconsul.consul != 1 && p.tipoconsul.consul != 2);
				cout << "--------REGISTRAR PAGO--------\n";
				if (p.tipoconsul.consul == 1) {// esta condicion es para validar segun el tipo de consulta será el cobro o valor de la consulta

					cout << "Valor de la consulta: $" << p.val.con << endl;

				}
				else if (p.tipoconsul.consul == 2) {
					cout << "Valor de la consulta: $" << p.val.sin << endl;
				}
				listaproductos.push_back(p);
				cout << "\n";
				cout << "-------------------------------\n";
				cout << "DESEA REGISTRAR OTRO PACIENTE?" << endl;
				cout << " 1.SI/ 2. NO/ : ";   //usamos este pequeño menu para que el admin pueda registrar otro paciente o no, sin necesidad de salirse del programa
				cin >> respuesta;
				cout << "-------------------------------\n";



			} while (respuesta == 1); // el registro de pacientes se repetira hasta que el admin quiera lo contrario
			break;
		case 2:

			//system("cls");


			cout << "=============================================\n";
			cout << "===========ASIGNAR CITA DE CONTROL===========\n";
			cout << "=============================================\n";
			do {

				cout << "********PACIENTE********\n";
				Beep(500, 500);

				cout << "NOMBRE COMPLETO: ";
				cin.ignore();
				getline(cin, asig.nomb); // se usa el vector pacientes y en la posicion i se guarda la identificacion


				cout << "IDENTIFICACION: ";
				cin.ignore();
				cin >> asig.ident;


				cout << "FECHA: ";
				cin.ignore(); // usamos esta funcion para limpiar el buffer
				getline(cin, asig.fecha);

				cout << "HORA: ";
				getline(cin, asig.hora);


				listacitas.push_back(asig);
				cout << "\n";
				cout << "-------------------------------\n";
				cout << "DESEA REGISTRAR OTRO PACIENTE?" << endl;
				cout << " 1.SI/ 2. NO/ : ";   //usamos este pequeño menu para que el admin pueda registrar otro paciente o no, sin necesidad de salirse del programa
				cin >> respuesta;

				cout << "-------------------------------\n";

			} while (respuesta == 1);

			break;

		case 3:
		consultar_pacientes_registrados();


			break;
		case 4:
			cout << "=====================================================\n";
			cout << "===========CONSULTAR CITAS REGISTRADAS===============\n";
			cout << "=====================================================\n";
			for (int i = 0; i < listacitas.size(); i++) { //size permite ejecutarse segun la cantidad que tenga la lista
				Asignar asig = listacitas[i];
				asig.mostrar_datoss();
			}

			break;

		case 5:
			Beep(500, 500);
			Beep(750, 450);
			Beep(900, 300);
			Beep(500, 200);
			Beep(750, 200);
			Beep(900, 100);
			Beep(500, 100);
			Beep(750, 100);
			Beep(900, 100);
			Beep(500, 50);
			Beep(750, 50);
			Beep(1000, 900);
			cout << "--PROGRAMA CERRADO!" << endl;

			break;

		default: // Otra opcion: no válida
			cout << "DEBE DIGITAR UNA OPCION VALIDA 1/5" << endl;
			break;
		} //-- cierre del switch
	} while (opc != 5);

	system("pause");
	return 0;
}

int mostrarmenu()
{
	int opc;
	bool exito;
	do {  // usamos este menu para que el admin puedsa ver graficamente lo queu desea realizar y asi pueda escoger

		cout << "------------------------" << endl;
		cout << "----------MENU----------" << endl;
		cout << "------------------------" << endl;
		cout << "1. Registrar Paciente" << endl;
		cout << "2. Asignar Cita de Control" << endl;
		cout << "3. Consultar Pacientes" << endl;
		cout << "4. Consultar Citas" << endl;
		cout << "5. Salir" << endl;
		cout << "Digite una opcion 1/5: ";
		cin >> opc;

		if (opc < 1 && opc > 5) {
			exito = false;
		}
		else {
			exito = true;
		}
	} while (exito == false);

	return opc;
}


void consultar_pacientes_registrados() {
    	//int j=0;
			cout << "=====================================================\n";
			cout << "===========CONSULTAR PACIENTES REGISTRADOS===========\n";
			cout << "=====================================================\n";
			// este caso solo mostrará paciente si realmente estan ingresados
			//este caso mostrara los pacientes registrados en el dia y finalmente arroja una pequeña factura

			if (listaproductos.empty() == true) {

				cout << "**AUN NO EXISTEN PACIENTES REGISTRADOS**";
			}
			else
			{

				for (int i = 0; i < listaproductos.size(); i++) { //size permite ejecutarse segun la cantidad que tenga la lista
					Paciente p = listaproductos[i];
					p.mostrar_datos();


					cout << "--------TIPO DE CONSULTA-------\n";
					if (p.tipoconsul.consul == 1) {
						cout << "TIPO DE CONSULTA: General Con Radiografia " << endl;
						cout << "--------PAGO--------\n";
						cout << "VALOR DE LA CONSULTA: $" << p.val.con << endl; // aqui mostramos lo que se registro segun  la posicion de la iteracion que se realizo
						var1 = var1 + p.val.con;
						cout << "VALOR de var 1 " << var1 << endl;
					}
					else if (p.tipoconsul.consul == 2) {
						cout << "TIPO DE CONSULTA: General Sin Radiografia " << endl;
						cout << "--------PAGO--------\n";
						cout << "VALOR DE LA CONSULTA: $" << p.val.sin << endl;  // aqui se debe digitar el valor de la consulta
						var2 = var2 + p.val.sin;
						cout << "VALOR de var 2: " << var2 << endl;
					}
					ganancias = var1 + var2;
					//++atendidos;
				}

				cout << "===========REPORTE TOTAL===========\n";
				cout << "VALOR TOTAL DE GANACIAS: " << ganancias << endl;
				cout << "TOTAL DE PACIENTES ATENDIDOS: " << listaproductos.size() << endl;

			}
    }
