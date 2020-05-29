
//字符串查找
char* my_strstr(const char* dst, const char* str)
{
	assert(dst != NULL && str != NULL);
	//如果子串为空，直接返回此字符串
	if (*str == '\0')
		return (char*)dst;
	while (*dst != '\0')
	{
		//如果当前字符和子串第一个字符相同，就判断
		if (*dst == *str)
		{
			//两个指针在*dst_m != '\0'时分别向后移动
			//如果两指针所指内容相同，两指针后移，否则直接退出循环。
			//如果*str_m == '\0',说明找到了子串，返回dst
			const char* dst_m = dst;
			const char* str_m = str;
			while (*dst_m != '\0')
			{
				if (*str_m == '\0')
					return (char*)dst;
				if (*dst_m != *str_m)
					break;
				dst_m++;
				str_m++;
			}
		}
		//没找到，dst后移继续找，
		dst++;
	}
	//找完了没找到，返回null；
	char* res = "(null)";
	return res;
}



//字符串截断
int find(char ch, const char* str)
{
	while (*str != '\0')
	{
		if (ch == *str)
			return 1;
		str++;
	}
	return 0;
}
char* my_strtok(char* dst, const char* str)
{
	assert(dst != NULL && str != NULL);
	//如果str是空串，直接返回dst
	if (*str == '\0')
		return dst;
	while (*dst != '\0')
	{
		//在str中能找到*dst，dst后移
		if (find(*dst, str))
			dst++;
		else
		{
			//找不到dst，记录dst，考察dst后边的字符
			char* p = dst + 1;
			//某字符在str中能找到，将此字符置0，并退出循环
			while (*p != '\0' && !find(*p, str))
				p++;
			*p = '\0';
			return dst;
		}
	}
	char* res = "(null)";
	return res;
}