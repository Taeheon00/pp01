#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#pragma comment(lib,"OpenGL32.lib")

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	public:
		MGameLoop() { }
		~MGameLoop() {}

		static void error_callback(int error, const char* description)
		{
			fputs(description, stderr);
		}
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);
		}


		void Run()
		{
			GLFWwindow* window;
			glfwSetErrorCallback(error_callback);
			if (!glfwInit())
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}
			window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);

			Initialize(window);
			while (!glfwWindowShouldClose(window))
			{

				Input(window);
				Update(window);
				Render(window);

			}
			Release(window);
		}
		void Stop()
		{

		}

	private:
		void Initialize(GLFWwindow* window)
		{
			if (!window)
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}
			glfwMakeContextCurrent(window);
			glfwSetKeyCallback(window, key_callback);
		}
		void Release(GLFWwindow* window)
		{
			glfwDestroyWindow(window);
			glfwTerminate();
			exit(EXIT_SUCCESS);
		}

		void Input(GLFWwindow* window)
		{
			playerinput();
		}
		void Update(GLFWwindow* window)
		{

		}
		void Render(GLFWwindow* window)
		{

			
		}

		void playerinput()
		{
            #define VK_SPACE  0x20
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				
			}
			else
			{
				
			}
		}

	};
}