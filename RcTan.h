#pragma once
#ifndef _RC_TAN_H_
#define _RC_TAN_H_

typedef float Mat3x2[6];

float CalDistanceR(unsigned int a,unsigned int b, float angle);
void Mat3x2Translate(Mat3x2 m,float x, float y);
void Mat3x2Init(Mat3x2 m);
void Mat3x2Ratato(Mat3x2 m, unsigned int cx, unsigned cy, unsigned int a, unsigned int b, float angle);



#endif
