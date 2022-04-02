#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning; // 내부 게임 동작변수

	public:
		MGameLoop() 
		{
			_isGameRunning = false;
		}
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;

			Initalize();

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
			_isGameRunning = false; // 내부에서 false로 변경
		}

	private:

		void Initalize()
		{
			SetCursorState(false);
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) == -0x8000|| GetAsyncKeyState(VK_SPACE) == -0x8001)
			{

			}
			else
			{
				// 김태인
			}
		}

		void Update()
		{

		}

		void Render()
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			//system("cls");
			cout << "Rendering... ";

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			
			cout << "Rendering speed : " << renderDuration.count()<< "sec" << endl;

			int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);

			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::microseconds(remainingFrameTime));
		}

		void Release(){}

	private: // 게임 사용 함수
		
		void MoveCursor(short x, short y)
		{
			COORD position = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}

		void SetCursorState(bool visible)
		{
			CONSOLE_CURSOR_INFO consoleCursorInfo;
			consoleCursorInfo.bVisible = visible;
			consoleCursorInfo.dwSize = 1;

			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
		}
	};
}