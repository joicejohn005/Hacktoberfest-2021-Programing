#include <iostream>
#include "DynIntQueue.h"
int main()
{
	const int MAX_VALUES = 6;
	// CREATE a DynIntQueue object
	DynIntQueue Queue;

	//enquire a series of numbers
	cout << "Enqueuing " << MAX_VALUES << " items....\n";
	for (int x = 0; x < MAX_VALUES; x++)
	{
		Queue.enqueue(x);
	}

	//dequeue and retrieve all numbers in the queue
	cout << "The values in the queue were:\n";

	while (!Queue.isEmpty())
	{
		int value; //dummy variable
		Queue.dequeue(value);
		cout << value << " ";
	}
	cout << endl;
	cout << "The problem end\n";
	system("pause");
	return 0;
}
