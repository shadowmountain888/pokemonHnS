.set LOCALID_ICEPATH1_KIMONO, 9
IcePath_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

IcePath_1F_EventScript_Item_PpUp::
	finditem ITEM_PP_UP
	end
IcePath_1F_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end
IcePath_1F_EventScript_Item_HM_Waterfall::
	finditem ITEM_HM_WATERFALL
	end

IcePath_1F_EventScript_KimonoGirl::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	goto_if_eq VAR_FACING, DIR_SOUTH, IcePath_1F_EventScript_KimonoGirlPushPrompt
	msgbox IcePath_1F_Text_Stuck1, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

IcePath_1F_Trigger_KimonoGirl::
	lock
	msgbox IcePath_1F_Text_Leave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

IcePath_1F_EventScript_KimonoGirlPushPrompt::
	msgbox IcePath_1F_Text_Stuck2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused
IcePath_1F_EventScript_KimonoGirlPush::
	msgbox IcePath_1F_Text_Shove, MSGBOX_AUTOCLOSE
	closemessage
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_Movement_PlayerJump
	waitmovement 0
	waitse
	playse SE_M_ICY_WIND
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoSlide
	waitmovement 0
	msgbox IcePath_1F_Text_Thanks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoLeave
	waitmovement LOCALID_ICEPATH1_KIMONO
	setflag FLAG_HIDE_ICE_PATH_KIMONO
	removeobject LOCALID_ICEPATH1_KIMONO
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_ICE_PATH_STATE, 1
	release
	end

IcePath_1F_EventScript_KimonoGirlRefused::
	msgbox IcePath_1F_Text_Cruel, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IcePath_1F_EventScript_KimonoGirlPush
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused

IcePath_Movement_PlayerJump:
	jump_in_place_down
	step_end

IcePath_Movement_KimonoSlide:
	slide_down
	slide_down
	slide_down
	slide_down
	walk_in_place_fast_down
	face_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

IcePath_Movement_KimonoLeave:
	walk_down
	walk_down
	walk_down
	step_end

IcePath_1F_Text_Leave:
	.string "{JPN}きものガール:                       $"

IcePath_1F_Text_Stuck1:
    .string "{JPN}あら まあ    あなた {PLAYER}さんね?\n"
	.string "{JPN}こんなところで おあいするなんて!\p"
    .string "{JPN}じつは    わたしの げたが\n"
	.string "{JPN}こおりに くっついて うごけないの.\p"
    .string "{JPN}つまり ぞうりが じめんに\n"
	.string "{JPN}れいとうされちゃったの.\p"
    .string "{JPN}てぃひ.\p"
	.string "{JPN}でも わらいごとじゃないわ.\p"
    .string "{JPN}まわって きてくれて\n"
	.string "{JPN}せなかを おしてくれる?$"

IcePath_1F_Text_Stuck2:
    .string "{JPN}あら まあ    あなた {PLAYER}さんね?\n"
	.string "{JPN}こんなところで おあいするなんて!\p"
    .string "{JPN}じつは    わたしの げたが\n"
	.string "{JPN}こおりに くっついて うごけないの.\p"
    .string "{JPN}つまり ぞうりが じめんと\n"
	.string "{JPN}れいとうされちゃったの.\p"
    .string "{JPN}てぃひ.\p"
	.string "{JPN}でも わらいごとじゃないわ.\n"
    .string "{JPN}せなかを おしてくれる?$"

IcePath_1F_Text_Shove:
    .string "{JPN}    えいっ!    $"

IcePath_1F_Text_Cruel:
    .string "{JPN}そんな ひどいことしないで.\n"
	.string "{JPN}せなかを おしてくれるでしょ?$"

IcePath_1F_Text_Thanks:
    .string "{JPN}あなたって ほんとうに やさしいのね.\n"
	.string "{JPN}どうも ありがとう!$"
