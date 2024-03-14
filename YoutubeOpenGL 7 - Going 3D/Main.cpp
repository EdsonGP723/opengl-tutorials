//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


const unsigned int width = 800;
const unsigned int height = 800;


// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	 0.5f, -0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.250f, 0.498f, //0
	 0.0f,  0.0f,   0.5f,   0.83f, 0.70f, 0.44f,	0.490f, 0.743f, //1 
	 0.5f,  0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.730f, 0.497f, //2
	 //Cara numero #1

	 0.5f,  0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.490f, 0.743f, //3
	 0.0f,  0.0f,   0.5f,   0.83f, 0.70f, 0.44f,	0.968f, 0.744f, //4
	-0.5f,  0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.730f, 0.497f, //5
	//Cara numero #7

	-0.5f,  0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.490f, 0.743f, //6
	 0.0f,  0.0f,   0.5f,   0.83f, 0.70f, 0.44f,	0.730f, 0.992f, //7
	-0.5f, -0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.968f, 0.744f, //8
	//Cara numero #5

	-0.5f, -0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.250f, 0.498f, //9
	 0.0f,  0.0f,   0.5f,   0.83f, 0.70f, 0.44f,	0.011f, 0.744f, //10
	 0.5f, -0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.490f, 0.743f, //11
	 //Cara numero #3

	 0.0f,  0.0f,  -0.5f,   0.83f, 0.70f, 0.44f,	0.490f, 0.251f, //12
	 0.5f, -0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.250f, 0.498f, //13
	 0.5f,  0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.730f, 0.497f, //14
	 //Cara numero #4

	  0.0f,  0.0f,  -0.5f,   0.83f, 0.70f, 0.44f,	0.972f, 0.251f, //15
	  0.5f,  0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.730f, 0.497f, //16
	 -0.5f,  0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.490f, 0.251f, //17
	 //Cara numero #6

	  0.0f,  0.0f,  -0.5f,   0.83f, 0.70f, 0.44f,	0.731f, 0.003f, //18
	 -0.5f,  0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.972f, 0.251f, //19
	 -0.5f, -0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.490f, 0.251f, //20
	 //Cara numero #8

	  0.0f,  0.0f,  -0.5f,   0.83f, 0.70f, 0.44f,	0.013f, 0.249f, //21
	 -0.5f, -0.5f,   0.0f,   0.92f, 0.86f, 0.76f,    0.250f, 0.498f, //22
	  0.5f, -0.5f,   0.0f,   0.83f, 0.70f, 0.44f,	0.490f, 0.251f, //23
	  //Cara numero #2
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	3, 4, 5,
	6, 7, 8,
	9,10,11,
	12,13,14,
	15,16,17,
	18,19,20,
	21,22,23
};



int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, width, height);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	Texture brickTex((parentDir + texPath + "1.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shaderProgram.Activate();

		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60)
		{
			rotation += 0.005f;
			prevTime = crntTime;
		}

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(1.0f, 0.0f, 1.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
		proj = glm::perspective(glm::radians(75.0f), (float)width / height, 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		glUniform1f(uniID, 0.5f);
		brickTex.Bind();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}