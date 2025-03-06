#include "FPS.h"

namespace fps
{
	FPS::FPS()
		:m_nowTime(static_cast<float>(GetNowCount()))
		, m_prevTime(m_nowTime)
		, m_deltaTime(0.0f)
	{
		//�����Ȃ�
	}

	FPS::~FPS()
	{
		//�����Ȃ�
	}

	void FPS::Update()
	{
		//�t���[�����[�g�Z�o
		m_nowTime = static_cast<float>(GetNowCount());
		m_deltaTime = (m_nowTime - m_prevTime) / 1000.0f;
		m_prevTime = m_nowTime;
	}
}
