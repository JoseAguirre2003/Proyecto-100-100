/* Proyecto de Introduccion a la informatica y Logica Computacional
Informatica - Seccion C - Semestre 1
Integrantes: 
Deismar Duran - 24.339.332  
Maria Pacheco - 30.447.971
Ronner Vasquez - 29.831.702
Carlos Rodriguez - 29.795.810
Jose Aguirre - 30.161.797 */

//Este si es un 100 de 100, a que si? ( ͡° ͜ʖ ͡°)

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
void interseEntrTresConj();
void menuInterce();
void menuConjunto();
void menuComplementos();
void complementoDeConj(int *conj, int size);
void complementConjRespectoA(int *conj1, int *conj2, int size1, int size2);
void diferenciaSimetrica(int *conj1, int *conj2, int size1, int size2);
void complemetAuBuC();

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
    system("cls");
    menuPrincipal();
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
        printf("Conjunto Universal:\n");
        mostrarConjunto(universo, tamano);

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
            system("cls");
            complemetAuBuC();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            complementConjRespectoA(conjA, conjB, sizeA, sizeB);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            complementConjRespectoA(conjA, conjC, sizeA, sizeC);
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            diferenciaSimetrica(conjA, conjB, sizeA, sizeB);
            system("pause");
            system("cls");
            break;
        case 8:
            /* FIN */
            break;
        default:
            system("cls");
            printf("\nIngreso una opcion incorrecta\nVuelva a intentar\n");
            break;
        }
    } while (opc != 8);
}

void mostrarConjunto(int *conj, int size){

    int i;

    if(size == 0)
        printf("El conjunto esta vacio\n");
    else if(size == 1)
        printf("Conunto: {%i}\n", conj[0]);
    else{
        printf("Conjunto: {%i", conj[0]);
        for(i = 1; i < size; i++){
            printf(", %i", conj[i]);
        }
        printf("}\n");
    }
}

void interseEntreDosConjuntos(int *conj1, int *conj2, int size1, int size2){

    int *interseccion;
    interseccion = (int*)malloc((size1 + size2) * sizeof(int));
    int k = 0, i, j;

    for (i = 0; i < size1; i++){
        for (j = 0; j < size2; j++){
            if(conj1[i] == conj2[j]){
                interseccion[k] = conj2[j];
                k++;
            }
        }
    }
        
    interseccion = (int*)realloc(interseccion, k*sizeof(int));
    mostrarConjunto(interseccion, k);
}

void interseEntrTresConj(){

    int *interseccion3;
    interseccion3 = (int*)malloc(tamano * sizeof(int));
    int j = 0;

    for (int i = 0; i < tamano; i++){

        if (universo[i] % 2 == 0 && universo[i] % 3 == 0 && universo[i] % 4 == 0){
            
            interseccion3[j] = universo[i];
            j++;

        }

    }   

    interseccion3 = (int*)realloc(interseccion3, j*sizeof(int));
    mostrarConjunto(interseccion3, j);
}

void menuConjunto(){

    int opc;

    printf("Que conjutno desea ver?\n");
    printf("1 - Conjunto A\n");
    printf("2 - Conjunto B\n");
    printf("3 - Conjunto C\n");
    scanf("%i", &opc);

    do{

        switch (opc){
        case 1:
            system("cls");
            printf("\nEl Conjunto A es:\n");
            mostrarConjunto(conjA, sizeA);
            break;
        case 2:
            system("cls");
            printf("\nEl Conjunto B es:\n");
            mostrarConjunto(conjB, sizeB);
            break;
        case 3:
            system("cls");
            printf("\nEl Conjunto C es:\n");
            mostrarConjunto(conjC, sizeC);
            break;
        default:
            system("cls");
            printf("Opcion incorrecta, debe elegir entre 1 y 3\nIntente nuevamente\n");
            break;
        }

    }while(opc < 1 || opc > 3);
    system("pause");
    system("cls");
}

