#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}
		int i = 0;
		chrono::system_clock::time_point  startRenderTimePoint;

		void Run()
		{
			_isGameRunning = true;
			Initialize();

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

		}
		void Release()
		{
		}

		void Input()
		{
			/*	if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{

				}
				else
				{

				}*/

		}
		void Update()
		{

		}

		void Render()
		{
			float FPS;

			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);


			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			
			startRenderTimePoint = chrono::system_clock::now();

			cRenderer.DrawString("FPS : " + to_string(FPS = 1.f / renderDuration.count()));
		}
		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
	};






}