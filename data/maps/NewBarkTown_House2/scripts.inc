NewBarkTown_House2_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "{JPN}あら{PLAYER}くん！\p"
	.string "{JPN}うちのだんな\n"
	.string "{JPN}なんだかいそがしそうだけど\l"
	.string "{JPN}むりしてないかしら？\p"
	.string "{JPN}ポケモンのけんきゅうになると\n"
	.string "{JPN}むちゅうでごはんもたべないのよ$"
NewBarkTown_House2_Text_ElmsSon:
	.string "{JPN}ぼくおおきくなったら\n"
	.string "{JPN}おとうさんのおてつだいをする！\p"
	.string "{JPN}そしてすごい\n"
	.string "{JPN}ポケモンはかせになるんだ！$"