﻿#pragma once

#include <iostream>
#include <complex> 

using namespace std;

// Разработка классов, наследование и полиморфизм
namespace nsClassDevelopmentInheritancePolymorphism
{
	void main();


	// Задача 3.1. Механика классов(7)
	void task1();
	// Насколько хорошо вы разбираетесь в деталях написания классов?
	// Эта задана посвящена не только явным ошибкам при создании классов;
	// скорее, она в большей степени относится к профессиональному стилю разработки.
	// Понимание основных принципов поможет вам при разработке более надежных и легче поддерживаемых классов.

	class Complex
	{
	public:
		Complex(double real, double imaginary = 0)
			:_real(real), _imaginary(imaginary)
		{

		}
			
		void operator + (Complex other)
		{
			_real = _real + other._real;
			_imaginary = _imaginary + other._imaginary;
		}

		void operator << (std::ostream os)
		{
			os << "(" << _real << "," << _imaginary << ")";
		}

		Complex operator ++ ()
		{
			++_real;
			return *this;
		}

		Complex operator ++ (int)
		{
			Complex temp = *this;
			++_real;
			return temp;
		}

	private:
		double _real, _imaginary;
	};

	// Вместо написания собственного кода повторно используйте имеющийся, в особенности код стандартной библиотеки.
	// Это быстрее, проще и безопаснее.

	// 1. Конструктор позволяет неявное преобразование.
	// Не забывайте о скрытых временных объектах, создаваемых при неявном преобразовании. 
	// Избежать их появления можно, объявляя по возможности разрабатываемые вами конструкторы как explicit и избегая написания операторов преобразования.
	
	// Оператор + недостаточно эффективен.
	// По возможности передавайте объекты в качестве параметров функции по ссылке, как const&, а не по значению.
	// Предпочтительно использовать "а ор= Ь; " вместо "а = a op b;" (где ор означает некоторый оператор).
	// Такой код проще для понимания и зачастую более эффективен.
	// T& T::operator+=(const T& other) 
	// {
	// 	//... 
	//	return *this;
	// }
	// const T operator+(const T& a, const T& b)
	// {
	// 	T temp(a);
	// 	temp += b;
	// 	return temp;
	// }
	// Если вы предоставляете автономную версию некоторого оператора(например, operator*), всегда предоставляйте и присваивающую версию этого оператора(operator+=), причем предпочтительна реализация первого оператора посредством второго.
	// Кроме того, сохраняйте естественные взаимоотношения между ор и ор = (здесь ор означает произвольный оператор).
	
	// 3. operator+ не должен быть функцией-членом.
	// Стандарт требует, чтобы операторы = , [], () и -> были членами, а операторы new, new[], delete и delete[] — статическими членами.
	// Для всех остальных функций действует следующее правило.
	// Если функция представляет собой operator >> или operator << для потокового ввода-вывода, или если она требует преобразования типа левого аргумента, или если она может быть реализована только с использованием открытого интерфейса класса, ее следует сделать нечленом класса (в первых двух случаях — другом класса).
	// Если требуется виртуальное поведение данной функции, добавьте виртуальную функцию - член и реализуйте ее посредством соответствующей функции - нечлена, в противном случае сделайте ее членом класса.

	// 4. operator+ не должен изменять значение объекта и должен возвращать временный объект, содержащий сумму.

	// 5. Если вы определяете оператор ор, вам следует определить и оператор ор=.
	// В данном случае, поскольку у вас определен operator*, вы должны определить и operator+= и реализовать оператор + посредством оператора +=.
	
	// 6. operator << не должен быть функцией-членом.

	// 7. operator << должен иметь возвращаемый тип ostream& и должен возвращать ссылку на поток, чтобы обеспечить возможность использования цепочек выводов типа "cout << а << Ь".
	// Всегда возвращайте ссыпку на поток из операторов operator<< u operator>>.

	// 8. Возвращаемый тип оператора преинкремента некорректен.
	// Преинкремент должен возвращать ссылку на неконстантный объект — в нашем случае Complex&. Это обеспечивает более интуитивный и эффективный код клиента.

	// 9. Возвращаемый тип оператора постинкремента некорректен.
	// Постинкремент должен возвращать константное значение — в данном случае const Complex.

