/* Este programa dibuja una "Tetera", este objeto esta definido
 * en GLUT, se crea una fuente de luz, y un material */
* en GLUT, se crea una fuente de luz, y un material */
/***************Avila Armenta Fernando Ivan**************************/
//Incluimos las librerias
//#include <GL/glut.h>
//#include <stdlib.h>
#include "Main.h"

float rgb[3];

void InitGL(GLvoid)     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
														//glClearDepth(1.0f);									// Configuramos Depth Buffer
														//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realiza
}


void color(float r, float g, float b) {
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}



void rectangulo(float base, float altura, float x, float y) {
	glBegin(GL_QUADS);
	//glColor3f(rgb[0], rgb[1], rgb[2]);
	glVertex3f(x, y, -0.2); //V1
	glVertex3f(x + base, y, -0.2);//V2
	glVertex3f(x + base, y + altura, -0.2);//V3
	glVertex3f(x, y + altura, -0.2); //V4
	glEnd();
}

void poligonalR(float base, float altura, float x, float y) {
	glBegin(GL_LINE_LOOP);
	glVertex3f(x, y, -0.2); //V1
	glVertex3f(x + base, y, -0.2);//V2
	glVertex3f(x + base, y + altura, -0.2);//V3
	glVertex3f(x, y + altura, -0.2); //V4
	glEnd();
}

void rombo(double x, double y, double l, int i, int n) {
	double t = 3.141592654 * 2 / n;
	double p[3][2];
	double x1 = l*cos(t*i), y1 = l*sin(t*i),
		x2 = l*cos(t*(i + 1)), y2 = l*sin(t*(i + 1));

	p[0][0] = x1; p[0][1] = y1;
	p[1][0] = x1 + x2; p[1][1] = y1 + y2;
	p[2][0] = x2; p[2][1] = y2;
	glBegin(GL_POLYGON);
	glVertex3f(x, y, -0.2);
	glVertex3f(x + p[0][0], y + p[0][1], -0.2);
	glColor3f(0.49, 0.88, 0.96);
	glVertex3f(x + p[1][0], y + p[1][1], -0.2);
	glColor3f(0.45, 0.88, 0.33);
	glVertex3f(x + p[2][0], y + p[2][1], -0.2);
	glEnd();
}




// Aqui ponemos lo que queremos dibujar.
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

														//Las iniciales de mi nombre son F, I, ya que me llamo Fernando Ivan
														//Letra F
	float i = 0, h = 1, x = -8 + i, y = -8 + i;
	glColor3f(1, 1, 0.0);
	rectangulo(1, 1, x, y);
	rectangulo(2, 1, x, y + h);
	rectangulo(1, 1, x, y + 2 * h);
	rectangulo(3, 1, x, y + 3 * h);

	//Letra I
	i = 4 + i;
	x = -8 + i; y = -8;
	glColor3f(0, 1, 1.0);
	poligonalR(3, 1, x, y);
	poligonalR(1, 1, x + 1, y + h);
	poligonalR(1, 1, x + 1, y + 2 * h);
	poligonalR(3, 1, x, y + 3 * h);

	//Las iniciales de mis apellidos son A, A ya que me apellido Avila Armenta
	//Letra A
	//glColor3f(0.0, 0.0, 1.0);
	i = 4 + i;
	x = -8 + i; y = -8;
	glColor3f(0, 0, 1.0);
	rectangulo(1, 1, x, y);
	rectangulo(1, 1, x + 3, y);
	rectangulo(4, 1, x, y + h);
	rectangulo(1, 1, x, y + 2 * h);
	rectangulo(1, 1, x + 3, y + 2 * h);
	rectangulo(2, 1, x + 1, y + 3 * h);

	//Letra A
	i = 5 + i;
	x = -8 + i; y = -8;
	glColor3f(1, 0, 0.0);
	poligonalR(1, 1, x, y);
	poligonalR(1, 1, x + 3, y);
	poligonalR(4, 1, x, y + h);
	poligonalR(1, 1, x, y + 2 * h);
	poligonalR(1, 1, x + 3, y + 2 * h);
	poligonalR(2, 1, x + 1, y + 3 * h);

	//Ahora dibujamos una estrella
	int n = 5;
	x = -5; y = 5;
	for (i = 0; i<n; i++) {
		glColor3f(1, 1, 0.0);
		rombo(x, y, 2, i, n);
	}
	glFlush();
	return;
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-10, 10, -10, 10, 0.1, 2);//CONFIGURACI�N DEL PUERTO DE VISTA 
									  //L�mite en el eje vertical, eje horizontal, eje profundidad

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									//Matriz identidad para no modificar nada de lo anterior
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: exit(0);
		break;
	}
	glutPostRedisplay();
}




// Main del programa.
int main(int argc, char **argv)
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 2"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutMainLoop();          // 

							 // ANSI C requiere que main retorne un valor entero.
	return 0;
}



