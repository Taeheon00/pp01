#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <cstdlib>

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
		int bestscore =0;

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

				Input();
				Update();
				Render();


			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{
			score = 0;
		}
		void Release()
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				p.isKeyPressed();
			}
			else
			{
				p.isKeyUnpressed();
			}
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
			else if (e.x == 0)
			{
				e.x = rand() % 36 + 27;
				e.Enemycheck = false;
			}

			if (e.x == 19)
				score += 1;
			string SCORE = "Score: " + to_string(score);

			if (score >= bestscore)
				bestscore = score;
			string BESTSCORE = "BestScore: " + to_string(bestscore);

			if (e.Enemycheck)
			{
				cRenderer.Clear();
				cRenderer.MoveCursor(35, 6);
				cRenderer.DrawString("Game Over!");
				cRenderer.MoveCursor(20, 7);
				cRenderer.DrawString("Please SPACE Bar Key Pressed Game Restart");
				cRenderer.MoveCursor(35, 8);
				cRenderer.DrawString(BESTSCORE);
				Stop();
				while (e.Enemycheck) {
					if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001) {
						e.Enemycheck = false;
						e.x = rand() % 36 + 27; e.y = 7;
						Run();
						break;
					}
				}
			}

			cRenderer.MoveCursor(0,1);
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
		}


		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));

	};
}