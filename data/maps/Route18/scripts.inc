Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route18_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route18_EventScript_Boris::
	trainerbattle_single TRAINER_BORIS Route18_Text_BirdKeeperBorisSeen, Route18_Text_BirdKeeperBorisBeaten
	msgbox Route18_Text_BirdKeeperBorisAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Bob::
	trainerbattle_single TRAINER_BOB Route18_Text_BirdKeeperBobSeen, Route18_Text_BirdKeeperBobBeaten
	msgbox Route18_Text_BirdKeeperBobAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_SIGN
	end

Route18_Text_BirdKeeperBorisSeen:
	.string "{JPN}ポケモンを さがしているなら\n"
	.string "{JPN}たかい くさむらを みなくちゃ!$"

Route18_Text_BirdKeeperBorisBeaten:
	.string "{JPN}あいたたー!$"

Route18_Text_BirdKeeperBorisAfterBattle:
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}バトルが たのしいんだろうね$"

Route18_Text_BirdKeeperBobSeen:
	.string "{JPN}サイクリングロードは\n"
	.string "{JPN}タマムシシティへの ちかみちだよ$"

Route18_Text_BirdKeeperBobBeaten:
	.string "{JPN}...ふう!$"
Route18_Text_BirdKeeperBobAfterBattle:
	.string "{JPN}じてんしゃを もってないと\n"
	.string "{JPN}ちかみちは つかえないんだ$"
	.string ""

Route18_Text_Sign:
	.string "{JPN}18ばんどうろ\p"
	.string "{JPN}タマムシシティ - セキチクシティ$"
