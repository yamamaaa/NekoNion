#pragma once

namespace gamesystem
{
    /// <summary>
    /// �Q�[�����[�v�O��̐ݒ�֘A
    /// </summary>
    class GameSetting final
    {
    public:

        /// <summary>
        /// ����������
        /// </summary>
        static void Init();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameSetting();

    private:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameSetting();

        /// <summary>
        /// ���C�u�����������O�̏���
        /// </summary>
        static void BeforeLibInit();

        /// <summary>
        /// ���C�u������������̏���
        /// </summary>
        static void AfterLibInit();

        static std::unique_ptr<GameSetting> gamesetting;           //���g�̎���
    };
}