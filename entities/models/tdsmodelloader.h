#ifndef TDSMODELLOADER_H
#define TDSMODELLOADER_H

#include <GL/glut.h>
#include <lib3ds/file.h>
#include <lib3ds/camera.h>
#include <lib3ds/mesh.h>
#include <lib3ds/node.h>
#include <lib3ds/material.h>
#include <lib3ds/matrix.h>
#include <lib3ds/vector.h>
#include <lib3ds/light.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <SDL/SDL_image.h>

#include "entities/model.h"

#define	TEX_XSIZE	1024
#define	TEX_YSIZE	1024

//#define USE_SDL

struct _player_texture
{
  int valid; // was the loading attempt successful ?
#ifdef	USE_SDL
  SDL_Surface *bitmap;
#else
  void *bitmap;
#endif
  GLuint tex_id; //OpenGL texture ID
  float scale_x, scale_y; // scale the texcoords, as OpenGL thinks in TEX_XSIZE and TEX_YSIZE
};
typedef struct _player_texture Player_texture;

class TdsModelLoader : public Model
{
public:
    TdsModelLoader();
    TdsModelLoader(const char *name, std::string filename);
    //TdsModelLoader(std::string name, std::__cxx11::string filename);
    /*
    TdsModelLoader(std::string param, std::string nomeModelo,
            float tx, float ty, float tz,
            float ax, float ay, float az,
            float sx, float sy, float sz);
            */
    ~TdsModelLoader();

    Player_texture *pt;
    int tex_mode; // Texturing active ?
    Lib3dsFile *file;
    void render_node(Lib3dsNode *node);

   void desenha() override;

   float getSize();
   void setSize(float size);

   void addSlices() override;
   void addStacks() override;
   void decSlices() override;
   void decStacks() override;

   int getSlices() override;
   int getStacks() override;

   std::string getNome() override;

private:

    bool selecionado = false;
    bool sombra = false;
    bool eixo = false;

    std::string filename = "";

};

#endif // TDSMODELLOADER_H
