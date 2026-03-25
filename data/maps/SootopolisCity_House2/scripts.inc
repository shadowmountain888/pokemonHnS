SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "{JPN}おくりびやま...\p"
	.string "{JPN}その ちょうじょうには ふたつの\n"
	.string "{JPN}たまが ならんで おいてあるのを\nしってるかい?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "{JPN}そう ふたつの たまが\n"
	.string "{JPN}ならんでいるのじゃ...\p"
	.string "{JPN}それらが いっしょに ある\nこうけいは...\nなぜか こころが やすらぐのう...$"
SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "{JPN}そうなのかい?\n"
	.string "{JPN}きっと いちど いって みるべき\nじゃろうな...$"
