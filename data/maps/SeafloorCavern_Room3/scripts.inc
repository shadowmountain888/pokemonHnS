SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_GRANT, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_VANCE, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "{JPN}あははははは!\p"
	.string "{JPN}せんすいかんも なしに どうやって\n"
	.string "{JPN}ここまで きたのかしら?\l"
	.string "{JPN}すごい こどもね!\p"
	.string "{JPN}でも... ここで じゃまを されては\n"
	.string "{JPN}こまるのよ.\p"
	.string "{JPN}それに てんきけんきゅうじょの\n"
	.string "{JPN}ことで おかえしも したいしね...\p"
	.string "{JPN}ちょっと いたいめを みせて\n"
	.string "{JPN}あげるわ! かくごなさい!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "{JPN}あはははは!\p"
	.string "{JPN}いたっ!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "{JPN}あははははは!\n"
	.string "{JPN}あなた とても つよいのね.\p"
	.string "{JPN}チーム アクアの メンバーじゃ\n"
	.string "{JPN}ないなんて とても ざんねんよ.\p"
	.string "{JPN}わたしたちの ボスが やくそくした\n"
	.string "{JPN}すばらしい せかいを\l"
	.string "{JPN}いっしょに たのしめたのに...$"
SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "{JPN}おれたちの ゆめを かなえるには\n"
	.string "{JPN}ポケモンの ちからが ひつようなんだ.\p"
	.string "{JPN}しかし おまえのような じゃまものが\n"
	.string "{JPN}ポケモンの ちからを つかって\l"
	.string "{JPN}こんな ばしょでも じゃまを する!\p"
	.string "{JPN}じんせいって おれたちの\n"
	.string "{JPN}おもうとおりには いかないな!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "{JPN}ぐわあ!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "{JPN}おれたちは リーダーの もくてきを\n"
	.string "{JPN}ぎもんに おもったり しないんだ.\p"
	.string "{JPN}でも きみは ただの がきなのに\n"
	.string "{JPN}おれたちの ボスに たちむかう.\p"
	.string "{JPN}もしかして...\n"
	.string "{JPN}きみって なにか とくべつな...$"
