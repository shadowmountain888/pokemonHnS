Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
    goto_if_eq VAR_RESULT, TRUE, Route111_OldLadysRestStop_EventScript_Rest_PokecenterChallenge
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest_PokecenterChallenge::
	msgbox Route111_OldLadysRestStop_Text_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_PokecenterChallenge:
	.string "{JPN}ごめんなさいね.\n"
	.string "{JPN}ポケモンセンターチャレンジを\nやってるのね!$"
	
Route111_OldLadysRestStop_Text_RestUpHere:
	.string "{JPN}あらあら まあ.\n"
	.string "{JPN}ポケモンたち つかれてるでしょう?\p"
	.string "{JPN}よかったら ここで やすんでいって.\n"
	.string "{JPN}それが いちばんよ! そうしなさい.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "{JPN}そうそう.\n"
	.string "{JPN}ゆっくり やすんでいきなさい!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "{JPN}あらあら まあ.\n"
	.string "{JPN}ポケモンたち まだ つかれてるの?\p"
	.string "{JPN}もう いちど ここで やすみなさい.\n"
	.string "{JPN}それが いちばんよ.そうしなさい.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "{JPN}そうなの?\n"
	.string "{JPN}えんりょ することは ないのよ.$"

