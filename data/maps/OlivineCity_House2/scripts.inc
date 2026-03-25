OlivineCity_House2_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "{JPN}タンバへいくとちゅうに\n"
	.string "{JPN}4つのむじんとうがあるんだ\p"
	.string "{JPN}わるいこどもはおしおきに\n"
	.string "{JPN}そのしまへつれてくのさ！$"
OlivineCity_Text_PunishmentBoy:
	.string "{JPN}あたしがイタズラすると\n"
	.string "{JPN}おとうさんすぐにおどかすの..$"