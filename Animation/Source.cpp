

#include <windows.h> 
#include <glut.h>

GLfloat ang = 0;// declare the angle
int isShowed = 0;//declare the variable 

void windowKey(unsigned char key, int x, int y)
{
    if (key == ' ') {//when press space
        if (isShowed == 1) {
            isShowed = 0;// dont show background
        }
        else {
            isShowed = 1; // show
        }
    }
}

void draw(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clears the window and depth buffer 
    glLoadIdentity(); // replaces the current matrix with the identity matrix
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);// conrol the way we look at a scene

    glEnable(GL_LIGHTING);                // so the renderer considers light
    glEnable(GL_LIGHT0);                  // turn LIGHT0 on
    glEnable(GL_COLOR_MATERIAL); // enable the meterial

    GLfloat white[] = { 1.0, 0.8, 0.9, 1.0 };//define a color array
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);//diffuse color of the vertix depends on the position
    GLfloat direction[] = { 0.9,1,0,0 };//define the direction array for the position
    glLightfv(GL_LIGHT0, GL_POSITION, direction);// assign the position of the light

    if (isShowed == 1) {// show or not the background 
       // glutSolidTeapot(500);
        glClearColor(1, 0, 0, 1);

    }
    else {
        glClearColor(1, 1, 1, 1);
    }

    glPushMatrix(); // pushes the current matrix stack down 
    glScalef(3, 3, 3); // caling along the x, y, and z axes
    glRotatef(-20.0, 1.0, 0.0, 0.0);//performs a counterclockwise rotation of angle degrees
    glPopMatrix();
    glColor3f(1.59, 1.29, 1.12);//change color
    // Make a cone.  
    glPushMatrix();
    glRotatef(-270, 1.0, 0.0, 0.0);
    glutSolidCone(1, 2.5, 70, 12);
    glPopMatrix();// pops the current matrix stack

    glColor3f(1, 0., 0.8);
    // Make a sphere 
    glPushMatrix();
    glTranslatef(0, 0.8, -0.3);//translation specified by ( x, y, z )
    glRotated(ang, 0, 1, 0);
    glutSolidSphere(1.1, 50, 50);
    glPopMatrix();

    glColor3f(1, 0.6, 1);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    // Make a torus
    glutSolidTorus(0.3, 0.8, 16, 40);
    glPopMatrix();

    ang += 0.2;// animation

    glutSwapBuffers();//waps the buffers of the current window if double buffered  
}

int main() {
    glutInitDisplayMode(GLUT_DOUBLE);// sets the initial display mode. Usage. 
    glutInitWindowSize(600, 400);//size of the window
    glutCreateWindow("project");//name of the window
    glClearColor(1, 1, 1, 1);//specifies clear values for the color buffers
    glMatrixMode(GL_PROJECTION);//sets the current matrix mode. which is projection
    glLoadIdentity();
    gluPerspective(30, 600 / 400, 0, 100);//sets up a perspective projection matrix. 
    glMatrixMode(GL_MODELVIEW);//function specifies which matrix is the current matrix.
    glLoadIdentity();
    glutDisplayFunc(draw);// sets the display callback for the current window.
    glutIdleFunc(draw);//continuously called when  glutDisplayFunc(createPopupMenus);
    glutKeyboardFunc(windowKey);//sets the keyboard callback for the current window.
    glutMainLoop();//enters the event processing loop
}
