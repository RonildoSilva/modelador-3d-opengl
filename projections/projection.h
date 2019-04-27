#ifndef PROJECTION_H
#define PROJECTION_H
#include <iostream>
#include <bib/CameraDistante.h>

class Projection
{
public:
    Projection();
    GLfloat *getProjectionFrustumMatrix(float near, float far, float aspect_ratio, Camera *camera);
    GLfloat *getProjectionPerspectiveMatrix(float angleOfView, float near, float far, float aspect_ratio, Camera *camera);
};

#endif // PROJECTION_H
