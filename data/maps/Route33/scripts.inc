Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "{JPN}トンネルを ぬけてきたが\n"
	.string "{JPN}まだまだ げんきが\l"
	.string "{JPN}あまってるぜ!$"

Route33_Text_HikerAnthony2Beaten:
	.string "{JPN}うわあ! きみのほうが\n"
	.string "{JPN}げんきだなあ!$"

Route33_Text_HikerAnthony2After:
	.string "{JPN}おれたち やまおとこは\n"
	.string "{JPN}やまが いちばんだ!$"

Route33_Text_HikerAnthonyDunsparce:
	.string "{JPN}おい ノコッチは\n"
	.string "{JPN}つかまえたかい?\p"
	.string "{JPN}おれも つかまえたんだ\p"
	.string "{JPN}あかりで てらして\nみてみろよ\lへんな かおしてるぞ!$"

Route33_Text_Lass:
	.string "{JPN}はあはあ..\n"
	.string "{JPN}やっとどうくつをぬけたわ\p"
	.string "{JPN}おもったよりなかが\n"
	.string "{JPN}ずっとひろいんだもの\l"
	.string "{JPN}ぜんぶみてまわれないうちに\l"
	.string "{JPN}つかれてでてきちゃった$"