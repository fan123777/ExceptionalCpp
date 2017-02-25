#pragma once

#include <string>
#include <algorithm>
#include <list>
#include <cassert>
#include <iostream>

using namespace std;

// Обобщенное программирование и стандартная библиотека c++
namespace nsGenericProgrammingAndTheStandardLibrary
{
	void main();


	// Задача 1.1. Итераторы(7)
	void task1();

	class Date
	{
	public:
		Date() = default;

		Date(const std::string& date_)
			:date(date_)
		{
		}

		const std::string getDate() const
		{
			return date;
		}

		void setDate(const std::string& date_)
		{
			date = date_;
		}

		bool operator ==(const Date& other)
		{
			return date == other.date;
		}

	private:
		std::string date;
	};

	Date TodaysDate();
	std::string TodayDate();

	std::ostream& operator<<(std::ostream& s, const Date& date);
	std::istream& operator>>(std::istream& s, Date& date);


	// Задача 1.2. Строки, нечувствительные к регистру. Часть 1(7)
	void task2();
	// 1. Что означает "нечувствительный к регистру"?
	// 2. Напишите класс ci_string
	// 3. Разумно ли делать нечувствительность к регистру свойством объекта?

	struct ci_char_traits : public std::char_traits<char>
	{
		static bool eq(char c1, char c2)
		{
			return toupper(c1) == toupper(c2);
		}

		static bool lt(char c1, char c2)
		{
			return toupper(c1) < toupper(c2);
		}

		static int compare(const char * s1, const char * s2, size_t n)
		{
			return _memicmp(s1, s2, n );
		}

		static const char* find(const char* s, int n, char a)
		{
			while (n-- > 0 && toupper(*s) != toupper(a))
			{
				++s;
			}
			return n >= 0 ? s : 0;
		}
	};

	typedef std::basic_string<char, ci_char_traits> ci_string;


	// Задача 1.3. Строки, нечувствительные к регистру. Часть 2(5)
	void task3();
	// 1. Безопасно ли наследовать ci_char_traits от char_traits<char> таким образом?
	// 2. Почему следующий код вызывает ошибку компиляции?
	// 3. Что можно сказать об использовании других операторов (например, +, +=, =) и о сочетании string и ci_string в качестве их аргументов?


	// Задача 1.4.Обобщенные контейнеры с максимальным повторным использованием.Часть 1(8)
	void task4();

	template<typename T, size_t size>
	class fixed_vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		fixed_vector()
		{

		}

		template<typename O, size_t osize>
		fixed_vector(const fixed_vector<O, osize>& other)
		{
			copy(other.begin(), other.begin() + min(size, osize), begin());
		}

		template<typename O, size_t osize>
		fixed_vector<T, size> operator=(const fixed_vector<O, osize>& other)
		{
			copy(other.begin(), other.begin() + min(size, osize), begin());
			return *this;
		}

		iterator begin()
		{
			return v_;
		}

		iterator end()
		{
			return v_ + size;
		}

		const_iterator begin() const
		{
			return v_;
		}

		const_iterator end() const
		{
			return v_ + size;
		}

