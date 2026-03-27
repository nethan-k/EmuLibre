#include <iostream>
#include <string>
#include <bitset>

#include "components/6502.h"
#include "components/atari2600_bus.h"

int main() {
	CPU6502 cpu;
	cpu.bus = new Atari2600Bus;

	cpu.bus->load_rom("main.bin"); /* load rom file */
	cpu.reset(); /* trigger reset signal */

	/* user input */
	while(true) {
		char x;
		std::cin >> x;

		switch(x) {
		case 'n':
			cpu.clock();
			break;

		case 's': {
			std::cout << (std::bitset<8>)cpu.sr << std::endl;
			break;
		}

		case 'r':
			std::cout << "a: " << (int)cpu.a;
			std::cout << ", x: " << (int)cpu.x;
			std::cout << ", y: " << (int)cpu.y;
			std::cout << ", sp: " << (int)cpu.sp;
			std::cout << ", pc: " << (int)cpu.pc << std::endl;
			break;
		}
	}

	delete cpu.bus;
	return 0;
 }
