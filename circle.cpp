#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

static void error_callback(int error, const char* description) {
	std::cout << description << "\n";
}

static void window_close_callback(GLFWwindow* window) {
	std::cout << "Close window called \n";
	glfwSetWindowShouldClose(window, GL_TRUE);
}

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(window, true);
}

int main() {
	
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		std::cout << "glfw init failed \n";
		return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	auto *window = glfwCreateWindow(640, 480, "MY WINDOW", NULL, NULL);
	if (!window) {
		std::cout << "window creation failed \n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glfwSwapInterval(1);

	//glfwSetWindowCloseCallback(window, window_close_callback);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

