/*
    Copyright 2011 Google Inc.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */


#ifndef GrGLInterface_DEFINED
#define GrGLInterface_DEFINED

#include "GrGLConfig.h"

#if !defined(GR_GL_FUNCTION_TYPE)
    #define GR_GL_FUNCTION_TYPE
#endif

////////////////////////////////////////////////////////////////////////////////

/**
 * Helpers for glGetString()
 */

void gl_version_from_string(int* major, int* minor,
                            const char* versionString);
bool has_gl_extension_from_string(const char* ext,
                                  const char* extensionString);

bool has_gl_extension(const char* ext);
void gl_version(int* major, int* minor);


////////////////////////////////////////////////////////////////////////////////

/*
 * Routines managing the global interface used to invoke OpenGL calls.
 */
struct GrGLInterface;
GR_API GrGLInterface* GrGLGetGLInterface();
GR_API void GrGLSetGLInterface(GrGLInterface* gl_interface);

/*
 * This is called when GrGLSetGLInterface() hasn't been called before creating a 
 * GrGpuGL object. It provides a default implementation. The actual implementation 
 * depends on which GrGLDefaultInterface_*.cpp has been linked. There are some 
 * platform-specific implementations provided as well as 
 * GrGLDefaultInterface_none.cpp which does nothing (effectively requiring an 
 * explicit GrGLSetGLInterface call by the host).
 */
void GrGLSetDefaultGLInterface();

typedef unsigned int GrGLenum;
typedef unsigned char GrGLboolean;
typedef unsigned int GrGLbitfield;
typedef signed char GrGLbyte;
typedef short GrGLshort;
typedef int GrGLint;
typedef int GrGLsizei;
typedef unsigned char GrGLubyte;
typedef unsigned short GrGLushort;
typedef unsigned int GrGLuint;
typedef float GrGLfloat;
typedef float GrGLclampf;
typedef double GrGLdouble;
typedef double GrGLclampd;
typedef void GrGLvoid;
typedef long GrGLintptr;
typedef long GrGLsizeiptr;

enum GrGLBinding {
    kDesktop_GrGLBinding = 0x01,
    kES1_GrGLBinding = 0x02,
    kES2_GrGLBinding = 0x04
};

