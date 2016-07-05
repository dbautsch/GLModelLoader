#pragma once

#include <string>

class GLModel {
public:
    GLModel();

    ~GLModel();

    void Load(const std::string & fileName);
};
