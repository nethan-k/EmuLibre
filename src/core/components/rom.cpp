#include "rom.h"

ROM::ROM() {

}

ROM::~ROM() {

}

uint8_t ROM::read(uint16_t addr) {
	return rom[addr];
}

void ROM::write(uint16_t addr, uint8_t data) {

	/*
	 * this function will only work if you
	 * set the game running variable to false.
	 * this function is here so i can load
	 * the game rom.
	*/

	if(!running) rom[addr] = data;
}
