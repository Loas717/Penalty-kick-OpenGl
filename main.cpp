#ifdef APPLE
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
//#include <math.h>
float alpha = 0;
float beta = 0;
float delta = 1;
float rectMinX = -3.0f;
float rectMaxX = 3.0f;
float rectMinY = -0.9f;
float rectMaxY = 4.0f;
float rectZ = -5.0f;
float sphereX = 0.0f;
float sphereY = -1.0f;
float sphereZ = 0.0f;
float x1 = 1.0;
float y1 = 1.0;
float z1 = 1.0;
float animationSpeed = -0.0f;
bool animation = true, fstexec = true, inside=false, mov=false, moveSphere = false, cubeMovingRight = true;
float t = 0.0f;
float bola_z = 3, bola_x = 0, bola_y = 0.4;
int chutes = 0, numgol = 0, erros = 0;
float cubeX = 0.0f;
float cubeZ=-8.0;
float cubeSpeed = 0.1f;
GLfloat windowWidth;
GLfloat windowHeight;
void init();
void DesenhaTexto(void *font, char *string);
void desenhaCuboGOL(float x, float y, float z);
void desenhaGol();
void display();
void Verifica_Gol();
void listeningSpKey (GLint tecla,
GLint x, GLint y);
void voltaValor(int value);
void cubeTimer(int value);
void Timer(int value);
void keyboard(unsigned char key, int x, int y);


int main(int argc, char **argv)
{
//cubeSpeed = 0.1f;
cubeMovingRight = true;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition(100, 100);
glutInitWindowSize(800, 600);
glutCreateWindow("SUPER GLUT BALL");
gluOrtho2D(0.0, 400, 0.0, 600);
init();
glutKeyboardFunc(keyboard);
glutSpecialFunc(listeningSpKey);
glutDisplayFunc(display);
glClear(GL_COLOR_BUFFER_BIT);
glEnable(GL_NORMALIZE);
//glutTimerFunc(600,Timer,0);
glutTimerFunc(0,cubeTimer,0);
glutMainLoop();
}

void init() {
glClearColor(0, 0, 0, 0);
glEnable(GL_DEPTH_TEST);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-10, 10, -10, 10, -10, 10);
}


void DesenhaTexto(void *font, char *string) {
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);
}
void desenhaCuboGOL(float x, float y, float z) {
    glPushMatrix();
    glTranslated(x, y, z);
    glutSolidCube(1.0f);
    glPopMatrix();
}
void desenhaGol(){
    if(inside==true){
        //G
        glColor3f(1.0, 1.0, 0.0);
        desenhaCuboGOL(0.0, 2.0, 1.0);
        desenhaCuboGOL(1.0, 2.0, 1.0);
        desenhaCuboGOL(0.0, 1.5, 1.0);
        desenhaCuboGOL(0.0, 1.0, 1.0);
        desenhaCuboGOL(1.0, 0.5, 1.0);
        desenhaCuboGOL(0.0, 0.5, 1.0);
        desenhaCuboGOL(1.0, 0.0, 1.0);
        desenhaCuboGOL(0.0, 0.0, 1.0);

        //O
        desenhaCuboGOL(2.5, 2.0, 1.0);
        desenhaCuboGOL(3.5, 2.0, 1.0);
        desenhaCuboGOL(3.5, 1.0, 1.0);
        desenhaCuboGOL(2.5, 0.0, 1.0);
        desenhaCuboGOL(2.5, 1.0, 1.0);
        desenhaCuboGOL(3.5, 0.0, 1.0);

        //L
        desenhaCuboGOL(5.0, 2.0, 1.0);
        desenhaCuboGOL(5.0, 0.0, 1.0);
        desenhaCuboGOL(5.0, 1.0, 1.0);
        desenhaCuboGOL(6.0, 0.0, 1.0);
    }
}
void display() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(17, 1, 0, 0);
glRotatef(beta, 0, 1, 0);
glRotatef(alpha, 1, 0, 0);
glScalef(delta, delta, delta);
glColor3f(1, 1, 1);

