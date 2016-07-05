#include "GLScene.hpp"

#include <stdexcept>
#include <GL/glew.h>

using namespace std;

GLScene::GLScene() {
    window = nullptr;
    glContext = nullptr;

    viewPortW = 0;
    viewPortH = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw runtime_error("Failed to init SDL.");

    //  try to request 3.2 GL version
    if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3) != 0)
        throw runtime_error("Failed to create OpenGL 3.3 context.");

    if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3) != 0)
        throw runtime_error("Failed to create OpenGL 3.3 context.");

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow("GLModelLoader - SDL App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == nullptr)
        throw runtime_error("Failed to create SDL main window.");

    glContext = SDL_GL_CreateContext(window);

    if (glContext == nullptr)
        throw runtime_error("Failed to create OpenGL context.");

    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}

GLScene::~GLScene() {
    if (glContext)
        SDL_GL_DeleteContext(glContext);

    if (window)
        SDL_DestroyWindow(window);

    SDL_Quit();
}

void GLScene::StartRendering() {
    if (window == nullptr || glContext == nullptr)
        throw runtime_error("OpenGL context was not properly initialized.");

    SDL_Event event;

    bool quit = false;

    while (!quit) {
        while(SDL_WaitEvent(&event)) {

            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }

            else if (event.type == SDL_WINDOWEVENT) {

                switch (event.window.type) {
                case SDL_WINDOWEVENT_RESIZED:
                    UpdateGLViewport(event.window.data1, event.window.data2);
                    break;
                }
            }

            Render();
        }
    }
}

void GLScene::Render() {
    glClearColor(0.1, 0.1, 0.2,1);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    SDL_GL_SwapWindow(window);
}

void GLScene::UpdateGLViewport(unsigned w, unsigned h) {
    glViewport(0, 0, w, h);
    viewPortW = w;
    viewPortH = h;
}
