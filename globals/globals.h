#ifndef GLOBALS_H
#define GLOBALS_H


class Globals
{
public:
    Globals();

    float normals[4][3] =
    {
      {1.0f,0.0f,0.0f},  //Left wall
      {-1.0f,0.0f,0.0f}, //Right wall
      {0.0f,0.0f,1.0f},  //Back wall
      {0.0f,1.0f,0.0f}   //Floor
    };

    float left_wall[4][3] =
    {
      {-2.0f,-0.5f,4.0f},
      {-2.0f,2.5f,4.0f},
      {-2.0f,2.5f,-3.0f},
      {-2.0f,-0.5f,-3.0f}
    };

    float right_wall[4][3] =
    {
      {2.0f,-0.5f,4.0f},
      {2.0f,2.5f,4.0f},
      {2.0f,2.5f,-3.0f},
      {2.0f,-0.5f,-3.0f}
    };

    float ground[4][3] =
    {
      {-2.0f,-0.5f,-3.0f},
      {-2.0f,-0.5f,4.0f},
      {2.0f,-0.5f,4.0f},
      {2.0f,-0.5f,-3.0f}
    };
};

#endif // GLOBALS_H
