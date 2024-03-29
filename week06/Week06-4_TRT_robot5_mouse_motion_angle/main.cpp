#include <GL/glut.h>
float angle = 0;
void myCube()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02, 30, 30);

    glPushMatrix();///�k
        glTranslatef(0.25, 0, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef( 0.25, 0, 0 );
        myCube();///���u
        glPushMatrix();
        glTranslatef(0.25, 0, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef( 0.25, 0, 0 );
        myCube();///��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///��
        glTranslatef(-0.25, 0, 0);
        glRotatef(-angle, 0, 0, 1);///step04-1
        glTranslatef( -0.25, 0, 0 );
        myCube();///���u
        glPushMatrix();
        glTranslatef(-0.25, 0, 0);
        glRotatef(-angle, 0, 0, 1);///step04-1
        glTranslatef( -0.25, 0, 0 );
        myCube();///��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    ///angle++; step04-2
}
void motion(int x, int y) ///step04-2
{
    angle = x;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06-4");

    glutMotionFunc(motion);///step04-2 mouse motion

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
