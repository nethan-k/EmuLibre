#pragma once

#include <cstdint>

class TIA {
	public:
		TIA();
		~TIA();

		uint8_t read(uint8_t addr);
		void write(uint8_t addr, uint8_t val);
};
