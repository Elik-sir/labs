#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

//Создайте класс String с операциями +, +=, =, ==, !=, >, <, >=, <=

class String
{
private:
    size_t size = 0;
    size_t capacity = 0;
    char *data = nullptr;

public:
    String();
    String(const char *str);
    String(const char c);
    String(const std::string &str);
    String(const String &str);
    ~String();

    char *c_str();
    String **strtok(const char *delim, int &size);

    String &operator=(const String &str);
    String &operator=(const std::string &str);
    String &operator=(const char *s);
    String &operator=(const char c);

    String &operator+=(const String &str);
    String &operator+=(const std::string &str);
    String &operator+=(const char *s);
    String &operator+=(const char c);

    String &operator+=(const bool c);
    String &operator+=(const short c);
    String &operator+=(const int c);
    String &operator+=(const long long c);
    String &operator+=(const float c);
    String &operator+=(const double c);
    String &operator+=(const long double c);

    String &operator+(const String &str);
    String &operator+(const std::string &str);
    String &operator+(const char *str);
    String &operator+(const char c);

    bool operator==(const String &str);
    bool operator==(const std::string &str);
    bool operator==(const char *str);
    bool operator==(const char c);

    bool operator!=(const String &str_cmp);
    bool operator!=(const std::string &str);
    bool operator!=(const char *str);
    bool operator!=(const char c);

    bool operator>(const String &str_cmp);
    bool operator>(const std::string &str);
    bool operator>(const char *str);
    bool operator>(const char c);

    bool operator<(const String &str_cmp);
    bool operator<(const std::string &str);
    bool operator<(const char *str);
    bool operator<(const char c);

    bool operator>=(const String &str_cmp);
    bool operator>=(const std::string &str);
    bool operator>=(const char *str);
    bool operator>=(const char c);

    bool operator<=(const String &str_cmp);
    bool operator<=(const std::string &str);
    bool operator<=(const char *str);
    bool operator<=(const char c);

    friend std::ostream &operator<<(std::ostream &os, const String &str)
    {
        for (int i = 0; i < str.size; i++)
        {
            os << (str.data[i]);
        }
        return os;
    }
};

#endif