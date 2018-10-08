#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "utn.h"
#include "clientes.h"
#include "juegos.h"

static int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int inicializarAlquiler(eAlquileres* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL )
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = 0;
    }

    return retorno;

}


int espacioLibreAlquiler(eAlquileres* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL)
    {
        for( i=0 ; i<len ; i++)
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

/*int altaAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    eAlquileres auxiliarAlquiler;
    int retorno=-1;
    int estaLibre=espacioLibreAlquiler(listaAlquileres, lenAlquileres);
    if(estaLibre==-1)
    {
        printf("No hay espacio libre");
    }
    if(estaLibre!=-1)
    {
        auxiliarAlquiler.codigoJuego = elegirJuego(listaJuegos, lenJuegos);
        auxiliarAlquiler.codigoCliente=elegirCliente(listaCliente, lenCliente); //

        auxiliarAlquiler.fechaIngreso.dia= getValidInt("Ingrese dia: ","Error, dia no valido.", 1, 31);
        auxiliarAlquiler.fechaIngreso.mes = getValidInt("Ingrese mes: ","Error, mes no valido.", 1, 12);
        auxiliarAlquiler.fechaIngreso.anio = getValidInt("Ingrese anio: ","Error, anio no valido.", 1000, 2018);
        auxiliarAlquiler.codigoAlquiler=generarNextId();
        auxiliarAlquiler.isEmpty=0;
        listaAlquileres[estaLibre] = auxiliarAlquiler;
        printf("Alquiler logrado con exito!\n");
        retorno=0;
        //}

    }

    return retorno;

}

int elegirJuego(eJuegos* listaJuegos, int len)
{
    int retorno=-1;
    int i;
    int idJuegos;
    printf("\nJuegos\n\n");
    mostrarTodosLosJuegos(listaJuegos, len);
    printf("\nSeleccione Juego: ");
    scanf("%d", &idJuegos);
    for( i=0; i<len ; i++)
    {
        if(listaJuegos[i].codigoJuego==idJuegos)
        {
            retorno=idJuegos;
            break;
        }
    }
    return retorno;
}

int elegirCliente(eCliente* listaCliente, int len)
{

    int idClientes;
    int i;
    printf("\nClientes\n\n");
    for(i=0; i < len; i++)
    {
        printf("%d %s\n", listaCliente[i].codigoCliente, listaCliente[i].apellido);
    }
    printf("\nSeleccione id del cliente: ");
    scanf("%d", &idClientes);

    return idClientes;
}
/*
void cargarCodigoJuego(eAlquileres* listaAlquiler, int lenAlquiler, int idAlquiler, int idJuegos){
     int i;
    for(i=0; i < lenAlquiler; i++)
    {
        if( listaAlquiler[i].codigoAlquiler == idJuegos)
        {
            idJuegos=listaAlquiler[i].codigoAlquiler;
            break;
        }
    }
}

void cargarCodigoCliente(eAlquileres* listaAlquiler, int lenAlquiler, int idAlquiler, int idCliente)
{       int i;
    for(i=0; i < lenAlquiler; i++){
        if( listaAlquiler[i].codigoAlquiler == idCliente){
            idCliente=listaAlquiler[i].codigoAlquiler;
            break;
        }
    }
}
*/
