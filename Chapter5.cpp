#include "Chapter5.h"

namespace nsNamespaceAndNameSearch
{
	void main()
	{
		// task1();
		// task2();
		// task3();
		task4();
	}


	// Задача 5.1.Поиск имен и принцип интерфейса.Часть 1(9.5)
	void task1()
	{

	}

	namespace B
	{
		void g(A::X x)
		{
			// ambiguous
			// g(x); // какая g()? 
		}

		void h(A::Y у)
		{
			h(у); // какая h()? 
		}

		void f(int i)
		{
			f(i); // какая f()? 
		}
	}


	// Задача 5.2.Поиск имен и принцип интерфейса.Часть 2(9)
	void task2()
	{

	}


	// Задача 5.3.Поиск имен и принцип интерфейса.Часть 3(5)
	void task3()
	{

	}


	// Задача 5.4. Поиск имен и принцип интерфейса. Часть 4(9)
	void task4()
	{

	}
}
