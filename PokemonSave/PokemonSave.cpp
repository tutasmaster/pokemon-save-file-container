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
	std::cout << "\tCurrent Pokemon: " << (int)sf.party_size << "\n\n";
	for(auto i = 0; i < sf.party_size; i++)
	{
		std::cout << "\tID: " << std::hex << (int)sf.party_data[i].id << "\n";
		std::cout << "\tNAME: " << Gen1::Pokemon_List[sf.party_data[i].id].name << "\n";
		std::cout << "\tNICK: " << sf.party_data[i].name << "\n";
		std::cout << "\tOT: " << sf.party_data[i].trainer_name << "\n";
		std::cout << "\tTYPE 1: " << std::hex << Gen1::Pokemon_List[sf.party_data[i].id].type1 << "\n";
		std::cout << "\tTYPE 2: " << std::hex << Gen1::Pokemon_List[sf.party_data[i].id].type2 << "\n";
		std::cout << "\n";
	}
	std::cout << "\tBAG_DATA:\n";
	std::cout << "\tCurrent Items: " << (int)sf.bag_size << "\n\n";
	for(auto i = 0; i < sf.bag_size; i++)
	{
		std::cout << "\tName: " << Gen1::Item_List[sf.bag_data[i].id].name << "\n";
		std::cout << "\tQuantity: " << (int)sf.bag_data[i].quantity << "\n\n";
	}

	std::cout << "BOX_DATA:\n";
	for(auto i = 0; i < 12; i++)
	{
		std::cout << "\tBOX " << std::dec << (int)i << "\n";
		for(auto j = 0; j < sf.box_data[i].size; j++)
			std::cout << "\t\tNAME: " << Gen1::Pokemon_List[sf.box_data[i].data[j].id].name << "\n";
	}
	Gen1::ShowdownGenerator sg(sf);
	return 0;
}
