

// Clase Nodo.h


#pragma once
#include "Persona.h"
#include <string>

class Nodo {
private:
  //atributos
  Persona dato;
  Nodo *siguiente;

public:
  // constructor
  Nodo();
  // constructor con parametros
  Nodo(const Persona &dato);
  // Destructor
  virtual ~Nodo();

  // getters y setters
  void setDato(const Persona &dato);
  Persona getDato() const;

  Nodo *getSiguiente() const;
  void setSiguiente(Nodo *siguiente);
};
