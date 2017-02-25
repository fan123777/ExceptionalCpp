#include "Chapter3.h"

using namespace std;

namespace nsClassDevelopmentInheritancePolymorphism
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
		task11();
	}


	// Задача 3.1. Механика классов(7)
	void task1()
	{

	}


	// Задача З.2.Замещение виртуальных функций(6)
	void task2()
	{
		Base b;
		Derived d;
		Base* pb = new Derived;
		b.f(1.0);
		d.f(1.0);
		pb->f(1.0);
		b.g();
		d.g();
		pb->g();
		delete pb;
	}

	void Base::f(int)
	{
		cout << "Base::f(int)" << endl;
	}

	void Base::f(double)
	{
		cout << "Base::f(double)" << endl;
	}

	void Base::g(int i)
	{
		cout << i << endl;
	}

	void Derived::f(complex<double>)
	{
		cout << "Derived::f(complex)" << endl;
	}

	void Derived::g(int i)
	{
		cout << "Derived::g() " << i << endl;
	}


	// Задача 3.3.Взаимоотношения классов.Часть 1(5)
	void task3()
	{

	}


	// Задача 3.4. Взаимоотношения классов. Часть 2(6)
	void task4()
	{

	}


	// Задача 3.5.Наследование: потребление и злоупотребление (6)
	void task5()
	{

	}


	// Задача 3.6. Объектно-ориентированное программирование(4)
	void task6()
	{

	}


	// Задача 3.7.Множественное наследование(6)
	void task7()
	{

	}


	// Задача 3.8. Эмуляция множественного наследования(5)
	void task8()
	{

	}


	// Задача 3.9.Множественное наследование и проблема сиамских близнецов(4)
	void task9()
	{

	}


	// Задача 3.10. (Не)чисто виртуальные функции(7)
	void task10()
	{

	}


	// Задача 3.11. Управляемый полиморфизм(3)
	void task11()
	{

	}
}
