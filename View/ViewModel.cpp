////////////////////////////////////////////////////////////////////////////////
//
/**
	\file
	\brief ���������� ������ ViewModel
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "ViewModel.h"
#include "IPainter.h"
#include "../Utils/Last.h"

namespace view
{

	//------------------------------------------------------------------------------
/**
	��������� ���������� �������� ���������
	\return ��������� � ������� ��� ���������
*/
//---
	std::vector<DrawData> ViewModel::GetDrawData()
	{
		return m_data;
	}

	//------------------------------------------------------------------------------
	/**
		���������
		\param painter ����������
	*/
	//---
	void ViewBase::Draw(view::IPainter& painter)
	{
		auto&& allDrawData = GetDrawData();
		for (auto&& drawData : allDrawData)
			painter.Draw(drawData);
	}
	//------------------------------------------------------------------------------
	/**
		��������� ������ �� ������
		\param prim_container ��������� � ������� ��� ���������
	*/
	//---
	void ViewModel::Update(const PrimitiveContainer& prim_container)
	{
		QColor color = Qt::blue;
		constexpr unsigned int width = 2;
		m_data.clear();
		for (const auto& i : prim_container)
		{
			DrawData temp{ i, color, width };
			m_data.emplace_back(temp);
		}
	}

} // namespace view