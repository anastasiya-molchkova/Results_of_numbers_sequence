/* Написать программу, которая вычисляет среднее арифметическое последовательности дробных чисел, вводимых с клавиатуры. 
После ввода последнего числа программа должна вывести минимальное и максимальное числа из последовательности. 
Количество чисел последовательности вводит пользователь.*/

#include <iostream>
#include <clocale>  // для вывода на кириллице

using std::cout; using std::cin; using std::endl;

// получаем от пользователя количество чисел в последовательности
unsigned get_length()
{
	cout << "Введите количество чисел последовательности: ";
	int answer;
	cin >> answer;
	while (cin.fail() || (answer <= 0))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели нечто некорректное, введите положительное число: ";
		cin >> answer;
	}
	return static_cast<unsigned>(answer);
}

// получаем от пользователя последовательность чисел, вычисляем минимум, максимум и среднее арифметическое
void get_and_calculate_sequence_cycle()
{
	unsigned n_number = get_length();
	double min_number, 
		   max_number, 
		   summ{ 0 };

	cout << "Для рассчёта необходимо ввести последовательность из заданного количества чисел." << endl;

	for (unsigned short i = 0; i < n_number; i++)
	{
		double next_number{ 0 };
		cout << "Введите число №" << i + 1 << ": ";
		cin >> next_number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Вы ввели нечто некорректное, введите число: ";
			cin >> next_number;
		}

		summ += next_number;
		if (i == 0)
		{
			min_number = next_number;
			max_number = next_number;
		}
		else
		{ 
			if (next_number < min_number) min_number = next_number;
			else if (next_number > max_number) max_number = next_number;
		}
 	}

	cout << endl;
	cout << "Количество чисел: " << n_number << endl;
	cout << "Среднее арифметическое: " << (summ/n_number) << endl;
	cout << "Минимальное число: " << min_number << endl;
	cout << "Максимальное число: " << max_number << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // для вывода на кириллице
	cout << "Программа вычисляет минимальное, максимальное и среднее арифметическое число для введённой последовательности чисел." << endl << endl;

	while (true)
		get_and_calculate_sequence_cycle();
	 
	return 0;
}