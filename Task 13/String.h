#pragma once

#include <cstddef>

class String {
   public:
    String();
    String(const char* str);
    String(const String& str);
    String(String&& str) noexcept;
    ~String();

    String& append (const char* s);
    int compare(const String& str);
    void clear();
    String& insert(std::size_t pos, const char* str);
    size_t rfind (char c, size_t pos) const;

    String& operator=(const char* str);
    String& operator=(String&& str) noexcept;
    char& operator[](std::size_t pos);

   private:
    size_t size;
    size_t capacity;
    char* pointer;
    char* storage;
};