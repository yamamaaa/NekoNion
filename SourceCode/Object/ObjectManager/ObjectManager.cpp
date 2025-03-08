#include "ObjectManager.h"

namespace object
{
    //���̂̒��g�����
    std::unique_ptr<ObjectManager>ObjectManager::objectmanager = nullptr;

    ObjectManager::ObjectManager()
        :m_Objects(0)
    {
        //�����Ȃ�
    }

    ObjectManager::~ObjectManager()
    {
        //�����Ȃ�
    }

    void ObjectManager::InitObjManager()
    {
        //���g�̒��g����Ȃ�C���X�^���X����
        if (!objectmanager)
        {
            objectmanager.reset(new ObjectManager);
        }
    }

    void ObjectManager::AddObj(ObjectBase* newObj)
    {
        //�^�O�̌��������ăI�u�W�F�N�g�o�^
        std::string tag = newObj->GetTagName();
        objectmanager->m_Objects[tag].emplace_back(newObj);
    }

    void ObjectManager::ReleaseAllObj()
    {
        //�I�u�W�F�N�g�폜
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            objectmanager->m_Objects[tag].clear();
        }

        objectmanager->m_Objects.clear();
    }

    void ObjectManager::UpdateAllObj(const float deltatime)
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            if (!objectmanager->m_Objects[tag].empty())
            {
                // �Y���^�O�ɂ��邷�ׂẴI�u�W�F�N�g���X�V
                for (auto& obj : objectmanager->m_Objects[tag])
                {
                    //�X�V
                    obj->UpdateObj(deltatime);
                }
            }
        }
    }

    void ObjectManager::DrawAllObj()
    {
        for (std::string& tag : objectmanager->m_SceneTag)
        {
            if (!objectmanager->m_Objects[tag].empty())
            {
                for (auto& obj : objectmanager->m_Objects[tag])
                {
                    obj->DrawObj();
                }
            }
        }
    }

    ObjectBase* ObjectManager::GetGameObj(std::string tagname, int index)
    {
        //�f�[�^������΃^�O�̎w��I�u�W�F�N�g��Ԃ�
        if (objectmanager->m_Objects[tagname].empty() || objectmanager->m_Objects[tagname].size() < index)
        {
            return nullptr;
        }
        return objectmanager->m_Objects[tagname][index].get();
    }
}