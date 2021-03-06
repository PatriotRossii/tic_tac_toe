#pragma once

#include <vector>

namespace tic_tac_toe {
template<typename Container>
struct IsSame {
	const Container& container;
public:
	IsSame(const Container& container): container{container} { }
	bool operator()(std::vector<std::size_t> indeces) const {
		bool is_all_same = true;

		const auto& first = container[indeces[0]];
		for(std::size_t i = 1, size = indeces.size(); i != size; ++i) {
			is_all_same = is_all_same && container[indeces[i]] == first;
		}

		return is_all_same;
	}
	bool operator()(std::vector<std::pair<std::size_t, std::size_t>> indeces) const {
		bool is_all_same = true;

		const auto& first = container[indeces[0].first][indeces[0].second];
		for(std::size_t i = 1, size = indeces.size(); i != size; ++i) {
			is_all_same = is_all_same && container[indeces[i].first][indeces[i].second] == first;
		}

		return is_all_same;
	}
};
}