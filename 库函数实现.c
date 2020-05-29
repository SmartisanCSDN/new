//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}

//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* p = str;
//	while (*p != '\0')
//		p++;
//	return p - str;
//}





//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL && src != NULL);
//	char* p = dest;
//	while (*src != '\0')
//	{
//		*p = *src;
//		p++;
//		src++;
//	}
//	*p = '\0';
//	return dest;
//}



//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest != NULL && src != NULL);
//	char* p = dest;
//	while (*p != '\0')
//		p++;
//	while (*src != '\0')
//	{
//		*p = *src;
//		p++;
//		src++;
//	}
//	*p = '\0';
//	return dest;
//}


//int my_strcmp(const char* src, const char* dst)
//{
//	assert(src != NULL && dst != NULL);
//
//	while (*src != '\0' || *dst != '\0')
//	{
//		if (*src - *dst > 0)
//			return 1;
//		else if (*src - *dst < 0)
//			return -1;
//		else
//		{
//			src++;
//			dst++;
//		}
//	}
//	return 0;
//
//	/*while (*src != '\0' && *dst != '\0')
//	{
//		if (*src > *dst)
//			return 1;
//		if (*src < *dst)
//			return -1;
//		src++;
//		dst++;
//	}
//	if (*src != '\0')
//		return 1;
//	else if (*dst != '\0')
//		return -1;
//	else
//		return 0;*/
//}



//void* my_memcpy(void* dst, const void* src, size_t count)
//{
//	assert(dst != NULL && src != NULL);
//	void* p = dst;
//	while (count > 0)
//	{
//		*(char*)p = *(char*)src;
//		((char*)p)++;
//		((char*)src)++;
//		count--;
//	}
//	return dst;
//}


void* my_memmove(void* dst, const void* src, size_t count)
{
	assert(dst != NULL && src != NULL);
	void* p = dst;
	//如果copy而不被覆盖，就直接copy
	if (dst < src || (char*)dst >= (char*)src + count)
	{
		while (count > 0)
		{
			*(char*)p = *(char*)src;
			((char*)p)++;
			((char*)src)++;
			count--;
		}
	}
	//改变方向，从后往前拷贝
	else
	{
		(char*)src += count - 1;
		(char*)p += count - 1;
		while (count > 0)
		{
			*(char*)p = *(char*)src;
			((char*)p)--;
			((char*)src)--;
			count--;
		}
	}
	return dst;
}




int main()
{
	char str1[15] = "abcdefg";
	char str2[] = "hello";
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9, 0 };
	my_memmove(a, b, sizeof(int)* 3);
	for (int i = 0; i < 5; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}