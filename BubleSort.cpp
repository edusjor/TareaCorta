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
using namespace std;

// function prototypes 
const int SIZE = 10000;
template <class T>
void printArray(T ar[], int sz);
template <class T>
void bubbleSort(T ar[], int sz);
int numeroAleatorio(int);


int main()
{
  //int sa[SIZE] = {3,4,7,1,4};


	int sa[SIZE];


	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	tiempo_inicio = clock();

	for (int i=0; i<SIZE; i++){
		sa[i]=rand();
	}
	


  // test array
  cout << "Unsorted array:" << endl;
  printArray(sa, SIZE);

  bubbleSort(sa,SIZE);

  cout << "Sorted array:" << endl;
  printArray(sa, SIZE);

    tiempo_final = clock();

	segundos = (double)(tiempo_inicio - tiempo_final) / CLOCKS_PER_SEC; /*según que estes midiendo el tiempo en segundos es demasiado grande*/

    cout<<endl<<endl<<endl<<segundos<<endl;
	printf("%f",segundos); 

  cin.get(); // hold window open

  return EXIT_SUCCESS;
}


//----------------------------------------------------------------------------
// prints array of size size
//----------------------------------------------------------------------------
template <class T>
void printArray(T array[], int size)
{
  for(int i = 0; i < size; i++)
    cout << array[i] << " ";
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
