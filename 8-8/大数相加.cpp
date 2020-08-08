void bigint::Add(bigint & bt, bigint& bt1, bigint& bt2)
{
	size_t index = 1;
	u_char pro = 0;
	bt.clear();
	while (index <= bt1.size() && index <= bt2.size())
	{
		pro += bt1[index] + bt2[index];
		bt.push_back(pro % 10);
		pro /= 10;
		++index;
	}
	while (index <= bt1.size())
	{
		pro += bt1[index];
		bt.push_back(pro % 10);
		pro /= 10;
		++index;
	}
	while (index <= bt2.size())
	{
		pro += bt2[index];
		bt.push_back(pro % 10);
		pro /= 10;
		++index;
	}
	if (pro != 0)
		bt.push_back(pro);
}
