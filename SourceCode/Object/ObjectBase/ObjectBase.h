#pragma once
#include<DxLib.h>
#include<string>
#include <vector>

namespace object
{
	/// <summary>
	/// ゲームオブジェクト基底クラス
	/// </summary>
	class ObjectBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="string">オブジェクト名</param>
		ObjectBase(std::string tagname);

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~ObjectBase();

		/// <summary>
		/// オブジェクトの読み込み関連
		/// </summary>
		virtual void LoadObj() = 0;

		/// <summary>
		/// オブジェクトの更新処理
		/// </summary>
		/// <param name="deltaTime"デルタタイム></param>
		virtual void  UpdateObj(const float deltatime) = 0;

		/// <summary>
		/// オブジェクトの描画
		/// </summary>
		virtual void  DrawObj() = 0;

		/// <summary>
		/// 移動処理
		/// </summary>
		/// <param name="deltaTime"デルタタイム></param>
		virtual void MoveObj(const float deltatime) {};

		/// <summary>
		/// オブジェクトのタグ名取得
		/// </summary>
		/// <returns>タグ名</returns>
		const std::string GetTagName()const { return m_ObjTag; }

		/// <summary>
		/// オブジェクトの位置を参照
		/// </summary>
		/// <returns>位置情報</returns>
		const VECTOR& GetObjPos() const { return m_ObjPos; }

		/// <summary>
		/// 当たり判定
		/// </summary>
		/// <param name="colobj">判定するオブジェクト</param>
		virtual void OnCollisionEnter(ObjectBase* colobj) {};

		/// <summary>
		/// 当たり判定情報取得
		/// </summary>
		/// <returns>:当たり判定情報</returns>
		MV1_COLL_RESULT_POLY_DIM GetColInfo()const { return m_ColInfo; }

		/// <summary>
		/// 方向取得
		/// </summary>
		/// <returns>方向</returns>
		VECTOR GetObjDir() const { return m_ObjDir; }

	private:

		/// <summary>
		/// オブジェクト座標算出
		/// </summary>
		/// <returns>座標</returns>
		void CalcObjPos();

		std::string m_ObjTag;	// オブジェクト種類

		int m_ObjHandle;       // オブジェハンドル

		VECTOR m_ObjPos;          //オブジェクト位置
		VECTOR m_ObjScale;        //オブジェクトの大きさ
		VECTOR m_ObjWorldPos;     //ワールド座標
		VECTOR m_ObjLocalPos;     //ローカル座標
		VECTOR m_ObjDir;          //方向

		MV1_COLL_RESULT_POLY_DIM m_ColInfo;	//当たり判定情報
	};
}