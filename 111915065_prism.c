#include "GL/glut.h"
#include "math.h"

void drw_polygon(int n = 3, int arg = 0, float mult = 1, float v = 1.0)
{
    if (arg < 0)
        arg = 0;
    glBegin(GL_POLYGON);
        glColor4f(1.0, 1.0, 1.0, 1.0);
        for(int i = arg; i <= (360 + arg); i += (360 / n))
            {
            float a = i * M_PI / 180;
            glVertex3f(mult * cos(a), mult * sin(a), 0.0);
        }
	glEnd();

	glBegin(GL_POLYGON);
        glColor4f(1.0, 1.0, 1.0, 1.0);
        for(int i = arg; i <= (360 + arg); i += (360 / n))
            {
            float a = i * M_PI / 180;
            glVertex3f(mult * cos(a), mult * sin(a), v);
        }
	glEnd();

	glBegin(GL_QUAD_STRIP);
        glColor4f(0.0, 1.0, 0.0, 1.0);
        for(int i = arg; i < 480; i += (360 / n))
            {
            float a = i * M_PI / 180;
            glVertex3f(mult * cos(a), mult * sin(a), 0.0);
            glVertex3f(mult * cos(a), mult * sin(a), v);
        }
	glEnd();
}

void show_prism()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(0.05, 1.0, 1.0, 0.0);
    drw_polygon(3, 0, 2, 4);
	glutSwapBuffers();
}

void loop1(int = 0)
{
	show_prism();
	glutTimerFunc(1, loop1, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(600, 200);
	glutCreateWindow("111915065 prism");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -5, 5);
	glutDisplayFunc(show_prism);
	loop1();
	glutMainLoop();
}
