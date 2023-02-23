#include <GL/glut.h>
void display()
{
    glColor3f(1,1,0); ///黃色
    glutSolidTeapot( 0.5 ); ///畫出實心大茶壺

    glColor3f(0,1,0);///綠色
    glutSolidTeapot( 0.3 ); ///畫出實心小茶壺

    glutSwapBuffers(); ///交換顯示出來
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///GLUT開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///設定GLUT的顯示模式
    glutCreateWindow("Week02");///建視窗名字"Week02
    "
    glutDisplayFunc(display); ///要顯示的對應函示 display()

    glutMainLoop(); ///最後用主要迴圈卡最下面
}
