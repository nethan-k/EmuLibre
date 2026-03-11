#pragma once

#include <cstdint>

/* https://web.archive.org/web/20190926022044/http://www.ionpool.net/arcade/gottlieb/technical/datasheets/R6532_datasheet.pdf */

class RIOT6532 {
	public:
		RIOT6532();
		~RIOT6532();

		bool cs1;
		bool cs2;
		uint8_t ram[128];

		/* Read/Write RAM */
		uint8_t read_ram(uint8_t addr);
		void write_ram(uint8_t addr, uint8_t val);

		/* Read/Write I/O, Timer */
		uint8_t read_util(uint8_t addr);
		void write_util(uint8_t addr, uint8_t val);
};
