#include "Play.h"
#include"../Title/Title.h"

namespace scene
{
	Play::Play()
		:SceneBase()
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Play::~Play()
	{
		//�����Ȃ�
	}

	void Play::LoadObject()
	{
		////�I�u�W�F�N�g�^�O���Z�b�g
		//object::ObjectManager::NowSceneSet(objecttag::Play_ObjectTagAll);
		////Game��Ԃ��Z�b�g
		//object::ObjectManager::SetNowGameState(object::GamePlay);
		//object::ObjectManager::SetNextGameState(object::GamePlay);

		//object::ObjectManager::Entry(new object::Area);
		//object::ObjectManager::Entry(new object::MoveArea);
		//object::ObjectManager::Entry(new object::ClockWork);
	}

	SceneBase* Play::UpdateScene(const float deltaTime)
	{
	//	object::ObjectManager::UpdateAllObj(deltaTime);

	//	//�����L���O���[�h
	//	if (object::GamePlay == status)
	//	{
	//		return new Play();
	//	}

		return this;
	}

	void Play::DrawScene()
	{
		ObjectManager::DrawAllObj();

#if DEBUG
		DrawString(0, 0, "Play", GetColor(255, 255, 255));
#endif // DEBUG
	}
}
