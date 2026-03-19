#include "atari2600_bus.h"

#include <fstream>
#include <cstdint>
#include <string>
#include <iostream>
#include <bitset>

Atari2600Bus::Atari2600Bus() {

}

Atari2600Bus::~Atari2600Bus() {

}

void Atari2600Bus::load_rom(std::string fname) {
	std::ifstream rom_file(fname, std::ios::in | std::ios::binary);

	/* get length of file */
	rom_file.seekg(0, std::ios::end);
	size_t length = rom_file.tellg();
	rom_file.seekg(0, std::ios::beg);

	if(length > sizeof(rom)) {
		length = sizeof(rom);
	}

	rom_file.read(reinterpret_cast<char*>(&rom[0]), length);
}

uint8_t Atari2600Bus::read(uint16_t addr) {
	addr &= mask; /* 6507 only has 13 of the 16 address lines connected */
	uint8_t out = 0x00;

	std::cout << "bus: reading at 0x" << std::hex << addr << std::endl;

	if(addr >= 0x0030 && addr <= 0x003d) {
		std::cout << "bus: reached tia read handler from 0x0030 to 0x003d" << std::endl;
		out = tia.read(addr);
	} else if(addr >= 0x0080 && addr <= 0x00ff) {
		std::cout << "bus: reached riot ram read handler from 0x0080 to 0x00ff" << std::endl;
		out = riot.read_ram(addr);
	} else if(addr >= 0x0280 && addr <= 0x0297) {
		std::cout << "bus: reached riot util read handler from 0x0280 to 0x0297" << std::endl;
		out = riot.read_util(addr);
	} else if(addr >= 0x1000 && addr <= 0x1fff) {
		std::cout << "bus: reached rom read handler from 0x1000 to 0x1fff" << std::endl;
		out = rom[addr & 0x0fff];
	}

	std::cout << "bus: got 0x" << std::hex << (int)out << std::endl;
	return out;
}

void Atari2600Bus::write(uint16_t addr, uint8_t data) {
	addr &= mask; /* 6507 only has 13 of the 16 address lines connected */
	std::cout << "bus: writing at 0x" << addr << std::endl;

	if(addr >= 0x0000 && addr <= 0x002c) {
		std::cout << "bus: reached tia write handler from 0x0030 to 0x003d" << std::endl;
		tia.write(addr, data);
	} else if(addr >= 0x0080 && addr <= 0x00ff) {
		std::cout << "bus: reached riot ram write handler from 0x0080 to 0x00ff" << std::endl;
		riot.write_ram(addr, data);
	} else if(addr >= 0x0280 && addr <= 0x0297) {
		std::cout << "bus: reached riot util write handler from 0x0280 to 0x0297" << std::endl;
		riot.write_util(addr, data);
	}
}
