#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <stdio.h>
#include <GL/glut.h>
#include"CMP3_MCI.h"
#include "glm.h"

CMP3_MCI myMP3;

GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * eye = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * lowarm1 = NULL, * lowarm2 = NULL;
GLMmodel * ear1 = NULL, * ear2 = NULL;

float teapotX = 0, teapotY = 0, oldX = 0, oldY = 0;
float angle[20] = {}, angle2[20] = {};
float NewAngle[20] = {}, NewAngle2[20] = {};
float OldAngle[20] = {}, OldAngle2[20] = {};
int ID = 0, s1, s2, i;
float xa[20] = { 0.0f },ya[20] = { 0.0f };
FILE * fout = NULL;
FILE * fin = NULL;

void timer(int t) {
    printf("現在timer(%d)\n", t);
    glutTimerFunc(20, timer, t+1); ///馬上設定下一個鬧鐘
    float alpha = (t%50) / 50.0; ///0.0 ~ 1.0

    if(t%50==0){
        if(fin == NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i] );
            fscanf(fin, "%f", &NewAngle2[i] );}
    }
    for(int i=0; i<20; i++){
        angle[i] = NewAngle[i] * alpha + OldAngle[i] * (1-alpha);
        angle2[i] = NewAngle2[i] * alpha + OldAngle2[i] * (1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='4') ID = 4;
    if(key=='5') ID = 5;
    if(key=='6') ID = 6;
    if(key=='7') ID = 7;
    if(key=='8') ID = 8;
    if(key=='9') ID = 9;
    if(key=='b') ID = 10;
    if(key=='c') ID = 11;
    switch (key) {
            case 'w':
                for (int i = 0; i < 20; i++) {
                    ya[i] += 0.02f;}break;
            case 's':
                for (int i = 0; i < 20; i++) {
                    ya[i] -= 0.02f;}break;
            case 'a':
                for (int i = 0; i < 20; i++) {
                    xa[i] -= 0.02f;}break;
            case 'd':
                for (int i = 0; i < 20; i++) {
                    xa[i] += 0.02f;}break;
        }
        glutPostRedisplay();
    }
GLuint bg;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
void reshape(int width, int height) {
    /// 設定Viewport為整個視窗大小
    glViewport(0, 0, width, height);

    /// 計算實際顯示的畫面區域
    int displayWidth = width;
    int displayHeight = height;
    if (width > height)displayWidth = height;
    else displayHeight = width;

    /// 設定正交投影矩陣
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    /// 設定視圖矩陣
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /// 計算畫面顯示的區域位置
    int offsetX = (width - displayWidth) / 2;
    int offsetY = (height - displayHeight) / 2;
    glViewport(offsetX, offsetY, displayWidth, displayHeight);
}

