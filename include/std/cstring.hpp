#pragma once

#include <system.h>
#include <cphelper.hpp>

namespace std {
    class str {
    private:
        STRING m_data;
        size_t m_len;
    public:
        str() {
            empty();
        }
        str(STRING data) {
            m_data = data;
            m_len = strlen(data);
        }

        str *concat(str a, str b) {
            STRING neu = sprintf("%s%s", a.raw(), b.raw());
            str *newstr = new str(neu);
            return newstr;
        }

        void empty() {
            if (m_data != NULL) {
                delete m_data;
                m_data = NULL;
            }
            m_data = callocate<STRING>(1);
            m_data[0] = '\0';
            m_len = 0;
        }

        STRING raw() {
            return m_data;
        }
        size_t len() {
            return m_len;
        }
        operator STRING() { return raw(); }
        void operator=(const STRING&str) {
            puts("in here");
            m_data = str;
            m_len = strlen(str);
        }
        str &operator+=(const str &s) {
            return *(this->concat(*this, s));
        }
        str &operator+(const str &s) {
            return *this += s;
        }
    };
}