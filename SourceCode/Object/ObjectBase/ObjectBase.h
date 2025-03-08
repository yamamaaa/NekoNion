#pragma once
#include<DxLib.h>
#include<string>
#include <vector>

namespace object
{
	/// <summary>
	/// �Q�[���I�u�W�F�N�g���N���X
	/// </summary>
	class ObjectBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="string">�I�u�W�F�N�g��</param>
		ObjectBase(std::string tagname);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~ObjectBase();

		/// <summary>
		/// �I�u�W�F�N�g�̓ǂݍ��݊֘A
		/// </summary>
		virtual void LoadObj() = 0;

		/// <summary>
		/// �I�u�W�F�N�g�̍X�V����
		/// </summary>
		/// <param name="deltaTime"�f���^�^�C��></param>
		virtual void  UpdateObj(const float deltatime) = 0;

		/// <summary>
		/// �I�u�W�F�N�g�̕`��
		/// </summary>
		virtual void  DrawObj() = 0;

		/// <summary>
		/// �ړ�����
		/// </summary>
		/// <param name="deltaTime"�f���^�^�C��></param>
		virtual void MoveObj(const float deltatime) {};

		/// <summary>
		/// �I�u�W�F�N�g�̃^�O���擾
		/// </summary>
		/// <returns>�^�O��</returns>
		const std::string GetTagName()const { return m_ObjTag; }

		/// <summary>
		/// �I�u�W�F�N�g�̈ʒu���Q��
		/// </summary>
		/// <returns>�ʒu���</returns>
		const VECTOR& GetObjPos() const { return m_ObjPos; }

		/// <summary>
		/// �����蔻��
		/// </summary>
		/// <param name="colobj">���肷��I�u�W�F�N�g</param>
		virtual void OnCollisionEnter(ObjectBase* colobj) {};

		/// <summary>
		/// �����蔻����擾
		/// </summary>
		/// <returns>:�����蔻����</returns>
		MV1_COLL_RESULT_POLY_DIM GetColInfo()const { return m_ColInfo; }

		/// <summary>
		/// �����擾
		/// </summary>
		/// <returns>����</returns>
		VECTOR GetObjDir() const { return m_ObjDir; }

	private:

		/// <summary>
		/// �I�u�W�F�N�g���W�Z�o
		/// </summary>
		/// <returns>���W</returns>
		void CalcObjPos();

		std::string m_ObjTag;	// �I�u�W�F�N�g���

		int m_ObjHandle;       // �I�u�W�F�n���h��

		VECTOR m_ObjPos;          //�I�u�W�F�N�g�ʒu
		VECTOR m_ObjScale;        //�I�u�W�F�N�g�̑傫��
		VECTOR m_ObjWorldPos;     //���[���h���W
		VECTOR m_ObjLocalPos;     //���[�J�����W
		VECTOR m_ObjDir;          //����

		MV1_COLL_RESULT_POLY_DIM m_ColInfo;	//�����蔻����
	};
}