BattleFrontier_Lounge9_MapScripts::
	.byte 0

BattleFrontier_Lounge9_Heal::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSTidalRooms_EventScript_Bed_PokecenterChallenge
	msgbox BattleFrontier_Lounge9_Heal_TEXT, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox BattleFrontier_Lounge9_Heal_TEXT2, MSGBOX_NPC
	waitmessage
	release
	end

BattleFrontier_Lounge9_Heal_TEXT:
	.string "{JPN}こんにちは!\n"
	.string "{JPN}しゅぎょうどうじょうへ\lようこそ!\pあなたの ポケモンを\nかいふく させて\lいただきます$"

BattleFrontier_Lounge9_Heal_TEXT2:
	.string "{JPN}また おこし ください!$"

BattleFrontier_Lounge9_EV_No:
	msgbox BattleFrontier_Lounge9_EV_No_TEXT, MSGBOX_DEFAULT
	waitmessage
	release
	end

@EV Gym

BattleFrontier_Lounge9_EV_HP::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_HP_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_HP_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_HP_Yes::
	msgbox BattleFrontier_Lounge9_EV_HP_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_WAILORD, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end
	
BattleFrontier_Lounge9_EV_ATK::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_ATK_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_ATK_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_ATK_Yes::
	msgbox BattleFrontier_Lounge9_EV_ATK_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_GALLADE, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SATK::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SATK_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SATK_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SATK_Yes::
	msgbox BattleFrontier_Lounge9_EV_SATK_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_GARDEVOIR, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_DEF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_DEF_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_DEF_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_DEF_Yes::
	msgbox BattleFrontier_Lounge9_EV_DEF_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_AGGRON, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SDEF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SDEF_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SDEF_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SDEF_Yes::
	msgbox BattleFrontier_Lounge9_EV_SDEF_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_LUDICOLO, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SPD::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SPD_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SPD_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SPD_Yes::
	msgbox BattleFrontier_Lounge9_EV_SPD_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_SCEPTILE, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_HP_TEXT:
	.string "{JPN}やあ ともだち!\n"
	.string "{JPN}きみの ポケモンの\l"
	.string "{JPN}HP を きたえて あげるよ\pじゅんびは いいかい?$"

BattleFrontier_Lounge9_EV_HP_TEXT2:
	.string "{JPN}いけ! ホエルオー!$"

BattleFrontier_Lounge9_EV_ATK_TEXT:
	.string "{JPN}オシャ! きみの ポケモンの\n"
	.string "{JPN}こうげきを きたえて あげるぞ\p"
	.string "{JPN}じゅんびは いいか?$"

BattleFrontier_Lounge9_EV_ATK_TEXT2:
	.string "{JPN}いけ! エルレイド!$"

BattleFrontier_Lounge9_EV_SATK_TEXT:
	.string "{JPN}ボンジュール! きみの ポケモンの\n"
	.string "{JPN}とくこうを きたえて あげるよ\p"
	.string "{JPN}じゅんびは いいかい?$"

BattleFrontier_Lounge9_EV_SATK_TEXT2:
	.string "{JPN}いけ! サーナイト!$"
	
BattleFrontier_Lounge9_EV_DEF_TEXT:
	.string "{JPN}よう! きみの ポケモンの\n"
	.string "{JPN}ぼうぎょを きたえて やるぜ\p"
	.string "{JPN}じゅんびは いいか?$"

BattleFrontier_Lounge9_EV_DEF_TEXT2:
	.string "{JPN}いけ! ボスゴドラ!$"

BattleFrontier_Lounge9_EV_SDEF_TEXT:
	.string "{JPN}ボンジュール モントレーナー!\n"
	.string "{JPN}きみの ポケモンの とくぼうを\l"
	.string "{JPN}きたえて あげるよ\pじゅんびは いいかい?$"

BattleFrontier_Lounge9_EV_SDEF_TEXT2:
	.string "{JPN}いけ! ルンパッパ!$"

BattleFrontier_Lounge9_EV_SPD_TEXT:
	.string "{JPN}ふん... きみの\n"
	.string "{JPN}ポケモンのすばやさを\n"
	.string "{JPN}きたえてやろう.\pじゅんびはいいか?$"

