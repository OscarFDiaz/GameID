#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <stdexcept>
#include <iostream>


template <class T>
class Civilizacion
{
private:
    T *arreglo;
    int tam;
    int indice;
    const static int MAX = 5;
    ///Nombre por defecto de la civ.
public:
    std::string nombreC = "SIN NOMBRE";

    Civilizacion();
    ~Civilizacion();
    std::string getNombreC();

    void setNombreC(std::string s);
    void agregarA(const T &dato);
    void eliminarA(int pos);

    int linearFindData(const T &name);
    int poblacionT();
    int tamanio();

    bool isEmpty();

    T &operator[](int posicion);

    void toString();

};

template <class T>
Civilizacion<T>::Civilizacion()
{
    arreglo = new T[MAX];
    indice = 0;
    tam = MAX;
}

template <class T>
Civilizacion<T>::~Civilizacion()
{
    delete[]arreglo;
}

template<class T>
std::string Civilizacion<T>::getNombreC()
{
    return nombreC;
}

template<class T>
void Civilizacion<T>::setNombreC(std::string s)
{
    nombreC = s;
}

template<class T>
void Civilizacion<T>::agregarA(const T &dato)
{
    if(indice < tam){
        ///Si el indice es menor al tam total se agrega el aldeano
        arreglo[indice++] = dato;
        std::cout << std::endl << "-=ALDEANO AGREGADO=-" << std::endl << std::endl;
    }else{
        ///Si no se aumenta el tam y se crea un nuevo arreglo y se agrega el aldeano
        T *nuevo = new T[tam+5];
        for (int i = 0; i < indice; ++i) {
            nuevo[i]=arreglo[i];
        }
        delete []arreglo;
        arreglo = nuevo;
        arreglo[indice++] = dato;
        tam = tam + 5;
        std::cout << std::endl << "-=ALDEANO AGREGADO=-" << std::endl << std::endl;
    }
}

template <class T>
int Civilizacion<T>::linearFindData(const T& name) {
    ///Busca el nombre del aldeano si lo encuentra regresa su posicion
    int i(0);
    while( i <= indice){
        if(arreglo[i] == name){
            return i;
        }
        i++;
    }
    ///Si no lo encuentra regresa -1 (Inexistente)
    return -1;
    }


template<class T>
void Civilizacion<T>::eliminarA(int pos)
{
    if (pos >= indice or pos < 0) {
        ///Revisa si hay espacio para eliminar(Obsoleto por 'isEmpty()')
        std::cout << "-=POSICION INVALIDA=-";
    }
    for (int i = pos; i < indice - 1; ++i) {
        ///Recorre el arreglo para sobreescribir la posicion
        arreglo[i] = arreglo[i+1];
    }
    ///Reduce el indice diciendo que hay un aldeano menos
    indice--;
}

template<class T>
int Civilizacion<T>::poblacionT()
{
    return indice;
}

template<class T>
int Civilizacion<T>::tamanio()
{
    return tam;
}

template<class T>
bool Civilizacion<T>::isEmpty()
{
    ///Si el indice es igual a '0' no hay nada en el arreglo
    return indice == 0;
}

template<class T>
void Civilizacion<T>::toString()
{
    std::cout << std::endl << "-Nombre civilizacion: " << nombreC<< std::endl;
    std::cout << "-Poblacion total: " << poblacionT() << std::endl;
    std::cout << "-Aldeanos: " << std::endl;
    for (int i = 0; i < poblacionT(); ++i) {
        std::cout << arreglo[i] << std::endl;
    }
}

template<class T>
T &Civilizacion<T>::operator[](int posicion)
{
    ///Operador sobrecargado para poder imprimir el arreglo tipo T
    if (posicion < 0 or posicion >= indice){
        std::cout << "-=POSICION INVALIDA=-";
    }
    return arreglo[posicion];
}


#endif // CIVILIZACION_H