glPushMatrix();
 glTranslatef(0,-0.7,2);
 glTranslatef(bola_x, bola_y, bola_z);
glutSolidSphere(0.5f, 40, 20);
glPopMatrix();
glPushMatrix();
//cube
    glTranslatef(0, 1, 0.5);
    glTranslatef(cubeX, -1, -5);
    glScalef(1.0f, 3.0f, 1.0f);
    glutSolidCube(1.0f);
glPopMatrix();
glPushMatrix();
//cube
    glColor3f(1.0f, 0.71f, 0.76f);
    glTranslatef(0, 3, 0.5);
    glTranslatef(cubeX, -1, -5);
    glScalef(1.0f, 1.0f, 1.0f);
    glutSolidCube(1.0f);
glPopMatrix();
glColor3d(1,1,1);
glLineWidth(5);
glBegin(GL_LINES);
    glVertex3f(3,-0.9,-5);
    glVertex3f(3,4,-5);
    //
    glVertex3f(3,4,-5);
    glVertex3f(-3,4,-5);
    //
    glVertex3f(-3,-0.9,-5);
    glVertex3f(-3,4,-5);
    //
    //glLineWidth(14);
    glVertex3f(6,-0.8,-5);
    glVertex3f(-6,-0.8,-5);
    //
    glVertex3f(-3.5,-0.8,-5);
    glVertex3f(-3.5,-0.8,-2);
    //
    glVertex3f(3.5,-0.8,-5);
    glVertex3f(3.5,-0.8,-2);
    //
    glVertex3f(-3.5,-0.8,-2);
    glVertex3f(3.5,-0.8,-2);
    //
    glVertex3f(3,4,-5);
    glVertex3f(3,4,-6);
    //
    glVertex3f(-3,4,-5);
    glVertex3f(-3,4,-6);
    //
    glVertex3f(-3,4,-6);
    glVertex3f(3,4,-6);
    //
    glVertex3f(-3,4,-6);
    glVertex3f(-3,-0.9,-8);
    //
    glVertex3f(3,4,-6);
    glVertex3f(3,-0.9,-8);
    //
    glVertex3f(-3,-0.9,-8);
    glVertex3f(3,-0.9,-8);
    //
    glVertex3f(-3,-0.8,-5);
    glVertex3f(-3,-0.8,-8);
    //
    glVertex3f(3,-0.8,-5);
    glVertex3f(3,-0.8,-8);
    //
    /*glVertex3f(-3,-0.3,-5);
    glVertex3f(-3,-0.3,-7.8);*/
    //
    /*glVertex3f(-3,0.2,-5);
    glVertex3f(-3,0.2,-7.6);*/
glEnd();


glPushMatrix();
        char numgol_str[100],erros_str[100], chutes_str[100];
            sprintf(numgol_str, "%d", numgol);
            sprintf(erros_str, "%d", erros);
            sprintf(chutes_str, "%d", chutes);
        float z = -1.5, scale_factor = 0.02;
        glColor3f(0.1, 0.5, 0.9);
        glRasterPos3d(-6, 5,z);
            DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "CHUTES -> ");
        glRasterPos3d(-3.9, 5, z);
            DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, chutes_str);

        glRasterPos3d(-6, 4,z);
            DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "GOLS -> ");
        glRasterPos3d(-4.4, 4, z);
            DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, numgol_str);

        glRasterPos3d(-6, 3,z);
            DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "ERROS -> ");
        glRasterPos3d(-4.1, 3, z);
            DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, erros_str);
    desenhaGol();
    glPopMatrix();
glTranslatef(0, -1, 0);
glScalef(4, 0.1f, 5.3);
glColor3f(0, 1, 0);
//glLoadIdentity();
glutSolidCube(3.0f);
glutSwapBuffers();
}



