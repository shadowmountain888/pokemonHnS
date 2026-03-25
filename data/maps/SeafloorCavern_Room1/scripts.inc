SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_TROY, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_TULLY, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "{JPN}がきなんていらねえんだよ!\n"
	.string "{JPN}さっさとうちにかえれ!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "{JPN}いえに かえりたいよ...$"
SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "{JPN}しょうしん して したっぱを\n"
	.string "{JPN}こき つかいたいなあ...$"
SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "{JPN}あの せんすいかん... なかが\n"
	.string "{JPN}せまくて からだが いたいよ!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "{JPN}まけるとむかつくぜ!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "{JPN}おれたちがぶんどった\n"
	.string "{JPN}せんすいかん やべえんだぜ.\l"
	.string "{JPN}なかがせますぎるんだよ!$"

