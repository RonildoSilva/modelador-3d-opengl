#ifndef GLOBALS_H
#define GLOBALS_H


class Globals
{
public:
    Globals();

    float normals[4][3] =
    {
      {1.0f,0.0f,0.0f},  //Left wall  0
      {-1.0f,0.0f,0.0f}, //Right wall 1
      {0.0f,0.0f,1.0f},  //Back wall  2
      {0.0f,1.0f,0.0f}   //Floor      3
    };

    float left_wall[4][3] =
    {
     {-2.0f,0.0f,-3.0f}, //3
     {-2.0f,2.5f,-3.0f},//2
     {-2.0f,2.5f,4.0f}, //1
     {-2.0f,0.0f,4.0f}, //0
    };

    float right_wall[4][3] =
    {
      {2.0f,0.0f,4.0f},
      {2.0f,2.5f,4.0f},
      {2.0f,2.5f,-3.0f},
      {2.0f,0.0f,-3.0f}
    };

    float ground[4][3] =
    {
      {-2.0f,0.0f,-3.0f},
      {-2.0f,0.0f,4.0f},
      {2.0f,0.0f,4.0f},
      {2.0f,0.0f,-3.0f}
    };

    float back_wall[4][3] =
    {
      {2.0f, 0.0f,-3.0f},//3
      {2.0f, 2.5f, -3.0f},//2
      {-2.0f, 2.5f, -3.0f},//1
      {-2.0f, 0.0f, -3.0f}//0
    };
};

#endif // GLOBALS_H
