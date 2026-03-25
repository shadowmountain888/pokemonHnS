.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_GARBAGEVAR, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_GARBAGEFLAG
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "{JPN}ああ きみが{PLAYER}{KUN}だね?\n"
	.string "{JPN}きみのかつやくのうわさは\l"
	.string "{JPN}きいているよ.\p"
	.string "{JPN}わたしのなまえはワタル.\p"
	.string "{JPN}かつてはソウトポリスの\n"
	.string "{JPN}ジムリーダーだったんだが \l"
	.string "{JPN}ちょっとしたことがあってね.\p"
	.string "{JPN}いまは わたしのしたアダンに\n"
	.string "{JPN}ジムのうんえいをまかせている.\p"
	.string "{JPN}...\n"
	.string "{JPN}...\p"
	.string "{JPN}グラードンとカイオーガ \n"
	.string "{JPN}ここであばれている2ひきの\l"
	.string "{JPN}ポケモンは ちょうこだいポケモン\l"
	.string "{JPN}とかんがえられているんだ.\p"
	.string "{JPN}しかし ちょうこだいポケモンは\n"
	.string "{JPN}2ひきだけではない.\p"
	.string "{JPN}どこかに もう1ぴきいるんだ.\p"
	.string "{JPN}どこかに レックウザという\n"
	.string "{JPN}なまえのちょうこだいポケモンが\l"
	.string "{JPN}いるんだ.\p"
	.string "{JPN}とおいむかし たたかう2ひきを\nしずめたのは レックウザだった\lといわれている.\pしかし わたしにも\nレックウザのありかは\lわからない...$"
CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "{JPN}ミクリ: {PLAYER}{KUN} もしかして\n"
	.string "{JPN}レックウザがどこにいるか\l"
	.string "{JPN}しってるかい?\pもししってるなら \nおしえてくれないか?$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "{JPN}ミクリ: めざめのほらあな?\p"
	.string "{JPN}でもそれはここじゃないか!\n"
	.string "{JPN}もっとよくかんがえてくれ!\p"
	.string "{JPN}おねがいだ レックウザが\n"
	.string "{JPN}いまどこにいるかを\lかんがえてみてくれ.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "{JPN}ワタル:やまのはか?\p"
	.string "{JPN}しかし さっきそこであった\n"
	.string "{JPN}おばあさんは そんなこと\l"
	.string "{JPN}なにもいわなかったが...\p"
	.string "{JPN}おばあさんが わたしに\n"
	.string "{JPN}なにかをかくすとは\l"
	.string "{JPN}おもえないんだが...\p{PLAYER}{KUN} もういちど\nよくかんがえてくれないか?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "{JPN}ワタル:え?おぼえていない?\n"
	.string "{JPN}うーん...こまったな...\p"
	.string "{JPN}なんとかおもいだせないかね?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "{JPN}ミクリ: そらのはしら?\p"
	.string "{JPN}それだ!\n"
	.string "{JPN}そらのはしらにちがいない!\p"
	.string "{JPN}{PLAYER}{KUN} いっこくの\n"
	.string "{JPN}ゆうよもない!\lいますぐそらのはしらにむかおう!$"

