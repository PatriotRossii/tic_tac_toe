#pragma once

#include <vector>

namespace tic_tac_toe {
template<typename Container>
struct IsSame {
	const Container& container;
public:
	IsSame(const Container& container);
	bool operator()(std::vector<std::size_t> indeces) const; 
	bool operator()(std::vector<std::pair<std::size_t, std::size_t>> indeces) const;
};
}