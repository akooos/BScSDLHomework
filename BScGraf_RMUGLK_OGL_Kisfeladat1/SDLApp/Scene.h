#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
#include <glm/gtx/transform.hpp>
#include "../Utils/Logger/Logger.h"
#include <math.h>

class SDLApplication;

class Scene
{
	bool quit;
	int  rc;
	friend class SDLApplication;

public:
	Scene():quit(false),rc(0){};
	virtual ~Scene(){};

	void close(int rc = 0){
		quit = true;
		this->rc = rc;
	}

protected:
	virtual bool init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void cleanUp() = 0;
	virtual void keyboardDown(SDL_KeyboardEvent& key){}
	virtual void keyboardUp(SDL_KeyboardEvent& key){}
	virtual void mouseMove(SDL_MouseMotionEvent& mouse){}
	virtual void mouseDown(SDL_MouseButtonEvent& mouse){}
	virtual void mouseUp(SDL_MouseButtonEvent& mouse){}
	virtual void mouseWheel(SDL_MouseWheelEvent& wheel){}
	virtual void resize(int width, int height){
		glViewport(0, 0, width, height);
	}

	bool checkShaderProgram(GLuint id_shader_program){

		GLint infoLogLength = 0, result = 0;
		glGetProgramiv(id_shader_program, GL_LINK_STATUS, &result);
		glGetProgramiv(id_shader_program, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (GL_FALSE == result){
			std::vector<char> ProgramErrorMessage(infoLogLength);
			glGetProgramInfoLog(id_shader_program, infoLogLength, NULL, &ProgramErrorMessage[0]);
			fprintf(stdout, "%s/n", &ProgramErrorMessage[0]);

			char* aSzoveg = new char[ProgramErrorMessage.size()];
			memcpy(aSzoveg, &ProgramErrorMessage[0], ProgramErrorMessage.size());

			Log->error("[Shader] Sáder Huba panasza: " + std::string(aSzoveg));
			delete aSzoveg;
			return false;
		}

		return true;
	}
};
struct Vertex
{
	glm::vec3 p;
	glm::vec3 c;
};
#endif

