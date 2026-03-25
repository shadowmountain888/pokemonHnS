.set LOCALID_DOJO_LICKILICKY, 1
.set LOCALID_DOJO_MACHAMP, 2
.set LOCALID_DOJO_STEELIX, 3
.set LOCALID_DOJO_ALAKAZAM, 4
.set LOCALID_DOJO_SLOWKING, 5
.set LOCALID_DOJO_PIDGEOT, 6

SaffronCity_FightingDojo_MapScripts::
	.byte 0

SaffronCity_FightingDojo_EventScript_StatueLeft::
	msgbox SaffronCity_FightingDojo_Text_Sign1, MSGBOX_SIGN
	end
SaffronCity_FightingDojo_EventScript_StatueRight::
	msgbox SaffronCity_FightingDojo_Text_Sign2, MSGBOX_SIGN
	end

SaffronCity_FightingDojo_EventScript_BlackBelt::
	msgbox SaffronCity_FightingDojo_Text_BlackBelt, MSGBOX_NPC
	end

SaffronCity_FightingDojo_EventScript_Cooltrainer::
	msgbox SaffronCity_FightingDojo_Text_Cooltrainer, MSGBOX_NPC
	end

SaffronCity_FightingDojo_EventScript_Refused::
	closemessage
	release
	end

SaffronCity_FightingDojo_EventScript_Lickilicky_EV_HP::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LICKILICKY, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Lickilicky, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_1, SaffronCity_FightingDojo_EventScript_BattleLickilicky_EV_HP
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_LICKILICKY
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_HP
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleLickilicky_EV_HP::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_LICKILICKY, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_1
	release
	end
	
SaffronCity_FightingDojo_Text_Lickilicky:
	.string "{JPN}ベロベルト: ベローーーー!$"

SaffronCity_FightingDojo_EventScript_Machamp_EV_Attack::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Machamp, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_2, SaffronCity_FightingDojo_EventScript_BattleMachamp_EV_Attack
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_MACHAMP
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Attack
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleMachamp_EV_Attack::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_MACHAMP, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_2
	release
	end

SaffronCity_FightingDojo_Text_Machamp:
	.string "{JPN}カイリキー: カイリキー!$"

SaffronCity_FightingDojo_EventScript_Steelix_EV_Defense::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Steelix, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_3, SaffronCity_FightingDojo_EventScript_BattleSteelix_EV_Defense
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_STEELIX
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Defense
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleSteelix_EV_Defense::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_STEELIX, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_3
	release
	end

SaffronCity_FightingDojo_Text_Steelix:
	.string "{JPN}ハガネール: ガリガリガリ!$"

SaffronCity_FightingDojo_EventScript_Alakazam_EV_SpecialAttack::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Alakazam, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_4, SaffronCity_FightingDojo_EventScript_BattleAlakazam_EV_SpecialAttack
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_ALAKAZAM
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_SpecialAttack
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleAlakazam_EV_SpecialAttack::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_ALAKAZAM, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_4
	release
	end

SaffronCity_FightingDojo_Text_Alakazam:
	.string "{JPN}フーディン: フーディン!$"

SaffronCity_FightingDojo_EventScript_Slowking_EV_SpecialDefense::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Slowking, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_5, SaffronCity_FightingDojo_EventScript_BattleSlowking_EV_SpecialDefense
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_SLOWKING
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_SpecialDefense
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleSlowking_EV_SpecialDefense::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_SLOWKING, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_5
	release
	end

SaffronCity_FightingDojo_Text_Slowking:
	.string "{JPN}ヤドキング: うーん...$"

SaffronCity_FightingDojo_EventScript_Pidgeot_EV_Speed::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Pidgeot, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_6, SaffronCity_FightingDojo_EventScript_BattlePidgeot_EV_Speed
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_PIDGEOT
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Speed
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattlePidgeot_EV_Speed::
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_PIDGEOT, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_6
	release
	end

SaffronCity_FightingDojo_Text_Pidgeot:
	.string "{JPN}ピジョット: ピジョーー!$"

SaffronCity_FightingDojo_Text_HP:
	.string "{JPN}HP$"
SaffronCity_FightingDojo_Text_Attack:
	.string "{JPN}こうげき$"
SaffronCity_FightingDojo_Text_Defense:
	.string "{JPN}まいりましたわ\n"
	.string "{JPN}おつよいですのね..\p"
	.string "{JPN}このレインボーバッジ\n"
	.string "{JPN}さしあげなくてはなりません$"
