SSAqua_RoomNE_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "{JPN}ひとりなのか?\n"
	.string "{JPN}それじゃあ しょうぶだ!$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "{JPN}これは てごわすぎる!$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "{JPN}カントーちほうには\n"
	.string "{JPN}のぼりがいのある やまは\nあるのかなあ?$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "{JPN}リリィって しってるか?\n"
	.string "{JPN}カントーの にんきDJなんだ$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "{JPN}ぎゃああああ!$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "{JPN}リリィも いいけど\n"
	.string "{JPN}マリィが さいこうだ!\n"
    .string "{JPN}ジョウトちほうの ラジオ\n"
	.string "{JPN}ばんぐみも チェック\n"
    .string "{JPN}したいなあ!$"
