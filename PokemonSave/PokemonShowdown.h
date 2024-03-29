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
					std::to_string(sf.party_data[i].evs.hp_val + 1)  + " HP / " +
					std::to_string(sf.party_data[i].evs.atk_val + 1) + " Atk / " +
					std::to_string(sf.party_data[i].evs.def_val + 1) + " Def / " +
					std::to_string(sf.party_data[i].evs.spc_val + 1) + " SpA / " +
					std::to_string(sf.party_data[i].evs.spd_val + 1) + " Spe " + "\n";

				output_text += "IVs: " +
					std::to_string(sf.party_data[i].ivs.hp * 2) + " HP / " +
					std::to_string(sf.party_data[i].ivs.atk * 2) + " Atk / " +
					std::to_string(sf.party_data[i].ivs.def * 2) + " Def / " +
					std::to_string(sf.party_data[i].ivs.spc * 2) + " SpA / " +
					std::to_string(sf.party_data[i].ivs.spd * 2) + " Spe " + "\n";

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

		ShowdownGenerator(RAW_Pokemon arr[],int size = 6, std::string output = "output.txt")
		{
			std::string output_text = "";

			for (auto i = 0; i < size; i++)
			{
				if (arr[i].name == StrToUpper(Pokemon_List[arr[i].id].name))
					output_text += Pokemon_List[arr[i].id].name + "\n";
				else
					output_text += std::string(arr[i].name) + " (" + Pokemon_List[arr[i].id].name + ")\n";
				output_text += "Ability: none\n";
				output_text += "Level: " + std::to_string(arr[i].level) + "\n";
				output_text += "EVs: " +
					std::to_string(arr[i].evs.hp_val + 1) + " HP / " +
					std::to_string(arr[i].evs.atk_val + 1) + " Atk / " +
					std::to_string(arr[i].evs.def_val + 1) + " Def / " +
					std::to_string(arr[i].evs.spc_val + 1) + " SpA / " +
					std::to_string(arr[i].evs.spd_val + 1) + " Spe " + "\n";

				output_text += "IVs: " +
					std::to_string(arr[i].ivs.hp * 2) + " HP / " +
					std::to_string(arr[i].ivs.atk * 2) + " Atk / " +
					std::to_string(arr[i].ivs.def * 2) + " Def / " +
					std::to_string(arr[i].ivs.spc * 2) + " SpA / " +
					std::to_string(arr[i].ivs.spd * 2) + " Spe " + "\n";

				//TODO: ADD IVs

				if (arr[i].move1 != 0)
					output_text += "- " + Move_List[arr[i].move1 - 1].name + "\n";
				if (arr[i].move2 != 0)
					output_text += "- " + Move_List[arr[i].move2 - 1].name + "\n";
				if (arr[i].move3 != 0)
					output_text += "- " + Move_List[arr[i].move3 - 1].name + "\n";
				if (arr[i].move4 != 0)
					output_text += "- " + Move_List[arr[i].move4 - 1].name + "\n";

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