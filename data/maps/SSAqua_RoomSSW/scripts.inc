SSAqua_RoomSSW_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "{JPN}カントーちほうで\n"
	.string "{JPN}かえんショーを やるんだ!$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "{JPN}シュウ... ほのおが ちっちゃく\nなっちゃった...$"
SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "{JPN}うみのうえでは ほのおは\n"
	.string "{JPN}よわいのかな?\nそんなこと ないって?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "{JPN}おばあちゃんに あいに\n"
	.string "{JPN}いくついでに むしポケモンを\nつかまえるんだ!$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "{JPN}うわあ つよいなあ!$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "{JPN}ジョウトちほうの きには\n"
	.string "{JPN}たくさんの ポケモンが\nいるんだよ!$"
