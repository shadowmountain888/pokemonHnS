.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_GARBAGEFLAG
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_SETH, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_STANLY, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_STEVE, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "{JPN}へへへ...\p"
	.string "{JPN}もう ここまで きたのか?\n"
	.string "{JPN}きみを みくびってたよ!\p"
	.string "{JPN}だが ここまでだ!\p"
	.string "{JPN}おれは きみが いままで\n"
	.string "{JPN}あった したっぱとは ちがう.\p"
	.string "{JPN}じかんかせぎじゃない.\n"
	.string "{JPN}きみを こなごなに してやる!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "{JPN}へへへ...\n"
	.string "{JPN}おれも まけちまった...$"
AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "{JPN}へへへ!\p"
	.string "{JPN}おれが きみと あそんでる\n"
	.string "{JPN}あいだに  ボスは じゅんび\lを おえちゃったぜ!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "{JPN}へへへ!\p"
	.string "{JPN}うちの ボスは もう うみの\n"
	.string "{JPN}そこの どうくつに むかった\l"
	.string "{JPN}からな!\p"
	.string "{JPN}もし おいかけるなら\n"
	.string "{JPN}ミナモシティの むこうの\l"
	.string "{JPN}おおきな うみを さがすんだな!\p"
	.string "{JPN}でも みつけられるかな?\nへへへ!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "{JPN}わははは  まちくたびれたぜ!\n"
	.string "{JPN}おまえとも しょうぶだ!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "{JPN}まつのに つかれた...\n"
	.string "{JPN}まけて ぼんやり...$"
AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "{JPN}ボス...\n"
	.string "{JPN}これで いいんですか?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "{JPN}ワープパネルは アジトの\n"
	.string "{JPN}じまんなんだぜ!\p"
	.string "{JPN}じぶんが どこにいるか\n"
	.string "{JPN}わからないだろ?\p"
	.string "{JPN}てきを まよわせて つかれさせて\n"
	.string "{JPN}から どかーんと いく!\lそれが おれたちの さくせんだ!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "{JPN}なんなんだ おまえは?\n"
	.string "{JPN}ぜんぜん つかれてないじゃ\lないか!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "{JPN}そういえば... マスターボールを\n"
	.string "{JPN}どこに おいたか おもいだせない.\p"
	.string "{JPN}まもりに しっぱいしたら ボスに\n"
	.string "{JPN}しかられちまう...$"
AquaHideout_B2F_Text_Grunt8Intro:
	.string "{JPN}アクアだんに はいった とき\n"
	.string "{JPN}さいしょに おぼえたのが\l"
	.string "{JPN}この ワープパネルの つながりだ!$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "{JPN}ワープパネルの ことを\n"
	.string "{JPN}かんがえすぎてた...$"
AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "{JPN}もっと こうかてきに\n"
	.string "{JPN}たたかう ほうほうを まなばないと...$"
