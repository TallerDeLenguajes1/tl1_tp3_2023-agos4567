#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



int main(){

char **VectorChar;
char *Buff;
int nombre=0;


Buff= (char *) malloc(100*sizeof(char));
VectorChar=(char **)malloc(sizeof(int*)*5);
//cargo 5 nombres 
for (int i = 0; i < 5; i++)
{
    
   printf("ingrese el nombre numero %d\n",i+1);
   gets(Buff);
    fflush(stdin);
      nombre=strlen(Buff);
  
     
    VectorChar[i]=(char *)malloc(sizeof(char)*nombre);



    strcpy(VectorChar[i], Buff);
    printf("\n");


}



//mostrar nombres
for (int i = 0; i < 5; i++)
{
   printf("el nombre numero %d ingresado es ", i+1);
   puts(VectorChar[i]);
   printf("\n");
}





for (int i = 0; i < 5; i++)
{
  free(Buff);
free(VectorChar);
}



    return 0;
}