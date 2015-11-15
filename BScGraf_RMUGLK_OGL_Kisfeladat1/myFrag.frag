#version 130

in vec3 vs_out_col;
in vec3 vs_out_pos;
out vec4 fs_out_col;

void main()
{    
  //  if ( -2 > vs_out_pos.x && vs_out_pos.y > 2 )
//	 discard;

    fs_out_col = vec4(vs_out_col, 1);
}
