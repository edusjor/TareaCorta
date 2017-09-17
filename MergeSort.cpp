//MergeSort.cpp
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
void merge_sort(T arr[], int size);
template <class T>
void merge_sort(T a[], int low, int high);
template <class T>
void merge(T a[], int left_low, int left_high, int right_low, int right_high);
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

	  	tiempo_inicio = clock();
		merge_sort(sa,qElem);
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
	archivo = fopen("GraficaMergeSort.csv","wt");

	if (archivo!=NULL){
		printf("\nEl archivo se creo correctamente\n");
	}
	else{
		puts("No se pudo crear el archivo");
	}
}



void guardar(double arraySegundos[], int arrayElementos[]){
	ofstream archivo;
	archivo.open("GraficaMergeSort.csv",ios::out);

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
void merge_sort(T a[], int length) {
    merge_sort(a, 0, length-1);
}

template <class T>
void merge_sort(T a[], int low, int high) {
    if (low >= high)                  //Base case: 1 value to sort->sorted
      return;                         //(0 possible only on initial call)
    else {
      int mid = (low + high)/2;       //Approximate midpoint*
      merge_sort(a, low, mid);        //Sort low to mid part of array
      merge_sort(a, mid+1, high);     //Sort mid+1 to high part of array
      merge(a, low, mid, mid+1,high); //Merge sorted subparts of array
    }
}

template <class T>
void merge(T a[], int left_low, int left_high, int right_low, int right_high) 
{ 
    int length = right_high-left_low+1;
    int temp[length];
    int left = left_low;
    int right = right_low;
    for (int i = 0; i < length; ++i) { 
        if (left > left_high)
            temp[i] = a[right++];
        else if (right > right_high)
            temp[i] = a[left++];
        else if (a[left] <= a[right])
            temp[i] = a[left++];
        else
            temp[i] = a[right++]; 
    }
    
    for (int i=0; i< length; ++i) 
        a[left_low++] = temp[i];
}

