#ifndef OCTAHEDRON_SDL_APPLICATION
#define OCTAHEDRON_SDL_APPLICATION

#include "SDLApp/SDLApplication.h"

class OctahedronScene;

class OctahedronSDLApplication : public SDLApplication
{
	OctahedronScene * sceneOctahedron;

protected:

	virtual void initGLContextAttributes() const;
	void initWindow(std::string &title, SDL_Rect &rect, Uint32 &sdl_window_flags);

public:
	OctahedronSDLApplication(int argc, char *argv[]);
	virtual ~OctahedronSDLApplication();
	Scene * scene() const;	
};

#endif

