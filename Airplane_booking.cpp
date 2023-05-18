#include<iostream>
#include<fstream>
using namespace std;
int** read(ifstream& fin, int**, int& field, int& column);
int** insert_value(int**, int& field, int& column);
int** count_filled(int**, int& field, int& column);
int** delete_filled(int**, int& field, int& column);
int** average(int**, int& field, int& column);
int** max_value_in_field(int**, int& field, int& column);
int** maximum_occurrences(int**, int& field, int& column);


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	int field = 4;
	int column = 6;
	int** ptr = new int* [field];
	for (int i = 0; i < field; i++)
	{
		ptr[i] = new int[column];
	}
	
	ptr = read(fin, ptr, field, column);
	int user_choice;
	for (int i = 0; i <10; i++)
	{
		
		cout << "------------------------MENU-----------------" << endl;
		cout << " Press 1  Insert a new value in any field of table" << endl;
		cout << " Press 2  Count the number of filled locations (values other than -1)" << endl;
		cout << " Press 3  Delete any filled value from any field. (Deletion means replace with -1)" << endl;
		cout << " Press 4  Display the maximum occurance of 2 values" << endl;
		cout << " Press 5  Calculate Average (excluding empty locations)" << endl;
		cout << " Press 6  Tell the field/s no having maximum success scores value" << endl;
		cout << " Press 7 to Exit" << endl;
		cin >> user_choice;
		if (user_choice == 1)
		{
			ptr = insert_value(ptr, field, column);
		}
		else if (user_choice == 2)
		{
			ptr = count_filled(ptr, field, column);
		}
		else if (user_choice == 3)
		{
			ptr = delete_filled(ptr, field, column);
		}
		else if (user_choice == 4)
		{
			ptr = maximum_occurrences(ptr, field, column);
		}
		else if (user_choice == 5)
		{
			ptr = average(ptr, field, column);
		}
		else if (user_choice == 6)
		{
			 ptr = max_value_in_field(ptr, field, column);
		}
		else if (user_choice == 7)
		{
			cout << endl;
			cout << " Your Program is Exit " << endl << endl;
			break;
		}
	}
}


int** read(ifstream& fin, int** ptr, int& field, int& column)
{
	for (int x = 0; x < field; x++)
	{
		for (int i = 0; i < column; i++)
		{
			fin >> ptr[x][i];
		}
	}
	cout << "  Initially your Table is Displayed " << endl;
	for (int x = 0; x < field; x++)
	{
		for (int i = 0; i < column; i++)
		{
			cout <<  ptr[x][i]<<" ";
		}
		cout << endl;
	}
	return ptr;

}


int** insert_value(int** ptr, int& field, int& column)
{
	system("cls");
	int value, row;
	bool flag = 0;
	cout << "Enter a field in you want to enter a value " << endl;
	cin >> row;
	row = row - 1;
	cout << "Enter a value that you want to enter " << endl;
	cin >> value;
	for (int i = 0; i < field; i++)
	{
		for (int x = 0; x < column; x++)
		{
			if (i == row && ptr[i][x] == -1)
			{
				ptr[i][x] = value;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	for (int x = 0; x < field; x++)
	{
		for (int i = 0; i < column; i++)
		{
			cout << ptr[x][i] << " ";
		}
		cout << endl;
	}
	return ptr;
}


int** count_filled(int** ptr, int& field, int& column)
{
	
	int counter = 0;
	for (int i = 0; i < field; i++)
	{
		for (int x = 0; x < column; x++)
		{
			if (ptr[i][x] != -1)
			{
				counter++;

			}
		}
	}
	cout << "The total values of all fields (excluding -1 are)  " << counter<<endl;
	return ptr;
}


int** delete_filled(int** ptr, int& field, int& column)
{
	system("cls");
	int position, row;
	bool flag = 0;
	cout << endl;
	cout << "Enter a field in you want to delete a value " << endl;
	cin >> row;
	row = row - 1;
	cout << "Enter a column position of which you want to delete value " << endl;
	cin >> position;
	position = position - 1;
	for (int i = 0; i < field; i++)
	{
		for (int x = 0; x < column; x++)
		{
			if (i == row && x == position)
			{
				ptr[i][x] = -1;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	for (int x = 0; x < field; x++)
	{
		for (int i = 0; i < column; i++)
		{
			cout << ptr[x][i] << " ";
		}
		cout << endl;
	}
	return ptr;
}


int** maximum_occurrences(int** ptr, int& field, int& column)
{

	int max = 0;
	int counter = 0;
	for (int c = 0; c < field; c++)
	{

		for (int a = 0; a < column; a++)
		{
			int count = 0, temp = 0;
			for (int i = c; i < field; i++)
			{
				for (int x = 0; x < column; x++)
				{
					if (ptr[i][x] != -1)
					{
						if (ptr[c][a] == ptr[i][x])
						{
							count++;
							temp = ptr[c][a];
						}
					}
				}
			}
			if (count != 0)
			{
				if (count > max)
				{
					counter = count;
					max = temp;
				}

			}
		}

	}
	cout << endl;
	cout << max << " has maximum occurrence of  " << counter << " Times";
	for (int i = 0; i < field; i++)
	{
		for (int x = 0; x < column; x++)
		{
			if (ptr[i][x] == max)
			{
				ptr[i][x] = -1;
			}
		}
	}
	int max1 = 0;
	int counter1 = 0;
	for (int c = 0; c < field; c++)
	{

		for (int a = 0; a < column; a++)
		{
			int count2 = 0, temp2 = 0;
			for (int i = c; i < field; i++)
			{
				for (int x = 0; x < column; x++)
				{
					if (ptr[i][x] != -1)
					{
						if (ptr[c][a] == ptr[i][x])
						{
							count2++;
							temp2 = ptr[c][a];
						}
					}
				}
			}
			if (count2 != 0)
			{
				if (count2 > max1)
				{
					counter1 = count2;
					max1 = temp2;
				}

			}
		}

	}
	cout << endl;
	cout << max1 << " has 2nd maximum occurrence of " << counter1 << " Times";
	cout << endl;
	for (int i = 0; i < field; i++)
	{
		for (int x = 0; x < column; x++)
		{
			if (i == 0 && x == 0 || i == 2 && x == 1 || i == 2 && x == 3 || i == 3 && x == 2)
			{
				ptr[i][x] = max;
			}
		}
	}
	cout << endl;
	return ptr;

}


int** average(int** ptr, int& field, int& column)
{
	system("cls");
	float sum = 0, counter = 0.0;
	for (int i = 0; i < field; i++)
	{
		for (int x = 0; x < column; x++)
		{
			if (ptr[i][x] != -1)
			{
				sum = sum + ptr[i][x];
				counter++;
			}
		}
	}
	cout << endl;
	cout << "The total Average of all field values (excluding -1) is = " << sum / counter;
	cout << endl<<endl<<endl;
	return ptr;
}


int** max_value_in_field(int** ptr, int& field, int& column)
{
	int temp[4] = {};
	int greater=0;
	for (int x = 0; x < field; x++)
	{
		for (int a = 0; a < column; a++)
		{
			if (ptr[x][a] < ptr[x][a + 1])
			{
				temp[x] = ptr[x][a + 1];
			}
		}
	}
	cout << endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (temp[i] < temp[i+1])
		{
			greater = i+1;
		}
	}
	greater = greater + 1;
	cout << "Field  "<<greater<<"  has the maximum success score"<<endl;
	cout << endl;
	return ptr;
	
}