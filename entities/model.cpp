#include "model.h"

Model::Model() {}

/** **/
void Model::init(float tx, float ty, float tz, float ax, float ay, float az, float sx, float sy, float sz) {
    this->tx = tx;
    this->ty = ty;
    this->tz = tz;

    this->ax = ax;
    this->ay = ay;
    this->az = az;

    this->sx = sx;
    this->sy = sy;
    this->sz = sz;
}


float Model::getAX() { return this->ax; }
float Model::getAY() { return this->ay; }
float Model::getAZ() { return this->az; }

void Model::setAX(float ax) { this->ax = ax; }
void Model::setAY(float ay) { this->ay = ay; }
void Model::setAZ(float az) { this->az = az; }

void Model::addAX(float ax) { this->ax += ax; }
void Model::addAY(float ay) { this->ay += ay; }
void Model::addAZ(float az) { this->az += az; }

/** **/
float Model::getTX() { return this->tx; }
float Model::getTY() { return this->ty; }
float Model::getTZ() { return this->tz; }

void Model::setTX(float tx) { this->tx = tx; }
void Model::setTY(float ty) { this->ty = ty; }
void Model::setTZ(float tz) { this->tz = tz; }

void Model::addTX(float tx) { this->tx+=tx; }
void Model::addTY(float ty) { this->ty+=ty; }
void Model::addTZ(float tz) { this->tz+=tz; }

/** **/
float Model::getSX() { return this->sx; }
float Model::getSY() { return this->sy; }
float Model::getSZ() { return this->sz; }

void Model::setSX(float sx) { this->sx = sx; }
void Model::setSY(float sy) { this->sy = sy; }
void Model::setSZ(float sz) { this->sz = sz; }

void Model::addSX(float sx) { this->sx+=sx; }
void Model::addSY(float sy) { this->sy+=sy; }
void Model::addSZ(float sz) { this->sz+=sz; }

/** **/
void Model::setSelecionado(bool selecionado){ this->selecionado = selecionado; }
bool Model::isSelecionado(){ return this->selecionado; }

void Model::setEixo(bool eixo) { this->eixo = eixo; }
bool Model::isEixo() { return this->eixo; }

void Model::setSombra(bool sombra) { this->sombra = sombra; }
bool Model::isSombra() { return this->sombra; }
