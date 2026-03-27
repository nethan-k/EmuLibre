#include "tia.h"

TIA::TIA() {

}

TIA::~TIA() {

}

void clock() {

}

uint8_t TIA::read(uint16_t addr) {
	addr &= 0x00ff;
	return mem[addr];
}

void TIA::write(uint16_t addr, uint8_t val) {
	addr &= 0x00ff;
	mem[addr] = val;
}