SaffronCity_FightingDojo_Text_SpecialAttack:
	.string "{JPN}とくこう$"
SaffronCity_FightingDojo_Text_SpecialDefense:
	.string "{JPN}とくぼう$"
SaffronCity_FightingDojo_Text_Speed:
	.string "{JPN}すばやさ$"

SaffronCity_FightingDojo_Text_WouldYouLikeToBattle:
	.string "{JPN}{STR_VAR_2}の きそポイント3で\n{STR_VAR_1}と たたかいますか?$"

SaffronCity_FightingDojo_Text_BlackBelt:
	.string "{JPN}かくとうどうじょうへ ようこそ!\p"
	.string "{JPN}ここでは たたかいによって\n"
	.string "{JPN}ポケモンの のうりょくを\nきたえることが できるぞ!$"

SaffronCity_FightingDojo_Text_Sign1:
	.string "{JPN}ひだり: HP ぼうぎょ とくぼう$"

SaffronCity_FightingDojo_Text_Sign2:
	.string "{JPN}みぎ: こうげき とくこう すばやさ$"

SaffronCity_FightingDojo_Text_Cooltrainer::
	.string "{JPN}カントーちほうの バッジを\n"
	.string "{JPN}すべて もっている\nトレーナーのみが\nVIPラウンジに はいれます$"

@Ability swapper

SaffronCity_FightingDojo_Ability_Man::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojo_Ability_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_FightingDojo_Ability_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_FightingDojo_Ability_No
	end

SaffronCity_FightingDojo_Ability_No:
	msgbox SaffronCity_FightingDojo_Ability_Text_No, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_SetZeroNoMoney::
	msgbox SaffronCity_FightingDojo_SetZeroTextNoMoney, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_Ability_CheckMoney:
	checkmoney 25000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq SaffronCity_FightingDojo_Ability_Continue
	compare VAR_RESULT, FALSE
	goto_if_eq SaffronCity_FightingDojo_SetZeroNoMoney
	end

SaffronCity_FightingDojo_Ability_Continue:
	closemessage
	special ChoosePartyMon
	waitstate
	special SwitchMonAbility
	compare VAR_RESULT, TRUE
	goto_if_eq SaffronCity_FightingDojo_Ability_Finish
	compare VAR_RESULT, FALSE
	goto_if_eq SaffronCity_FightingDojo_Ability_Cant
	end

SaffronCity_FightingDojo_Ability_Cant:
	msgbox SaffronCity_FightingDojo_Ability_Text_Cant, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_Ability_Finish:
	fadescreen 0x1
	delay 100
	fadescreen 0x0
	faceplayer
	waitse
	playse SE_EXP_MAX
	msgbox SaffronCity_FightingDojo_Ability_Finish_Text, MSGBOX_DEFAULT
	removemoney 25000, 0
	closemessage
	release
	end

SaffronCity_FightingDojo_Ability_Finish_Text:
	.string "{JPN}これで おしまいです!\nまた どうぞ!$"

SaffronCity_FightingDojo_Ability_Text1:
	.string "{JPN}いらっしゃい!\n"
	.string "{JPN}わたしは とくせいの\n"
	.string "{JPN}エキスパートです!\p"
	.string "{JPN}ポケモンの とくせいを\n"
	.string "{JPN}25000えんで\nこうかんできますよ!\pどの ポケモンの とくせいを\nこうかんしますか?$"

SaffronCity_FightingDojo_Ability_Text_No:
	.string "{JPN}そうですね また ひつようなときに\nどうぞ$"

SaffronCity_FightingDojo_Ability_Text_Cant:
	.string "{JPN}それは できません\n"
	.string "{JPN}この ポケモンには\n2ばんめの とくせいが\nありません!$"

SaffronCity_FightingDojo_Ability_Text_NoChampion:
	.string "{JPN}いらっしゃい!\n"
	.string "{JPN}わたしは とくせいの\n"
	.string "{JPN}エキスパートです!\p"
	.string "{JPN}ポケモンの とくせいを\n"
	.string "{JPN}こうかんできるのですが\p"
	.string "{JPN}ざんねんながら こしが\nいたくて きょうは\nしごとが できません\pまた あとで きてください!$"

SaffronCity_FightingDojo_SetZeroTextNoMoney:
	.string "{JPN}おかねが たりません\p"
	.string "{JPN}おかねを もってきてから\nまた きてください$"

