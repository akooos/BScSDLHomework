#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

class SDLApplication;

class Scene
{
	friend class SDLApplication;

public:
	Scene(){};
	virtual ~Scene(){};
protected:
	virtual bool init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void keyboardDown(SDL_KeyboardEvent& key){}
	virtual void keyboardUp(SDL_KeyboardEvent& key){}
	virtual void mouseMove(SDL_MouseMotionEvent& mouse){}
	virtual void mouseDown(SDL_MouseButtonEvent& mouse){}
	virtual void mouseUp(SDL_MouseButtonEvent& mouse){}
	virtual void mouseWheel(SDL_MouseWheelEvent& wheel){}
	virtual void resize(int width, int height){}
	
};

#endif

