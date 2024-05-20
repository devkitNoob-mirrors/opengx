find_path(_OPENGL_gl_gl_INCLUDE_DIR NAMES GL/gl.h)
find_path(_OPENGL_gl_egl_INCLUDE_DIR NAMES EGL/egl.h)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OpenGL
	REQUIRED_VARS _OPENGL_gl_gl_INCLUDE_DIR
)

include(FindPkgConfig)
pkg_check_modules(GLU glu)

set(_OPENGL_glapi_LIBRARY "opengx")
set(OPENGL_FOUND ${OpenGL_FOUND})
set(OPENGL_XMESA_FOUND OFF)
set(OPENGL_GLU_FOUND ${GLU_FOUND})
set(OPENGL_OpenGL_FOUND ${OpenGL_FOUND})
set(OpenGL_GLX_FOUND OFF)
set(OpenGL_EGL_FOUND ${OpenGL_FOUND})
set(OPENGL_INCLUDE_DIR ${_OPENGL_gl_gl_INCLUDE_DIR})
set(OPENGL_EGL_INCLUDE_DIRS ${_OPENGL_gl_egl_INCLUDE_DIR})
set(OPENGL_LIBRARIES ${OPENGL_egl_LIBRARY} ${_OPENGL_glapi_LIBRARY})

set(OPENGL_LIBRARY ${OPENGL_LIBRARIES})
set(OPENGL_INCLUDE_PATH ${OPENGL_INCLUDE_DIR})

if(OpenGL_FOUND)
	if(NOT TARGET OpenGL::EGL)
		add_library(OpenGL::EGL INTERFACE IMPORTED)
		set_target_properties(OpenGL::EGL PROPERTIES
			INTERFACE_INCLUDE_DIRECTORIES "${_OPENGL_gl_egl_INCLUDE_DIR}"
			INTERFACE_LINK_LIBRARIES "${OPENGL_egl_LIBRARY};${_OPENGL_glapi_LIBRARY}"
		)
	endif()

	if(NOT TARGET OpenGL::GL)
		add_library(OpenGL::GL INTERFACE IMPORTED)
		set_target_properties(OpenGL::GL PROPERTIES
			INTERFACE_INCLUDE_DIRECTORIES "${_OPENGL_gl_gl_INCLUDE_DIR}"
			INTERFACE_LINK_LIBRARIES "${GLU_LIBRARIES};${OPENGL_egl_LIBRARY};${_OPENGL_glapi_LIBRARY}"
		)
	endif()
endif()
