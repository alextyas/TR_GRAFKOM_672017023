#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void ukuran(int,int);
void tampil(void);
void hilang(void);
void display(void);
void dasar(void);
void keyboard(unsigned char, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;


void dasar(void)
{
	//Laut
    /*glBegin(GL_QUADS);
    glColor3ub(0, 0, 255);
    glVertex3f(-150.0, -12.0, 50.0);
    glVertex3f(80.0, -12.0, 50.0);
    glVertex3f(80.0, -12.0, -50.0);
    glVertex3f(-150.0, -12.0, -50.0);
    glEnd();*/


    // atas samping kanan
    glBegin(GL_QUADS);
    glColor3ub(254, 240, 245);
    glVertex3f(-75.0,20.0 , -30.0);
    glVertex3f(40.0, 20.0, -30.0);
    glVertex3f(40.0, 0.0, -30.0);
    glVertex3f(-75.0, 0.0, -30.0);
    glEnd();

    //bawah samping kanan
    glBegin(GL_QUADS);
    glColor3ub(250, 99, 71);
    glVertex3f(-75.0,0.0 , -30.0);
    glVertex3f(40.0, 0.0, -30.0);
    glVertex3f(47.0, -12.0, -20.0);
    glVertex3f(-75.0, -12.0, -20.0);
    glEnd();

    // atas belakang
    glBegin(GL_QUADS);
    glColor3ub(175, 238, 239);
    glVertex3f(40.0,0.0 , 30.0);
    glVertex3f(40.0, 20.0, 30.0);
    glVertex3f(40.0, 20.0, -30.0);
    glVertex3f(40.0, 0.0, -30.0);
    glEnd();

     // bawah belakang
    glBegin(GL_QUADS);
    glColor3ub(72, 209, 204);
    glVertex3f(47.0,-12.0 , 20.0);
    glVertex3f(40.0, 0.0, 30.0);
    glVertex3f(40.0, 0.0, -30.0);
    glVertex3f(47.0, -12.0, -20.0);
    glEnd();



    //alas
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, -11.8 , 20.0);
    glVertex3f(47.0, -11.8, 20.0);
    glVertex3f(47.0, -11.8, -20.0);
    glVertex3f(-75.0, -11.8, -20.0);
    glEnd();

    //alas atas
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, 15.0 , 30.0);
    glVertex3f(40.0, 15.0, 30.0);
    glVertex3f(40.0, 15.0, -30.0);
    glVertex3f(-75.0, 15.0, -30.0);
    glEnd();

     //segitiga atas samping kanan
    glBegin(GL_QUADS);
    glColor3ub(245,245,223);
    glVertex3f(-120.0, 20.0 , 0.0);
    glVertex3f(-75.0, 20.0, -30.0);
    glVertex3f(-75.0, 0.0, -30.0);
    glVertex3f(-110.0, 0.0, 0.0);
    glEnd();

    //segitiga bawah samping kanan
    glBegin(GL_QUADS);
    glColor3ub(188, 143, 142);
    glVertex3f(-110.0,0.0 , 0.0);
    glVertex3f(-75.0, 0.0, -30.0);
    glVertex3f(-75.0, -12.0, -20.0);
    glVertex3f(-100.0, -12.0, 0.0);
    glEnd();

    //alas depan segitiga
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, -11.8, 20.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, -11.8, -20.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-100, -11.8, 0.0);
    glEnd();

    //alas depan segitiga
    glBegin(GL_POLYGON);
    glColor3ub(125, 105, 66);
    glVertex3f(-75.0, 15.0, 29.2);
    glColor3ub(105, 105, 55);
    glVertex3f(-75.0, 15.0, -29.2);
    glColor3ub(125, 105, 66);
    glVertex3f(-115, 15.0, 0.0);
    glEnd();


    //alas rufftoop
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-60.0, 55.0 , 22.0);
    glVertex3f(30.0, 55.0, 22.0);
    glVertex3f(30.0, 55.0, -22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-60.0, 55.0 , 22.0);
    glVertex3f(30.0, 55.0, 22.0);
    glVertex3f(30.0, 55.0, -22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();


    //alas lantai
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-60.0, 15.1 , 22.0);
    glVertex3f(30.0, 15.1, 22.0);
    glVertex3f(30.0, 15.1, -22.0);
    glVertex3f(-60.0, 15.1, -22.0);
    glEnd();
     //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-60.0, 15.1 , 22.0);
    glVertex3f(30.0, 15.1, 22.0);
    glVertex3f(30.0, 15.1, -22.0);
    glVertex3f(-60.0, 15.1, -22.0);
    glEnd();


    //alas lantai2
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-60.0, 25.0 , 22.0);
    glVertex3f(30.0, 25.0, 22.0);
    glVertex3f(30.0, 25.0, -22.0);
    glVertex3f(-60.0, 25.0, -22.0);
    glEnd();
     //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-60.0, 25.0 , 22.0);
    glVertex3f(30.0, 25.0, 22.0);
    glVertex3f(30.0, 25.0, -22.0);
    glVertex3f(-60.0, 25.0, -22.0);
    glEnd();


    //alas lantai 3
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-60.0, 35.0 , 22.0);
    glVertex3f(30.0, 35.0, 22.0);
    glVertex3f(30.0, 35.0, -22.0);
    glVertex3f(-60.0, 35.0, -22.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-60.0, 35.0 , 22.0);
    glVertex3f(30.0, 35.0, 22.0);
    glVertex3f(30.0, 35.0, -22.0);
    glVertex3f(-60.0, 35.0, -22.0);
    glEnd();

    //alas lantai 4
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-60.0, 45.0 , 22.0);
    glVertex3f(30.0, 45.0, 22.0);
    glVertex3f(30.0, 45.0, -22.0);
    glVertex3f(-60.0, 45.0, -22.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-60.0, 45.0 , 22.0);
    glVertex3f(30.0, 45.0, 22.0);
    glVertex3f(30.0, 45.0, -22.0);
    glVertex3f(-60.0, 45.0, -22.0);
    glEnd();

    //Ruang bagian atas nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0 , 10.0);
    glVertex3f(-35.0, 62.0, 10.0);
    glVertex3f(-35.0, 62.0, -10.0);
    glVertex3f(-50.0, 62.0, -10.0);
    glEnd();
    //Ruang bagian atas kanan nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0 , -10.0);
    glVertex3f(-35.0, 62.0, -10.0);
    glVertex3f(-35.0, 62.0, -20.0);
    glVertex3f(-45.0, 62.0, -20.0);
    glEnd();
    //Ruang bagian atas kiri nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-35.0, 62.0, 10.0);
    glVertex3f(-35.0, 62.0, 20.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glEnd();
    //Ruang bagian depan nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0 , 10.0);
    glVertex3f(-50.0, 55.0, 10.0);
    glVertex3f(-50.0, 55.0, -10.0);
    glVertex3f(-50.0, 62.0, -10.0);
    glEnd();
    //Ruang bagian depan  kanan nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 55.0 , -10.0);
    glVertex3f(-50.0, 62.0, -10.0);
    glVertex3f(-45.0, 62.0, -20.0);
    glVertex3f(-45.0, 55.0, -20.0);
    glEnd();

    //Ruang bagian depan  kiri nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 55.0 , 10.0);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glVertex3f(-45.0, 55.0, 20.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-50.0, 55.0 , 10.0);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glVertex3f(-45.0, 55.0, 20.0);
    glEnd();

    //Ruang bagian  kiri nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-45.0, 55.0 , 20.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glVertex3f(-35.0, 62.0, 20.0);
    glVertex3f(-35.0, 55.0, 20.0);
    glEnd();
    //Ruang bagian kanan nahkoda
     glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-45.0, 55.0 , -20.0);
    glVertex3f(-45.0, 62.0, -20.0);
    glVertex3f(-35.0, 62.0, -20.0);
    glVertex3f(-35.0, 55.0, -20.0);
    glEnd();
    //Ruang bagian belakang nahkoda
     glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-35.0, 55.0 , 20.0);
    glVertex3f(-35.0, 62.0, 20.0);
    glVertex3f(-35.0, 62.0, -20.0);
    glVertex3f(-35.0, 55.0, -20.0);
    glEnd();




    //rumah kapal 2 tutup belakang
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(30.0, 15.0 , -22.0);
    glVertex3f(30.0, 15.0, 22.0);
    glVertex3f(30.0, 55.0, 22.0);
    glVertex3f(30.0, 55.0, -22.0);
    glEnd();

    //rumah kapal 2 tutup depan
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0 , -22.0);
    glVertex3f(-75.0, 15.0, 22.0);
    glVertex3f(-60.0, 55.0, 22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

     //rumah kapal 2 tutup depan
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0 , -22.0);
    glVertex3f(-75.0, 15.0, 22.0);
    glVertex3f(-60.0, 55.0, 22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

    //rumah kapal 2 tutup kanan
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0 , -22.0);
    glVertex3f(30.0, 15.0, -22.0);
    glVertex3f(30.0, 55.0, -22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 18.0 ,-22.1);
    glVertex3f(28.0, 18.0, -22.1);
    glVertex3f(28.0, 22.0, -22.1);
    glVertex3f(20.0, 22.0, -22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 28.0 ,-22.1);
    glVertex3f(28.0, 28.0, -22.1);
    glVertex3f(28.0, 32.0, -22.1);
    glVertex3f(20.0, 32.0, -22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 38.0 ,-22.1);
    glVertex3f(28.0, 38.0, -22.1);
    glVertex3f(28.0, 42.0, -22.1);
    glVertex3f(20.0, 42.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 48.0 ,-22.1);
    glVertex3f(28.0, 48.0, -22.1);
    glVertex3f(28.0, 52.0, -22.1);
    glVertex3f(20.0, 52.0, -22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 18.0 ,-22.1);
    glVertex3f(16.0, 18.0, -22.1);
    glVertex3f(16.0, 22.0, -22.1);
    glVertex3f(8.0, 22.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 38.0 ,-22.1);
    glVertex3f(16.0, 38.0, -22.1);
    glVertex3f(16.0, 42.0, -22.1);
    glVertex3f(8.0, 42.0, -22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 28.0 ,-22.1);
    glVertex3f(16.0, 28.0, -22.1);
    glVertex3f(16.0, 32.0, -22.1);
    glVertex3f(8.0, 32.0, -22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 48.0 ,-22.1);
    glVertex3f(16.0, 48.0, -22.1);
    glVertex3f(16.0, 52.0, -22.1);
    glVertex3f(8.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 48.0 ,-22.1);
    glVertex3f(-4.0, 48.0, -22.1);
    glVertex3f(-4.0, 52.0, -22.1);
    glVertex3f(4.0, 52.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 18.0 ,-22.1);
    glVertex3f(-4.0, 18.0, -22.1);
    glVertex3f(-4.0, 22.0, -22.1);
    glVertex3f(4.0, 22.0, -22.1);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 28.0 ,-22.1);
    glVertex3f(-4.0, 28.0, -22.1);
    glVertex3f(-4.0, 32.0, -22.1);
    glVertex3f(4.0, 32.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 38.0 ,-22.1);
    glVertex3f(-4.0, 38.0, -22.1);
    glVertex3f(-4.0, 42.0, -22.1);
    glVertex3f(4.0, 42.0, -22.1);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 38.0 ,-22.1);
    glVertex3f(-16.0, 38.0, -22.1);
    glVertex3f(-16.0, 42.0, -22.1);
    glVertex3f(-8.0, 42.0, -22.1);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 28.0 ,-22.1);
    glVertex3f(-16.0, 28.0, -22.1);
    glVertex3f(-16.0, 32.0, -22.1);
    glVertex3f(-8.0, 32.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 18.0 ,-22.1);
    glVertex3f(-16.0, 18.0, -22.1);
    glVertex3f(-16.0, 22.0, -22.1);
    glVertex3f(-8.0, 22.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 48.0 ,-22.1);
    glVertex3f(-16.0, 48.0, -22.1);
    glVertex3f(-16.0, 52.0, -22.1);
    glVertex3f(-8.0, 52.0, -22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 48.0 ,-22.1);
    glVertex3f(-20.0, 48.0, -22.1);
    glVertex3f(-20.0, 52.0, -22.1);
    glVertex3f(-28.0, 52.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 18.0 ,-22.1);
    glVertex3f(-20.0, 18.0, -22.1);
    glVertex3f(-20.0, 22.0, -22.1);
    glVertex3f(-28.0, 22.0, -22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 38.0 ,-22.1);
    glVertex3f(-20.0, 38.0, -22.1);
    glVertex3f(-20.0, 42.0, -22.1);
    glVertex3f(-28.0, 42.0, -22.1);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 28.0 ,-22.1);
    glVertex3f(-20.0, 28.0, -22.1);
    glVertex3f(-20.0, 32.0, -22.1);
    glVertex3f(-28.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 28.0 ,-22.1);
    glVertex3f(-32.0, 28.0, -22.1);
    glVertex3f(-32.0, 32.0, -22.1);
    glVertex3f(-40.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 18.0 ,-22.1);
    glVertex3f(-32.0, 18.0, -22.1);
    glVertex3f(-32.0, 22.0, -22.1);
    glVertex3f(-40.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 38.0 ,-22.1);
    glVertex3f(-32.0, 38.0, -22.1);
    glVertex3f(-32.0, 42.0, -22.1);
    glVertex3f(-40.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 48.0 ,-22.1);
    glVertex3f(-32.0, 48.0, -22.1);
    glVertex3f(-32.0, 52.0, -22.1);
    glVertex3f(-40.0, 52.0, -22.1);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 18.0 ,-22.1);
    glVertex3f(-44.0, 18.0, -22.1);
    glVertex3f(-44.0, 22.0, -22.1);
    glVertex3f(-52.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 38.0 ,-22.1);
    glVertex3f(-44.0, 38.0, -22.1);
    glVertex3f(-44.0, 42.0, -22.1);
    glVertex3f(-52.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 28.0 ,-22.1);
    glVertex3f(-44.0, 28.0, -22.1);
    glVertex3f(-44.0, 32.0, -22.1);
    glVertex3f(-52.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 48.0 ,-22.1);
    glVertex3f(-44.0, 48.0, -22.1);
    glVertex3f(-44.0, 52.0, -22.1);
    glVertex3f(-52.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-61.0, 48.0 ,-22.1);
    glVertex3f(-56.0, 48.0, -22.1);
    glVertex3f(-56.0, 52.0, -22.1);
    glVertex3f(-60.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 18.0 ,-22.1);
    glVertex3f(-56.0, 18.0, -22.1);
    glVertex3f(-56.0, 22.0, -22.1);
    glVertex3f(-64.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 28.0 ,-22.1);
    glVertex3f(-56.0, 28.0, -22.1);
    glVertex3f(-56.0, 32.0, -22.1);
    glVertex3f(-64.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 38.0 ,-22.1);
    glVertex3f(-56.0, 38.0, -22.1);
    glVertex3f(-56.0, 42.0, -22.1);
    glVertex3f(-64.0, 42.0, -22.1);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 18.0 ,-21.9);
    glVertex3f(28.0, 18.0, -21.9);
    glVertex3f(28.0, 22.0, -21.9);
    glVertex3f(20.0, 22.0, -21.9);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 28.0 ,-21.9);
    glVertex3f(28.0, 28.0, -21.9);
    glVertex3f(28.0, 32.0, -21.9);
    glVertex3f(20.0, 32.0, -21.9);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 38.0 ,-21.9);
    glVertex3f(28.0, 38.0, -21.9);
    glVertex3f(28.0, 42.0, -21.9);
    glVertex3f(20.0, 42.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 48.0 ,-21.9);
    glVertex3f(28.0, 48.0, -21.9);
    glVertex3f(28.0, 52.0, -21.9);
    glVertex3f(20.0, 52.0, -21.9);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 18.0 ,-21.9);
    glVertex3f(16.0, 18.0, -21.9);
    glVertex3f(16.0, 22.0, -21.9);
    glVertex3f(8.0, 22.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 38.0 ,-21.9);
    glVertex3f(16.0, 38.0, -21.9);
    glVertex3f(16.0, 42.0, -21.9);
    glVertex3f(8.0, 42.0, -21.9);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 28.0 ,-21.9);
    glVertex3f(16.0, 28.0, -21.9);
    glVertex3f(16.0, 32.0, -21.9);
    glVertex3f(8.0, 32.0, -21.9);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 48.0 ,-21.9);
    glVertex3f(16.0, 48.0, -21.9);
    glVertex3f(16.0, 52.0, -21.9);
    glVertex3f(8.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 48.0 ,-21.9);
    glVertex3f(-4.0, 48.0, -21.9);
    glVertex3f(-4.0, 52.0, -21.9);
    glVertex3f(4.0, 52.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 18.0 ,-21.9);
    glVertex3f(-4.0, 18.0, -21.9);
    glVertex3f(-4.0, 22.0, -21.9);
    glVertex3f(4.0, 22.0, -21.9);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 28.0 ,-21.9);
    glVertex3f(-4.0, 28.0, -21.9);
    glVertex3f(-4.0, 32.0, -21.9);
    glVertex3f(4.0, 32.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 38.0 ,-21.9);
    glVertex3f(-4.0, 38.0, -21.9);
    glVertex3f(-4.0, 42.0, -21.9);
    glVertex3f(4.0, 42.0, -21.9);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 38.0 ,-21.9);
    glVertex3f(-16.0, 38.0, -21.9);
    glVertex3f(-16.0, 42.0, -21.9);
    glVertex3f(-8.0, 42.0,-21.9);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 28.0 ,-21.9);
    glVertex3f(-16.0, 28.0, -21.9);
    glVertex3f(-16.0, 32.0, -21.9);
    glVertex3f(-8.0, 32.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 18.0 ,-21.9);
    glVertex3f(-16.0, 18.0,-21.9);
    glVertex3f(-16.0, 22.0,-21.9);
    glVertex3f(-8.0, 22.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 48.0 ,-21.9);
    glVertex3f(-16.0, 48.0, -21.9);
    glVertex3f(-16.0, 52.0, -21.9);
    glVertex3f(-8.0, 52.0, -21.9);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 48.0 ,-21.9);
    glVertex3f(-20.0, 48.0, -21.9);
    glVertex3f(-20.0, 52.0, -21.9);
    glVertex3f(-28.0, 52.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 18.0 ,-21.9);
    glVertex3f(-20.0, 18.0, -21.9);
    glVertex3f(-20.0, 22.0, -21.9);
    glVertex3f(-28.0, 22.0, -21.9);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 38.0 ,-21.9);
    glVertex3f(-20.0, 38.0, -21.9);
    glVertex3f(-20.0, 42.0, -21.9);
    glVertex3f(-28.0, 42.0, -21.9);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 28.0 ,-21.9);
    glVertex3f(-20.0, 28.0, -21.9);
    glVertex3f(-20.0, 32.0, -21.9);
    glVertex3f(-28.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 28.0 ,-21.9);
    glVertex3f(-32.0, 28.0, -21.9);
    glVertex3f(-32.0, 32.0, -21.9);
    glVertex3f(-40.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 18.0 ,-21.9);
    glVertex3f(-32.0, 18.0, -21.9);
    glVertex3f(-32.0, 22.0, -21.9);
    glVertex3f(-40.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 38.0 ,-21.9);
    glVertex3f(-32.0, 38.0, -21.9);
    glVertex3f(-32.0, 42.0, -21.9);
    glVertex3f(-40.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 48.0 ,-21.9);
    glVertex3f(-32.0, 48.0, -21.9);
    glVertex3f(-32.0, 52.0, -21.9);
    glVertex3f(-40.0, 52.0, -21.9);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 18.0 ,-21.9);
    glVertex3f(-44.0, 18.0, -21.9);
    glVertex3f(-44.0, 22.0, -21.9);
    glVertex3f(-52.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 38.0 ,-21.9);
    glVertex3f(-44.0, 38.0,-21.9);
    glVertex3f(-44.0, 42.0, -21.9);
    glVertex3f(-52.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 28.0 ,-21.9);
    glVertex3f(-44.0, 28.0, -21.9);
    glVertex3f(-44.0, 32.0, -21.9);
    glVertex3f(-52.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 48.0 ,-21.9);
    glVertex3f(-44.0, 48.0, -21.9);
    glVertex3f(-44.0, 52.0, -21.9);
    glVertex3f(-52.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-61.0, 48.0 ,-21.9);
    glVertex3f(-56.0, 48.0, -21.9);
    glVertex3f(-56.0, 52.0, -21.9);
    glVertex3f(-60.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 18.0 ,-21.9);
    glVertex3f(-56.0, 18.0, -21.9);
    glVertex3f(-56.0, 22.0, -21.9);
    glVertex3f(-64.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 28.0 ,-21.9);
    glVertex3f(-56.0, 28.0, -21.9);
    glVertex3f(-56.0, 32.0, -21.9);
    glVertex3f(-64.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 38.0 ,-21.9);
    glVertex3f(-56.0, 38.0, -21.9);
    glVertex3f(-56.0, 42.0, -21.9);
    glVertex3f(-64.0, 42.0, -21.9);
    glEnd();

}

