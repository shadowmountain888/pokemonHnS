CeladonCity_House1_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "{JPN}こんにちは!\p"
	.string "{JPN}いま だいしょくらい\n"
	.string "{JPN}たいかいを やってるんです.\p"
	.string "{JPN}いま おきゃくさまには\nサービス できません.\nすみません.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "{JPN}...ずるずる もぐもぐ...$"
CeladonCity_House1_Text_Fisher1Concentration:
	.string "{JPN}はなしかけないで!\p"
	.string "{JPN}しゅうちゅうりょくが\nとぎれちゃうよ!$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "{JPN}...ごくり... もぐもぐ...$"
CeladonCity_House1_Text_Fisher2Quantity:
	.string "{JPN}りょうより かず!\n"
	.string "{JPN}おなかがいっぱいに\lなったら しあわせだ!$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "{JPN}むしゃむしゃ...$"
CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "{JPN}ここの たべものも\n"
	.string "{JPN}おいしいけど\l"
	.string "{JPN}コガネシティが いちばん\nおいしいよ.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "{JPN}ばりばり... ばりばり...$"
CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "{JPN}ここでは だれも コインケースを\n"
	.string "{JPN}くれません. ジョウトで\lさがしてみて ください.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "{JPN}ばりばり... ばりばり...\p"
	.string "{JPN}まだまだ たべられるよ!\p"
	.string "{JPN}もっと シェフ!$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "{JPN}だいしょくらい たいかい!\n"
	.string "{JPN}じかんせいげんなし!\p"
	.string "{JPN}おわりなき たたかい!\nいちばん いっぱい たべた\lひとは ぜんぶ ただ!$"

