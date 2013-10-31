// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include 

//#include <glm/glm.hpp>
//using namespace glm;

//#include <common/shader.hpp>

//#define WINDOW_WIDTH 1366
//#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define EXIT_FAILURE 1

typedef enum{
	FALSE,
	TRUE
}BOOl;

//private vars


//recieve input from keyboard
void keyCallback(GLFWwindow* theWindow, int key, int scancode, int action, int mods){
	
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(theWindow, GL_TRUE);
	}
	

}

int main( void )
{
	
	if(!glfwInit())
		exit(EXIT_FAILURE);
		
	//open window and set it up
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 
		"BRO CHALLENGE TETRIS", glfwGetPrimaryMonitor(), NULL);
	
	if(!window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	
	glfwSetKeyCallback(window, keyCallback);
	
	
	do{
		float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(window);
	
		glfwPollEvents();
	}while(!glfwWindowShouldClose(window));
	
	
	
	glfwDestroyWindow(window);
	glfwTerminate();
	

	return 0;
}
