#include <DxLib.h>
#include <memory>

#include "GameSetting.h"

namespace gamesystem
{
    //���̂̏�����
    std::unique_ptr<GameSetting> GameSetting::gamesetting = nullptr;

    void GameSetting::Init()
    {
        //���̂ɉ��������Ă��Ȃ�������
        if (!gamesetting)
        {
            //���̓��ɃC���X�^���X�𐶐�
            gamesetting.reset(new GameSetting);
        }
    }

    GameSetting::GameSetting()
    {
        BeforeLibInit();

        //DxLib����������
        if (DxLib_Init() == -1)
        {
            //�G���[���N�����璼���ɏI��
            DebugBreak();
        }

        AfterLibInit();
    }

    GameSetting::~GameSetting()
    {
        //���C�u�����I��
        DxLib_End();
    }

    void GameSetting::BeforeLibInit()
    {
        //�A���`�G�C���A�X�̐ݒ�
        SetFullSceneAntiAliasingMode(4, 2);

        // Direct3D9Ex ���g�p����
        SetUseDirect3DVersion(DX_DIRECT3D_9EX);
    }

    void GameSetting::AfterLibInit()
    {
        //�`���𗠉�ʂɐݒ�
        SetDrawScreen(DX_SCREEN_BACK);

        SetBackgroundColor(0, 0, 0);   // �w�i�F�ݒ�

        //Z�o�b�t�@�ݒ�
        SetUseZBuffer3D(true);
        SetWriteZBuffer3D(true);
    }
}