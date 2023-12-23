#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_matriz(int **mat, int l, int c);

void imprimir(int **mat, int l, int c);

int main(){
    srand(time(NULL));
    int **mat1,**mat2,**mat_mult;
    int l1,c1,l2,c2,l_mult,c_mult;
    int *vet_l1,*vet_c1,*vet_l2,*vet_c2;
    int i=0,j=0,x=0,aux=0;
    printf("Digite o numero de linhas da matriz 1\n");
    scanf("%d",&l1);
    printf("Digite o numero de colunas da matriz 1\n");
    scanf("%d",&c1);
    printf("Digite o numero de linhas da matriz 2\n");
    scanf("%d",&l2);
    printf("Digite o numero de colunas da matriz 2\n");
    scanf("%d",&c2);
    if(c1 == l2){
        mat1=malloc(l1*sizeof(int));
        for(i=0;i<l1;i++){
            mat1[i]=malloc(c1*sizeof(int));
        }
        preencher_matriz(mat1,l1,c1);
        printf("MATRIZ 1:\n\n");
        imprimir(mat1,l1,c1);
        mat2=malloc(l2*sizeof(int));
        for(i=0;i<l2;i++){
            mat2[i]=malloc(c2*sizeof(int));
        }
        preencher_matriz(mat2,l2,c2);
        printf("MATRIZ 2: \n\n");
        imprimir(mat2,l2,c2);
        l_mult=l1;
        c_mult=c2;
        mat_mult=malloc(l_mult*sizeof(int));
        for(i=0;i<l_mult;i++){
            mat_mult[i]=malloc(c_mult*sizeof(int));
        }
        vet_l1=(int*)malloc(l1*sizeof(int));
        vet_c1=(int*)malloc(c1*sizeof(int));
        vet_l2=(int*)malloc(l2*sizeof(int));
        vet_c2=(int*)malloc(c2*sizeof(int));
        for(i=0;i<l1;i++){
            vet_l1[i]=i;
        }
        for(i=0;i<c1;i++){
            vet_c1[i]=i;
        }
        for(i=0;i<l2;i++){
            vet_l2[i]=i;
        }
        for(i=0;i<c2;i++){
            vet_c2[i]=i;
        }
        for(i=0;i<l1;i++){
            for(j=0;j<c2;j++){
                mat_mult[i][j]=0;
                for(x=0;x<l2;x++){
                    mat_mult[i][j]+=mat1[i][x]*mat2[x][j];
                }

            }
        }
        printf("A Matriz resultande da multiplicao de matrizes:\n\n");
        imprimir(mat_mult,l_mult,c_mult);
    }else{
        printf("Nao e possivel fazer multiplicao dessas matrizes\n");
    }
    return 0;
}

void preencher_matriz(int **mat, int l, int c){
    int i=0,j=0;
    
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            mat[i][j]=rand()%5+1;
        }
    }
}

void imprimir(int **mat, int l, int c){
    int i=0,j=0;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%4d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}