	// 10. Постинкремент должен быть реализован посредством преинкремента
	// Для согласованности всегда реализуйте постфиксный инкремент посредством префиксного;
	// в противном случае ваши пользователи получат неожиданные(и, скорее всего, неприятные) результаты.

	// 11. Избегайте использования зарезервированных имен.
	// не использовать ведущие подчеркивания вовсе.


	// Задача З.2.Замещение виртуальных функций(6)
	void task2();

	class Base
	{
	public:
		virtual void f(int);
		virtual void f(double);
		virtual void g(int i = 10);
	};
	
	class Derived : public Base
	{
	public:
		void f(complex<double>);
		void g(int i = 20);
	};

	// 1. void main() является нестандартной инструкцией и, соответственно, непереносимой.
	// 2. Использование delete pb; небезопасно.
	// Делайте деструктор базового класса виртуальным (за исключением тех случаев, когда вы совершенно точно знаете, что не будет никаких попыток удаления производного объекта посредством указателя на базовый).

	// - Перегрузка (overload) функции f () означает наличие другой функции с тем же именем(f) в той же области видимости, но с другими типами параметров.
	// При вызове f () компилятор пытается выбрать наиболее подходящую для типов фактических параметров функцию.
	// - Замещение, или переопределение (override) виртуальной функции f() означает наличие в производном классе другой функции с тем же именем(f) и теми же типами параметров.
	// - Сокрытие (hide) функции f() в окружающей области видимости (базовый класс, внешний класс или пространство имен) означает наличие другой функции с тем же именем(f) во вложенной области видимости(производный класс, вложенный класс или пространство имен), так что эта функция скрывает функцию с тем же именем из объемлющей области видимости.
	
	// 3. Derived::f не является перегруженной. Класс Derived не перегружает, а скрывает Base::f.
	// Это отличие очень важно, поскольку означает, что Base::f(int) и Base::f(double) не видимы в области видимости Derived.
	// (Удивительно, но некоторые популярные компиляторы даже не выводят предупреждения об этом, так что знать о сокрытии важнее, чем можно было бы предполагать.)
	// При использовании функции с тем же именем, что и у унаследованной функции, убедитесь, что унаследованные функции внесены в область видимости с помощью объявления using, если только вы не намерены скрывать их.

	// 4. Derived::g замещает Base::g, но при этом изменяет параметр по умолчанию.
	// Никогда не изменяйте параметры по умолчанию замещаемых унаследованных функций.


	// Задача 3.3.Взаимоотношения классов.Часть 1(5)
	void task3();
	// Каковы ваши познания в области объектно - ориентированного проектирования? Эта задача иллюстрирует ряд распространенных ошибок при проектировании классов.

	class BasicProtocol /* : возможные базовые классы */
	{
	public:
		BasicProtocol();
		virtual ~BasicProtocol();
		bool BasicMsgA( /* ... */);
		bool BasicMsgB( /* ... */);
		bool BasicMsgC( /* ... */);
	};

	class Protocol1 : public BasicProtocol
	{
	public:
		Protocol1();
		~Protocol1();
		bool DoMsgl( /* ... */);
		bool DoMsg2( /* ... ;*/);
		bool DoMsg3( /* ... */);
		bool DoMsg4( /* ... */);
	};

	class Protocol2 : public BasicProtocol
	{
	public:
		Protocol2();
		~Protocol2();
		bool DoMsgl( /* ... */);
		bool DoMsg2( /* ... ;*/);
		bool DoMsg3( /* ... */);
		bool DoMsg4( /* ... */);
	};

