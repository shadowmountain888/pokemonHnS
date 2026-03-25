MtMortar_1F_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Nugget::
    finditem ITEM_NUGGET
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "{JPN}こんどは まけないぞ!$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "{JPN}こどもに まけるなんて...?$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "{JPN}まえに からてつかいが\n"
	.string "{JPN}たたかいを もうしこんできた\p"
	.string "{JPN}とんでもなく つよくて\n"
	.string "{JPN}ぼこぼこに やられたよ\p"
	.string "{JPN}しゅぎょうの ためだって\n"
	.string "{JPN}おくに いっちゃった\p"
	.string "{JPN}げんきに してるかな?$"

MountMortar2_Text_SupernerdMarkusSeen:
	.string "{JPN}おい! ヒュー!$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "{JPN}きみを ほかの ひとと\n"
	.string "{JPN}まちがえて しまった...$"
MountMortar2_Text_SupernerdMarkusAfter:
	.string "{JPN}シロガネやまを たんけんしに\n"
	.string "{JPN}きたんだけど パートナーと\l"
	.string "{JPN}はぐれて しまった...\p"
	.string "{JPN}たきのぼりを おぼえた\n"
	.string "{JPN}シードラを つかう\l"
	.string "{JPN}トレーナーに あったかい?$"
