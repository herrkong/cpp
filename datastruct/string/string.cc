#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class String
{
public:
    String()
        : _pstr(nullptr)
    {
        cout << "String()" << endl;
    }

    String(const char *pstr)
        : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(const String &str)
        : _pstr(new char[strlen(str._pstr) + 1])
    {
        cout << "String(const String & )" << endl;
        strcpy(_pstr, str._pstr);
    }
    ~String()
    {
        cout << "~String()" << endl;
        delete[] _pstr;
    }

    String &operator=(const String &str)
    {
        cout << "String & operator=(const String & str)" << endl;
        if (this != &str)
        {
            delete[] _pstr;
            _pstr = new char[strlen(str._pstr) + 1]();
            strcpy(this->_pstr, str._pstr);
        }
        return *this;
    }

    String &operator=(const char *pstr)
    {
        cout << "String & operator=(const char * pstr)" << endl;
        if (this->_pstr != pstr)
        {
            delete[] _pstr;
            _pstr = new char[strlen(pstr) + 1]();
            strcpy(this->_pstr, pstr);
        }
        strcpy(this->_pstr, pstr);
        return *this;
    }

    String &operator+=(const String &str)
    {
        this->_pstr = strcat(this->_pstr, str._pstr);
        return *this;
    }

    String &operator+=(const char *pstr)
    {
        this->_pstr = strcat(this->_pstr, pstr);
        return *this;
    }

    char &operator[](std::size_t index)
    {
        return this->_pstr[index];
    }

    const char &operator[](std::size_t index) const
    {
        return this->_pstr[index];
    }

    std::size_t size() const
    {
        return strlen(this->_pstr);
    }
    const char *c_str() const
    {
        return (const char *)(this->_pstr);
    }

    char *getpstr() const
    {
        return _pstr;
    }

    void print() const
    {
        cout << _pstr << endl;
    }

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);

private:
    char *_pstr;
};

bool operator==(const String &str1, const String &str2)
{
    cout << "friend String operator==()" << endl;
    int ret = strcmp(str1._pstr, str2._pstr);
    if (ret == 0)
        return true;
    else
        return false;
}

bool operator!=(const String &str1, const String &str2)
{
    cout << "friend String operator!=()" << endl;
    int ret = strcmp(str1._pstr, str2._pstr);
    if (ret == 0)
        return false;
    else
        return true;
}

bool operator<(const String &str1, const String &str2)
{
    cout << "friend String operator<()" << endl;
    int ret = strcmp(str1._pstr, str2._pstr);
    if (ret < 0)
        return true;
    else
        return false;
}

bool operator>(const String &str1, const String &str2)
{
    cout << "friend String operator>()" << endl;
    int ret = strcmp(str1._pstr, str2._pstr);
    if (ret > 0)
        return true;
    else
        return false;
}

bool operator<=(const String &str1, const String &str2)
{
    cout << "friend String operator<=()" << endl;
    int ret = strcmp(str1._pstr, str2._pstr);
    if (ret > 0)
        return false;
    else
        return true;
}

bool operator>=(const String &str1, const String &str2)
{
    cout << "friend String operator>=()" << endl;
    int ret = strcmp(str1._pstr, str2._pstr);
    if (ret < 0)
        return false;
    else
        return true;
}

std::ostream &operator<<(std::ostream &os, const String &str)
{

    cout << "std::ostream & operator<<(std::ostream & ,const String &)" << endl;
    cout << str._pstr << endl;
    return os;
}
std::istream &operator>>(std::istream &cin, String &str)
{
    cout << "std::istream & operator>>(std::istream &,const String &)" << endl;
    cout << "Please input a sentence" << endl;
    char buf[128];
    cin.getline(buf, 128);
    str = buf;
    return cin;
}

//定义一些get()函数就是了。

String operator+(const String &str1, const String &str2)
{
    cout << "String operator+(const String &,const String &)" << endl;
    String tmp1 = str1.getpstr();
    String tmp2 = str2.getpstr();
    tmp1 += tmp2;
    return tmp1;
}

String operator+(const String &str1, const char *str2)
{
    cout << "String operator+(const String &,const char *)" << endl;
    String tmp1 = str1.getpstr();
    tmp1 += str2;
    return tmp1;
}

String operator+(const char *str1, const String &str2)
{
    cout << "String operator+(const char *,const char *)" << endl;
    String tmp1 = str1;
    String tmp2 = str2.getpstr();
    tmp1 += tmp2;
    return tmp1;
}

void test0()
{
    String s0 = "Fc Schalke 04";
    s0.print();
    String s1 = s0;
    s1.print();
}

void test1()
{
    String s1 = "Deutschland";
    String s2 = "Veltins";
    s1.print();
    s2.print();
    cout << "s1>s2?:" << endl
         << (s1 > s2) << endl;
    cout << "s1==s2?:" << endl
         << (s1 == s2) << endl;
    cout << "s1<s2?:" << endl
         << (s1 < s2) << endl;
    cout << "s1!=s2?:" << endl
         << (s1 != s2) << endl;
    cout << "s1<=s2?:" << endl
         << (s1 <= s2) << endl;
    cout << "s1>=s2?:" << endl
         << (s1 >= s2) << endl;
}

void test2()
{
    String s1 = "How are you?";
    String s2;
    cout << "s1=" << s1 << endl;
    std::cin >> s2;
    cout << "s2=" << s2 << endl;
}

void test3()
{
    String s1 = "Orange";
    s1.print();
    cout << "s1[4]=" << s1[4] << endl;
    cout << "s1.size()=" << s1.size() << endl;
    cout << "s1.c_str()=" << s1.c_str() << endl;
}

void test4()
{
    String s1 = "herrkong";
    String s2 = "hb";
    s1 += s2;
    s1.print();
}

void test5()
{
    String s1 = "herrkong";
    String s2 = "Bundesliga";
    cout << "s1+s2=" << s1 + s2 << endl;
    cout << "s1+shenzhen=" << s1 + "shenzhen" << endl;
    cout << "HongKong+s1"
         << "HongKong" + s1 << endl;
}

int main()
{
    // test0();
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}
