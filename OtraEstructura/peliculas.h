#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char titulo[51];
    int anio;
    char nacionalidad[51];
    int idDirector; //Unir con los directores
    int isEmpty;

}ePeliculas;

typedef struct
{
    char nombre[51];
    eFecha nacimiento;
    char paisOrigen[51];
    int isEmpty;

}eDirectores;

int inicializarPeliculas(ePeliculas* lista, int tam);

int menuDeOpciones();

int espacioLibrePeliculas(ePeliculas* lista, int tam);

int buscarPeliculaPorId(ePeliculas* lista, int tam, int id);

int agregarPelicula(ePeliculas* lista, int tam);

int mostrarUnaPelicula(ePeliculas* lista, int indice);

int removerPelicula(ePeliculas* lista, int tam, int id);

#endif