	// Каждая функция - член DoMsg...() вызывает для выполнения общей работы функции BasicProtocol::Basic...(), но реальная передана осуществляется функциями DoMsg... ().
	// Никогда не используйте открытое наследование, за исключением модели ЯВЛЯЕТСЯ и РАБОТАЕТ КАК.
	// Все замещающие функции - члены при этом не должны предъявлять повышенные требования к условиям своей работы и не должны иметь пониженную функциональность по сравнению с оригиналом.
	// Никогда не используйте открытое наследование для повторного использования кода(базового класса).
	// Используйте открытое наследование только для того, чтобы быть повторно использованным кодом, полиморфно использующим базовые объекты.
	// 1. BasicProtocol не имеет виртуальных функций (кроме деструктора, о которомчуть позже).
	// Это означает, что он не предназначен для полиморфного использования, что само по себе является аргументом против открытого наследования.
	// 2. BasicProtocol не имеет защищенных функций или членов.
	// Это означает, что отсутствует "интерфейс наследования", что является аргументом против любого наследования, как открытого, так и закрытого.
	// 3. BasicProtocol инкапсулирует общую деятельность, но, как указывалось, он не выполняет реальную передачу — это делают производные классы.
	// Это означает, что объект BasicProtocol не РАБОТАЕТ КАК производный объект протокола и не ИСПОЛЬЗУЕТСЯ КАК производный объект протокола.
	// Открытый интерфейс должен использоваться только в одном случае — для взаимоотношения ЯВЛЯЕТСЯ, подчиняющегося принципу подстановки Лисков(LSP).
	// Для большей ясности я обычно называю это взаимоотношение РАБОТАЕТ КАК или ИСПОЛЬЗУЕТСЯ КАК.
	// 4. Производный класс использует только открытый интерфейс BasicProtocol.
	// Это означает, что в данном случае наследование не дает никаких преимуществ, а вся необходимая работа может быть выполнена с помощью отдельного вспомогательного объекта типа BasicProtocol.
	// При моделировании отношения "реализован посредством" предпочтительно использовать делегирование, а не наследование.
	// Используйте закрытое наследование только тогда, когда оно совершенно необходимо, т.е. когда вам требуется доступ к защищенным членам или требуется заместить виртуальную функцию.
	// Никогда не используйте открытое наследование для повторного использования кода.
	
	// Задача 3.4. Взаимоотношения классов. Часть 2(6)
	void task4();
	// Шаблоны проектирования представляют собой важный инструмент при написании повторно используемого кода.
	// Распознаете ли вы шаблоны проектирования в данной задаче? Если да, сможете ли вы их улучшить?

	class Record;
	class PrimaryKey;

	class GenericTableAlgorithm
	{
	public:
		GenericTableAlgorithm(const string& table);
		virtual ~GenericTableAlgorithm();
		// Process () возвращает true тогда и только тогда, 
		// когда выполнение функции завершается успешно. 
		// Функция выполняет следующую работу: 
		// а) физически читает записи таблицы, вызывая для 
		// каждой из них Filter() для определения того, 
		// должна ли данная запись быть обработана 
		// б) после составления списка обрабатываемых строк 
		// вызывает ProcessRow() для каждой строки из списка. 
		bool Process();

	private:
		// FilterO возвращает true тогда и только тогда, 
		// когда строка должна быть включена в список 
		// обрабатываемых строк, действие по умолчанию - 
		// возврат true - все строки должны быть обработаны. 
		virtual bool Fi1ter(const Record&);
		// ProcessRow() вызывается для каждой записи из списка 
		// обрабатываемых строк. Здесь конкретный класс 
		// указывает, какие действия должны быть выполнены над 
		// строкой, (примечание: это означает, что каждая 
		// обрабатываемая строка будет считана дважды, однако 
		// будем считать, что это необходимо, и не будем 
		// рассматривать вопросы производительности.; 
		virtual bool ProcessRow(const PrimaryKey&) = 0;

		struct GenericTableAlgorithmImpl* pimpl_;
	};

	// 1. Этот проект реализует хорошо известный шаблон проектирования.Какой? Почему он применим в данном случае?
	// 2. Не изменяя основ проекта, проанализируйте способ его осуществления.
	// Что бы вы предпочли сделать иначе? В чем состоит предназначение члена pimpl_?
	// 3. Приведенный проект на самом деле может быть значительно усовершенствован.
	// За что отвечает класс GenericTableAlgorithm? Если он одновременно решает несколько задач, то каким образом можно улучшить их инкапсуляцию?
	// Поясните, как ваш ответ влияет на повторное использование класса и, в частности, на его расширяемость.

	// 1. Template Method.
	// Избегайте открытых виртуальных функций; вместо них предпочтительнее использовать шаблон проектирования "Метод шаблона".
	// Не забывайте о существовании шаблонов проектирования.

