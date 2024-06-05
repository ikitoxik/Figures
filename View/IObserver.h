////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ќбъ€вление класса IObserver
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
	///  ласс IObserver
	/**
	*/
	////////////////////////////////////////////////////////////////////////////////
	class IObserver
	{
	public:
		/// ƒеструктор
		virtual ~IObserver() = default;
		/// ќбновить представление
		virtual void Update(const PrimitiveContainer& prim_container) = 0;
	};
}// namespace view