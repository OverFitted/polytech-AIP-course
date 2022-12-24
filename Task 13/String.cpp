#include "String.h"

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>

String::String() {
    pointer = new char[capacity];
    *pointer = '\0';
}

String::String(const char *str) {
    size = strlen(str);
    pointer = new char[size + 1];
    capacity = size + 1;

    for (int i = 0; i < size; ++i) {
        pointer[i] = str[i];
    }
    pointer[size] = '\0';
}

String::String(const String &str) {
    size = str.size;
    pointer = new char[size + 1];
    capacity = size + 1;

    for (int i = 0; i < size + 1; ++i) {
        pointer[i] = str.pointer[i];
    }
}

String::String(String &&str) noexcept {
    size = str.size;
    pointer = str.pointer;
    capacity = str.capacity;

    str.capacity = str.size = 0;
    str.pointer = nullptr;
}

String::~String() {
    delete[] pointer;
}

String &String::append(const char *s) {
    capacity += strlen(s), size += strlen(s);
    char *buffer = new char[capacity];

    for (int i = 0; i < capacity - strlen(s); i++) {
        buffer[i] = pointer[i];
    }

    for (int i = capacity - strlen(s); i < capacity; i++) {
        buffer[i] = s[i];
    }

    pointer = buffer;
    return *this;
}

int String::compare(const String &str) {
    return strcmp(this -> pointer, str.pointer);
}

void String::clear() {
    size = 0, capacity = size + 1;
    pointer = nullptr;
}

size_t String::get_len() const {
    return size;
}

String &String::insert(std::size_t pos, const char *str) {
    capacity += strlen(str), size += strlen(str);
    char *buffer = new char[capacity];

    int temp_idx = 0;
    for (int i = 0; i < capacity - strlen(str); i++) {
        if (i >= pos && i < pos + strlen(str)) {
            buffer[i] = str[temp_idx];
            temp_idx++;
        } else
            buffer[i] = pointer[i - temp_idx];
    }

    pointer = buffer;
    return *this;
}

size_t String::rfind(char c, size_t pos) const {
    if (pos == npos) {
        pos = capacity;
    }
    int found_idx = (int)npos;

    for (int i = (int)std::min(pos, size) - 1; i >= 0; i--) {
        if (pointer[i] == c){
            found_idx = i;
            break;
        }
    }

    return (size_t)found_idx;
}

void String::reserve(size_t new_size) {
    size = new_size;
    capacity = size + 1;
    pointer = new char[capacity];
}

String &String::operator=(const char *str) {
    size = strlen(str);
    pointer = new char[size + 1];
    capacity = size + 1;

    for (int i = 0; i < size; ++i) {
        pointer[i] = str[i];
    }

    pointer[size] = '\0';
    return *this;
}

String &String::operator=(String &&str) noexcept {
    if (&str == this) {
        return *this;
    }

    size = str.size;
    pointer = str.pointer;
    capacity = str.capacity;

    str.pointer = nullptr;
    str.capacity = str.size = 0;

    return *this;
}

std::ostream &operator<<(std::ostream &out, String &str) {
    return out << str.pointer;
}

std::istream &operator>>(std::istream &in, String &str) {
    in >> str.pointer;
    str.size = strlen(str.pointer);
    str.capacity = str.size + 1;
    return in;
}
