#include <GL/glut.h>
float angle=0, newAngle=0, oldAngle=0; ///step02-2 宣告新舊角度
float oldX = 0; ///舊的X座標
void timer(int t)
{
    if(t<100)glutTimerFunc( 33, timer, t+1);
    float alpha = t/100.0;
    angle = alpha*newAngle + (1-alpha)*oldAngle; /// 公式
    glutPostRedisplay(); ///重複畫
}
void keyboard(unsigned char key, int x, int y) /// step01-2
{
    glutTimerFunc(0, timer, 0); ///step01-2
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN) oldAngle = angle;
    if(state==GLUT_UP) newAngle = angle;
    oldX = x;
    glutPostRedisplay();
}
void motion(int x, int y)
{
    angle += x=oldX;
    oldX = x;
    glutPostRedisplay();
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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutTimerFunc(3000, timer, 0); /// 3000ms = 3sec
    glutDisplayFunc(display);
    glutMainLoop();
}
