set(PROJECT_NAME Shader1)
project(${PROJECT_NAME})

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

# Set OpenGL dependecies
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Include)
set(GL_LIB_DIR ${CMAKE_SOURCE_DIR}/Libs)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32.lib ${GL_LIB_DIR}/glfw3.lib ${GL_LIB_DIR}/glad.lib)