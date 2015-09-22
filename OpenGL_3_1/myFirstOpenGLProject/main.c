//
//  main.c
//  myFirstOpenGLProject
//
//  Created by 卢远鹏 on 15/9/6.
//  Copyright (c) 2015年 Flag. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <math.h>


void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 400.0);
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.4, 0.2);
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_CLEAR);
    glBegin(GL_QUADS);
    
//    glVertex2i(50, 50);
//    glVertex2i(50, 100);
//
//    glVertex2i(100, 100);
//    glVertex2i(100, 50);
//    glVertex2i(150, 50);
//    glVertex2i(150, 100);
//    glVertex2i(200, 50);
//    glVertex2i(200, 100);
    
    glRasterPos2i(100, 300);
    for (int k = 0; k < 36; k++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'k');
    }

    glEnd();
    
    glFlush();
}


void drawList()
{
    const double TWO_PI = 6.2831853;
    
    GLuint regHex;
    
    GLdouble theta;
    GLint x, y, k;
    
    regHex = glGenLists(1);
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.4, 0.2);
    
    glNewList(regHex, GL_COMPILE);
    glBegin(GL_POLYGON);
    for (k = 0; k < 6; k++) {
        theta = TWO_PI * k / 6.0;
        x = 200 + 150 * cos(theta);
        y = 200 + 150 * sin(theta);
        glVertex2i(x, y);
    }
    glEnd();
    glEndList();
    
    glCallList(regHex);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("An Example OpenGL Program");
    
    init();
    glutDisplayFunc(drawList);
    glutMainLoop();
    return 0;
}

