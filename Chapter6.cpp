#include "Chapter6.h"

// ���������� ������� � ��������� 
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


	// ������ 6.1.���������� �������.����� 1(3)
	void task1()
	{

	}


	// ������ 6.2. ���������� �������. ����� 2(6)
	void task2()
	{
		// D* pdl = new D;
		// delete pdl; // D::operator delete(void*).

		// B* pb2 = new D;
		// delete pb2; // D::operator delete(void*). 

		// D* pd3 = new D[10];
		// delete[] pd3; // D::operator delete[] (void*).
		
		// B* pb4 = new D[10];
		// delete[] pb4; // �� ����������
		// ���� �������, ����� ����������� ��� ���������, ������������� operator deleted(), �������������� ��� ������������� ����.

		// B �;
		// typedef void (B::*pmf)(void*, size_t);
		// pmf pi = &B::f;
		// pmf p2 = &B::operator delete; // ����������� ������� - ����
	}


	// ������ 6.3. ���������� auto_ptr. ����� 1 
	void task3()
	{

	}

	// ������ 6.4.���������� auto_ptr.����� 2(5)
	void task4()
	{

	}


	// ������ 6.5. ���������������� ���������-�����. ����� 1(5)
	void task5()
	{

	}


	// ������ 6.6. ���������������� ���������-����� ����� 2(6)
	void task6()
	{

	}
}
