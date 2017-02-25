#include "Chapter7.h"
#include <algorithm>

using namespace std;

namespace nsOptimizationAndPerformance
{
	void main()
	{
		// task1();
		// task2();
		// task3();
		// task4();
		task5();
	}


	// Задача 7.1. inline(4)
	void task1()
	{

	}


	// Задача 7.2. Отложенная оптимизация. Часть 1(2)
	void task2()
	{

	}

	String::String()
		:buf_(0), len_(0), used_(0)
	{
	}

	String::~String()
	{
		delete[] buf_;
	}

	String::String(const String& other)
		:buf_(new char[other.len_]),
		len_(other.len_),
		used_(other.used_)
	{
		// copy(other.buf_, other.buf_ + used_, buf_);
	}

	void String::Reserve(size_t n)
	{
		if (len_ < n)
		{
			size_t newlen = max(len_*1.5, (double)n);
			char* newbuf = new char[newlen];
			// copy(buf_, buf_ + used_, newbuf);

			delete[] buf_;
			buf_ = newbuf;
			len_ = newlen;
		}
	}

	void String::Append(char c)
	{
		Reserve(used_ + 1);
		buf_[used_++] = c;
	}


	// Задача 7.3. Отложенная оптимизация. Часть 2(3)
	void task3()
	{

	}

	namespace optimized
	{
		StringBuf::StringBuf()
			:buf(0), len(0), used(0), refs(1)
		{
		}

		StringBuf::~StringBuf()
		{
			delete[] buf;
		}

		void StringBuf::Reserve(size_t n)
		{
			if (len < n)
			{
				size_t newlen = max(len*1.5, (double)n);
				char* newbuf = new char[newlen];
				// copy(buf_, buf_ + used_, newbuf);

				delete[] buf;
				buf = newbuf;
				len = newlen;
			}
		}

		String::String()
			:data_(new StringBuf)
		{
		}

		String::~String()
		{
			if (--data_->refs < 1)
				delete data_;
		}

		String::String(const String& other)
			:data_(other.data_)
		{
			++data_->refs;
		}

		void String::AboutToModify(size_t n)
		{
			if (data_->refs > 1)
			{
				auto_ptr<StringBuf> newdata(new StringBuf);
				newdata->Reserve(max(data_->len, n));
				// copy(data_->buf, data_->buf + data_->used, newdata->buf);
				newdata->used = data_->used;
				--data_->refs;
				data_ = newdata.release();
			}
			else
				data_->Reserve(n);
		}

		void String::Append(char c)
		{
			AboutToModify(data_->used + 1);
			data_->buf[data_->used++] = c;
		}

		size_t String::Length() const
		{
			return data_->used;
		}

		char& String::operator[](size_t n)
		{
			AboutToModify(data_->len);
			return data_->buf[n];
		}

		const char& String::operator[](size_t n) const
		{
			return data_->buf[n];
		}

	}


	// Задача 7.4.Отложенная оптимизация.Часть 3(6)
	void task4()
	{

	}


	// Задача 7.5.Отложенная оптимизация.Часть 4(8)
	void task5()
	{

	}
}
