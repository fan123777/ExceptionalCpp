#include "Chapter1.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream> 
#include <iterator>
#include <sstream>
#include <cassert>

using namespace std;

namespace nsGenericProgrammingAndTheStandardLibrary
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
		task18();
	}


	// Задача 1.1. Итераторы(7)
	void task1()
	{
		if (false)
		{
			std::stringstream ss("The quick brown fox jumped over the lazy dogs");
			vector<string> e;
			copy(istream_iterator<string>(ss), istream_iterator<string>(), back_inserter(e));
			vector<string>::iterator first = find(e.begin(), e.end(), "01/01/95");
			vector<string>::iterator last = find(e.begin(), e.end(), "12/31/95");
			// !!!
			*last = string("12/30/95"); // last can be == end
			// !!!
			copy(first, last, ostream_iterator<string>(cout, "\n")); // [first;last) can be wrong range
			// !!! --e.end can be wrong, c++ doesn't allow to change temporary objects
			// e.end() - 1
			// e should be not empty
			e.insert(--e.end(), TodayDate());
			e.insert(e.end() - 1, TodayDate());
			// !!!
			copy(first, last, ostream_iterator<string>(cout, "\n"));
			// first, last can be wrong iterators!
			// !!! never use invalid iterators
			// - *e.end() - always error
			// - is iterator left valid after your changes?
			// - is [first;last) correct range?
			// - is code mofifying temporary object of built-in data type(--e.end())?
		}
		std::stringstream ss("01/01/95 10/10/10 12/31/95");
		vector<Date> e;
		copy(istream_iterator<Date>(ss), istream_iterator<Date>(), back_inserter(e));
		vector<Date>::iterator first = find(e.begin(), e.end(), Date("01/01/95"));
		vector<Date>::iterator last = find(e.begin(), e.end(), Date("12/31/95"));
		*last = Date("12/30/95");
		copy(first, last, ostream_iterator<Date>(cout, "\n"));
	}

	Date TodaysDate()
	{
		return Date("qwerty");
	}

	std::string TodayDate()
	{
		return string("qwerty");
	}

	std::ostream& operator<<(std::ostream& s, const Date& date)
	{
		s << "(" << date.getDate() << ")";
		return s;
	}

	std::istream& operator>>(std::istream& s, Date& date)
	{
		std::string data;
		s >> data;
		date.setDate(data);
		return s;
	}


	// Задача 1.2. Строки, нечувствительные к регистру. Часть 1(7)
	void task2()
	{
		ci_string s("AbCdE"); 
		// Нечувствительно к регистру 
		assert(s == "abcde");
		assert(s == "ABCDE");
		// Остается чувствительно к регистру 
		assert(strcmp(s.c_str(), "AbCdE") == 0);
		assert(strcmp(s.c_str(), "abcde") != 0);
	}


	// Задача 1.3. Строки, нечувствительные к регистру. Часть 2(5)
	void task3()
	{
		ci_string s = "abc";
		// cout << s << endl;
		cout << s.c_str() << endl;

		string a = "ааа";
		ci_string b = "bbb";
		// string с = a + b;
		string с = a + b.c_str();
	}


	// Задача 1.4.Обобщенные контейнеры с максимальным повторным использованием.Часть 1(8)
	void task4()
	{

	}


	// Задача 1.5.Обобщенные контейнеры с максимальным повторным использованием.Часть 2(6)
	void task5()
	{
		//fixed_vector<char, 4> v;
		//fixed_vector<int, 4> w;
		//fixed_vector<int, 4> w2(w); // вызов неявного конструктора копирования
		//fixed_vector<int, 4> w3(v); // вызов шаблона конструктора с преобразованием
		//w = w2; // вызов неявного оператора присваивания копированием 
		//w = w2; // вызов шаблона оператора присваивания
	}

	// Задача 1.6.Временные объекты(5)
	void task6()
	{

	}

	string FindAddr(list<Employee> emps, string name)
	// Предпочтительно передавать объекты по ссылке, как const&, вместо передачи их по значению.
	{
		for (list<Employee>::iterator i = emps.begin(); i != emps.end(); i++)
		// Если некоторое значение остается неизменным, лучше вычислить его заранее и сохранить, чем постоянно вычислять его, создавая при этом излишние объекты.
		// Для согласованности всегда реализуйте постфиксный инкремент посредством префиксного; в противном случае ваши пользователи получат неожиданные(и, скорее всего, неприятные) результаты.
		// Предпочтительно использовать префиксный инкремент вместо постфиксного. Используйте постфиксный инкремент только в том случае, если вам требуется начальное значение объекта.
		{
			if (*i == name)
			// Следите за скрытыми временными объектами, создаваемыми при неявных преобразованиях. Один из неплохих способов избежать такого создания - по возможности использовать объявление конструкторов как explicit и избегать написания операторов преобразования типов.
			{
				return i->addr();
				// Обе эти инструкции создают временные объекты типа string, но избежать этого невозможно.
			}
		}

		return "";
		// Обе эти инструкции создают временные объекты типа string, но избежать этого невозможно.
	}
	// Следите за временем жизни объектов. Никогда, никогда, никогда не возвращайте указатель или ссылку на локальный автоматический объект; это совершенно бесполезно, поскольку вызывающий код не может их использовать, но(что еще хуже) может попытаться это сделать.

	string EffectiveFindAddr(const list<Employee>& emps, const string& name)
	{
		list<Employee>::const_iterator end(emps.end());
		for (list<Employee>::const_iterator i = emps.begin(); i != end; ++i)
		{
			if (i->getName() == name)
			{
				return i->addr();
			}
		}

		return "";
	}


	// Задача 1.7.Использование стандартной библиотеки(или еще раз о временных объектах)(5)
	void task7()
	{

	}

	string stdFindAddr(const list<Employee>& emps, const string& name)
	{
		list<Employee>::const_iterator i(find(emps.begin(), emps.end(), name));
		if (i != emps.end())
			return i->addr();
		return "";
	}
	// Вместо написания собственного кода повторно используйте имеющийся, в особенности код стандартной библиотеки.Это быстрее, проще и безопаснее.


	// Задача 1.8.Переключение потоков(2)
	void task8()
	{

	}

	int main(int argc, char* argv[])
	{
		fstream in, out;
		if (argc > 1) in.open(argv[1], ios::in | ios::binary);
		if (argc > 2) out.open(argv[2], ios::out | ios::binary);

		Process( in.is_open() ? in : cin, out.is_open() ? out : cout );
		
		return 0;
	}


	// Задача 1.9. Предикаты. Часть 1(4)
	void task9()
	{
		vector<int> v{ 1, 2, 3, 1, 2, 3, 1, 2, 3 };
		// auto iter = remove(v.begin(), v.end(), 3);
		// v.erase(iter, v.end());
		remove_nth(v.begin(), v.end(), 3);
		// remove_if(v.begin(), v.end(), FlagNth(3));
	}


	// Задача 1.10.Предикаты.Часть 2(7)
	void task10()
	{

	}


	// Задача 1.11.Расширяемые шаблоны : путем наследования или свойств?
	void task11()
	{

	}


	class Rose {};
	class A { public: typedef Rose rose; };
	template<typename T>
	class B : public T { public: typedef typename T::rose foo; };
	template<typename T>
	void smell(T) { std::cout << "bad"; }
	void smell(Rose) { std::cout << "good"; }

	// Задача 1.12.Typename(7)
	void task12()
	{
		smell(A::rose());
		smell(B<A>::foo()); // :-)
	}


	// Задача 1.13. Контейнеры, указатели и неконтейнеры(5)
	void task13()
	{
		vector<char> v;
		// ... Заполняем v ... 
		char* p = &v[0];
		// ... Работаем с *р ... 

		// как улучшить?
		vector<char>::iterator i = v.begin();
	}


	// Задача 1.14. Использование vector и deque(3)
	void task14()
	{
		vector<int> с(1000);
		с.erase(с.begin() + 10, с.end());
		с.reserve(10);
	}


	// Задача 1.15.Использование set и тар
	void task15()
	{

	}


	// Задача 1.16.Эквивалентный код?(5)
	void task16()
	{

	}


	// Задача 1.17. Специализация и перегрузка шаблонов(6)
	template<>
	void g<int>(int)
	{
		cout << "8" << endl;
	}

	void g(int, double)
	{
		cout << "9" << endl;
	}

	void g(int)
	{
		cout << "10" << endl;
	}

	void task17()
	{
		int i = 0;
		double d = 0;
		float f = 0;
		string s;

		g(i); //a 10
		g<int>(i); //b 8
		g(i, i); //c 3
		g(s); //d 2
		g(i, f); //e 1
		g(i, d); //f 9
		g(s, &s); //g 6
		g(i, &d); //h 7
		g(&d, d); //i 5
		g(&d); //j 4
		g(d, &i); //k 1
		g(&i, &i); //l 3
	}

	// Задача 1.18. Mastermind(8)
	void task18()
	{

	}
}
