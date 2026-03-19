#pragma once

#include <cstdint>

class ROM {
	public:
		ROM();
		~ROM();

		uint8_t rom[4096];

		uint8_t read(uint16_t addr);
		void write(uint16_t addr, uint8_t data);
};
