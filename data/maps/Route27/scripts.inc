.set LOCALID_ROUTE27_FATMAN, 1

Route27_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    setflag FLAG_VISITED_KANTO
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
    
    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_SolarBeam::
    finditem ITEM_TM_SOLAR_BEAM
    end

Route27_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
    .string "{JPN}おーい!$"

Route27_Text_FisherMessage:
    .string "{JPN}きみ じぶんが なにをしたか\n"
	.string "{JPN}わかるかい?\p"
    .string "{JPN}きみは カントーちほうへの\n"
	.string "{JPN}だいいっぽを ふみだしたんだ\pポケギアの マップを\nかくにんしてみたまえ$"

Route27_Text_CooltrainermBlakeSeen:
    .string "{JPN}きみ けっこう つよそうだな\n"
	.string "{JPN}しょうぶしよう!$"

Route27_Text_CooltrainermBlakeBeaten:
    .string "{JPN}うわあ!$"

Route27_Text_CooltrainermBlakeAfter:
    .string "{JPN}この きびしいたびじで\n"
	.string "{JPN}しょうりすれば しんじつがあきらかに!\p"
    .string "{JPN}へへ ごめん なんか かっこいい\n"
	.string "{JPN}ことを いってみたかったんだ$"

Route27_Text_CooltrainermBrianSeen:
    .string "{JPN}ふむ? きみ うまいね?$"

Route27_Text_CooltrainermBrianBeaten:
    .string "{JPN}おもったとおりだ!$"

Route27_Text_CooltrainermBrianAfter:
    .string "{JPN}いいトレーナーは ほかの\n"
	.string "{JPN}いいトレーナーが わかるものさ$"

Route27_Text_CooltrainerfReenaSeen:
    .string "{JPN}このあたりの やせいポケモンを\n"
	.string "{JPN}あなどってはいけないわよ$"

Route27_Text_CooltrainerfReenaBeaten:
    .string "{JPN}あら! あなた つよすぎるわ!$"

Route27_Text_CooltrainerfReenaAfter:
    .string "{JPN}あなた こどもなのに\n"
	.string "{JPN}あなどれないわね$"

Route27_Text_CooltrainerfMeganSeen:
    .string "{JPN}ここに くるひとは めずらしいわ\p"
	.string "{JPN}ひとりで しゅぎょうしてるの?$"

Route27_Text_CooltrainerfMeganBeaten:
    .string "{JPN}あら! ほんとうに つよいのね!$"

Route27_Text_CooltrainerfMeganAfter:
    .string "{JPN}しんかまえと しんかあとの\n"
	.string "{JPN}ポケモンを しらべてるのよ\p"
    .string "{JPN}しんかすると ほんとうに\n"
	.string "{JPN}ポケモンは つよくなるの\p"
    .string "{JPN}でも しんかけいは わざを\n"
	.string "{JPN}おそくに おぼえるのよね$"

Route27_Text_PsychicGilbertSeen:
    .string "{JPN}なにも いわないで!\p"
	.string "{JPN}きみが かんがえてることを\n"
    .string "{JPN}あててみせよう.\p"
	.string "{JPN}うーーーん...\p"
    .string "{JPN}わかったぞ! きみは ポケモン\nリーグに ちょうせんするんだ!$"

Route27_Text_PsychicGilbertBeaten:
    .string "{JPN}きみは つよすぎるよ!$"

Route27_Text_PsychicGilbertAfter:
    .string "{JPN}きみの じつりょくなら リーグでも\n"
	.string "{JPN}やっていけるよ\p"
    .string "{JPN}ぼくの よげんが そういってる$"

Route27_Text_BirdKeeperJoseSeen:
    .string "{JPN}ぴー! ぴー! ぴぴー!$"

Route27_Text_BirdKeeperJoseBeaten:
    .string "{JPN}ぴー!$"

Route27_Text_BirdKeeperJoseAfter:
    .string "{JPN}ぼくたち とりつかいは とりの\n"
	.string "{JPN}なきごえを まねて ポケモンを\nしきするんだ$"

TohjoFalls_Text_Sign:
    .string "{JPN}トージョーのたき\p"
	.string "{JPN}カントーと ジョウトーを むすぶ$"

Route27_Text_FisherScottSeen:
    .string "{JPN}きょうは ちょうしがいいぞ!\p"
	.string "{JPN}リーグチャンピオンにでも\n"
    .string "{JPN}かてそうなきぶんだ!$"

Route27_Text_FisherScottBeaten:
    .string "{JPN}だめだ! このしょうぶじゃ!$"

Route27_Text_FisherScottAfter:
    .string "{JPN}つりと おなじで ポケモンも\n"
	.string "{JPN}あきらめたら おわりなんだ$"
