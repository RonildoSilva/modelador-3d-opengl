#include "teapot.h"
#include <iostream>

using namespace std;

Teapot::Teapot(){ this->nome = "Teapot"; }

float Teapot::getSize() { return this->size; }
void Teapot::setSize(float size) { this->size = size; }


string Teapot::getNome()
{
    return this->nome;
}

void Teapot::desenha()
{
    //sistema local
    glPushMatrix();
        //composicao de transformacoes
        glTranslated(this->getTX(),this->getTY(),this->getTZ());

        glRotated(this->getAX(),0,0,1);
        glRotated(this->getAY(),0,1,0);
        glRotated(this->getAZ(),1,0,0);

        glScaled(this->getSX(),this->getSY(),this->getSZ());

        //desenhando eixos do sistema de coordenadas local 1
        if(isEixo()){
            Desenha::drawEixos( 0.5 );
        }

        //desenhando objeto

        if(isSelecionado()){
            glColor3f(0.22,1.0,0.07);
        }
        else if (isSombra()){
            glColor3f(0.0,0.0,0.0);
        }
        else{
            glColor3f(0.8,0.5,0.5);
        }

        glutSolidTeapot(this->getSize());
    glPopMatrix();
}
