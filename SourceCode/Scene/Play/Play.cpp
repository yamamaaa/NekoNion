#include "Play.h"
#include"../Title/Title.h"

namespace scene
{
	Play::Play()
		:SceneBase()
	{
		//読み込み関連
		LoadObject();
	}

	Play::~Play()
	{
		//処理なし
	}

	void Play::LoadObject()
	{
		////オブジェクトタグをセット
		//object::ObjectManager::NowSceneSet(objecttag::Play_ObjectTagAll);
		////Game状態をセット
		//object::ObjectManager::SetNowGameState(object::GamePlay);
		//object::ObjectManager::SetNextGameState(object::GamePlay);

		//object::ObjectManager::Entry(new object::Area);
		//object::ObjectManager::Entry(new object::MoveArea);
		//object::ObjectManager::Entry(new object::ClockWork);
	}

	SceneBase* Play::UpdateScene(const float deltaTime)
	{
	//	object::ObjectManager::UpdateAllObj(deltaTime);

	//	//ランキングモード
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
