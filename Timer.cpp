#include "Timer.h"
#include <thread>
#include <synchapi.h>

using namespace std;
void Timer::TickProc()
{
	constexpr int	nMaxFps = 60;

	constexpr int	nMicoroSecPerSec = 1000000; //1秒あたりのμ秒(fpsの計算で、分解能にmicrosecondsを指定したい)

	// 計測のベース時間からの経過時間
	float elapsedTimeFromBaseTime;

	//------------------------------
	// calc deltatime
	//------------------------------
	chrono::system_clock::time_point nowTime = chrono::system_clock::now();
	float deltaTimeMs = duration_cast<std::chrono::microseconds>(nowTime - m_prevTime).count();

	// calc FPS
	++m_nFrameCount;

	// 計測のベース時間からの経過時間
	elapsedTimeFromBaseTime = chrono::duration_cast<chrono::microseconds>(nowTime - m_baseTime).count();

	if (elapsedTimeFromBaseTime >= nMicoroSecPerSec)
	{
		m_fps = float(m_nFrameCount * nMicoroSecPerSec) / elapsedTimeFromBaseTime; //1フレームあたりにかかった時間(総フレームを経過時間で割る)
		// FPS計測のベース時間を、今の時間にリセット
		m_baseTime = nowTime;
		// FPS計測用のフレームカウントをリセット
		m_nFrameCount = 0;
	}

	//convert ms deltatime 
	m_deltaTime = deltaTimeMs / float(nMicoroSecPerSec);
	m_prevTime = nowTime;


	// control frame rate
	DWORD ms = 1000 / nMaxFps;
	if (m_deltaTime * 1000 < ms)
	{
		//垂直同期
		//ディスプレイの更新前にフレームの更新処理が終わった場合、まつ
		Sleep(ms - (m_deltaTime * 1000));
	}

}
