AbandonedShip_Rooms2_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_RUSS, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "{JPN}ダン: たからものを さがしてたら\n"
	.string "{JPN}トレーナーを はっけんしたぞ!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "{JPN}ダン: きょうりょくしても\n"
	.string "{JPN}かてなかった...$"
AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "{JPN}ダン: たからものが\n"
	.string "{JPN}みつからない...\nだれかに とられちゃったのかな?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "{JPN}ダン: ポケモンが 2ひきも いないのか.\n"
	.string "{JPN}それじゃ ぼくらには かてないよ.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "{JPN}キラ: あら?\n"
	.string "{JPN}たからものを さがしてたのに\l"
	.string "{JPN}トレーナーを みつけちゃった!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "{JPN}キラ: うわあ つよーい!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "{JPN}キラ: たからものは どこかしら?\p"
	.string "{JPN}たからものを みつけたら なにを\n"
	.string "{JPN}かおうか もう きめてるの!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "{JPN}キラ: あら ポケモンが 2ひきいないの?\n"
	.string "{JPN}それじゃ こんどに しましょう!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "{JPN}キラ: もう むかつく!\n"
	.string "{JPN}でんわばんごう とうろくしちゃうから!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "{JPN}ダン: ずっと たからものを\n"
	.string "{JPN}さがしつづけてたんだ.\p"
	.string "{JPN}ぼくらの ポケモンも つよくなった.\n"
	.string "{JPN}みせてあげようか?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "{JPN}ダン: あいかわらず つよいなあ!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "{JPN}ダン: たからものは みつからないし\n"
	.string "{JPN}ポケモンバトルは まけるし...\p"
	.string "{JPN} かえりたいよ... でも そんなこと\n"
	.string "{JPN}いったら かのじょに おこられるし...$"
AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "{JPN}ダン: ポケモンが 2ひきも いないのか.\n"
	.string "{JPN}それじゃ ぼくらには かてないよ.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "{JPN}キラ: あら? また あったわね!\p"
	.string "{JPN}わたしたちと おなじで あなたも\n"
	.string "{JPN}たからものさがしを あきらめてない?\p"
	.string "{JPN}まけたほうが たからものさがしを\n"
	.string "{JPN}やめるって のは どう?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "{JPN}キラ: あー また まけちゃった...$"
AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "{JPN}キラ: ポケモンを もっと そだてて\n"
	.string "{JPN}ここの たからものを みつけるまで\l"
	.string "{JPN}かえらないわよ!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "{JPN}キラ: あら ポケモンが 2ひきいないの?\n"
	.string "{JPN}それじゃ こんどに しましょう!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "{JPN}およぐのは にがてだけど\n"
	.string "{JPN}バトルは とくいなのよ!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "{JPN}あらら.\n"
	.string "{JPN}うまく いかなかったわね.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "{JPN}このふねのなかを はだしで\n"
	.string "{JPN}あるくのって きもちわるいね.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "{JPN}つよさと やさしさ...\n"
	.string "{JPN}それが トレーナーの たからもの!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "{JPN}ああ きみには なにか\n"
	.string "{JPN}ひかるものが あるね.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "{JPN}どこかの きゃくしつで\n"
	.string "{JPN}ひかるものを みたよ.$"
