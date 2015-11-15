#include "OctahedronScene.h"
#include "GLUtils.hpp"

static float GyokKetto = 1.414213f;
OctahedronScene::OctahedronScene()
{
	id_shader_program = 0;
	id_vao = 0;
	id_vbo = 0;
	enable_rot = false;
}


OctahedronScene::~OctahedronScene()
{
}

bool OctahedronScene::init(){
		
	// törlési szín legyen kékes
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_CULL_FACE); // kapcsoljuk be a hatrafele nezo lapok eldobasat
	glEnable(GL_DEPTH_TEST); // mélységi teszt bekapcsolása (takarás)
	glCullFace(GL_BACK); // GL_BACK: a kamerától "elfelé" néző lapok, GL_FRONT: a kamera felé néző lapok
	
	
	//glPolygonMode(GL_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT, GL_LINE);
	/*
	// indexpuffer adatai
	GLushort indices[] =
	{
		// 1. háromszög
		0, 1, 2,
		// 2. háromszög
		2, 1, 3,
		0,2,4,
		2,3,4,
		0,4,5,
		5,4,3,
		0,5,1,
		1,5,3

	};

	Vertex vert[] =
	{
		
		//          x,  y, z             R, G, B
		{ glm::vec3(0, 1, 0), glm::vec3(1, 0, 0) },
		{ glm::vec3(-1, 0, 1), glm::vec3(0, 0, 0) },
		{ glm::vec3(1, 0, 1), glm::vec3(0, 0, 0) },

		
		{ glm::vec3(0, -1, 0), glm::vec3(0, 1, 0) },
		{ glm::vec3(1, 0, -1), glm::vec3(0, 0, 0) },
		{ glm::vec3(-1, 0, -1), glm::vec3(0, 0, 0) },
	};
	*/

	Vertex vert[] = {
		{ glm::vec3(0, GyokKetto, 0), glm::vec3(1, 0, 0) },
		{ glm::vec3(-1, 0, 1), glm::vec3(1, 0, 0) },
		{ glm::vec3(1, 0, 1), glm::vec3(1, 0, 0) },

		{ glm::vec3(-1, 0, 1), glm::vec3(0, 1, 0) },
		{ glm::vec3(0, -GyokKetto, 0), glm::vec3(0, 1, 0) },
		{ glm::vec3(1, 0, 1), glm::vec3(0, 1, 0) },
		
		{ glm::vec3(0, GyokKetto, 0), glm::vec3(0, 0, 1) },
		{ glm::vec3(1, 0, 1), glm::vec3(0, 0, 1) },
		{ glm::vec3(1, 0, -1), glm::vec3(0, 0, 1) },

		{ glm::vec3(1, 0, -1), glm::vec3(0.2, 0.05, 0.4 ) },
		{ glm::vec3(1, 0, 1), glm::vec3(0.2, 0.05, 0.4) },
		{ glm::vec3(0, -GyokKetto, 0), glm::vec3(0.2, 0.05, 0.4) },
				
		{ glm::vec3(-1, 0, -1), glm::vec3(0.3,0.6, 0) },
		{ glm::vec3(0, GyokKetto, 0), glm::vec3(0.3, 0.6, 0) },
		{ glm::vec3(1, 0, -1), glm::vec3(0.3, 0.6, 0) },

		{ glm::vec3(0, -GyokKetto, 0), glm::vec3(0.25, 0.5, 0.4) },
		{ glm::vec3(-1, 0, -1), glm::vec3(0.25, 0.5, 0.4) },
		{ glm::vec3(1, 0, -1), glm::vec3(0.25, 0.5, 0.4) },

		{ glm::vec3(0, GyokKetto, 0), glm::vec3(0.15, 0.5, 0.7) },
		{ glm::vec3(-1, 0, -1), glm::vec3(0.15, 0.5, 0.7) },
		{ glm::vec3(-1, 0, 1), glm::vec3(0.15, 0.5 ,0.7) },

		{ glm::vec3(0, -GyokKetto, 0), glm::vec3(0.4, 0.15, 0.5) },
		{ glm::vec3(-1, 0, 1), glm::vec3(0.4, 0.15, 0.5) },
        { glm::vec3(-1, 0, -1), glm::vec3(0.4, 0.15, 0.5) },
		


		/*
		{ glm::vec3(-9,9,9), glm::vec3(0.4,1,0)},
		{ glm::vec3(9, 9, 9), glm::vec3(0.4, 1, 0) },
		{ glm::vec3(9, -9, 9), glm::vec3(0.4, 1, 0)},
		{ glm::vec3(-9, -9, 9), glm::vec3(0.4, 1, 0)},

		{ glm::vec3(-9, 9, -9), glm::vec3(0.4, 1, 0)},
		{ glm::vec3(9, 9, -9), glm::vec3(0.4, 1, 0) },
		{ glm::vec3(9, -9, -9), glm::vec3(0.4, 1, 0)},
		{ glm::vec3(-9, -9, -9), glm::vec3(0.4, 1, 0)}
		*/
	};
	//id generálás az 1 db vao id
	glGenVertexArrays(1, &id_vao);
	//bindolás
	glBindVertexArray(id_vao);
	//új errőforrás létrrehozása
	glGenBuffers(1,&id_vbo);
	glBindBuffer(GL_ARRAY_BUFFER,id_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	//index puffer létrehozás
	//glGenBuffers(1, &id_ib);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_ib);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//Pozíciók elmagyarázása a VAO-nak
	glEnableVertexAttribArray(0);
	//0. indexű ATTRIBÚTUMOT  állítjuk be
	//GL_FLOAT aza adatok típusa
	//GL_FALSE -- normalizált legyen e
	//sizeof(Vertex) -- stride
	//0. indexű hol kezdődik sizeof(Vertex) hosszú adatban
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	//Színek elmagyarázása
	//1 csatornát bekapcsolom hogy használnám
	glEnableVertexAttribArray(1);
	//1. indexű ATTRIBÚTUMOT ....
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3)));
	//nem foglalkozunk többet VAO-val, ezzel kikapcsoljuk illetve jelezzük hogy nem piszkáljuk; 0-val jelezve
	glBindVertexArray(0);
	//nem foglalkozunk többet VBO-val, ezzel kikapcsoljuk illetve jelezzük hogy nem piszkáljuk; 0-val jelezve
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//nem foglalkozunk többet index puffer VBO-val, ezzel kikapcsoljuk illetve jelezzük hogy nem piszkáljuk; 0-val jelezve
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//Shaderek betöltése
	GLuint id_vs = loadShader(GL_VERTEX_SHADER, "myVert.vert");
	GLuint id_fs = loadShader(GL_FRAGMENT_SHADER, "myFrag.frag");	

	//Shader program betöltése/fordítása/linkelése következik...
	id_shader_program = glCreateProgram();
	//shader hozzácsatolása a programhoz
	glAttachShader(id_shader_program, id_vs);
	glAttachShader(id_shader_program, id_fs);

	//Linkelés előtt változókat be kell állítani a VAO-beli indexhez !!!
	//0. csatornán vannak a pozíciók; vs_in_pos pedig a shader programban egy változó
	glBindAttribLocation(id_shader_program, 0, "vs_in_pos");
	//1. csatornán vannak a színek; vs_in_col pedig a shader programban egy változó
	glBindAttribLocation(id_shader_program, 1, "vs_in_col");
	//program linkelése
	glLinkProgram(id_shader_program);
	//linkelése ellenőrzése
	checkShaderProgram(id_shader_program);
    //shader betöltések törlése
	glDeleteShader(id_vs);
	glDeleteShader(id_fs);

	//m_mat_proj = glm::perspective(45.0f, 640 / 480.0f, 1.0f, 1000.0f);

	// shader-beli transzformációs mátrixok címének lekérdezése
	loc_world = glGetUniformLocation(id_shader_program, "world");
	loc_view = glGetUniformLocation(id_shader_program, "view");
	loc_proj = glGetUniformLocation(id_shader_program, "proj");
	return true;
}
void OctahedronScene::render(){
	
	// töröljük a frampuffert (GL_COLOR_BUFFER_BIT) és a mélységi Z puffert (GL_DEPTH_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(id_shader_program);
    m_mat_world = glm::mat4(1.0f);

    float angle = SDL_GetTicks() / 500.0f   ;


	//függölegesen hullámoz 9 sugarú gömbön kívül  
	//m_mat_world = glm::rotate<float>(angle, 1, 0, 0)*  glm::translate<float>(5 * sin(SDL_GetTicks() / 250.0f), 10, 0) * glm::rotate<float>(90, 1, 0, 0) * m_mat_world;
	//függölegesen hullámoz
    //m_mat_world = glm::rotate<float>(angle, 0, 1, 0)*  glm::translate<float>(0.0f, 5.0f * sin(SDL_GetTicks() / 500.0f), -10.0f) *  m_mat_world;

    m_mat_world = glm::rotate<float>(m_mat_world,angle, glm::vec3(0,1, 0));
    m_mat_world = glm::translate<float>(m_mat_world,glm::vec3(0.0f, 5.0f * sin(SDL_GetTicks() / 250.0f), -10.0f));

    //m_mat_world = glm::rotate<float>(m_mat_world,90, glm::vec3(1, 0, 0));

    if (enable_rot){
        float angle_rot = SDL_GetTicks() / 1000.0f  ;
//		m_mat_world = glm::rotate<float>(angle_rot, 0, 0, 1);
        m_mat_world = glm::rotate<float>(m_mat_world,angle_rot, glm::vec3(0, 0, 1));

    }

	//loc_world: hely ahová letöltjök a GPUba a mátrixot,// 1 mátrixot szeretnénk letölteni // GL_FALSE ne transzponálja // mátrix legelső elemének címe
	glUniformMatrix4fv(loc_world, 1, GL_FALSE, &(m_mat_world[0][0]));
	glUniformMatrix4fv(loc_view, 1, GL_FALSE, &(m_mat_view[0][0]));
	glUniformMatrix4fv(loc_proj, 1, GL_FALSE, &(m_mat_proj[0][0]));
	//VAO bekoapcsolása a VBO-val jön
	glBindVertexArray(id_vao);
	
	//kirajzolás
	glDrawArrays(GL_TRIANGLES, 0, 24);	
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT,0);
	//VAO kikapcsolása, már hogy nem piszkáljuk többet
	glBindVertexArray(0); 
	//shader program kikapcsolása, már hogy nem piszkáljuk többet
	glUseProgram(0);




}
void OctahedronScene::update(){
	// nézeti transzformáció beállítása// honnan nézzük a színteret // a színtér melyik pontját nézzük // felfelé mutató irány a világban
    m_mat_view = glm::lookAt(glm::vec3(0, 0, 22),glm::vec3(0, 0, 0),glm::vec3(0, 1, 0));
}
void OctahedronScene::cleanUp(){
	glDeleteBuffers(1,&id_vbo);
	glDeleteVertexArrays(1, &id_vao);
	glDeleteProgram(id_shader_program);
}
void  OctahedronScene::keyboardDown(SDL_KeyboardEvent& key){

	if (key.keysym.sym == SDLK_ESCAPE){		
			close();
	}

	if (key.keysym.sym == SDLK_SPACE){
		enable_rot = !enable_rot;
	}

}
void OctahedronScene::resize(int width, int height){

	Scene::resize(width, height);
	// 90 fokos nyilasszog, // ablakmereteknek megfelelo nezeti arany // kozeli vagosik // tavoli vagosik
    m_mat_proj = glm::perspective(45.0f,width/(float)height,0.01f,100.0f);

}
