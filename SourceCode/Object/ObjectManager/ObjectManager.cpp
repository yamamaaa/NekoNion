#include "ObjectManager.h"

namespace object
{
    //実体の中身を空に
    std::unique_ptr<ObjectManager>ObjectManager::objectmanager = nullptr;

    ObjectManager::ObjectManager()
        :m_Objects(0)
    {
        //処理なし
    }

    ObjectManager::~ObjectManager()
    {
        //処理なし
    }

    void ObjectManager::InitObjManager()
    {
        //自身の中身が空ならインスタンス生成
        if (!objectmanager)
        {
            objectmanager.reset(new ObjectManager);
        }
    }

    void ObjectManager::AddObj(ObjectBase* newObj)
    {
        //タグの検索をしてオブジェクト登録
        std::string tag = newObj->GetTagName();
        objectmanager->m_Objects[tag].emplace_back(newObj);
    }

    void ObjectManager::ReleaseAllObj()
    {
        //オブジェクト削除
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
                // 該当タグにあるすべてのオブジェクトを更新
                for (auto& obj : objectmanager->m_Objects[tag])
                {
                    //更新
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
        //データがあればタグの指定オブジェクトを返す
        if (objectmanager->m_Objects[tagname].empty() || objectmanager->m_Objects[tagname].size() < index)
        {
            return nullptr;
        }
        return objectmanager->m_Objects[tagname][index].get();
    }
}