#include "PokemonShowdown.h"

int main()
{
	Gen1::SaveFile sf;
	Gen1::SaveFileReader::ReadToFile(sf,"Pokemon Yellow.sav");

	std::cout << "PLAYER_DATA:\n";
	std::cout << "\tPlayer Name: " << sf.player_data.name << "\n";
	std::cout << "\tRival Name: " << sf.player_data.rival_name << "\n";
	std::cout << "\tMoney: " << sf.player_data.money << "$\n\n";

	std::cout << "PARTY_DATA:\n";
	std::cout << "\tCurrent Pokemon: " << (int)sf.party_size << "\n";
	for(auto i = 0; i < sf.party_size; i++){
		std::cout << "\t\tID: " << std::hex << (int)sf.party_data[i].id << "\n";
		std::cout << "\t\tNAME: " << Gen1::Pokemon_List[sf.party_data[i].id].name << "\n";
		std::cout << "\t\tNICK: " << sf.party_data[i].name << "\n";
		std::cout << "\t\tOT: " << sf.party_data[i].trainer_name << "\n";
		std::cout << "\t\tTYPE 1: " << std::hex << Gen1::Pokemon_List[sf.party_data[i].id].type1 << "\n";
		std::cout << "\t\tTYPE 2: " << std::hex << Gen1::Pokemon_List[sf.party_data[i].id].type2 << "\n";
		std::cout << "\n";
	}
	Gen1::ShowdownGenerator sg(sf);
	return 0;
}
