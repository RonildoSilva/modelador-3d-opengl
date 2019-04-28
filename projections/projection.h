#ifndef PROJECTION_H
#define PROJECTION_H
#include <iostream>
#include <bib/CameraDistante.h>

class Projection
{
public:
    Projection();
    GLfloat *getProjectionOrthoMatrix(float near, float far, float aspect_ratio, Camera *camera);
    GLfloat *getProjectionPerspectiveMatrix(float angleOfView, float near, float far, float aspectRatio, Camera *camera);
    float * getCalculatedPlane(float p1[],float p2[],float p3[]);
    float * getshadowMatrix( float plane[], float light_pos[]);
};

#endif // PROJECTION_H
