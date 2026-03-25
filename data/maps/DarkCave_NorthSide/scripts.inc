DarkCave_NorthSide_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_NorthSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "{JPN}うわあ!びっくりしたあ!\p"
	.string "{JPN}くろいメガネを かけてたから\n"
    .string "{JPN}きみに きがつかなかったよ.\p"
	.string "{JPN}ここで なにを してるかって?\p"
    .string "{JPN}いや きにしないで くれよ.\p"
	.string "{JPN}くろいメガネを あげるから\n"
    .string "{JPN}ぼくを みたこと わすれて\n"
	.string "{JPN}くれるかな?$"

DarkCave2_Text_Nerd2:
    .string "{JPN}くろいメガネは あくタイプの\n"
	.string "{JPN}わざの いりょくを あげるんだ.$"
