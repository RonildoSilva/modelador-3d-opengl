#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>

#include <GL/glut.h>

#include <vector>
#include<entities/model.h>

#include <bib/CameraDistante.h>
#include <bib/Desenha.h>

#include <projections/projection.h>

using namespace  std;

class OGLWidget : public QGLWidget
{
public:
    OGLWidget(QWidget *parent = 0);
    void drawQuadPlane(float coo[][3], float normal[3]);
    void initializeGL();
    void paintGL();
        void displayInit();
        void displayPerspective();
        void displayOrtho();
        void displayEnd();
    void resizeGL(int w, int h);

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void addTorusListaModelos();
    void addTeapotListaModelos();
    void addCubeListaModelos();
    void addArvoreListaModelos();

    void addLuzListaModelos();

    void addKratosListaModelos();
    void addBoyListaModelos();
    void addMarioListaModelos();
    void addShelfListaModelos();

    void addEsqueletoListaModelos();
    void addCachorroListaModelos();
    void addLoboListaModelos();

    void increaseCont();
    void decreaseCont();

    void mudancasEixoX(char tipo, float valor);
    void mudancasEixoY(char tipo, float valor);
    void mudancasEixoZ(char tipo, float valor);

    void mudancasAngulo(float x, float y, float z);
    void mudancasTranslacao(float x, float y, float z);
    void mudancasEscala(float x, float y, float z);

    void mudaCamera(int numeroCamera);

    void carregarEstado();
    void salvarEstado();
    void carregarModelo3DOBJ(string caminho, string nome);
    void carregarModelo3D3DS(string caminho, string nome);

    void iniciaLuz();
    void carregaCamera();
    void salvaCamera();

    Camera* cam = new CameraDistante(19.5323,9.36482,24.4429,-0.0726667,0.927333,0,-0.162686,0.965604,-0.202832);
    //Camera* cam = new CameraDistante(0,0,0, 0,0,0, 0,0,0);
    Projection * projection = new Projection();
    float savedCamera[9];

    bool islistaVazia();

    ~OGLWidget();

public slots:
    void buttonPressEvent();

private:
    vector<Model*> listaModelos;

    int cont = 0;

    int width = 800;
    int height = 600;
    float ar = height>0 ? (float) width / (float) height : 1.0;

    int slices = 20;
    int stacks = 20;

    float ax;
    float ay;
    float az;

    float tx;
    float ty;
    float tz;

    float sx;
    float sy;
    float sz;

    float trans_obj = false;

    float delta = 5.0;

    QTimer timer;
    QPoint lastPos;

protected:

};


#endif // OGLWIDGET_H
