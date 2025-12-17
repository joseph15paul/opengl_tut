#include <cmath>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Shader.h>

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

	float vertices[] = {
		-0.75f, -0.250f, 0.0f,
		0.0f, 0.750f, 0.0f,
		0.75f, -0.25f, 0.0f,
	};

	unsigned int vao;
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	Shader shader = Shader("/home/joseph/code/opengl/tutorial/uniform/vshader", "/home/joseph/code/opengl/tutorial/uniform/fshader");

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		shader.use();
		int time = glfwGetTime();
		float green = std::sin(time) /2.0 + 0.5;
		shader.setFloat("uniGreen", green);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

