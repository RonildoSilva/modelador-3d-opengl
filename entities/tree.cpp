#include "tree.h"

using namespace std;

Tree::Tree() { this->nome = "Arvore"; }
int numberCups = 2;
void Tree::addSlices() { this->slices++; }
void Tree::decSlices() { this->slices--; }

void Tree::addStacks() { this->stacks++; }
void Tree::decStacks() { this->stacks--; }

int Tree::getSlices() { return this->slices; }
int Tree::getStacks() { return this->stacks; }

void Tree::desenha(){
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
        glColor3f(0.5,0.5,0.5);
    }

    glRotated(-90,1,0,0);

    GLdouble i = 1.0; //>= 1.0 <= 2.0
    GLdouble green_base = 0.5; //Representa a relacao da largura da base e a cor

    GLfloat mult = 0.5;

    //Tronco
    glColor3d(0.6, 0.1, 0.1);
    gluCylinder(gluNewQuadric(),
                mult*(GLdouble)numberCups/10,
                mult*(GLdouble)numberCups/10,
                (1.0), slices, stacks);

    GLfloat angle = 0.0;
    //Copas
    while (i <= numberCups) {

        glColor3d(0,green_base/i,0);

        glTranslated(0,0,1.0); //Poe uma copa sobre a outra
        gluCylinder(gluNewQuadric(),
                    mult*((numberCups+green_base)-(i)),
                    mult*(numberCups-i),
                    (i), slices, stacks);
        i+=0.5;
    }

    glPopMatrix();
}

string Tree::getNome()
{
    return this->nome;
}

