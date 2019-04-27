#ifndef PROJECTION_H
#define PROJECTION_H
#include <iostream>
#include <bib/CameraDistante.h>

class Projection
{
public:
    Projection();
    float *getPerspectiveProjectionMatrix(float near, float far, float aspect_ratio, Camera *camera);
};

#endif // PROJECTION_H
