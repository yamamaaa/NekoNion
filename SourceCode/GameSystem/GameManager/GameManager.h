#include "../../Scene/SceneManager/SceneManager.h"

namespace gamesystem
{
    /// <summary>
    /// ウィンドウ関連
    /// </summary>
    class Window;

    /// <summary>
    /// ゲームループ前後の設定関連
    /// </summary>
    class GameSetting;

    /// <summary>
    /// ゲーム全体の進行管理クラス
    /// </summary>
    class GameManager final
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        GameManager();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~GameManager();

        /// <summary>
        /// 後処理
        /// </summary>
        void Finalize();

    private:

        Window* window;
        GameSetting* gamesetting;

        //シーンマネージャー
        std::unique_ptr<class scene::SceneManager> sceneManager;
    };
}