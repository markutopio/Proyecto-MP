#include <stdio.h>
#include <stdlib.h>

int ConsultaElemento(int* vector, int posicion);

int main() {
    int* vector;
    int i, posicion, numElementos = 8;

    vector = (int*)malloc(numElementos*sizeof(int));

    if (vector==NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Introduce %d elementos en el vector:\n", numElementos);
    for (i = 0;i<numElementos;i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &vector[i]);
    }

    printf("Introduce la posicion del elemento a consultar: ", numElementos);
    scanf("%d", &posicion);

    posicion--;

    printf("El elemento en la posicion %d es: %d\n", posicion+1, ConsultaElemento(vector, posicion));

    free(vector);

    return 0;
}

int ConsultaElemento(int*vector, int posicion) {
    return vector[posicion];
}
