#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 5
#define M 7

void cargarDatos(int *matrizDinamica);
void mostrarDatos(int *matrizDinamica);


int main(){

int acum=0;

int *matrizDinamica= (int *) malloc(sizeof(int)*M*N);


 cargarDatos(matrizDinamica);
 mostrarDatos(matrizDinamica);

int mn=0;
int pn=49000;
int mes=1;
int anio=1;

for (int i = 0; i < 5; i++)
{
   for (int j = 0; j < 7; j++)
   {
    
        if (*((matrizDinamica + i * M) +j ) > mn)
        {
            mn=*((matrizDinamica + i * M) +j );

            mes=j+1;
            anio=i+1;
       
        }
   
   }
   
}

printf("el valor mas alto fue %d\n",mn);
    printf("mes : %d\n",mes);
      printf("anio : %d\n",anio);






return 0;

 }


void cargarDatos(int *matrizDinamica){

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 7; j++)
    {
        

     *((matrizDinamica + i * M) +j ) = 1+rand()%(100-10);
  

    }


} 





}
 
void mostrarDatos(int * matrizDinamica){


for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 7; j++)
    {
        

    
     printf("%4d", *((matrizDinamica +i *M)+j));

    }

   printf("\r\n");

} 


 }