	private:
		T v_[size];
	};


	// Задача 1.5.Обобщенные контейнеры с максимальным повторным использованием.Часть 2(6)
	void task5();

	template<typename T, size_t size>
	class safe_fixed_vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		safe_fixed_vector() :
			v_(new T[size])
		{
		}

		~safe_fixed_vector()
		{
			delete[] v_;
		}

		template<typename O, size_t osize>
		safe_fixed_vector(const safe_fixed_vector<O, osize>& other)
			: v_(new T[size])
		{
			try {
				copy(other.begin(), other.begin() + min(size, osize), begin());
			}
			catch (...)
			{
				delete[] v_;
				throw;
			}
		}

		safe_fixed_vector(const safe_fixed_vector<T, size>& other)
			: v_(new T[size])
		{
			try {
				copy(other.begin(), other.end(), begin());
			}
			catch (...)
			{
				delete[] v_;
				throw;
			}
		}

		void Swap(safe_fixed_vector<T, size>& other) throw()
		{
			swap(v_, other.v_);
		}

		template<typename O, size_t osize>
		safe_fixed_vector<T, size>& operator=(const safe_fixed_vector<O, osize>& other)
		{
			// вся работа делается здесь: 
			fixed_vector<T, size> temp(other);
			// Здесь исключения не генерируются: 
			Swap(temp);
			return *this;
		}

		safe_fixed_vector<T, size>& operator=(const safe_fixed_vector<T, size>& other)
		{
			// вся работа делается здесь: 
			fixed_vector<T, size> temp(other);
			// Здесь исключения не генерируются: 
			Swap(temp);
			return *this;
		}
		iterator begin()
		{
			return v_;
		}

		iterator end()
		{
			return v_ + size;
		}

		const_iterator begin() const
		{
			return v_;
		}

		const_iterator end() const
		{
			return v_ + size;
		}
	private:
		T* v_;
	};

	// Никогда не задумывайтесь о безопасности исключений после разработки класса.
	// Безопасность исключений влияет на устройство класса и никогда не оказывается "просто деталью  реализации".


	// Задача 1.6.Временные объекты(5)
	void task6();

	class Employee
	{
	public:
		Employee(const string& name)
			:name_(name)
		{

		}

		string addr() const
		{
			return "";
		}

		bool operator==(const Employee& other) const
		{
			return name_ == other.name_;
		}

		const string& getName() const
		{
			return name_;
		}

	private:
		string name_;

	};

	string FindAddr(list<Employee> emps, string name);
	string EffectiveFindAddr(const list<Employee>& emps, const string& name);


	// Задача 1.7.Использование стандартной библиотеки(или еще раз о временных объектах)(5)
	void task7();
	string stdFindAddr(const list<Employee>& emps, const string& name);


	// Задача 1.8.Переключение потоков(2)
	void task8();
	// 1. Какие типы имеют std::c n и std::cout?
	// 2. Напишите программу ECHO, которая просто повторяет вводимую информацию и  одинаково работает при двух следующих вариантах вызова.
	// Краткий ответ звучит так: тип cin - std::basic_istream<char, std::char_traint<char> >
	// a cout - std::basic_ostream<char, std::char_traint<char> >
	// Предпочитайте удобочитаемость. Избегайте чрезмерно краткого кода (краткого, но трудного для понимания и сопровождения).Избегайте крайностей!
	int main(int argc, char* argv[]);

	template<typename C = char, typename T = char_traits<C>>
	void Process(basic_istream<C, T>& in, basic_ostream<C, T>& out)
	{

	}
	// Предпочитайте расширяемость.
	// Каждая часть кода — каждый модуль, класс, функция - должны отвечать за выполнение единой, четко определенной задачи.
	
	
	// Задача 1.9. Предикаты. Часть 1(4)
	void task9();
	// 1. Как функционирует алгоритм std::remove()? Будьте максимально точны.
	// 2. Напишите код, удаляющий все значения, равные трем, из std::vector<int>.
	// 3. Программист, работающий в вашей команде, написал следующие варианты кода для удаления n - го элемента контейнера.
	// а) Реализуйте недостающую часть Метода 1. 
	// б) Какой метод лучше ? Почему ? Рассмотрите все возможные проблемы, которые могут возникнуть в том или ином решении.
	// Метод 1. Разработка специализированного алгоритма 
	template<typename FwdIter>
	FwdIter remove_nth(FwdIter first, FwdIter last, size_t n)
	{
		// Проверка выполнения предусловия 
		assert(distance(first, last) >= n);

		// выполнение задания 
		advance(first, n);
		if (first != last)
		{
			FwdIter dest = first;
			return copy(++first, last, dest);
		}
		return last;
	}

	// метод 2. Написание объекта-функции, 
	// возвращающего true при n-м применении, и 
	// использовании его как предиката для remove_if 
	class FlagNth
	{
	public:
		FlagNth(size_t n) : current_(0), n_(n) {}
		template<typename T>
		bool operator()(const T&) { return ++current_ == n_; }
	private:
		size_t current_;
		const size_t n_;
	};


	// Задача 1.10.Предикаты.Часть 2(7)
	void task10();
	// 1. Что такое предикаты и как они используются в STL? Приведите пример.
	// 2. Когда предикаты с состояниями могут оказаться полезными? Приведите примеры.
	// 3. Какие требования к алгоритмам следует предъявлять, чтобы обеспечить корректную работу предикатов?
	class GreaterThanFive :public std::unary_function<int, bool>
	{
	public:
		bool operator()(int i) const
		{
			return i > 5;
		}
	};
	// можем сделать int и 5 шаблоном и параметро GreaterThan
	// Чтобы предикаты с состояниями были действительно применимы в алгоритме, алгоритм в общем случае должен гарантировать выполнение определенных условий при работе с предикатами.
	// - Алгоритм не должен делать копий предиката
	// - Алгоритм должен применять предикат к элементам диапазона в некотором предопределенном порядке
	// Главное правило: если что-то стандартом не требуется, то рассчитывать на это "что-то" нельзя.
	

	// Задача 1.11.Расширяемые шаблоны : путем наследования или свойств?
	void task11();
	// 1. Что такое класс свойств?
	// 2. Покажите, как проверить наличие определенного члена в классе-параметре шаблона?
	// 3. a) требовалось, чтобы т был производным от Cloneable, а также
	// б) обеспечить реализацию, в которой выполняются одни действия, если т - производный от Cloneable класс, и некоторые другие действия, если это не так.
	// 4. Является ли подход, описанный в п. 3, наилучшим способом обеспечить требование(обнаружение) наличия Clone()? Приведите другие варианты решения.
	// 5. Насколько полезно знание шаблона о том, что его параметр типа т является производным от некоторого другого типа? Дает ли такое знание какие - либо преимущества, которые не могут быть достигнуты иначе, без отношений наследования?
	// 1. класс свойств — это класс, который инкапсулирует множество типов и функций, необходимых для шаблонных классов и функций для работы с объектами типов, для которых они инстанцируются.

	// 2. T должен иметь член T* T::Clone() const 
	// Задача состоит в том, чтобы гарантировать, что тип т имеет функцию, выглядящую в точности так: T* T::Clone() const.
	// деструктор — наиболее простое место для размещения кода, требующего наличия функции - члена.

	template<typename T>
	class C
	{
		bool vlaidate() const
		{
			T* (T::*test)() const = &T::Clone();
			test;
			return true;
		}

		~C()
		{
			assert(validate());
		}
	};

	// Классы ограничений
	template<typename т>
	class HasClone
	{
	public:
		static void Constraints()
		{
			т* (T::*test)() const = &T::Clone;
			test; // для подавления предупреждения о 
			// неиспользуемой переменной. 
		}

		HasClone()
		{
			void(*p)() = Constraints;
		}
	};

	template<typename T>
	class С1 : HasClone<T>
	{
		// ... 
	};

	// Требование наследования, вариант 1
	template<typename D, typename B>
	class IsDerivedFrom1
	{
		class No { };
		class Yes { No no[2]; };
		static Yes Test(B*); // Объявлена, но не определена 
		static No Test(...); // Объявлена, но не определена 
	public:
		enum
		{
			is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes)
		};
	};

	template<typename T>
	class X
	{
		bool validateRequirements() const
		{
			// typedef необходим, поскольку иначе запятая в 
			// описании типа будет воспринята как разделитель 
			// параметров макроса assert. 
			typedef IsDerivedFrom1<T, Cloneable> Y;
			// проверка времени выполнения, которая легко может 
			// быть преобразована в проверку времени компиляции 
			assert(Y::is);
			return true;
		}
	public:
		// используем деструктор, чтобы не вносить код 
		// в каждый из конструкторов 
		~X()
		{
			assert(ValidateRequirements());
			// ... 
		}
	};

	// Требование наследования, вариант 2
	template<typename D, typename B>
	class IsDerivedFrom2
	{
		static void Constraints(D* p)
		{
			в* pb = p;
			pb = p; // для подавления предупреждения о
			// неиспользуемой переменной.
		}

	protected:
		IsDerivedFrom2()
		{
			void(*p)(D*) = Constraints;
		}
	};

	template<typename D>
	class IsDerivedFrom2<D, void>
	{
		IsDerivedFrom2() { char * p = (int*)0; /* Ошибка */ }
	};

	class Cloneable
	{

	};

	template<typename T>
	class X1 : IsDerivedFrom2<T, Cloneable>
	{
		//...
	};

	// Требование наследования, вариант 3
	template<typename D, typename B>
	class IsDerivedFrom
	{
		class No{};

		class Yes { No no[2]; };

		static Yes Test(B*); // не определена
		static No Test(...); // не определена

		static void Constraints(D* p)
		{
			B* pb = p;
			pb = p;
		}

	public:
		enum {is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes)};

		IsDerivedFrom()
		{
			void(*p)(D*) = Constraints;
		}
	};

	// Выбор альтернативных реализаций
	// б) обеспечить реализацию, в которой выполняются одни действия, если T - производный от cloneable класс, и некоторые другие действия, если это не так.

	// пример Зг: использование IsDerivedFrom для 
	// использования наследования от doneable, если 
	// таковое имеет место, и выполнения некоторых 
	// других действий в противном случае. 
	template<typename T, int>
	class XImpl
	{
		// Общий случай: т не является наследником doneable 
	};

	template<typename T>
	class XImpl<T, 1>
	{
		// т - производный от doneable класс 
	};

	template<typename T>
	class X2
	{
		XImpl<T, IsDerivedFrom<T, Cloneable>::Is> impl_;
		// ... делегирование выполнения imp!. ... 
	};

	// Требования и свойства
	// пример 4. использование свойств вместо IsDerivedFrom 
	// для обеспечения возможности клонирования и выполнения 
	// иных действий, требует написания специализаций для 
	// каждого из используемых классов, 
	template<typename T>
	class XTraits
	{
	public:
		// Общий случай: использование конструктора копирования 
		static T* Clone(const T* p)
		{
			return new т(*р);
		}
	};

	class MyCloneable
	{
	public:
		MyCloneable* Clone() const;
	};

	template<>
	class XTraits<MyCloneable>
	{
	public:
		// MyCloneable производный от Cloneable, так что 
		// просто используем CloneO 
		static MyCloneable* Clone(const MyCloneable* p)
		{
			return p->Clone();
		}
	};

	// Наследование и свойства


	// Задача 1.12.Typename(7)
	void task12();
	// 1. Что такое typename и что делает это ключевое слово?
	// 2. Какие ошибки(если таковые есть) имеются в приведенном ниже коде?

	template<typename T>
	class x_base
	{
	public:
		typedef T instantiated_type;
	};

	template<typename A, typename B>
	class x : public x_base<B>
	{
	public:
		bool operator()(const typename instantiated_type& i) const
		{
			return i != typename instantiated_type();
		}
		// ... прочий код ... 
	};
	// Имя, используемое в объявлении или определении шаблона и зависимое от параметра шаблона, считается не являющимся именем типа, если только поиск имени не находит соответствующее имя типа или имя с квалификатором typename.
	

	// Задача 1.13. Контейнеры, указатели и неконтейнеры(5)
	void task13();
	// 1. Рассмотрим следующий код.
	// 2. Рассмотрим следующий код.
	template<typename T>
	void f(T& t)
	{
		typename T::value_type* pi = &t[0];
		typename T::value_type* p2 = &*t.begin();
	}
	// Стандарт гарантирует, что если соответствующая последовательность (такая, как vector<char>) предоставляет operator[] (), то этот оператор должен возвращать lvalue типа char, а это означает, что может быть получен его адрес.
	// vector<bool>
	// Прокси-контейнеры и предположения STL
	// 1. Не оптимизируйте преждевременно.
	// 2. Не оптимизируйте до тех пор, пока не убедитесь в том, что это необходимо.
	// 3. Даже в этом случае не оптимизируйте до тех пор, пока не будете точно знать, что и где надо оптимизировать.
	
	// Что делать
	// deque<bool>
	
	
	// Задача 1.14. Использование vector и deque(3)
	void task14();
	// 1. В стандартной библиотеке типы vector и deque предоставляют схожие сервисы. Какой из типов вы обычно используете? Почему? При каких условиях вы используете другой тип данных?
	// 2. Что делает следующий фрагмент кода?
	// 3. И vector, и deque обычно резервируют некоторую дополнительную память для предотвращения чрезмерно частого перераспределения памяти при добавлении новых элементов.
	// Можно ли полностью очистить vector или deque(т.е.не только удалить все содержащиеся в них элементы, но и освободить всю зарезервированную память) ? Продемонстрируйте, как это сделать, или поясните, почему этого сделать нельзя.


	// Задача 1.15.Использование set и mар
	void task15();
	// Ключевое правило ассоциативного контейнера
	// После того как ключ вставлен в ассоциативный контейнер, он никогда не должен изменять свое относительное положение в этом контейнере.
	

	// Задача 1.16.Эквивалентный код?(5)
	void task16();
	// 1. Опишите, что делает следующий код.
	
	// пример 1. 
	// 
	// f(а++);

	// 2. В чем состоит различие, если таковое имеется, между двумя приведенными фрагментами кода?
	// пример 2а. 
	// 
	// f(а++);
	// пример 26. 
	// 
	// f(a);
	// а++;

	// 3. В вопросе 2 сделаем предположение, что f () — функция, принимающая аргумент по значению, и что класс объекта имеет operator++(int)с естественной семантикой.В чем теперь состоит различие(если таковое имеется) между примерами 2а и 26?

	// 1. Итак, f может представлять собой следующее.
	// 1) Макрос
	// #define f(x) x // 1 раз 
	// #define f(x) (х,х,х,х,х,х,х,х,х) // 9 раз 
	// #define f(x) // ни разу 
	// Избегайте использования макросов.Это обычно затрудняет понимание и, соответственно , сопровождение кода.
	// 2) Функция 
	// В этом случае сначала вычисляется а++, после чего результат передается функции в качестве параметра.
	// 3) Объект
	// как и функция
	// 4) Имя типа
	// В этом случае инструкция сначала вычисляет а++ и использует результат этого выражения для инициализации временного объекта типа f.
	// В свою очередь, а может представлять собой следующее.
	// 1) Макрос
	// В этом случае а может означать почти что угодно.
	// 2) Объект (возможно, встроенного типа) 
	// Всегда сохраняйте естественную семантику при перегрузке операторов. 'Поступайте так, как поступает int", — т.е. следуйте семантике встроенных типов.
	// 3) Значение, такое как адрес
	// Например, а может быть указателем.

	// Побочные действия
	// Не играть с недействительными итераторами.
	
	// Задача 1.17. Специализация и перегрузка шаблонов(6)
	void task17();
	// 1. Что такое специализация шаблона? Приведите пример. 
	// 2. Что такое частичная специализация? Приведите пример. 
	// 3. Рассмотрим следующие объявления.
	template<typename T1, typename T2>
	void g(T1, T2)
	{
		cout << "1" << endl;
	}

	template<typename T>
	void g(T)
	{
		cout << "2" << endl;
	}

	template<typename T>
	void g(T, T)
	{
		cout << "3" << endl;
	}

	template<typename T>
	void g(T*)
	{
		cout << "4" << endl;
	}

	template<typename T>
	void g(T*, T)
	{
		cout << "5" << endl;
	}

	template<typename T>
	void g(T, T*)
	{
		cout << "6" << endl;
	}

	template<typename T>
	void g(int, T*)
	{
		cout << "7" << endl;
	}

	// Задача 1.18. Mastermind(8)
	void task18();
}
