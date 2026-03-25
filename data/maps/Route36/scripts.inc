.set LOCALID_ROUTE36_SUDOWOODO, 6
.set LOCALID_ROUTE36_ROCKSMASHGUY, 3

Route36_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "{JPN}{PLAYER}は\n"
	.string "{JPN}ゼニガメじょうろをつかった！$"
Route36_Text_UsedSquirtbottle:
	.string "{JPN}{PLAYER}は\n"
	.string "{JPN}ゼニガメじょうろをつかった！$"
Route36_Text_SudowoodoAttacked:
	.string "{JPN}おかしなきは\n"
	.string "{JPN}ゼニガメじょうろをいやがってる！\p"
	.string "{JPN}おかしなきがおそいかかってきた！$"
Route36_Text_RockSmashGuy1:
	.string "{JPN}わーへい!\p"
	.string "{JPN}あの きを まっすぐパンチで\n"
	.string "{JPN}へしおってやろうと おもったんだ.\p"
	.string "{JPN}でも できなかった! おれは\nしっぱいさくだ!$"

Route36_Text_RockSmashGuy2:
	.string "{JPN}あの いやな きを どかしたのか?\p"
	.string "{JPN}すごいじゃないか!\n"
	.string "{JPN}これを きみに あげよう.$"

Route36_Text_RockSmashGuy3:
	.string "{JPN}それは いわくだきだ.\p"
	.string "{JPN}いっぱつの よく ねらった\n"
	.string "{JPN}パンチで いわを くだけるぞ.\p"
	.string "{JPN}じゃまな いわが あったら\n"
	.string "{JPN}くだいて しまえ!$"

Route36_Text_OddTree:
	.string "{JPN}へんな きが みちを ふさいでいる.$"

Route36_Text_Lass1:
	.string "{JPN}この みちは よるは きを つけて!\p"
	.string "{JPN}ガーディみたいだけど\n"
	.string "{JPN}こわい オーラを まとった\l"
	.string "{JPN}ポケモンを みたの.$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "{JPN}あの へんな きが あとかたも\n"
	.string "{JPN}なく きえちゃった.\p"
	.string "{JPN}あ! あの きは ほんとうは\n"
	.string "{JPN}ポケモンだったの?$"

Route36_Text_PsychicMarkSeen:
	.string "{JPN}きみの こころを よんでやる!$"

Route36_Text_PsychicMarkBeaten:
	.string "{JPN}よみまちがえた!$"

Route36_Text_PsychicMarkAfter:
	.string "{JPN}あいての かんがえが わかれば\n"
	.string "{JPN}つよく なれるのになあ.$"

Route36_Text_SchoolboyAlan1Seen:
	.string "{JPN}べんきょうの おかげで どんな\n"
	.string "{JPN}ポケモンにも たいおう できるぞ!$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "{JPN}あれ! けいさんまちがい?$"

Route36_Text_SchoolboyAlanAfter:
	.string "{JPN}だめだなあ.1にち 5じかんも\n"
	.string "{JPN}べんきょうしてるのに.\p"
	.string "{JPN}ほんを よむだけじゃ\nだめなんだなあ.$"

Route36_Text_MeetArthur:
	.string "{JPN}アーサー: きみは だれだい?\n"
	.string "{JPN}ぼくは ようびきょうだいの\l"
	.string "{JPN}アーサーだ.\p"
	.string "{JPN}ぼくの すきな ようびを\nあてたら ごほうびを あげるよ.$"

Route36_Text_ArthurNope:
	.string "{JPN}ちがうよ!$"

Route36_Text_ArthurGivesGift:
	.string "{JPN}はい.これを あげるよ.$"

Route36_Text_ArthurGaveGift:
	.string "{JPN}アーサー: いわタイプの わざを\n"
	.string "{JPN}つかう ポケモンに もたせるといい.\p"
	.string "{JPN}iわタイプの こうげきを\nつよくして くれるよ.$"

Route36_Text_ArthurThursday:
	.string "{JPN}アーサー: ぼくは もくようびの\n"
	.string "{JPN}アーサー.7にんきょうだいの\l5ばんめなんだ.$"

Route36_Text_Sign:
	.string "{JPN}36ばんどうろ$"

Route36_Text_Sign_RuinsNorth:
	.string "{JPN}アルフのいせき\n"
	.string "{JPN}きたがわいりぐち$"
Route36_Text_Tips1:
	.string "{JPN}トレーナーの こころえ\n"
	.string "{JPN}ポケモンの のうりょくは\l"
	.string "{JPN}おなじ しゅぞくでも ちがう.\p"
	.string "{JPN}さいしょは にたような のうりょく\n"
	.string "{JPN}でも そだてると はっきりと\l"
	.string "{JPN}ちがいが あらわれる.$"

Route36_Text_Tips2:
	.string "{JPN}トレーナーの こころえ\n"
	.string "{JPN}あなをほるを つかえば\n"
	.string "{JPN}にゅうりぐちに もどれる.\p"
	.string "{JPN}どうくつや ダンジョンたんけんに\n"
	.string "{JPN}べんりだ.$"
