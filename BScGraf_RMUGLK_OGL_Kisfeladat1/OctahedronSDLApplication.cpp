#include "OctahedronSDLApplication.h"
#include "OctahedronScene.h"

OctahedronSDLApplication::OctahedronSDLApplication(int argc, char * argv[]) :SDLApplication(argc, argv), sceneOctahedron(new OctahedronScene())
{
	SETUP_DEFAULT_LOGGER;
}
OctahedronSDLApplication::~OctahedronSDLApplication()
{
	delete sceneOctahedron;
}
void OctahedronSDLApplication::initWindow(std::string &title, SDL_Rect &rect, Uint32 &sdl_window_flags){

	SDL_DisplayMode dm;

	title = APP_NAME;
	title += " - Octahedron ";

	if (SDL_GetCurrentDisplayMode(0, &dm) == 0){
		rect.h = 2 * dm.h / 3;
		rect.w = 2 * dm.w / 3;
		rect.x = (dm.w - rect.w) / 2;
		rect.y = (dm.h - rect.h) / 2;
	}

	sdl_window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
}
Scene * OctahedronSDLApplication::scene() const{
	return sceneOctahedron;
}
void OctahedronSDLApplication::initGLContextAttributes() const{

	// megjelenítés: várjuk be a vsync-et
	SDL_GL_SetSwapInterval(1);
	// beállíthatjuk azt, hogy pontosan milyen OpenGL context-et szeretnénk létrehozni - ha nem tesszük, akkor
	// automatikusan a legmagasabb elérhető verziójút kapjuk
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    //set double buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    glewExperimental = GL_TRUE; //!!! ez kell

	// állítsuk be, hogy hány biten szeretnénk tárolni a piros, zöld, kék és átlátszatlansági információkat pixelenként

    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	// duplapufferelés
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	// mélységi puffer hány bites legyen
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	// antialiasing - ha kell
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);
}
