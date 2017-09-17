//QuickSort.cpp


//SelectionSort
//----------------------------------------------------------------------------

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
void swap(T* val1, T* val2);
template <class T>
int partition(T arr[], int low, int high);
template <class T>
void quicksort(T arr[], int low, int high);
int numeroAleatorio(int);
void CrearArchivo();
void guardar(double arraySegundos[], int arrayElementos[]);


int main()
{



		
	
	

  //int sa[SIZE] = {3,4,7,1,4};
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	int maxElem=1000;
	double arraySegundos[maxElem];
	int arrayElementos[maxElem];
	int sa[maxElem];//array con numeros aleatorios

	
	CrearArchivo();
	//int SIZE = 10;
	int cont=0;
	for (int qElem=1;qElem<=maxElem;qElem+=10){
		

		for (int i=0; i<qElem; i++){ // crea maxElem numero de numeros aleatorios agregandolos al array
			sa[i]=rand();

		}

		//cout<<endl<<sizeof(sa)<<endl;
		// test array
		//cout << "Unsorted array:" << endl;
	  	//printArray(sa, SIZE);
	  	int minim=0;

	  	tiempo_inicio = clock();
	
		quicksort(sa, minim, qElem);
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
	archivo = fopen("GraficaQuickSort.csv","wt");

	if (archivo!=NULL){
		printf("\nEl archivo se creo correctamente\n");
	}
	else{
		puts("No se pudo crear el archivo");
	}
}



void guardar(double arraySegundos[], int arrayElementos[]){
	ofstream archivo;
	archivo.open("GraficaQuickSort.csv",ios::out);

	if (archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	int cont=0;   
	while (1){          			//recorre el array y cuando encuentra aun 0 es que ya recorrio todo
		if(arrayElementos[cont]==0) //y entonces el contador actual sera la cantidad de elmementos en el array
			break;
		cont+=1;
	}
	

	for (int i=0; i<cont;i++){


		archivo<<to_string(arrayElementos[i])+","+to_string(arraySegundos[i])+"\n";
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
void swap(T* val1, T* val2)
{
	int temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

template <class T>
int partition(T arr[], int low, int high)
{
	int i = low-1, j = low;
	int key = arr[high];

	while(j < high)
	{
		if(arr[j] <= key)
		{
			i++;
			if(i!=j)
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i+1], &arr[high]);	
	return i+1;
}

template <class T>
void quicksort(T arr[], int low, int high)
{
	int part;
	if(low < high)
	{
		part = partition(arr, low, high);
		quicksort(arr, low, part-1);
		quicksort(arr, part+1, high);
	}
 }