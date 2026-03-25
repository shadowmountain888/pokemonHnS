Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "{JPN}ぼくは ポケモンを そだててるんだ.\n"
	.string "{JPN}いっしょに バトルしない?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "{JPN}Ack! I lost that one...$"
Route4_Text_BirdKeeperHank_AfterBattle:
	.string "{JPN}とくていの ポケモンを そだてたいなら\n"
	.string "{JPN}さいしょに だして すぐに\l"
	.string "{JPN}こうたいするんだ.\p"
	.string "{JPN}それが コツだよ.$"

Route4_Text_PicnickerHope_Seen:
	.string "{JPN}なんだか かてそうな きがするの.\p"
	.string "{JPN}ほんとうか たしかめましょ!$"

Route4_Text_PicnickerHope_Beaten:
	.string "{JPN}あーあ あなた つよすぎるのよ.$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "{JPN}おつきみやまに ピッピが でるって\n"
	.string "{JPN}きいたことがあるの.\pでも どこにいるのかしら?$"

Route4_Text_PicnickerSharon_Seen:
	.string "{JPN}Um...\n"
	.string "{JPN}I...$"
Route4_Text_PicnickerSharon_Beaten:
	.string "{JPN}...$"
Route4_Text_PicnickerSharon_AfterBattle:
	.string "{JPN}...I'll go train some more...$"
Route4_Text_MtMoonSquareSign:
	.string "{JPN}おつきみやま あたらしい いりぐち\n"
	.string "{JPN}どうくつの くずれにより\p"
	.string "{JPN}あしもとに ちゅうい$"