	// 2. Для широко используемых классов предпочтительно использовать идиому указателя на реализацию(Pimpl) для сокрытия деталей реализации.
	// Для хранения закрытых членов (как функций, так и переменных) используйте непрозрачный указатель(указатель на объявленный, но не определенный класс), объявленный как "struct xxxxlmpl*  pimpl_;
	// ", например " class Map { private: struct Maplmpl* pimpl_ }; ".

	// 3. рассматриваемый класс только выиграет от разделения стоящих перед ним задач между двумя классами.
	// - Код клиента ИСПОЛЬЗУЕТ (специализированный соответствующим образом) обобщенный алгоритм.
	// - GenericTableAlgorithm ИСПОЛЬЗУЕТ специализированный конкретный класс "деталей", определяющий его действия в конкретной ситуации.
	// Каждая часть кода — каждый модуль, класс, функция — должны отвечать за выполнение единой, четко определенной задачи.
	// 1) Что произойдет при изменении открытого интерфейса GenericTableAlgorithm?
	// В исходной версии потребуется перекомпиляция всех конкретных рабочих классов, поскольку они являются производными от GenericTableAlgorithm.
	// В усовершенствованной версии все изменения открытого интерфейса GenericTableAlgorithm надежно изолированы и никак не влияют на конкретные рабочие классы.
	// 2) Что произойдет при изменении расширяемого протокола GenericTableAlgorithm(например, при добавлении аргументов по умолчанию к функциям Filter() или ProcessRow())?
	// В исходной версии требуется перекомпиляция всех внешних клиентов GenericTableAlgorithm(несмотря на то, что открытый интерфейс остался неизменным), поскольку производный интерфейс видим в определении класса.
	// В усовершенствованной версии все изменения интерфейса протокола GenericTableAlgorithm надежно изолированы и никак не влияют на внешних пользователей.
	// 3) Любой конкретный рабочий класс теперь может быть использован не только в алгоритме GenericTableAlgorithm, но и в любом другом, который работает с использованием интерфейса Filter() / ProcessRow().
	// To, что мы получили в результате усовершенствования, очень напоминает стратегический шаблон проектирования(Strategy pattern).


	// Задача 3.5.Наследование: потребление и злоупотребление (6)
	void task5();
	// Почему наследование? Наследованием часто чрезмерно увлекаются даже опытные разработчики.
	// Однако следует всегда минимизировать взаимосвязи объектов.
	// Если взаимоотношение между классами может быть выражено несколькими способами, следует использовать тот, который при сохраняющейся практичности приводит к наиболее слабым связям.
	// Наследование, будучи одной из самых сильных связей(второй после отношения дружбы), которые можно выразить средствами C++, может применяться только тогда, когда нет эквивалентной альтернативы с более слабым взаимодействием.
	// В данной задаче нас интересуют вопросы наследования.Попутно мы создадим практически полный список всех обычных и необычных причин для использования наследования.
	
	// пример 1 
	// 
	template<class T>
	class MyList
	{
	public:
		bool Insert(const T&, size_t index);
		T Access(size_t index) const;
		size_t Size() const;

	private:
		T* buf_;
		size_t bufsize_;
	};

	// пример 1а 
	template<class T>
	class MySet1 : private MyList<T>
	{
	public:
		bool Add(const T&); // вызывает insert() 
		T Get(size_t index) const; // вызывает Access() 
		// using MyList<T>::Size();
		// ...
	};

	// Пример 16 
	template<class T>
	class MySet2
	{
	public:
		bool Add(const T&); // Вызывает imp1_.lnsert() 
		T Get(size_t index);
		// вызывает impl_.Access() 
		size_t Size() const; // вызывает imp1_.Size() 
		// ... 
	private:
		MyList<T> impl_;
	};

	// 1. Имеется ли различие между MySetl и MySet2?
	// 2. Говоря более обобщенно, в чем заключается различие между закрытым наследованием и включением?
	// Приведите по возможности более полный список причин, по которым могло бы потребоваться использовать наследование, а не включение.
	// - Закрытое наследование всегда должно выражать отношение РЕАЛИЗОВАН ПОСРЕДСТВОМ(за одним редким исключением, о котором я скажу чуть позже).
	// Оно делает использующий класс зависящим от открытых и защищенных частей используемого класса.
	// - Включение всегда выражает отношение СОДЕРЖИТ и, следовательно, РЕАЛИЗОВАН ПОСРЕДСТВОМ.
	// Включение делает использующий класс зависящим только от открытых частей используемого класса.
	// Предпочтительно использовать включение (делегирование, отношение СОДЕРЖИТ, композицию, агрегирование и т.д.), а не наследование.
	// При работе с моделью РЕАЛИЗОВАН ПОСРЕДСТВОМ всегда используйте выражение посредством включения, а не наследования.

