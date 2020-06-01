#include "Bus.h"

Bus::Bus()
{
	// Connect our public cpu class to this bus
	cpu.ConnectBus(this);

	//Clear RAM contents of those dirty non zero bits (auto is an easy way to do this for arrays)
	for (auto &i : ram) i = 0x00;
}

Bus::~Bus()
{

}

void Bus::write(uint16_t addr, uint8_t data)
{
	//write the data to ram at given address (if address is in valid range)
	if (addr >= 0x0000 && addr <= 0xFFFF)
	{
		ram[addr] = data;
	}
}

uint8_t Bus::read(uint16_t addr, bool bReadOnly)
{
	//returns the data in ram at given address (if address is in valid range)
	if (addr >= 0x0000 && addr <= 0xFFFF)
	{
		return ram[addr];
	}

	//return 0 if outside of range
	return 0x00;
}