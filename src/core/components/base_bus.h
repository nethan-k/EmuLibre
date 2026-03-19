#pragma once

#include <cstdint>

class BaseBus {
	public:
		uint8_t read(uint16_t addr);
		void write(uint16_t addr, uint8_t data);
};
