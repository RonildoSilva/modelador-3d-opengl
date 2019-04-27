#ifndef MODEL_H
#define MODEL_H

#include <GL/glut.h>
#include <bib/CameraDistante.h>
#include <bib/Desenha.h>

#include <string>

/** Classe Abstrata **/
class Model
{
public:
    virtual void init(float tx, float ty, float tz, float ax, float ay, float az, float sx, float sy, float sz);
    Model();
    virtual void desenha() = 0;

    /** Manipulation Angle Functions **/
    virtual void setAX(float ax);
    virtual void setAY(float ay);
    virtual void setAZ(float az);

    virtual float getAX();
    virtual float getAY();
    virtual float getAZ();

    virtual void addAX(float ax);
    virtual void addAY(float ay);
    virtual void addAZ(float az);

    /** Manipulation Translate Functions **/
    virtual float getTX();
    virtual float getTY();
    virtual float getTZ();

    virtual void setTX(float tx);
    virtual void setTY(float ty);
    virtual void setTZ(float tz);

    virtual void addTX(float tx);
    virtual void addTY(float ty);
    virtual void addTZ(float tz);

    /** Manipulation Scale Functions **/
    virtual float getSX();
    virtual float getSY();
    virtual float getSZ();

    virtual void setSX(float sx);
    virtual void setSY(float sy);
    virtual void setSZ(float sz);

    virtual void addSX(float sx);
    virtual void addSY(float sy);
    virtual void addSZ(float sz);

    /** Manipulation Selection Functions **/
    virtual void setSelecionado(bool selecionado);
    virtual bool isSelecionado();

    virtual void setSombra(bool sombra);
    virtual bool isSombra();

    virtual void setEixo(bool eixo);
    virtual bool isEixo();

    virtual std::string getNome() = 0;

    std::string nome = "Model";
private:
    float ax = 0.0;
    float ay = 0.0;
    float az = 0.0;

    float tx = 0.0;
    float ty = 0.0;
    float tz = 0.0;

    float sx = 1.0;
    float sy = 1.0;
    float sz = 1.0;

    bool selecionado = false;
    bool sombra = false;
    bool eixo = false;
};

#endif // MODEL_H
