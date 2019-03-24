#ifndef TREE_H
#define TREE_H

#include <GL/glut.h>
#include <bib/CameraDistante.h>
#include <bib/Desenha.h>
#include<entities/model.h>

class Tree : public Model
{
public:
    Tree();

    void desenha() override;

    float getInnerRadius();
    float getOutterRadius();

    void setInnerRadius(float innerRadius);
    void setOutterRadius(float outterRadius);

    void addSlices() override;
    void addStacks() override;
    void decSlices() override;
    void decStacks() override;

    int getSlices() override;
    int getStacks() override;

    std::string getNome() override;

private:
    std::string nome = "Arvore";

    int slices = 10;
    int stacks = 10;

    float trans_obj = false;

    float delta = 5.0;
};

#endif // TREE_H
