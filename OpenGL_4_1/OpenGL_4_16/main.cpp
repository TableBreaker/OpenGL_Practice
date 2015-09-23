//
//  main.cpp
//  OpenGL_4_16
//
//  Created by 卢远鹏 on 15/9/19.
//  Copyright © 2015年 Flag. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;

GLsizei winWidth = 400, winHeight = 400;
GLuint regHex;

class screenPt
{
private:
    GLint x, y;
public:
    screenPt()
    {
        x = y = 0;
    }
    
    void setCoords(GLint xCoord, GLint yCoord)
    {
        x = xCoord;
        y = yCoord;
    }
    
    GLint getx() const
    {
        return x;
    }
    
    GLint gety() const
    {
        return y;
    }
};

static void init(void)
{
    screenPt hexVertex, cirCtr;
    GLdouble theta;
    GLint k;
    
    cirCtr.setCoords(winWidth / 2, winHeight / 2);
    
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    regHex = glGenLists(1);
    
    glNewList(regHex, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (k = 0; k < 6; k++) {
        theta = TWO_PI * k / 6.0;
        hexVertex.setCoords(cirCtr.getx() + 150 * cos(theta), cirCtr.gety() + 150 * sin(theta));
        glVertex2i(hexVertex.getx(), hexVertex.gety());
    }
    glEnd();
    glEndList();
}

void regHexagon()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear display window
    
    glCallList(regHex);
    
    glFlush();
}

void winReshapeFcn(int newWidth, int newHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
    
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Reshape-Function & Display-List Example");
    
    init();
    glutDisplayFunc(regHexagon);
    glutReshapeFunc(winReshapeFcn);
    
    glutMainLoop();
    return 0;
}






















