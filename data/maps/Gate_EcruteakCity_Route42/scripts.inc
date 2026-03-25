Gate_EcruteakCity_Route42_MapScripts::
	.byte 0

Gate_EcruteakCity_Route42_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route42_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route42_Text_EcruteakGateOfficer:
	.string "{JPN}シロガネやまの なかは\n"
	.string "{JPN}まよいみちに なってるんだ.\p"
	.string "{JPN}きを つけて.\n"
	.string "{JPN}まよわないように してくれ.$"

