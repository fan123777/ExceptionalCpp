#include "Chapter2.h"

namespace nsExceptionSafety
{
	void main()
	{
		// task1();
		// task2();
		// task3();
		// task4();
		// task5();
		// task6();
		// task7();
		// task8();
		// task9();
		// task10();
		// task11();
		// task12();
		// task13();
		// task14();
		// task15();
		// task16();
		// task17();
		// task18();
		task19();
	}


	// Задача 2.1. Разработка безопасного кода. Часть 1(7)
	void task1()
	{

	}


	// Задача 2.2.Разработка безопасного кода.Часть 2(8)
	void task2()
	{

	}


	// Задача 2.3. Разработка безопасного кода. Часть 3(9.5)
	void task3()
	{

	}


	// Задача 2.4. Разработка безопасного кода. Часть 4(8)
	void task4()
	{

	}


	// Задача 2.5. Разработка безопасного кода. Часть 5(7)
	void task5()
	{

	}


	// Задача 2.6.Разработка безопасного кода.Часть 6(9)
	void task6()
	{

	}


	// Задача 2.7.Разработка безопасного кода.Часть 7(5)
	void task7()
	{

	}


	// Задача 2.8. Разработка безопасного кода. Часть 8(9)
	void task8()
	{

	}


	// Разработка безопасного кода. Часть 9(8)
	void task9()
	{

	}


	// Задача 2.10. Разработка безопасного кода. Часть 10(9.5)
	void task10()
	{

	}


	// Задача 2.11.Сложность кода.Часть 1(9)
	void task11()
	{

	}

	string EvaluateSalaryAndReturnName(Employee e)
	{
		if (e.Title() == "CEO" || e.Salary() > 100000)
			cout << e.First() << " " << e.Last() << " is overpaid" << endl;
		return e.First() + " " + e.Last();
	}


	// Задача 2.12. Сложность кода. Часть 2(7)
	void task12()
	{
		Employee bob;
		string theName;
		theName = SafeEvaluateSalaryAndReturnName(bob);

	}

	string SafeEvaluateSalaryAndReturnName(Employee e)
	{
		/*if (e.Title() == "CEO" || e.Salary() > 100000)
			cout << e.First() << " " << e.Last() << " is overpaid" << endl;
		return e.First() + " " + e.Last();*/

		// Попытка #1. Улучшение.
		string result = e.First() + " " + e.Last();
		if (e.Title() == "CEO" || e.Salary() > 100000)
		{
			string message = result + " is overpaid\n";
			cout << message;
		}
		return result;
	}


	// Задача 2.13. Исключения в конструкторах. Часть 1(4)
	void task13()
	{

	}

	C::C()
		try
		:A() // необязательный список инициализации 
		,b_()
	{
	}
	catch (...)
	{
		/* Здесь мы перехватываем исключения, сгенерированные
		А::A() или B::B().
		Если A::A() успешно завершается, после чего B:B()
		генерирует исключение, язык гарантирует, что для
		уничтожения уже созданного базового объекта типа А
		до входа в блок catch будет вызван деструктор А::~А()*/
	}


	// Задача 2.14. Исключения в конструкторах. Часть 2(7)
	void task14()
	{

	}


	// Задача 2.15.Неперехваченные исключения(6)
	void task15()
	{

	}


	// Задача 2.16. Проблема неуправляемых указателей. Часть 1(6)
	void task16()
	{

	}


	// Задача 2.17. Проблема неуправляемых указателей. Часть 2(8)
	void task17()
	{
		// auto_ptr<T1> t1(new T1);
		// auto_ptr<T2> t2(new T2);
		// f(t1, t2);
	}


	// Задача 2.18. Разработка безопасных классов. Часть 1(7)
	void task18()
	{

	}


	// Задача 2.19. Разработка безопасных классов. Часть 2(6)
	void task19()
	{

	}
}
