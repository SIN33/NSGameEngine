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

	//�Q�[�����[�v�̍Ō�ɂ����
	//�f���^�^�C���̌v�Z�A�����������s��
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
	// ���O�t���[������̌o�ߎ��ԁis�j
	float m_deltaTime = 0.0f;

	// ��O�̃t���[���̃^�C���X�^���v
	std::chrono::system_clock::time_point m_prevTime;

	// fps�v�Z���Ɏg�p����L�^�p�̃^�C���X�^���v
	std::chrono::system_clock::time_point m_baseTime;

	// fps(GetTick�֐����ŁA��ɍX�V�����)
	float m_fps = 0;

	//fps�@�̌v���ɗp����(fps�̎Z�o�O�ɍX�V���ꂽ�t���[����)
	int m_nFrameCount = 0;
};
