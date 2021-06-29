#include <iostream>

using namespace std;

struct wood
{
	int Key;
	int Count;
	wood* Left;
	wood* Right;
};

class TREE
{
private:
	wood* Tree;
	void FindPlace(wood**, int);
public:
	TREE() { Tree = NULL; };
	~TREE() {};
	wood** GetTree() { return &Tree; };
	void Construction(int*, int);
	void Clear(wood**);
	void PrintTree(wood**);
	void Search(wood**, int);
};

void TREE::Construction(int* arr, int size)
{
	for (int i = 0; i < size; i++)	
		FindPlace(&Tree, arr[i]);
}

void TREE::FindPlace(wood** pHead, int element)
{
	if (*pHead == NULL)
	{
		*pHead = new(wood){ element, 1, NULL, NULL };
	}
	else
	{
		if ((**pHead).Key > element)
		{
			FindPlace(&(**pHead).Left, element);
		}
		else if ((**pHead).Key < element)
		{
			FindPlace(&(**pHead).Right, element);
		}
		else
		{
			(**pHead).Count = (**pHead).Count + 1;
		}
	}
}

void TREE::Clear(wood** pHead)
{
	if (*pHead != NULL)
	{
		Clear(&(**pHead).Left);
		Clear(&(**pHead).Right);
		//cout << "Delete " << (**pHead).Key << endl;
		delete* pHead;
	}
}

void TREE::PrintTree(wood** pHead)
{
	if (*pHead != NULL)
	{
		PrintTree(&(**pHead).Left);
		cout << " Key: " << (**pHead).Key << " Count: " << (**pHead).Count << endl;
		PrintTree(&(**pHead).Right);
	}
}


void TREE::Search(wood** pHead, int element)
{
	if (*pHead != NULL)
	{
		if ((**pHead).Key > element)
		{
			Search(&(**pHead).Left, element);
		}
		else if ((**pHead).Key < element)
		{
			Search(&(**pHead).Right, element);
		}
		else if ((**pHead).Key == element)
		{
			cout << "Search element: " << element << " Key: " << (**pHead).Key << " Count: " << (**pHead).Count << endl;
		}
	}
	else
	{
		cout << "Search element: " << element << " is missing" << endl;
	}
}


int main()
{
	int size = 10;
	int* a = new int[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}

	TREE tr;
	cout << endl;
	tr.Construction(a, size);
	tr.PrintTree(tr.GetTree());
	
	tr.Search(tr.GetTree(), 99);

	tr.Clear(tr.GetTree());
	delete[] a;
	return 0;
}