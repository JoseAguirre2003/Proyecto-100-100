#include<stdio.h>
#include<stdlib.h>
int contA = 0, contB = 0, contC = 0;
int dimensionarConjuntoA(int array[], int tamano);
int dimensionarConjuntoB(int array[], int tamano);
int dimensionarConjuntoC(int array[], int tamano);
int main(){
    int universoTamano;
    printf("Ingrese el tamano del universo:\n");
    scanf("%i", &universoTamano);   
    int universos[universoTamano];
    int i;
    printf("Ingrese el valores:\n");
    for(i = 0; i < universoTamano; i++){
        scanf("%i", &universos[i]);
    } 
    system("cls");
    for (i = 0; i < universoTamano; i++){
        printf("%i\n", universos[i]);
    }
    int A[dimensionarConjuntoA(universos, tamano)]; 
    int B[dimensionarConjuntoB(universos, tamano)];
    int C[dimensionarConjuntoC(universos, tamano)];
    int j = 0;
    for (i = 0; i < universoTamano; i++){        
        if(universos[i] % 2 == 0){
            A[j] = universos[i];
            j++;
        }
    }
    for (i = 0; i < universoTamano; i++){        
        if(universos[i] % 3 == 0){
            B[j] = universos[i];
            j++;
        }
    }
    for (i = 0; i < universoTamano; i++){    
        if(universos[i] % 4 == 0){
            C[j] = universos[i];
            j++;
        }
    }
    printf("Conjunto A\n");
    for (i = 0; i < contA; i++){

        printf("%i\n", A[i]);
    }
    printf("Conjunto B\n");
    for (i = 0; i < contB; i++){

        printf("%i\n", B[i]);
    }
    printf("Conjunto C\n");
    for (i = 0; i < contC; i++){
        printf("%i\n", C[i]);

    }
    system("PAUSE");
 
    return 0;
}
int dimensionarConjuntoA(int array[], int tamano){
    for (i = 0; i < tamano; i++){
        if(array[i] % 2 == 0)
            contA++;
    }
}
int dimensionarConjuntoB(int array[], int tamano){
    for (i = 0; i < tamano; i++){
        if(array[i] % 3 == 0)
            contB++;
    }
}
int dimensionarConjuntoC(int array[], int tamano){
    for (i = 0; i < tamano; i++){
        if(array[i] % 4 == 0)
            contC++;
    }
}