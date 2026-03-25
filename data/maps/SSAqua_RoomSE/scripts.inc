SSAqua_RoomSE_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
    .string "{JPN}おい きみ!ぼくと\n"
	.string "{JPN}バトルしないか?$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
    .string "{JPN}つよいなあ!$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
    .string "{JPN}ひとりで たびをしてるのか?\n"
	.string "{JPN}おかあさんは しんぱいじゃない?$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
    .string "{JPN}あたしのこと あかちゃんだと\n"
	.string "{JPN}おもってるの? ひどいわ!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
    .string "{JPN}あー! まけちゃった!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
    .string "{JPN}あかちゃんなんて よぶのは\n"
	.string "{JPN}おんなのこに しつれいよ!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
    .string "{JPN}あたし あかちゃんじゃないもん!\n"
	.string "{JPN}おねえさんに しつれいよ!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
    .string "{JPN}あー! まけちゃった!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
    .string "{JPN}ときには こどもの ほうが\n"
	.string "{JPN}おとなより かしこいのよ!$"