	// В каком случае использовать закрытое наследование?
	// - Нам требуется замещение виртуальной функции.
	// - Нам требуется доступ к защищенным членам.
	// - Нам требуется создание используемого объекта до (или уничтожение его после) другого базового подобъекта.
	// - Нам требуется совместное использование общего виртуального базового класса или замещение конструктора виртуального базового класса.
	// - Получение существенной выгоды от оптимизации пустого базового класса.
	// - Нам требуется Управляемый полиморфизм " — ЯВЛЯЕТСЯ из принципа подстановки Лисков — но только на определенном участке кода.
	
	// 3.
	// - MyList не имеет защищенных членов, так что нам не требуется наследование для доступа к ним.
	// - MyList не имеет виртуальных функций, так что нам не требуется наследование для их замещения.
	// - MySet не имеет других потенциальных базовых классов, так что объект MyList не обязан создаваться до или уничтожаться после базового подобьекта.
	// - MyList не имеет виртуальных базовых классов, совместное использование или замещение конструкторов которых могло бы потребоваться классу MySet.
	// - MyList не пуст, так что обоснование "оптимизация пустого класса" в данном случае неприменимо.
	// - MySet HE ЯВЛЯЕТСЯ MyList

	// Пример 2. необходимо наследование 
	class Base1
	{
	public:
		virtual int Func1();
	protected:
		bool Func2();
	private:
		bool Func3(); // использует Func 
	};

	// пример 1в. Обобщенное включение 
	// 
	template<class T, class impl = MyList<T> >
	class MySet3
	{
	public:
		bool Add(const T&); // вызывает impl_.insert() 
		T Get(size_t index) const;
		// вызывает impl_.Access() 
		size_t Size() const; // вызывает impl_.size() 
		// ... 
	private:
		impl impl_;
	};

	// используйте открытое наследование только для моделирования истинного отношения ЯВЛЯЕТСЯ.
	// - Никогда не используйте открытое наследование там, где достаточно закрытого. 
	// Открытое наследование никогда не должно применяться для моделирования отношения РЕАЛИЗОВАН ПОСРЕДСТВОМ без истинного отношения ЯВЛЯЕТСЯ.
	// - Никогда не используйте открытое наследование для реализации отношения "ЯВЛЯЕТСЯ ПОЧТИ".
	// Всегда убеждайтесь, что открытое наследование, в соответствии с принципом подстановки Лисков, моделирует как отношение ЯВЛЯЕТСЯ, так и РАБОТАЕТ ПОДОБНО.
	// Все замещающие функции - члены при этом не должны предъявлять повышенные требования к условиям своей работы и не должны иметь пониженную функциональность по сравнению с оригиналом.
	// Никогда не используйте открытое наследование для повторного использования кода (базового класса); используйте открытое наследование только для того, чтобы быть повторно использованным кодом, полиморфно использующим базовые объекты.


	// Задача 3.6. Объектно-ориентированное программирование(4)
	void task6();
	// Является ли C++ объектно-ориентированным языком? И да, и нет, вопреки распространенному мнению.
	// Данная маленькая задана поможет вам понять это утверждение.
	// Не спешите быстро дать ответ на вопрос и перейти к другим задачам — сначала немного подумайте.
	// 1. Не все согласны с тем, что именно обозначает "объектно-ориентированный".
	// Так что же такое объектная ориентированность? Даже сейчас, при широкой ее распространенности, если вы опросите 10 человек, то получите 15 ответов.
	// 2. C++ поддерживает множество парадигм.
	// 3. Ни один язык не может быть абсолютно универсальным.


	// Задача 3.7.Множественное наследование(6)
	void task7();
	// 1. Что такое множественное наследование и какие дополнительные возможности или сложности привносит множественное наследование в C++?
	// 2. Является ли множественное наследование необходимым?
	// Если да, то приведите как можно больше ситуаций, доказывающих необходимость поддержки множественного наследования в языке.
	// Если нет, аргументируйте, почему одиночное наследование, возможно, в сочетании с интерфейсами в стиле Java, не уступает множественному и почему в языке не должно быть множественного наследования.

