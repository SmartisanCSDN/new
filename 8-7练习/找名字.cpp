struct pa
{
	string names;
	string name;
};

int main()
{
	vector<pa> values;
	pa temp;
	while (1)
	{
		getline(cin, temp.names);
		if (temp.names[0] == '0')
			break;
		getline(cin, temp.name);
		values.push_back(temp);
	}
	auto it = values.begin();
	while (it != values.end())
	{
		auto it_names = it->names.begin();
		int flag = 0;
		while (it_names != it->names.end())
		{
			string str;
			if (*it_names == '\"')
			{
				++it_names;
				while (*it_names != '\"')
				{
					str += *it_names;
					++it_names;
				}
				++it_names;
			}
			else
			{
				while (it_names != it->names.end() && *it_names != ',')
				{
					str += *it_names;
					++it_names;
				}
			}
			if (str == it->name)
			{
				cout << "Ignore" << endl;
				flag = 1;
				break;
			}
			if (it_names != it->names.end())
				++it_names;
		}
		if (flag == 0)
			cout << "Important!" << endl;
		++it;
	}
	return 0;
}
