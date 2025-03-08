#pragma once
#include<memory>
#include<unordered_map>

#include"../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// オブジェクト管理
	/// </summary>
	class ObjectManager final
	{
	public:

		/// <summary>
		/// 初期化処理
		/// </summary>
		static void InitObjManager();

        /// <summary>
        /// 現在のシーンタグをセット
        /// </summary>
        static void NowSceneSet(std::vector<std::string> scene_objtag) {
            objectmanager->m_SceneTag = scene_objtag;
        }

        /// <summary>
        /// オブジェクト追加
        /// </summary>
        /// <param name="newObj">:追加オブジェクト</param>
        static void AddObj(class ObjectBase* newObj);

        /// <summary>
        /// オブジェクト更新
        /// </summary>
        /// <param name="deltaTime">:デルタタイム</param>
        static void UpdateAllObj(const float deltaTime);

        /// <summary>
        /// オブジェクト描画
        /// </summary>
        static void DrawAllObj();

        /// <summary>
        /// 全オブジェクト削除
        /// </summary>
        static void ReleaseAllObj();

        /// <summary>
        /// オブジェクトの取得
        /// </summary>
        /// <param name="tag">タグ名</param>
        /// <param name="index">オブジェクト番号</param>
        /// <returns>指定のオブジェクト</returns>
        static ObjectBase* GetGameObj(std::string tagname, int index);

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~ObjectManager();

	private:

		/// <summary>
		/// コンストラクタ(シングルトン)
		/// </summary>
		ObjectManager();

        std::vector<std::string> m_SceneTag;                       // 現在のシーンのオブジェクトタグ
        static std::unique_ptr<ObjectManager> objectmanager;       //自身の実体
        std::unordered_map<std::string, std::vector<std::shared_ptr<class ObjectBase>>> m_Objects;  //オブジェクトリスト
	};
}