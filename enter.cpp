#include <iostream>
#include <conio.h>

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	int N = 10;
	
	int arr[N];
	
	for(int i = 0; i<N; i++)
	{
		cout << "Введите значение для " << i+1 << " элемента массива:";
		while(!(cin >> arr[i]))
		{
			cin.clear();
			while(cin.get() != '\n');
			
			cout << "Введите значение для " << i+1 << " элемента массива:";
		}
	}
	
	for(int i=0; i<N; i++)
	cout << arr[i] << endl;
	
	
	_getch();
	return 0;
}
