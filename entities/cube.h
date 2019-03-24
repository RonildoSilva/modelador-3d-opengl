#ifndef CUBE_H
#define CUBE_H

#include <GL/glut.h>
#include <bib/CameraDistante.h>
#include <bib/Desenha.h>

#include<entities/model.h>

class Cube : public Model
{
public:
    Cube();
    void desenha() override;

    float getSize();
    void  setSize(float size);

    std::string getNome() override;

private:
    std::string nome = "Teapot";

    float size = 1.0;

    float trans_obj = false;

    float delta = 5.0; //remover ou nao
};

#endif // CUBE_H
