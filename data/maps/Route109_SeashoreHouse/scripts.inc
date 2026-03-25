Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "{JPN}わたしは シーサイドハウスの\n"
	.string "{JPN}あるじじゃ!\l"
	.string "{JPN}かいじんと よんでくれ!\p"
	.string "{JPN}\n"
	.string "{JPN}なによりも あついポケモン\n"
	.string "{JPN}バトルを みるのが すきなのじゃ!\p"
	.string "{JPN}\nきみの こころも あつく\nもえているか みせてくれ!\p\nここの トレーナーを ぜんぶ\nたおせたら ごほうびを\lあげるからな!$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "{JPN}あつい しあいを みせてくれ!\p"
	.string "{JPN}\n"
	.string "{JPN}そのためだけに この\nシーサイドハウスを やっているのじゃ!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "{JPN}あつい! あつすぎるじゃ!\n"
	.string "{JPN}そのバトル もえあがったぞ!\l"
	.string "{JPN}わしは だいまんぞくじゃ!\p"
	.string "{JPN}\n"
	.string "{JPN}あつい たたかいを みせてくれた\n"
	.string "{JPN}おれいに これを うけとってくれ!\p\nサイダー はんダース\nプレゼントじゃ!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "{JPN}おお それにしても\n"
	.string "{JPN}バッグが いっぱいじゃな\lわしが あずかっておこう$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "{JPN}サイダーは いかがかな?\n"
	.string "{JPN}ポケモンも だいすきじゃ!\p"
	.string "{JPN}\n"
	.string "{JPN}1ぽん 300えんじゃ!\nかっていかんかね!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "{JPN}はい どうぞ!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "{JPN}おかねが たりないのう$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "{JPN}だめかい?\n"
	.string "{JPN}それは ざんねんじゃ$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "{JPN}シーサイドハウスで バトルを\n"
	.string "{JPN}さがしているなら\l"
	.string "{JPN}おれより あつい トレーナーは\niないぜ!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "{JPN}あつい バトルだった!\n"
	.string "{JPN}このまけは みとめるぜ!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "{JPN}カイナシティに きたときは\n"
	.string "{JPN}あつい バトルと つめたい\lサイダーを たのしむのさ!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "{JPN}つまらない バトルなんて\n"
	.string "{JPN}やるかいが ないわ\p"
	.string "{JPN}\nもえるような あつい バトルこそ\nトレーナーと ポケモンを\lきたえるのよ!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "{JPN}あつかった!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "{JPN}ふう のどが かわいちゃった\n"
	.string "{JPN}サイダーでも のもうかしら$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "{JPN}ぼくの ポケモンの すごさを\n"
	.string "{JPN}みせてあげる! なかないでよ!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "{JPN}...I lost, but I won't cry...$"
Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "{JPN}ぼくの ポケモンが みずのうえを\n"
	.string "{JPN}はしる わざを おぼえてくれたら\l"
	.string "{JPN}この うきわを すてられるのにな$"

