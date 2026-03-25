SSAqua_RoomNNE_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "{JPN}カントーちほうに いって\n"
	.string "{JPN}うでだめしを するんだ!$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "{JPN}かちたかったのに!$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "{JPN}ジョウトちほうの\n"
	.string "{JPN}トレーナーでも カントーの\l"
    .string "{JPN}ジムリーダーと たたかえるんだ$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "{JPN}チャンピオンを めざして\n"
	.string "{JPN}しゅぎょう しているの!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "{JPN}わたしたちの ちがいって\n"
	.string "{JPN}なんなのかしら?$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "{JPN}いつか あなたに\n"
	.string "{JPN}かってみせるわ!$"
