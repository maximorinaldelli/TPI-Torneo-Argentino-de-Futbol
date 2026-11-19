#include <iostream>
#include <cstring>

#include "Menu.h"
#include "Jugador.h"
#include "Club.h"
#include "Partido.h"
#include "Cancha.h"
#include "Gol.h"
#include "Contrato.h"

#include "ArchivoJugadores.h"
#include "ArchivoClubes.h"
#include "ArchivoPartidosh.h"

using namespace std;

void Menu::menuPrincipal()
{
        system("cls");
cout<<"------------------- MENU PRINCIPAL -------------------"<<endl;
cout<<"1.MENU JUGADORES"<<endl;
cout<<"2.MENU CLUBES"<<endl;
cout<<"3.MENU CONTRATOS"<<endl;
cout<<"4.MENU CANCHAS"<<endl;
cout<<"5.MENU PARTIDOS"<<endl;
cout<<"6.MENU GOLES"<<endl;
cout<<"7.MENU REPORTES"<<endl;
cout<<"0.SALIR"<<endl;
cout<<"---------------------------------------------------"<<endl;
}
void Menu::menuJugadores()
{

int opc;
    system("cls");
    do{
cout<<"------------------- MENU JUGADORES -------------------"<<endl;
cout<<"1.CARGAR JUGADORES"<<endl;
cout<<"2.MOSTRAR JUGADORES"<<endl;
cout<<"3.BUSCAR JUGADOR"<<endl;
cout<<"4.MODIFICAR JUGADOR"<<endl;
cout<<"5.DAR DE BAJA JUGADOR"<<endl;
cout<<"0.VOLVER"<<endl;
cout<<"---------------------------------------------------"<<endl;
cout<<"INGRESE UNA OPCION:"<<endl;
cin>>opc;

switch(opc)
{
case 1:{
    Jugador reg;
    ArchivoJugadores archireg;

    reg.cargar(0);
    system("cls");
    if(archireg.guardarRegistro(reg))
    {
        cout<< "JUGADOR GUARDADO CORRECTAMENTE."<<endl;
    }else{
    cout<< "ERROR AL CARGAR JUGADOR."<<endl;
    }
    system("pause");
    break;
    }

case 2:{
    Jugador reg;
    ArchivoJugadores archireg;

    system("cls");

    int cant = archireg.contarRegistros();
    if(cant == 0)
    {
        cout<<"Archivo de jugadores vacio"<<endl;
        system("pause");
        break;
    }

    for(int i=0;i<cant;i++)
    {
        reg = archireg.leerRegistro(i);
        if(reg.getEstado()){
        reg.mostrar();
        cout<<endl;
        }
    }

    system("pause");
    break;
}
case 3:
    {
    ArchivoJugadores archireg;
    Jugador reg;
    int id;

    cout << "INGRESE EL ID DE JUGADOR BUSCADO: "<<endl;
    cin>>id;
    int res = archireg.buscarPorId(id);
    if(res != -1)
    {
        cout<< "JUGADOR ENCONTRADO: "<<endl;
        reg = archireg.leerRegistro(res);
        reg.mostrar();
        system("pause");
    }else{
    cout<< "JUGADOR NO ENCONTRADO"<<endl;
    system("pause");
    break;
    }

    break;
    }

case 4:
    {
        ArchivoJugadores archireg;
        Jugador reg;
        int id;

        cout<< "INGRESE ID DEL JUGADOR A MODIFICAR:"<<endl;
        cin>>id;

        int pos = archireg.buscarPorId(id);
        if(pos != -1)
        {
            reg = archireg.leerRegistro(pos);

            cout<< "DATOS ACTUALES: "<<endl;

            reg.mostrar();
            system("pause");
            system("cls");

            reg.cargar(1);
            bool res = archireg.modificaRegistro(reg,pos);

            if(res)
            {
            system("cls");
            cout<< "REGISTRO MODIFICADO CORRECTAMENTE"<<endl;
            system("pause");
            break;
            }else{
            system("cls");
            cout<< "ERROR AL MODIFICAR EL ARCHIVO"<<endl;
            system("pause");
            }
        }else{
        system("cls");
        cout<<"NO SE ENCONTRO REGISTRO CON ESE ID."<<endl;
        system("pause");
        }
        break;
    }
    case 5:{

    ArchivoJugadores archireg;

    cout<<"INGRESE EL ID A DAR DE BAJA"<<endl;
    int id;
    cin>>id;
   if( archireg.bajaLogica(id))
   {
       system("cls");
       cout<< "DADO DE BAJA CORRECTAMENTE"<<endl;
        system("pause");
   }else{
        system("cls");
       cout<< "ERROR AL DAR DE BAJA"<<endl;
        system("pause");
   }

    }
    break;
}
}while(opc!=0);
    }


void Menu::ejecutar()
{

}





