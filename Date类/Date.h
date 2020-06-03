#ifndef _DATE_H_
#define _DATE_H_



#include<iostream>
#include<time.h>


using namespace std;

class Date
{
public:
	//获取某年某月天数
	int GetMonthDay(int year, int month);


	//无参构造函数
	Date();
	//以年和天数构造日期
	Date(int year, int days);
	//全参构造函数
	Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day){}


	//拷贝构造函数
	Date(const Date& date);
	//赋值运算符重载
	Date& operator=(const Date& date);


	//<<运算符重载
	friend ostream& operator<<(ostream& out, const Date& date);


	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	//日期-=天数
	Date& operator-=(int day);
	//日期-天数
	Date operator-(int day);


	//日期-日期
	int operator-(Date& date);


	//前置++
	Date& operator++();
	//后置++
	Date operator++(int);
	//前置--
	Date& operator--();
	//后置--
	Date operator--(int);


	//==运算符重载
	bool operator==(const Date& date) const;
	//！=运算符重载
	bool operator!=(const Date& date) const;
	//>运算符重载
	bool operator>(const Date& date) const;
	//<运算符重载
	bool operator<(const Date& date) const;
	//>=运算符重载
	bool operator>=(const Date& date) const;
	//<=运算符重载
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
//	// 日期-日期 返回天数
//	int operator-(const Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};