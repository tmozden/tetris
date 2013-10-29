/* Tetris main 
 * Author Travis Mozden
 * 
 *
 */
#include <iostream>
#include <string>
#include <GL/glut.h>

void renderFunc(){

	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
 
 
int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1500, 850);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bro Chanllenge Tetris");
	
	//callbacks 
	glutDisplayFunc(renderFunc);
	
	glutMainLoop();
}
