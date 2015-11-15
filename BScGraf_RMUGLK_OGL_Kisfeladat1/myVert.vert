#version 130

// VBO-b�l �rkez� v�ltoz�k
in vec3 vs_in_pos;
in vec3 vs_in_col;

// a pipeline-ban tov�bb adand� �rt�kek
out vec3 vs_out_col;
//out vec3 vs_out_pos;
// shader k�ls� param�terei - most a h�rom transzform�ci�s m�trixot k�l�n-k�l�n vessz�k �t
uniform mat4 world;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	
	//z(x,y)=x^3 - x*y + y^2 fel�let, -2<=x,y<=2 feletti r�sz�nek n�gy sarokpontj�ba �s k�z�ppontj�ban (teh�t z(-2,-2),z(2,-2),z(2,2),z(-2,2),z(0,0) pontokba) 
	vs_out_col = vs_in_col;

//	vec3 v = vec3(vs_in_pos);
//	if ( -2 <= vs_in_pos.x && vs_in_pos.y <= 2 ){
	//	v.z = pow(v.x,3) - (v.x * v.y) + pow(v.y,2);
		
//	} 

//	vs_out_pos = v;
	  
	  gl_Position = proj * view * world * vec4( vs_in_pos, 1 );
	 // gl_Position = proj * view * world * vec4( v, 1 );
	
}