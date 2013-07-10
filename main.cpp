/*	Brent Mello
	Color Cipher
	main.cpp
	February 26, 2013
*/

#include "Cipher.h"
#include<GL\freeglut.h>

color red = {1.0,0.0,0.0};
color blue = {0.0,1.0,0.0};
Cipher myCipher(red,blue);

void drawBitmapText(char *string,float x,float y) 
{  
	char *c;
	glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

void spaceBar(unsigned char key, int x, int y)
{
	if (key == 27) //If "esc" is pressed
		exit(0);
	if (key == 98) //If "b" is pressed
		myCipher.set_encryptedBlend();
	if (key == 102) //If "f" is pressed
		myCipher.set_encryptedFmod();
	if (key == 32) { //If "spacebar" is pressed
		myCipher.reset_encrypted();
		myCipher._key = randColor();
		myCipher._secret = randColor();
	}
	glutPostRedisplay;
}

void renderScene(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(myCipher._key.red, myCipher._key.green, myCipher._key.blue);
	drawBitmapText("Key", -0.95, 0.9);
	glBegin(GL_QUADS);
		glVertex2f(-1.0,0.5);
		glVertex2f(-1.0,-1.0);
		glVertex2f(-0.4,-1.0);
		glVertex2f(-0.4,0.5);
	glEnd();

	glColor3f(myCipher._secret.red, myCipher._secret.green, myCipher._secret.blue);
	drawBitmapText("Secret", -0.25, 0.9);
	glBegin(GL_QUADS);
		glVertex2f(-0.3,0.5);
		glVertex2f(-0.3,-1.0);
		glVertex2f(0.3,-1.0);
		glVertex2f(0.3,0.5);
	glEnd();

	glColor3f(myCipher._encrypted.red, myCipher._encrypted.green, myCipher._encrypted.blue);
	drawBitmapText("Encrypted", 0.45, 0.9);
	glBegin(GL_QUADS);
		glVertex2f(1.0,0.5);
		glVertex2f(1.0,-1.0);
		glVertex2f(0.4,-1.0);
		glVertex2f(0.4,0.5);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv) {
	srand( time( NULL ) );

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200,50);
	glutInitWindowSize(800,600);
	glutCreateWindow("Color Cipher");

	glutDisplayFunc(renderScene);
	glutKeyboardFunc(spaceBar);

	glutMainLoop();
}