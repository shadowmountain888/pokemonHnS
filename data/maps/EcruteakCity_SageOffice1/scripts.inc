.set LOCALID_SAGEOFFICE_SAGE, 3

EcruteakCity_SageOffice1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "{JPN}すずのねはとうのもとに\nすむものにとってあきらか$"
EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 60
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "{JPN}すずのとうはふさわしくない\nもののりっぷはきんしじゃ\lもうしわけないがかえってくれ$"
EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "{JPN}すずのとうはエンジュジムの\nバッジなしではいっぷきんしじゃ\pおお！\pエンジュのジムバッジ！\nどうぞとおってくだされ$"
EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "{JPN}じゅうだいなできごとが\nおこったのじゃ\pもうしわけないがかえって\nもらわねばならん\p..こころをいやすもの..\pさんけんじゃのことばは\nとてもむずかしいのう..$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "{JPN}じゅうだいな できごとが\n"
	.string "{JPN}おこりました.\p"
	.string "{JPN}もうしわけ ありませんが\n"
	.string "{JPN}でていって いただけませんか.\p...$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "{JPN}さあおとおりなさいまし..$"
EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "{JPN}さあおとおりなさいまし..$"
EcruteakTinTowerEntrance_Text_SageDone:
	.string "{JPN}そのすずのねは\nもつもののこころをあらわす\pきみは..\nまことにふさわしいな$"
EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "{JPN}まえにあるすずのとうは\nきゅうそうのしんせいなとうじゃ\pそれをみるすべてのもののこころを\nいやしてくれるのじゃ$"
EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "{JPN}スズのとうがゆれました！\p"
	.string "{JPN}きっとホウオウが..\n"
	.string "{JPN}ホウオウがもどってきたのです！$"
EcruteakTinTowerEntrance_Text_Gramps:
	.string "{JPN}ふたつのとう..\nふたひきのポケモン..\pだがひとつがやけおちると\nりょうほうとびさっていった$"