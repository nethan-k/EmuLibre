#include "6532.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

RIOT6532::RIOT6532() {
	std::srand(std::time({}));
	for(int i = 0; i < 128; i++) {
		ram[i] = std::rand() % 256;
	}
}

RIOT6532::~RIOT6532() {

}

uint8_t RIOT6532::read_ram(uint8_t addr) {
	return ram[addr];
}

void RIOT6532::write_ram(uint8_t addr, uint8_t val) {
	ram[addr] = val;
}

uint8_t RIOT6532::read_util(uint8_t addr) {
	std::cout << "reached riot util read" << std::endl;
	return 0;
}

void RIOT6532::write_util(uint8_t addr, uint8_t val) {
	std::cout << "reached riot util write" << std::endl;
}
