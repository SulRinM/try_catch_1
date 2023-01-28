/*
В этом задании вы попробуете выбросить и обработать исключение.
Создайте функцию int function(std::string str, int forbidden_length).
Эта функция должна возвращать длину переданной строки, если эта длина не равна
значению переданного параметра forbidden_length.В противном случае она должна
выбрасывать исключение bad_length.
Для проверки функции организуйте работу с пользователем.В начале задайте запретную длину,
а затем считывайте пользовательские строки и выводите их длину до тех пор, пока пользователь
не введёт строку запретной длины.После этого сообщите ему, что он ввёл строку запретной длины,
и завершите программу.
*/

#include <iostream>
#include <string>

class bab_length : public std::exception
{
public:
	const char* what() const override
	{
		return "You have entered a word of forbidden length! Goodbye";
	}
};

int function(std::string str, int forbidden_length)
{
	int l = str.length();
	if (l != forbidden_length)
		return l;
	throw bab_length();
}

int main()
{
	std::string Str;
	int length;
	while (true)
	{
		try
		{
			std::cout << "Enter the forbidden length: ";
			std::cin >> length;
			std::cout << "Enter the word: ";
			std::cin >> Str;
			std::cout << "Word length " << Str << "equal to: " << function(Str, length) << "\n";
		}
		catch (const bab_length& ex)
		{
			std::cout << ex.what() << std::endl;
			break;
		}
	}
	return 0;
}