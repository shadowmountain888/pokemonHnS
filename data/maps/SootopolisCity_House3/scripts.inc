SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "{JPN}きみは ポケモントレーナー\n"
	.string "{JPN}だよね?\p"
	.string "{JPN}ルネシティの アダンには\n"
	.string "{JPN}たくさんの ファンが いるんだ.\nでしの ミクリよりも おおいよ!\pきみには ファンが いるの?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "{JPN}そうか それなら きっと\nかなり つよいんだね.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "{JPN}あら まあ...\n"
	.string "{JPN}ちょっと さびしいわね.\p"
	.string "{JPN}ファンを つくるために\n"
	.string "{JPN}もう すこし がんばって みて.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "{JPN}ねっしんな ファンたちは\n"
	.string "{JPN}ホウエンの そとからも やってくるんだ.\p"
	.string "{JPN}ミナモシティの トレーナー\n"
	.string "{JPN}ファンクラブに いったときは\nほんとうに すごかったよ.$"

