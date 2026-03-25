.set LOCALID_UNION_CAVE_LAPRAS, 6

UnionCave_B2F_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 20
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_B2F_EventScript_Item_MaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "{JPN}ひとには ふたつの\n"
	.string "{JPN}しゅるいが いるんだ.\p"
	.string "{JPN}センスが あるやつと\n"
	.string "{JPN}ないやつ.\pきみは どっちの\nひとかな?$"

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "{JPN}きみは まぶしい センスを\nもってるね!$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "{JPN}きみの ポケモンの センスは\n"
	.string "{JPN}すばらしくて カラフルだ.\p"
	.string "{JPN}これからも どんどん\nうまくなっていくよ!$"

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "{JPN}しゅぎょうちゅうなの.\n1かい どうかしら?$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "{JPN}あーあ! あなた つよすぎ!$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "{JPN}うまくなるまで ひとりで\n"
	.string "{JPN}しゅぎょうするわ.$"

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "{JPN}すきな ポケモンが いるなら\n"
	.string "{JPN}どこへでも いくの.\p"
	.string "{JPN}それが ほんとうの\nトレーナーよ.$"

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "{JPN}こんなことより\nポケモンを なでてたいわ!$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "{JPN}しゅうに いちど だけ\n"
	.string "{JPN}みずべに あらわれる ポケモンが\l"
	.string "{JPN}いるの.\pそのポケモンを みてみたくて...$"
