.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_GARBAGEFLAG
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "{JPN}おれも グラードンを みたいけど\n"
	.string "{JPN}しっぽすら みせてくれない...\p"
	.string "{JPN}ほんとうに イライラするよ\p"
	.string "{JPN}あっ やばい!\n"
	.string "{JPN}グラードンのこと しゃべっちゃった!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "{JPN}れいせいな きもちじゃないと\n"
	.string "{JPN}かつのは むりだな...$"
MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "{JPN}グラードンに しっぽって\nあるのかな?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "{JPN}ふははは!\n"
	.string "{JPN}もうすぐだ! もうすぐ!\l"
	.string "{JPN}おれたちの だいもくてきが\nたっせいされる!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "{JPN}ぐぬぬ...\n"
	.string "{JPN}ここまで きたのに こんなことって?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "{JPN}マツブサさま!\n"
	.string "{JPN}しんにゅうしゃが そちらに\nむかっています!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "{JPN}まだ おわりじゃない!\n"
	.string "{JPN}おれを かんたんに\nとおりぬけられると おもうなよ!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "{JPN}おれって こんなに\nよわかったのか?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "{JPN}こ こんどは もういっかい...$"
MagmaHideout_4F_Text_TabithaIntro:
	.string "{JPN}へへへ!\n"
	.string "{JPN}ここまで きたから おしえてやる!\p"
	.string "{JPN}そうだ!\n"
	.string "{JPN}この さきで グラードンが\n"
	.string "{JPN}ねむっているのだ!\p"
	.string "{JPN}マツブサは ついさっき\n"
	.string "{JPN}グラードンの もとに いった!\p"
	.string "{JPN}もうすぐ めざめるぞ!\nへへ! へへへ!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "{JPN}また やられた...\n"
	.string "{JPN}へへ...$"
MagmaHideout_4F_Text_TabithaPostBattle:
	.string "{JPN}...きみが おれの あいてをしてる\n"
	.string "{JPN}あいだに マツブサさまは グラードンを...$"
MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "{JPN}マツブサ: グラードン...\p"
	.string "{JPN}マグマに つつまれて ねむる\n"
	.string "{JPN}きみを めざめさせるものは なかった...\p"
	.string "{JPN}この あおいたま こそが\n"
	.string "{JPN}きみの もとめていた ものだろう?\p"
	.string "{JPN}あおいたまを もってきた\n"
	.string "{JPN}その かがやきで めざめるがよい!\p"
	.string "{JPN}そして みせてくれ...\n"
	.string "{JPN}きみの ちからの すべてを!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "{JPN}マツブサ: グラードン!\n"
	.string "{JPN}どうしたのだ?\p"
	.string "{JPN}あおいたまが かぎでは なかったのか?\p"
	.string "{JPN}グラードン!\n"
	.string "{JPN}どこへ いってしまったのだ...$"
MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "{JPN}マツブサ: ああ きみか?\p"
	.string "{JPN}あちこちで かってに\n"
	.string "{JPN}うろついているのを みかけたが...\p"
	.string "{JPN}わかったぞ!\n"
	.string "{JPN}きみが へんな じゃまを したのだな!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "{JPN}きみは なぜ そんなに\n"
	.string "{JPN}ポケモンを うまく あつかえるのだ?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "{JPN}マツブサ: グラードンが にげだした\n"
	.string "{JPN}りゆうが あるはずだ...\p"
	.string "{JPN}きみは そう いいたいのだろう?\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}ふん...\n"
	.string "{JPN}そんなこと わからないと おもうか?\p"
	.string "{JPN}グラードンが いなくなった いじょう\n"
	.string "{JPN}この かざんに ようは ない\p"
	.string "{JPN}グラードンを おいかけるから\n"
	.string "{JPN}ここで わかれだ!$"
	.string ""
