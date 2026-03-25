Gate_EcruteakCity_Route38_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "{JPN}どちらから いらしたって?\p"
	.string "{JPN}ワカバタウン?\p"
	.string "{JPN}ウツギはかせが すんでる\n"
	.string "{JPN}ところですよね?\p"
	.string "{JPN}ここまで ながい みちのりを\n"
	.string "{JPN}あるいて きたんですね.$"
