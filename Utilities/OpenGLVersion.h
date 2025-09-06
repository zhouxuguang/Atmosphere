#ifndef OPENGLVERSION_H
#define OPENGLVERSION_H
#include <QOpenGLFunctions_4_1_Core>

/***************************
 * OpenGL版本
 ***************************/
namespace GlobalContext{

extern QOpenGLFunctions_4_1_Core* contextFunc;

}

inline const char* glErrorString(GLenum err) {
    switch (err) {
        case GL_NO_ERROR: return "No error";
        case GL_INVALID_ENUM: return "Invalid enum";
        case GL_INVALID_VALUE: return "Invalid value";
        case GL_INVALID_OPERATION: return "Invalid operation";
        case GL_OUT_OF_MEMORY: return "Out of memory";
        case GL_INVALID_FRAMEBUFFER_OPERATION: return "Invalid framebuffer operation";
        default: return "Unknown error";
    }
}

#define GL_CHECK() \
    do { \
        GLenum err; \
        while ((err = f->glGetError()) != GL_NO_ERROR) { \
            qDebug() << "[OpenGL] " << glErrorString(err) \
                     << " @" << __FILE__ << ":" << __LINE__; \
        } \
    } while (0)

#define GL_CALL(x) \
    do { \
        f->glGetError(); /* Clear previous errors */ \
        x; \
        GL_CHECK(); \
} while (0)

typedef QOpenGLFunctions_4_1_Core OGL_Function;

#endif // OPENGLVERSION_H
