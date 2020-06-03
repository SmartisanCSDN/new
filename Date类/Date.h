#ifndef _DATE_H_
#define _DATE_H_



#include<iostream>
#include<time.h>


using namespace std;

class Date
{
public:
	//��ȡĳ��ĳ������
	int GetMonthDay(int year, int month);


	//�޲ι��캯��
	Date();
	//�����������������
	Date(int year, int days);
	//ȫ�ι��캯��
	Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day){}


	//�������캯��
	Date(const Date& date);
	//��ֵ���������
	Date& operator=(const Date& date);


	//<<���������
	friend ostream& operator<<(ostream& out, const Date& date);


	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	//����-=����
	Date& operator-=(int day);
	//����-����
	Date operator-(int day);


	//����-����
	int operator-(Date& date);


	//ǰ��++
	Date& operator++();
	//����++
	Date operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);


	//==���������
	bool operator==(const Date& date) const;
	//��=���������
	bool operator!=(const Date& date) const;
	//>���������
	bool operator>(const Date& date) const;
	//<���������
	bool operator<(const Date& date) const;
	//>=���������
	bool operator>=(const Date& date) const;
	//<=���������
	bool operator<=(const Date& date) const;

private:
	int m_year;
	int m_month;
	int m_day;
};
ostream& operator<<(ostream& out, const Date& date);






#endif //_DATE_H_









//class Date
//{
//public:
//
//	
//	
//
//	// ����-���� ��������
//	int operator-(const Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};