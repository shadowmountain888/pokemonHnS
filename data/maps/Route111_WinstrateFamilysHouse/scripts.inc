.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "{JPN}ポケモンを あんなに うまく\n"
	.string "{JPN}つかう トレーナーは はじめて\l"
	.string "{JPN}みたよ.\p"
	.string "{JPN}でも いっておくけど\n"
	.string "{JPN}わたしの むすこの ほうが\l"
	.string "{JPN}きみより つよいよ.\pポケモンリーグにも ちょうせん\nしたんだからね.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "{JPN}わたしたちは この\n"
	.string "{JPN}きょうせいギプスを つかって\l"
	.string "{JPN}ポケモンを きたえているんだ.\p"
	.string "{JPN}ここの みんなに かったきみに\n"
	.string "{JPN}ひつようか わからないけど\l"
	.string "{JPN}きょうせいギプスを あげよう.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "{JPN}ポケモンしょうぶに なると\n"
	.string "{JPN}みんな ねっくなって しまうのよ.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "{JPN}ママの ほうが パパより つよい!\p"
	.string "{JPN}あたしは ママより つよいの!\p"
	.string "{JPN}そして おばあちゃんは\n"
	.string "{JPN}あたしより つよいのよ!\p"
	.string "{JPN}でも おにいちゃんは\nおばあちゃんより もっと つよい!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "{JPN}たしかに おまえさんは\n"
	.string "{JPN}つよいのう.\p"
	.string "{JPN}しかし わしの まごと しょうぶ\n"
	.string "{JPN}したら くやしなきするじゃろう.\p"
	.string "{JPN}あの こは わしらが しっている\n"
	.string "{JPN}どの トレーナーよりも つよい.\p"
	.string "{JPN}いまごろ ポケモンリーグの\n"
	.string "{JPN}チャンピオンと たたかって\l"
	.string "{JPN}いるじゃろうて.\pあの こなら もう チャンピオンに\nなっているかも しれんのう!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "{JPN}わしの まごは いまごろ\n"
	.string "{JPN}ポケモンリーグの チャンピオンと\l"
	.string "{JPN}たたかっているじゃろうて.\p"
	.string "{JPN}あの こなら もう チャンピオンに\nなっているかも しれんのう!$"

