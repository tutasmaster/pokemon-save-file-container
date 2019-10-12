#pragma once

#include "Gen1.h"

namespace Gen1
{
	class ShowdownGenerator
	{
	public:
		ShowdownGenerator(Gen1::SaveFile sf,std::string output = "output.txt")
		{
			std::string output_text = "";

			for(auto i = 0; i < sf.party_size;i++)
			{
				if(sf.party_data[i].name == StrToUpper(Pokemon_List[sf.party_data[i].id].name))
					output_text += Pokemon_List[sf.party_data[i].id].name + "\n";
				else
					output_text += std::string(sf.party_data[i].name) + " (" + Pokemon_List[sf.party_data[i].id].name + ")\n";
				output_text += "Ability: none\n";
				output_text += "Level: " + std::to_string(sf.party_data[i].level) + "\n";
				output_text += "EVs: " +
					std::to_string(sf.party_data[i].evs.hp_val)  + " HP / " +
					std::to_string(sf.party_data[i].evs.atk_val) + " Atk / " +
					std::to_string(sf.party_data[i].evs.def_val) + " Def / " +
					std::to_string(sf.party_data[i].evs.spc_val) + " SpA / " +
					std::to_string(sf.party_data[i].evs.spd_val) + " Spe " + "\n";

				//TODO: ADD IVs

				if (sf.party_data[i].move1 != 0)
					output_text += "- " + Move_List[sf.party_data[i].move1 - 1].name + "\n";
				if (sf.party_data[i].move2 != 0)
					output_text += "- " + Move_List[sf.party_data[i].move2 - 1].name + "\n";
				if (sf.party_data[i].move3 != 0)
					output_text += "- " + Move_List[sf.party_data[i].move3 - 1].name + "\n";
				if (sf.party_data[i].move4 != 0)
					output_text += "- " + Move_List[sf.party_data[i].move4 - 1].name + "\n";

				output_text += "\n";
			}

			std::cout << output_text;
			
			std::ofstream output_file(output);
			output_file.write(output_text.c_str(), output_text.size());
			output_file.close();

			
		}
	private:
		static std::string StrToUpper(std::string str)
		{
			std::string result;
			for(int i = 0; i < str.size(); i++)
			{
				result += std::toupper(str[i]);
			}
			return result;
		}
	};
}