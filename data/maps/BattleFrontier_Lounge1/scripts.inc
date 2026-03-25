BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "{JPN}70ねんかん ポケモンを そだてて\n"
	.string "{JPN}きた わしじゃ!\l"
	.string "{JPN}でんせつの トップ ポケモン\l"
	.string "{JPN}ブリーダーと よばれておる!\p"
	.string "{JPN}わしほど けいけんを つめば\n"
	.string "{JPN}ポケモンの のうりょくは\l"
	.string "{JPN}ひとめで わかるように なるぞ!\p"
	.string "{JPN}きみは トレーナーじゃな.\n"
	.string "{JPN}じぶんの ポケモンの のうりょく\l"
	.string "{JPN}きょうみは ないかの?\p"
	.string "{JPN}さあ!\nきみの ポケモンを みせて\lもらおうかの!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "{JPN}...ふーん...\p"
	.string "{JPN}このこは ぜんたいてきに\n"
	.string "{JPN}ふつうの のうりょくと いえるね$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "{JPN}...ふーん...\p"
	.string "{JPN}このこは ぜんたいてきに\n"
	.string "{JPN}へいきん いじょうの のうりょくだね$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "{JPN}...ふーん...\p"
	.string "{JPN}このこは ぜんたいてきに\n"
	.string "{JPN}とても すばらしい のうりょくだ!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "{JPN}...ふーん...\p"
	.string "{JPN}このこは ぜんたいてきに\n"
	.string "{JPN}ほんとうに けっしゅつした のうりょくだ!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "{JPN}ちなみに このこの いちばんの\n"
	.string "{JPN}とくちょうは たいりょくだね...$"
BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "{JPN}ちなみに このこの いちばんの\n"
	.string "{JPN}とくちょうは こうげきだね...$"
BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "{JPN}ちなみに このこの いちばんの\n"
	.string "{JPN}とくちょうは ぼうぎょだね...$"
BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "{JPN}ちなみに このこの いちばんの\n"
	.string "{JPN}とくちょうは とくこうだね...$"
BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "{JPN}ちなみに このこの いちばんの\n"
	.string "{JPN}とくちょうは とくぼうだね...$"
BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "{JPN}ちなみに このこの いちばんの\n"
	.string "{JPN}とくちょうは すばやさだね...$"
BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "{JPN}そのステータスは まあまあだね\n"
	.string "{JPN}...ふーん... そんなかんじかな$"
BattleFrontier_Lounge1_Text_StatImpressive:
	.string "{JPN}そのステータスは かなりいいね\n"
	.string "{JPN}...ふーん... そんなかんじかな$"
BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "{JPN}そのステータスは けっしゅつだ!\n"
	.string "{JPN}...ふーん... そんなかんじかな$"
BattleFrontier_Lounge1_Text_StatFlawless:
	.string "{JPN}もう かんぺきだ! しんぴてきだね!\n"
	.string "{JPN}...ふーん... そんなかんじかな$"
BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "{JPN}なんじゃと?\n"
	.string "{JPN}わしの アドバイスを きく\l"
	.string "{JPN}じかんが ないじゃと?\p"
	.string "{JPN}ねんぱいしゃの けいけんから\nまなぼうと する きもちを\lもつべきじゃぞ!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "{JPN}なんじゃ また なにか ようかの?\p"
	.string "{JPN}わしには やるべき しごとが\n"
	.string "{JPN}あるのじゃ!\lまた こんどに しておくれ!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "{JPN}おお わかいの! きみの ポケモン\n"
	.string "{JPN}の のうりょくに きょうみが\l"
	.string "{JPN}あるかの?\p"
	.string "{JPN}さあ さあ!\nきみの ポケモンを みせて\lもらおうかの!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "{JPN}わしは エキスパートじゃが\n"
	.string "{JPN}タマゴの ままでは なんとも\l"
	.string "{JPN}いえんのじゃ!\n"
	.string "{JPN}ポケモンを みせておくれ!\nポケモンを みる ひつようが\lあるのじゃ!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "{JPN}わたしの ポケモンは とても\n"
	.string "{JPN}すばらしいって いわれたの!\nたいせつに そだてて よかった!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "{JPN}わたしの ポケモンが けっしゅつって!\n"
	.string "{JPN}でも とくべつなことは\l"
	.string "{JPN}なにもしてないのに...$"
