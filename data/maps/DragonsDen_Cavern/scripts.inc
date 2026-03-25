.set LOCALID_DRAGONSDEN2_CLAIR, 5
.set LOCALID_DEN_CLAIR, 35

DragonsDen_Cavern_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{JPN}{PLAYER}... そこにいるのね.\p"
	.string "{JPN}わたしについてこられる\n"
	.string "{JPN}というなら ヤマブキの\l"
	.string "{JPN}かくとうどうじょうにきなさい.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end


DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_ClairGiveDragonclaw, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_CLAW
	msgbox DragonsDen_Cavern_Text_ClairDescribeDragonclaw, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_ClairGiveDragonclaw:
    .string "{JPN}イブキ: ちょっと まって!\p"
	.string "{JPN}ごめんなさい.\n"
    .string "{JPN}これを おわびに うけとって.$"

DragonsDen_Cavern_Text_ClairDescribeDragonclaw:
    .string "{JPN}それには ドラゴンクロー が\n"
	.string "{JPN}はいってるの.\p"
    .string "{JPN}いいえ  わたしの つめとは\n"
	.string "{JPN}かんけいないわ.\p"
    .string "{JPN}いらないなら\nうけとらなくてもいいのよ.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "{JPN}どうしたの? ポケモンリーグに\n"
	.string "{JPN}いかないの?\p"
    .string "{JPN}チャンピオンになったら\n"
	.string "{JPN}どのジムリーダーとでも\l"
    .string "{JPN}さいせんできるのよ.\p"
	.string "{JPN}ポケモンリーグに いきなさい.\p"
    .string "{JPN}みちは わかる?\p"
	.string "{JPN}ここから ワカバタウンに いって.\p"
    .string "{JPN}それから ひがしに なみのりして\n"
	.string "{JPN}ポケモンリーグよ.\p"
    .string "{JPN}そのルートは とても きびしいわ.\p"
	.string "{JPN}ポケモンリーグで まけちゃ\n"
    .string "{JPN}だめよ!\p"
	.string "{JPN}もし まけたら わたしが\n"
    .string "{JPN}あなたに まけたことが\l"
	.string "{JPN}もっと いやになるから!\pぜんりょくで がんばって.$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "{JPN}ドラゴンのほこら\p"
	.string "{JPN}りゅうのあなに すんでいたと\n"
    .string "{JPN}いわれる\p"
	.string "{JPN}ドラゴンポケモンを まつる\n"
    .string "{JPN}ほこら.$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "{JPN}...\n"
	.string "{JPN}{PLAYER}か?\p"
    .string "{JPN}...いいや いまは\n"
	.string "{JPN}たたかわない...\p"
    .string "{JPN}おれのポケモンは\n"
	.string "{JPN}おまえにかつじゅんびが\l"
    .string "{JPN}できていない.\p"
	.string "{JPN}いまはむりをさせる\nわけにはいかない.\pさいきょうのポケモン\nトレーナーになるには\lきりつがひつようなんだ...$"
DragonsDen_Cavern_Text_SilverTraining2:
    .string "{JPN}...\p"
	.string "{JPN}...ふう...\p"
	.string "{JPN}じゃまをするな...$"
DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "{JPN}きみ! ゆるしもなく はいって\n"
	.string "{JPN}くるなんて!$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "{JPN}つ つよい!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "{JPN}おくの ほこらには わたしたち\n"
	.string "{JPN}ドラゴンつかいのいちぞくの\l"
    .string "{JPN}マスターが おられる.\pかってに はいっては だめだ!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "{JPN}あなた ここに いては だめよ!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "{JPN}あら やだ まけちゃった!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "{JPN}もうすぐ マスターから\n"
	.string "{JPN}ドラゴンを つかう きょかを\l"
    .string "{JPN}もらうの.\p"
	.string "{JPN}そうしたら りっぱな\n"
    .string "{JPN}ドラゴンつかいになって\lマスターに みとめてもらうわ.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "{JPN}しらない ひとだ.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "{JPN}いたーい.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "{JPN}ワタルと たたかうみたいだった.$"
	.string ""

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "{JPN}だれ?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "{JPN}いじわる.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "{JPN}いいつけてやる.\p"
	.string "{JPN}マスターが おこるよ.$"
