SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_TYLER, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_VALERIE, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "{JPN}きみは だれだ?\n"
	.string "{JPN}どこから はいってきた?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "{JPN}Lost it...$"
SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "{JPN}でぐちが みつからないぞ!\p"
	.string "{JPN}べつに こわくなんか ないからな!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "{JPN}きみは だれだ?\n"
	.string "{JPN}どこへ いくつもりだ?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "{JPN}まけちまった!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "{JPN}あいつ せんすいかんに\n"
	.string "{JPN}ちずを わすれてきやがった!\p"
	.string "{JPN}やくに たたないやつだ!$"

