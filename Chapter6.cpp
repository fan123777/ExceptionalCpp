#include "Chapter6.h"

// Управление памятью и ресурсами 
namespace nsMemoryAndResourceManagement
{
	void main()
	{
		// task1();
		// task2();
		// task3();
		// task4();
		// task5();
		task6();
	}


	// Задача 6.1.Управление памятью.Часть 1(3)
	void task1()
	{

	}


	// Задача 6.2. Управление памятью. Часть 2(6)
	void task2()
	{
		// D* pdl = new D;
		// delete pdl; // D::operator delete(void*).

		// B* pb2 = new D;
		// delete pb2; // D::operator delete(void*). 

		// D* pd3 = new D[10];
		// delete[] pd3; // D::operator delete[] (void*).
		
		// B* pb4 = new D[10];
		// delete[] pb4; // не определено
		// Язык требует, чтобы статический тип указателя, передаваемого operator deleted(), соответствовал его динамическому типу.

		// B Ь;
		// typedef void (B::*pmf)(void*, size_t);
		// pmf pi = &B::f;
		// pmf p2 = &B::operator delete; // статическая функция - член
	}


	// Задача 6.3. Применение auto_ptr. Часть 1 
	void task3()
	{

	}

	// Задача 6.4.Применение auto_ptr.Часть 2(5)
	void task4()
	{

	}


	// Задача 6.5. Интеллектуальные указатели-члены. Часть 1(5)
	void task5()
	{

	}


	// Задача 6.6. Интеллектуальные указатели-члены Часть 2(6)
	void task6()
	{

	}
}
