SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_OnFrame::
	map_script_2 VAR_SAFFRON_CITY_STATE, 0,  SaffronCity_EventScript_BaobaCall
	.2byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_EventScript_BaobaCall::
	pokenavcall SaffronCity_Text_Baoba
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	setvar VAR_SAFFRON_CITY_STATE, 1
	end

SaffronCity_Text_Baoba:
	.string "{JPN}えんちょう バオバ: {PLAYER}!\p"
	.string "{JPN}えんちょうの バオバじゃ.\p"
	.string "{JPN}サファリゾーンが また\n"
	.string "{JPN}かくちょうしたことを\l"
	.string "{JPN}つたえるために でんわしたのじゃ!\p"
	.string "{JPN}ついに わしの サファリゾーンが\n"
	.string "{JPN}かんぜんに じつげんしたぞ!\p"
	.string "{JPN}ばしょを おぼえておるじゃろう?\p"
	.string "{JPN}タンバシティの すぐ にしじゃ!\nまた あいにこい!$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "{JPN}わたし ロコンが だいすき! :D$"

SaffronCity_Text_Lass1:
	.string "{JPN}ひとの まねをするのが\n"
	.string "{JPN}とくいな ちいさな おんなのこが\l"
	.string "{JPN}ここに すんでるのよ.\p"
	.string "{JPN}はなしてる あいても まねしちゃう\nから こんらんするわ.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "{JPN}ものまねむすめが\n"
	.string "{JPN}かなしそうだったわ.\p"
	.string "{JPN}だいじにしてた ポケにんぎょうの\nピッピを なくしちゃったんですって.$"

SaffronCity_Text_PokefanM:
	.string "{JPN}きみ ジョウトから きたのか?\p"
	.string "{JPN}リニアが うごいてるなら\n"
	.string "{JPN}すぐに かえれるな.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "{JPN}きみ ジョウトから きたのか?\p"
	.string "{JPN}リニアに のれば\n"
	.string "{JPN}すぐに かえれるぞ.$"

SaffronCity_Text_CooltrainerM:
	.string "{JPN}ジムに いって トレーナーたちと\n"
	.string "{JPN}たたかうのを たのしみにしてたのに...\p"
	.string "{JPN}となりの つかわれてない\n"
	.string "{JPN}ジムに はいっちゃったよ.\p"
	.string "{JPN}はずかしかったなあ.$"

SaffronCity_Text_CooltrainerF:
	.string "{JPN}ここは シルフカンパニー.\n"
	.string "{JPN}ポケモングッズで ゆうめいよ.\p"
	.string "{JPN}むかし ロケットだんが\n"
	.string "{JPN}ねらってたのよ.$"

SaffronCity_Text_Fisher:
	.string "{JPN}むしゃ... むしゃ...\p"
	.string "{JPN}はつでんしょで おおきな\n"
	.string "{JPN}トラブルが おきてるって きいたよ.\p"
	.string "{JPN}むしゃ... むしゃ...$"
SaffronCity_Text_Fisher_ReturnedPart:
	.string "{JPN}むしゃ... むしゃ...\p"
	.string "{JPN}はつでんしょで おおきな トラブルが\n"
	.string "{JPN}あったって きいたよ.\p"
	.string "{JPN}むしゃ... むしゃ... はあー おなかいっぱい!$"
SaffronCity_Text_Youngster1:
	.string "{JPN}はじめて ろじうらに はいるのは\n"
	.string "{JPN}ちょっと ドキドキするなあ.$"

SaffronCity_Text_Youngster2:
	.string "{JPN}トキワには トレーナーハウスって\n"
	.string "{JPN}ばしょが あって\l"
	.string "{JPN}せかいじゅうの トレーナーが\lあつまるんだって.$"

SaffronCity_Text_Lass2:
	.string "{JPN}わたしたちの まちが\n"
	.string "{JPN}ラジオばんぐみで しょうかいされたの.\p"
	.string "{JPN}じぶんの まちが ほめられるのは\n"
	.string "{JPN}うれしいけど ちょっと\l"
	.string "{JPN}はずかしいわね.$"

SaffronCity_Text_Sign:
	.string "{JPN}ヤマブキシティ\p"
	.string "{JPN}かがやく おうごんの しょうぎょうとし$"

SaffronCity_Text_GymSign:
	.string "{JPN}ヤマブキシティ\n"
	.string "{JPN}ポケモンジム\l"
	.string "{JPN}ジムリーダー: ナツメ\p"
	.string "{JPN}エスパーポケモンの たつじん!$"

SaffronCity_Text_FightingDojoSign:
	.string "{JPN}だれでも かんげい!\n"
	.string "{JPN}かくとうどうじょう$"

SaffronCity_Text_SilphCoSign:
	.string "{JPN}シルフカンパニー\n"
	.string "{JPN}ビルディング$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "{JPN}エスパーおじさんの\n"
	.string "{JPN}いえ$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "{JPN}ヤマブキシティ\n"
	.string "{JPN}リニアえき$"
