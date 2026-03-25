.set LOCALID_NURSE, 1
.set LOCALID_Bill, 4

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Bill::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_BillGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_BillExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_BillExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExitNorth::
	applymovement LOCALID_Bill, FallarborTown_PokemonCenter_1F_Movement_BillExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_BillExited
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExitWest::
	applymovement LOCALID_Bill, FallarborTown_PokemonCenter_1F_Movement_BillExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_BillExited
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_Bill
	clearflag FLAG_GARBAGEFLAG
	release
	end

FallarborTown_PokemonCenter_1F_Movement_BillExitNorth:
	walk_right
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
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_BillExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_BillGreeting:
	.string "{JPN}あ こんにちは.\n"
	.string "{JPN}きみは?\p"
	.string "{JPN}そうか {PLAYER}{KUN}だね.\n"
	.string "{JPN}トレーナーだということが\l"
	.string "{JPN}わかるよ.\p"
	.string "{JPN}ということは ぼくが\n"
	.string "{JPN}かいはつした ポケモン\l"
	.string "{JPN}ボックスシステムを つかって\l"
	.string "{JPN}いるんだね.\p"
	.string "{JPN}なぜ そんなことが わかるかって?\n"
	.string "{JPN}かんたんな すいりさ.\p"
	.string "{JPN}きみが ぼくに はなしかけたのは\n"
	.string "{JPN}この パソコンで なにかを\l"
	.string "{JPN}アクセス したかったからだ.\p"
	.string "{JPN}ああ しつれい.ぼくは マサキ.\pきみに あえて うれしいよ--\nボックスシステムを つかって\lくれて ありがたいね.\pもし よろしければ いえにも\nあそびに きてくれ.\lぼくのいえは 114ばんどうろに\lあるんだ.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "{JPN}むかし むかしの ポケモンって\n"
	.string "{JPN}どんな すがたを していたのかな?\p"
	.string "{JPN}まちの はずれにいる\n"
	.string "{JPN}カセキマニアなら しっているかも.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "{JPN}ハジツゲタウンの はたけでは\n"
	.string "{JPN}かざんばいの なかでも\l"
	.string "{JPN}そだつ つよい きのなえを\lうえているんだ.$"

