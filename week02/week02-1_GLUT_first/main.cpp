#include <GL/glut.h>
void display()
{
    glColor3f(1,1,0); ///����
    glutSolidTeapot( 0.5 ); ///�e�X��ߤj����

    glColor3f(0,1,0);///���
    glutSolidTeapot( 0.3 ); ///�e�X��ߤp����

    glutSwapBuffers(); ///�洫��ܥX��
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///GLUT�}�_��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///�]�wGLUT����ܼҦ�
    glutCreateWindow("Week02");///�ص����W�r"Week02
    "
    glutDisplayFunc(display); ///�n��ܪ�������� display()

    glutMainLoop(); ///�̫�ΥD�n�j��d�̤U��
}
