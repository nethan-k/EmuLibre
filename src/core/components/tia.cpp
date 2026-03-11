#include "tia.h"
#include <iostream>

TIA::TIA() {

}

TIA::~TIA() {

}

uint8_t TIA::read(uint8_t addr) {
	std::cout << "reached tia read()" << std::endl;
	return 0;
}

void TIA::write(uint8_t addr, uint8_t val) {
	std::cout << "reached tia write()" << std::endl;
}
