SproutTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "{JPN}どんなに はげしく たたかっても\n"
	.string "{JPN}この とうは つよく たっている$"

SproutTower_Text_SageNico_Beaten:
	.string "{JPN}いっしょうけんめい たたかったが\nわたしは よわすぎた$"

SproutTower_Text_SageNico_AfterBattle:
	.string "{JPN}やわらかい はしらが とうを\n"
	.string "{JPN}じしんからも まもっているのじゃ$"

SproutTower_Text_SageEdmond_Seen:
	.string "{JPN}...かぜにゆれる はっぱの\nように...$"
SproutTower_Text_SageEdmond_Beaten:
	.string "{JPN}ああ わたしは よわい!$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "{JPN}マダツボミの やさしい\n"
	.string "{JPN}うごきを まねて たたかって\n"
	.string "{JPN}みたのじゃが...\pしゅぎょうが たりなかった\nようじゃのう...$"

SproutTower_Text_2F_Statue:
	.string "{JPN}ポケモンの ぞうじゃ...\p"
	.string "{JPN}とても りっぱに みえるのう...$"
