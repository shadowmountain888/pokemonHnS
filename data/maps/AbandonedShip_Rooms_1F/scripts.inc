AbandonedShip_Rooms_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_JULIA, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "{JPN}このしゅるいの ふねは\n"
	.string "{JPN}めずらしいから\n"
	.string "{JPN}みてまわってるんだ.\p"
	.string "{JPN}ふむふむ...\nほかにも きゃくしつが\nありそうだな...$"
AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "{JPN}いったい なにが きみを\n"
	.string "{JPN}ここに つれてきたの?\lこうきしんが つよいのね!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "{JPN}こうきしんが つよいだけじゃ\nなくて つよいのね...$"
AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "{JPN}となりの おとこのひと...\p"
	.string "{JPN}かんこうだって いってるけど\n"
	.string "{JPN}どうかしらね.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "{JPN}きみって とても つよい\n"
	.string "{JPN}トレーナーなのね!\lきねんに とうろくさせて!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "{JPN}いったい なにが きみを\n"
	.string "{JPN}また ここに つれてきたの?\lほんとうに こうきしんが\nつよいのね!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "{JPN}きみって つよすぎない?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "{JPN}あの おとこの ひと\n"
	.string "{JPN}ぜったい なにか たくらんでる!\lとても あやしい こうどうを\nしてるのよ!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "{JPN}うわあああ!\n"
	.string "{JPN}みつかっちゃった!\n...あれ?$"
AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "{JPN}あ... きみ おかあさんじゃ\nないんだ.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "{JPN}おかあさんに おこられて\n"
	.string "{JPN}にげてきたんだ.\lぼくが ここにいること\nないしょにしてね!$"

