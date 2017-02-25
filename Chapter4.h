﻿#pragma once

// Брандмауэр и идиома скрытой реализации
namespace nsFirewallAndPimpl
{
	void main();


	// Задача 4.1. Минимизация зависимостей времени компиляции.Часть 1(4)
	void task1();
	// Когда мы говорим о зависимостях, то обычно подразумеваем зависимости времени выполнения, типа взаимодействия классов.
	// В данной задаче мы обратимся к анализу зависимостей времени компиляции.
	// В качестве первого шага попытаемся найти и ликвидировать излишние заголовочные файлы.
	// 1. Удалите #include <iostream>
	// Никогда не включайте в программу излишние заголовочные файлы.
	// 2. Замените ostream на iosfwd
	// - ostream теперь находится в пространстве имен std, а программисту запрещается объявлять что - либо, находящееся в этом пространстве имен.
	// - ostream в настоящее время представляет собой синоним шаблона, а именно шаблона basic_ostream<char>.
	// Там, где достаточно предварительного определения потока, предпочтительно использо ватъ директиву #include <iosfwd>.
	// До тех пор пока мы работаем со ссылкой ostream&, полное определение ostream необходимым не является.
	// 3. Замените "#include "e.h"" предварительным определением "class E;"
	// Класс Е упоминается только в качестве типа параметра и возвращаемого типа, так что его определение нам не требуется.
	// Никогда не используйте директиву #include там, где достаточно предварительного объявления.


	// Задача 4.2. Минимизация зависимостей времени компиляции.Часть 2(6)
	void task2();
	// Теперь, когда удалены все излишние заголовки, пришло время для второго захода: каким образом можно ограничить зависимости внутреннего представления класса?
	// Давайте рассмотрим, чего мы не можем сделать. 
	// - Мы не можем удалить a.h и b.h, поскольку X является наследником как А, так и B.
	// Для того чтобы компилятор мог получить размер объекта х, информацию о виртуальных функциях и прочую существенную информацию, требуется полное определение базовых классов.
	// - Мы не можем удалить list, c.h и d.h, поскольку list<C> и D представляют собой типы членов данных X.
	// Скрытая реализация представляет собой не что иное, как непрозрачный указатель (указатель на предварительно объявленный, но не определенный вспомогательный класс)
	// Основные преимущества идиомы скрытой реализации обусловлены тем, что она позволяет разорвать зависимости времени компиляции.
	// - Типы, упоминающиеся только в реализации класса, больше не должны быть определены в коде клиента, что позволяет устранить лишние директивы #include и повысить скорость компиляции.
	// - Реализация класса может быть легко изменена — вы можете свободно добавлять или удалять закрытые члены без перекомпиляции клиентского кода.
	// - Каждое создание и уничтожение объекта сопровождается выделением и освобождением памяти.
	// - Каждое обращение к скрытому члену требует как минимум одного уровня косвенности. (Уровней косвенности может оказаться и несколько, например, если обращение к скрытому члену использует указатель для вызова функции в видимом классе.)
	// Для широко используемых классов предпочтительно использовать идиому сокрытия реализации(брандмауэр компиляции, Pimpl) для сокрытия деталей реализации.
	// Для хранения закрытых членов(как переменных состояния, так и функций - членов) используйте непрозрачный указатель(указатель на объявленный, но не определенный класс), объявленный как "struct xxxxlmpl* pimpl_;".Например: "class Map { private: struct Maplmpl* pimpl_; }; ".
	
	// Задача 4.3. Минимизация зависимостей времени компиляции.Часть 3(7)
	void task3();
	// Теперь, когда удалены все излишние заголовочные файлы и устранены все излишние зависимости во внутреннем представлении класса, остались ли какие - либо возможности для дальнейшего разъединения классов?
	// Ответ возвращает нас к базовым принципам проектирования классов.
	// Дело в том, что класс в является закрытым базовым классом для X, но не имеет виртуальных функций.
	// Никогда не используйте наследование там, где достаточно включения.
	
	
	// Задача 4.4. Брандмауэры компиляции(6)
	void task4();
	// Использование скрытой реализации (идиомы PimpI) существенно снижает взаимозависимости кода и время построения программ.
	// Но что именно следует скрывать за указателем pimpl и как наиболее безопасно использовать его?
	// 1. Что следует внести в ximpl? Имеется четыре распространенные стратегии. 
	// - Разместить в Ximpl все закрытые данные (но не функции). 
	// - Разместить в ximpl все закрытые члены.
	// - Разместить в ximpl все закрытые и защищенные члены.
	// - Сделать ximpl классом, полностью повторяющим класс X, которым он должен был бы быть, и оставить в классе X только открытый интерфейс, просто перенаправляющий вызовы функций классу Ximpl.
	// 2. Требуется ли наличие в ximpl обратного указателя на объект X?
	
	// 1.
	// 1 - (6/10) 
	// 2 - (10/10) разместить в Xlmp все закрытые невиртуальные члены.
	// - Вы не можете скрывать виртуальные функции-члены, даже если это закрытые функции.
	// - Если функция в Pimpl-классе в свою очередь использует функции видимого класса, то ей может потребоваться "обратный указатель" на видимый объект, что приводит к дополнительному уровню косвенности
	// - Зачастую наилучшим компромиссом является использование варианта 2, с дополнительным размещением в Xlmpl тех не закрытых функций, которые должны вызываться закрытыми.
	// Для широко используемых классов предпочтительно использовать идиомы сокрытия реализации(брандмауэра компиляции, Pimp!) для сокрытия деталей реализации.
	// Для хранения закрытых членов(как переменных состояния, так и функций - членов) используйте непрозрачный указатель(указатель на объявленный, но не определенный класс), объявленный как "struct ххххimp I* pimp 7_; ".
	// 3 - (0/10)
	// Распространение идиомы Pimpl на защищенные члены является ошибкой.
	// 4 - (оценка: 10/10 в некоторых ситуациях)
	
	// 2. иногда - да


	// Задача 4.5. Идиома "Fast Pimpl"(6)
	void task5();
	// Иногда хочется схитрить во имя Уменьшения зависимостей" или "эффективности ", но не всегда это приводит к хорошим результатам.
	// В данной задаче рассматривается превосходная идиома для безопасного достижения обеих целей одновременно.
	// - используйте выравнивание
	// Избегайте использования встроенных функций и настройки кода, пока необходимость этого не будет доказана путем профилирования программы.
}