void kapal_transparan(void)
{
    //rumah kapal tutup kiri
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0 , 22.0);
    glVertex3f(30.0, 15.0, 22.0);
    glVertex3f(30.0, 55.0, 22.0);
    glVertex3f(-60.0, 55.0, 22.0);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 18.0 ,22.1);
    glVertex3f(28.0, 18.0, 22.1);
    glVertex3f(28.0, 22.0, 22.1);
    glVertex3f(20.0, 22.0, 22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 28.0 ,22.1);
    glVertex3f(28.0, 28.0, 22.1);
    glVertex3f(28.0, 32.0, 22.1);
    glVertex3f(20.0, 32.0, 22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 38.0 ,22.1);
    glVertex3f(28.0, 38.0, 22.1);
    glVertex3f(28.0, 42.0, 22.1);
    glVertex3f(20.0, 42.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 48.0 ,22.1);
    glVertex3f(28.0, 48.0, 22.1);
    glVertex3f(28.0, 52.0, 22.1);
    glVertex3f(20.0, 52.0, 22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 18.0 ,22.1);
    glVertex3f(16.0, 18.0, 22.1);
    glVertex3f(16.0, 22.0, 22.1);
    glVertex3f(8.0, 22.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 38.0 ,22.1);
    glVertex3f(16.0, 38.0, 22.1);
    glVertex3f(16.0, 42.0, 22.1);
    glVertex3f(8.0, 42.0, 22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 28.0 ,22.1);
    glVertex3f(16.0, 28.0, 22.1);
    glVertex3f(16.0, 32.0, 22.1);
    glVertex3f(8.0, 32.0, 22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.0, 48.0 ,22.1);
    glVertex3f(16.0, 48.0, 22.1);
    glVertex3f(16.0, 52.0, 22.1);
    glVertex3f(8.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 48.0 ,22.1);
    glVertex3f(-4.0, 48.0, 22.1);
    glVertex3f(-4.0, 52.0, 22.1);
    glVertex3f(4.0, 52.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 18.0 ,22.1);
    glVertex3f(-4.0, 18.0, 22.1);
    glVertex3f(-4.0, 22.0, 22.1);
    glVertex3f(4.0, 22.0, 22.1);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 28.0 ,22.1);
    glVertex3f(-4.0, 28.0, 22.1);
    glVertex3f(-4.0, 32.0, 22.1);
    glVertex3f(4.0, 32.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.0, 38.0 ,22.1);
    glVertex3f(-4.0, 38.0, 22.1);
    glVertex3f(-4.0, 42.0, 22.1);
    glVertex3f(4.0, 42.0, 22.1);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 38.0 ,22.1);
    glVertex3f(-16.0, 38.0, 22.1);
    glVertex3f(-16.0, 42.0, 22.1);
    glVertex3f(-8.0, 42.0, 22.1);
    glEnd();
 //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 28.0 ,22.1);
    glVertex3f(-16.0, 28.0, 22.1);
    glVertex3f(-16.0, 32.0, 22.1);
    glVertex3f(-8.0, 32.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 18.0 ,22.1);
    glVertex3f(-16.0, 18.0, 22.1);
    glVertex3f(-16.0, 22.0, 22.1);
    glVertex3f(-8.0, 22.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-8.0, 48.0 ,22.1);
    glVertex3f(-16.0, 48.0, 22.1);
    glVertex3f(-16.0, 52.0, 22.1);
    glVertex3f(-8.0, 52.0, 22.1);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 48.0 ,22.1);
    glVertex3f(-20.0, 48.0, 22.1);
    glVertex3f(-20.0, 52.0, 22.1);
    glVertex3f(-28.0, 52.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 18.0 ,22.1);
    glVertex3f(-20.0, 18.0, 22.1);
    glVertex3f(-20.0, 22.0, 22.1);
    glVertex3f(-28.0, 22.0, 22.1);
    glEnd();
     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 38.0 ,22.1);
    glVertex3f(-20.0, 38.0, 22.1);
    glVertex3f(-20.0, 42.0, 22.1);
    glVertex3f(-28.0, 42.0, 22.1);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 28.0 ,22.1);
    glVertex3f(-20.0, 28.0, 22.1);
    glVertex3f(-20.0, 32.0, 22.1);
    glVertex3f(-28.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 28.0 ,22.1);
    glVertex3f(-32.0, 28.0, 22.1);
    glVertex3f(-32.0, 32.0, 22.1);
    glVertex3f(-40.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 18.0 ,22.1);
    glVertex3f(-32.0, 18.0, 22.1);
    glVertex3f(-32.0, 22.0, 22.1);
    glVertex3f(-40.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 38.0 ,22.1);
    glVertex3f(-32.0, 38.0, 22.1);
    glVertex3f(-32.0, 42.0, 22.1);
    glVertex3f(-40.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 48.0 ,22.1);
    glVertex3f(-32.0, 48.0, 22.1);
    glVertex3f(-32.0, 52.0, 22.1);
    glVertex3f(-40.0, 52.0, 22.1);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 18.0 ,22.1);
    glVertex3f(-44.0, 18.0, 22.1);
    glVertex3f(-44.0, 22.0, 22.1);
    glVertex3f(-52.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 38.0 ,22.1);
    glVertex3f(-44.0, 38.0, 22.1);
    glVertex3f(-44.0, 42.0, 22.1);
    glVertex3f(-52.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 28.0 ,22.1);
    glVertex3f(-44.0, 28.0, 22.1);
    glVertex3f(-44.0, 32.0, 22.1);
    glVertex3f(-52.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-52.0, 48.0 ,22.1);
    glVertex3f(-44.0, 48.0, 22.1);
    glVertex3f(-44.0, 52.0, 22.1);
    glVertex3f(-52.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-61.0, 48.0 ,22.1);
    glVertex3f(-56.0, 48.0, 22.1);
    glVertex3f(-56.0, 52.0, 22.1);
    glVertex3f(-60.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 18.0 ,22.1);
    glVertex3f(-56.0, 18.0, 22.1);
    glVertex3f(-56.0, 22.0, 22.1);
    glVertex3f(-64.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 28.0 ,22.1);
    glVertex3f(-56.0, 28.0, 22.1);
    glVertex3f(-56.0, 32.0, 22.1);
    glVertex3f(-64.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-64.0, 38.0 ,22.1);
    glVertex3f(-56.0, 38.0, 22.1);
    glVertex3f(-56.0, 42.0, 22.1);
    glVertex3f(-64.0, 42.0, 22.1);
    glEnd();

  //atas samping kiri
    glBegin(GL_QUADS);
    glColor3ub(254, 240, 245);
    glVertex3f(-75.0,20.0 , 30.0);
    glVertex3f(40.0, 20.0, 30.0);
    glVertex3f(40.0, 0.0, 30.0);
    glVertex3f(-75.0, 0.0, 30.0);
    glEnd();

    //bawah sampin kiri
    glBegin(GL_QUADS);
    glColor3ub(250, 99, 71);
    glVertex3f(-75.0,0.0 , 30.0);
    glVertex3f(40.0, 0.0, 30.0);
    glVertex3f(47.0, -12.0, 20.0);
    glVertex3f(-75.0, -12.0, 20.0);
    glEnd();


    //segitiga atas samping kiri
    glBegin(GL_QUADS);
    glColor3ub(245,245,223);
    glVertex3f(-120.0,20.0 , 0.0);
    glVertex3f(-75.0, 20.0, 30.0);
    glVertex3f(-75.0, 0.0, 30.0);
    glVertex3f(-110.0, 0.0, 0.0);
    glEnd();

    //segitiga bawah samping kiri
    glBegin(GL_QUADS);
    glColor3ub(188, 143, 142);
    glVertex3f(-110.0,0.0 , 0.0);
    glVertex3f(-75.0, 0.0, 30.0);
    glVertex3f(-75.0, -12.0, 20.0);
    glVertex3f(-100.0, -12.0, 0.0);
    glEnd();
}

