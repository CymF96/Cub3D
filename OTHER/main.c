#include <math.h>
#include <stdio.h>
#include <float.h>

#define PI 3.14159265359

int main()
{
    float   angle1 = 0;
    float   angle2 = 0;
    float   x = 320;
    float   y = 640;

    angle1 = -PI / 2;
    angle2 = PI / 2;
    x += cos(angle1) * 3;
    y += sin(angle1) * 3;
    printf("angle 1: %.5f, angle 2: %.5f\n", angle1, angle2);
    printf("x: %.5f, y: %.5f\n", x, y);
    x += cos(angle2) * 3;
    y += sin(angle2) * 3;
    printf("x: %.5f, y: %.5f\n", x, y);
    return (0);
}
