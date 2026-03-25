OlivineCity_Mart_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "{JPN}あなたのポケモン\n"
	.string "{JPN}ひとをのせてうみをすすむわざは\l"
	.string "{JPN}もうおぼえてるのかしら？$"
OlivineCity_Text_MartLass:
	.string "{JPN}がいこくにいる\n"
	.string "{JPN}かれからもらったバタフリー\l"
	.string "{JPN}メールもってたの！\p"
	.string "{JPN}なんてかかれてたかしりたい？\n"
	.string "{JPN}えーとね..\p"
	.string "{JPN}やっぱりひ み つ！$"