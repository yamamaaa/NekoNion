#include "Title.h"

#include"../Play/Play.h"

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    Title::~Title()
    {
        //�����Ȃ�
    }

    void Title::LoadObject()
    {
        //�I�u�W�F�N�g�^�O���Z�b�g
        //object::ObjectManager::NowSceneSet(objecttag::TitleObjectTagAll);
        //Game��Ԃ��Z�b�g
        //object::ObjectManager::SetNowGameState(object::Title);
        //object::ObjectManager::SetNextGameState(object::Title);

        //Title��ʂ̑SUi����
        //object::ObjectManager::Entry(new object::TitleUi);
        //object::ObjectManager::Entry(new object::SelectMode);
        //object::ObjectManager::Entry(new object::Menu);
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        ObjectManager::UpdateAllObj(deltaTime);

        //�����L���O���[�h
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