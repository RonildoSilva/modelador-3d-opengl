#ifndef TEAPOT_H
#define TEAPOT_H

#include <GL/glut.h>
#include <bib/CameraDistante.h>
#include <bib/Desenha.h>

#include<entities/model.h>

class Teapot : public Model
{
public:
    Teapot();

    void desenha() override;

    float getSize();
    void  setSize(float size);

    void addSlices() override;
    void addStacks() override;
    void decSlices() override;
    void decStacks() override;

    int getSlices() override;
    int getStacks() override;

    std::string getNome() override;

private:
    std::string nome = "Teapot";

    float size = 1.0;

    float trans_obj = false;

    float delta = 5.0; //remover ou nao
};

#endif // TEAPOT_H
