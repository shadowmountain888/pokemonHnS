CianwoodHouse2_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "{JPN}おっ？かんこうきゃくか？\n"
	.string "{JPN}だったらしゃしんとってけー\p"
	.string "{JPN}そとにカメラあっただろ？\n"
	.string "{JPN}あれをおいたのわしー！\p"
	.string "{JPN}ほかにもわしのしんせきが\n"
	.string "{JPN}カメラもってあちこちに\l"
	.string "{JPN}あらわれるとおもうけど..\l"
	.string "{JPN}まずはここで1まいとってけー\p"
	.string "{JPN}カメラしらべれば\n"
	.string "{JPN}じどうでしゃしんとれっから\l"
	.string "{JPN}ポケモンといっしょに\l"
	.string "{JPN}たびのおもいでのこしてけー！$"
CianwoodCity_Text_LugiaHouseLass:
	.string "{JPN}ぎんのはねを もっていないと\n"
	.string "{JPN}みることが できないって\l"
	.string "{JPN}きいたことが あるの.\p"
	.string "{JPN}おなじ においが するのかも\nしれないわね.$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "{JPN}しまのまわりの うずしおは\n"
	.string "{JPN}うみの いきものが おこしてる\l"
	.string "{JPN}って きいたことが あるよ.\p"
	.string "{JPN}とくべつな わざが ないと\n"
	.string "{JPN}とおれないかも しれないね.$"
