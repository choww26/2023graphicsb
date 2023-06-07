#include <stdio.h>
#include <GL/glut.h>
#include "glm.h" ///week13 step02-2
GLMmodel * head =NULL;///week13 step02-2
GLMmodel * body =NULL;///week13 step02-2
GLMmodel * left_arm =NULL;

float teapotX = 0, teapotY = 0;
FILE * fout = NULL;
FILE * fin = NULL;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        if(head==NULL){///week13 step02-2 將模型讀進來
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");
            left_arm = glmReadOBJ("model/left_arm.obj");
            ///glmUnitize(head);
            ///glmUnitize(body);
        }
        glPushMatrix();
            glScalef(0.1,0.1,0.1);
            glmDraw(head, GLM_MATERIAL);///week13 step02-2
            glmDraw(body, GLM_MATERIAL);
            glmDraw(left_arm, GLM_MATERIAL);
        glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y)///step02-2
{
    teapotX += (x - oldX)/150.0;
    teapotX -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutMainLoop();
}
