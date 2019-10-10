#include "Gen1.h"

int main()
{
	Gen1::SaveFile sf;
	Gen1::SaveFileReader::ReadToFile(sf,"Pokemon Blue.sav");

	std::cout << "PLAYER_DATA:\n";
	std::cout << "\tPlayer Name: " << sf.player_data.name << "\n";
	std::cout << "\tRival Name: " << sf.player_data.rival_name << "\n";
	std::cout << "\tMoney: " << sf.player_data.money << "€\n\n";

	std::cout << "PARTY_DATA:\n";
	std::cout << "\tCurrent Pokemon: " << (int)sf.party_size << "\n";
	for(auto i = 0; i < sf.party_size; i++){
		std::cout << "\t\tID: " << std::hex << (int)sf.party_data[i].id << "\n";
		std::cout << "\t\tCUR HP: " << std::dec << (int)sf.party_data[i].hp << "\n";
		std::cout << "\t\tLEVEL: " << std::dec << (int)sf.party_data[i].level << "\n";
		std::cout << "\t\tSTATUS CONDITION: " << std::hex << (int)sf.party_data[i].status_condition << "\n";
		std::cout << "\t\tTYPE 1: " << std::hex << (int)sf.party_data[i].type1 << "\n";
		std::cout << "\t\tTYPE 2: " << std::hex << (int)sf.party_data[i].type2 << "\n";
		std::cout << "\n";
	}
	
	return 0;
}
