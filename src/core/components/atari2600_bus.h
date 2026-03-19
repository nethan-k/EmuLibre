#pragma once

#include "base_bus.h"
#include "tia.h"
#include "6532.h"

#include <cstdint>
#include <string>
#include <fstream>

class Atari2600Bus : public virtual BaseBus {
	public:
		Atari2600Bus();
		~Atari2600Bus();

		TIA tia; /* television interface adapter */
		RIOT6532 riot; /* ram, input/output, timer chip. also known as 6532 */

		uint16_t mask = 0x1fff;
		uint8_t rom[4096]; /* emulated rom */

		/* loads a rom file into rom */
		void load_rom(std::string fname);
		uint8_t read(uint16_t addr);
		void write(uint16_t addr, uint8_t data);
};
