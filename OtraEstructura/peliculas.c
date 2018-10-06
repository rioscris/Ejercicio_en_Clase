#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "peliculas.h"
#include "utn.h"

static int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int inicializarPeliculas(ePeliculas* lista, int tam)
{
    int i;
    int retorno=-1;
    if( lista != NULL )
    {
        for(i=0; i<tam ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = 0;
    }

    return retorno;

}

int menuDeOpciones()
{
    int opcion;
    //system("cls");
    printf("-----Menu de opciones-----\n\n");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int espacioLibrePeliculas(ePeliculas* lista, int tam)
{
    int i;
    int retorno=-1;
    if( lista != NULL)
    {
        for( i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }

    }
    return retorno;
}

int mostrarUnaPelicula(ePeliculas* lista, int indice)
{
    int retorno=-1;
    if( lista!= NULL)
    {
        if(lista[indice].isEmpty==0)
        {
           printf("%d\t   %s\t   %d\t  %s\t  ", lista[indice].id, lista[indice].titulo, lista[indice].anio, lista[indice].nacionalidad);
           retorno=0;
        }
    }
    return retorno;

}

int buscarPeliculaPorId(ePeliculas* lista, int tam, int id)
{
    int i;
    int retorno=-1;
    if( lista!= NULL)
    {
        for( i=0 ; i<tam ; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int agregarPelicula(ePeliculas* lista, int tam)
{
    ePeliculas auxiliarPelicula;
    int lugarLibre = espacioLibrePeliculas(lista, tam);
    int retorno=-1;
    //char auxNombre[51];
    //char auxNacionalidad[51];
    //int auxAnio;

    if(lista !=  NULL)
    {
        if(lugarLibre != -1)
        {
            getValidString("Ingrese titulo de la pelicula: ", "Error, titulo no valido.", auxiliarPelicula.titulo);
            auxiliarPelicula.anio = getValidInt("Ingrese anio de la pelicula: ","Error, anio no valido.", 0, 2023);
            getValidString("Ingrese nacionalidad de la pelicula: ","Error, nacionalidad no valida.", auxiliarPelicula.nacionalidad);
            auxiliarPelicula.id = generarNextId();
            auxiliarPelicula.isEmpty =0;
            lista[lugarLibre]=auxiliarPelicula;

            retorno=0;

        }
    }
    return retorno;
}

int removerPelicula(ePeliculas* lista, int tam, int id)
{
    int index;
    int i;
    int retorno=-1;

    if(lista!=NULL)
    {
        printf("Ingrese el id de la pelicula que desa eliminar: ");
        scanf("%d",&id);
        index=buscarPeliculaPorId(lista, tam, id);

        if(lista[index].isEmpty==0)
        {
             printf("ID\t   TITULO\t   ANIO\t   NACIONALIDAD\n");
             mostrarUnaPelicula(lista, index);
        }
        //Tendria que preguntar si quiere eliminar la pelicula
        for( i=0 ; i<tam ; i++)
        {
            if(index>=0)
            {
                printf("El usuario fue eliminado!\n");
                lista[index].isEmpty=1;
                break;
            }
            else
            {
                printf("No existe ese id!! \n");
                break;
            }
            retorno=0;
        }
    }
    return retorno;
}








