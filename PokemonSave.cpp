#include "Gen1.h"

int main()
{
	Gen1::SaveFile sf;
	Gen1::SaveFileReader::ReadToFile(sf,"Pokemon Blue.sav");

	std::cout << "Player Name: " << sf.player_data.name << "!\n";
	return 0;
}
