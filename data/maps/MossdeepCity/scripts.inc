.set LOCALID_WOMAN, 8
.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16
.set LOCALID_JIRACHI, 18

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MossdeepCity_OnTransition:
	callnative SetTimeBasedEncounters
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_Evo::
	msgbox MossdeepCity_EventScript_Evo_Text, MSGBOX_NPC
	end

MossdeepCity_EventScript_Evo_Text:
	.string "{JPN}ポケモンの イーブイは\n"
	.string "{JPN}いろんな ほうほうで\l"
	.string "{JPN}しんかするんだ.\p"
	.string "{JPN}かみなりのいし ほのおのいし \n"
	.string "{JPN}みずのいし... たとえば\l"
	.string "{JPN}エレブーや ブーバーの ように.\pそれらも いしで\nしんかするんだよ.$"

MossdeepCity_EventScript_Evo2::
	msgbox MossdeepCity_EventScript_Evo2_Text, MSGBOX_NPC
	end

MossdeepCity_EventScript_Evo2_Text:
	.string "{JPN}つまは ポケモンの イーブイが\n"
	.string "{JPN}だいすきなんだ.\p"
	.string "{JPN}イーブイの しんかほうほうを\n"
	.string "{JPN}ぜんぶ しっている.\l"
	.string "{JPN}みずのいしや リーフのいしを\n"
	.string "{JPN}もたせる ほうほうとか.\p"
	.string "{JPN}そう もたせるんだ!\n"
	.string "{JPN}つかうんじゃない!\n"
	.string "{JPN}きみは しっていたかい?\n"
	.string "{JPN}ぼくは しらなかった.\p"
	.string "{JPN}ひるまや よるに\n"
	.string "{JPN}なかよしに する ほうほうや.\p"
	.string "{JPN}フェアリータイプの わざを\nつかって かわいく する ほうほう!\p...\pイーブイは どこに いるか\nしってる?\nつまの ために つかまえようか.\pよろこぶと おもうんだ!$"

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	goto_if_set FLAG_JIRACHI, MossdeepCity_EventScript_Woman2
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman2::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock2, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	closemessage
	goto_if_set FLAG_JIRACHI, MossdeepCity_EventScript_WhiteRockEnd
	goto_if_unset FLAG_EXTRA_LEGENDARIES, MossdeepCity_EventScript_WhiteRockEnd
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_EventScript_Jirachi
	end

MossdeepCity_EventScript_WhiteRockEnd::
	end

MossdeepCity_EventScript_Jirachi::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_EventScript_JirachiMoves
	applymovement LOCALID_WOMAN, MossdeepCity_EventScript_JirachiMoves2
	waitmovement 0
	msgbox MossdeepCity_Text_ItsAWhiteRock2, MSGBOX_DEFAULT
	waitmessage
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	applymovement LOCALID_JIRACHI, MossdeepCity_EventScript_JirachiMoves3
	waitmovement 0
	msgbox MossdeepCity_Text_ItsAWhiteRock3, MSGBOX_DEFAULT
	closemessage
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MossdeepCity_EventScript_JirachiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MossdeepCity_EventScript_JirachiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MossdeepCity_EventScript_JirachiRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MossdeepCity_EventScript_JirachiRan
	release
	end

MossdeepCity_EventScript_JirachiWon::
	setflag FLAG_JIRACHI
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	callnative UpdateFollowingPokemon
	goto Common_EventScript_RemoveStaticPokemon
	releaseall
	end

MossdeepCity_EventScript_JirachiRan::
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	applymovement LOCALID_JIRACHI, MossdeepCity_EventScript_JirachiMoves4
	waitmovement 0
	releaseall
	end

MossdeepCity_EventScript_JirachiMoves:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_up
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_EventScript_JirachiMoves2:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_EventScript_JirachiMoves3:
	delay_16
	delay_16
	delay_16
	set_visible
	walk_down
	step_end

MossdeepCity_EventScript_JirachiMoves4:
	set_invisible
	walk_up
	step_end

MossdeepCity_Text_ItsAWhiteRock2:
	.string "{JPN}なにかが...\p"
	.string "{JPN}なにかが うごいている...\n"
	.string "{JPN}...$"
	.string ""
MossdeepCity_Text_ItsAWhiteRock3:
	.string "{JPN}しろいいわのうしろから\n"
	.string "{JPN}なにかがとびかかってきた!$"

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_CELADON_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_GARBAGEVAR, 2
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "{JPN}これはダイゴから\n"
	.string "{JPN}もらったんだけど \n"
	.string "{JPN}なににつかうのかわからないよ.\p"
	.string "{JPN}おうのいわっていうものらしい.\nきみ ほしい?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "{JPN}どうしてそんなものほしがるの?\n"
	.string "{JPN}へんなやつだね.\p"
	.string "{JPN}もらってもいいけど \n"
	.string "{JPN}ダイゴにはないしょだよ.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "{JPN}ダイゴのいえは\nすぐそこにあるよ!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "{JPN}そうそう きみもそうおもうでしょ!\n"
	.string "{JPN}へんないわなんて\nどうすればいいのかな?$"

