#include <stdio.h>
#include <time.h>
//biblioteca del tiempo
#include <stdlib.h>
//biblioteca de srand

void generarMatriz(int [][20], int, int);
void imprimirMatriz(int [][20], int, int, char [][4],char [][11]);
void sumarColumnas(int [][20], int, int,char[][11],int);
void sumarFilas(int x[][20],int, int,char [][4],int);
void Estadisticas(int [][20], int, int ,char[][4],char[][11],int);
int SumatoriaTotal(int [][20], int,int);

main(){
char Partido[][4]={"PUM","CHI","AME"};
char Municipio[][11]={"Puebla","Huejo","San Andres","San Pedro","Atlixco","Amalucan"};
int x[20][20];
int n,m;
int sumat;

n=3;
  //Filas
m=6;
  //Columnas
srand(time(NULL));
  //Funcion de randomizacion de semilla para generacion
  //de datos aleatorios distintos para cada vez que se
  //ejecute el programa
generarMatriz(x,n,m);
imprimirMatriz(x,n,m, Partido ,Municipio);
sumat = SumatoriaTotal(x,n,m);
printf("\nEl total de votos es %d",sumat);
sumarColumnas(x,n,m,Municipio,sumat);
printf("\n========================================");  
sumarFilas(x,n,m,Partido,sumat);
printf("\n========================================");  
Estadisticas(x, n ,m, Partido, Municipio, sumat);

}

void Estadisticas(int x[][20], int n, int m,char Partido[][4],char Municipio[][11], int sumat)
{
  int i,j,suma=0,mayor=0,pos=0;
  float porc;
  for(j=0;j<m;j++){
    suma=0;
    //Se reinicia nuestra sumatoria para poder hacer
    //el calculo separado de cada columna
    for(i=0;i<n;i++){
      //Saltos entre filas sin cambiar de columna
      //para calcular la sumatoria de toda la columna
    suma+=x[i][j];
    }

    if(suma>mayor){
      mayor=suma;
      pos=j;
      //Se comparan los valores de cada sumatoria de las
      //columnas y se guarda el valor con mayor numero de
      //votos en la variable mayor y la posicion en la que
      //se encuentra este valor en la matriz. 
 //Esto para poder determinar el nombre del municipio que
      //tiene mayor numero de votos.
    }
  }
  porc= (mayor*100.0)/sumat;
   printf("\n\nEl municipio con mayor votos es %s con %d votos con %0.2f porciento",Municipio[pos],mayor,porc);
  
 

    for(i=0;i<n;i++){
      suma=0;
      //Se reinicia nuestra sumatoria para poder hacer
      //el calculo separado de cada fila
      for(j=0;j<m;j++){
        //Saltos entre columna sin cambiar de fila
        //para calcular la sumatoria de toda la fila
      suma+=x[i][j];
      }

      if(suma>mayor){
          mayor=suma;
        pos=i;
//Se comparan los valores de cada sumatoria de las
//columnas y se guarda el valor con mayor numero de
//votos en la variable mayor y la posicion en la que
//se encuentra este valor en la matriz. 
//Esto para poder determinar el nombre del municipio que
//tiene mayor numero de votos.
}

    }
   porc= (mayor*100.0)/sumat;
  printf("\nEl partido con mayor votos es %s con %d votos con %0.2f porciento",Partido[pos],mayor,porc);
  
}


void sumarColumnas(int x[][20],int n, int m,char Municipio[][11],int sumat)
{
  int i,j,suma=0, mayor;
  float porc;	

  for(j=0;j<m;j++){
        suma=0;
    //Se reinicia nuestra sumatoria para poder hacer
    //el calculo separado de cada columna
        for(i=0;i<n;i++){
        suma+=x[i][j];
    //Saltos entre filas sin cambiar de columna
    //para calcular la sumatoria de toda la columna
        }
        printf("\n\n%s",Municipio[j]);
     porc= (suma*100.0)/sumat;
    printf("\n%d votos\nRepresenta el %0.2f porciento",suma,porc);

  }

}


void sumarFilas(int x[][20],int n, int m,char Partido[][4],int sumat)
{
int i,j,suma=0;
float porc=0;	

for(i=0;i<n;i++){
  suma=0;
  //Se reinicia nuestra sumatoria para poder hacer
  //el calculo separado de cada fila
  for(j=0;j<m;j++){
    //Saltos entre columna sin cambiar de fila
    //para calcular la sumatoria de toda la fila
  suma+=x[i][j];
  }
  printf("\n\n%s",Partido[i]);
   porc= (suma*100.0)/sumat;
  printf("\n%d votos\nRepresenta el %0.2f porciento",suma,porc);
  
   
}
}


void generarMatriz(int x[][20], int n, int m)
{
   int i,j;
for(i=0;i<n;i++)
{
  for(j=0;j<m;j++)
  {
    x[i][j]=50+rand()%800;}
  //Asignación de valores a las celdas de la matriz 
  //desde 50 más un numero aleatorio entre 0 y 800
  }
}


void imprimirMatriz(int x[][20], int n, int m,char Partido[][4],char Municipio[][11])
{
   int i,j;
  printf("\t");
   for(i=0;i<m;i++)
   printf("%s ",Municipio[i]);
//Se imprimen los municipios como encabezado con el ciclo
  
  for(i=0;i<n;i++)
  {
    printf("\n%s ",Partido[i]);
    //Se comienza cada fila con su partido antes de comenzar
    //a imprimir los valores de cada celda de la matriz
   for(j=0;j<m;j++)
   {
    printf("  %d \t ",x[i][j]);
   }
  // printf("\n");

  }

}

int SumatoriaTotal(int x[][20], int n, int m)
{
  int i,j;
  int sumat=0;
  for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
       sumat+=x[i][j];
//Vamos celda por celda y sumamos el valor de cada una para terminar con la sumatoria de toda la matriz
        }
    }
    return sumat;
//Regresamos el valor de la sumatoria para trabajarlo con
//demás funciones
}
