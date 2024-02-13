/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <time.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>


float bx = 10;
float moonX = 100; // x-coordinate of the moon
float moonSpeed = 0.001;

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy){
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 360; i++){
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }

    glEnd();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            bx += 0.91;
            break;

        case '-':
            bx -= 1;
            break;
    }

    glutPostRedisplay();
}

void tower() {


    glPushMatrix();  // Push the current matrix state

    glTranslatef(175, 380, 0);  // Translate to the center of the tower

    // Draw the circle
    glColor3f(1, 1, 1);  // White background
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(45 * cos(angle), 45 * sin(angle));  // Scale the circle radius to 50
    }
    glEnd();

    // Clock hands
    time_t now = time(0);
    struct tm* local_time = localtime(&now);
    int hours = local_time->tm_hour % 12;
    int minutes = local_time->tm_min;
    int seconds = local_time->tm_sec;

    glColor3f(0, 0, 1);  // Blue for seconds
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(41 * sin(seconds * 6 * 3.14159 / 180),
               41 * cos(seconds * 6 * 3.14159 / 180));  // Scale the line length to 75
    glEnd();

    glColor3f(0, 1, 0);  // Green for minutes
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(30 * sin(minutes * 6 * 3.14159 / 180),
               30 * cos(minutes * 6 * 3.14159 / 180));  // Scale the line length to 50
    glEnd();

    glColor3f(1, 0, 0);  // Red for hours
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(20 * sin((hours * 30 + minutes / 2.0) * 3.14159 / 180),
               20 * cos((hours * 30 + minutes / 2.0) * 3.14159 / 180));  // Scale the line length to 30
    glEnd();

    glPopMatrix();  // Restore the previous matrix state
}


void moon(GLfloat rx ,GLfloat cx, GLfloat cy){
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 360; i++){
        float angle = i * 3.1416 / 180;
        float x = rx * sin(angle);
        float y = rx * cos(angle);
        glVertex2f((x + cx), (y + cy));
    }

    glEnd();
}



void init(void){
    glClearColor(0.0, 0.0, 0.2, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500);
}





void hills() {

    // Hill 3 (triangle)
    glColor3ub(139, 99, 19);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 300);
    glVertex2d(200, 300);
    glVertex2d(100, 450);
    glEnd();

     //Hill2
    glColor3ub(139, 69, 19);  // Darker brown color
    glBegin(GL_POLYGON);
    glVertex2d(150, 300);
    glVertex2d(350, 300);
    glVertex2d(250, 450);
    glEnd();

    //Hill3
    glColor3ub(139, 69, 15);
    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(520, 300);
    glVertex2d(450, 450);
    glEnd();

    //Behind Road
    glColor3ub(0,100,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,150);
    glVertex2d(500,150);
    glVertex2d(500, 300);
    glVertex2d(0, 300);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 200);
    glVertex2d(500, 200);
    glVertex2d(500, 260);
    glVertex2d(0, 260);
    glEnd();

    // Hill 1 (rectangle)
     glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 150);
    glVertex2d(100, 150);
    glVertex2d(100, 430);  // Added fourth vertex for rectangle
    glVertex2d(-40, 430);
    glEnd();


//

    glColor3ub(180, 59, 20);
    glBegin(GL_POLYGON);
    glVertex2d(220, 420);
    glVertex2d(130, 420);
    glVertex2d(175,500);  // Changed vertex order to form a triangle
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(130, 420);
    glVertex2d(220, 420);
    glVertex2d(220, 150);
    glVertex2d(130, 150);
    glEnd();

    glColor3ub(255, 255, 255); // White color

// First window
glBegin(GL_POLYGON);
glVertex2d(140, 320);
glVertex2d(165, 320);
glVertex2d(165, 290);
glVertex2d(140, 290);
glEnd();

// Second window
glBegin(GL_POLYGON);
glVertex2d(185, 320);
glVertex2d(210, 320);
glVertex2d(210, 290);
glVertex2d(185, 290);
glEnd();

// Third window
glBegin(GL_POLYGON);
glVertex2d(140, 250);
glVertex2d(165, 250);
glVertex2d(165, 280);
glVertex2d(140, 280);
glEnd();

// Fourth window
glBegin(GL_POLYGON);
glVertex2d(185, 250);
glVertex2d(210, 250);
glVertex2d(210, 280);
glVertex2d(185, 280);
glEnd();

// Fifth window
glBegin(GL_POLYGON);
glVertex2d(140, 240);
glVertex2d(165, 240);
glVertex2d(165, 210);
glVertex2d(140, 210);
glEnd();

