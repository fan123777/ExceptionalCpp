#include "Chapter8.h"
#include <string>

using namespace std;

namespace nsFreeFunctionAndMacros
{
	void main()
	{
		// task1();
		// task2();
		// task3();
		task4();
	}


	// Задача 8.1.Рекурсивные объявления(6)
	// Пример 1 
	// Создаем typedef с именем FPDoublelnt для 
	// функции с параметром double, возвращающим int 
	typedef void(*FPDoub1eInt)(double);

	void f(double) {/*...*/ }
	void g(double) {/*...*/ }
	void h(double) {/*...*/ }

	void task1()
	{
		FPDoub1eInt fp;
		fp = f;
		fp(1.1); // вызов f()
		fp = g;
		fp(2.2); // вызов g()
		fp = h;
		fp(3.14); // вызов h()
	}


	// Задача 8.2.Имитация вложенных функций

	void f()
	{
		class LocalClass
		{
			// ... 
		};
		// ... 
	}

	void task2()
	{
		
	}


	// Задача 8.3.Макросы препроцессора(4)
	void task3()
	{

	}


	// Задача 8.4. #Definition(4)
	void task4()
	{

	}
}
