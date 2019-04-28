#include "projection.h"

using namespace std;

Projection::Projection() {}

//Orhto
GLfloat* Projection::getProjectionOrthoMatrix(float near, float far, float aspect_ratio, Camera *camera){
    float maxx = std::max(fabs(camera->u.x), fabs(camera->u.y));
    float maxy = std::max(fabs(camera->u.y), fabs(camera->u.y));
    float max = std::max(maxx, maxy);
    float r = max * aspect_ratio, t = max;
    float l = -r, b = -t;

    // set OpenGL perspective projection matrix
    GLfloat * M = new GLfloat[16];
    M[0] = 2 / (r - l); M[1] = 0; M[2] = 0; M[3] = 0;
    M[4] = 0;  M[5] = 2 / (t - b); M[6] = 0; M[7] = 0;
    M[8] = 0; M[9] = 0; M[10] = -2 / (far - near); M[11] = 0;
    M[12] = -(r + l) / (r - l); M[13] = -(t + b) / (t - b); M[14] = -(far + near) / (far - near); M[15] = 1;

    return M;
}

//Frustm
GLfloat* Projection::getProjectionPerspectiveMatrix(float angleOfView, float near,
                                                    float far, float aspectRatio, Camera *camera){
    float scale = tan(angleOfView * 0.5 * M_PI / 180) * near;
    float right = aspectRatio * scale, left = -right;
    //float left = -right;
    float top = scale, bottom = -top;
    //float bottom = -top;

    GLfloat * M = new GLfloat[16];

    // set OpenGL perspective projection matrix
    M[0] = 2 * near / (right - left);
    M[1] = 0;
    M[2] = 0;
    M[3] = 0;

    M[4] = 0;
    M[5] = 2 * near / (top - bottom);
    M[6] = 0;
    M[7] = 0;

    M[8] = (right + left) / (right - left);
    M[9] = (top + bottom) / (top - bottom);
    M[10] = -(far + near) / (far - near);
    M[11] = -1;

    M[12] = 0;
    M[13] = 0;
    M[14] = -2 * far * near / (far - near);
    M[15] = 0;

    return M;
}

//Find the plane on the form ax +  by + cx + d,
//based on three known points in the plane
//p1, p2, p3. a,b,c is the plane's normal.
float * Projection::getCalculatedPlane(float p1[],float p2[],float p3[]){
        //Array for the plane equation
    static float plane[4];

        //Given two vectors (three points) in the plane
        //the normal can be calculated
    plane[0] = ((p2[1]-p1[1])*(p3[2]-p1[2]))-
                             ((p2[2]-p1[2])*(p3[1]-p1[1]));
    plane[1] = ((p2[2]-p1[2])*(p3[0]-p1[0]))-
                             ((p2[0]-p1[0])*(p3[2]-p1[2]));
    plane[2] = ((p2[0]-p1[0])*(p3[1]-p1[1]))-
                             ((p2[1]-p1[1])*(p3[0]-p1[0]));
    plane[3] = -(plane[0]*p1[0] + plane[1]*p1[1] + plane[2]*p1[2]);


    return plane;
}

//The function return a 4x4 shadow matrix, and receives two arrays that
//contains the plane function for a plane that we will cast shadow on
//and the position of the light.
float * Projection::getshadowMatrix( float plane[], float light_pos[]) {
   static float shadow_mat[16];
   static float dot;

    //Finds dot, which is the product of the light vetcor and the plane's normal
   dot = plane[0] * light_pos[0] +
    plane[1] * light_pos[1] +
    plane[2] * light_pos[2] +
    plane[3] * light_pos[3];

   shadow_mat[0]  = dot - light_pos[0] * plane[0];
   shadow_mat[4]  = -light_pos[0] * plane[1];
   shadow_mat[8]  = -light_pos[0] * plane[2];
   shadow_mat[12] = -light_pos[0] * plane[3];

   shadow_mat[1]  = -light_pos[1] * plane[0];
   shadow_mat[5]  = dot - light_pos[1] * plane[1];
   shadow_mat[9]  = -light_pos[1] * plane[2];
   shadow_mat[13] = -light_pos[1] * plane[3];

   shadow_mat[2]  = -light_pos[2] * plane[0];
   shadow_mat[6]  = -light_pos[2] * plane[1];
   shadow_mat[10] = dot - light_pos[2] * plane[2];
   shadow_mat[14] = -light_pos[2] * plane[3];

   shadow_mat[3]  = -light_pos[3] * plane[0];
   shadow_mat[7]  = -light_pos[3] * plane[1];
   shadow_mat[11] = -light_pos[3] * plane[2];
   shadow_mat[15] = dot - light_pos[3] * plane[3];

   return shadow_mat;
}
