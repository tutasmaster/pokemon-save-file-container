

# Pokemon Save File Container
 A simple to use, header only container to handle pokemon save files, currently GENERATION I only in C++. (No additional libraries required)

## How to use

 1. Download the repo;
 2. Write some sample code like the one in PokemonSave.cpp
 3. Profit?
 The application will then show give you a quick run-down of what you have on your save-file and create a Pokemon-Showdown team with your pokemon into output.txt

## What can it do?

 - Load the entire of a Generation 1 (RBY) save-file into an easy to use container;
 - Decode simple pokemon-encoded text into ASCII;
 - Grab miscelaneous values like Pikachu's Friendship in Pokemon Yellow, collected badges and current money;
 - Check/Generate pokemon stats based on their DVs and IVs;
 - Includes an easy-to-use header of all the legal items,moves and pokemon in Generation I and their stats (list of moves per pokemon are not included);
 - Export any 6 pokemon into a [Pokemon-Showdown](https://pokemonshowdown.com/) team for battling

## Tested with:
 - Pokemon Red (U)
 - Pokemon Blue (U)
 - Pokemon Yellow (U)

## Credits
The entire code was written based off [Bulbapedia's resource](https://bulbapedia.bulbagarden.net/wiki/) on Generation I's [save-file](https://bulbapedia.bulbagarden.net/wiki/Save_data_structure_in_Generation_I), [pokemon](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_data_structure_in_Generation_I), [stats](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_base_stats_data_structure_in_Generation_I) and [character-encoding](https://bulbapedia.bulbagarden.net/wiki/Character_encoding_in_Generation_I)  wiki pages.