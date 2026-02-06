#include "str.h"

namespace mt {
    
    MyString::MyString(size_t count, char ch) : 
        m_size(count), 
        m_str(new char[m_size + 1]{'\0'}) 
    {
        std::fill(m_str, m_str + m_size, ch);
    }

    MyString::MyString(const char* str) : 
        m_size(str != nullptr ? strlen(str) : 0), 
        m_str(new char[m_size + 1]{'\0'}) 
    {
        std::copy(str, str + m_size, m_str);
    }

    MyString::MyString(const MyString &other) : MyString(other.m_str) {}

    MyString::~MyString() {
        delete[] m_str;
    }

    const char* MyString::c_str() const { return m_str; }
    size_t MyString::size() const { return m_size; }

    MyString& MyString::operator=(const MyString &other) {
        if(this != &other) {
            MyString tmp = other;
            std::swap(tmp.m_size, m_size);
            std::swap(tmp.m_str, m_str);
        }
        return *this;
    }

    MyString MyString::operator+(const MyString &other) const {
        MyString result(m_size + other.m_size, '\0');
        std::copy(m_str, m_str + m_size, result.m_str);
        std::copy(other.m_str, other.m_str + other.m_size, result.m_str + m_size);

        return result;
    }

    char& MyString::operator[](const size_t index) {
        return const_cast<char&>(
            static_cast<const MyString&>(*this)[index]
        );
    }

    const char& MyString::operator[](const size_t index) const {
        if(m_size <= index) {
            throw std::range_error("Index out of range");
        }

        return m_str[index];
    }

    std::ostream& operator<<(std::ostream &os, const MyString &str) {
        return os << str.c_str();
    }

}