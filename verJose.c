#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *universo;
int *conjA, *conjB, *conjC;
int sizeA, sizeB, sizeC;
int tamano;

void rellenarUniverso();
void rellenarConjuntos();
void menuPrincipal();
void mostrarConjunto(int *conj, int size);
void interceEntreDosConjuntos(int *conj1, int *conj2, int size1, int size2);
void menuInterce();
void menuConjunto();

int main(){

    int i;

    printf("Ingrese la cantidad de numeros para el conjunto universal: ");
    scanf("%i", &tamano);
    fflush(stdin);
    
    universo = (int*)malloc(tamano * sizeof(int));
    conjA = (int*)malloc(tamano * sizeof(int));
    conjB = (int*)malloc(tamano * sizeof(int));
    conjC = (int*)malloc(tamano * sizeof(int));

    rellenarUniverso();
    rellenarConjuntos(); 

    menuPrincipal();

    system("pause");

    return 0;
}

void rellenarUniverso(){

    for(int i = 0; i < tamano; i++){
        
        printf("Ingrese el valor %i: ", i+1);
        scanf("%i", &universo[i]);
        fflush(stdin);
        
    }

}

void rellenarConjuntos(){

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < tamano; i++){

        if(universo[i] % 2 == 0){
            conjA[a] = universo[i];
            a++;
            sizeA++;
        }

        if(universo[i] % 3 == 0){
            conjB[b] = universo[i];
            b++;
            sizeB++;
        }

        if(universo[i] % 4 == 0){
            conjC[c] = universo[i];
            c++;
            sizeC++;
        }

    }

    conjA = (int*)realloc(conjA, sizeA*sizeof(int));
    conjB = (int*)realloc(conjB, sizeB*sizeof(int));
    conjC = (int*)realloc(conjC, sizeC*sizeof(int));

}

void menuPrincipal(){

    int opc;

    printf("1 - Para ver los conjuntos A,B o C\n");
    printf("2 - Para ver las intersecciones entre A,B o C\n");
    printf("3 - Para ver los complementos de A,B o C\n");
    printf("4 - Para ver 'A u B u C\n");
    printf("5 - Para ver A - B\n");
    printf("6 - Para ver 'A respecto a C\n");
    printf("7 - Para ver la diferencia cimetrica entre A y B\n");
    printf("8 - Salir del programa\n");
    scanf("%i", &opc);

    switch (opc){
    case 1:
        menuConjunto();
        break;
    case 2:
        menuInterce();
        break;
    case 3:
        
        break;
    case 4:

        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    default:
        printf("\nIngreso una opcion incorrecta\nVuelva a intentar");
        system("cls");
        break;
    }

}

void mostrarConjunto(int *conj, int size){

    for(int i = 0; i < size; i++){
        
        printf("%i\n", conj[i]);
        
    }

}

void interseEntreDosConjuntos(int *conj1, int *conj2, int size1, int size2){

    int *interseccion;
    interseccion = (int*)malloc((size1 + size2) * sizeof(int));
    int k = 0, i, j;

    if(size1 < 1 || size2 < 1){
        printf("El conjunto esta vacio\n");
    }else{
        if(size1 > size2){
            for (i = 0; i < size1; i++){
                for (j = 0; j < size2; j++){
                    if(conj1[i] == conj2[j]){
                        interseccion[k] = conj2[j];
                        k++;
                    }
                }
            }
        }else{
            for (i = 0; i < size2; i++){
                for (j = 0; j < size1; j++){
                    if(conj2[i] == conj1[j]){
                        interseccion[k] = conj1[j];
                        k++;
                    }
                }
            }
        }
    }
        
    interseccion = (int*)realloc(interseccion, k*sizeof(int));

    mostrarConjunto(interseccion, k);

}

void menuInterce(){

    int opc;

    printf("Que intersecciones desea ver?\n");
    printf("1 - A n B\n");
    printf("2 - A n C\n");
    printf("3 - B n C\n");
    printf("1 - A n B n C\n");
    scanf("%i", &opc);

    switch (opc){
    case 1:
        interseEntreDosConjuntos(conjA, conjB, sizeA, sizeB);
        break;
    case 2:
        interseEntreDosConjuntos(conjA, conjC, sizeA, sizeC);
        break;
    case 3:
        interseEntreDosConjuntos(conjB, conjC, sizeB, sizeC);
        break;
    case 4:
        /* code */
        break;
    default:
        break;
    }

}

void menuConjunto(){

    int opc;

    printf("Que conjutno desea ver?\n");
    printf("1 - Conjunto A\n");
    printf("2 - Conjunto B\n");
    printf("3 - Conjunto C\n");

    switch (opc){
    case 1:
        printf("\nEl Conjunto A es:\n");
        mostrarConjunto(conjA, sizeA);
        break;
    case 2:
        printf("\nEl Conjunto B es:\n");
        mostrarConjunto(conjB, sizeB);
        break;
    case 3:
        printf("\nEl Conjunto C es:\n");
        mostrarConjunto(conjC, sizeC);
        break;
    default:
        break;
    }

}

// void complementoDeConj(int *conj){

//     int *complemento;
//     complemento = (int*)malloc((tamano) * sizeof(int));


//     for (int i = 0; i < tamano; i++){
//         if    
//     }
    
// }