.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "{JPN}わたしは デボンコーポレーション\n"
	.string "{JPN}しゃちょうの ツワブキです.\p"
	.string "{JPN}きみのこと きいてますよ!\p"
	.string "{JPN}わが しゃいんを いちどだけでなく\n"
	.string "{JPN}にどまで たすけて くれたそうで!\p"
	.string "{JPN}きみのような すばらしいひとに\n"
	.string "{JPN}おねがいが あるんです.\p"
	.string "{JPN}カイナシティの ぞうせんじょに\n"
	.string "{JPN}にもつを とどけるそうですね.\p"
	.string "{JPN}その とちゅうで ムロタウンに\n"
	.string "{JPN}よって いただけませんか?\p"
	.string "{JPN}ムロタウンの ダイゴに てがみを\n"
	.string "{JPN}とどけて ほしいんです.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "{JPN}ツワブキ: さて わたしは\n"
	.string "{JPN}りっぱな しゃちょうです.\p"
	.string "{JPN}ですから ただで おねがいするような\n"
	.string "{JPN}けちなこと は しません.\p"
	.string "{JPN}そこで これを うけとって\nください!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{JPN}{PLAYER}は ポケナビを\nてに いれた!$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "{JPN}ストーン: その きかいは...\p"
	.string "{JPN}ポケモン ナビゲーター \n"
	.string "{JPN}りゃくして ポケナビだ.\p"
	.string "{JPN}ぼうけんに でる トレーナーには\n"
	.string "{JPN}なくては ならない どうぐだよ.\p"
	.string "{JPN}ホウエン ちほうの ちずが\n"
	.string "{JPN}のっているんだ.\p"
	.string "{JPN}ムロタウンや ハジツゲタウンの\n"
	.string "{JPN}ばしょを かんたんに しらべられる!\p"
	.string "{JPN}ところで マグマだんと アクアだんと\n"
	.string "{JPN}いう あやしい はんざいしゃたちが\l"
	.string "{JPN}あちこちで もんだいを おこして\l"
	.string "{JPN}いるという はなしを きいたぞ.\pたびだつ まえに ゆっくり やすんで\nいったほうが いいと おもうよ.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "{JPN}ツワブキ: では {PLAYER}{KUN}\n"
	.string "{JPN}きを つけて いって らっしゃい!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "{JPN}ツワブキ: たよみましたよ!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "{JPN}ストーン: わたしの てがみを\n"
	.string "{JPN}とどけて くれたのですね?\n"
	.string "{JPN}ありがとう ございます!\p"
	.string "{JPN}これは おれいの しるしです.\nトレーナーの あなたの\nやくに たつでしょう.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "{JPN}ツワブキ: がくしゅうそうちを オンにすると\n"
	.string "{JPN}てもちの すべての ポケモンが\l"
	.string "{JPN}せんとうで けいけんちを はんぶんもらえます.\p"
	.string "{JPN}よわい ポケモンを そだてるのに\n"
	.string "{JPN}がくしゅうそうちは べんりですよ.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "{JPN}ツワブキ: わかいころから しごとづけで\n"
	.string "{JPN}くらして きました.\p"
	.string "{JPN}そのため りゅうこうや そういうことに\n"
	.string "{JPN}くわしくないのです.\p"
	.string "{JPN}いまの わかいひとは みんな\n"
	.string "{JPN}ポケモンリーグの トレーナーに\lなりたいのでしょうか?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "{JPN}ここは デボンコーポレーションの\n"
	.string "{JPN}3かいです.\p"
	.string "{JPN}しゃちょうしつも この かいに\n"
	.string "{JPN}あります.\p"
	.string "{JPN}それにしても きみが やってくれた\n"
	.string "{JPN}ことには かんしゃしきれません.\p"
	.string "{JPN}あの... ところで きみが\n"
	.string "{JPN}とりもどしてくれた にもつなんですが...\p"
	.string "{JPN}ハジツゲタウンの ぞうせんじょまで\n"
	.string "{JPN}とどけて もらえませんか?\p"
	.string "{JPN}また どろぼうに ねらわれたら\n"
	.string "{JPN}たいへんですから.\p"
	.string "{JPN}えーっと... えへへ それで \n"
	.string "{JPN}おねがい できますでしょうか?\p"
	.string "{JPN}そうそう.\n"
	.string "{JPN}ちょっと ここで まっていて ください.$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "{JPN}しゃちょうが おはなしが あるそうです.\p"
	.string "{JPN}ついて きて ください.$"
	.string ""

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "{JPN}どうぞ おさきに.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "{JPN}カイナシティの ぞうせんじょに いったら\n"
	.string "{JPN}クスノキ せんちょうに あって みてください.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "{JPN}デボンの あたらしい せいひん\n"
	.string "{JPN}リピートボールと タイマーボールが\l"
	.string "{JPN}トレーナーたちに だいにんきです.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "{JPN}しゃちょうが あつめた\n"
	.string "{JPN}めずらしい いしや がんせきの\lコレクションです.$"

