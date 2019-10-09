#pragma once

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

namespace Gen1
{

	class SaveFile
	{
	public:
		struct PlayerData
		{
			char raw_name[12];
			char name[12];
		}player_data;

		void ProcessData();
		void ConvertName();
		
	private:
		std::vector<char> data;
		friend class SaveFileReader;
	};

	class SaveFileReader
	{
	public:
		static int ReadToFile(SaveFile &sf, char const* filename)
		{
			std::ifstream file(filename,std::ios::binary|std::ios::ate);
			std::ifstream::pos_type pos = file.tellg();
			std::vector<char> result(pos);
			file.seekg(0, std::ios::beg);
			file.read(&result[0], pos);
			sf.data = result;
			file.close();
			sf.ProcessData();
			return 0;
		}
	};
}