#include "torus.h"

#include <iostream>

using namespace std;

Torus::Torus() { this->nome = "Torus"; }

Torus::Torus(float innerRadius, float outterRadius, int slices, int stacks)
{
    this->innerRadius = innerRadius;
    this->outterRadius = outterRadius;
    if(slices < 3){ this->slices = 3; }
    if(stacks < 3){ this->stacks = 3; }

    this->slices = slices;
    this->stacks = stacks;

    this->nome = "Torus";
}


void Torus::addSlices() { this->slices++; }
void Torus::decSlices() { this->slices--; }

void Torus::addStacks() { this->stacks++; }
void Torus::decStacks() { this->stacks--; }

int Torus::getSlices() { return this->slices; }
int Torus::getStacks() { return this->stacks; }

void Torus::desenha(){
    //sistema local
    glPushMatrix();
        //composicao de transformacoes
        glTranslated(this->getTX(),this->getTY(),this->getTZ());

        glRotated(this->getAX(),0,0,1);
        glRotated(this->getAY(),0,1,0);
        glRotated(this->getAZ(),1,0,0);

        glScaled(this->getSX(),this->getSX(),this->getSZ());

        //desenhando eixos do sistema de coordenadas local 1
        if(isEixo()){
            Desenha::drawEixos( 0.5 );
        }
         //glColor3d(0,1,0);
        //desenhando objeto
          if(isSelecionado()){
              glColor3f(0.22,1.0,0.07);
          }
          else if (isSombra()){
              glColor3f(0.0,0.0,0.0);
          }
          else{
              glColor3f(0.1,0.0,0.8);
          }

        glutSolidTorus(this->getInnerRadius(),this->getOutterRadius(),
                       this->getSlices(),this->getStacks());

    glPopMatrix();
}

float Torus::getInnerRadius()
{
    return this->innerRadius;
}

float Torus::getOutterRadius()
{
    return this->outterRadius;
}

void Torus::setInnerRadius(float innerRadius)
{
    this->innerRadius = innerRadius;
}

void Torus::setOutterRadius(float outterRadius)
{
    this->outterRadius = outterRadius;
}

string Torus::getNome() { return this->nome; }
