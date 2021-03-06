﻿#pragma once

// Оптимизация и производительность
namespace nsOptimizationAndPerformance
{
	void main();


	// Задача 7.1. inline(4)
	void task1();
	// Вопреки распространенному мнению, ключевое слово inline — отнюдь не панацея.
	// Это всего лишь полезный инструмент, если правильно его применять.
	// Когда именно вы должны это делать?

	// 1. Что делает ключевое слово inline?
	// 2. Увеличивает ли эффективность описание функции как inline?
	// что мы подразумеваем под эффективностью?
	// Имеем ли мы в виду размер программы, использование памяти, время выполнения, скорость разработки, время построения или что-то, не попавшее в этот список?
	// объявление функции как inline может как улучшить, так и ухудшить все перечисленные аспекты эффективности.
	// a) Размер программы.
	// b) Использование памяти.
	// c) Время выполнения.
	// например, если внутренний цикл вызывающей программы больше не помещается в кэше процессора, то общая скорость выполнения может заметно снизиться.
	// d) Скорость разработки, время построения.
	// И последнее: когда вы пытаетесь повысить эффективность программы, всегда начинайте с рассмотрения используемых вами алгоритмов и структур данных.
	
	// Скажи оптимизации "Нет" 
	// 3. Когда и какие функции следует описывать как inline?
	// Первое правило оптимизации: не оптимизируйте. 
	// Второе правило оптимизации : если вы все же решите оптимизировать, см.правило первое.
	// Избегайте тонкой настройки производительности вообще и использования встроенности в частности до тех пор, пока необходимость этого не будет доказана с использованием профайлера.


	// Задача 7.2. Отложенная оптимизация. Часть 1(2)
	void task2();
	// Копирование при записи(именуемое также 'отложенным копированием" ("lazy copy")) представляет собой распространенную технологию оптимизации, использующую счетчики ссылок.
	// Знаете ли вы, как правильно реализовать ее? В этой задаче мы рассмотрим простейший строковый класс, не использующий счетчиков ссылок, а в оставшейся части этой мини - серии задач мы рассмотрим, к каким последствиям может привести добавление к классу семантики копирования при записи.
	
	class String
	{
	public:
		String();
		~String();
		String(const String& other);
		void Append(char c);
		void Reserve(size_t n);

	private:
		char* buf_;
		size_t len_;
		size_t used_;
	};

	// Отступление от темы : какая стратегия увеличения буфера лучше
	// a) Тонный рост
	// - Преимущество: нет расхода памяти впустую.
	// - Недостаток: низкая производительность.
	// b) Рост с фиксированным шагом.
	// - Преимущество: малый расход памяти впустую.
	// - Недостаток: невысокая производительность.
	// c) Экспоненциальный рост.
	// - Преимущество: высокая производительность.
	// - Недостаток: расход части памяти впустую.
	
	
	// Задача 7.3. Отложенная оптимизация. Часть 2(3)
	void task3();
	// Копирование при записи представляет собой распространенный вид оптимизации. 
	// Знаете ли вы, как его реализовать?

	namespace optimized
	{
		class StringBuf
		{
		public:
			StringBuf();
			~StringBuf();
			void Reserve(size_t n);

			char* buf;
			size_t len;
			size_t used;
			unsigned refs;

		private:
			StringBuf(const StringBuf&);
			StringBuf& operator=(const StringBuf&);
		};

		class String
		{
		public:
			String();
			~String();
			String(const String& other);
			void Append(char c);
			size_t Length() const;
			char& operator[](size_t);
			const char& operator[](size_t) const;

		private:
			void AboutToModify(size_t n);
			StringBuf* data_;
		};
	}


	// Задача 7.4.Отложенная оптимизация.Часть 3(6)
	void task4();
	// В этой части мини-серии мы рассмотрим влияние ссылок и итераторов на копируемую при записи строку.Сможете ли вы распознать возникающие проблемы?
	

	// Задача 7.5.Отложенная оптимизация.Часть 4(8)
	void task5();
	// В последней задаче мини-серии рассматривается влияние безопасности потоков на копирование при записи.
	// В действительности ли отложенное копирование является оптимизацией?
	// 1. Почему Optimized::String из предыдущей задачи небезопасна в смысле потоков? Приведите примеры.
	// 2. Покажите, как сделать Optimized::String безопасным:
	// a) в предположении атомарности операций получения, установки и сравнения целых чисел;
	// b) без этого предположения.
	// 3. Обсудите, как все это повлияет на производительность.
	// Большая часть преимуществ отложенного копирования для небольших строк может быть достигнута без применения технологии копирования при записи, путем использования более эффективного распределения памяти.
	// (Само собой, вы можете применять более эффективное распределение памяти наряду с отложенным копированием.)
}
