#ifndef OBJMODELLOADER_H
#define OBJMODELLOADER_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <GL/gl.h>
#include <entities/model.h>

class ObjModelLoader : public Model
{
public:
    ObjModelLoader();
    //ObjModelLoader(std::string filename, std::__cxx11::string nome);
    ObjModelLoader(std::string filename, std::__cxx11::string nome);

    void desenha() override;

    float getSize();
    void  setSize(float size);

    std::string getNome() override;

    ~ObjModelLoader();

private:
    std::string filename = "";
    std::vector<std::vector<float>*> *vertices = new std::vector<std::vector<float>*>;
    std::vector<std::vector<int>*>   *faces    = new std::vector<std::vector<int>*>;
    std::vector<std::string>* GetSplittedStrings(std::string text, char delimeter);
    float GetFloatFromString(std::string text);
    float* GetNormal(float *coord1, float *coord2, float *coord3);
};

#endif // OBJMODELLOADER_H
