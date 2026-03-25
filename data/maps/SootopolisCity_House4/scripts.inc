SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "{JPN}きいてくれ.いいことを\n"
	.string "{JPN}おしえてやろう.\p"
	.string "{JPN}このあたりのうみには\n"
	.string "{JPN}こだいのいせきがあるらしい.\p"
	.string "{JPN}そのそこには たからものが\n"
	.string "{JPN}ねむっているかもしれないぞ.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "{JPN}こだいの たからもの...\p"
	.string "{JPN}そんなものが あれば いいけど\n"
	.string "{JPN}たとえ なかったとしても\l"
	.string "{JPN}ポケモンと いっしょに すいちゅうを\l"
	.string "{JPN}さんぽできたら きれいだろうな$"

SootopolisCity_House4_Text_Azumarill:
	.string "{JPN}マリルリ:まるりー.$"

