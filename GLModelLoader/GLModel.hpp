#pragma once

#include <string>
#include <memory>
#include <assimp/Importer.hpp>

class GLModel {
public:
    GLModel();

    ~GLModel();

    void Load(const std::string & fileName);

private:
    std::auto_ptr<aiScene> scene;

    std::auto_ptr <Assimp::Importer> importer;

    aiVector3D sceneMin, sceneMax, sceneCenter;


    void SceneGetBoundingBox();

    void SceneCalculateBoundingBoxForNode(const struct aiNode * node, aiVector3D & sceneMin, aiVector3D sceneMax);
};
