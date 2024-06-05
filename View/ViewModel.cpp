////////////////////////////////////////////////////////////////////////////////
//
/**
	\file
	\brief Реализация класса ViewModel
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
	Получение контейнера объектов отрисовки
	\return контейнер с данными для отрисовки
*/
//---
	std::vector<DrawData> ViewModel::GetDrawData()
	{
		return m_data;
	}

	//------------------------------------------------------------------------------
	/**
		Рисование
		\param painter отрисовщик
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
		Получение данных из модели
		\param prim_container контейнер с данными для отрисовки
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