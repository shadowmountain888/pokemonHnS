FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteCheck
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteCheck::
	goto_if_set FLAG_FINITE_TMS, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteTM27
	goto_if_unset FLAG_FINITE_TMS, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteTM27::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "{JPN}コズモはかせ: ああ...\n"
	.string "{JPN}マグマだんに いんせきの\l"
	.string "{JPN}ありかを おしえてしまうなんて\l"
	.string "{JPN}なんて ばかなことを...\p"
	.string "{JPN}メテオのたきの いんせき...\n"
	.string "{JPN}もう わたしの ものには\lならないでしょうね...$"
FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "{JPN}おお!\n"
	.string "{JPN}えっ?\p"
	.string "{JPN}そのアイテムは...\p"
	.string "{JPN}まさか?\p"
	.string "{JPN}マグマだんが メテオのたきから\n"
	.string "{JPN}うばっていった いんせき\l"
	.string "{JPN}なのでは?\p"
	.string "{JPN}どうか わたしに\n"
	.string "{JPN}ゆずってもらえませんか?\pただで とは いいません.\nこの きんのたまと\lこうかんしませんか?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "{JPN}コズモはかせ: このアイテムは\n"
	.string "{JPN}わたしのかんしゃのきもちです.\l"
	.string "{JPN}どうぞつかってください!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "{JPN}コズモはかせ: ああ しんじられない.\n"
	.string "{JPN}ほんとうに ほんとうにすばらしい!\p"
	.string "{JPN}これはわたしのけんきゅうに\nとてもやくにたちます!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "{JPN}コズモはかせ: そんな...\n"
	.string "{JPN}がっかりです...$"
FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "{JPN}コズモはかせ: おねがいします その\n"
	.string "{JPN}いんせきをゆずってもらえませんか?\p"
	.string "{JPN}ただでとはいいません.\n"
	.string "{JPN}このわざマシンとこうかんでは\lどうでしょうか?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "{JPN}コズモはかせは マグマだんの\n"
	.string "{JPN}にんげんたちといっしょに\l"
	.string "{JPN}114ばんどうろの りゅうせいのたきに\lでかけていきました.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "{JPN}かわいそうな コズモはかせ...\n"
	.string "{JPN}とても おちこんでる...\lきのどくに おもうわ.$"
FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "{JPN}コズモはかせを みて...\n"
	.string "{JPN}とても よろこんでる!\lかわいいわね.$"

