#include "SDLApplication.h"

#include "../Utils/Logger/Logger.h"
#include <iostream>

SDLApplication::SDLApplication(int argc, char* argv[])
{		
}
Uint32 SDLApplication::initSDLFlags() const{
    return 0;
}
int SDLApplication::exec(){


	if (SDL_Init(SDL_INIT_VIDEO | initSDLFlags() ) < 0)
	{
		// irjuk ki a hibat es terminaljon a program
		Log->error("[SDL indítása]Hiba az SDL inicializálása közben: " + GetSDLErrorStr()	);
		return EXIT_FAILURE;
	}

	initGLContextAttributes();
		
	SDL_Rect rect_wnd;
	Uint32 sdl_wnd_flags = 0;
	std::string title = "";

	rect_wnd.h = 480;
	rect_wnd.w = 640;
	rect_wnd.x = 100;
	rect_wnd.y = 100;

	initWindow(title,rect_wnd,sdl_wnd_flags);

	SDL_Window *wnd = 0;

	if ( !(wnd = SDL_CreateWindow( title.c_str(), rect_wnd.x,rect_wnd.y,rect_wnd.w,rect_wnd.h, SDL_WINDOW_OPENGL | sdl_wnd_flags ) )  )
	{
		Log->error("[Ablak létrehozása]Hiba az SDL inicializálása közben: " + GetSDLErrorStr() );
		SDL_Quit();
		return EXIT_FAILURE;
	}
		
	SDL_GLContext	context = 0;
    if ( !( context = SDL_GL_CreateContext(wnd) ) )
	{
		Log->error("[OGL context létrehozása]Hiba az SDL inicializálása közben: " + GetSDLErrorStr() );
		SDL_DestroyWindow(wnd);
		SDL_Quit();
		return EXIT_FAILURE;
	}

	// indítsuk el a GLEW-t
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		Log->error("[GLEW] Hiba az inicializálás során!");
		SDL_DestroyWindow(wnd);
		SDL_Quit();
		return EXIT_FAILURE;
	}

	int major;
	int minor;

	GetOpenGLVersion(major, minor);


    std::cout << "gl_renderer:" << glGetString(GL_RENDERER) << std::endl;
    std::cout << "gl_context: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "gl_shading_lang_version: "<< glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	
	if (major == -1 && minor == -1)
	{
		Log->error("[OGL context létrehozása] Nem sikerült létrehozni az OpenGL context-et! Lehet, hogy az SDL_GL_SetAttribute(...) hívásoknál az egyik beállítás helytelen.");
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(wnd);
		SDL_Quit();
		return EXIT_FAILURE;
	}	
	
	// feldolgozandó üzenet ide kerül
	SDL_Event ev;
	// alkalmazas példánya
	Scene *scene = this->scene();
	// véget kell-e érjen a program futása?
	scene->quit = false;
	if (!scene->init())
	{
		Log->error("[app.Init] Az alkalmazás inicializálása közben hibatörtént!");
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(wnd);
		SDL_Quit();		
		return EXIT_FAILURE;
	}

	scene->resize(rect_wnd.w, rect_wnd.h);

	while (!scene->quit)
	{
		// amíg van feldolgozandó üzenet dolgozzuk fel mindet:
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				scene->close();
				break;
			case SDL_KEYDOWN:							
				scene->keyboardDown(ev.key);
				break;
			case SDL_KEYUP:
				scene->keyboardUp(ev.key);
				break;
			case SDL_MOUSEBUTTONDOWN:
				scene->mouseDown(ev.button);
				break;
			case SDL_MOUSEBUTTONUP:
				scene->mouseUp(ev.button);
				break;
			case SDL_MOUSEWHEEL:
				scene->mouseWheel(ev.wheel);
				break;
			case SDL_MOUSEMOTION:
				scene->mouseMove(ev.motion);
				break;
			case SDL_WINDOWEVENT:
				if (ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)				
					scene->resize(ev.window.data1, ev.window.data2);				
				break;
			}
		}

		scene->update();
		scene->render();

		SDL_GL_SwapWindow(wnd);
	}

	scene->cleanUp();

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(wnd);
	SDL_Quit();

	return scene->rc;
}

void SDLApplication::initGLContextAttributes() const{
	// beállíthatjuk azt, hogy pontosan milyen OpenGL context-et szeretnénk létrehozni - ha nem tesszük, akkor
	// automatikusan a legmagasabb elérhető verziójút kapjuk
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// állítsuk be, hogy hány biten szeretnénk tárolni a piros, zöld, kék és átlátszatlansági információkat pixelenként
	/*
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	// duplapufferelés
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	// mélységi puffer hány bites legyen
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	*/

	// antialiasing - ha kell
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);
}

SDLApplication::~SDLApplication()
{
}
