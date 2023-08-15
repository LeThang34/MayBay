#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include <GL/freeglut.h>
using namespace std;
float carX, carY, carZ, carR, carG, carB, carAngle = 0;
float carY2, carY1, carY3 = 0.00;
bool isRotated = false;

void truc() {
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(50.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 50.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
}
bool derechoDown = false;
bool atrasDown = false;
bool izqDown = false;
bool derDown = false;
void myKeyboardUpFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		derechoDown = false;
		break;
	case 'd':
		atrasDown = false;
		break;
	case 'w':
		izqDown = false;
		break;
	case 's':
		derDown = false;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void myKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		derechoDown = true;
		break;
	case 'd':
		atrasDown = true;
		break;
	case 'w':
		izqDown = true;
		break;
	case 's':
		derDown = true;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
float wheelAngleLeft = carAngle;
float wheelAngleRight = carAngle;

float quay = 0;
float speed = 0.1;
float angleSpeed = 0.05;
float wheelAngle = 0.1;
void handleSpecialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		carX += speed * sin(carAngle - 3.14 / 2);
		carZ += speed * cos(carAngle - 3.14 / 2);
		break;
	case GLUT_KEY_DOWN:
		carX -= speed * sin(carAngle - 3.14 / 2);
		carZ -= speed * cos(carAngle - 3.14 / 2);
		break;
	case GLUT_KEY_LEFT:
		carAngle -= angleSpeed;
		break;
	case GLUT_KEY_RIGHT:
		carAngle += angleSpeed;
		break;
	}
	glutPostRedisplay();
}


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	truc();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	float speed = 0.1;
	float angleSpeed = 0.05;
	float wheelAngle = 0.1;
	if (derechoDown) {
		carX += speed * sin(carAngle - 3.14 / 2);
		carZ += speed * cos(carAngle - 3.14 / 2);
	}
	if (atrasDown) {
		carX -= speed * sin(carAngle - 3.14 / 2);
		carZ -= speed * cos(carAngle - 3.14 / 2);
	}
	if (izqDown) {
		carAngle -= angleSpeed;
	}
	if (derDown) {
		carAngle += angleSpeed;
	}
	glTranslatef(carX * sin(carAngle), 0.0, carZ * cos(carAngle));
	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0);

	 //----Thân-----
	glScalef(2, 0.5, 0.5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();

	//-----Cánh-----
	glTranslatef(carX + -0.5, -1.75, carZ + 0);
	glRotatef(55, 0, 0, 1);
	glScalef(1.5, 0.5, 0.15);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(carX - 0.5, 1.75, carZ);
	glRotatef(-55, 0, 0, 1);
	glScalef(1.5, 0.5, 0.15);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();

	//------Động cơ------
	glTranslatef(carX + -.75, -2.4, carZ -0.3);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1, 1);
	glutSolidCylinder(0.3, 2.5, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glColor3f(1, 0, 0);
	glTranslatef(carX + 1.75, -2.4, carZ -0.2);
	glRotatef(quay, 1, 0, 0);
	quay = quay + 1;
	glScalef(0.05, 0.5, 0.05);
	glutPostRedisplay();
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glColor3f(1, 0, 0);
	glTranslatef(carX + 1.8, -2.4, carZ -0.3);
	glRotatef(90, 0, 1, 0);
	glScalef(0.25, 0.25, 0.5);
	glutSolidCone(1, 1, 20, 20);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(carX + -.78, 2.4, carZ -0.3);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1, 1);
	glutSolidCylinder(0.3, 2.5, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glColor3f(1, 0, 0);
	glTranslatef(carX + 1.75, 2.4, carZ -0.2);
	glRotatef(quay, 1, 0, 0);
	quay = quay + 1;
	glScalef(0.05, 0.5, 0.05);
	glutPostRedisplay();
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glColor3f(1, 0, 0);
	glTranslatef(carX + 1.78, 2.4, carZ -0.3);
	glRotatef(90, 0, 1, 0);
	glScalef(0.25, 0.25, 0.5);
	glutSolidCone(1, 1, 20, 20);
	glPopMatrix();
	glPushMatrix();


	//------Đuôi-------
	glColor3f(1, 0, 0);
	glTranslatef(carX - 2.5, 0, carZ+1.5);
	glRotatef(-35, 0, 1, 0);
	glScalef(0.5, 0.05, 1);
	glutSolidCube(2);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(carX - 3, 0.5, carZ+ 2);
	glRotatef(-45, 0, 0, 1);
	glScalef(1, 0.5, 0.05);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(carX - 3, -0.5, carZ+ 2);
	glRotatef(45, 0, 0, 1);
	glScalef(1, 0.5, 0.05);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
	glPushMatrix();

	//-------Quạt-------
	glColor3f(1, 0, 0);
	glTranslatef(carX +3.5, 0, carZ+ 0);
	glRotatef(quay, 1, 0, 0);
	quay = quay + 1;
	glutPostRedisplay();
	glScalef(0.05, 0.75, 0.25);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();
	

	glDisable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	//-------Cabin---------
	glTranslatef(carX + 1., 0, carZ+0.8);
	glScalef(1, 0.5, 0.5);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glDisable(GL_LIGHT1);

	glEnable(GL_LIGHT2);		

	//-----Trục trước---------
	glTranslatef(carX+3., 0, carZ -.25);
	glRotatef(carY3-90, 0,1,0);
	glTranslatef(carX -1,0, carZ+0.75);
	glScalef(1.,0.25,0.5);
	glutSolidCube(1);
	glutPostRedisplay();
	glPopMatrix();
	glPushMatrix();

	//Bánh trước
	glTranslatef(carX+4., 0, carZ );
	glRotatef(carY3-90, 0, 1, 0);
	glTranslatef(carX -2, 0, carZ + 1.75);
	glScalef(0.25, 0.1, 0.25);
	glutSolidSphere(1, 50, 50);
	glutPostRedisplay();
	glPopMatrix();
	glPushMatrix();

	//------Trục sau----------
	//Bên phải
	glTranslatef(carX -1., 0.2, carZ -0.75);
	glRotatef(-carY1+90, 0, 1, 0);
	glTranslatef(carX+ 0.5, 0.2, carZ+0.25);
	glScalef(1., 0.25, 0.5);
	glutSolidCube(1);
	glutPostRedisplay();
	glPopMatrix();
	glPushMatrix();

	glTranslatef(carX -1.25, 0.2, carZ-0.5);
	glRotatef(-carY1+90 , 0, 1, 0);
	carY1 += 0.01;
	if (carY1 > 60) carY1 = 85;
	glTranslatef(carX + 1.5, 0.2, carZ + 0.5);
	glScalef(0.25, 0.1, 0.25);
	glutSolidSphere(1, 50, 50);
	glutPostRedisplay();
	glPopMatrix();
	glPushMatrix();
	//Bên trái
	glTranslatef(carX - 1., -0.2, carZ - 0.75);
	glRotatef(-carY1 + 90, 0, 1, 0);
	glTranslatef(carX + 0.5, -0.2, carZ + 0.25);
	glScalef(1., 0.25, 0.5);
	glutSolidCube(1);
	glutPostRedisplay();
	glPopMatrix();
	glPushMatrix();

	glTranslatef(carX - 1.25, -0.2, carZ - 0.5);
	glRotatef(-carY1 + 90, 0, 1, 0);
	carY1 += 0.01;
	if (carY1 > 60) carY1 = 85;
	glTranslatef(carX + 1.5, -0.2, carZ + 0.5);
	glScalef(0.25, 0.1, 0.25);
	glutSolidSphere(1, 50, 50);
	glutPostRedisplay();
	glPopMatrix();
	glPushMatrix();
	glDisable(GL_LIGHT2);

	glDisable(GL_LIGHTING);
	glPopMatrix();
	glFlush();
}

