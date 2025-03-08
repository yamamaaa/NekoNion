#pragma once
#include<memory>
#include<unordered_map>

#include"../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// �I�u�W�F�N�g�Ǘ�
	/// </summary>
	class ObjectManager final
	{
	public:

		/// <summary>
		/// ����������
		/// </summary>
		static void InitObjManager();

        /// <summary>
        /// ���݂̃V�[���^�O���Z�b�g
        /// </summary>
        static void NowSceneSet(std::vector<std::string> scene_objtag) {
            objectmanager->m_SceneTag = scene_objtag;
        }

        /// <summary>
        /// �I�u�W�F�N�g�ǉ�
        /// </summary>
        /// <param name="newObj">:�ǉ��I�u�W�F�N�g</param>
        static void AddObj(class ObjectBase* newObj);

        /// <summary>
        /// �I�u�W�F�N�g�X�V
        /// </summary>
        /// <param name="deltaTime">:�f���^�^�C��</param>
        static void UpdateAllObj(const float deltaTime);

        /// <summary>
        /// �I�u�W�F�N�g�`��
        /// </summary>
        static void DrawAllObj();

        /// <summary>
        /// �S�I�u�W�F�N�g�폜
        /// </summary>
        static void ReleaseAllObj();

        /// <summary>
        /// �I�u�W�F�N�g�̎擾
        /// </summary>
        /// <param name="tag">�^�O��</param>
        /// <param name="index">�I�u�W�F�N�g�ԍ�</param>
        /// <returns>�w��̃I�u�W�F�N�g</returns>
        static ObjectBase* GetGameObj(std::string tagname, int index);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~ObjectManager();

	private:

		/// <summary>
		/// �R���X�g���N�^(�V���O���g��)
		/// </summary>
		ObjectManager();

        std::vector<std::string> m_SceneTag;                       // ���݂̃V�[���̃I�u�W�F�N�g�^�O
        static std::unique_ptr<ObjectManager> objectmanager;       //���g�̎���
        std::unordered_map<std::string, std::vector<std::shared_ptr<class ObjectBase>>> m_Objects;  //�I�u�W�F�N�g���X�g
	};
}