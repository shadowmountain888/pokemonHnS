Route37_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "{JPN}アン: わたしと アンヌは\n"
	.string "{JPN}いっしょに がんばるよ!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "{JPN}アン&アンヌ: うーん...\n"
	.string "{JPN}ちょっと つよすぎるわ$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "{JPN}アン: わたしには いもうとと\n"
	.string "{JPN}ポケモンの きもちが わかるの$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "{JPN}アンヌ: わたしと アンは\n"
	.string "{JPN}いっしょに がんばるよ!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "{JPN}アン&アンヌ: うーん...\n"
	.string "{JPN}ちょっと つよすぎるわ$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "{JPN}アンヌ: わたしたちは ポケモンと\n"
	.string "{JPN}おなじ きもちを わけあってるの$"

Route37_Text_PsychicGreg_Seen:
	.string "{JPN}ポケモンは ねむってしまうと\n"
	.string "{JPN}なにも できないんだ\p"
	.string "{JPN}その こわさを おしえてあげよう!$"

Route37_Text_PsychicGreg_Beaten:
	.string "{JPN}まけちゃった...\nちょっと かなしいな...$"
Route37_Text_PsychicGreg_After:
	.string "{JPN}ポケモンを ねむらせたり\n"
	.string "{JPN}まひさせたりするのは\lいい バトルの テクニックだよ$"

Route37_Text_Sunny_Meet:
	.string "{JPN}サニー: こんにちは!\p"
	.string "{JPN}ぼく ようびきょうだいの\n"
	.string "{JPN}サニーだよ!\p"
	.string "{JPN}ぼくの すきな ようびを\nあててくれたら\lプレゼントを あげるよ$"

Route37_Text_Sunny_GiveGift1:
	.string "{JPN}きみを みたら これを\n"
	.string "{JPN}わたすように いわれてたんだ!$"

Route37_Text_Sunny_GiveGift2:
	.string "{JPN}きみを みたら これを\n"
	.string "{JPN}わたすように いわれてたんだ!$"

Route37_Text_Sunny_GaveGift:
	.string "{JPN}サニー: そのもの...\p"
	.string "{JPN}\n"
	.string "{JPN}うーん...\p"
	.string "{JPN}\n"
	.string "{JPN}... なんだったかな...\p"
	.string "{JPN}\n"
	.string "{JPN}...\p"
	.string "{JPN}\n"
	.string "{JPN}あ! おもいだした!\p\nでんきタイプのわざを おぼえた\nポケモンに もたせるといいよ\p\nおねえちゃんの モニカが\nでんきわざが つよくなるって!$"

Route37_Text_Sunny_Sunday:
	.string "{JPN}サニー: ぼくの きょうだいは\n"
	.string "{JPN}モニカに タスカニーに\l"
	.string "{JPN}ウェズリーに アーサー\l"
	.string "{JPN}フリーダに サントスだよ\pみんな ぼくより おおきいんだ!$"

Route37_Text_Sunny_NotSunday:
	.string "{JPN}サニー: きょうって にちようび?\n"
	.string "{JPN}うーん... わすれちゃった!$"
Route37_Text_Sign:
	.string "{JPN}37ばんどうろ\n"
	.string "{JPN}エンジュシティ さき$"
