#pragma once

#include <cpp/service.hpp>

class FileService : public Service {
public:
    FileService() : Service("FileService") {}
    void init() override {
        puts("where did it go");
        dolog(m_name, "Filesystem %s", "starting");
    }
};