void init() {
	glClearColor(1., .9, .9, .9);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	GLfloat posi[] = { 1, 0, 0, 1 };
	GLfloat ambient[] = { 1, 0, 0, 1 };
	GLfloat diffu[] = { 0, 0.5, 1.0, 1 };
	GLfloat specu[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, posi);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffu);

	glEnable(GL_LIGHT1);
	GLfloat posi1[] = { 1, 0, 0, 1 };
	GLfloat ambient1[] = { 1, 0, 0, 1 };
	GLfloat diffu1[] = { 0.8, 0.8, 0.8, 1 };
	GLfloat specu1[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT1, GL_POSITION, posi1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffu1);

	glEnable(GL_LIGHT2);
	GLfloat posi2[] = { 1, 0, 0, 1 };
	GLfloat ambient2[] = { 1, 0, 0, 1 };
	GLfloat diffu2[] = { 0., 0., 0., 1 };
	GLfloat specu2[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT2, GL_POSITION, posi2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffu2);
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (GLfloat)w / (GLfloat)h, .5, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(7, 5, 10, 0, 0, 0, 0,0, 1);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glutKeyboardUpFunc(myKeyboardUpFunc);
	init();
	glutDisplayFunc(MyDisplay);
	glutKeyboardUpFunc(myKeyboardUpFunc);
	glutKeyboardFunc(myKeyboardFunc);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
