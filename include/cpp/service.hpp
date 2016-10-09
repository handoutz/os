#pragma once
#define dolog(name, fmt, ...) log_service(name.raw(), fmt, __VA_ARGS__)
class Service {
public:
    std::str m_name;
    STRING name() const { return m_name.raw(); }
    Service(STRING name) : m_name(name) {

    }
    virtual void init() {}
};