BattleFrontier_Lounge9_EV_SPD_TEXT2:
	.string "{JPN}いけ! ジュカイン!$"

BattleFrontier_Lounge9_EV_No_TEXT:
	.string "{JPN}だめ? わかった$"

@Columns text

BattleFrontier_Lounge9_EV_Column::
	msgbox BattleFrontier_Lounge9_EV_Column_Text, MSGBOX_SIGN
	end

BattleFrontier_Lounge9_EV_Column_Text:
    .string "{JPN}しゅぎょうどうじょうへ ようこそ!\p"
	.string "{JPN}ここでは ポケモンの のうりょくを\n"
    .string "{JPN}あげる いろいろな しゅぎょうが\l"
	.string "{JPN}できるぞ\p"
    .string "{JPN}きそポイント リセット:\n"
	.string "{JPN}EV マンが ポケモンの\l"
    .string "{JPN}きそポイントを ゼロにしてくれる\l"
	.string "{JPN}かれは みぎれつに いるぞ\p"
    .string "{JPN}きそポイント しゅぎょう:\n"
	.string "{JPN}6にんの トレーナーが かくのうりょく\l"
    .string "{JPN}に とくか している\l"
	.string "{JPN}ひだりから:ぼうぎょ こうげき\l"
    .string "{JPN}HP すばやさ とくこう とくぼう\p"
	.string "{JPN}ヒント:きょうせいギプスは\n"
    .string "{JPN}きそポイントを 5ばいに してくれる!\p"
	.string "{JPN}ホウエンちほうの チャンピオンに\n"
    .string "{JPN}なったあとは つぎの きのうが\l"
	.string "{JPN}かいほう される:\p"
    .string "{JPN}こたいち しゅぎょう めざパ:\n"
	.string "{JPN}IV マンが ポケモンの こたいちを\l"
    .string "{JPN}さいだいに してくれる\l"
	.string "{JPN}めざめるパワーの タイプも\l"
    .string "{JPN}かえられる\p"
	.string "{JPN}けいけんち しゅぎょう:\n"
    .string "{JPN}ひだりしたの けいけんちナースが\nチーム ぜんたいを きたえてくれる\pとくせい こうかん:\nひだりうえの とくせいエキスパートが\nポケモンが もつ とくせいを\lこうかんしてくれる$"

@EV RESET

BattleFrontier_Lounge9_EV_SetZero::
	lockall
	faceplayer
	goto_if_unset FLAG_EV_MAN_FIRSTIME, BattleFrontier_Lounge9_EV_SetZeroIntro
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNoIntro, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroIntro::
	setflag FLAG_EV_MAN_FIRSTIME
	msgbox BattleFrontier_Lounge9_EV_SetZeroText, MSGBOX_NPC
	waitmessage
	end

BattleFrontier_Lounge9_EV_SetZeroMoney::
	msgbox BattleFrontier_Lounge9_EV_SetZeroMoneyText, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroCheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroCheckMoney::
	checkmoney 20000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroYes
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_EV_SetZeroYes::
	msgbox BattleFrontier_Lounge9_EV_SetZeroText2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge BattleFrontier_Lounge9_EV_SetZeroNo
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroEgg
	goto BattleFrontier_Lounge9_EV_SetZeroSure
	end

BattleFrontier_Lounge9_EV_SetZeroNo::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNo, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroNoMoney::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNoMoney, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroEgg::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextEgg, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroSure::
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextSure, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroProceed
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroProceed::
	faceplayer
	fadescreen 0x1
	delay 30
	removemoney 20000, 0
	fadescreen 0x0
	setvar VAR_0x8000, 0
	setvar VAR_0x8001, 0
	setvar VAR_0x8002, 0
	setvar VAR_0x8003, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special SetHpEvs
	special SetAtkEvs
	special SetDefEvs
	special SetSpdEvs
	special SetSpAtkEvs
	special SetSpDefEvs
	msgbox BattleFrontier_Lounge9_EV_SetZeroText3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroText:
    .string "{JPN}こんにちは トレーナー\n"
	.string "{JPN}わたしの なまえは イーブイ\l"
    .string "{JPN}みんなには EV マンと よばれている\p"
	.string "{JPN}ここは わたしの しせつで\n"
    .string "{JPN}あに の アイブイと いっしょに\l"
	.string "{JPN}しゅぎょうを おこなっている\p"
    .string "{JPN}もし ポケモンの きそポイントを\n"
	.string "{JPN}かんぜんに リセットしたければ\lわたしに こえを かけてくれ$"