extern "C" {
/*
 * The following interface exports the OpenGL entry points used by the system.
 * Use of OpenGL calls is disallowed.  All calls should be invoked through
 * the global instance of this struct, defined above.
 *
 * IMPORTANT NOTE: The OpenGL entry points exposed here include both core GL
 * functions, and extensions.  The system assumes that the address of the
 * extension pointer will be valid across contexts.
 */
struct GrGLInterface {
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLActiveTextureProc)(GrGLenum texture);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLAttachShaderProc)(GrGLuint program, GrGLuint shader);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBindAttribLocationProc)(GrGLuint program, GrGLuint index, const char* name);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBindBufferProc)(GrGLenum target, GrGLuint buffer);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBindTextureProc)(GrGLenum target, GrGLuint texture);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBlendColorProc)(GrGLclampf red, GrGLclampf green, GrGLclampf blue, GrGLclampf alpha);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBlendFuncProc)(GrGLenum sfactor, GrGLenum dfactor);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBufferDataProc)(GrGLenum target, GrGLsizeiptr size, const GrGLvoid* data, GrGLenum usage);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBufferSubDataProc)(GrGLenum target, GrGLintptr offset, GrGLsizeiptr size, const GrGLvoid* data);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLClearProc)(GrGLbitfield mask);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLClearColorProc)(GrGLclampf red, GrGLclampf green, GrGLclampf blue, GrGLclampf alpha);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLClearStencilProc)(GrGLint s);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLClientActiveTextureProc)(GrGLenum texture);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLColor4ubProc)(GrGLubyte red, GrGLubyte green, GrGLubyte blue, GrGLubyte alpha);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLColorMaskProc)(GrGLboolean red, GrGLboolean green, GrGLboolean blue, GrGLboolean alpha);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLColorPointerProc)(GrGLint size, GrGLenum type, GrGLsizei stride, const GrGLvoid* pointer);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLCompileShaderProc)(GrGLuint shader);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLCompressedTexImage2DProc)(GrGLenum target, GrGLint level, GrGLenum internalformat, GrGLsizei width, GrGLsizei height, GrGLint border, GrGLsizei imageSize, const GrGLvoid* data);
    typedef GrGLuint (GR_GL_FUNCTION_TYPE *GrGLCreateProgramProc)(void);
    typedef GrGLuint (GR_GL_FUNCTION_TYPE *GrGLCreateShaderProc)(GrGLenum type);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLCullFaceProc)(GrGLenum mode);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDeleteBuffersProc)(GrGLsizei n, const GrGLuint* buffers);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDeleteProgramProc)(GrGLuint program);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDeleteShaderProc)(GrGLuint shader);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDeleteTexturesProc)(GrGLsizei n, const GrGLuint* textures);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDepthMaskProc)(GrGLboolean flag);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDisableProc)(GrGLenum cap);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDisableClientStateProc)(GrGLenum array);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDisableVertexAttribArrayProc)(GrGLuint index);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDrawArraysProc)(GrGLenum mode, GrGLint first, GrGLsizei count);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDrawElementsProc)(GrGLenum mode, GrGLsizei count, GrGLenum type, const GrGLvoid* indices);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLEnableProc)(GrGLenum cap);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLEnableClientStateProc)(GrGLenum cap);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLEnableVertexAttribArrayProc)(GrGLuint index);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLFrontFaceProc)(GrGLenum mode);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGenBuffersProc)(GrGLsizei n, GrGLuint* buffers);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGenTexturesProc)(GrGLsizei n, GrGLuint* textures);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGetBufferParameterivProc)(GrGLenum target, GrGLenum pname, GrGLint* params);
    typedef GrGLenum (GR_GL_FUNCTION_TYPE *GrGLGetErrorProc)(void);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGetIntegervProc)(GrGLenum pname, GrGLint* params);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGetProgramInfoLogProc)(GrGLuint program, GrGLsizei bufsize, GrGLsizei* length, char* infolog);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGetProgramivProc)(GrGLuint program, GrGLenum pname, GrGLint* params);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGetShaderInfoLogProc)(GrGLuint shader, GrGLsizei bufsize, GrGLsizei* length, char* infolog);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGetShaderivProc)(GrGLuint shader, GrGLenum pname, GrGLint* params);
    typedef const GrGLubyte* (GR_GL_FUNCTION_TYPE *GrGLGetStringProc)(GrGLenum name);
    typedef GrGLint (GR_GL_FUNCTION_TYPE *GrGLGetUniformLocationProc)(GrGLuint program, const char* name);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLLineWidthProc)(GrGLfloat width);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLLinkProgramProc)(GrGLuint program);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLLoadMatrixfProc)(const GrGLfloat* m);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLMatrixModeProc)(GrGLenum mode);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLPixelStoreiProc)(GrGLenum pname, GrGLint param);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLPointSizeProc)(GrGLfloat size);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLReadPixelsProc)(GrGLint x, GrGLint y, GrGLsizei width, GrGLsizei height, GrGLenum format, GrGLenum type, GrGLvoid* pixels);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLScissorProc)(GrGLint x, GrGLint y, GrGLsizei width, GrGLsizei height);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLShadeModelProc)(GrGLenum mode);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLShaderSourceProc)(GrGLuint shader, GrGLsizei count, const char** str, const GrGLint* length);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLStencilFuncProc)(GrGLenum func, GrGLint ref, GrGLuint mask);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLStencilFuncSeparateProc)(GrGLenum face, GrGLenum func, GrGLint ref, GrGLuint mask);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLStencilMaskProc)(GrGLuint mask);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLStencilMaskSeparateProc)(GrGLenum face, GrGLuint mask);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLStencilOpProc)(GrGLenum fail, GrGLenum zfail, GrGLenum zpass);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLStencilOpSeparateProc)(GrGLenum face, GrGLenum fail, GrGLenum zfail, GrGLenum zpass);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLTexCoordPointerProc)(GrGLint size, GrGLenum type, GrGLsizei stride, const GrGLvoid* pointer);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLTexEnviProc)(GrGLenum target, GrGLenum pname, GrGLint param);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLTexImage2DProc)(GrGLenum target, GrGLint level, GrGLint internalformat, GrGLsizei width, GrGLsizei height, GrGLint border, GrGLenum format, GrGLenum type, const GrGLvoid* pixels);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLTexParameteriProc)(GrGLenum target, GrGLenum pname, GrGLint param);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLTexSubImage2DProc)(GrGLenum target, GrGLint level, GrGLint xoffset, GrGLint yoffset, GrGLsizei width, GrGLsizei height, GrGLenum format, GrGLenum type, const GrGLvoid* pixels);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLUniform1fvProc)(GrGLint location, GrGLsizei count, const GrGLfloat* v);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLUniform1iProc)(GrGLint location, GrGLint x);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLUniform4fvProc)(GrGLint location, GrGLsizei count, const GrGLfloat* v);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLUniformMatrix3fvProc)(GrGLint location, GrGLsizei count, GrGLboolean transpose, const GrGLfloat* value);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLUseProgramProc)(GrGLuint program);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLVertexAttrib4fvProc)(GrGLuint indx, const GrGLfloat* values);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLVertexAttribPointerProc)(GrGLuint indx, GrGLint size, GrGLenum type, GrGLboolean normalized, GrGLsizei stride, const GrGLvoid* ptr);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLVertexPointerProc)(GrGLint size, GrGLenum type, GrGLsizei stride, const GrGLvoid* pointer);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLViewportProc)(GrGLint x, GrGLint y, GrGLsizei width, GrGLsizei height);

    // FBO Extension Functions
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBindFramebufferProc)(GrGLenum target, GrGLuint framebuffer);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBindRenderbufferProc)(GrGLenum target, GrGLuint renderbuffer);
    typedef GrGLenum (GR_GL_FUNCTION_TYPE *GrGLCheckFramebufferStatusProc)(GrGLenum target);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDeleteFramebuffersProc)(GrGLsizei n, const GrGLuint *framebuffers);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLDeleteRenderbuffersProc)(GrGLsizei n, const GrGLuint *renderbuffers);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLFramebufferRenderbufferProc)(GrGLenum target, GrGLenum attachment, GrGLenum renderbuffertarget, GrGLuint renderbuffer);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLFramebufferTexture2DProc)(GrGLenum target, GrGLenum attachment, GrGLenum textarget, GrGLuint texture, GrGLint level);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGenFramebuffersProc)(GrGLsizei n, GrGLuint *framebuffers);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLGenRenderbuffersProc)(GrGLsizei n, GrGLuint *renderbuffers);
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLRenderbufferStorageProc)(GrGLenum target, GrGLenum internalformat, GrGLsizei width, GrGLsizei height);

    // Multisampling Extension Functions
    // same prototype for ARB_FBO, EXT_FBO, GL 3.0, & Apple ES extension
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLRenderbufferStorageMultisampleProc)(GrGLenum target, GrGLsizei samples, GrGLenum internalformat, GrGLsizei width, GrGLsizei height);
    // desktop: ext_fbo_blit, arb_fbo, gl 3.0
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLBlitFramebufferProc)(GrGLint srcX0, GrGLint srcY0, GrGLint srcX1, GrGLint srcY1, GrGLint dstX0, GrGLint dstY0, GrGLint dstX1, GrGLint dstY1, GrGLbitfield mask, GrGLenum filter);
    // apple's es extension
    typedef GrGLvoid (GR_GL_FUNCTION_TYPE *GrGLResolveMultisampleFramebufferProc)();

    // Buffer mapping (extension in ES).
    typedef GrGLvoid* (GR_GL_FUNCTION_TYPE *GrGLMapBufferProc)(GrGLenum target, GrGLenum access);
    typedef GrGLboolean (GR_GL_FUNCTION_TYPE *GrGLUnmapBufferProc)(GrGLenum target);

    // Indicator variable specifying the type of GL implementation
    // exported:  GLES{1|2} or Desktop.
    GrGLBinding fBindingsExported;

    GrGLActiveTextureProc fActiveTexture;
    GrGLAttachShaderProc fAttachShader;
    GrGLBindAttribLocationProc fBindAttribLocation;
    GrGLBindBufferProc fBindBuffer;
    GrGLBindTextureProc fBindTexture;
    GrGLBlendColorProc fBlendColor;
    GrGLBlendFuncProc fBlendFunc;
    GrGLBufferDataProc fBufferData;
    GrGLBufferSubDataProc fBufferSubData;
    GrGLClearProc fClear;
    GrGLClearColorProc fClearColor;
    GrGLClearStencilProc fClearStencil;
    GrGLClientActiveTextureProc fClientActiveTexture;
    GrGLColor4ubProc fColor4ub;
    GrGLColorMaskProc fColorMask;
    GrGLColorPointerProc fColorPointer;
    GrGLCompileShaderProc fCompileShader;
    GrGLCompressedTexImage2DProc fCompressedTexImage2D;
    GrGLCreateProgramProc fCreateProgram;
    GrGLCreateShaderProc fCreateShader;
    GrGLCullFaceProc fCullFace;
    GrGLDeleteBuffersProc fDeleteBuffers;
    GrGLDeleteProgramProc fDeleteProgram;
    GrGLDeleteShaderProc fDeleteShader;
    GrGLDeleteTexturesProc fDeleteTextures;
    GrGLDepthMaskProc fDepthMask;
    GrGLDisableProc fDisable;
    GrGLDisableClientStateProc fDisableClientState;
    GrGLDisableVertexAttribArrayProc fDisableVertexAttribArray;
    GrGLDrawArraysProc fDrawArrays;
    GrGLDrawElementsProc fDrawElements;
    GrGLEnableProc fEnable;
    GrGLEnableClientStateProc fEnableClientState;
    GrGLEnableVertexAttribArrayProc fEnableVertexAttribArray;
    GrGLFrontFaceProc fFrontFace;
    GrGLGenBuffersProc fGenBuffers;
    GrGLGenTexturesProc fGenTextures;
    GrGLGetBufferParameterivProc fGetBufferParameteriv;
    GrGLGetErrorProc fGetError;
    GrGLGetIntegervProc fGetIntegerv;
    GrGLGetProgramInfoLogProc fGetProgramInfoLog;
    GrGLGetProgramivProc fGetProgramiv;
    GrGLGetShaderInfoLogProc fGetShaderInfoLog;
    GrGLGetShaderivProc fGetShaderiv;
    GrGLGetStringProc fGetString;
    GrGLGetUniformLocationProc fGetUniformLocation;
    GrGLLineWidthProc fLineWidth;
    GrGLLinkProgramProc fLinkProgram;
    GrGLLoadMatrixfProc fLoadMatrixf;
    GrGLMatrixModeProc fMatrixMode;
    GrGLPixelStoreiProc fPixelStorei;
    GrGLPointSizeProc fPointSize;
    GrGLReadPixelsProc fReadPixels;
    GrGLScissorProc fScissor;
    GrGLShadeModelProc fShadeModel;
    GrGLShaderSourceProc fShaderSource;
    GrGLStencilFuncProc fStencilFunc;
    GrGLStencilFuncSeparateProc fStencilFuncSeparate;
    GrGLStencilMaskProc fStencilMask;
    GrGLStencilMaskSeparateProc fStencilMaskSeparate;
    GrGLStencilOpProc fStencilOp;
    GrGLStencilOpSeparateProc fStencilOpSeparate;
    GrGLTexCoordPointerProc fTexCoordPointer;
    GrGLTexEnviProc fTexEnvi;
    GrGLTexImage2DProc fTexImage2D;
    GrGLTexParameteriProc fTexParameteri;
    GrGLTexSubImage2DProc fTexSubImage2D;
    GrGLUniform1fvProc fUniform1fv;
    GrGLUniform1iProc fUniform1i;
    GrGLUniform4fvProc fUniform4fv;
    GrGLUniformMatrix3fvProc fUniformMatrix3fv;
    GrGLUseProgramProc fUseProgram;
    GrGLVertexAttrib4fvProc fVertexAttrib4fv;
    GrGLVertexAttribPointerProc fVertexAttribPointer;
    GrGLVertexPointerProc fVertexPointer;
    GrGLViewportProc fViewport;

    // FBO Extension Functions
    GrGLBindFramebufferProc fBindFramebuffer;
    GrGLBindRenderbufferProc fBindRenderbuffer;
    GrGLCheckFramebufferStatusProc fCheckFramebufferStatus;
    GrGLDeleteFramebuffersProc fDeleteFramebuffers;
    GrGLDeleteRenderbuffersProc fDeleteRenderbuffers;
    GrGLFramebufferRenderbufferProc fFramebufferRenderbuffer;
    GrGLFramebufferTexture2DProc fFramebufferTexture2D;
    GrGLGenFramebuffersProc fGenFramebuffers;
    GrGLGenRenderbuffersProc fGenRenderbuffers;
    GrGLRenderbufferStorageProc fRenderbufferStorage;

    // Multisampling Extension Functions
    // same prototype for ARB_FBO, EXT_FBO, GL 3.0, & Apple ES extension
    GrGLRenderbufferStorageMultisampleProc fRenderbufferStorageMultisample;
    // desktop: ext_fbo_blit, arb_fbo, gl 3.0
    GrGLBlitFramebufferProc fBlitFramebuffer;
    // apple's es extension
    GrGLResolveMultisampleFramebufferProc fResolveMultisampleFramebuffer;

    // Buffer mapping (extension in ES).
    GrGLMapBufferProc fMapBuffer;
    GrGLUnmapBufferProc fUnmapBuffer;

    // Code that initializes this struct using a static initializer should
    // make this the last entry in the static initializer. It can help to guard
    // against failing to initialize newly-added members of this struct.
    enum { kStaticInitEndGuard } fStaticInitEndGuard;
};

}  // extern "C"

#endif
