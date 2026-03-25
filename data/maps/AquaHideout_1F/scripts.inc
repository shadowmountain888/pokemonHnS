AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_SAYO, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "{JPN}なに?なに?チーム アクアに\n"
	.string "{JPN}なんの ようだ?\p"
	.string "{JPN}おれたちの ボスは いないぞ!\n"
	.string "{JPN}たいせつな ものを うばいに\n"
	.string "{JPN}いったからな!\p"
	.string "{JPN}... ...\n"
	.string "{JPN}どこに いったって?\p"
	.string "{JPN}わはは!そんな だいじなことを\nきみに おしえると おもうか?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "{JPN}なに? なに?\n"
	.string "{JPN}きみは マグマだんの したっぱ?\p"
	.string "{JPN}マグマだんが アジトで\n"
	.string "{JPN}すごい ポケモンを めざめさせ\l"
	.string "{JPN}ようと してるって きいたよ.\p"
	.string "{JPN}でも そのアジトって\nどこに あるんだろう?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "{JPN}なに?なに?チーム アクアに\n"
	.string "{JPN}なんの ようだ?\p"
	.string "{JPN}おれたちの ボスは いないぞ!\n"
	.string "{JPN}せんすいかんを のっとりに\n"
	.string "{JPN}いったからな!\p"
	.string "{JPN}... ...\n"
	.string "{JPN}どこに いったって?\p"
	.string "{JPN}わはは!そんな だいじなことを\nきみに おしえると おもうか?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "{JPN}なに?なに?チーム アクアに\n"
	.string "{JPN}なんの ようだ?\p"
	.string "{JPN}おれたちの ボスは いないぞ!\n"
	.string "{JPN}122ばん どうろの おくりびやまに\n"
	.string "{JPN}むかったからな!\p"
	.string "{JPN}... ...\n"
	.string "{JPN}なぜ いったって?\p"
	.string "{JPN}わはは!そんな だいじなことを\nきみに おしえると おもうか?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "{JPN}なに? なに?\n"
	.string "{JPN}きみは マグマだんの したっぱ?\p"
	.string "{JPN}マグマだんが えんとつやまで\n"
	.string "{JPN}すごい ポケモンを ねらってるって\l"
	.string "{JPN}きいたよ.\pでも その ポケモンって\nどんなのかな?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "{JPN}なに?なに?チーム アクアに\n"
	.string "{JPN}なんの ようだ?\p"
	.string "{JPN}おれたちの ボスは いないぞ!\n"
	.string "{JPN}カイナシティに むかったからな!\p"
	.string "{JPN}... ...\n"
	.string "{JPN}なぜ いったって?\p"
	.string "{JPN}わはは!そんな だいじなことを\n"
	.string "{JPN}きみに おしえると おもうか?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "{JPN}あいやいやい!\n"
	.string "{JPN}あやしいやつを はっけん!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "{JPN}ぐるるる...\n"
	.string "{JPN}まけちまった!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "{JPN}チームの ために まけたが\n"
	.string "{JPN}やくめは はたしたぞ...$"
