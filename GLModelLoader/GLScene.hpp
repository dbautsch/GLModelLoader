#pragma once

#include <SDL2/SDL.h>

class GLScene {
public:
    GLScene();

    ~GLScene();

    void StartRendering();

private:
    SDL_Window * window;

    SDL_GLContext glContext;

    unsigned viewPortW, viewPortH;


    void Render();

    void UpdateGLViewport(unsigned w, unsigned h);
};
