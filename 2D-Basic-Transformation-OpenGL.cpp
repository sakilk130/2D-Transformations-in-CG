#include <stdio.h>

#include <math.h>

#include <iostream>

#include <vector>

#include<gdiplus.h>

#include <GL/glut.h>

using namespace std;

int pntX1, pntY1, choice = 0, edges;
vector < int > pntX;
vector < int > pntY;
int transX, transY;
double scaleX, scaleY;
double round(double d) {
  return floor(d + 0.5);
}

void drawPolygon() {
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
  for (int i = 0; i < edges; i++) {
    glVertex2i(pntX[i], pntY[i]);
  }
  glEnd();
}

void drawPolygonTrans(int x, int y) {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.0, 1.0);
  for (int i = 0; i < edges; i++) {
    glVertex2i(pntX[i] + x, pntY[i] + y);
  }
  glEnd();
}

void drawPolygonScale(double x, double y) {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);
  for (int i = 0; i < edges; i++) {
    glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
  }
  glEnd();
}
void myInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);

  if (choice == 1) {
    drawPolygon();
    drawPolygonTrans(transX, transY);
  } else if (choice == 2) {
    drawPolygon();
    drawPolygonScale(scaleX, scaleY);
  }
  glFlush();
}
int main(int argc, char ** argv) {
  cout << "Enter your choice:\n" << endl;
  cout << "1. Translation" << endl;
  cout << "2. Scaling" << endl;
  cout << "3. Exit\n" << endl;
  cout << "Choice:";
  cin >> choice;

  if (choice == 3) {
    return 0;
  }
  cout << "Enter no. of edges:";
  cin >> edges;

  for (int i = 0; i < edges; i++) {
    cout << "Enter co-ordinates for vertex " << i + 1 << ":";
    cin >> pntX1 >> pntY1;
    pntX.push_back(pntX1);
    pntY.push_back(pntY1);
  }

  if (choice == 1) {
    cout << "Enter the translation factor for x and y:";
    cin >> transX >> transY;
  } else if (choice == 2) {
    cout << "Enter the scaling factor for x and y:";
    cin >> scaleX >> scaleY;
  }
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Extended Basic Transformations");
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();

}
