#include <string/string.hpp>


string::string(const char* str){
    m_size = strlen(str);
    m_capacity = m_size*2;
    m_buffer = new char[m_size*2];
    memcpy((void*)m_buffer, (void*)str, m_size);
}
[[nodiscard]]size_t string::size() const noexcept  {
    return m_size;
}
[[nodiscard]]size_t string::capacity() const noexcept {
    return m_capacity;
}
[[nodiscard]]const char* string::c_str() const noexcept {
    return m_buffer;
}
void string:: push_back(char ch){
    if(m_size+1==m_capacity){
        expand(2);
    }
    m_buffer[m_size] = ch;
    m_buffer[m_size+1] = '\0';
    ++m_size;
}
void string::expand(size_t k){
    const char* old = m_buffer;
    m_capacity*=2;
    m_buffer = new char[m_capacity];
    memcpy((void*)m_buffer, (void*)old, m_size);
    delete old;
}
