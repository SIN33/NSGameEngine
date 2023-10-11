#pragma once

#include <chrono>
class Timer
{
public:
	//ctor
	Timer()
	{
		m_deltaTime = 0.0f;
		m_prevTime = std::chrono::system_clock::now();
		m_baseTime = std::chrono::system_clock::now();
		m_nFrameCount = 0;
	}

	//ゲームループの最後にいれる
	//デルタタイムの計算、垂直同期を行う
	void  TickProc();

	float DeltaTime()
	{
		return m_deltaTime;
	}
	float FPS()
	{
		return m_fps;
	}

private:
	// 直前フレームからの経過時間（s）
	float m_deltaTime = 0.0f;

	// 一つ前のフレームのタイムスタンプ
	std::chrono::system_clock::time_point m_prevTime;

	// fps計算時に使用する記録用のタイムスタンプ
	std::chrono::system_clock::time_point m_baseTime;

	// fps(GetTick関数内で、常に更新される)
	float m_fps = 0;

	//fps　の計測に用いる(fpsの算出前に更新されたフレーム数)
	int m_nFrameCount = 0;
};
