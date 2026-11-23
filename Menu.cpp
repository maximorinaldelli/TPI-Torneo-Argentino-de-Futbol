#include <iostream>
#include <cstring>

#include "Menu.h"
#include "Jugador.h"
#include "Club.h"
#include "Partido.h"
#include "Cancha.h"
#include "Gol.h"
#include "Contrato.h"
#include "Cancha.h"

#include "ArchivoJugadores.h"
#include "ArchivoClubes.h"
#include "ArchivoPartidosh.h"
#include "ArchivoContratos.h"
#include "ArchivoCancha.h"

using namespace std;

void Menu::menuPrincipal()
{
        int opc;
        do{
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
cout<<"INGRESE UNA OPCION: ";
cin>>opc;

switch(opc)
{
case 1:
    menuJugadores();
    break;

case 2:
    menuClubes();
    break;

case 3:
   menuContratos();
    break;

case 4:
   menuCanchas();
    break;

case 5:
   /// menuPartidos();
    break;

case 6:
   /// menuGoles();
    break;

case 7:
    break;
case 0:
    return;
}
}while(opc!=0);
}

void Menu::menuJugadores()
{

int opc;
    do{
    system("cls");
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
        system("cls");
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
        system("cls");
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

            system("cls");
            reg.mostrar();
            system("pause");

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
    case 0:
        return;

}
}while(opc!=0);
    }


void Menu::menuClubes()
{
    ArchivoClubes archireg;
    int opc;
    do{
    system("cls");
cout<<"------------------- MENU CLUBES -------------------"<<endl;
cout<<"1.CARGAR CLUB"<<endl;
cout<<"2.MOSTRAR CLUBES"<<endl;
cout<<"3.BUSCAR CLUB"<<endl;
cout<<"4.MODIFICAR CLUB"<<endl;
cout<<"5.DAR DE BAJA CLUB"<<endl;
cout<<"0.VOLVER"<<endl;
cout<<"---------------------------------------------------"<<endl;
cout<<"INGRESE UNA OPCION:"<<endl;
cin>>opc;

switch(opc)
{
case 1:
    {
    system("cls");
    Club reg;
    reg.cargar(false);
    if(archireg.guardarRegistro(reg))
    {
        system("cls");
        cout<< "REGISTRO GUARDADO CORRECTAMENTE"<<endl;
        system("pause");
    }else{
    system("cls");
    cout<< "ERROR AL CARGAR EL RGISTRO"<<endl;
    system("pause");
    }
    break;
    }
case 2:
    {
    Club reg;
    system("cls");
    int cant = archireg.contarRegistro();

    if(cant == 0)
    {
        system("cls");
        cout<< "ARCHIVO DE CLUBES VACIO"<<endl;
        system("pause");
    }
    for(int i=0;i<cant;i++)
    {
        reg = archireg.leerRegistro(i);
        if(reg.getEstado())
        {
            reg.mostrar();
            cout<<endl;
        }
    }
    system("pause");
    break;
    }

case 3:
    {
    Club reg;
    cout<< "INGRESE EL ID SOLICITADO."<<endl;
    int id;
    cin>>id;
    int res = archireg.buscarXId(id);
    if(res != -1)
    reg = archireg.leerRegistro(res);
    {
        if(reg.getEstado() == true){
        system("cls");
        cout<< "CLUB ENCONTRADO: "<<endl;
        reg.mostrar();
        system("pause");
        }
    else{
    cout<< "CLUB NO ENCONTRADO O INHABILITADO"<<endl;
    }
    break;
    }
    }

case 4:
    {
        cout<< "INGRESE EL ID A MODIFICAR"<<endl;
        int id;
        cin>>id;
        int pos = archireg.buscarXId(id);
        Club reg;

        if(pos != -1)
        {
            reg = archireg.leerRegistro(pos);
                system("cls");
                cout<< "DATOS ACTUALES: "<<endl;
                reg.mostrar();
                system("pause");

                system("cls");
                reg.cargar(true);
                bool res = archireg.modificarRegistro(reg,pos);

                if(res)
                {
                    system("cls");
                    cout<< "REGISTRO MODIFICADO CORRECTAMENTE"<<endl;
                    system("pause");
                }else{
                system("cls");
                cout<< "ERROR AL MODIFICAR EL REGISTRO"<<endl;
                system("pause");
                }

        }
        break;
    }
case 5:
    {
    system("cls");
    cout<<"INGRESE EL ID A DAR DE BAJA"<<endl;
    int id;
    cin>>id;
    if(archireg.bajaLogica(id))
    {
        cout<< "CLUB DADO DE BAJA CORRECTAMENTE"<<endl;
        system("pause");
    }
    break;
}

case 0:
    return;
}
    }
    while(opc!=0);
}

