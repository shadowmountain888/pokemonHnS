.set LOCALID_ROUTE20_DENNIS, 17
.set LOCALID_ROUTE20_HEADLOCKER, 16

Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "{JPN}デニス: しゃあああああ!$"

Route20_Text_Headlocker:
	.string "{JPN}このルートには\n"
	.string "{JPN}めずらしいポケモンが\n"
	.string "{JPN}いるんだ.\p"
	.string "{JPN}ときどき めずらしい\n"
	.string "{JPN}しんかのどうぐも\n"
	.string "{JPN}もっているぞ.\p"
	.string "{JPN}ダブルで レアだ!\p ぼくは ポケモンずかんを\nかんせいさせたいから\nここで なんじかんも\nつりを してるんだ!$"

Route20_Text_Seel:
	.string "{JPN}パウワウ: パウ パウ!$"

Route20_Text_Dewgong:
	.string "{JPN}ジュゴン: ジュゴーン!$"

Route20_Text_SeafoamSign:
	.string "{JPN}ふたごじま$"

Route20_Text_SwimmerfNicoleSeen:
	.string "{JPN}みずのなかだと\nとても かるく かんじるわ.$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "{JPN}あら だめ!$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "{JPN}すいえいは ぜんしんの\n"
	.string "{JPN}うんどうになるの.\p とても からだに\nいいのよ.$"

Route20_Text_SwimmerfLoriSeen:
	.string "{JPN}すごい バッジの\n"
	.string "{JPN}コレクションね.\nしょうぶしましょう!$"

Route20_Text_SwimmerfLoriBeaten:
	.string "{JPN}だめ!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "{JPN}なみのりは もう みずで\n"
	.string "{JPN}つかう ゆいいつの\nひでんマシンじゃ\nないのね.$"

Route20_Text_SwimmermCameronSeen:
	.string "{JPN}およいで ジョウトまで\n"
	.string "{JPN}いくのは むりかな.$"

Route20_Text_SwimmermCameronBeaten:
	.string "{JPN}あいやー!$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "{JPN}うみの ほかにも\n"
	.string "{JPN}いけや かわでも\nおよげるんだ.$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "{JPN}このひょうしきに\n"
	.string "{JPN}なんて かいてあるの?\p グレンジム ジムリーダー:\nカツラ$"