void hilang(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    dasar();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    kapal_transparan();
    dasar();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void display(void)
{
    if (is_depth)
        tampil();
    else
        hilang();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case'w':
        case'W' :
            glTranslatef(0.0, 0.0, 3.0);
            break;
        case'd':
        case'D':
            glTranslatef(-3.0, 0.0, 0.0);
            break;
        case's':
        case'S':
            glTranslatef(0.0, 0.0, -3.0);
            break;
        case'a':
        case'A':
            glTranslatef(3.0, 0.0, 0.0);
            break;
        case'7':
            glTranslatef(0.0, 3.0, 0.0);
            break;
        case'9':
            glTranslatef(0.0, -3.0, 0.0);
            break;
        case'2':
            glRotatef(2.0, 1.0, 0.0, 0.0);
            break;
        case'8':
            glRotatef(-2.0, 1.0, 0.0, 0.0);
            break;
        case'6':
            glRotatef(2.0, 0.0, 1.0, 0.0);
            break;
        case'4':
            glRotatef(-2.0, 0.0, 1.0, 0.0);
            break;
        case'1':
            glRotatef(2.0, 0.0, 0.0, 1.0);
            break;
        case'3':
            glRotatef(-2.0, 0.0, 0.0, 1.0);
            break;
        case'5':
            if(is_depth)
            {
                is_depth = 0;
                tampil();
            }
            else
            {
                is_depth = 1;
                hilang();
            }
            break;
    }
    display();
}

void idle()
{
    if (!mouseDown)
    {
        xrot == 0.3f;
        yrot == 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void ok()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void mouseMotion(int x, int y)
{
    ok();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(30.5, -30.0, -170.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.5f);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1350,1150);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TR Grafkom");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
