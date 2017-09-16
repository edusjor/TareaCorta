//BubleSort
//----------------------------------------------------------------------------
// Filename: BubbleSort.htm
// Bubble Sort v1.0
// by Paul Bladek
// March 13, 2003
// compiled using MS Visual C++ 6.0
// An Examples of a Bubble Sort
//----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <stdio.h>
using namespace std;

// function prototypes 

template <class T>
void printArray(T ar[], int sz);
template <class T>
void bubbleSort(T ar[], int sz);
int numeroAleatorio(int);
void CrearArchivo();
void guardar(double arraySegundos[], int arrayElementos[]);


int main()
{


/*
	//int sa[SIZE] = {3,4,7,1,4};
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	

	

	CrearArchivo();
	int SIZE = 100;
	int sa[SIZE];
	
		for (int i=0; i<SIZE; i++){
			sa[i]=rand();
		}

		// test array
		cout << "Unsorted array:" << endl;
	  	//printArray(sa, SIZE);

	  	tiempo_inicio = clock();
		bubbleSort(sa,SIZE);
		tiempo_final = clock();

       	cout << "Sorted array:" << endl;
		//printArray(sa, SIZE);

		segundos = (double)( tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC; //según que estes midiendo el tiempo en segundos es demasiado grande
	
	    cout<<endl<<endl<<endl<<"segundos: "<<segundos<<endl;


		//
		
		guardar(segundos,SIZE);
		cin.get(); // hold window open
  		return EXIT_SUCCESS;
*/
		
	
	

  //int sa[SIZE] = {3,4,7,1,4};
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	int maxElem=3000;
	double arraySegundos[maxElem];
	int arrayElementos[maxElem];
	int sa[maxElem];//array con numeros aleatorios

	CrearArchivo();
	//int SIZE = 10;
	int cont=0;
	for (int qElem=1;qElem<maxElem;qElem+=10){
		

		for (int i=0; i<qElem; i++){ // crea maxElem numero de numeros aleatorios agregandolos al array
			sa[i]=rand();

		}

		//cout<<endl<<sizeof(sa)<<endl;
		// test array
		//cout << "Unsorted array:" << endl;
	  	//printArray(sa, SIZE);

	  	tiempo_inicio = clock();
		bubbleSort(sa,qElem);
		tiempo_final = clock();

       	//cout << "Sorted array:" << endl;
		//printArray(sa, SIZE);

		segundos = (double)( tiempo_final-tiempo_inicio) / CLOCKS_PER_SEC; //según que estes midiendo el tiempo en segundos es demasiado grande
	
	    //cout<<endl<<endl<<endl<<"segundos: "<<segundos<<endl;


		//
		arraySegundos[cont]=segundos;
		arrayElementos[cont]=qElem;
		cont+=1;

			
		

		
	}
	guardar(arraySegundos,arrayElementos);
	cout<<endl<<"guardado"<<endl;

	//cin.get(); // hold window open
  	return EXIT_SUCCESS;
  
}

void CrearArchivo()
{

	FILE *archivo;
	archivo = fopen("GraficaBubbleSort.csv","wt");

	if (archivo!=NULL){
		printf("\nEl archivo se creo correctamente\n");
	}
	else{
		puts("No se pudo crear el archivo");
	}
}











void guardar(double arraySegundos[], int arrayElementos[]){
	ofstream archivo;
	archivo.open("GraficaBubbleSort.csv",ios::out);

	if (archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	int cont=0;
	while (1){
		if(arrayElementos[cont]==0)
			break;
		cont+=1;
	}
	

	for (int i=0; i<cont;i++){


		archivo<<to_string(arraySegundos[i])+","+to_string(arrayElementos[i])+"\n";
	}
	
	archivo.close();
}

//----------------------------------------------------------------------------
// prints array of size size
//----------------------------------------------------------------------------
template <class T>
void printArray(T array[], int size)
{
  for(int i = 0; i < size; i++)
    cout << array[i] << " \n";
  cout << endl;
}

//----------------------------------------------------------------------------
// sorts array of size size by Bubble Sort method
//----------------------------------------------------------------------------
template <class T>
void bubbleSort(T array[], int size)
{

  bool noChange = true; // stop when a pass causes no change
  for(int i = size; i > 0; i--)
  {
    noChange = true;
    for(int j = 1; j < i; j++)
    {
      if(array[j] < array[j - 1])
      {
        swap(array[j], array[j-1]);
        noChange = false;
      } // end if
    } // end for(j)
    if (noChange)
      return; // sorted--no need to continue
  } // end for(i) 
}