void motion(int x, int y) {
    teapotX += (x - oldX) / 150.0 * 10; ///teapotX = (x-150)/150.0;
    teapotY += (oldY - y) / 150.0 * 10; ///teapotY = (150-y)/150.0;
    angle[ID] += x - oldX;
    angle2[ID] += oldY - y;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    printf("  glTranslatef( %.2f, %.2f, 0 ); \n", teapotX, teapotY );
}
void display() {
    printf("10160430－林承美\n");
    glClearColor(0.5f, 0.61f,0.61f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, bg);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex2f(-1, -1);
            glTexCoord2f(1, 0);
            glVertex2f(1, -1);
            glTexCoord2f(1, 1);
            glVertex2f(1, 1);
            glTexCoord2f(0, 1);
            glVertex2f(-1, 1);
        glEnd();
        glDepthRange(0.0, 0.05);
    glPopMatrix();

    glPushMatrix();
        glClear(GL_DEPTH_BUFFER_BIT);
        glScalef(1.0, 1.0, 1.0);
        glTranslatef(0,-0.5,0);///往下一半
        glTranslatef(xa[i], ya[i], 0);
        glBindTexture(GL_TEXTURE_2D,s1);
        glPushMatrix();
            glColor3f(1,1,1);
            glScalef(0.04, 0.04, 0.04);
            glRotatef(angle[0], 0, 1, 0); ///身體的轉動
            glmDraw(body, GLM_MATERIAL|GLM_TEXTURE);

            glPushMatrix();///左腿
                glTranslatef(-0.1, +6.33, 0 );
                glRotatef(angle[10], 0, 1, 0);
                glRotatef(angle2[10], 1, 0, 0);
                glTranslatef( 0.1, -6.33, 0 );
                glmDraw(leg1, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();


            glPushMatrix();///右腿
                glTranslatef(+0.10, +6.33, 0 );
                glRotatef(angle[11], 0, 1, 0);
                glRotatef(angle2[11], 1, 0, 0);
                glTranslatef(-0.10, -6.33, -0.1 );
                glmDraw(leg2, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();///頭

                glTranslatef(0.00, 0.10, -0.3 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef( -0.00, 0.2, 0 );
                glBindTexture(GL_TEXTURE_2D,s1);
                glmDraw(head, GLM_MATERIAL|GLM_TEXTURE);
                glBindTexture(GL_TEXTURE_2D,s2);
                glmDraw(eye, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();///左耳
                    glTranslatef(12.00, +20.53, 0 );
                    ///glRotatef(angle[2], 0, 1, 0);
                    glRotatef(angle2[2], 1, 0, 0);
                    glTranslatef( -11.60, -20.53, 0 );
                    glBindTexture(GL_TEXTURE_2D,s1);
                    glmDraw(ear1, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
                glPushMatrix();///右耳
                    glTranslatef(-12.00, +22.53, 0 );
                   /// glRotatef(angle[3], 0, 1, 0);
                    glRotatef(angle2[3], 1, 0, 0);
                    glTranslatef( 11.60, -22.53, 0 );
                    glmDraw(ear2, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();


            glPushMatrix();///左手
                glPushMatrix();
                    glTranslatef(-2.50, +13.27, 0 );
                    glRotatef(angle[4], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef( 2.50, -13.27, 0 );
                    glmDraw(arm1, GLM_MATERIAL|GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef( -3.50, +13.50, 0 );
                        glRotatef(angle[5], 0, 1, 0);
                        ///glRotatef(angle2[5], 1, 0, 0);
                        glTranslatef( 3.70, -13.50, 0 );
                        glmDraw(lowarm1, GLM_MATERIAL|GLM_TEXTURE);

                        glPushMatrix();
                            glTranslatef(-2.30, +12.1, 0 );
                           /// glRotatef(angle[6], 0, 1, 0);
                            glRotatef(angle2[6], 1, 0, 0);
                            glTranslatef( 2.50, -12.1, 0 );
                            glmDraw(hand1, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///右手
                glPushMatrix();
                    glTranslatef(+2.50, +13.27, 0 );
                    glRotatef(angle[7], 0, 1, 0);
                    glRotatef(angle2[7], 1, 0, 0);
                    glTranslatef(-2.50, -13.27, 0 );
                    glmDraw(arm2, GLM_MATERIAL|GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(+3.50, +13.50, 0 );
                        glRotatef(angle[8], 0, 1, 0);
                        ///glRotatef(angle2[8], 1, 0, 0);
                        glTranslatef(-3.70, -13.50, 0 );
                        glmDraw(lowarm2, GLM_MATERIAL|GLM_TEXTURE);

                        glPushMatrix();
                            glTranslatef(+2.30, +12.10, 0 );
                            ///glRotatef(angle[9], 0, 1, 0);
                            glRotatef(angle2[9], 1, 0, 0);
                            glTranslatef(-2.50, -12.10, 0 );
                            glmDraw(hand2, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(550,550);
    glutCreateWindow("Final");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    eye = glmReadOBJ("model/eye.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    lowarm1 = glmReadOBJ("model/lowarm1.obj");
    lowarm2 = glmReadOBJ("model/lowarm2.obj");
    ear1 = glmReadOBJ("model/ear1.obj");
    ear2 = glmReadOBJ("model/ear2.obj");

    s1=myTexture("model/BODY.png");
    s2=myTexture("model/EYE.png");
    bg=myTexture("bg.png");
    glEnable(GL_DEPTH_TEST);

    char filename[] = "Intro.wav";
    myMP3.Load(filename);
    myMP3.Play();

    glutMainLoop();
}
