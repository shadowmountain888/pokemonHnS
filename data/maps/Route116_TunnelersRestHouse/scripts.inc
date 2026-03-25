Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "{JPN}あそこの カナシダトンネル...\p"
	.string "{JPN}はじめは おおぜいの さぎょういんが\n"
	.string "{JPN}さいしんの きかいで いわを\l"
	.string "{JPN}ほっていたんだ.\p"
	.string "{JPN}でも やめなきゃ ならなくなった.\p"
	.string "{JPN}そのへんの やせいポケモンに\n"
	.string "{JPN}わるいえいきょうを あたえることが\l"
	.string "{JPN}わかったからさ.\p"
	.string "{JPN}だから ここで ごろごろしながら\nなにもしないでいるしか ないんだよ.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "{JPN}バーダントゥーフまで ひとりで\n"
	.string "{JPN}トンネルを ほっている おとこのひと\l"
	.string "{JPN}が いるんだ.\l"
	.string "{JPN}どうしても とおりたいらしい.\p"
	.string "{JPN}きかいを つかわずに\n"
	.string "{JPN}すこしずつ ほっていけば\l"
	.string "{JPN}ポケモンを おどろかせないし\l"
	.string "{JPN}しぜんかんきょうも\lきずつけないって いってた.\pもう つうじたかな?$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "{JPN}このトンネルを つかわずに\n"
	.string "{JPN}バーダントゥーフに いくには\l"
	.string "{JPN}デュフォードまで うみを わたって\l"
	.string "{JPN}カイナまで ふねで いって\lキンセツを とおっていかなきゃ\lならないんだ.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "{JPN}きいた? バーダントゥーフまでの\n"
	.string "{JPN}トンネルが つうじたんだって!\p"
	.string "{JPN}つよく のぞんでいれば\n"
	.string "{JPN}ゆめは かなうことも あるのね.$"

