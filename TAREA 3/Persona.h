

// Clase Persona.h  


#pragma once
#include <iostream>
#include <string>

class Persona
{
 private:
  // Private attributes  
  std::string nombre;
  std::string apellido;
  std::string cedula;
 
public:
  //constructor vacio
  Persona();
  //constructor con parametros
  Persona(const std::string& nombre, const std::string& apellido,const std::string& cedula);

  //metodo para pedir datos
  void pedirDatos();
  /// Empty Destructor
  virtual ~Persona();

 //setters y getters
  void setNombre(const std::string& nombre);
  std::string getNombre()const;
 
  void setApellido(const std::string& apellido);
  std::string getApellido()const;

  void setCedula(const std::string& cedula);
  std::string getCedula()const;
 
};

