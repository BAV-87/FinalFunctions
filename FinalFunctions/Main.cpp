#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//����������� ������� ����������� �������
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
		}
//  ����� ������� � �������
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
void type_of(int num)    { std::cout << "INT\n"; } // ��������� ������ � ������� ��� ��� ������
void type_of(double num) { std::cout << "DOUBLE\n"; } // ��� ������� ������
void type_of(char sym) { std::cout << "CHAR\n"; } //������� ������������� �������


int sum_AB(int A, int B); // �������� ������� sum_AB

template <typename T>
void middle_sort(T arr[], const int length);

template <typename T>
void move_arr(T arr[], const int length, int steps);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//������ 1. ��� ������, �������� ���� ������
	/*std::cout << "\n������ 1.\n";
	std::cout << "77- "; type_of(77); // ��������� ����� � ������� ��� �������� ���� ������
	std::cout << "5.1 -"; type_of(5.1); // ��������� ����� � ������� ��� �������� ���� ������
	std::cout << "A - "; type_of('A'); // ��������� ����� � ������� ��� �������� ���� ������
	std::cout << std::endl;*/

	//������ 2. ����������� �����
	/*std::cout << "\n������ 2.\n������� ��� ����� -> ";
	std::cin >> n >> m;
	std::cout << "����� ����� �� " << n << " �� " << m << " = " << sum_AB(n, m) << "\n";*/

	//������ 3.
	/*std::cout << "������ 3.\n����������� ������:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -10, 11);
	print_arr(arr3, size3);

	middle_sort(arr3, size3);

	std::cout << "�������� ������:\n";
	print_arr(arr3, size3);*/

	//������ 4.
	std::cout << "������ 4.\n����������� ������:\n";
	const int size4 = 10;
	int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_arr(arr4, size4);
	std::cout << "������� ����� -> ";
	std::cin >> n;
	move_arr(arr4, size4, n);

	std::cout << "�������� ������:\n";
	print_arr(arr4, size4);

 	return 0;
}

template <typename T>
void move_arr(T arr[], const int length, int steps) {
	for (int i = 1; i <= steps; i++) {
		T tmp = arr[length - 1];
		for (int i = length - 1; i >= 1; i--)
			arr[i] = arr[i - 1];
		arr[0] = tmp;
	}
	if (steps >= 0)
		for (int i = 0; i < steps; i++) {
			T tmp = arr[length - 1];
			for (int j = length - 1; j >= 1; j--)
				arr[j] = arr[j - 1];
			arr[0] = tmp;
		}
	else
		for (int i = 0; i > -steps; i++)
			for (int j = 0; j < length - 1; j++)
				std::swap(arr[j], arr[j + 1]);

}



template <typename T>
void middle_sort(T arr[], const int length) {
	int first_index = 0, last_index = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	// ������ ���������� �������������� ��������
	for (int i = length - 1; i >= first_index; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	// ����������� ����������
	/*for (int i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);*/

	// ������� ����������
	std::sort(arr + first_index + 1, arr + last_index);


}


//���������� ������� sum_AB
int sum_AB(int A, int B) { 
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;
}