// Sixth window
glBegin(GL_POLYGON);
glVertex2d(185, 240);
glVertex2d(210, 240);
glVertex2d(210, 210);
glVertex2d(185, 210);
glEnd();




    glColor3f(0.4f, 0.4f, 0.4f);

// Building polygon
glBegin(GL_POLYGON);
glVertex2d(240, 280);
glVertex2d(340, 280);
glVertex2d(340, 450);
glVertex2d(240, 450);
glEnd();

// Window color
glColor3ub(255, 255, 255); // White color

// First window
glBegin(GL_POLYGON);
glVertex2d(250, 400);
glVertex2d(280, 400);
glVertex2d(280, 370);
glVertex2d(250, 370);
glEnd();

// Second window
glBegin(GL_POLYGON);
glVertex2d(300, 400);
glVertex2d(330, 400);
glVertex2d(330, 370);
glVertex2d(300, 370);
glEnd();

// Third window
glBegin(GL_POLYGON);
glVertex2d(250, 360);
glVertex2d(280, 360);
glVertex2d(280, 330);
glVertex2d(250, 330);
glEnd();

// Fourth window
glBegin(GL_POLYGON);
glVertex2d(300, 360);
glVertex2d(330, 360);
glVertex2d(330, 330);
glVertex2d(300, 330);
glEnd();

// Third window
glBegin(GL_POLYGON);
glVertex2d(250, 320);
glVertex2d(280, 320);
glVertex2d(280, 290);
glVertex2d(250, 290);
glEnd();

// Fourth window
glBegin(GL_POLYGON);
glVertex2d(300, 320);
glVertex2d(330, 320);
glVertex2d(330, 290);
glVertex2d(300, 290);
glEnd();


    // Hill 3 (rectangle)
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POLYGON);
    glVertex2d(355, 150);
    glVertex2d(450, 150);
    glVertex2d(450, 440);  // Added fourth vertex for rectangle
    glVertex2d(355, 440);
    glEnd();

}



void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //Ground Color

    glColor3ub(0, 100, 0);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(500,0);
    glVertex2d(500, 150);
    glVertex2d(0, 150);
    glEnd();

    //Road

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2d(0,55);
    glVertex2d(500,55);
    glVertex2d(500, 115);
    glVertex2d(0, 115);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(0,60);
    glVertex2d(500,60);
    glVertex2d(500, 110);
    glVertex2d(0, 110);
    glEnd();

    glColor3ub(255, 255, 252);
    moon(20,moonX,450);
    //hills
    hills();

    tower();
    glPushMatrix();
    glTranslatef(moonX, 0, 0);

    glColor3ub(22, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(410,100);
    glVertex2d(490, 100);
    glVertex2d(485, 130);
    glVertex2d(410, 130);
    glEnd();


    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(420,130);
    glVertex2d(475, 130);
    glVertex2d(465, 160);
    glVertex2d(430, 160);
    glEnd();

    //Car Window

    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(425,130);
    glVertex2d(445, 130);
    glVertex2d(445, 150);
    glVertex2d(430, 150);
    glEnd();


    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(450,130);
    glVertex2d(470, 130);
    glVertex2d(465, 150);
    glVertex2d(450, 150);
    glEnd();

    //Car Wheel

    glColor3ub(0,0,0);
    circle(10, 14, 435, 100);
    circle(10, 14, 465, 100);

    glColor3ub(245, 245, 245);
    circle(6, 10, 435, 100);
    circle(6, 10, 465, 100);

    glPopMatrix();
    bx += .11;
    glPushMatrix();
    glTranslatef(bx, 0, 0);

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(410,100);
    glVertex2d(490, 100);
    glVertex2d(485, 130);
    glVertex2d(410, 130);
    glEnd();


    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(420,130);
    glVertex2d(475, 130);
    glVertex2d(465, 160);
    glVertex2d(430, 160);
    glEnd();

    //Car Window

    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(425,130);
    glVertex2d(445, 130);
    glVertex2d(445, 150);
    glVertex2d(430, 150);
    glEnd();


    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(450,130);
    glVertex2d(470, 130);
    glVertex2d(465, 150);
    glVertex2d(450, 150);
    glEnd();

    //Car Wheel

    glColor3ub(0,0,0);
    circle(10, 14, 435, 100);
    circle(10, 14, 465, 100);

    glColor3ub(245, 245, 245);
    circle(6, 10, 435, 100);
    circle(6, 10, 465, 100);

    glPopMatrix();
    bx += .01;

    moonX += moonSpeed;
    if (moonX > 500){
        moonX = -20;
    }

    if (bx > 0){
        bx = -500;
    }
    glutPostRedisplay();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);

    glutInitWindowSize(700, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("A Moving Car Scenario");
    init();
    glutKeyboardFunc(key);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

