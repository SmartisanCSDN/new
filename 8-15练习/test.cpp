#include<iostream>
#include<vector>
#include<stack>


using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        string rstr;
        auto it = str.begin();
        while (it != str.end())
        {
            if (*it >= '0' && *it <= '9')
                rstr += *it;
            ++it;

        }
        cout << rstr << endl;

    }
    return 0;

}

int main()
{
    int n = 0;
    while (std::cin >> n)
    {
        if (n == 0)
            break;
        std::stack<char> sk;
        char ch;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> ch;
            int a = 0, b = 0;
            if (ch >= '0' && ch <= '9')
                sk.push(ch);
            else
            {
                b = sk.top() - '0';
                sk.pop();
                a = sk.top() - '0';
                sk.pop();
                switch (ch)
                {
                    case '+': a += b; break;
                    case '-': a -= b; break;
                    case '*': a *= b; break;
                    case '/': a /= b; break;

                }
                sk.push(a + '0');

            }

        }
        std::cout << (sk.top() - '0') << std::endl;

    }
    return 0;

}



//#include<iostream>
////#include<vector>
////#include<string>
////#include<stack>
////
////int main()
////{
////    int n = 0;
////    std::vector<std::string> value;
////    while (std::cin >> n)
////    {
////        if (n == 0)
////            break;
////        std::string str;
////        char ch;
////        for (int i = 1; i <= n; i++)
////        {
////            std::cin >> ch;
////            str += ch;
////        }
////        value.push_back(str);
////    }
////    auto it_v = value.begin();
////    while (it_v != value.end())
////    {
////        std::stack<char> sk;
////        int a = 0, b = 0;
////        auto it = (*it_v).begin();
////        while (it != (*it_v).end())
////        {
////            if (*it >= '0' && *it <= '9')
////                sk.push(*it);
////            else
////            {
////                b = sk.top() - '0';
////                sk.pop();
////                a = sk.top() - '0';
////                sk.pop();
////                switch (*it)
////                {
////                case '+': a += b; break;
////                case '-': a -= b; break;
////                case '*': a *= b; break;
////                case '/': a /= b; break;
////                }
////                sk.push(a + '0');
////            }
////            ++it;
////        }
////        std::cout << sk.top() - '0' << std::endl;
////        ++it_v;
////    }
////    return 0;
////}
//}
//}
//}
//}
//}
//}
//}
