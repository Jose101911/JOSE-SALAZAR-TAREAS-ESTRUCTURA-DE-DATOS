

// Clase Interfaz IPila.h  


#pragma once
#include "Persona.h"
#include <string>

/// class IPila

class IPila {
public:
  //destructor 
  virtual ~IPila()=default;
 //metodo ingresar
  virtual void apilar(const Persona& p) = 0;

  //metodo eliminar
  virtual void desapilar() = 0;

  //metodo buscar
  virtual bool buscar(const std::string& cedula) = 0;

  //metodo imprimir
  virtual void imprimir() = 0;
  
  virtual int sizePila() = 0;

};
