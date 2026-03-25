SaffronCity_House1_MapScripts::
	.byte 0

SaffronCity_House1_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_PSYCHIC, SaffronCity_House1_EventScript_MrPsychicAfter
	msgbox MrPsychic_Text_1, MSGBOX_NPC
	giveitem ITEM_TM_PSYCHIC
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	setflag FLAG_GOT_TM_PSYCHIC
	release
	end

SaffronCity_House1_EventScript_MrPsychicAfter::
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	end

MrPsychic_Text_1:
	.string "{JPN}...\p"
	.string "{JPN}...\p"
	.string "{JPN}...\p"
	.string "{JPN}...わかった!\p"
	.string "{JPN}きみは これが ほしかったんだ!$"

MrPsychic_Text_2:
	.string "{JPN}わざマシン29は サイコキネシス.\p"
	.string "{JPN}あいての とくぼうを\n"
	.string "{JPN}さげることが あるよ.$"
