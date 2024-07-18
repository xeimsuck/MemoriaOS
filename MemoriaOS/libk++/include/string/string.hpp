#ifndef MOS_LIBKPP_STRING_HPP
#define MOS_LIBKPP_STRING_HP

#include <stddef.h>

class string {
public:
    string(const char* str);
    [[nodiscard]]size_t size() const noexcept;
    [[nodiscard]]size_t capacity() const noexcept;
    [[nodiscard]]const char* c_str() const noexcept;
    void push_back(char ch);
private:
    char* m_buffer= nullptr;
    size_t m_size=0;
    size_t m_capacity=0;
    void expand(size_t k);
};

#endif //MOS_LIBKPP_STRING_HP
