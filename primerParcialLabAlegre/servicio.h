#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

    int id;
    char descripcionServicio[20];
    int precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

int cargarDescripcionServicio(eServicio ArrayServicios[], int tamServicio, int idServicio, char descripcionServicio[]);

int mostrarServicios(eServicio ArrayServicios[], int tamServicio);

int buscarServicioPorId(eServicio arrayDeServicios[], int tamSer, int idServicio);
