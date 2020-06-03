#define _CRT_SECURE_NO_WARNINGS 1


#include"Date.h"


int Date::GetMonthDay(int year, int month)
{
	static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
	int day = days[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		day += 1;
	return day;
}

Date::Date()
{
	//默认调用系统当前时间
	time_t te;
	time(&te);
	struct tm *ptm = localtime(&te);
	m_year = ptm->tm_year + 1900;
	m_month = ptm->tm_mon + 1;
	m_day = ptm->tm_mday;
}

Date::Date(int year, int days)
{
	//先构建当年1月0日的日期，然后加上天数
	m_year = year;
	m_month = 1;
	m_day = 0;
	*this += days;
}

Date::Date(const Date& date)
{
	m_year = date.m_year;
	m_month = date.m_month;
	m_day = date.m_day;
}

Date& Date::operator=(const Date& date)
{
	if (&date != this)
	{
		m_year = date.m_year;
		m_month = date.m_month;
		m_day = date.m_day;
	}
	return *this;
}


ostream& operator<<(ostream& out, const Date& date)
{
	out << date.m_year << '-' << date.m_month << '-' << date.m_day;
	return out;
}


Date& Date::operator+=(int days)
{
	if (days <= this->GetMonthDay(m_year, m_month) - m_day)
		m_day += days;
	else
	{
		days -= (this->GetMonthDay(m_year, m_month) - m_day);
		m_day = 0;
		if (m_month == 12)
		{
			m_year++;
			m_month = 1;
		}
		else
			m_month++;
		while (days > this->GetMonthDay(m_year, m_month))
		{
			days -= this->GetMonthDay(m_year, m_month);
			if (m_month == 12)
			{
				m_year++;
				m_month = 1;
			}
			else
				m_month++;
		}
		m_day = days;
	}
	return *this;
}


Date Date::operator+(int days)
{
	Date date = *this;
	date += days;
	return date;
}


Date& Date::operator-=(int days)
{
	if (days < m_day)
		m_day -= days;
	else
	{
		days -= m_day;
		m_day = 0;
		if (m_month == 1)
		{
			m_year--;
			m_month = 12;
		}
		else
			m_month--;
		while (days > GetMonthDay(m_year, m_month))
		{
			days -= GetMonthDay(m_year, m_month);
			if (m_month == 1)
			{
				m_year--;
				m_month = 12;
			}
			else
				m_month--;
		}
		m_day = GetMonthDay(m_year, m_month) - days;
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date date = *this;
	date -= day;
	return date;
}




int Date::operator-(Date& date)
{
	if (*this == date)
		return 0;
	int flag = 0;
	int count = 0;
	Date before = *this;
	Date& behind = date;
	if (*this < date)
	{
		before = date;
		behind = *this;
		flag = 1;
	}
	if (before.m_year == behind.m_year && before.m_month == behind.m_month)
		return before.m_day - behind.m_day;
	else
	{
		count = before.m_day;
		if (before.m_month == 1)
		{
			before.m_year--;
			before.m_month = 12;
		}
		else
			before.m_month--;
		while (before.m_year != behind.m_year || before.m_month != behind.m_month)
		{
			count += GetMonthDay(before.m_year, before.m_month);
			if (before.m_month == 1)
			{
				before.m_year--;
				before.m_month = 12;
			}
			else
				before.m_month--;
		}
		count += GetMonthDay(behind.m_year, behind.m_month) - behind.m_day;
	}


	if (flag == 0)
		return count;
	else
		return -count;
}


Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date date = *this;
	*this += 1;
	return date;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date date = *this;
	*this -= 1;
	return date;
}



bool Date::operator==(const Date& date) const
{
	if (m_year == date.m_year && m_month == date.m_month && m_day == date.m_day)
		return true;
	else
		return false;
}

bool Date::operator!=(const Date& date) const
{
	if (m_year != date.m_year || m_month != date.m_month || m_day != date.m_day)
		return true;
	else
		return false;
}

bool Date::operator>(const Date& date) const
{
	if (m_year > date.m_year)
		return true;
	else if (m_year == date.m_year)
	{
		if (m_month > date.m_month)
			return true;
		else if (m_month == date.m_month)
		{
			if (m_day > date.m_day)
				return true;
		}
	}
	return false;
}

bool Date::operator<(const Date& date) const
{
	if (m_year < date.m_year)
		return true;
	else if (m_year == date.m_year)
	{
		if (m_month < date.m_month)
			return true;
		else if (m_month == date.m_month)
		{
			if (m_day < date.m_day)
				return true;
		}
	}
	return false;
}


bool Date::operator>=(const Date& date) const
{
	if (*this > date || *this == date)
		return true;
	else
		return false;
}


bool Date::operator<=(const Date& date) const
{
	if (*this < date || *this == date)
		return true;
	else
		return false;
}
