Route10_PowerPlantBackRoom_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDER
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "{JPN}かんりにん: お おれは\n"
	.string "{JPN}だれかを ふっとばす\n"
	.string "{JPN}じゅんびが できてるぞ!\p"
	.string "{JPN}だれが おれの はつでんきを\n"
	.string "{JPN}こわしたって いうんだ?\p"
	.string "{JPN}あんなに じかんを かけたのに!\p"
	.string "{JPN}もし そいつを つかまえたら\nでんじほうを おみまいして\nやるからな!$"

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "{JPN}かんりにん: そいつを\n"
	.string "{JPN}ゆるさないぞ!\p"
	.string "{JPN}はんにんが なこうが\n"
	.string "{JPN}あやまろうが\p"
	.string "{JPN}それでも たたきのめして\nやるからな!\pがははははっ!$"

Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "{JPN}かんりにん: あっ! そうだ!\p"
	.string "{JPN}それは あいしの はつでんきの\n"
	.string "{JPN}なくなった ぶひんだ!\nきみが みつけたのか?$"

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "{JPN}わはは! ありがとう!\p"
	.string "{JPN}ほら! おれいに この\nわざマシンを もっていけ!$"

Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "{JPN}かんりにん: その わざマシンは\n"
	.string "{JPN}かみなりだ.\p"
	.string "{JPN}とても つよい わざなんだ!\p"
	.string "{JPN}めいちゅうりつは だれも\n"
	.string "{JPN}じまんできないが\lいりょくは ばつぐんだぞ!$"

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "{JPN}かんりにん: あいしの はつでんき!\p"
	.string "{JPN}でんきを つくりつづけて\nくれよな!$"

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "{JPN}でんりょくが ないと この とびらは\nきけんだ.$"