MossdeepCity_Text_WailmerWatching:
	.string "{JPN}トクサネの まわりでは\n"
	.string "{JPN}やせいの ホエルコが\l"
	.string "{JPN}みられるんだ.\p"
	.string "{JPN}それは えーっと...\n"
	.string "{JPN}なんていうんだっけ...\p"
	.string "{JPN}ホエ ホエ ホエ...\pホエルコ ウォッチング!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "{JPN}このしまのうちゅうセンターでは\n"
	.string "{JPN}おおきなロケットを\n"
	.string "{JPN}うちあげているんだ.\p"
	.string "{JPN}さいきんとどいたてがみで\nなにかおおさわぎになってるよ.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "{JPN}このしまのうちゅうセンターでは\n"
	.string "{JPN}おおきなロケットを\nうちあげているんだ.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "{JPN}かいぞくのともだちからきいたんだけど\n"
	.string "{JPN}アクアだんがミナモシティに\n"
	.string "{JPN}きちをかまえたらしいね.\p"
	.string "{JPN}でも だれかがやってきて\n"
	.string "{JPN}かれらをやっつけたらしいよ!\p"
	.string "{JPN}でもここトクサネは\n"
	.string "{JPN}マグマだんにねらわれてるんだ.\p"
	.string "{JPN}かれらがなにをたくらんでるか\nしりたかったら\nuちゅうセンターにいってみな.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "{JPN}おれはかいぞくだから\n"
	.string "{JPN}うみのほうがたいせつなのは\n"
	.string "{JPN}もちろんなんだけど.\p"
	.string "{JPN}でもな ながいこうかいのあとで\nりくちにもどってくると\nほっとするんだよな!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "{JPN}すてきだとおもわない?\p"
	.string "{JPN}せかいじゅうが このしまみたいに\n"
	.string "{JPN}しょくぶつやはなで\nおおわれてたら?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "{JPN}すべてのいのちは りくちに\n"
	.string "{JPN}すんでいても いきるためには\n"
	.string "{JPN}umiがひつようなんだ.\p"
	.string "{JPN}いのちは やくわりをおえると\n"
	.string "{JPN}つちとなって りくちにかえる.\p"
	.string "{JPN}そしてうみは いつでも\n"
	.string "{JPN}りくちとつながっているんだ.\pそう まさにここのかいがんみたいに.$"

MossdeepCity_Text_SurfExhilarating:
	.string "{JPN}ふねでの たびも いいけど.\p"
	.string "{JPN}ポケモンと いっしょに\n"
	.string "{JPN}なみのりで うみを わたる...\p"
	.string "{JPN}それこそが スリルまんてんの\n"
	.string "{JPN}たびだ!\nそう おもわないかい \nわかもの?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "{JPN}このいわは うちゅうセンターの\n"
	.string "{JPN}ひとたちにとって\n"
	.string "{JPN}tokubetsuないみがあるんだ.\p"
	.string "{JPN}ロケットがあんぜんに\n"
	.string "{JPN}とべますようにって\n"
	.string "{JPN}ねがいをこめておいたんだよ.\n"
	.string "{JPN}きみはねがいをかけるとき\n"
	.string "{JPN}なにをつかう?\nほしにねがいをかける?\pぼくはねがいごとのふだを\nつかうんだ.\nそれがぼくのやりかただよ.$"

MossdeepCity_Text_SpecialSpaceCenterRock2:
	.string "{JPN}なんだって? \nそれはぼくのねがいじゃない!$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "{JPN}しろい いわだ.\p"
	.string "{JPN}ふしぎな エネルギーが\nでている...$"
MossdeepCity_Text_GymSign:
	.string "{JPN}トクサネシティ ポケモンジム\n"
	.string "{JPN}ジムリーダー: フウとラン\p"
	.string "{JPN}ふしぎなコンビネーション!$"

MossdeepCity_Text_CitySign:
	.string "{JPN}トクサネシティ\n"
	.string "{JPN}スローガン: ポケモンをたいせつに!$"

MossdeepCity_Text_SpaceCenterSign:
	.string "{JPN}トクサネうちゅうセンター\n"
	.string "{JPN}うちゅうにもっともちかいばしょ$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "{JPN}エニシダ: {PLAYER}くん げんき?\n"
	.string "{JPN}おれは だいちょうしだ!\p"
	.string "{JPN}トクサネの ジムリーダーは\n"
	.string "{JPN}つよいって きいたから\l"
	.string "{JPN}ようすを みに きたんだ.\p"
	.string "{JPN}でも このまちは\n"
	.string "{JPN}なんか へんだ.\p"
	.string "{JPN}けいこくじょうや\n"
	.string "{JPN}うちゅうセンターの\l"
	.string "{JPN}はなしが でてるし...\p"
	.string "{JPN}でも おれには\nかんけいない ことだろうな.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "{JPN}あー... なみが あしに\n"
	.string "{JPN}かかって きもちいいなあ...\p"
	.string "{JPN}なみといえば みずの しまの\n"
	.string "{JPN}まち ルネシティの ことだけど.\p"
	.string "{JPN}あそこの ジムに あたらしい\n"
	.string "{JPN}リーダーが きたらしい.\p"
	.string "{JPN}あたらしい リーダーは\n"
	.string "{JPN}むかし ミクリに\lしどうを うけていたらしいよ.$"
