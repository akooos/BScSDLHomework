#ifndef OCTAHEDRON_SCENE_H
#define OCTAHEDRON_SCENE_H

#include "SDLApp/Scene.h"
#include "Utils/Utils.h"
class OctahedronScene :	public Scene
{
	GLuint id_vao; //vertex arrary object 
	GLuint id_vbo; //vertex buffer object
	//GLuint id_ib; //index buffer id;

	GLuint id_shader_program;

	GLuint loc_proj; //projekció trafó mátrix helye a GPU-ban
	GLuint loc_world; //világ trafó mátrix helye a GPU-ban
	GLuint loc_view; //nézeti trafó mátrix helye a GPU-ban

	glm::mat4  m_mat_proj;
	glm::mat4  m_mat_world;
	glm::mat4  m_mat_view;

	bool enable_rot;
protected:
	virtual void  keyboardDown(SDL_KeyboardEvent& key);
public:
	OctahedronScene();
	virtual ~OctahedronScene();
	virtual bool init() ;
	virtual void render();
	virtual void update() ;
	virtual void cleanUp() ;
	virtual void resize(int width, int height);
};

#endif