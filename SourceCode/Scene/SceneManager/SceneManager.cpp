#include "SceneManager.h"
#include"../../Scene/SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include"../../FPS/FPS.h"

#ifdef DEBUG
#include"../Play/Play.h"
#endif // DEBUG

namespace scene
{
    SceneManager::SceneManager()
        :m_HoldScene(nullptr)
        , fps(new fps::FPS)
    {
        //����������
        ObjectManager::Initialize();

        //���݂̃V�[�����^�C�g���ɐݒ�
        m_NowScene.emplace(new Play);

        //Game��Ԃ��Z�b�g
        ObjectManager::SetNowGameState(Play);
        ObjectManager::SetNextGameState(Play);

        //�}�E�X�̕\���ݒ�
        SetMouseDispFlag(false);
    }

    SceneManager::~SceneManager()
    {
        //�����Ȃ�
    }

    void SceneManager::GameLoop()
    {
        // �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            //if (object::GameStatus::GameEnd == object::ObjectManager::GetNextGameState())
            //    break;
            //�V�[���̃t���[
            UpdateScene();    //�X�V����
            ChangeScene();    //�؂�ւ�����
            DrawScene();      //�`�揈��
        }
    }

    void SceneManager::UpdateScene()
    {
        //���݂̃V�[�����X�V����mHoldScene�ɑ��
        fps->Update();
        m_HoldScene = m_NowScene.top()->UpdateScene(fps->GetDeltaTime());
    }

    void SceneManager::DrawScene()
    {
        ClearDrawScreen();					// ��ʂ��N���A
        m_NowScene.top()->DrawScene();		// ���̃V�[����\��
#if DEBUG
        DrawLine(960, 0, 960, 1080, GetColor(255, 0, 255), FALSE);  //������
        DrawLine(0, 540, 1920, 540, GetColor(0, 255, 255), FALSE);
#endif // DEBUG
        ScreenFlip();						// ����ʂ̓��e��\��ʂɔ��f
    }

    void SceneManager::ChangeScene()
    {
        // ���̃V�[���������ł͂Ȃ�������
        if (m_NowScene.top().get() != m_HoldScene)
        {
            //���݂̃V�[�����폜���A���̃V�[���ɐ؂�ւ�
            m_NowScene.pop();
            m_NowScene.emplace(m_HoldScene);
        }
    }
}