BattleFrontier_Lounge9_EV_SetZeroTextNoIntro:
    .string "{JPN}EV マン:おかえり\n"
	.string "{JPN}きみの ポケモンぜんいんの\l"
    .string "{JPN}きそポイントを リセットしようか?$"

BattleFrontier_Lounge9_EV_SetZeroText2:
	.string "{JPN}どの ポケモンの きそポイントを\n"
	.string "{JPN}ゼロに リセットしようか?$"

BattleFrontier_Lounge9_EV_SetZeroText3:
    .string "{JPN}ふう! たいへんだったが\n"
	.string "{JPN}なんとか できた!\lきそポイントが ぜんぶ ゼロに\lなったぞ!$"

BattleFrontier_Lounge9_EV_SetZeroTextEgg:
	.string "{JPN}すまない それは\nできないんだ$"

BattleFrontier_Lounge9_EV_SetZeroTextNo:
	.string "{JPN}ひつようなときは また きてくれ!$"

BattleFrontier_Lounge9_EV_SetZeroMoneyText:
    .string "{JPN}これは かなり こんなんな\n"
	.string "{JPN}かてい なんだ\l"
    .string "{JPN}20000えんが かかる\lつづけるかい?$"

BattleFrontier_Lounge9_EV_SetZeroTextNoMoney:
    .string "{JPN}おかねが たりないようだね\p"
	.string "{JPN}たまったら また きてくれ$"

BattleFrontier_Lounge9_EV_SetZeroTextSure:
    .string "{JPN}ほんとうに この ポケモンの\n"
	.string "{JPN}きそポイントを リセット するかい?\p"
    .string "{JPN}この かてい は もとには\lもどせないぞ$"

@IV setter to 31 (all of them) &&&& HIDDEN POWER Type selector

BattleFrontier_Lounge9_IV_Man::
	checkflag FLAG_IV_SETTER
	lockall
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_IV_ManNoChampion
	call_if_unset FLAG_IV_SETTER, BattleFrontier_Lounge9_IV_First_Time
	msgbox BattleFrontier_Lounge9_IV_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_IV_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_IV_No
	end

BattleFrontier_Lounge9_IV_ManNoChampion::
	msgbox BattleFrontier_Lounge9_IV_TextNoChampion, MSGBOX_NPC
	releaseall
	end

BattleFrontier_Lounge9_IV_First_Time::
	msgbox BattleFrontier_Lounge9_IV_TextFirstTime, MSGBOX_NPC
	setflag FLAG_IV_SETTER
	releaseall
	end

BattleFrontier_Lounge9_IV_No::
	msgbox BattleFrontier_Lounge9_IV_Text_No, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_IV_NoLevel::
	msgbox BattleFrontier_Lounge9_IV_Text_NoLevel, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_IV_CheckMoney::
	checkmoney 100000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_IV_ChoosePkm
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_IV_ChoosePkm::
	faceplayer
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge BattleFrontier_Lounge9_IV_No
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroEgg
	goto BattleFrontier_Lounge9_IV_CheckIfLvlMax
	end

BattleFrontier_Lounge9_IV_CheckIfLvlMax::
	faceplayer
	waitmessage
	checkpartymonlevel 100
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_IV_Continue_Question_CustomOrMax
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_IV_NoLevel
	releaseall
	end

BattleFrontier_Lounge9_IV_Continue_Question_CustomOrMax::
	faceplayer
	msgbox BattleFrontier_Lounge9_IV_Text_CustomizeIVs, MSGBOX_DEFAULT
	waitmessage
	dynmultichoice 20, 8, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, EventScript_IVSetter_Text_CustomizeIVs, EventScript_IVSetter_Text_SetMax
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge9_IV_CustomizeIVs_SelectType
	case 1, BattleFrontier_Lounge9_IV_SetMax
	case MULTI_B_PRESSED, BattleFrontier_Lounge9_IV_No
	closemessage
	release
	end

