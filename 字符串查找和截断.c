
//�ַ�������
char* my_strstr(const char* dst, const char* str)
{
	assert(dst != NULL && str != NULL);
	//����Ӵ�Ϊ�գ�ֱ�ӷ��ش��ַ���
	if (*str == '\0')
		return (char*)dst;
	while (*dst != '\0')
	{
		//�����ǰ�ַ����Ӵ���һ���ַ���ͬ�����ж�
		if (*dst == *str)
		{
			//����ָ����*dst_m != '\0'ʱ�ֱ�����ƶ�
			//�����ָ����ָ������ͬ����ָ����ƣ�����ֱ���˳�ѭ����
			//���*str_m == '\0',˵���ҵ����Ӵ�������dst
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
		//û�ҵ���dst���Ƽ����ң�
		dst++;
	}
	//������û�ҵ�������null��
	char* res = "(null)";
	return res;
}



//�ַ����ض�
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
	//���str�ǿմ���ֱ�ӷ���dst
	if (*str == '\0')
		return dst;
	while (*dst != '\0')
	{
		//��str�����ҵ�*dst��dst����
		if (find(*dst, str))
			dst++;
		else
		{
			//�Ҳ���dst����¼dst������dst��ߵ��ַ�
			char* p = dst + 1;
			//ĳ�ַ���str�����ҵ��������ַ���0�����˳�ѭ��
			while (*p != '\0' && !find(*p, str))
				p++;
			*p = '\0';
			return dst;
		}
	}
	char* res = "(null)";
	return res;
}