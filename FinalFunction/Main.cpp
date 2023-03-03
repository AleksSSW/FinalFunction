#include <iostream>
#include <cstdlib>
#include<ctime>
#include<algorithm>
template <typename T>
void print_arr(T arr[], const int length) {//функция массива
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std:: cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template<typename T>
void fill_arr(T arr[], const int length, int left, int right) {//функция именно для массива, чтобы вывести случайный массив. нужно исп 2 фу-ции(для вывода массива и заполнение массива случ числами)
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
//Перегруженная ф-ция для задачи № 1;
void type_of(int num)   { std::cout << "INT\n"; }
void type_of(char num)  { std::cout << "CHAR\n"; }
void type_of(float num) { std::cout << "float\n"; }
void type_of(double num){ std::cout << "DOUBLE\n"; }
//Ф-ция для задачи 2:
int sum_AB(int A, int B) {
	if (A > B) {
		std::swap(A, B);
		std::cout << "Ты дурачок";
	}
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;
}
//Ф-ция для задачи 3 (для массивов нписано выше 2 ф-ции)
template <typename T>
void middle_sort(T arr[], const int length) {
	int first_index=0, last_index=0;
	for (int i = 0; i < length; i++)//нашли первую позицию
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for (int i = length-1; i>=0; i--)//нашли вторую позицию
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	//быстрая сортировка для чисел между 1 и2 позицией:
	/*if (first_index != last_index)
	std::sort(arr+first_index+1, arr+last_index);*/
	//Пузырьковая сортировка
	for (int i = last_index-1; i > first_index+1; i--)
		for (int j = first_index+1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

template<typename T>
void move_arr(T arr[], const int length) {
	for (int i = 0; i < length-1; i++)
		std::swap(arr[length], arr[length-1]);
		}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//Задача 1. Ф-ция принимает любое число т выводит его тип данных/ Для нее пишем перегруженную ф-цию с войд, т.к она ничего не возвращает
	/*std::cout << "задача 1.\n";
	std::cout << "105 - "; type_of(105);
	std::cout << "\'A\' - "; type_of('A');
	std::cout << "7.7F - "; type_of(7.7F);
	std::cout << "0.1 - "; type_of(0.1);
	std::cout << std::endl;*/
	//Задача 2. Рекурсивную ф-цию которая вычисляет сумму всех чисел в диапазоне от А до В включительно
	/*std::cout << "Задача 1.\nВведите первое число ->";
	std::cin >> n;
	std::cout<< "Задача 1.\nВведите второе число ->";
	std::cin >> m;
	std::cout << "Сумма чисел от " << n << " до " << m << ":" << sum_AB(n, m) << "\n\n";*/
	//Задача 3. Массив случ чисел от -20 до+20 необх найти позиции крайних отриц  и отсортировать их
	/*std::cout << "Изначальный массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);
	std::cout << std::endl;*/
	//задача 4. Ф принимает массив и его длину и после последнего числа идет сдвиг на 1шаг
	std::cout << "Задача 4.\nИзначальный массив:\n";
	const int size4 = 5;
	int arr4[size4]{ 1,2,3,4,5 };
	print_arr(arr4, size4);
	std::cout << "Введите кол-во сдвигов - ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);
	std::cout << std::endl;



	return 0;
}