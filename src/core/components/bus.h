#pragma once

#include "6502.h"
#include "6532.h"
#include "tia.h"

#include <cstdint>
#include <iostream>

class Bus {
	public:
		Bus();
		~Bus();

		TIA tia;
		RIOT6532 riot;
		uint8_t rom[];

		uint8_t read(uint16_t addr);
		void write(uint16_t addr, uint8_t val);
};
