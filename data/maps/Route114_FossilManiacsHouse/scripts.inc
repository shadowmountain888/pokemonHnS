Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "{JPN}おにいちゃんは\n"
	.string "{JPN}かせきマニアなの...\n"
	.string "{JPN}かせきが だいすきな\n"
	.string "{JPN}やさしいひとよ...\p"
	.string "{JPN}あなを ほるのも\n"
	.string "{JPN}だいすきなの...\nこのあなも ひとりで\nほったのよ...\pこれを あげるから\nおにいちゃんみたいに\nあなを ほってみて...$"
Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "{JPN}どうくつの なかで\n"
	.string "{JPN}ポケモンに あなをほるを\nつかうと\nいりぐちに もどるよ...$"
Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "{JPN}かわった かたちの いわが\n"
	.string "{JPN}しょうけーすに\nぎっしり ならんでる...$"
Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "{JPN}ちそうの こうせい...\n"
	.string "{JPN}あめが つちを けずるしくみ...\n"
	.string "{JPN}いし つち がんせき...\p"
	.string "{JPN}ほんで ぎっしりだ...$"

