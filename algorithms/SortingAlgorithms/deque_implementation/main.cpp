#include <iostream>
#include <string>
#include <deque>

using namespace std;

void bubblesort(deque<int> &deck)
{
	int cantity = deck.size();
	for (unsigned int i = 0; i < cantity; ++i)
	{
		for (unsigned int j = i; j < cantity; ++j)
		{
			if (deck[i] > deck[j])
			{
				unsigned int buffer = deck[j];
				deck[j] = deck[i];
				deck[i] = buffer;
			}
		}
	}
}

/*
partition is a function used by the quicksort algorithm
*/
int partition(deque<int> &deck, int low, int high)
{
	// deck is given by reference, that way we can directly modify the array
	int pivot = deck[low];

	int count = 0;
	for (int i = low + 1; i <= high; i++)
	{
		if (deck[i] <= pivot)
			count++;
	}

	int pivotIndex = low + count;
	swap(deck[pivotIndex], deck[low]);
	int i = low, j = high;

	while (i < pivotIndex && j > pivotIndex)
	{

		while (deck[i] <= pivot)
		{
			i++;
		}

		while (deck[j] > pivot)
		{
			j--;
		}

		if (i < pivotIndex && j > pivotIndex)
		{
			swap(deck[i++], deck[j--]);
		}
	}

	return pivotIndex;
}

/*
quicksort function, a recursive function that use the partition function to correctly sort a given array
it's a divide and conquer algorithm
*/
void quicksort(deque<int> &deck, int low, int high)
{
	if (low < high)
	{
		int pivot_location = partition(deck, low, high);
		quicksort(deck, low, pivot_location - 1);
		quicksort(deck, pivot_location + 1, high);
	}
}

deque<int> merge(deque<int> deckA, deque<int> deckB)
{
	deque<int> deckC;

	while (!deckA.empty() && !deckB.empty())
	{
		if (deckA[0] > deckB[0])
		{
			deckC.push_back(deckB[0]);
			deckB.pop_front();
		}
		else
		{
			deckC.push_back(deckA[0]);
			deckA.pop_front();
		}
	}

	while (!deckA.empty())
	{
		deckC.push_back(deckA[0]);
		deckA.pop_front();
	}

	while (!deckB.empty())
	{
		deckC.push_back(deckB[0]);
		deckB.pop_front();
	}

	return deckC;
}

deque<int> mergesort(deque<int> deck)
{
	unsigned int n = deck.size();
	if (n == 1)
	{
		return deck;
	} // else
	//{
	// cout<<"a"<<endl;
	deque<int> deckA;
	deque<int> deckB;

	for (unsigned int i = 0; i < n / 2; ++i)
	{
		// cout<<deck[i]<<endl;
		deckA.push_front(deck[i]);
	}
	for (unsigned int i = n / 2; i < n; ++i)
	{
		// cout<<deck[i]<<endl;
		deckB.push_front(deck[i]);
	}
	// cout<<"d"<<endl;
	deckA = mergesort(deckA);
	deckB = mergesort(deckB);
	return merge(deckA, deckB);
	//}
}

void selectionSort(deque<int> &deck)
{
	int deckSize = deck.size();
	for (int i = 0; i < deckSize - 1; ++i)
	{
		int minimum = i;
		for (int j = i + 1; j < deckSize; ++j)
		{
			if (deck[j] < deck[minimum])
			{
				minimum = j;
			}
		}
		// switch between both values
		int buffer = deck[i];
		deck[i] = deck[minimum];
		deck[minimum] = buffer;
		// intercambiar(lista , i , minimo);
	}
}

void selectionSortRecursive(deque<int> &deck, int index)
{
	int deckSize = deck.size();
	int minimum = index;
	for (int j = index + 1; j < deckSize; ++j)
	{
		if (deck[j] < deck[minimum])
		{
			minimum = j;
		}
	}

	// switch between both values
	int buffer = deck[index];
	deck[index] = deck[minimum];
	deck[minimum] = buffer;

	if (index + 1 < deckSize)
	{
		selectionSortRecursive(deck, index + 1);
	}
}

int main()
{
	deque<int> deck;
	deck.push_front(34123);
	deck.push_front(0);
	deck.push_front(978);
	deck.push_front(12);
	deck.push_front(5);
	deck.push_front(77);
	deck.push_front(3);
	deck.push_front(321);

	for (auto i = deck.begin(); i != deck.end(); ++i)
	{
		cout << *i << endl;
	}

	// bubblesort(deck);
	// deck = mergesort(deck);
	// quicksort(deck, 0, deck.size()-1);
	// selectionSort(deck);
	selectionSortRecursive(deck, 0);

	cout << "\n#####################################\n"
		 << endl;

	for (auto i = deck.begin(); i != deck.end(); ++i)
	{
		cout << *i << endl;
	}

	return 0;
}
