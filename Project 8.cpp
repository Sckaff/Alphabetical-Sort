//Fernando Sckaff
//COP2000.0M1
//Reading a given file with 20 string inputs and arranging them in alphabetical order

#include<iostream>
#include <string>
#include <fstream>

using std::string;
using std::ifstream;

class Student
{
	//Private member variables
private:
	ifstream in;
	string names[20],	//Array of strings
		minName;		//The minimum name element found on the array at a certain point (closer to the beginning of the alphabet)
	int minIndex;		//The minimum names array subscript that contains minName (on the arraySort function)

	//Public member functions
public:
	Student();
	void maintenance();
	void arraySort();
	void display();
};

//Constructor
Student::Student()
{
	minIndex = 0;
}

//Open the File
void Student::maintenance()
{
	using std::cerr;
	using std::endl;

	in.open("students.txt"); //Open the file

	if (!in) //Test to see whether the file opened properly
	{
		cerr << "The file did not open properly." << endl << endl;
		exit(404);
	}

	for (int i = 0; i < 20; i++) //Reading the file
	{
		in >> names[i];
	}

	in.close(); //Close the file
}

//The sorting algorithm mimicking the selection sort
void Student::arraySort()
{
	for (int fIndex = 0; fIndex < 19; fIndex++)
	{
		minIndex = fIndex;
		minName = names[fIndex];

		for (int sIndex = fIndex + 1; sIndex < 20 ; sIndex++)
		{
			if (names[sIndex] < minName)
			{
				minIndex = sIndex;
				minName = names[sIndex];
			}
		}
		names[minIndex] = names[fIndex];
		names[fIndex] = minName;
	}
}

//Display the desired output by the user
void Student::display()
{
	using std::cout;
	using std::endl;

	cout << "Reading file input..." << endl << endl
	<< "The alphabetical list:" << endl << endl;

	arraySort(); //Using the sorting algorithm

	for (int i = 0; i < 20; i++)
	{
		cout << names[i] << endl;
	}
}

int main()
{
	using std::cout;
	using std::endl;
	
	Student order; //Instatiating an object

	//Order of execution
	order.maintenance();
	order.display();

	cout << endl << endl;
	system("pause");
	return 0;
}