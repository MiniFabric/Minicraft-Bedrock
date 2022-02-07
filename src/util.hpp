//
// Created by ENDERZOMBI102 on 07/02/2022.
//

#pragma once

#include <vector>

namespace MiniCraft::Util {

	template<typename T, typename I> requires std::bidirectional_iterator<I>
	inline auto contains( I *vec, T *element ) -> bool {
		return std::find( vec->begin(), vec->end(), element ) != vec->end();
	}

}