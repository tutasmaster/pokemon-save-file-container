#pragma once

#include "Gen1Pokemon.h"

namespace Gen1
{
	struct Move
	{
		enum Category
		{
			Physical,
			Special,
			Status
		};
		std::string name = "MissingNo";
		Pokemon::Type type = Pokemon::None;
		Category category;
		uint8_t max_pp = 0;
		uint8_t power = 0;
		uint8_t accuracy = 0;
	};

	const Move Move_List[] =
	{
		{"Pound", Pokemon::Normal, Move::Physical, 35, 40, 100},
		{"Karate Chop", Pokemon::Normal,Move::Physical, 25, 50, 100},
		{"Double Slap", Pokemon::Normal, Move::Physical, 10, 15, 85},
		{"Comet Punch", Pokemon::Normal,Move::Physical,15,18,85},
		{"Mega Punch", Pokemon::Normal, Move::Physical, 20,80,85},
		{"Pay Day", Pokemon::Normal,Move::Physical,20,40,100},
		{"Fire Punch", Pokemon::Fire,Move::Physical,15,75,100},
		{"Ice Punch",Pokemon::Ice,Move::Physical,15,75,100},
		{"Thunder Punch",Pokemon::Electric,Move::Physical,15,75,100},
		{"Scratch", Pokemon::Normal, Move::Physical, 15, 75, 100},
		{"Vice Grip", Pokemon::Normal, Move::Physical, 30,55,100},
		{"Guillotine", Pokemon::Normal, Move::Physical,5,0,30},
		{"Razor Wind", Pokemon::Normal, Move::Special,10,80,75},
		{"Swords Dance",Pokemon::Normal, Move::Status,30,0,0},
		{"Cut", Pokemon::Normal,Move::Physical,30,50,95},
		{"Gust",Pokemon::Normal,Move::Special,35,40,100},
		{"Wing Attack", Pokemon::Flying, Move::Physical, 35, 35, 100},
		{"Whirlwind", Pokemon::Normal, Move::Status, 20, 0, 85},
		{"Fly", Pokemon::Flying,Move::Physical,15,90,95},
		{"Bind", Pokemon::Normal, Move::Physical, 20, 15, 75},
		{"Slam", Pokemon::Normal, Move::Physical, 20, 80, 75},
		{"Vine Whip", Pokemon::Grass, Move::Physical, 10, 35, 100},
		{"Stomp", Pokemon::Normal,Move::Physical,20,65,100},
		{"Double Kick",Pokemon::Fight, Move::Physical, 30, 30, 100},
		{"Mega Kick", Pokemon::Normal, Move::Physical, 5, 120, 75},
		{"Jump Kick", Pokemon::Fight, Move::Physical,25,70,95},
		{"Rolling Kick", Pokemon::Fight, Move::Physical,15,60,85},
		{"Sand Attack", Pokemon::Normal,Move::Status,15,0,100},
		{"Headbutt",Pokemon::Normal, Move::Physical,15,70,100},
		{"Horn Attack",Pokemon::Normal,Move::Physical, 25, 65, 100},
		{"Fury Attack",Pokemon::Normal,Move::Physical, 20, 15, 85},
		{"Horn Drill",Pokemon::Normal,Move::Physical, 5, 0, 30},
		{"Tackle",Pokemon::Normal,Move::Physical, 35, 40, 100},
		{"Body Slam",Pokemon::Normal,Move::Physical, 15, 85, 100},
		{"Wrap",Pokemon::Normal,Move::Physical, 20, 15, 85},
		{"Take Down",Pokemon::Normal,Move::Physical, 20, 90, 85},
		{"Thrash",Pokemon::Normal,Move::Physical, 20, 90, 100},
		{"Double-Edge",Pokemon::Normal,Move::Physical, 15, 100, 10},
		{"Tail Whip", Pokemon::Normal, Move::Status, 30, 0, 100},
		{"Poison Sting",Pokemon::Poison, Move::Physical, 35, 15, 100},
		{"Twineedle", Pokemon::Bug, Move::Physical, 20, 25, 100},
		{"Pin Missile", Pokemon::Bug, Move::Physical, 20, 25, 95},
		{"Leer",Pokemon::Normal, Move::Status, 30, 0, 100},
		{"Bite",Pokemon::Normal, Move::Status, 15,60, 100},
		{"Growl", Pokemon::Normal, Move::Status, 40,0, 100},
		{"Roar", Pokemon::Normal, Move::Status, 20, 0, 100},
		{"Sing",Pokemon::Normal,Move::Status,15,55},
		{"Supersonic",Pokemon::Normal,Move::Status,20,55},
		{"Sonic Boom",Pokemon::Normal,Move::Special,20,0,90},
		{"Disable",Pokemon::Normal,Move::Status,20,0,55},
		{"Acid",Pokemon::Poison,Move::Special,30,40,100},
		{"Ember",Pokemon::Fire,Move::Special,25,40,100},
		{"Flamethrower",Pokemon::Fire,Move::Special,15,95,100},
		{"Mist",Pokemon::Ice,Move::Status,30,0,0},
		{"Water Gun",Pokemon::Ice,Move::Special,25,40,100},
		{"Hydro Pump", Pokemon::Water, Move::Special, 5, 120, 80},
		{"Surf",Pokemon::Water,Move::Special,5,95,100},
		{"Ice Beam",Pokemon::Ice,Move::Special,10,95,100},
		{"Blizzard",Pokemon::Ice,Move::Special,5,120,90},
		{"Psybeam",Pokemon::Psychic,Move::Special,20,65,100},
		{"Bubble Beam", Pokemon::Water, Move::Special,20,65,100},
		{"Aurora Beam",Pokemon::Ice,Move::Special,20,65,100},
		{"Hyper Beam", Pokemon::Normal,Move::Special,5,150,90},
		{"Peck",Pokemon::Flying,Move::Physical,35,35,100},
		{"Drill Peck",Pokemon::Flying,Move::Physical,35,35,100},
		{"Submission",Pokemon::Fight,Move::Physical,25,80,80},
		{"Low Kick",Pokemon::Fight,Move::Physical,20,50,90},
		{"Counter",Pokemon::Fight,Move::Physical,20,0,100},
		{"Seismic Toss", Pokemon::Fight,Move::Physical,20,0,100},
		{"Strength",Pokemon::Normal,Move::Physical,20,80,100},
		{"Absorb",Pokemon::Grass,Move::Special,20,20,100},
		{"Mega Drain",Pokemon::Grass,Move::Special,10,40,100},
		{"Leech Seed",Pokemon::Grass,Move::Status,10,0,90},
		{"Growth",Pokemon::Normal,Move::Status,40,0,0},
		{"Razor Leaf",Pokemon::Grass,Move::Physical,25,55,95},
		{"Solar Beam",Pokemon::Grass,Move::Special,10,120,100},
		{"Poison Powder",Pokemon::Poison,Move::Status,35,0,75},
		{"Stun Spore", Pokemon::Grass, Move::Status,30,0,75},
		{"Sleep Powder",Pokemon::Grass,Move::Status,15,75},
		{"Petal Dance",Pokemon::Grass,Move::Special,20,70,100},
		{"String Shot",Pokemon::Bug,Move::Status,40,0,95},
		{"Dragon Rage", Pokemon::Dragon,Move::Special,10,0,100},
		{"Fire Spin", Pokemon::Fire,Move::Special,15,15,85},
		{"Thunder Shock",Pokemon::Electric,Move::Special,30,40,100},
		{"Thunderbolt",Pokemon::Electric,Move::Special,15,95,100},
		{"Thunder Wave", Pokemon::Electric,Move::Status,20,100},
		{"Thunder",Pokemon::Electric,Move::Special,10,120,70},
		{"Rock Throw",Pokemon::Rock,Move::Physical,15,50,65},
		{"Earthquake",Pokemon::Rock,Move::Physical,15,50,90},
		{"Fissure",Pokemon::Ground,Move::Physical,5,0,30},
		{"Dig",Pokemon::Ground,Move::Physical,10,100,100},
		{"Toxic",Pokemon::Poison,Move::Status,10,0,85},
		{"Confusion",Pokemon::Psychic,Move::Special,25,50,100},
		{"Psychic",Pokemon::Psychic,Move::Special,10,90,100},
		{"Hypnosis",Pokemon::Psychic,Move::Status,20,0,60},
		{"Meditate",Pokemon::Psychic,Move::Status,40,0,0},
		{"Agility",Pokemon::Normal,Move::Physical,30,0,0},
		{"Quick Attack",Pokemon::Normal,Move::Physical,30,40,100},
		{"Rage",Pokemon::Normal,Move::Physical,20,20,100},
		{"Teleport",Pokemon::Psychic,Move::Status,20,0,0}
	};
}