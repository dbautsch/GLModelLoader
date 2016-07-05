#include "GLModel.hpp"

#include <exception>
#include <limits>
#include <assimp/cimport.h>
#include <assimp/scene.h>

using namespace std;

GLModel::GLModel() {

}

GLModel::~GLModel() {

}

void GLModel::Load(const string & fileName) {

    //!< Load 3D model from file using Assimp library.
    //!< \param fileName [in] An input file which contains model data. Function
    //!<    is recognizing the format of the input file.

    importer.reset(new Assimp::Importer());
    const aiScene * loadedScene = importer->ReadFile(fileName, 0);

    if (loadedScene == nullptr)
        throw runtime_error("Assimp has failed to load file " + fileName);

    scene.reset(importer->GetOrphanedScene());
}

void GLModel::SceneGetBoundingBox() {

    aiMatrix4x4 modelMatrix;

    aiIdentityMatrix4(&modelMatrix);


    sceneMin.x = numeric_limits<float>::max();
    sceneMin.y = numeric_limits<float>::max();
    sceneMin.z = numeric_limits<float>::max();

    sceneMax.x = numeric_limits<float>::min();
    sceneMax.y = numeric_limits<float>::min();
    sceneMax.z = numeric_limits<float>::min();

    sceneCenter.x = 0;
    sceneCenter.y = 0;
    sceneCenter.z = 0;

    SceneCalculateBoundingBoxForNode(scene->mRootNode, sceneMin, sceneMax);
}

void GLModel::SceneCalculateBoundingBoxForNode(const struct aiNode * node,
    aiVector3D & sceneMin, aiVector3D sceneMax) {

}
