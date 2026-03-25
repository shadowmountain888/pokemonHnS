MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "{JPN}おとうとは みんなの\n"
	.string "{JPN}ひみつきちを さがすのが\lすきだって いってるの$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "{JPN}おとうとは みんなの\n"
	.string "{JPN}ひみつきちを たずねて\l"
	.string "{JPN}ポケモンバトルするのが\pすきだって いってるの$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "{JPN}{STR_VAR_1}の ちかくに\n"
	.string "{JPN}ひみつきちを つくったのって\lあなた?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "{JPN}どこかに ひみつきちを\n"
	.string "{JPN}つくってよ!\lさがしに いくから!$"

MossdeepCity_House4_Text_Skitty:
	.string "{JPN}エネコ: みゃーん?$"

