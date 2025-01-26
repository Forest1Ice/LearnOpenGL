set(PROJECT_NAME Coordinate2)
project(${PROJECT_NAME})

set(SRC ${CMAKE_SOURCE_DIR}/Src)
file(GLOB SRC_FILES "${SRC}/*.cpp")

add_executable(
    ${PROJECT_NAME}
    main.cpp
    ${SRC_FILES}
)

# Set OpenGL dependecies
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Include)
set(GL_LIB_DIR ${CMAKE_SOURCE_DIR}/Libs)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32.lib ${GL_LIB_DIR}/glfw3.lib ${GL_LIB_DIR}/glad.lib)

# Add resources
set(SHADER_PATH "${CMAKE_SOURCE_DIR}/Resources/shaders")
add_definitions(-DSHADER_PATH="${SHADER_PATH}")

set(TEXTURE_PATH "${CMAKE_SOURCE_DIR}/Resources/textures")
add_definitions(-DTEXTURE_PATH="${TEXTURE_PATH}")