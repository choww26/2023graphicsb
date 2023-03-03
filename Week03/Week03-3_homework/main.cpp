#include <GL/glut.h>
#include <stdio.h>
float X=0, Y=0, Z=0;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.16,0.49);glVertex2f(-0.19,0.54);
glVertex2f(-0.14,0.59);glVertex2f(-0.09,0.59);glVertex2f(-0.09,0.63);glVertex2f(-0.08,0.67);
glVertex2f(-0.06,0.63);glVertex2f(-0.03,0.59);glVertex2f(0.01,0.55);glVertex2f(0.07,0.52);
glVertex2f(0.13,0.51);glVertex2f(0.11,0.46);glVertex2f(0.07,0.43);glVertex2f(0.17,0.40);
glVertex2f(0.25,0.33);glVertex2f(0.32,0.25);glVertex2f(0.27,0.21);glVertex2f(0.18,0.19);
glVertex2f(0.11,0.23);glVertex2f(0.04,0.26);glVertex2f(0.04,0.26);glVertex2f(0.06,0.19);
glVertex2f(-0.01,0.13);glVertex2f(-0.11,0.09);glVertex2f(-0.27,0.07);glVertex2f(-0.35,0.10);
glVertex2f(-0.47,0.13);glVertex2f(-0.41,0.23);glVertex2f(-0.37,0.27);glVertex2f(-0.46,0.21);
glVertex2f(-0.57,0.19);glVertex2f(-0.55,0.28);glVertex2f(-0.48,0.37);glVertex2f(-0.39,0.39);

    glEnd();
    glutSwapBuffers();

}
void mouse(int button, int state, int x, int y)
{
    X=(x-150)/150.0;
    Y=-(y-150)/150.0;
    if(state==GLUT_DOWN)printf("glVertex2f(%.2f,%.2f);\n", X, Y);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Week03-3");
    glutMouseFunc(mouse);
    glutDisplayFunc(display);

    glutMainLoop();
}
