RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "{JPN}そのけついな ひょうじょう...\n"
	.string "{JPN}そのしなやかな うごき...\l"
	.string "{JPN}そして よくきたえられた ポケモン...\p"
	.string "{JPN}きみは あきらかに うでのたつ\n"
	.string "{JPN}トレーナーだ!\p"
	.string "{JPN}いや まて なにもいうな.\n"
	.string "{JPN}みただけで わかるよ.\p"
	.string "{JPN}きみなら この ひでんマシンを\n"
	.string "{JPN}うまく つかえるはずだ.\p"
	.string "{JPN}えんりょや はずかしがる\nひつようはない.\nさあ うけとってくれ!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "{JPN}そのひでんマシン みじかく\n"
	.string "{JPN}HMっていうのは いあいぎりだ.\p"
	.string "{JPN}HMのわざは せんとうがいでも\n"
	.string "{JPN}ポケモンがつかえるわざだよ.\p"
	.string "{JPN}いあいぎりをおぼえられる\n"
	.string "{JPN}ポケモンなら トレーナーが\l"
	.string "{JPN}いわバッジをもっていれば\l"
	.string "{JPN}ほそいきをきりたおせるんだ.\p"
	.string "{JPN}それにいちばんいいのは\nわざをおしえなくても\lだいじょうぶってことだよ.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "{JPN}カナズミシティを かくちょう\n"
	.string "{JPN}したとき おとうさんも\l"
	.string "{JPN}てつだったんだ.\p"
	.string "{JPN}ポケモンに いあいぎりを\nつかわせて きのちを\lきれいにしたんだよ.$"

