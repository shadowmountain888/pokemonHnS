.set LOCALID_POWERPLANT_COP, 1
.set LOCALID_POWERPLANT_ENGINEER, 2

Route10_PowerPlantEntrance_MapScripts::
	.byte 0

Route10_PowerPlantEntrance_EventScript_Cop::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopAfterDone
	msgbox Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopDuringRocket::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopAfterDone::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_Engineer1::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer1Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer1Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer2Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Cop2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Cop2Done
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious, MSGBOX_NPC
	end
Route10_PowerPlantEntrance_EventScript_Cop2Done::
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer3Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_Trigger_Cop::
	lock
	playse SE_POKENAV_CALL
	applymovement2 LOCALID_POWERPLANT_COP, Common_Movement_ExclamationMark
	waitse
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkToPlayer
	waitmovement 0
	turnobject LOCALID_POWERPLANT_ENGINEER, DIR_SOUTH
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_POWERPLANT_COP, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkBack
	waitmovement 0
	setvar VAR_KANTO_ROCKET_STORY_STATE, 2
	clearflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	release
	end

Route10_PowerPlantEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route10_PowerPlantEntrance_Movement_WalkBack:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn:
	.string "{JPN}どろぼうが はつでんしょに\n"
	.string "{JPN}おしいったんだ...\p"
	.string "{JPN}いったい せかいは\nどうなってるんだ?$"

Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter:
	.string "{JPN}ハナダから れんらくが\n"
	.string "{JPN}あったんだ.\p"
	.string "{JPN}あやしい やつが\n"
	.string "{JPN}うろついているとの\lことだ.$"

Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation:
	.string "{JPN}きみに きょうりょく\n"
	.string "{JPN}してもらえないかな?$"

Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity:
	.string "{JPN}けいびを つよくしないと\n"
	.string "{JPN}いけないな.$"

Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart:
	.string "{JPN}だれかが はつでんきの\n"
	.string "{JPN}だいじな ぶひんを\l"
	.string "{JPN}ぬすんでいったんだ.\p"
	.string "{JPN}それが ないと しんしき\n"
	.string "{JPN}はつでんきは つかえない!$"

Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning:
	.string "{JPN}はつでんきが うごいてるよ.\n"
	.string "{JPN}でんりょくも たっぷりだ.$"

Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning:
	.string "{JPN}この はつでんしょは\n"
	.string "{JPN}まえは はいきょだったんだ.\p"
	.string "{JPN}リニアの でんりょくのために\n"
	.string "{JPN}ふっかつさせたのさ.$"
	.string ""

Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain:
	.string "{JPN}はつでんきが また\nうごきだしたぞ!$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious:
	.string "{JPN}はつでんしょの しょちょうは\n"
	.string "{JPN}おくの はつでんきの へやに\p"
	.string "{JPN}いるけど だれかが はつでんきを\n"
	.string "{JPN}こわしてしまって かなしみと\l"
	.string "{JPN}いかりで いっぱいなんだ...$"
Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful:
	.string "{JPN}はつでんきが なおってから\n"
	.string "{JPN}しょちょうが きげんいいんだ.$"

Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity:
	.string "{JPN}リニアは たくさんの\n"
	.string "{JPN}でんりょくを つかうんだ.\p"
	.string "{JPN}しんしき はつでんきが\n"
	.string "{JPN}うごかないと はしれないのさ.$"

Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning:
	.string "{JPN}よし! やっと リニアを\n"
	.string "{JPN}うごかすことが できるぞ.$"
