#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_matriz(int *mat, int ord);

void imprimir(int *mat, int ord);

int main(){
    srand(time(NULL));
    int *mat1,*mat2,*mat_mult;
    int ord;
    int i=0,j=0,k=0,x=0,aux=0,total=0,sum=0;
    printf("Digite a ordem das matrizes\n");
    scanf("%d",&ord);
    total=ord*ord;

        mat1=(int*)malloc(total*sizeof(int));
        mat2=(int*)malloc(total*sizeof(int));
        mat_mult=(int*)malloc(total*sizeof(int));
        preencher_matriz(mat1,ord);
        printf("MATRIZ 1:\n\n");
        imprimir(mat1,ord);
        preencher_matriz(mat2,ord);
        printf("MATRIZ 2:\n\n");
        imprimir(mat2,ord);
        for (i=0;i<ord;i++) {
            for (j=0;j<ord;j++) {
                sum = 0;
                for (k=0;k<ord;k++)
                    sum=sum+mat1[i*ord+k]*mat2[k*ord+j];
                mat_mult[i*ord+j]=sum;
            }
        }
        printf("A Matriz resultande da multiplicao de matrizes:\n\n");
        imprimir(mat_mult,ord);

    return 0;
}

void preencher_matriz(int *mat, int ord){
    int i=0,j=0,total=0;
    total=ord*ord;
    for(i=0;i<total;i++){
        mat[i]=rand()%5+1;
    }
}

void imprimir(int *mat, int ord){
    int i=0,j=0,cont=0,total=0;
    total=ord*ord;
    for(i=0;i<total;i++){
        cont++;
        printf("%4d",mat[i]);
        if(cont == ord){
            printf("\n");
            cont=0;
        }
    }
    printf("\n");
}