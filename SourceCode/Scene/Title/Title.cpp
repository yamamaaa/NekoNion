#include "Title.h"

#include"../Play/Play.h"

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        //読み込み関連
        LoadObject();
    }

    Title::~Title()
    {
        //処理なし
    }

    void Title::LoadObject()
    {
        //オブジェクトタグをセット
        //object::ObjectManager::NowSceneSet(objecttag::TitleObjectTagAll);
        //Game状態をセット
        //object::ObjectManager::SetNowGameState(object::Title);
        //object::ObjectManager::SetNextGameState(object::Title);

        //Title画面の全Ui生成
        //object::ObjectManager::Entry(new object::TitleUi);
        //object::ObjectManager::Entry(new object::SelectMode);
        //object::ObjectManager::Entry(new object::Menu);
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        ObjectManager::UpdateAllObj(deltaTime);

        //ランキングモード
        if (GamePlay == status)
        {
            return new Play();
        }

        return this;
    }

    void Title::DrawScene()
    {
        ObjectManager::DrawAllObj();

#if DEBUG
        DrawString(0, 0, "title", GetColor(255, 255, 255));
#endif
    }
}