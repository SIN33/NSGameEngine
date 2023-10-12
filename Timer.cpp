#include "Timer.h"
#include <thread>
#include <synchapi.h>

using namespace std;
void Timer::TickProc()
{
	constexpr int	nMaxFps = 60;

	constexpr int	nMicoroSecPerSec = 1000000; //1�b������̃ʕb(fps�̌v�Z�ŁA����\��microseconds���w�肵����)

	// �v���̃x�[�X���Ԃ���̌o�ߎ���
	float elapsedTimeFromBaseTime;

	//------------------------------
	// calc deltatime
	//------------------------------
	chrono::system_clock::time_point nowTime = chrono::system_clock::now();
	float deltaTimeMs = duration_cast<std::chrono::microseconds>(nowTime - m_prevTime).count();

	// calc FPS
	++m_nFrameCount;

	// �v���̃x�[�X���Ԃ���̌o�ߎ���
	elapsedTimeFromBaseTime = chrono::duration_cast<chrono::microseconds>(nowTime - m_baseTime).count();

	if (elapsedTimeFromBaseTime >= nMicoroSecPerSec)
	{
		m_fps = float(m_nFrameCount * nMicoroSecPerSec) / elapsedTimeFromBaseTime; //1�t���[��������ɂ�����������(���t���[�����o�ߎ��ԂŊ���)
		// FPS�v���̃x�[�X���Ԃ��A���̎��ԂɃ��Z�b�g
		m_baseTime = nowTime;
		// FPS�v���p�̃t���[���J�E���g�����Z�b�g
		m_nFrameCount = 0;
	}

	//convert ms deltatime 
	m_deltaTime = deltaTimeMs / float(nMicoroSecPerSec);
	m_prevTime = nowTime;


	// control frame rate
	DWORD ms = 1000 / nMaxFps;
	if (m_deltaTime * 1000 < ms)
	{
		//��������
		//�f�B�X�v���C�̍X�V�O�Ƀt���[���̍X�V�������I������ꍇ�A�܂�
		Sleep(ms - (m_deltaTime * 1000));
	}

}
