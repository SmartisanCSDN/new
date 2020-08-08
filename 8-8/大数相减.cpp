void bigint::Sub(bigint & bt, bigint& bt1, bigint& bt2)
{
	if (bt1 < bt2)
		return;
	else if (bt1 == bt2)
		bt = 0;
	else
	{
		bt.clear();
		u_char sign = 0;
		size_t index = 1;
		while (index <= bt2.size())
		{
			int value = 0;
			//减法借位的条件是次位为0又有借位或者次位减去借位小于被减数
			if (bt1[index] < sign || bt1[index] - sign < bt2[index])
			{
				value = 10 + bt1[index] - sign;
				sign = 1;
			}
			else
			{
				value = bt1[index] - sign;
				sign = 0;
			}
			bt.push_back(value - bt2[index]);
			index++;
		}
		while (index <= bt1.size())
		{
			int value = 0;
			if (bt1[index] < sign)
			{
				value = 10 + bt1[index] - sign;
				sign = 1;
			}
			else
			{
				value = bt1[index] - sign;
				sign = 0;
			}
			bt.push_back(value);
		}
		bt.adjust();
	}
}



void bigint::adjust()
{
	while ((*this)[size()] == 0)
	{
		(*this)[size()] = u_char();
		this->big.size()--;
	}
}