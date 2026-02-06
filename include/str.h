#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstddef>
#include <cstring>
#include <algorithm>

namespace mt {

    class MyString {
        public:
            MyString(size_t count, char ch);
            explicit MyString(const char* str = "");
            MyString(const MyString &other);
            ~MyString();

            const char* c_str() const;
            size_t size() const;

            MyString& operator=(const MyString &other);
            MyString operator+(const MyString &other) const;
            char& operator[](size_t index);
            const char& operator[](size_t index) const;
        private:
            size_t m_size;
            char* m_str;
    };

    std::ostream& operator<<(std::ostream &os, const MyString &str);

}

#endif // STR_H