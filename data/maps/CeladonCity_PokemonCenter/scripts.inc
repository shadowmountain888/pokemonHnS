.set LOCALID_NURSE, 1

CeladonCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "{JPN}エリカは くさタイプの\n"
	.string "{JPN}ポケモンの たつじんよ.\p"
	.string "{JPN}ゆだんしてると\n"
	.string "{JPN}いたいめに あうわよ.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "{JPN}ロケットだんの アジトは\n"
	.string "{JPN}ゲームコーナーの ちかにあった.\p"
	.string "{JPN}あ  まてよ. それは\n"
	.string "{JPN}3ねんまえの はなしだった.$"

Celadon_Text_Eusine1:
	.string "{JPN}ミナキ: やあ!\p"
	.string "{JPN}きょうどに かえって\n"
	.string "{JPN}きたんだ.\pひさしぶりだなあ.$"

Celadon_Text_EusineLeaves:
	.string "{JPN}{PLAYER}  きいたか?\p"
	.string "{JPN}スズのとうに にじいろの\n"
	.string "{JPN}ポケモンが あらわれたという\n"
	.string "{JPN}あたらしい うわさが あるんだ.\p"
	.string "{JPN}ポケモンも かいふくしたし\n"
	.string "{JPN}エンジュシティに むかうよ.\n"
	.string "{JPN}また あおう  {PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "{JPN}ところで {PLAYER}.\p"
	.string "{JPN}でんせつの ポケモン\n"
	.string "{JPN}ライコウと エンテイは\l"
	.string "{JPN}つかまえたかい?\p"
	.string "{JPN}<...><...><...>\p"
	.string "{JPN}そうか...\p"
	.string "{JPN}どちらか いっぴきでも\n"
	.string "{JPN}つかまえたら\lしらせてくれよ.\pたのんだぞ {PLAYER}!$"
