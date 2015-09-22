//
//  main.cpp
//  OpenGL_4_3
//
//  Created by 卢远鹏 on 15/9/19.
//  Copyright © 2015年 Flag. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <math.h>

const GLdouble twoPi = 6.283185;

class scrPt
{
public:
    GLint x, y;
};

GLsizei winWidth = 400, winHeight = 300;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
    
}

void drawCircle(scrPt ctr, GLfloat radius)
{
    scrPt pt[2];
    GLfloat curDegree, degree = 1.0 / radius;
    
    curDegree = degree;
    pt[0].x = ctr.x + radius;
    pt[0].y = ctr.y;
    
    while (curDegree < twoPi) {
        
        pt[1].x = ctr.x + radius * cos(curDegree);
        pt[1].y = ctr.y + radius * sin(curDegree);
        
        glBegin(GL_LINES);
        glVertex2i(pt[0].x, pt[0].y);
        glVertex2i(pt[1].x, pt[1].y);
        glEnd();
        
        pt[0].x = pt[1].x;
        pt[0].y = pt[1].y;
        curDegree += degree;
    }
}

void pieChart(void)
{
    scrPt circCtr, piePt;
    GLint radius = winWidth / 4;
    
    GLdouble sliceAngle, previousSliceAngle = 0.0;
    
    GLint k, nSlices = 12;
    GLfloat dataValues[12] = {10.0, 7.0, 13.0, 5.0, 13.0, 14.0, 3.0, 16.0, 5.0, 3.0, 17.0, 8.0};
    
    GLfloat dataSum = 0.0;
    
    circCtr.x = winWidth / 2;
    circCtr.y = winHeight / 2;
    
    
    //draw a circle
    drawCircle(circCtr, radius);
    
    for (k = 0; k < nSlices; k++) {
        dataSum += dataValues[k];
    }
    
    for (k = 0; k < nSlices; k++) {
        sliceAngle = twoPi * dataValues[k] / dataSum + previousSliceAngle;
        piePt.x = circCtr.x + radius * cos(sliceAngle);
        piePt.y = circCtr.y + radius * sin(sliceAngle);
        
        glBegin(GL_LINES);
        glVertex2i(circCtr.x, circCtr.y);
        glVertex2i(piePt.x, piePt.y);
        glEnd();
        previousSliceAngle = sliceAngle;
    }
}

void displayFcn(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.0, 1.0);
    pieChart();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    
    glutCreateWindow("Pie Chart");
    
    init();
    glutDisplayFunc(displayFcn);
    
    glutMainLoop();
}






