.set LOCALID_LAKEOFRAGE_GYARADOS, 8
.set LOCALID_LAKEOFRAGE_LANCE, 3
.set LOCALID_LAKEOFRAGE_DRAGONITE, 16
.set LOCALID_LAKEOFRAGE_OLDMAN, 4
.set LOCALID_LAKE_PRYCE, 17

LakeOfRage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
    .string "{JPN}{PLAYER}よ.\p"
	.string "{JPN}ここでも さむさが わしを\n"
	.string "{JPN}するどくしてくれる.\p"
	.string "{JPN}また たたかいたくなったら\nかくとうどうじょうに こい.$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Max_Revive::
	finditem ITEM_MAX_REVIVE
	end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "{JPN}カイリュー: ギャフゥ...$"

LakeOfRage_Text_LanceForcedToEvolve:
	.string "{JPN}あのあかいギャラドス\nどうかんがえてみてもようすが\l"
	.string "{JPN}ふつうじゃなかった...\p"
	.string "{JPN}やはりだれかのしわざで\nむりやりしんかを\l"
	.string "{JPN}させられてしまったのか...\p$"
LakeOfRage_Text_LanceIntro1:
	.string "{JPN}きみもうわさをききつけて\nやってきたのかい?\p"
	.string "{JPN}そう{PLAYER}というのか\nおれはワタル\l"
	.string "{JPN}きみとおなじトレーナーさ\p"
	.string "{JPN}ここのうわさをききつけ\nしんそうをしらべていたんだが...\p"
	.string "{JPN}{PLAYER}くん!\nさっきのたたかいをみれば\l"
	.string "{JPN}きみがそうとうなじつりょくの\lトレーナーだとわかる\p"
	.string "{JPN}よかったらおれにちょっと\nちからをかしてくれないか?$"

LakeOfRage_Text_LanceIntro2:
    .string "{JPN}ここにいる おとこのひとが\n"
	.string "{JPN}うわさを おしえてくれたのだ.\p"
    .string "{JPN}それで しらべに きたのだが...$"
LakeOfRage_Text_LanceIntro3:
    .string "{JPN}さっき きみの たたかいぶりを\n"
	.string "{JPN}みせてもらった.\p"
    .string "{JPN}かなりの うでまえの\n"
	.string "{JPN}トレーナーだということが\l"
    .string "{JPN}わかったよ.\p"
	.string "{JPN}もしよかったら\nちょうさを てつだってくれるかい?$"

LakeOfRage_Text_LanceRadioSignal:
	.string "{JPN}ワタル: そうかたすかるよ!\p"
	.string "{JPN}みずうみのコイキングたちは\nチョウジからのなぞのでんぱで\l"
	.string "{JPN}むりやりしんかさせられている\lそんなきがするんだ\p"
	.string "{JPN}そしてあの\nあやしいおみやげやさん...\p"
	.string "{JPN}{PLAYER}くん!\nおれはひとあしさきに\l"
	.string "{JPN}チョウジタウンへむかってるよ!$"

LakeOfRage_Text_LanceRefused:
	.string "{JPN}そうか...\nきがかわったらきてくれよ$"

LakeOfRage_Text_LanceAskHelp:
	.string "{JPN}ワタル: どう?\nちからをかしてくれるかい?$"

LakeOfRage_Text_GyaradosCry:
	.string "{JPN}ギャラドス: ギャシャーッ!!$"

LakeOfRage_Text_Gramps:
	.string "{JPN}ギャラドスがおいかりじゃ!\nなんかよくないことがおきるんじゃ$"

LakeOfRage_Text_GrampsCleared:
    .string "{JPN}はっはっは! コイキングが\nつりあがっておる!$"

LakeOfRage_Text_SuperNerd:
	.string "{JPN}ここはむかしギャラドスが\nあばれまわってできたんだって\p"
	.string "{JPN}こんかいのじけんと\nなにかかんけいあるのかな?$"

