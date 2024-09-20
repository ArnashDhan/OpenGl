#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<Shader/Shader.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

int main() {


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpengl", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create a Window" << std::endl;
		glfwTerminate();
		return -1;

	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	Shader ourShader("src/ShaderCode/VertexShader.vert", "src/ShaderCode/FragmentShader.frag");
	float firstTriangle[] = {
		// first triangle
		0.2f,  0.8f, 0.0f,  1.0f,0.0f,0.0f,// top right
		0.2f, -0.8f, 0.0f,  0.0f,1.0f,0.0f,// bottom right
		-0.3f,  0.8f, 0.0f,  0.0f,0.0f,1.0f// top left 
	};
	float secondTriangle[] = {
		// second triangle
		0.2f, -0.8f, 0.0f,    1.0f,0.0f,0.0f,  // bottom right
		-0.3f, -0.8f, 0.0f,   0.0f,1.0f,0.0f,// bottom left
		-0.3f,  0.8f, 0.0f,   0.0f,0.0f,1.0f// top left
	};
	float secondTriangleTF[] = {
		// second triangle
		0.2f, 0.5f, 0.0f, 1.0f,0.0f,0.0f, // bottom left
		0.8f, 0.8f, 0.0f,  0.0f,1.0f,0.0f, // top right
		0.2f,  0.8f, 0.0f,  0.0f,0.0f,1.0f // top left big f
	};
	float secondTriangleTBF[] = {
		// second triangle
		0.2f, 0.5f, 0.0f, 1.0f,0.0f,0.0f, // bottom left
		0.8f, 0.8f, 0.0f,   0.0f,1.0f,0.0f,// top right
		0.8f,  0.5f, 0.0f,  0.0f,0.0f,1.0f //bottom right
	};
	float secondTriangleSF[] = {
		// second triangle
		0.2f, 0.0f, 0.0f, 1.0f,0.0f,0.0f, // Top left
		0.5f, 0.0f, 0.0f,  0.0f,1.0f,0.0f, // top right
		0.2f,  -0.2f, 0.0f,  0.0f,0.0f,1.0f // Bottom left
	};
	float secondTriangleSBF[] = {
		// second triangle
		0.5f, 0.0f, 0.0f, 1.0f,0.0f,0.0f, // top right
		0.2f,  -0.2f, 0.0f,   0.0f,1.0f,0.0f, // Bottom left
		0.5f,  -0.2f, 0.0f,  0.0f,0.0f,1.0f //bottom right
	};


	unsigned int VBOs[6], VAOs[6], EBO;
	glGenVertexArrays(6, VAOs);
	glGenBuffers(1, & EBO);
	glGenBuffers(6, VBOs);

	glBindVertexArray(VAOs[0]);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//	position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//	colour Attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//	colour Attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAOs[2]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangleTF), secondTriangleTF, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//	colour Attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAOs[3]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangleTBF), secondTriangleTBF, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//	colour Attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAOs[4]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[4]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangleSF), secondTriangleSF, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//	colour Attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAOs[5]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[5]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangleSBF), secondTriangleSBF, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//	colour Attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)) );
	glEnableVertexAttribArray(1);
	
	
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ourShader.use();
		ourShader.setFloat("someUniform", 1.0f);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(VAOs[2]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glBindVertexArray(VAOs[4]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		//half mark
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(VAOs[3]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glBindVertexArray(VAOs[5]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(6, VAOs);
	glDeleteBuffers(6, VBOs);


	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}






















