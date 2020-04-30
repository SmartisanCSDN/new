class Solution
{
    public:
        void replaceSpace(char *str,int length)
        {
            if(str == NULL)
                return;
            int count_k = 0, len_str = 0;
            for(int i = 0; str[i] != '\0'; i++)
            {
                len_str++;
                if(str[i] == ' ')
                    count_k++;
            }
            int len_new = len_str + count_k * 2;
            if(len_new > length)
                return;
            while(count_k-- > 0)
            {
                if(str[len_str] = ' ')
                {
                    str[len_new--] = '0';
                    str[len_new--] = '2';
                    str[len_new--] = '%';
                }
                else
                    str[len_new--] = str[len_str];
                len_str--;
                count_k--;
            }
        }
};
