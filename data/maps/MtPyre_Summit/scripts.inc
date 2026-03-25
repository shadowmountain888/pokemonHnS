.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_THERESA, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_TIM, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_TIMOTHY, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_TOBY, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "{JPN}だめだ!あのマグマだんの\n"
	.string "{JPN}やつらに さきをこされた!\p"
	.string "{JPN}おくれをとるわけには\nいかない!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "{JPN}たしか おまえは もどって きた\n"
	.string "{JPN}マグマだんの ひとりだと おもったのに...$"
MtPyre_Summit_Text_Grunt1PostBattle:
	.string "{JPN}そうか おまえは つよいな...\n"
	.string "{JPN}でも おれたちは たくさん いるぞ!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "{JPN}はっはっは!\n"
	.string "{JPN}ざんねんだったな!\p"
	.string "{JPN}もしおまえが はやくきていれば\n"
	.string "{JPN}よわっちいマグマだんと\l"
	.string "{JPN}たたかうだけですんだのに\p"
	.string "{JPN}でもいまきたからには\nつよいおれたちの\lあいてをしてもらうぜ!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "{JPN}うぐぅ... さきに マグマだんと\n"
	.string "{JPN}たたかわせて おけば よかった...$"
MtPyre_Summit_Text_Grunt2PostBattle:
	.string "{JPN}おまえはなにもしらないのに\n"
	.string "{JPN}なんでおれたちの\lじゃまをするんだよ!$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "{JPN}おまえ...\n"
	.string "{JPN}えんとつやまで みかけたな.\p"
	.string "{JPN}どちらの だんにも ぞくして いないのに\n"
	.string "{JPN}なぜ ここに いるんだ?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "{JPN}だれかと やりあうなら\n"
	.string "{JPN}マグマだんと やってくれ...$"
MtPyre_Summit_Text_Grunt3PostBattle:
	.string "{JPN}へっ どうでもいいさ!\n"
	.string "{JPN}じかんかせぎはできたからな!\p"
	.string "{JPN}ボスはもうほしいものを\n"
	.string "{JPN}てにいれたはずだ!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "{JPN}あっ わかったぞ!\n"
	.string "{JPN}おまえ マグマだんに\l"
	.string "{JPN}はいろうとしたけど\p"
	.string "{JPN}ことわられたんだろ!\p"
	.string "{JPN}でも アクアだんにも\nはいれるとおもうなよ!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "{JPN}そんなに アクアだんに はいりたいなら\n"
	.string "{JPN}かんがえて やってもいいぞ...$"
MtPyre_Summit_Text_Grunt4PostBattle:
	.string "{JPN}おれたちメンバーと\n"
	.string "{JPN}リーダーのコンビは\lさいこうなんだぜ!$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "{JPN}アオギリ: マグマだんの マツブサに\n"
	.string "{JPN}さきを こされたが われわれも\l"
	.string "{JPN}\n"
	.string "{JPN}ほしいものを てに いれた.\p"
	.string "{JPN}おくりやまに ほぞんされていた\n"
	.string "{JPN}べにいろのたま...\l"
	.string "{JPN}この アオギリが いただいた!\n"
	.string "{JPN}ふふふ... これで われわれの\nさいしゅうもくてきが たっせい できる!\nよし みんな!\nひきあげるぞ!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "{JPN}ああ... いけない...\n"
	.string "{JPN}こんなことに なって しまうとは...\p"
	.string "{JPN}あいいろのたまだけでなく\n"
	.string "{JPN}べにいろのたまも うばわれて しまった...\p"
	.string "{JPN}あいいろのたまと べにいろのたまは\n"
	.string "{JPN}はなれて はいけない.いっしょにあるべきだ.\p"
	.string "{JPN}あのひとたちは ふたつのたまを\n"
	.string "{JPN}つかって なにを しようと いうのか?\n"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}そうじゃ.さきに あいいろのたまを\n"
	.string "{JPN}とって いったのは マグマだんじゃったか?\p"
	.string "{JPN}いそいでいたせいか これを\n"
	.string "{JPN}おとして いきおった.\p"
	.string "{JPN}なんなのかは よく わからんが\n"
	.string "{JPN}きみに もたせて おこう.\n"
	.string "{JPN}なにかの やくに たつかも しれん.$"
	.string ""

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "{JPN}あの よこしまな おとこたちに\n"
	.string "{JPN}うばわれた あいいろのたまと べにいろのたま...\n"
	.string "{JPN}はなれて はいけない たまじゃ...\n"
	.string "{JPN}おそろしいことが おこるかも しれん...$"
MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "{JPN}おお なんということじゃ...\n"
	.string "{JPN}グラードンと カイオーガの りょうほうが\n"
	.string "{JPN}めざめたと いうのかね?\p"
	.string "{JPN}あいいろのたまと べにいろのたまは\n"
	.string "{JPN}ふたりの ポケモンの いかりを\l"
	.string "{JPN}しずめる ちからが あると いわれておる...\p"
	.string "{JPN}また たまの ほんとうの もちぬしが\n"
	.string "{JPN}まだ いきて いると いわれておる.\p"
	.string "{JPN}しかし それが だれなのか なんなのか\n"
	.string "{JPN}だれも しらない.\n"
	.string "{JPN}にんげんかも しれんし ポケモンかも\n"
	.string "{JPN}しれんが だれも しらないのじゃ.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "{JPN}たまを とって いった ふたりの おとこが\n"
	.string "{JPN}じぶんから かえしに きた.\n"
	.string "{JPN}あのひとたちは...\n"
	.string "{JPN}あんがい わるいひとでは ないのかも しれんな...$"
MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "{JPN}だいち うみ そらの けしん...\n"
	.string "{JPN}それが ちょうこだい ポケモンの\n"
	.string "{JPN}しょうたいだと いわれておる...\n"
	.string "{JPN}われわれ にんげんや ポケモンに\n"
	.string "{JPN}いのちが あるように この せかいにも\l"
	.string "{JPN}iのちが やどって おる...\n"
	.string "{JPN}ちょうこだい ポケモンは そのことを\n"
	.string "{JPN}おしえて くれたのじゃ...$"
	.string ""
MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "{JPN}おくりやまは しんだ ポケモンの\n"
	.string "{JPN}たましいを しずめる ばしょじゃ...\n"
	.string "{JPN}ホウエンちほう ぜんたいを\n"
	.string "{JPN}みわたせる たかい ばしょじゃ...\n"
	.string "{JPN}ポケモンの むねん たましいも\n"
	.string "{JPN}ここで やすらかに なれるじゃろう...\n"
	.string "{JPN}きみが ここに いるのも ぐうぜんかのう...\n"
	.string "{JPN}わしの はなしを きいて くれるかね?\n"
	.string "{JPN}ホウエンちほうに ふるくから つたわる はなしじゃ.$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "{JPN}それは とても とても むかしの\n"
	.string "{JPN}できごとじゃった...\n"
	.string "{JPN}だいちの ポケモンと うみの ポケモンが\n"
	.string "{JPN}はげしく たたかい せかいは\l"
	.string "{JPN}おおあれに なった...\n"
	.string "{JPN}だいちの ポケモンは やまを つくり\n"
	.string "{JPN}たいりくを うみだした...\n"
	.string "{JPN}うみの ポケモンは おおなみを おこし\n"
	.string "{JPN}かいようを きざんだ...\n"
	.string "{JPN}ふたりの はげしい たたかいは\n"
	.string "{JPN}おわる ことを しらなかった.\n"
	.string "{JPN}せかいは だいかじと あらしに\n"
	.string "{JPN}つつまれた.\n"
	.string "{JPN}あいいろのたまと べにいろのたまが\n"
	.string "{JPN}さいがいを おわらせた.\n"
	.string "{JPN}ふたつの たまから ひかりが あふれ\n"
	.string "{JPN}いかりくるう ふたりを しずめた.\n"
	.string "{JPN}おとなしく なった ふたりは ふかい\nうみの そこに もぐり やがて\lすがたを けした...$"
MtPyre_Summit_Text_WellThatTooIsFine:
	.string "{JPN}そうか...\n"
	.string "{JPN}それも よかろう...$"
MtPyre_Summit_Text_MaxieSilence:
	.string "{JPN}マツブサ: {PLAYER}...\n"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...$"
MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "{JPN}ホウエンちほうの でんせつを\n"
	.string "{JPN}みらいに つたえるのが わしの やくめじゃ.\n"
	.string "{JPN}そして いま ルネシティで おわった\n"
	.string "{JPN}きききが あたらしい でんせつを つくった...\n"
	.string "{JPN}あたらしい ホウエンちほうの でんせつを\n"
	.string "{JPN}きく じかんは あるかね?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "{JPN}それは とても とても むかしの\n"
	.string "{JPN}できごとじゃった...\n"
	.string "{JPN}だいちの ポケモンと うみの ポケモンが\n"
	.string "{JPN}はげしく たたかい せかいは\l"
	.string "{JPN}おおあれに なった...\n"
	.string "{JPN}だいちの ポケモンは やまを つくり\n"
	.string "{JPN}たいりくを うみだした...\n"
	.string "{JPN}うみの ポケモンは おおなみを おこし\n"
	.string "{JPN}かいようを きざんだ...\n"
	.string "{JPN}ふたりの はげしい たたかいは\n"
	.string "{JPN}おわる ことを しらなかった.\n"
	.string "{JPN}せかいは だいかじと あらしに\n"
	.string "{JPN}つつまれた.\n"
	.string "{JPN}そのとき あらしの なかから\n"
	.string "{JPN}そらの ポケモンが まいおりた.\n"
	.string "{JPN}あざやかな みどりいろに かがやく\n"
	.string "{JPN}そのポケモンは いかりくるう ふたりを\lしずめた.\nそして やくめを はたした みどりの\nポケモンは おおぞらの かなたへと\lとんで いった...$"
