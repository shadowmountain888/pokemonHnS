.set LOCALID_GOLDENROD_ROOF_NERD, 1

GoldenrodCity_DepartmentStore_7F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
	.string "{JPN}ふう-つかれたわ\pときどきかいものにつかれると\nおくじょうにやすみにくるの$"
GoldenrodDeptStore_Text_RoofFisher:
	.string "{JPN}なんですって？おとながこれに\nはまってわるいですか？\pまいにちかよってにんぎょうを\nぜんぶあつめるつもりです！$"
GoldenrodDeptStore_Text_RoofTwin:
	.string "{JPN}ここではときどき\nば-げんせ-るがあるのよ$"
GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
	.string "{JPN}わあすごい！$"
GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
	.string "{JPN}じゃまをしないでくれる？$"
GoldenrodDeptStore_Text_RoofPokefanM:
	.string "{JPN}ほしいものがあるんだけど\nおかねがたりないんだ.\pあつめたきのみでも\nうってみようかな.$"
GoldenrodDeptStore_Text_RoofTeacher:
	.string "{JPN}まあやすいものばかり！\nかいすぎてバッグが\nいっぱいになったわ！$"
GoldenrodDeptStore_Text_RoofBugCatcher:
	.string "{JPN}おれのポケモンっていざって\nときにマヒやどくにされちゃう\nんだよな..\pそれでなんでもなおしを\nかいにきたんだ\pまだのこってるかな？$"