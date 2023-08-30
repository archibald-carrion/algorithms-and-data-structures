#ifndef Ordenador_h
#define Ordenador_h

#include <iostream>

class Ordenador
{
private:
	// Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
	// Puede definir cuantos métodos quiera.

	void merge(int *A, int *A0, int n0, int *A1, int n1)
	{
		size_t i = 0, j = 0, k = 0;

		while (i < n0 && j < n1)
		{
			if (A0[i] < A1[j])
			{
				A[k++] = A0[i++];
			}
			else
			{
				A[k++] = A1[j++];
			}
		}

		while (i < n0)
		{
			A[k++] = A0[i++];
		}

		while (j < n1)
		{
			A[k++] = A1[j++];
		}
	}

	void monticularizar(int *A, int n, int i)
	{
		int biggest = i;
		// using the given formula, we calculate the index of left & right sons
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && A[left] > A[biggest])
			biggest = left;

		if (right < n && A[right] > A[biggest])
			biggest = right;

		if (biggest != i)
		{
			// swap A[i] and A[biggest]
			int buffer = A[i];
			A[i] = A[biggest];
			A[biggest] = buffer;
			monticularizar(A, n, biggest);
		}
	}

	int partition(int *A, const int &lower, const int &upper)
	{
		// by default the pivot is the element at the right-most cell of the array
		int pivot = A[upper];
		int i = (lower - 1);

		for (int j = lower; j <= upper - 1; ++j)
		{
			// exchange the elements while the policias haven't met
			if (A[j] < pivot)
			{
				i++;
				int buffer = A[i];
				A[i] = A[j];
				A[j] = buffer;
			}
		}
		int buffer = A[i + 1];
		A[i + 1] = A[upper];
		A[upper] = buffer;
		return (i + 1);
	}

	void quicksort(int *A, const int &lower, const int &upper)
	{
		if (lower < upper)
		{
			int pivot = partition(A, lower, upper);
			quicksort(A, lower, pivot - 1);
			quicksort(A, pivot + 1, upper);
		}
	}

	int get_Nth_digit(int number, int index)
	{
		int div = 1;
		for (int i = 0; i < index; ++i)
		{
			div *= 10;
		}

		int digit = (number / div) % 10;
		return digit;
	}

	// index is the digit that must be studied
	void sort_Nth_digit(int *A, int n, int index)
	{
		int *B = new int[n];
		const int DIGIT_QUANTITY = 19;
		int counters[DIGIT_QUANTITY];
		// set as 0 every cell of counters
		for (size_t i = 0; i < DIGIT_QUANTITY; i++)
		{
			counters[i] = 0;
		}

		// count how many occurence of each digit and store it in counters
		for (size_t i = 0; i < n; ++i)
		{
			int index_number = get_Nth_digit(A[i], index) + 9;
			counters[index_number] = counters[index_number] + 1;
			// we add 9 to the index, because get_Nth_digit return a
			// value between -9 and 9, and we want an index in [0, 19]
		}
		// transform counters to be the accumulate values
		int buffer = 0;
		for (size_t i = 0; i < DIGIT_QUANTITY; i++)
		{
			buffer += counters[i];
			counters[i] = buffer;
		}

		// "paso magico"
		for (int i = n - 1; i >= 0; --i)
		{
			int index_number = get_Nth_digit(A[i], index) + 9;
			int new_index = counters[index_number];
			B[new_index - 1] = A[i];
			counters[index_number] = counters[index_number] - 1;
		}

		// copy B into A
		for (size_t i = 0; i < n; i++)
		{
			A[i] = B[i];
		}

		delete[] B;
	}

public:
	Ordenador(){};
	~Ordenador(){};
	// Si no implementa algunos de los métodos de ordenamiento no lo borre;
	// déjelo con el cuerpo vacío para evitar errores de compilación, ya
	// que se va a ejecutar el mismo «main» para todas las tareas.
	// Implemente los algoritmos en este archivo, no en un CPP.
	void seleccion(int *A, int n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			int minimum = i;
			for (size_t j = i + 1; j < n; ++j)
			{
				if (A[j] < A[minimum])
				{
					minimum = j;
				}
			}
			// switch both value
			int buffer = A[i];
			A[i] = A[minimum];
			A[minimum] = buffer;
		}
	}

	void insercion(int *A, int n)
	{
		for (size_t i = 1; i < n; ++i)
		{
			int j = i;
			while (j > 0 && A[j - 1] > A[j])
			{
				int buffer = A[j];
				A[j] = A[j - 1];
				A[j - 1] = buffer;
				j = j - 1;
			}
		}
	}

	void mergesort(int *A, int n)
	{
		if (n < 2)
		{
			return;
		}

		int half = n / 2;
		int *A0 = new int[half];
		int *A1 = new int[n - half];

		for (size_t i = 0; i < half; ++i)
		{
			A0[i] = A[i];
		}

		for (size_t i = half; i < n; ++i)
		{
			A1[i - half] = A[i];
		}

		mergesort(A0, half);
		mergesort(A1, n - half);
		merge(A, A0, half, A1, n - half);

		delete[] A0;
		delete[] A1;
	}

	void heapsort(int *A, int n)
	{
		for (int i = n / 2 - 1; i >= 0; --i)
		{
			monticularizar(A, n, i);
		}

		for (int i = n - 1; i >= 0; i--)
		{
			// swap A[0] and A[i]
			int buffer = A[0];
			A[0] = A[i];
			A[i] = buffer;
			monticularizar(A, i, 0);
		}
	}

	void quicksort(int *A, int n)
	{
		quicksort(A, 0, n - 1);
	}

	void radixsort(int *A, int n)
	{
		int max_digit_quantity = 10;
		for (size_t i = 0; i < max_digit_quantity; ++i)
		{
			sort_Nth_digit(A, n, i);
		}
	}
};
#endif