void menuInterce(){

    int opc;

    printf("Que intersecciones desea ver?\n");
    printf("1 - A n B\n");
    printf("2 - A n C\n");
    printf("3 - B n C\n");
    printf("4 - A n B n C\n");
    scanf("%i", &opc);

    do{
        switch (opc){
        case 1:
            system("cls");
            printf("\nEl Conjunto A n B es:\n");
            interseEntreDosConjuntos(conjA, conjB, sizeA, sizeB);
            break;
        case 2:
            system("cls");
            printf("\nEl Conjunto A n C es:\n");
            interseEntreDosConjuntos(conjA, conjC, sizeA, sizeC);
            break;
        case 3:
            system("cls");
            printf("\nEl Conjunto B n C es:\n");
            interseEntreDosConjuntos(conjB, conjC, sizeB, sizeC);
            break;
        case 4:
            system("cls");
            printf("\nEl Conjunto A n B n C es:\n");
            interseEntrTresConj();
            break;
        default:
            system("cls");
            printf("Opcion incorrecta, debe elegir entre 1 y 4\nIntente nuevamente\n");
            break;
        }

    }while(opc < 1 || opc > 4); 
    system("pause");
    system("cls");
}

void menuComplementos(){

    int opc; 

    printf("Que complementos desea ver?\n");
    printf("1 - Complento de A\n");
    printf("2 - Complento de B\n"); 
    printf("3 - Complento de C\n");
    scanf("%i", &opc);

    do{

        switch (opc){
        case 1:
            system("cls");
            printf("\nEl Complemento de A es:\n");
            complementoDeConj(conjA, sizeA);
            break;
        case 2:
            system("cls");
            printf("\nEl Complemento de B es:\n");
            complementoDeConj(conjB, sizeB);
            break;
        case 3:
            system("cls");
            printf("\nEl Complemento de C es:\n");
            complementoDeConj(conjC, sizeC);
            break; 
        default:
            system("cls");
            printf("Opcion incorrecta, debe elegir entre 1 y 3\nIntente nuevamente\n");
        break;
        }

    }while(opc < 1 || opc > 3);
    system("pause");
    system("cls");
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

void complementConjRespectoA(int *conj1, int *conj2, int size1, int size2){

    int *complementRes;
    complementRes = (int*)malloc((tamano) * sizeof(int));
    int k = 0;
    int encontrado = 0;

    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            if(conj1[i] == conj2[j])
                encontrado = 1;
        }
        if (!encontrado){
            complementRes[k] = conj1[i];
            k++;
        }
        encontrado = 0;
    }
    
    complementRes = (int*)realloc(complementRes, k*sizeof(int));
    mostrarConjunto(complementRes, k);
}

void diferenciaSimetrica(int *conj1, int *conj2, int size1, int size2){
    
    int *difSimetric;
    difSimetric = (int*)malloc((size1 + size2) * sizeof(int));
    int i, j, k = 0;
    int encontrado = 0;

    for (i = 0; i < size1; i++){
        for(j = 0; j < size2; j++){\
            if(conj1[i] == conj2[j])
                encontrado = 1;
        } 
        if(!encontrado){
            difSimetric[k] = conj1[i];
            k++;
        }
        encontrado = 0;
    }

    for (i = 0; i < size2; i++){
        for(j = 0; j < size1; j++){\
            if(conj2[i] == conj1[j])
                encontrado = 1;
        } 
        if(!encontrado){
            difSimetric[k] = conj2[i];
            k++;
        }
        encontrado = 0;
    }

    difSimetric = (int*)realloc(difSimetric, k*sizeof(int));
    mostrarConjunto(difSimetric, k);
}

void complemetAuBuC(){
    int *complementoAuBuC;
    complementoAuBuC = (int*)malloc(tamano * sizeof(int));
    int k = 0;
    int i, j;
    int encontrado = 0;

    for (i = 0; i < tamano; i++){
        for(j = 0; j < sizeA; j++){\
            if(universo[i] == conjA[j])
                encontrado = 1;
        } 
        if(!encontrado){
            complementoAuBuC[k] = universo[i];
            k++;
        }
        encontrado = 0;
    }
    for (i = 0; i < sizeB; i++){
        for(j = 0; j < tamano; j++){\
            if(conjB[i] == complementoAuBuC[j])
                encontrado = 1;
        } 
        if(!encontrado){
            complementoAuBuC[k] = conjB[i];
            k++;
        }
        encontrado = 0;
    }
    for (i = 0; i < sizeC; i++){
        for(j = 0; j < tamano; j++){\
            if(conjC[i] == complementoAuBuC[j])
                encontrado = 1;
        } 
        if(!encontrado){
            complementoAuBuC[k] = conjC[i];
            k++;
        }
        encontrado = 0;
    }
    complementoAuBuC = (int*)realloc(complementoAuBuC, k*sizeof(int));  
    mostrarConjunto(complementoAuBuC, k);        
}