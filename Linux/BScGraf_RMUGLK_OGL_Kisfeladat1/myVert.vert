#version 130

// VBO-ból érkezõ változók
in vec3 vs_in_pos;
in vec3 vs_in_col;

// a pipeline-ban tovább adandó értékek
out vec3 vs_out_col;
//out vec3 vs_out_pos;
// shader külsõ paraméterei - most a három transzformációs mátrixot külön-külön vesszük át
uniform mat4 world;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	
	//z(x,y)=x^3 - x*y + y^2 felület, -2<=x,y<=2 feletti részének négy sarokpontjába és középpontjában (tehát z(-2,-2),z(2,-2),z(2,2),z(-2,2),z(0,0) pontokba) 
	vs_out_col = vs_in_col;

//	vec3 v = vec3(vs_in_pos);
//	if ( -2 <= vs_in_pos.x && vs_in_pos.y <= 2 ){
	//	v.z = pow(v.x,3) - (v.x * v.y) + pow(v.y,2);
		
//	} 

//	vs_out_pos = v;
	  
	  gl_Position = proj * view * world * vec4( vs_in_pos, 1 );
	 // gl_Position = proj * view * world * vec4( v, 1 );
	
}