EventScript_IVSetter_Text_CustomizeIVs:
	.string "{JPN}カスタマイズ$"

EventScript_IVSetter_Text_SetMax:
	.string "{JPN}さいだいち に せっと$"

BattleFrontier_Lounge9_IV_SetMax::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31
	setvar VAR_0x8008, 31
	setvar VAR_0x8009, 31
	setvar VAR_0x800A, 31
	setvar VAR_0x800B, 31
	setvar VAR_UNUSED_0x8014, 31
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpdIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_IV_CustomizeIVs_SelectType:
	msgbox BattleFrontier_Lounge9_IV_Text_CustomizeIVs_SetType, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, EventScript_IVSetter_Type_Fighting, EventScript_IVSetter_Type_Flying, EventScript_IVSetter_Type_Poison, EventScript_IVSetter_Type_Ground, EventScript_IVSetter_Type_Rock, EventScript_IVSetter_Type_Bug, EventScript_IVSetter_Type_Ghost, EventScript_IVSetter_Type_Steel, EventScript_IVSetter_Type_Fairy, EventScript_IVSetter_Type_Fire, EventScript_IVSetter_Type_Water, EventScript_IVSetter_Type_Grass, EventScript_IVSetter_Type_Electric, EventScript_IVSetter_Type_Psychic, EventScript_IVSetter_Type_Ice, EventScript_IVSetter_Type_Dragon, EventScript_IVSetter_Type_Dark 
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fighting
	case 1, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Flying
	case 2, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Poison
	case 3, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ground
	case 4, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Rock
	case 5, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Bug
	case 6, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ghost
	case 7, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Steel
	case 8, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fairy
	case 9, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fire
	case 10, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Water
	case 11, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Grass
	case 12, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Electric
	case 13, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Psychic
	case 14, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ice
	case 15, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dragon
	case 16, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dark
	closemessage
	release
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fighting::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Flying::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Poison::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ground::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Rock::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Bug::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ghost::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Steel::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fairy::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fire::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Water::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Grass::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Electric::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Psychic::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ice::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dragon::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dark::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_IV_TextNoChampion:
	.string "{JPN}ん? なんだ?\p"
	.string "{JPN}ああ きみはトレーナーか.\n"
	.string "{JPN}だが つよいとは\n"
	.string "{JPN}いえないな...\p"
	.string "{JPN}ポケモンリーグをたおして\n"
	.string "{JPN}また きてくれ.\p"
	.string "{JPN}このちほうで いちばん\nつよいトレーニングを\nおしえてやろう!$"

BattleFrontier_Lounge9_IV_Text_CustomizeIVs:
	.string "{JPN}こせいち を とくていの あたい に\n"
	.string "{JPN}せっと して ちがう めざめる\l"
	.string "{JPN}パワー の タイプ を つくりますか?\p"
	.string "{JPN}それとも すべて の こせいち を\n31 に せっと しましょうか?$"

BattleFrontier_Lounge9_IV_Text_CustomizeIVs_SetType:
	.string "{JPN}どの タイプ の めざめるパワー を\n"
	.string "{JPN}おさがし ですか?$"

EventScript_IVSetter_Type_Fighting:
	.string "{JPN}かくとうタイプ$"

EventScript_IVSetter_Type_Flying:
	.string "{JPN}ひこうタイプ$"

EventScript_IVSetter_Type_Poison:
	.string "{JPN}どくタイプ$"

EventScript_IVSetter_Type_Ground:
	.string "{JPN}じめんタイプ$"

EventScript_IVSetter_Type_Rock:
	.string "{JPN}いわタイプ$"

EventScript_IVSetter_Type_Bug:
	.string "{JPN}むしタイプ$"

EventScript_IVSetter_Type_Ghost:
	.string "{JPN}ゴーストタイプ$"

EventScript_IVSetter_Type_Steel:
	.string "{JPN}はがねタイプ$"

EventScript_IVSetter_Type_Fairy:
	.string "{JPN}フェアリータイプ$"

EventScript_IVSetter_Type_Fire:
	.string "{JPN}ほのおタイプ$"

