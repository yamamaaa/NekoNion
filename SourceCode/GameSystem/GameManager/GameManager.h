#include "../../Scene/SceneManager/SceneManager.h"

namespace gamesystem
{
    /// <summary>
    /// �E�B���h�E�֘A
    /// </summary>
    class Window;

    /// <summary>
    /// �Q�[�����[�v�O��̐ݒ�֘A
    /// </summary>
    class GameSetting;

    /// <summary>
    /// �Q�[���S�̂̐i�s�Ǘ��N���X
    /// </summary>
    class GameManager final
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameManager();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameManager();

        /// <summary>
        /// �㏈��
        /// </summary>
        void Finalize();

    private:

        Window* window;
        GameSetting* gamesetting;

        //�V�[���}�l�[�W���[
        std::unique_ptr<class scene::SceneManager> sceneManager;
    };
}