void Verifica_Gol(){
    if(bola_z<=-8){
       animation = false;
         if(bola_x<-3 || bola_x>3){
            chutes ++; printf("CHUTES %d\n", chutes);
            printf("TES %f\n", bola_z);
            animation = false, mov = false;
            erros ++;
            printf("erros %d\n", erros);
         }
         if ((bola_x<=cubeX+0.5&&bola_x>=cubeX-0.5)||(bola_x+0.25<=cubeX&&bola_x+0.25>=cubeX)){
            numgol=numgol;
            chutes ++; printf("CHUTES %d\n", chutes);
            animation = false, mov = false;
            erros ++;
            printf("erros %d\n", erros);
         }else {if(bola_x>=-2.5 && bola_x<=2.5){
                inside=true;
            animation = false, mov = false, inside = true;
            printf("TES %f\n", bola_z);
            printf("ballx %f\n", bola_x);
                        printf("cubex %f\n", cubeX);
            chutes ++; printf("CHUTES %d\n", chutes);
            numgol ++; printf("GOLS %d\n", numgol);
        }}
    }
}


void listeningSpKey (GLint tecla,
GLint x, GLint y) {
switch(tecla) {
case GLUT_KEY_UP:
alpha = alpha - 1;
break;
case GLUT_KEY_DOWN:
alpha = alpha + 1;
break;
case GLUT_KEY_LEFT:
beta = beta + 1;
break;
case GLUT_KEY_RIGHT:
beta = beta - 1;
break;
}
glutPostRedisplay();
}

void voltaValor(int value){

animation = true; fstexec = true;inside=false;
x1 = 1.0;
y1 = 1.0;
z1 = 1.0;
bola_z = 3;
bola_x = 0;
bola_y = 0.4;
glutPostRedisplay();
}
void cubeTimer(int value){
    if (cubeMovingRight) {
        cubeX += cubeSpeed;
        if (cubeX > 3.0f) {
            cubeX = 3.0f;
            cubeMovingRight = false;
        }
    } else {
        cubeX -= cubeSpeed;
        if (cubeX < -3.0f) {
            cubeX = -3.0f;
            cubeMovingRight = true;
        }
    }
      glutPostRedisplay();
    glutTimerFunc(16, cubeTimer, 0);
}

void Timer(int value)
{

    if (animation) {
        bola_z -= 0.2;
        Verifica_Gol();

        glutPostRedisplay();
    }
    if(!animation){
        glutTimerFunc(600,voltaValor,0);
        return;
    }
    glutTimerFunc(16, Timer, 0);
}

void restart(){
    alpha = 0;
    beta = 0;
    delta = 1;
    x1 = 1.0;
    y1 = 1.0;
    z1 = 1.0;
    bola_z = 3, bola_x = 0, bola_y = 0.4;

    chutes = 0, numgol = 0, erros = 0;

    animation = false, fstexec = true, inside = false, mov = false;
}

void keyboard(unsigned char key, int x, int y)
{
if(key == 'q')
delta = delta * 1.1f;
if(key == 'w')
delta = delta * 0.9f;
if(key=='b'){
//left=true;
//printf("%d", left);
}
if(key == ' ')
    if(fstexec == true){
        fstexec = false;
        glutTimerFunc(0,Timer,0);
    }
    if (key == 'c')
    {
        system("C:/Users/T-Gamer/Desktop/tettet/trabalho_glut.exe");
    }
    if (key == 'h')
    {
        bola_x-=0.3;
        if(bola_x<=-5.0){
            bola_x=4.9;
        }
    }
     if (key == 'j')
    {
        bola_x+=0.3;
        if(bola_x>=5.0){
            bola_x=-4.9;
        }
    }
    if (key == 'r')
    {
        restart();
    }
    if (key == 27)
    {
        exit(0);
    }
glutPostRedisplay();
}
