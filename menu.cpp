#include "menu.h"
#include "civilizacion.h"
#include "aldeano.h"

Menu::Menu(Civilizacion<Aldeano> *arr)
{
    string op;
    Aldeano a;///Para el aldeano
    ///Para el arreglo

    while (true) {
        ///nombre de la civ actual
            cout << endl << "-Nombre de la civilizacion: " << arr->getNombreC() << endl<< endl;
        ///Opciones del menu
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano " << endl;
        cout << "0) Regresar" << endl;
        cout << "Opcion: "; getline(cin, op);
        system("cls");

        if (op == "1") {
            ///Se piden los datos para el aldeano
            int myInt;
            string myStr;
            cout << "Ingresa el nombre: ";
            getline(cin, myStr);
            a.setNombreA(myStr);

            cout << "Ingresa la edad: ";
            cin >> myInt;
            a.setEdadA(myInt);

            cin.ignore();
            cout << "Ingresa el genero (H/M): ";
            getline(cin, myStr);
            if (myStr == "H" or myStr == "M") {
                ///Si se ingresa una H o una M se setea el genero
                a.setGeneroA(myStr);
            }else{
                ///Si se ingresa algo diferente de H o M se cancela
                cout << endl << "-=ERROR: UTILIZA H O M" << endl << endl;
                continue;
            }

            cout << "Ingresa la salud (HP): ";
            cin >> myInt;
            a.setSaludA(myInt);
            cin.ignore();
            ///Se agrega el aldeano al arreglo
            arr->agregarA(a);

        }else if (op == "2") {

            string myStr;
            int pos;
            if(arr->isEmpty()){
                ///Si el arreglo esta vacío no es posible eliminar aldeanos, se sigue con el menu
                cout << "-=ERROR: NO HAY ALDEANOS PARA ELIMINAR=-" << endl << endl;
                continue;
            }
            ///Si no esta vacío se pide el nombre del aldeano y se hace la busqueda
            cout << "Ingresa el nombre del aldeano a eliminar: ";
            getline(cin, myStr);
            a.setNombreA(myStr);
            pos = arr->linearFindData(a);
            if(pos == -1){
                ///Si la busqueda regresa -1 el adeano no existe
                cout << endl << "-=ERROR: EL ALDEANO NO EXISTE-=" << endl << endl;
                continue;
            }else{
                ///El aldeano existe, preguntar si desea eliminarlo
                string op;
                cout << "Estas seguro de eliminar a '" << myStr << "'? S/N: ";
                getline(cin, op);
                if(op == "S"){
                    ///Si dice que sí se elimina al aldeano y se envia la confirmación
                    arr->eliminarA(pos);
                    cout << endl << "-=ALDEANO ELIMINADO=-" << endl << endl;
                }else if(op == "N"){
                    ///Si dice que no el aldeano vuelve "a su hogar" y se sigue con el menu
                    cout << endl << "-=EL ALDEANO VOLVIO A SU HOGAR=-" << endl << endl;
                    continue;
                }else{
                    ///Si se usa una letra diferente de 'S' o 'N'
                    cout << endl << "-=ERROR: OPCION NO VALIDA=-" << endl << endl;
                }
            }

        }else if (op == "0") {
            ///Se cierra el programa
            break;
        }else if(op == "5"){}
    }
}
