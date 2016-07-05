#include <iostream>
#include <exception>
#include <memory>

#include "GLScene.hpp"

using namespace std;

int main() {
    auto_ptr<GLScene> scene;

    try {
        scene.reset(new GLScene());
        scene->StartRendering();
    }
    catch (exception & e) {
        cout << e.what();
    }

    return 0;
}
