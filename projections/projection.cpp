#include "projection.h"

using namespace std;

Projection::Projection() {}

float* Projection::getPerspectiveProjectionMatrix(float near, float far, float aspect_ratio, Camera *camera){

    float maxx = std::max(fabs(camera->u.x), fabs(camera->u.y));
    float maxy = std::max(fabs(camera->u.y), fabs(camera->u.y));
    float max = std::max(maxx, maxy);
    float r = max * aspect_ratio, t = max;
    float l = -r, b = -t;
    float n = near;
    float f = far;

    // set OpenGL perspective projection matrix
    float M [16];
        M[0] = 2 / (r - l);
        M[1] = 0;
        M[2] = 0;
        M[3] = 0;

        M[4] = 0;
        M[5] = 2 / (t - b);
        M[6] = 0;
        M[7] = 0;

        M[8] = 0;
        M[9] = 0;
        M[10] = -2 / (f - n);
        M[11] = 0;

        M[12] = -(r + l) / (r - l);
        M[13] = -(t + b) / (t - b);
        M[14] = -(f + n) / (f - n);
        M[15] = 1;

        return M;
}
