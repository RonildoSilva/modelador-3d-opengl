#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H

#include <vector>
#include <fstream>
#include <iostream>

#include "entities/model.h"
#include "entities/torus.h"
#include "entities/teapot.h"
#include "entities/cube.h"
#include "entities/tree.h"
#include "entities/luz.h"

#include "entities/models/objmodelloader.h"
#include "entities/models/tdsmodelloader.h"

using namespace std;

class FileManipulation
{
public:
    FileManipulation();

    vector<Model*> carregarEstado(vector<Model*> listaModelos);
    void salvarEstado(vector<Model *> listaModelos);

    CameraDistante *carregaCamera();
    void salvaCamera(Camera *cam);
};

#endif // FILEMANIPULATION_H
