#include "RawShaderProgram.h"
#include <QDebug>
#include <iostream>

#define F(c) c *f = (GlobalContext::contextFunc)

RawShaderProgram::RawShaderProgram(std::vector<GLuint> shaders){
    F(OGL_Function);
    id = f->glCreateProgram();
    GL_CHECK();
    for(auto it = shaders.begin();it != shaders.end();++it)
    {
        f->glAttachShader(id,*it);
        GL_CHECK();
    }
    f->glLinkProgram(id);
    GL_CHECK();
    char infoLog[1024];
    int success;
    f->glGetProgramiv(id, GL_LINK_STATUS, &success);
    GL_CHECK();
    if(!success){
        f->glGetProgramInfoLog(id, 1024, nullptr, infoLog);
        GL_CHECK();
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    for(auto it = shaders.begin();it != shaders.end();++it)
    {
        //f->glDetachShader(id,*it);
        GL_CHECK();
    }
}

RawShaderProgram::~RawShaderProgram(){
    F(OGL_Function);
    f->glDeleteProgram(id);
    GL_CHECK();
}

void RawShaderProgram::use() const{
    F(OGL_Function);
    f->glUseProgram(id);
    GL_CHECK();
}

void RawShaderProgram::release() const{
    F(OGL_Function);
    f->glUseProgram(0);
    GL_CHECK();
}

GLuint RawShaderProgram::programId(){
    return this->id;
}

void RawShaderProgram::setInt(const QString &param, int value){
    F(OGL_Function);
    int location = f->glGetUniformLocation(id, param.toStdString().c_str());
    GL_CHECK();
    if(location == -1){
        qDebug() << param << "->INVALID UNIFORM";
    }
    f->glUniform1i(location,value);
}

void RawShaderProgram::setFloat(const QString &param, float value){
    F(OGL_Function);
    int location = f->glGetUniformLocation(id, param.toStdString().c_str());
    GL_CHECK();
    if(location == -1){
        qDebug() << param << "->INVALID UNIFORM";
    }
    f->glUniform1f(location,value);
    GL_CHECK();
}

void RawShaderProgram::setVector2(const QString &param, QVector2D value){
    F(OGL_Function);
    int location = f->glGetUniformLocation(id, param.toStdString().c_str());
    GL_CHECK();
    if(location == -1){
        qDebug() << param << "->INVALID UNIFORM";
    }
    f->glUniform2f(location,value.x(), value.y());
    GL_CHECK();
}

void RawShaderProgram::setVector3(const QString &param, QVector3D value){
    F(OGL_Function);
    int location = f->glGetUniformLocation(id, param.toStdString().c_str());
    GL_CHECK();
    if(location == -1){
        qDebug() << param << "->INVALID UNIFORM";
    }
    f->glUniform3f(location,value.x(), value.y(), value.z());
    GL_CHECK();
}

void RawShaderProgram::setVector4(const QString &param, QVector4D value){
    F(OGL_Function);
    int location = f->glGetUniformLocation(id, param.toStdString().c_str());
    GL_CHECK();
    if(location == -1){
        qDebug() << param << "->INVALID UNIFORM";
    }
    f->glUniform4f(location,value.x(), value.y(), value.z(), value.w());
    GL_CHECK();
}

void RawShaderProgram::setMatrix4(const QString &param, QMatrix4x4 value){
    F(OGL_Function);
    int location = f->glGetUniformLocation(id, param.toStdString().c_str());
    GL_CHECK();
    if(location == -1){
        qDebug() << param << "->INVALID UNIFORM";
    }
    float *target = value.data();
    f->glUniformMatrix4fv(location,1,true,target);
    GL_CHECK();
}

void RawShaderProgram::link()
{
    F(OGL_Function);
    f->glLinkProgram(id);
    GL_CHECK();
    char infoLog[1024];
    int success;
    f->glGetProgramiv(id, GL_LINK_STATUS, &success);
    GL_CHECK();
    if(!success){
        f->glGetProgramInfoLog(id, 1024, nullptr, infoLog);
        GL_CHECK();
        std::cout << "RawShaderProgram::link ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}
