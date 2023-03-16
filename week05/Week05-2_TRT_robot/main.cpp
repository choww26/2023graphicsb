#include <GL/glut.h>
float angle=0;
void myCube()///step2 ��禡
{
     glPushMatrix();
        glScalef(0.5, 0.2, 0.2);
        glutSolidCube(1); ///step1���
     glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);
    glutSolidCube(1);///step4����

    glPushMatrix();
        glTranslatef(0.5,0.5,0);///step5���`����k�W��
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.25, 0, 0);///step3�����`�b����
        glColor3f(0,1,0);///step4��⪺
        myCube();///step2
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,0.5,0);///step5���`���쥪�W��
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.25, 0, 0);///step3�����`�b����
        glColor3f(0,1,0);///step4��⪺
        myCube();///step2
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}

int main(int argc,char* argv[])
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05-2");

    glutDisplayFunc(display);

    glutIdleFunc(display);
    glutMainLoop();

}
