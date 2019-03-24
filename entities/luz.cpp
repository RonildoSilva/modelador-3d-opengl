#include "luz.h"

#include <iostream>

using namespace std;

Luz::Luz()
{
    this->indexLight ++;
    this->nome = "Luz";
}

/* Não altero a escala */
void Luz::addSY(float sy) { this->sy = 1.0; }
void Luz::addSX(float sx) { this->sx = 1.0; }
void Luz::addSZ(float sz) { this->sz = 1.0; }

void Luz::setSX(float sx) { this->sx = 1.0; }
void Luz::setSY(float sy) { this->sy = 1.0; }
void Luz::setSZ(float sz) { this->sz = 1.0; }

float Luz::getSX() { return this->sx; }
float Luz::getSY() { return this->sy; }
float Luz::getSZ() { return this->sz; }

void Luz::desenha(){
    //habilitando transparencias
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //sistema local
    glPushMatrix();

        //composicao de transformacoes
        glTranslated(this->getTX(),this->getTY(),this->getTZ());

        glRotated(this->getAX(),0,0,1);
        glRotated(this->getAY(),0,1,0);
        glRotated(this->getAZ(),1,0,0);

        glScaled(this->getSX(),this->getSX(),this->getSZ());

        //desenhando objeto
        if(isSelecionado()){
            glColor4f(0.22,1.0,0.07,1);
        }
        else{
            glColor4f(1,1,1,0);
        }

        //glTranslatef(this->getTX(),this->getTY(),this->getTZ());
        gluSphere(gluNewQuadric(),this->innerRadius, this->slices, this->stacks);
        glutGUI::trans_luz = trans_luz;
        GUI::setLight(indexLight, 0, 0, 0, false, false);

        //GUI::setLight(0,posicao_luz[0],posicao_luz[1],posicao_luz[2],false,false);
        GLfloat posicao_luz[] = {this->getTX(),this->getTY(),this->getTZ(),1.0f};
        glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);

    glPopMatrix();
}

float Luz::getInnerRadius() { return this->innerRadius; }
void Luz::setInnerRadius(float innerRadius) { this->innerRadius = innerRadius; }

float Luz::getOutterRadius() { return this->outterRadius; }
void Luz::setOutterRadius(float outterRadius) { this->outterRadius = outterRadius; }

string Luz::getNome(){ return this->nome; }
