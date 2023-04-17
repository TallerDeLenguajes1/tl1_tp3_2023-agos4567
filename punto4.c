#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define MAX 50
char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”

}typedef Cliente;


void CargarClientes(Cliente *puntC, int cantCliente);
void MostrarClientes(Cliente *puntC, int cantCliente);
float PrecioTotal(Producto *puntP);
void liberarMemoria(Cliente *puntC, int cantCliente);

int main(){

Cliente *puntC;
int cantCliente;

printf("ingrese la cantidad de clientes:\n");

scanf("%d",&cantCliente);



if (cantCliente < 5)
{
    fflush(stdin);

puntC= malloc(sizeof(Cliente)*cantCliente);

 CargarClientes(puntC, cantCliente);
MostrarClientes(puntC, cantCliente);
liberarMemoria(puntC, cantCliente);



}else{
    printf("no puede cargar mas de 5 clientes\n");
}









    return 0;
}




void CargarClientes(Cliente *puntC, int cantCliente){
char Buff[100];
int auxP;
srand(time(NULL));

printf("      Cargar pedidos   \n");

for (int i = 0; i < cantCliente; i++)
{
    puntC->ClienteID=i+1;
    printf("---Cliente ID----%d\n",puntC->ClienteID);
    fflush(stdin);
    printf("Ingrese Nombre:\n");
    fflush(stdin);
    gets(Buff);
    
    puntC->NombreCliente=malloc(sizeof(char)*(strlen(Buff)+1));
    strcpy(puntC->NombreCliente,Buff);

   puntC->CantidadProductosAPedir=rand()%5+1;


   puntC->Productos=malloc(puntC->CantidadProductosAPedir*sizeof(Producto));
    

   for (int j = 0; j < puntC->CantidadProductosAPedir; j++)
   {
    


   puntC->Productos[j].ProductoID=j+1;
   puntC->Productos[j].Cantidad=rand()%10+1;
   puntC->Productos[j].PrecioUnitario=rand()%(100-10)+10;
   auxP=rand()%5;
   puntC->Productos[j].TipoProducto=tiposProductos[auxP];

   


   }
   

puntC++;

}


}


void MostrarClientes(Cliente *puntC, int cantCliente){

printf("\n----------M O S T R A R --------------\n");

for (int i = 0; i < cantCliente; i++)
{

    float costoTotal=0;
     printf("             Cliente ID:%d \n ",puntC->ClienteID);
     printf("El nombre es: ");
     puts(puntC->NombreCliente);
     fflush(stdin);
     printf("cantidad de productos a pedir (valor aleatorio):%d\n",puntC->CantidadProductosAPedir);
      for (int j = 0; j <  puntC->CantidadProductosAPedir; j++)
      {
       

         printf(" ********* Producto cargado nro : %d *********\n",puntC->Productos->ProductoID);
          printf("Cantidad :%d\n",puntC->Productos->Cantidad);
          printf("Tipo de producto: ");
        puts(puntC->Productos->TipoProducto);
        printf("Precio del producto: %.2f\n",puntC->Productos->PrecioUnitario);
        costoTotal= costoTotal + PrecioTotal(puntC->Productos);
      
       
        puntC->Productos++;
      }
        
       printf("el total a pagar del cliente %.2f\n",costoTotal);
      puntC++;
  printf("\n");
}

}



void liberarMemoria(Cliente *puntC, int cantCliente){

    for (int i = 0; i < cantCliente; i++)
    {
        free(puntC->NombreCliente);
        free(puntC->Productos);
        puntC++;
    }
    free(puntC);
}

float PrecioTotal(Producto *puntP){
   
  return (puntP->Cantidad  * puntP->PrecioUnitario);

 }




