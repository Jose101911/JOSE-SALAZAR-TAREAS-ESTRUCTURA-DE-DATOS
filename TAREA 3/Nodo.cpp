

// Clase Nodo.cpp


#include "Nodo.h"

// constructor
Nodo::Nodo() { this->siguiente = nullptr; }
// constructor con parametros
Nodo::Nodo(const Persona &dato) {
  this->dato = dato;
  this->siguiente = nullptr;
}
// destructor
Nodo::~Nodo() {}

// getters y setters
void Nodo::setDato(const Persona &dato) { this->dato = dato; }

Persona Nodo::getDato() const { return this->dato; }

Nodo *Nodo::getSiguiente() const { return this->siguiente; }
void Nodo::setSiguiente(Nodo *siguiente) { this->siguiente = siguiente; }
