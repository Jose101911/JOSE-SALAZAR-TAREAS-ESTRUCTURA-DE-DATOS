#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H

#include <iostream>
#include "Nodo.h"

using namespace std;

template <typename T>
class ListaDobleCircular
{
public:
    ListaDobleCircular();
    ~ListaDobleCircular();

    bool estaVacia();
    int getTamanio();

    void insertarAlInicio(T valor);
    void insertarAlFinal(T valor);
    Nodo<T>* buscar(T dato);
    void eliminar(T dato);
    void imprimir();
    T obtenerEnPosicion(int pos);

private:
    Nodo<T>* cabeza;
    int tamanio;
};

template <typename T>
ListaDobleCircular<T>::ListaDobleCircular()
{
    cabeza = nullptr;
    tamanio = 0;
}

template <typename T>
ListaDobleCircular<T>::~ListaDobleCircular()
{
    while (!estaVacia())
    {
        eliminar(cabeza->getDato());
    }
}

template <typename T>
bool ListaDobleCircular<T>::estaVacia()
{
    return cabeza == nullptr;
}

template <typename T>
int ListaDobleCircular<T>::getTamanio()
{
    return tamanio;
}

template <typename T>
void ListaDobleCircular<T>::insertarAlFinal(T valor)
{
    Nodo<T>* nuevo = new Nodo<T>(valor);

    if (estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        cabeza = nuevo;
    }
    else
    {
        Nodo<T>* ultimo = cabeza->getAnterior();

        nuevo->setSiguiente(cabeza);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        cabeza->setAnterior(nuevo);
    }
    tamanio++;
}

template <typename T>
void ListaDobleCircular<T>::insertarAlInicio(T valor)
{
    Nodo<T>* nuevo = new Nodo<T>(valor);

    if (estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
    }
    else
    {
        Nodo<T>* ultimo = cabeza->getAnterior();

        nuevo->setSiguiente(cabeza);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        cabeza->setAnterior(nuevo);
    }
    cabeza = nuevo;   
    tamanio++;
}

template <typename T>
Nodo<T>* ListaDobleCircular<T>::buscar(T dato)
{
    if (estaVacia())
    {
        return nullptr;
    }

    Nodo<T>* actual = cabeza;

    do
    {
        if (actual->getDato() == dato)
        {
            return actual;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza);

    return nullptr;
}

template <typename T>
void ListaDobleCircular<T>::eliminar(T dato)
{
    if (estaVacia())
    {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo<T>* actual = cabeza;

    do
    {
        if (actual->getDato() == dato)
        {
            
            if (actual->getSiguiente() == actual)
            {
                cabeza = nullptr;
            }
            else
            {
               
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());

                
                if (actual == cabeza)
                {
                    cabeza = actual->getSiguiente();
                }
            }

            delete actual;
            tamanio--;
            cout << "Elemento eliminado" << endl;
            return;
        }

        actual = actual->getSiguiente();

    } while (actual != cabeza);

    cout << "Elemento no encontrado" << endl;
}

template <typename T>
void ListaDobleCircular<T>::imprimir()
{
    if (estaVacia())
    {
        cout << "Lista vacia" << endl;
        return;
    }

    Nodo<T>* actual = cabeza;

    do
    {
        cout << actual->getDato() << " ";
        actual = actual->getSiguiente();
    } while (actual != cabeza);

    cout << endl;
}


template <typename T>
T ListaDobleCircular<T>::obtenerEnPosicion(int pos)
{
    if (estaVacia())
    {
        cout << "La lista esta vacia" << endl;
        return T();
    }

    if (pos < 0 || pos >= tamanio)
    {
        cout << "Posicion invalida" << endl;
        return T();
    }

    Nodo<T>* actual = cabeza;

    
    if (pos <= tamanio / 2)
    {
        for (int i = 0; i < pos; i++)
        {
            actual = actual->getSiguiente();
        }
    }
    else
    {
        for (int i = 0; i < tamanio - pos; i++)
        {
            actual = actual->getAnterior();
        }
    }

    return actual->getDato();
}



#endif
