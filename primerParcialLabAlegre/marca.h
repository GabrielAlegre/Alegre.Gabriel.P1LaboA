#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];

}eMarca;

#endif // MARCA_H_INCLUDED

int cargarDescripcionMarca(eMarca ArrayMarcas[], int tamMarca, int idMarca, char descripcionMarca[]);

int mostrarMarcas(eMarca ArrayMarcas[], int tamMarca);