EventScript_IVSetter_Type_Water:
	.string "{JPN}みずタイプ$"

EventScript_IVSetter_Type_Grass:
	.string "{JPN}くさタイプ$"

EventScript_IVSetter_Type_Electric:
	.string "{JPN}でんきタイプ$"

EventScript_IVSetter_Type_Psychic:
	.string "{JPN}エスパータイプ$"

EventScript_IVSetter_Type_Ice:
	.string "{JPN}こおりタイプ$"

EventScript_IVSetter_Type_Dragon:
	.string "{JPN}ドラゴンタイプ$"

EventScript_IVSetter_Type_Dark:
	.string "{JPN}あくタイプ$"

BattleFrontier_Lounge9_IV_Text_SetMaxQuestion:
	.string "{JPN}では すべて の こせいち を\n"
	.string "{JPN}さいだいち の 31 に せっと します.\lつづけて よろしい ですか?$"

BattleFrontier_Lounge9_IV_TextFirstTime:
    .string "{JPN}おお! きみか!\n"
	.string "{JPN}ここでみかけるとは\n"
    .string "{JPN}うれしいぞ!\p"
	.string "{JPN}まて... きみは わたしを\n"
    .string "{JPN}しらないのか?\p"
	.string "{JPN}...\p"
    .string "{JPN}...\p"
	.string "{JPN}そうか! きみを\n"
    .string "{JPN}テレビでみたぞ!\p"
	.string "{JPN}わたしは アイバン だが\n"
    .string "{JPN}アイブイマンと よんでくれ!\p"
	.string "{JPN}そう わたしは\n"
	.string "{JPN}イーブイマンのあにきだ.\n"
	.string "{JPN}とうぜんだろう?\p"
    .string "{JPN}そして きみは...\p"
	.string "{JPN}きみは {PLAYER} \n"
    .string "{JPN}さいきん ポケモンリーグを\n"
	.string "{JPN}せいはしたひとだ!\p"
    .string "{JPN}きみの さいごのたたかいは\n"
	.string "{JPN}すばらしかった.\n"
    .string "{JPN}みていて おおくをまなんだ.\n"
	.string "{JPN}だから きみの\n"
    .string "{JPN}ファンクラブに はいったぞ!\p"
	.string "{JPN}そのあと わたしも\n"
	.string "{JPN}つよくなろうと\n"
	.string "{JPN}きめたんだ.\n"
    .string "{JPN}そして きゅうきょくの\n"
	.string "{JPN}トレーニングを つくりだした.\p"
    .string "{JPN}もちろん ポケモンのためにだ!\n"
	.string "{JPN}きみが のぞむなら\n"
    .string "{JPN}いっしょに トレーニングして\nきみの ポケモンの\nのうりょくを さいだいに\nひきだせるぞ.\pだが... この トレーニングに\nたえるには ポケモンは\nじゅうぶんな じゅんびが\nひつようだ.\nレベル100に たっした\nポケモンだけが\nたえられるのだ.\pためしてみるか?\pきびしくて ながい\nかていなので\n100000えんが ひつようだ.\pじゅんびが できたら\nおしえてくれ!$"

BattleFrontier_Lounge9_IV_Text1:
	.string "{JPN}こせいちマン: やあ! ホウエンちほう\n"
	.string "{JPN}さいこう の きゅうきょく トレーニング\l"
	.string "{JPN}メニュー を うけに きたのかい?\p"
	.string "{JPN}100.000えん かかるけど それだけ の\nかち は あるよ!\lはじめよう か?$"

BattleFrontier_Lounge9_IV_Text_No:
	.string "{JPN}おお... では\nまた こんどな.$"
BattleFrontier_Lounge9_IV_Text_NoLevel:
	.string "{JPN}きみの ポケモンは\n"
	.string "{JPN}まだ さいこうレベルに\nたっしていないようだな...$"
BattleFrontier_Lounge9_IV_Finish:
	.string "{JPN}ふう... つかれた...\n"
	.string "{JPN}きみの ポケモンは\n"
	.string "{JPN}どうだ?\p"
	.string "{JPN}いく まえに すこし\nやすんだほうがいい.\pでは また あおう!$"

@Chansey training

