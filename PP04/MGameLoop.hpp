#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Hurdle.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point  startRenderTimePoint;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}
		int i = 0;
		Player p;
		Hurdle h;

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


			// y는 높이 이므로 y 5 ~ 7 
			// 랜덤으로 좌표에서 막대기가 나오도록 생성
			// 초마다 옆으로 2씩 움직임
			
			// 랜덤 스폰
			// 이후 1초마다 왼쪽으로 이동
			int num = rand();
			int go = ((int)num % 12) - 5;

			h.isHurdleSpawn(go);

			cRenderer.MoveCursor(h.x, h.y);
			cRenderer.DrawString("--");
		}

		void Render()
		{
			float FPS;

			cRenderer.Clear();
			
			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("P");

			cRenderer.MoveCursor(10, 20);


			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			
			startRenderTimePoint = chrono::system_clock::now();

			cRenderer.DrawString("FPS : " + to_string(FPS = 1.f / renderDuration.count()));

			this_thread::sleep_for(chrono::milliseconds(20));
		}
		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
	};






}