#pragma once

#include <cstddef>
#include <iostream>

class String {
    static const size_t npos = -1;

   public:
    String();
    String(const char* str);
    String(const String& str);
    String(String&& str) noexcept;
    ~String();

    String& append(const char* s);
    int compare(const String& str);
    void clear();
    size_t get_len() const;
    String& insert(std::size_t pos, const char* str);
    size_t rfind(char c, size_t pos = npos) const;
    void reserve(size_t new_size);

    String& operator=(const char* str);
    String& operator=(String&& str) noexcept;
    char& operator[](std::size_t pos);

    friend std::ostream& operator<<(std::ostream& out, String& str);
    friend std::istream& operator>>(std::istream& in, String& str);

   private:
    size_t size = 0, capacity = size + 1;
    char* pointer = nullptr;
};