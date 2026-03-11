#include <iostream>
#include <fstream>

#include "components/6502.h"
#include "components/bus.h"

int main() {

	CPU6502 cpu;
	cpu.bus = new Bus;

	

	delete cpu.bus;
	return 0;
}
