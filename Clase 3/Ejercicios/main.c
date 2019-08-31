#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b,  int c);
int getInt200500();
int getIntRango(int min, int max);

int main()
{
    int max;
    int num;
    int num2;
    int numMin = 1;
    int numMax = 10;


        max = getMax( 1, 1, 0);
        num = getInt200500();
        num2 = getIntRango(numMin, numMax);

        printf("El maximo es: %d \n\n", max);
        printf("El numero es: %d\n\n", num);
        printf("El numero es: %d\n\n", num2);

    return 0;
}

int getMax(int a, int b,  int c){
    int max;

    max = a;

         max = a;
         if(max < b){
            max = b;
         }
         if(max < c){
            max = c;
         }

    return max;
}

int getInt200500(){
    int num;

        printf("Ingese numero entre 200 y 500: ");
        scanf("%d", &num);

        while(num < 200 || num > 500){
            printf("Errr. Reingrese numero entre 200 y 500: ");
            scanf("%d", &num);
        }

    return num;
}

int getIntRango(int min, int max){
    int num;

        printf("Ingese numero entre %d y %d: ", min, max);
        scanf("%d", &num);

        while(num < min || num > max){
            printf("Error. Reingese numero entre %d y %d: ", min, max);
            scanf("%d", &num);
        }

    return num;
}