LakeOfRage_Text_CooltrainerF:
	.string "{JPN}あかいギャラドスはどうしたの?\p"
	.string "{JPN}えっもういないの?\nそんなせっかくきたのに...\p"
	.string "{JPN}いいわあなたしょうぶしましょ!$"


LakeOfRage_Text_FisherAndreSeen:
    .string "{JPN}いま つったばかりの ポケモンで\n"
	.string "{JPN}たたかわせてくれ!$"

LakeOfRage_Text_FisherAndreBeaten:
    .string "{JPN}つりの うでまえは いちにんまえ\n"
	.string "{JPN}でも ポケモントレーナーとして\nは まだまだだな...$"
LakeOfRage_Text_FisherAndreAfter:
    .string "{JPN}つりしとしては まけないぞ!\n"
	.string "{JPN}いちにちじゅう ポケモンを\lつっているからな.$"


LakeOfRage_Text_FisherRaymondSeen:
    .string "{JPN}なにを やっても おなじ\n"
	.string "{JPN}ポケモンしか つれないんだ...$"
LakeOfRage_Text_FisherRaymondBeaten:
    .string "{JPN}つりいとが からまっちゃったよ...$"
LakeOfRage_Text_FisherRaymondAfter:
    .string "{JPN}どうして いい ポケモンが\n"
	.string "{JPN}つれないんだろう?$"

LakeOfRage_Text_CooltrainermAaronSeen:
    .string "{JPN}トレーナーが べつの トレーナーを\n"
	.string "{JPN}みつけたら しょうぶを\l"
    .string "{JPN}いどまなければならない.\nそれが われわれの さだめだ.$"

LakeOfRage_Text_CooltrainermAaronBeaten:
    .string "{JPN}ふう... いいバトルだった.$"
LakeOfRage_Text_CooltrainermAaronAfter:
    .string "{JPN}ポケモンと トレーナーは\n"
	.string "{JPN}たえまない たたかいで\lつよくなっていくのだ.$"

LakeOfRage_Text_CooltrainerfLoisSeen:
    .string "{JPN}あかい ギャラドスは\n"
	.string "{JPN}どうなったの?\p"
    .string "{JPN}いなくなっちゃった?\p"
	.string "{JPN}あーあ. むだあしだったかも.\p"
    .string "{JPN}そうだ! しょうぶしましょ!$"
	.string ""

LakeOfRage_Text_CooltrainerfLoisBeaten:
    .string "{JPN}やるわね!$"

LakeOfRage_Text_CooltrainerfLoisAfter:
    .string "{JPN}そういえば ピンクいろの\n"
	.string "{JPN}バタフリーを みたことがあるの.$"



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
    .string "{JPN}ウェズリー: やあ! げんきかい?\p"
	.string "{JPN}ぼくは ようびきょうだいの\n"
	.string "{JPN}ひとりなんだ!\lぼくの すきな ようびを\nあててみてくれる?$"

LakeOfRage_Text_WesleyGivesGift:
    .string "{JPN}はじめまして. おみやげを\n"
	.string "{JPN}どうぞ.$"

LakeOfRage_Text_WesleyGaveGift:
    .string "{JPN}ウェズリー: くろおびは\n"
	.string "{JPN}かくとうタイプの わざの\lいりょくを あげてくれるよ.$"

LakeOfRage_Text_WesleyWednesday:
    .string "{JPN}ウェズリー: きみが ぼくを\n"
	.string "{JPN}みつけたということは\l"
    .string "{JPN}きょうだいしまいに あったのかな?\n"
	.string "{JPN}それとも うんが よかっただけ?$"

LakeOfRage_Text_WesleyNotWednesday:
    .string "{JPN}ウェズリー: ざんねん...$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
	.string "{JPN}ここはいかりのみずうみ\nべつめいギャラドスこ$"

LakeOfRage_Text_FishingGuruSign:
	.string "{JPN}ここはつりめいじんのいえ$"
