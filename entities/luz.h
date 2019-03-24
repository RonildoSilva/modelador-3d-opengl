#ifndef LUZ_H
#define LUZ_H

#include <GL/glut.h>
#include <bib/CameraDistante.h>
#include <bib/Desenha.h>
#include <entities/model.h>

#include <bib/GUI.h>

class Luz : public Model
{
public:
    Luz();

    void desenha() override;

    float getInnerRadius();
    float getOutterRadius();

    void setInnerRadius(float innerRadius);
    void setOutterRadius(float outterRadius);

    void addSX(float sx);
    void addSY(float sy);
    void addSZ(float sz);

    void setSX(float sx);
    void setSY(float sy);
    void setSZ(float sz);

    float getSX();
    float getSY();
    float getSZ(); 

    std::string getNome() override;

private:
    std::string nome = "Luz";

    int indexLight = -1;

    float innerRadius = 0.2;
    float outterRadius = 0.8;

    int slices = 15;
    int stacks = 15;

    float trans_obj = false;
    float trans_luz = false;

    float ax = 0.0;
    float ay = 0.0;
    float az = 0.0;

    float delta = 5.0;

    float sx = 1.0;
    float sy = 1.0;
    float sz = 1.0;
};

#endif // LUZ_H
