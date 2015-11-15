include_directories( ${OPENGL_INCLUDE_DIRS}, ${GLEW_INCLUDE_DIRS}, ${SDL2_INCLUDE_DIRS} )
add_executable ( ${EXECUTABLE_NAME} main.cpp SDLApp/SDLApplication.cpp OctahedronScene.cpp OctahedronSDLApplication.cpp)
target_link_libraries( ${EXECUTABLE_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES} )

