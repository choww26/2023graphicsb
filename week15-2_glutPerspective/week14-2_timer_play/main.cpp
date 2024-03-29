#include <GL/glut.h>
float angle=0;
void timer(int t)
{
    glutTimerFunc( 33, timer, t+1);
    angle+=3; /// ����+3
    glutPostRedisplay(); ///���Ƶe
}
void keyboard(unsigned char key, int x, int y) /// step01-2
{
    glutTimerFunc(0, timer, 0); ///step01-2
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutKeyboardFunc(keyboard);
    glutTimerFunc(3000, timer, 0); /// 3000ms = 3sec
    glutDisplayFunc(display);
    glutMainLoop();
}