void Menu::menuContratos()
{
    ArchivoContratos archireg;
    int opc;
    do{
system("cls");
cout<<"------------------- MENU CONTRATOS -------------------"<<endl;
cout<<"1.CARGAR CONTRATO"<<endl;
cout<<"2.MOSTRAR CONTRATOS"<<endl;
cout<<"3.BUSCAR CONTRATO"<<endl;
cout<<"4.MODIFICAR CONTRATO"<<endl;
cout<<"5.DAR DE BAJA CONTRATO"<<endl;
cout<<"0.VOLVER"<<endl;
cout<<"---------------------------------------------------"<<endl;
cout<<"INGRESE UNA OPCION:"<<endl;
cin>>opc;

    switch(opc)
    {
        case 1:{
    system("cls");
    Contrato reg;
    reg.cargar(false);

    if(archireg.guardarRegistro(reg))
    {
        system("cls");
        cout<< "CONTRATO GUARDADO CORRECTAMENTE"<<endl;
        system("pause");
    }else{
    system("cls");
    cout<<"ERROR AL CARGAR EL CONTRATO"<<endl;
    system("pause");
    }

    break;
    }

    case 2:
        {
        system("cls");
        Contrato reg;
        int cant = archireg.contarRegistros();

        if(cant ==0)
        {
            system("cls");
            cout<< "ARCHIVO DE CONTRATOS VACIO"<<endl;
            system("pause");
            break;
        }
        for(int i=0;i<cant;i++)
        {
         reg = archireg.leerRegistro(i);
         if(reg.getEstado())
         {
             reg.mostrar();
         }
        }
        break;
        }

    case 3:
        {
        Contrato reg;
        system("cls");
        int id;
        cout<<"INGRESE EL ID DEL CONTRATO BUSCADO"<<endl;
        cin>>id;
        if(archireg.buscarPorId(id) != -1)
        {
        reg.cargar(true);
        }else{
        system("cls");
        cout<<"NO SE ENCONTRO CONTRATO CON ESE ID "<<endl;
        system("pause");
        }
        break;
        }

    case 4:
        {
        system("cls");
    cout<< "INGRESE EL ID A MODIFICAR"<<endl;
    int id;
    cin>>id;
    int pos = archireg.buscarPorId(id);
    Contrato reg;

    if(pos != -1)
    {
        reg = archireg.leerRegistro(pos);
            system("cls");
            cout<< "DATOS ACTUALES: "<<endl;
            reg.mostrar();
            system("pause");

            system("cls");
            reg.cargar(true);
            bool res = archireg.modificarRegistro(reg,pos);

            if(res)
            {
                system("cls");
                cout<< "REGISTRO MODIFICADO CORRECTAMENTE"<<endl;
                system("pause");
            }else{
            system("cls");
            cout<< "ERROR AL MODIFICAR EL REGISTRO"<<endl;
            system("pause");
            }

    }
    break;



        break;
        }

    case 5:{
        Contrato reg;
        system("cls");
        int id;
        cout<<"INGRESE EL ID DEL CONTRATO A DAR DE BAJA"<<endl;
        cin>>id;

        if(archireg.buscarPorId(id) != -1)
        {
            if(archireg.bajaLogica(id))
            {
                system("cls");
                cout<< "DADO DE BAJA CORRECTAMENTE"<<endl;
                system("pause");
            }else{
                system("cls");
                cout<< "ERROR AL DAR DE BAJA"<<endl;
                system("pause");
            }
        }else
        {
        system("cls");
        cout<< "NO SE ENCONTRO CONTRATO CON ESE ID"<<endl;
        system("pause");
        }
    break;
    }
    case 0: return;

    }




}while(opc!=0);
}

void Menu::menuCanchas()
{
    int opc;
    do{
    system("cls");
    cout<<"------------------- MENU CANCHAS -------------------"<<endl;
cout<<"1.CARGAR CANCHAS"<<endl;
cout<<"2.MOSTRAR CANCHAS"<<endl;
cout<<"3.BUSCAR CANCHAS"<<endl;
cout<<"4.MODIFICAR CANCHAS"<<endl;
cout<<"5.DAR DE BAJA CANCHAS"<<endl;
cout<<"0.VOLVER"<<endl;
cout<<"---------------------------------------------------"<<endl;
cout<<"INGRESE UNA OPCION:"<<endl;
cin>>opc;

    switch(opc)
    {
        case 1:{
        system("cls");
    Cancha reg;
    ArchivoCancha archireg;

    reg.cargar(0);
    system("cls");
    if(archireg.guardarRegistro(reg))
    {
        cout<< "CANCHA GUARDADA CORRECTAMENTE."<<endl;
    }else{
    cout<< "ERROR AL CARGAR CANCHA."<<endl;
    }
    system("pause");
    break;
    }

case 2:{
        system("cls");
    Cancha reg;
    ArchivoCancha archireg;

    system("cls");

    int cant = archireg.contarRegistros();
    if(cant == 0)
    {
        cout<<"Archivo de cancha vacio"<<endl;
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
    ArchivoCancha archireg;
    Cancha reg;
    int id;

    cout << "INGRESE EL ID DE LA CANCHA A BUSCAR: "<<endl;
    cin>>id;
    int res = archireg.buscarPorId(id);
    if(res != -1)
    {
        cout<< "CANCHA ENCONTRADA: "<<endl;
        reg = archireg.leerRegistro(res);
        reg.mostrar();
        system("pause");
    }else{
    cout<< "CANCHA NO ENCONTRADA"<<endl;
    system("pause");
    break;
    }

    break;
    }

case 4:
    {
        ArchivoCancha archireg;
        Cancha reg;
        int id;

        cout<< "INGRESE ID DE LA CANCHA A MODIFICAR:"<<endl;
        cin>>id;

        int pos = archireg.buscarPorId(id);
        if(pos != -1)
        {
            reg = archireg.leerRegistro(pos);

            cout<< "DATOS ACTUALES: "<<endl;

            system("cls");
            reg.mostrar();
            system("pause");

            reg.cargar(1);
            bool res = archireg.modificarRegistro(reg,pos);

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

    ArchivoCancha archireg;

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
    case 0:
        return;
    }


    }while(opc=!0);
}

void Menu::ejecutar()
{
    menuPrincipal();
}





