#include "FPS.h"

namespace fps
{
	FPS::FPS()
		:m_nowTime(static_cast<float>(GetNowCount()))
		, m_prevTime(m_nowTime)
		, m_deltaTime(0.0f)
	{
		//処理なし
	}

	FPS::~FPS()
	{
		//処理なし
	}

	void FPS::Update()
	{
		//フレームルート算出
		m_nowTime = static_cast<float>(GetNowCount());
		m_deltaTime = (m_nowTime - m_prevTime) / 1000.0f;
		m_prevTime = m_nowTime;
	}
}
