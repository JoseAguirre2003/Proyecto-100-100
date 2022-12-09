#include<stdio.h>
#include<stdlib.h>

int contA = 0, contB = 0, contC = 0, Universo[0], conjA[0], conjB[0], conjC[0];
int contadorPrincipal = 0;
void defUniverso();
void defConjuntos();
void mostrarConjuntos();
void unionConjuntos();

int dimensionarConjuntoA(int array[], int tamano);
int dimensionarConjuntoB(int array[], int tamano);
int dimensionarConjuntoC(int array[], int tamano);

int main(){
    defUniverso();
    defConjuntos();
    mostrarConjuntos();
    unionConjuntos();

    return 0;
}

void defUniverso(){
        char continuar;
    
    do
    {
        printf("ingrese un elemento\n");
        scanf("%i", &Universo[contadorPrincipal]);
        fflush(stdin);
        contadorPrincipal++;
        printf("desea seguir registrando elementos (Y/N)\n");
        scanf("%c", &continuar);
    } while (continuar == 'Y' || continuar == 'y');
    
    for (int j = 0; j < contadorPrincipal; j++)
    {
        printf("%i\n", Universo[j]);
    }
    system("pause");
}

void defConjuntos(){

    for (int i = 0; i < contadorPrincipal; i++)
    {
        if(Universo[i] % 2 == 0){
            conjA[i] = Universo[i];
            contA++;
        }

        if(Universo[i] % 3 == 0){
            conjB[i] = Universo[i];
            contB++;
        }

        if(Universo[i] % 4 == 0){
            conjC[i] = Universo[i];
            contC++;
        }
    }
}
void mostrarConjuntos(){  
    printf("Los del conjunto A:\n");
    for (int i = 0; i < contA; i++)
    {   
        printf("%i\n", conjA[i]);
    }
    printf("Los del conjunto B:\n");
    for (int i = 0; i < contB; i++)
    {   
        printf("%i\n", conjB[i]);
    }
    printf("Los del conjunto C:\n");
    for (int i = 0; i < contC; i++)
    {   
        printf("%i\n", conjC[i]);
    }
    system("pause");
}

void unionConjuntos(){

    int opc;
    int i;

    printf("Que conjutno desear unir?\n");
    printf("1 - Conjunto A ∩ B\n");
    printf("2 - Conjunto A ∩ C\n");
    printf("3 - Conjunto B ∩ C");
    printf("4 - Conjunto A ∩ B ∩ C\n");
    printf("Su opcion es: ");
    scanf("%i", &opc);

    switch (opc){
    case 1:
        for (i = 0;i < contA; i++)
        {   
            printf("%i\n", conjA[i]);
        }
        for (i = 0; i < contB; i++)
        {
            
            for (int j = 0; j < contA; j++)
            {
                if (conjB[i] == conjA[j])
                {
                    printf("%i\n", conjB[i]);
                }
                
            }
            
        }
        
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    default:
        printf("Opcion invalida");
        break;
    }

    system("pause");

}