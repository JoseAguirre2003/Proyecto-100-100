#include <stdio.h>
#include <stdlib.h>

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
void menuComplementos();
void complementoDeConj(int *conj, int size);

int main(){

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

    do{
        
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
            system("cls");
            menuConjunto();
            break;
        case 2:
            system("cls");
            menuInterce();
            break;
        case 3:
            system("cls");
            menuComplementos();
            break;
        case 4:
            /* code */
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
            system("cls");
            printf("\nIngreso una opcion incorrecta\nVuelva a intentar\n");
            break;
        }

    } while (opc != 8);

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

void menuConjunto(){

    int opc;

    printf("Que conjutno desea ver?\n");
    printf("1 - Conjunto A\n");
    printf("2 - Conjunto B\n");
    printf("3 - Conjunto C\n");
    scanf("%i", &opc);

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

    system("pause");
    system("cls");

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
    default:
        break;
    }

    system("pause");
    system("cls");

}

void menuComplementos(){

    int opc; 

    printf("Que complementos desea ver?\n");
    printf("1 - Complento de A\n");
    printf("2 - Complento de B\n"); 
    printf("2 - Complento de C\n");
    scanf("%i", &opc);

    switch (opc){
    case 1:
        complementoDeConj(conjA, sizeA);
        break;
    case 2:
        complementoDeConj(conjB, sizeB);
        break;
    case 3:
        complementoDeConj(conjC, sizeC);
        break; 
    default:
    break;
   }

}

void complementoDeConj(int *conj, int size){

    int *complemento;
    complemento = (int*)malloc((tamano) * sizeof(int));
    int k = 0;
    int encontrado = 0;

    for (int i = 0; i < tamano; i++){
        for(int j = 0; j < size; j++){\
            if(universo[i] == conj[j])
                encontrado = 1;
        } 
        if(!encontrado){
            complemento[k] = universo[i];
            k++;
        }
        encontrado = 0;
    }

    complemento = (int*)realloc(complemento, k*sizeof(int));

    mostrarConjunto(complemento, k);
    
}

// void complementConjRespectoA(){

//     int *complementRes;
//     complementRes = (int*)malloc((tamano) * sizeof(int));



// }