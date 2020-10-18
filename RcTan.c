#include<math.h>
#include "RcTan.h"

#define DegreeToPi 3.1415926f / 180.0f
//
float CalDistanceR(unsigned int a, unsigned int b,float angle)
{
    float Ref = 0.0f;

    // Circle
    if (a == b) {
        return a;
    }
    // short a large b
    else if (a < b) {
        float af = a * a;//short
        float cf = b * b - af;
        float sinF = (float)sin(angle);
        float di = 1 - cf / af * sinF * sinF;

        Ref = b / (float)sqrt(di);

    }
    // short b large a
    else {
        float af = a * a;
        float cf = af - b * b;
        float cosF = (float)cos(angle);
        float di = 1 - cf / af * cosF * cosF;

        Ref = b / (float)sqrt(di);
    }

    return Ref;
}

void Mat3x2Translate(Mat3x2 m, float x, float y)
{
    m[4] = m[4] + m[0] * x + m[2] * y;
    m[5] = m[5] + m[3] * y + m[1] * x;
}

void Mat3x2Init(Mat3x2 m)
{
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;
    m[3] = 1;
    m[4] = 0;
    m[5] = 0;
}

void Mat3x2Ratato(Mat3x2 m, unsigned int cx, unsigned cy, unsigned int a, unsigned int b, float angle)
{
    // 1.Init
    Mat3x2Init(m);

    // 2.Translate to Centery Point
    Mat3x2Translate(m, cx, cy);

    // 3.Ratato
    float Ang = angle *DegreeToPi;
    float c = (float)cos(Ang);
    float s = (float)sin(Ang);
    float R = CalDistanceR(a, b, Ang);

    m[0] =  c;
    m[1] =  s;
    m[2] = -s;
    m[3] =  c;

    // 3.Translate to O
    Mat3x2Translate(m, -1.0f * cx, -1.0f * cy);
}