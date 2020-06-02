Date& operator+=(int days)
{
	if (days <= this->GetMonthDay(m_year, m_month) - m_day)
		m_day += days;
	else
	{
		days -= this->GetMonthDay(m_year, m_month) - m_day;
		if (m_month == 12)
			++m_year;
		m_month = (m_month + 1) % 13;
		if (m_month == 0)
			m_month = 1;
		m_day = 0;
		while (days > this->GetMonthDay(m_year, m_month))
		{
			days -= this->GetMonthDay(m_year, m_month);
			if (m_month == 12)
				++m_year;
			m_month = (m_month + 1) % 13;
			if (m_month == 0)
				m_month = 1;
		}
		m_day = days;
	}
	return *this;
}