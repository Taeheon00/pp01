#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <cstdlib>
#include <GLFW/glfw3.h>
#pragma comment(lib, "OpenGL32")

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;
		Enemy e;
		int score = 0;
		int bestscore = 0;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{

				key_callback();
				Update();
				Render();


			}
			Release();
		}
		void Stop()
		{

		}

	private:
		void Initialize()
		{

		}
		void Release()
		{

		}

		static void error_callback(int error, const char* description)
		{
			fputs(description, stderr);
		}
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);

			if (key == GLFW_KEY_UP && action == GLFW_PRESS)
				p->MoveUp(0.01f);
			if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
				p->MoveUp(0.0f);
			if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
				p->MoveUp(-0.01f);
			if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
				p->MoveUp(0.0f);
			if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
				p->MoveRight(0.01f);
			if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
				p->MoveRight(0.0f);
			if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
				p->MoveRight(-0.01f);
			if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
				p->MoveRight(0.0f);



		}

		void Update()
		{

		}
		void Render()
		{

			cRenderer.Clear();
			e.enemymove();

			if ((e.x == p.x) && (e.y == p.y))
			{
				e.Enemycheck = true;
			}

			if (e.x == 19)
				score += 1;
			string SCORE = "Score: " + to_string(score);

			if (score >= bestscore)
				bestscore = score;
			string BESTSCORE = "BestScore: " + to_string(bestscore);

			cRenderer.MoveCursor(0, 1);
			cRenderer.DrawString(SCORE);

			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("P");

			cRenderer.MoveCursor(e.x, e.y);
			cRenderer.DrawString("E");

			cRenderer.MoveCursor(0, 0);
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));

			if (e.Enemycheck)
			{
				cRenderer.Clear();
				cRenderer.MoveCursor(35, 6);
				cRenderer.DrawString("Game Over!");
				cRenderer.MoveCursor(20, 7);
				cRenderer.DrawString("Please SPACE Bar Key Pressed Game Restart");
				cRenderer.MoveCursor(35, 8);
				cRenderer.DrawString(BESTSCORE);
				cRenderer.MoveCursor(37, 9);
				cRenderer.DrawString(SCORE);
				cRenderer.MoveCursor(0, 0);
				cRenderer.DrawString(fps);

				while (e.Enemycheck) {
					if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001) {
						e.Enemycheck = false;
						e.x = rand() % 36 + 27; e.y = 7;
						score = 0;
						break;
					}
				}
			}
		}


		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));

	};
}