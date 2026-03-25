Route26_House1_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
    .string "{JPN}きみの ポケモンたち\n"
	.string "{JPN}ちょっと つかれているね.\pすこし やすませて\nあげたほうが いいよ.$"

Route26_Text_HealHouseKeepAtIt:
    .string "{JPN}はい!\p"
	.string "{JPN}きみの ポケモンたち\n"
    .string "{JPN}げんきに なったよ!\pがんばって!$"