BattleFrontier_Lounge9_Nurse::
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_NurseChampion
	msgbox BattleFrontier_Lounge9_NurseRepeat2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_Lounge9_Chansey1End
	case YES, BattleFrontier_Lounge9_NurseBattle
	case MULTI_B_PRESSED, BattleFrontier_Lounge9_Chansey1End

BattleFrontier_Lounge9_NurseBattle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JOEY, 0, BattleFrontier_Lounge9_NurseIntro, BattleFrontier_Lounge9_NurseDefeat, BattleFrontier_Lounge9_ChanseyBattleAgain
	end

BattleFrontier_Lounge9_Chansey1End::
	closemessage
	end

BattleFrontier_Lounge9_ChanseyBattleAgain::
	faceplayer
	msgbox BattleFrontier_Lounge9_NurseRepeat, MSGBOX_AUTOCLOSE
	clearflag 0x85B
	end

BattleFrontier_Lounge9_NurseChampion:
	faceplayer
	msgbox BattleFrontier_Lounge9_NurseChampionText, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge9_NurseChampionText:
	.string "{JPN}わたし は けいけんち ナース よ!\n"
	.string "{JPN}ざんねん だけど あなた が チャンピオン\l"
	.string "{JPN}に ならない と バトル できないの.$"

BattleFrontier_Lounge9_NurseIntro:
	.string "{JPN}いくわよ ハピナス!$"

BattleFrontier_Lounge9_NurseDefeat:
	.string "{JPN}ああ... ハピナス \nタマゴうみを つかって!$"
BattleFrontier_Lounge9_NurseRepeat:
	.string "{JPN}よろしければ また バトル\nしましょう!$"

BattleFrontier_Lounge9_NurseRepeat2:
	.string "{JPN}バトルの じゅんびは\nできてる?$"

@Ability swapper

BattleFrontier_Lounge9_Ability_Man::
	lockall
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_Ability_ManNoChampion
	msgbox BattleFrontier_Lounge9_Ability_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_Ability_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_Ability_No
	end

BattleFrontier_Lounge9_Ability_ManNoChampion::
	msgbox BattleFrontier_Lounge9_Ability_Text_NoChampion, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_No:
	msgbox BattleFrontier_Lounge9_Ability_Text_No, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_CheckMoney:
	checkmoney 25000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_Ability_Continue
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_Ability_Continue:
	closemessage
	special ChoosePartyMon
	waitstate
	special SwitchMonAbility
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_Ability_Finish
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_Ability_Cant
	end

BattleFrontier_Lounge9_Ability_Cant:
	msgbox BattleFrontier_Lounge9_Ability_Text_Cant, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_Finish:
	fadescreen 0x1
	delay 100
	fadescreen 0x0
	faceplayer
	waitse
	playse SE_EXP_MAX
	msgbox BattleFrontier_Lounge9_Ability_Finish_Text, MSGBOX_DEFAULT
	removemoney 25000, 0
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_Finish_Text:
	.string "{JPN}できあがり! どういたしまして!$"

BattleFrontier_Lounge9_Ability_Text1:
	.string "{JPN}いらっしゃい!\n"
	.string "{JPN}とくせいエキスパートです!\p"
	.string "{JPN}ポケモンの とくせいを\n"
	.string "{JPN}あっというまに いれかえます!\n"
	.string "{JPN}25000えんです!\pどのポケモンの とくせいを\nいれかえますか?$"

BattleFrontier_Lounge9_Ability_Text_No:
	.string "{JPN}はい.ひつようなときは\nこえを かけてください.$"

BattleFrontier_Lounge9_Ability_Text_Cant:
	.string "{JPN}それは むりです.\n"
	.string "{JPN}このポケモンには\n2つめの とくせいが ありません!$"

BattleFrontier_Lounge9_Ability_Text_NoChampion:
	.string "{JPN}いらっしゃい!\n"
	.string "{JPN}とくせいエキスパートです!\p"
	.string "{JPN}ポケモンの とくせいを\n"
	.string "{JPN}あっというまに いれかえられます.\p"
	.string "{JPN}あいにく こしが いたくて\n"
	.string "{JPN}きょうは しごとが できません.\pまた こんど きてください!$"