	// 1. основная сложность виртуальных базовых классов состоит в том, что они должны быть непосредственно инициализированы в последнем производном классе иерархии.
	// Избегайте множественного наследования больше чем от одного непротокольного класса (под протокольным классом мы понимаем абстрактный базовый класс, состоящий исключительно из чисто виртуальных функций и не содержащий данных).
	// 2. Коротко можно ответить так: ни одна возможность языка не является "необходимой".
	// Большинство реальных применений множественного наследования можно разделить на три категории.
	// - Комбинирование модулей или библиотек.
	// - Классы протоколов (интерфейсов).
	// - Простота (полиморфного) использования.
	
	
	// Задача 3.8. Эмуляция множественного наследования(5)
	void task8();
	// Если использование множественного наследования невозможно, каким образом можно его эмулировать?
	// Данная задана поможет вам понять, почему множественное наследование в C++ работает именно так, а не иначе.
	// При решении задачи постарайтесь по возможности использовать максимально естественный синтаксис вызывающего кода.


	// Задача 3.9.Множественное наследование и проблема сиамских близнецов(4)
	void task9();
	// Замещение унаследованной виртуальной функции — дело несложное, но только до тех пор, пока вы не пытаетесь заместить виртуальную функцию, имеющую одну и ту же сигнатуру в двух базовых классах.
	// Такое может случиться, даже если базовый класс не был разработан сторонним производителем! Так как же можно разделить такие "сиамские функции"?
	class BaseA
	{
		virtual int ReadBuf(const char*);
		// ... 
	};

	class BaseB
	{
		virtual int ReadBuf(const char *);
		// ...
	};

	// пример 1. Попытка №1, неверная 
	class Derived1 : public BaseA, public BaseB
	{
		// ... 
		int ReadBuf(const char*);
		// Замещает как BaseA::ReadBuf(), 
		// так и BaseB::ReadBufС) 
	};

	// Пример 2. Попытка №2, корректная 
	// 
	class BaseA2 : public BaseA
	{
	public:
		virtual int BaseAReadBuf(const char* p) = 0;
	private:
		int ReadBuf(const char* p) // Замещение наследованной
		{
			return BaseAReadBuf(p); // вызов новой функции
		}
	};

	class BaseB2 : public BaseB
	{
	public:
		virtual int BaseBReadBuf(const char* p) = 0;
	private:
		int ReadBuf(const char* p) // Замещение наследованной 
		{
			return BaseBReadBuf(p); // вызов новой функции 
		}
	};

	class Derived2 : public BaseA2, public BaseB2
	{
	public: // или private: - в зависимости от того, должен ли 
		// код быть доступен для непосредственного вызова 
		int BaseAReadBuf(const char*);
		// Замещает BaseA::ReadBuf косвенно, 
		// через BaseA2::BaseAReadBuf 
		int BaseBReadBuf(const char*);
		// Замещает BaseB::ReadBuf косвенно, 
		// через BaseB2::BaseBReadBuf 
	};


	// Задача 3.10. (Не)чисто виртуальные функции(7)
	void task10();
	// Имеет ли смысл снабжать чисто виртуальную функцию телом?
	// 1. Что такое чисто виртуальная функция? Приведите пример.
	// 2. Для чего может понадобиться написание тела для чисто виртуальной функции? 
	// Приведите по возможности как можно больше причин для такого решения.

	// 1. Чисто виртуальный деструктор
	// Всегда делайте деструкторы базовых классов либо виртуальными и открытыми, либо невиртуальными и защищенными.
	// 2. Определение поведения по умолчанию
	// 3. Обеспечение частичной функциональности
	// 4. Обходной путь недостаточной диагностики компилятора


	// Задача 3.11. Управляемый полиморфизм(3)
	void task11();
	// Отношение ЯВЛЯЕТСЯ— очень полезный инструмент в объектно-ориентированном моделировании.
	// Однако иногда может потребоваться запретить полиморфное использование некоторых классов.
	// В данной задаче приведен соответствующий пример и показано, как достичь требуемого эффекта.
	// friend + закрытое наследование.
}