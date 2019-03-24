#ifndef TORUS_H
#define TORUS_H

#include <GL/glut.h>
#include <bib/CameraDistante.h>
#include <bib/Desenha.h>
#include <entities/model.h>

class Torus: public Model
{
public:
    Torus();
    Torus(float innerRadius, float outterRadius,
          int slices, int stacks);

    void desenha() override;

    float getInnerRadius();
    float getOutterRadius();

    void setInnerRadius(float innerRadius);
    void setOutterRadius(float outterRadius);

    void addSlices();
    void addStacks();
    void decSlices();
    void decStacks();

    int getSlices();
    int getStacks();


    std::string getNome() override;

private:
    std::string nome = "Torus";

    float innerRadius = 0.2;
    float outterRadius = 0.8;

    int slices = 15;
    int stacks = 15;

    float trans_obj = false;

    float delta = 5.0;
};

#endif // TORUS_H
