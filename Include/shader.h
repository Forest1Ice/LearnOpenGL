#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Shader
{
public:
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char * vertexPath, const char * fragmentPath);

    // activate the shader
    // ------------------------------------------------------------------------
    void use();

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string & name, bool value) const;
    void setInt(const std::string & name, int value) const;
    void setFloat(const std::string & name, float value) const;

    // access the program ID
    inline unsigned int getID() const
    {
        return m_ID;
    }

private:
    // program ID
    unsigned int m_ID;

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif