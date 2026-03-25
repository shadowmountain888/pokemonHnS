.set LOCALID_DIRECTOR_OFFICE, 1
.set LOCALID_GOLDENROD_ARCHER, 2
.set LOCALID_GOLDENROD_ARIANA, 3
.set LOCALID_PETREL_OFFICE, 4
.set LOCALID_DIRECTOR_STUDIO, 5

GoldenrodCity_RadioTower_5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "{JPN}き-きみか！たすけにきてくれたのか？$"
GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "{JPN}そうおもったか？\pざんねん！おれはにせものだ！\pのっとりのじゅんびのために\nほんものになりすましていたのだ\pほんもののきょくちょうを\nどこにかくしたかしりたいか？\pおしえてやろう\nだがまずおれにかってからだ！$"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "{JPN}わかったわかった！\nやつのいばしょをおしえてやる$"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "{JPN}ボスは ディレクターを\n"
	.string "{JPN}ちかそうこに かくしたんだ.\p"
	.string "{JPN}ちかの いちばん おくにあるよ.\p"
	.string "{JPN}おれは やさしいから\n"
	.string "{JPN}ちかそうこに いくための\l"
	.string "{JPN}ちかしつのカギを やろう.\p"
	.string "{JPN}でも そこまで たどりつけるか\n"
	.string "{JPN}あやしいもんだけどな.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "{JPN}ボスは ディレクターを\n"
	.string "{JPN}ちかそうこに かくしたんだ.\p"
	.string "{JPN}ちかの いちばん おくにあるよ.\p"
	.string "{JPN}ちかしつのカギで ちかそうこに\n"
	.string "{JPN}iけるぞ.\p"
	.string "{JPN}でも そこまで たどりつけるか\n"
	.string "{JPN}あやしいもんだけどな.$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "{JPN}チョウジタウンのアジトで\nあったことおぼえてる？\pボスにおこられたけど\nつよくなったのよ！\pあのときはまけたけど\nこんどはまけないわ！$"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "{JPN}そんなばかな！\pがんばってたたかったのに\nまたまけちゃった..\pサカキさまごめんなさい..$"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{JPN}{PLAYER}っていうのね？\pあんたみたいなこどもには\nロケットだんのすばらしさが\pわからないでしょうね\nざんねんだわ\pあなたのちからはみとめるけど$"
GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "{JPN}アポロ: おやおや...\nついにここまできましたか\p"
	.string "{JPN}なかなかゆうしゅうな\nトレーナーのようですね\p"
	.string "{JPN}われわれはラジオきょくをのっとり\nぜんこくにむけて\l"
	.string "{JPN}ふっかつせんげんをするのです\p"
	.string "{JPN}そうすればどこかで\nしゅぎょうちゅうのサカキさまも\l"
	.string "{JPN}もどられるにちがいない\p"
	.string "{JPN}あのむかしのえいこうを\nとりもどすのです...\l"
	.string "{JPN}そのじゃまはさせませんよ!\p$"
GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "{JPN}ば..ばかな！\nサカキさまおゆるしください！$"
GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "{JPN}アポロ: ...なんということだ\p"
	.string "{JPN}すべてのゆめが\nいまおわりましたよ\lやはりわたしではむりでしたか\p"
	.string "{JPN}わかりました\nサカキさまがそうしたように\lわたしたちロケットだんは"
	.string "{JPN}\lここでかいさんしましょう\p"
	.string "{JPN}さらばです\p$"
GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "{JPN}きょくちょう: おお...!\nもうやっつけてくれたのか\l"
	.string "{JPN}れいをいうよほんとありがとう\p"
	.string "{JPN}きみのゆうきあるこうどうが\nぜんこくのポケモンをすくったんだ\p"
	.string "{JPN}よし!きみだったら\nこれをもつのにふさわしいだろう\l"
	.string "{JPN}うけとってくれたまえ!\p$"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "{JPN}むかしここにあったふるいとうを\nたてかえてラジオとうにしたとき\l"
	.string "{JPN}とうのてっぺんでみつかったのが\lそのにじいろのはねなんだ\p"
	.string "{JPN}にじいろのはねがあれば\nエンジュのスズのとうにのぼれる\p"
	.string "{JPN}そんなはなしを\nわたしはタンバのしりあいから\lきいたことがあるよ\p"
	.string "{JPN}さてそろそろわたしは\nきょくちょうしつにもどるよ\lじゃあね!\p$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "{JPN}むかしは ここコガネシティに\n"
	.string "{JPN}とうが たっていたんじゃ.\p"
	.string "{JPN}でも ふるくて きしんでいて\n"
	.string "{JPN}ね.\p"
	.string "{JPN}それで わたしたちの ラジオとう\n"
	.string "{JPN}に たてかえたんじゃよ.\p"
	.string "{JPN}こうじちゅうに その はねを\n"
	.string "{JPN}ほりだしたんじゃ.\p"
	.string "{JPN}むかしは コガネには いろんな\n"
	.string "{JPN}ポケモンが すんでいたと\l"
	.string "{JPN}きいておるよ.\p"
	.string "{JPN}もしかすると...\p"
	.string "{JPN}その はねは タンバシティちかくの\nうずまきじまと かんけいが\lあるのかもしれんのう...\pよし じむしつに もどるとしよう.$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "{JPN}ああ！\pそうそう..\pきみにあげたそのはね..\nでんせつのポケモンと\lかんけいがあるとおもうんだ\pでも！そのはねだけでは\nでんせつのポケモンはあらわれない..\pほかになにかひつようなものが\nあるらしいんだが..\pなんだったかな..\pおもいだせないんだ$"
GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "{JPN}そうそう!\p"
	.string "{JPN}あぶなくわすれるところだった!\p"
	.string "{JPN}タンバのしりあいがいうには\nそのにじいろのはねで\l"
	.string "{JPN}スズのとうをのぼっていっても\lそれだけではでんせつのポケモンは\l"
	.string "{JPN}こないらしいんだ\p"
	.string "{JPN}なにかもうひとつ\nひつようなものがあるって...\l"
	.string "{JPN}いってたような...\lいってなかったような...\l"
	.string "{JPN}なんだっけなあ...\p"
	.string "{JPN}わすれてしまいました!\p$"
GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "{JPN}しゃちょうやあ{PLAYER}くん！\pわたしはポケモンがだいすきでね\pポケモンへのあいをつたえるため\nこのラジオとうをたてたんだ\pみんながばんぐみをたのしんで\nくれるといいんだがね$"
GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "{JPN}ベンきみはぼくらのおんがく\nきいてくれてるかい？$"
GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "{JPN}5F しゃちょうしつ$"
GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "{JPN}5F スタジオ1$"
