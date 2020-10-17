#include <iostream>
#include <locale>
using namespace std;

void Bubble(int *a, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int k;
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
		}
		
	}
	
}
void task1()
{
	int a[1000] = { 0 };
	int n = 0;
	cout << "\nEnter the length of the array:";
	cin >> n;
	cout << "\nEnter numbers:";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Bubble(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\t';
	}
}

void Count(char *b, int m ) 
{
	int const len = 26;
	int l[len] = { 0 };
	int j = 0;
	for (int i = 0; i < m; i++) {
		j = int(b[i] - 'a');
		l[j]++;
	}
	int i = 0;
	j = 0;
	while (j <= len) {
		if (l[j] > 0) {
			b[i] = char(int('a')+j);
			i++;
			l[j]--;
		}
		else {
			j++;
		}
	}

}


void task2()
{
	char b[1000] = { 0 };
	int m = 0;
	cout<< "\nEnter the length of the array:";
	cin >> m;
	cout << "\nEnter letters:";
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	Count(b, m);
	for (int i = 0; i < m; i++) {
		cout << b[i];
	}


	
}

void S(int *arr, int begin, int end)
{
	int i = begin,
		mid = (begin + end) / 2,
		j = mid + 1,
		d[1000];
	for (int k = begin; k <= end; k++) {
		if ((i<=mid) && ((j>end) || (arr[i] < arr[j]))) {
			d[k] = arr[i];
			i++;
		}
		else {
			d[k] = arr[j];
			j++;
       	}
	}
	for (int k = begin; k <= end; k++)
		arr[k] = d[k]; 

	
	
}

void SO(int *arr, int left, int right)
{
	int t = 0;
	if (left < right)
		if (right - left == 1) {
			if (arr[left] > arr[right]) {
				t = arr[left];
				arr[left] = arr[right];
				arr[right] = t;

			}
		}
		else {
			SO(arr, left, ( left + right ) / 2);
			SO(arr, ( left + right ) / 2 + 1, right);
			S(arr, left, right);
		}
	
}
void task3() 
{
	int v, arr[1000];
	cout << "\nEnter the length of the array:";
	cin >> v;
	cout << "\nEnter numbers:";
	for (int i = 0; i < v; i++) {
		cin >> arr[i];
	}

	SO(arr, 0, v - 1);
	
	for (int i = 0; i < v; i++) {
		cout << arr[i] << '\t';
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int choice = 0;
	while (true)
	{
		cout << "\n Что вы хотите ввести?\n"
			<< "\n1.Задание 1"
			<< "\n2.Задание 2"
			<< "\n3.Задание 3"
			<< "\n4.Выход";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}