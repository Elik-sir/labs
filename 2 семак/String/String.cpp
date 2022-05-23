#include "String.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

//+, +=, =, ==, !=, >, <, >=, <=.

using namespace std;

String::String() : String("")
{
}
String::String(const char *str)
{
    this->size = strlen(str);
    capacity = size + 1;
    data = new char[capacity];
    strcpy(data, str);
}

String::String(const char c)
{
    this->size = 1;
    capacity = size + 1;
    data = new char[capacity];
    data[0] = c;
    data[1] = '\0';
}

String::String(const string &str) : String(str.c_str())
{
}

String::String(const String &str) : String(str.data)
{
}

String::~String()
{
    delete[] data;
}

char *String::c_str()
{
    return data;
}

String **String::strtok(const char *delim, int &size)
{
    String **tokens = new String *[1000];
    char *datacp = new char[this->size + 1];

    strcpy(datacp, data);

    size = 0;

    char *str = std::strtok(datacp, delim);

    while (str != nullptr)
    {
        tokens[size++] = new String(str);
        str = std::strtok(nullptr, delim);
    }
    return tokens;
}

String &String::operator=(const String &str)
{
    if (this == &str)
    {
        return *this;
    }
    return operator=(str.data);
}

String &String::operator=(const string &str)
{
    return operator=(str.c_str());
}

String &String::operator=(const char *s)
{
    size_t len = strlen(s) + 1;

    if (capacity < len)
    {
        delete[] data;
        data = new char[len];
        capacity = len;
        size = len - 1;
    }

    strcpy(data, (char *)s);

    return *this;
}

String &String::operator=(const char c)
{
    return operator=({c, '\0'});
}

String &String::operator+=(const String &str)
{
    return operator+=(str.data);
}

String &String::operator+=(const string &str)
{
    return operator+=(str.c_str());
}

String &String::operator+=(const char *s)
{
    size_t len = strlen(s);

    if (capacity < size + 1 + len)
    {
        capacity = size + len + 1;
        char *tmp = new char[capacity];
        strcpy(tmp, data);
        delete[] data;
        data = tmp;
    }

    strcpy(data + size, s);

    size += len;

    return *this;
}

String &String::operator+=(const char c)
{
    return operator+=({c, '\0'});
}

String &String::operator+=(const bool c)
{
    char *buf = new char[6];
    sprintf(buf, "%s", c ? "true" : "false");
    operator+=(buf);
    delete[] buf;
    return *this;
}

String &String::operator+=(const short c)
{
    char *buf = new char[10];
    sprintf(buf, "%d", c);
    operator+=(buf);
    delete[] buf;
    return *this;
}

String &String::operator+=(const int c)
{
    char *buf = new char[12];
    sprintf(buf, "%d", c);
    operator+=(buf);
    delete[] buf;
    return *this;
}

String &String::operator+=(const long long c)
{
    char *buf = new char[21];
    sprintf(buf, "%lld", c);
    operator+=(buf);
    delete[] buf;
    return *this;
}

String &String::operator+=(const float c)
{
    char *buf = new char[50];
    sprintf(buf, "%f", c);
    operator+=(buf);
    delete[] buf;
    return *this;
}

String &String::operator+=(const double c)
{
    char *buf = new char[350];
    sprintf(buf, "%lf", c);
    operator+=(buf);
    delete[] buf;
    return *this;
}

String &String::operator+=(const long double c)
{
    char *buf = new char[5000];
    sprintf(buf, "%lf", c);
    operator+=(buf);
    delete[] buf;
    return *this;
}

String &String::operator+(const String &str)
{
    return operator+(str.data);
}

String &String::operator+(const string &str)
{
    return operator+(str.c_str());
}

String &String::operator+(const char *str)
{
    String *temp = new String(data);
    *temp += str;
    return *temp;
}

String &String::operator+(const char c)
{
    return operator+({c, '\0'});
}

bool String::operator==(const String &str)
{
    if (this == &str)
    {
        return true;
    }
    return operator==(str.data);
}

bool String::operator==(const string &str)
{
    return operator==(str.c_str());
}

bool String::operator==(const char *str)
{
    return strcmp(data, str) == 0;
}

bool String::operator==(const char c)
{
    return operator==({c, '\0'});
}

bool String::operator!=(const String &str_cmp)
{
    return !operator==(str_cmp);
}

bool String::operator!=(const string &str)
{
    return !operator==(str);
}

bool String::operator!=(const char *str)
{
    return !operator==(str);
}

bool String::operator!=(const char c)
{
    return !operator==(c);
}

bool String::operator>(const String &str_cmp)
{
    if (this == &str_cmp)
    {
        return false;
    }
    return operator>(str_cmp.data);
}

bool String::operator>(const string &str)
{
    return operator>(str.c_str());
}

bool String::operator>(const char *str)
{
    return strcmp(data, str) > 0;
}

bool String::operator>(const char c)
{
    return operator>({c, '\0'});
}

bool String::operator<(const String &str_cmp)
{
    if (this == &str_cmp)
    {
        return false;
    }
    return operator<(str_cmp.data);
}

bool String::operator<(const string &str)
{
    return operator<(str.c_str());
}

bool String::operator<(const char *str)
{
    return strcmp(data, str) < 0;
}

bool String::operator<(const char c)
{
    return operator<({c, '\0'});
}

bool String::operator>=(const String &str_cmp)
{
    if (this == &str_cmp)
    {
        return true;
    }
    return operator>=(str_cmp.data);
}

bool String::operator>=(const string &str)
{
    return operator>=(str.c_str());
}

bool String::operator>=(const char *str)
{
    return !operator<(str);
}

bool String::operator>=(const char c)
{
    return operator>=({c, '\0'});
}

bool String::operator<=(const String &str_cmp)
{
    if (this == &str_cmp)
    {
        return true;
    }
    return operator<=(str_cmp.data);
}

bool String::operator<=(const string &str)
{
    return operator<=(str.c_str());
}

bool String::operator<=(const char *str)
{
    return !operator>(str);
}

bool String::operator<=(const char c)
{
    return operator<=({c, '\0'});
}