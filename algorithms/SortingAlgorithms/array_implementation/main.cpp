#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Ordenador.h"

int *create_array(int n)
{
  // use the time as a seed for the random function
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  // allocate in the heap the correct memory size needed
  int *array = new int[n];
  // give to each of the value in the array a random value from
  // -2147483648 to 2147483647
  for (size_t i = 0; i < n; ++i)
  {
    array[i] = (std::rand() - RAND_MAX / 2) * 2;
  }

  return array;
}

void print_array(int *A, int n)
{
  for (size_t i = 0; i < n; ++i)
  {
    std::cout << A[i] << std::endl;
  }
}

int main()
{
  int quantity_elements = 200000;
  int *my_array = create_array(quantity_elements);
  Ordenador ordenador;

  // std::cout << "Before using merge sort: " << std::endl;
  // print_array(my_array, quantity_elements);

  auto start = std::chrono::high_resolution_clock::now();
  // ############################################################################

  // ordenador.seleccion(my_array, quantity_elements);
  // ordenador.insercion(my_array, quantity_elements);
  //  ordenador.mergesort(my_array, quantity_elements);
  // ordenador.heapsort(my_array, quantity_elements);
  // ordenador.quicksort(my_array, quantity_elements);
  ordenador.radixsort(my_array, quantity_elements);

  // ############################################################################
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end - start;
  std::cout << "Execution time (msec): " << elapsed.count() << std::endl;
  // std::cout << " \n After using merge sort: " << std::endl;
  // print_array(my_array, quantity_elements);
  delete[] my_array;
  return 0;
}
