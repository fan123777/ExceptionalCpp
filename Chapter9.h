#pragma once

// �������, ������ � ����������
namespace nsTrapsErrorsAntiidioms
{
	void main();


	// ������ 9.1.��������������� ��������(5)
	void task1();
	// "��� �?" � ������ ������ ���������� ������ � ���, ��������� �� ��� ��������� �� ���� � ��� �� ������.
	// ������� �� ������ �������� ������������ ����� �������, ����� ��� ���������� ������ �� ������ ��� ���������� �� �������� ������������ ������ ����.
	// �������� ������������, ������������ ������ �������� ���������� ������� � ������, ������������� �������� ������ ���������� � ������ ���������� � � ������ ������������ ������ ����.
	// ���������� �������� ������������ ������ ���� ����� ��� ������������� ������� �������� �������������:
	// - ���� �� ������ ��������� ������������ ������ ����, �� �� � ��������� �������������� ��� ������������.
	// - ���� �� ������ ��������� ������������ ������ ����, �� �� � ��������� �������������� ��� ������������.
	// ����� ������������ �������� �� ������������ ������ ���� ��� �����������, ����� �������� � ���������� �������� ������.
	// - ��������� ���������� � ��������� �������� �� ����������.
	// - ������ ������, �� �� ������ ���������� ������������ ��������� � �������������� ���������� �������� <, <= , >, � >= , ���� � ���������� ��������� ��������� ����� �������� ���������.


	// ������ 9.2. �������������� ��������������(4)
	void task2();
	// �������������� �������������� �� ������ ���� � ������� ����� ���� ������������� ������.
	// ��� ������ ����������, ������ �������������� �������������� ����� ��������� ������������� ��������.
	// ����� ������ ������� �������� ��������������� �������������� �����, ��� ����� �������������� ��������� �������������� ����, ��� � ����������� ������� �� explicit ������������ � ����� ����������.
	// - ������� �������������� ����� ������ ���������� ����������.
	// - ������� �������������� ����� �������� � ���������� ��������� ���� ��� ����� - ���� ��������� �� �������.
	// ��������� ��������� ���������� �������������� ����� � ��-explicit �������������. 


	// ������ 9.3.������� ����� ��������.����� 1(5)
	void task3();
	// "���� ��� �� ����... " ����� � ���������������� ���������� ������? � ������ ������ ����������, ����� ����� ��������� �������� � ���������.
	// ������ ���������� ������ ���������� � ������ ���������� ���.
	// �������������� ��� ����� �������, ����� ���� ��� ��������� ���������� ��������� ������������� ��� �������, � ������ ���������� � ������������� ���������.
	// ��������� "������ ��������" ����� ����������������. ����� �������, ���������� �������� ������������ ������, ��������� ����������.
	
	
	// ������ 9.4. ������� ����� ��������. ����� 2(6)
	void task4();
	// � ������ ������ �� ������������� ����� ������������� ������, ������� ������� ������� ��������.
	// � ���������� ����������� PeerDirect �������� ���������:
	// - ���������� ���������� ������������ ��� T& �::operator=(const T&)
	// - �� ����������� const T&.
	// ��������� "������ ��������" ����� ����������������. ����� �������, ���������� �������� ������������ ������, ��������� ����������.
	// ��������� ��������� ������� ������� ����, ���� ���� ��� ��� ��������� ��� ���������� ����, ��� �� ��������.
	// ������ ���������� ������ ���������� � ������ ���������� ���. �������������� ��� ����� �������, ����� ���� ��� ��������� ���������� ��������� ������������� ��� �������, � ������ ���������� � ������������� ���������.
	// T& �::operator=(const T& other) 
	// {
	//	T temp(other);
	//	Swap(temp);
	//	return *this;
	// }
	// ��������������� ���������� ����� �������� - ������ Swap(), �� ������������ ����������, � ����������� ���������� ������������ ����������� ������������ ����������� ��������� �������.
}
