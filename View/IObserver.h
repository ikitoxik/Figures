////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ IObserver
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>
#include <vector>
#include "../Geometry/Primitive.h"

namespace view
{
	using PrimitiveSPtr = std::shared_ptr<geometry::IPrimitive>;
	using PrimitiveContainer = std::vector<PrimitiveSPtr>;

	////////////////////////////////////////////////////////////////////////////////
	//
	/// ����� IObserver
	/**
	*/
	////////////////////////////////////////////////////////////////////////////////
	class IObserver
	{
	public:
		/// ����������
		virtual ~IObserver() = default;
		/// �������� �������������
		virtual void Update(const PrimitiveContainer& prim_container) = 0;
	};
}// namespace view