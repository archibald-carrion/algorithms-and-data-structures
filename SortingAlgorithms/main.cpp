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

void quicksort(deque<int> deck)
{
}

deque<int> merge(deque<int> deckA, deque<int> deckB)
{
	deque<int> deckC;

	while (!deckA.empty() || !deckB.empty())
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
	if (n == 1){
		return deck;
	} else
	{
		cout<<"a"<<endl;
		deque<int> deckA;
		deque<int> deckB;

		for (unsigned int i = 0; i < n / 2; ++i)
		{
			cout<<"b"<<endl;
			deckA.push_front(deck[i]);
		}
		for (unsigned int i = n / 2; i < n; ++i)
		{
			cout<<"c"<<endl;
			deckB.push_front(deck[i]);
		}
		cout<<"d"<<endl;
		mergesort(deckA);
		mergesort(deckB);
		return merge(deckA, deckB);
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

	//bubblesort(deck);
	mergesort(deck);

	cout << "\n#####################################\n"
		 << endl;

	for (auto i = deck.begin(); i != deck.end(); ++i)
	{
		cout << *i << endl;
	}

	return 0;
}
