#ifndef SDLAPPLICATION_H
#define SDLAPPLICATION_H

#include <string>

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include "Scene.h"

class SDLApplication
{	
protected:
	virtual Uint32   initSDLFlags() const;
	virtual void  initGLContextAttributes() const;		
	virtual Scene * scene() const = 0;	
	virtual void  initWindow(std::string &title, SDL_Rect &rect, Uint32 &sdl_window_flags) = 0;
public:
	SDLApplication(int argc, char * argv[]);
	virtual ~SDLApplication();		
	int exec();		
};

inline static std::string GetSDLErrorStr() {
	return std::string(SDL_GetError());
}
inline static void GetOpenGLVersion(int &major, int &minor){
	major = -1;
	minor = -1;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
}

#endif
