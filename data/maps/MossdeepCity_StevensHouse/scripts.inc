.set LOCALID_STEVEN, 1
.set LOCALID_BELDUM_BALL, 2

MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_StevensHouse_OnTransition:
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos::
	setobjectxyperm LOCALID_STEVEN, 6, 5
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame:
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
	lockall
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_WHIRLPOOL
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	waitmovement 0
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_StevensHouse_EventScript_SendBeldumParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_StevensHouse_EventScript_SendBeldumPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end
	
MossdeepCity_StevensHouse_EventScript_SendBeldumPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_BELDUM_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven::
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
	finditem ITEM_HM_WHIRLPOOL
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
	.string "{JPN}スチーブン: {PLAYER}{KUN}...\p"
	.string "{JPN}みてのとおり あまり\n"
	.string "{JPN}ものはないが ここがぼくのいえだ\p"
	.string "{JPN}きみがしてくれた すべてのことに\n"
	.string "{JPN}かんしゃしている\p"
	.string "{JPN}これは ぼくからの\n"
	.string "{JPN}おれいのしるしだ\n"
	.string "{JPN}ひでんマシン ダイビングだよ\nえんりょしなくていい\nきみはこれをうけとるかちがある$"

MossdeepCity_StevensHouse_Text_ExplainDive:
	.string "{JPN}ダイゴ: なみのりを つかっているとき\n"
	.string "{JPN}くらい みずの ばしょに きづくはずだ\p"
	.string "{JPN}そんな ふかい みずの ばしょで\n"
	.string "{JPN}ダイビングを つかってみるといい\p"
	.string "{JPN}かいていまで もぐることが できるぞ\p"
	.string "{JPN}もとの ばしょに もどりたいときは\n"
	.string "{JPN}もういちど ダイビングを つかうんだ\p"
	.string "{JPN}ただし ばしょによっては\nうみめんに でられないところも ある$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
	.string "{JPN}ダイゴ: どうやら トクサネシティと\n"
	.string "{JPN}ルネシティの あいだには\l"
	.string "{JPN}かいていの どうくつが あるらしい\p"
	.string "{JPN}クスノキかんちょうが せんすいかんで\n"
	.string "{JPN}はっけんした あの どうくつのことだ$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
	.string "{JPN}{PLAYER}は モンスターボールを\n"
	.string "{JPN}しらべた\p"
	.string "{JPN}なかには ダンバルという\n"
	.string "{JPN}ポケモンが はいっていた\pモンスターボールを もらいますか?$"

MossdeepCity_StevensHouse_Text_ObtainedBeldum:
	.string "{JPN}{PLAYER}は ダンバルを てにいれた!$"

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
	.string "{JPN}これいじょう ポケモンを\nもつことは できません$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
	.string "{JPN}{PLAYER}は モンスターボールを\n"
	.string "{JPN}もとの ばしょに おいた$"

MossdeepCity_StevensHouse_Text_LetterFromSteven:
	.string "{JPN}てがみがある\p"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}{PLAYER}{KUN}へ...\p"
	.string "{JPN}ぼくは すこしたましいを\n"
	.string "{JPN}さがしにいき みちでしゅぎょうを\n"
	.string "{JPN}することにした\p"
	.string "{JPN}しばらくいえには\n"
	.string "{JPN}かえらないつもりだ\p"
	.string "{JPN}きみにたのみがある\p"
	.string "{JPN}つくえのうえの モンスターボールを\n"
	.string "{JPN}もっていってほしい\p"
	.string "{JPN}なかには ぼくのだいすきな\n"
	.string "{JPN}ポケモン ダンバルがはいっている\p"
	.string "{JPN}たのんだぞ\n"
	.string "{JPN}いつかまた あえることを\nねがっている\nツキノイシ スチーブン$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
	.string "{JPN}ダイゴが あつめた めずらしい\n"
	.string "{JPN}いわや いしの コレクションだ$"

