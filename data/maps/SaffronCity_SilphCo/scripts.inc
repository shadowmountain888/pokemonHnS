.set LOCALID_SILPHCO_STEVEN, 2

SaffronCity_SilphCo_MapScripts::
	.byte 0

SaffronCity_SilphCo_EventScript_Steven::
	lock 
	msgbox SaffronCity_SilphCo_Text_Steven1, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	delay 20
	playse SE_PIN
	applymovement LOCALID_SILPHCO_STEVEN, Common_Movement_ExclamationMark
	delay 60
SaffronCity_SilphCo_EventScript_StevenChooseStone::
	message SaffronCity_SilphCo_Text_Steven2
	waitmessage
	multichoice 20, 0, MULTI_HOENN_STARTERS, FALSE
	switch VAR_RESULT
	case 0, SaffronCity_SilphCo_EventScript_TreeckoChosen
	case 1, SaffronCity_SilphCo_EventScript_TorchicChosen
	case 2, SaffronCity_SilphCo_EventScript_MudkipChosen
	case MULTI_B_PRESSED, SaffronCity_SilphCo_EventScript_Refused

SaffronCity_SilphCo_EventScript_Refused::
	msgbox SaffronCity_SilphCo_Text_Refused, MSGBOX_DEFAULT
	turnobject LOCALID_SILPHCO_STEVEN, DIR_NORTH
	closemessage
	release
	end

SaffronCity_SilphCo_Text_Refused:
	.string "{JPN}ああ...$"

SaffronCity_SilphCo_EventScript_TreeckoChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TREECKO, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_TorchicChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TORCHIC, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_MudkipChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_MUDKIP, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven

SaffronCity_SilphCo_EventScript_AfterStarterGiven::
	msgbox SaffronCity_SilphCo_Text_Steven4, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SaffronCity_SilphCo_EventScript_PlayerMove
	applymovement LOCALID_SILPHCO_STEVEN, SaffronCity_SilphCo_Movement_StevenLeave
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_GOT_HOENN_STARTER
	removeobject LOCALID_SILPHCO_STEVEN
	release
	end

SaffronCity_SilphCo_EventScript_PlayerMove:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

SaffronCity_SilphCo_Movement_StevenLeave:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


SaffronCity_SilphCo_Text_Steven1:
	.string "{JPN}もしもし...\n"
	.string "{JPN}でんぱが わるいな...\l"
	.string "{JPN}とうちゃんしだいかな\l"
	.string "{JPN}そうか...\n"
	.string "{JPN}それじゃ いくよ また あおう$"
SaffronCity_SilphCo_Text_Steven2:
	.string "{JPN}ダイゴ: きみは... その ひとみに\n"
	.string "{JPN}みおぼえが あるな\p"
	.string "{JPN}ひとみが かがやく トレーナーを\n"
	.string "{JPN}みると いつも おぼえているんだ\p"
	.string "{JPN}ポケモンずかんを もってるね!\n"
	.string "{JPN}きみも ポケモンを さがしているのか!\l"
	.string "{JPN}ちょっと みせてくれ...\p"
	.string "{JPN}きみの やくに たてると おもうよ\p"
	.string "{JPN}めのまえに いしが あったとしよう\n"
	.string "{JPN}どんな いろを えらぶ?$"
	.string ""
SaffronCity_SilphCo_Text_Steven3:
	.string "{JPN}ただしい せんたくだ!\n"
	.string "{JPN}{STR_VAR_1}を あげよう!$"
SaffronCity_SilphCo_Text_Steven4:
	.string "{JPN}たいせつに そだててくれ\n"
	.string "{JPN}きみが かわいがってくれれば\lぼくも とても うれしいよ$"

SaffronCity_SilphCo_EventScript_Receptionist::
	msgbox SilphCo_Text_Receptionist, MSGBOX_NPC
	end
SaffronCity_SilphCo_EventScript_Officer::
	goto_if_set FLAG_GOT_UP_GRADE, SaffronCity_SilphCo_EventScript_OfficerAfter
	msgbox SilphCo_Text_Officer, MSGBOX_NPC
	giveitem ITEM_UP_GRADE
	setflag FLAG_GOT_UP_GRADE
SaffronCity_SilphCo_EventScript_OfficerAfter::
	msgbox SilphCo_Text_Officer_GotUpGrade, MSGBOX_NPC
	end

SaffronCity_SilphCo_EventScript_Sign1::
	msgbox SilphCo_Text_Sign1, MSGBOX_SIGN
	end

SaffronCity_SilphCo_EventScript_Sign2::
	msgbox SilphCo_Text_Sign2, MSGBOX_SIGN
	end

SilphCo_Text_Sign1:
	.string "{JPN}シルフカンパニー\n"
	.string "{JPN}1F うけつけ$"

SilphCo_Text_Sign2:
	.string "{JPN}シルフカンパニー\n"
	.string "{JPN}エレベーター こしょうちゅう$"

SilphCo_Text_Receptionist:
	.string "{JPN}いらっしゃいませ ここは\n"
	.string "{JPN}シルフカンパニーの ほんしゃです$"

SilphCo_Text_Officer:
	.string "{JPN}2かいから うえは しゃいん\n"
	.string "{JPN}いがい はいれません\p"
	.string "{JPN}でも はるばる きてくれたので\n"
	.string "{JPN}きねんひんを どうぞ$"
	.string ""

SilphCo_Text_Officer_GotUpGrade:
	.string "{JPN}シルフカンパニーの\n"
	.string "{JPN}さいしん せいひんです\pまだ はんばいしていません$"
