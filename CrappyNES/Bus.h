#pragma once
//use cstdint to rename the standard types into explicit types
#include <cstdint>
#include <array>
#include "cpu6502.h"
class Bus
{
public:
	Bus();
	~Bus();

public: //devices hooked to bus
	cpu6502 cpu;

	//Virtual RAM
	std::array<uint8_t, 64 * 1024> ram;

public: //Bus Read & Write, Don't worry about emulating R/W signal because it is implyed by which function is called
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool bReadOnly = false);
};

