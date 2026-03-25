.set LOCALID_NURSE, 1
.set LOCALID_ECRUTEAK_BILL, 6

EcruteakCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "{JPN}やあぼくはマサキ\nきみはだれだい？\pふうん{PLAYER}か\nちょうどよいときにきたね$"
EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "{JPN}ぼくのポケモンボックスシステムの\nちょうせいがおわったところだよ\pポケモンをあずけるときにつかう\nパソコンのことだよ\pあれはぼくがかいはつしたんだ！\pこれでジョウトとカントーの\nすべてのポケモンセンターで\lぼくのパソコンがうごくよ\pコガネシティにかえって\nかぞくにあわなくちゃ\lいつでもあそびにきてよ！\pそれじゃあね！$"
EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "{JPN}まいこはんのおどりって\nすばらしいなあ\pポケモンをつかうすがたも\nおんなじようにきれいや$"
EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "{JPN}きみももっとたくさんの\nひととたたかいたいだろう？\pトレーナーがあつまる\nばしょがあるらしいぞ\pどこかって？\pオリーブシティのちょっと\nさきなんだ$"
EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "{JPN}ジムリーダーのマツバさま\n"
	.string "{JPN}すてきだわあ\l"
	.string "{JPN}あのクールなところがいいの\p"
	.string "{JPN}それにポケモンも\n"
	.string "{JPN}とってもつよいんだから$"
EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "{JPN}いかりのみずうみ..\n"
	.string "{JPN}あかいギャラドスのしゅつげん..\l"
	.string "{JPN}なにかじけんのにおいがするな$"
