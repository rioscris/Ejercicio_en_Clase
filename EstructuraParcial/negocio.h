#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED

typedef struct
{
    int dia;
    int fecha;
    int anio;
}eFecha;

typedef struct
{
    int legajo;//autoincremental
    char apellido[51];//validar
    char nombre[51];//validar
    char sexo;//validar
    float salario; //mayor a cero
    int idSector;
    eFecha fechaIngresoEmpleado;
    int isEmpty;

}eEmpleados; //alta, baja, modificacion

typedef struct
{
   int id; //autoincremental
   int idComida; //Debe existir
   int lejagoEmpleado; //debe existir
   eFecha fechaAlmuerzo;
  // int isEmpty;
}eAlmuerzo;

typedef struct
{
    int id; //codigo menu autoincremental
    char descripcion[51];// validar
    int importe; //debe ser mayot a cero
    //int isEmpty;
}eMenu; // alta, baja, modificacion


typedef struct
{
    int id;
    char descripcion[51];

}eSector;

//Hay que crear un 5to struct de sectores

int inicializarEmpleados(eEmpleados* lista, int tam);


#endif
