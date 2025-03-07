#pragma once
#include<Dxlib.h>
#include"../../Object/ObjectManager/ObjectManager.h"

using namespace object;

namespace scene
{
    /// <summary>
    /// シーンの更新処理クラス
    /// </summary>
    class SceneBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        SceneBase();

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~SceneBase();

        /// <summary>
        /// オブジェクト読み込み関連
        /// </summary>
        virtual void LoadObject() = 0;

        /// <summary>
        /// シーン更新処理
        /// </summary>
        /// <param name="deltaTime">デルタタイム</param>
        /// <returns>次のフレームシーン</returns>
        virtual SceneBase* UpdateScene(const float deltaTime) = 0;

        /// <summary>
        /// シーン描画処理
        /// </summary>
        virtual void DrawScene() = 0;
    };
}