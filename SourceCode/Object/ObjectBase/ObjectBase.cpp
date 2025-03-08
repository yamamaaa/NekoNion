#include "ObjectBase.h"

namespace object
{
	ObjectBase::ObjectBase(std::string tagname)
		:m_ObjTag(tagname),
		m_ObjHandle(-1),
		m_ObjPos(),
		m_ObjScale(VGet(0.1f, 0.1f, 0.1f)),
		m_ObjWorldPos(),
		m_ObjLocalPos(),
		m_ObjDir(VGet(1, 0, 0)),
		m_ColInfo()
	{
		//èàóùÇ»Çµ
	}

	ObjectBase::~ObjectBase()
	{
		//èàóùÇ»Çµ
	}

	void ObjectBase::CalcObjPos()
	{
		m_ObjPos = VAdd(m_ObjWorldPos, m_ObjLocalPos);
	}
}