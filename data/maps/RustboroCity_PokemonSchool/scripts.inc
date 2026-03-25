RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "{JPN}こくばんには バトルで\n"
	.string "{JPN}ポケモンに えいきょうする\lじょうたいへんかが かいて ある$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "{JPN}どの トピックを よみますか?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "{JPN}ポケモンが どくを うけると\n"
	.string "{JPN}HPが じょじょに へっていく\p"
	.string "{JPN}どくの こうかは バトルが\n"
	.string "{JPN}おわっても つづく\p"
	.string "{JPN}どくじょうたいの ポケモンは\n"
	.string "{JPN}いどうちゅうも HPが へる\p"
	.string "{JPN}どくけしで どくを ちりょう\nしよう$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "{JPN}ポケモンが まひすると\n"
	.string "{JPN}すばやさが おちる\p"
	.string "{JPN}バトルちゅうに うごけなく\n"
	.string "{JPN}なることも ある\p"
	.string "{JPN}まひは バトルご も つづく\n"
	.string "{JPN}まひなおしで ちりょうしよう$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "{JPN}ポケモンが ねむってしまうと\n"
	.string "{JPN}こうげきが できない\p"
	.string "{JPN}じぶんで めざめることも あるが\n"
	.string "{JPN}バトルが おわっても\l"
	.string "{JPN}ねむったまま\p"
	.string "{JPN}めざましで おこしてあげよう$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "{JPN}やけどは こうげきりょくを\n"
	.string "{JPN}さげ HPも じょじょに へらす\p"
	.string "{JPN}やけどは バトルご も つづく\n"
	.string "{JPN}やけどなおしで ちりょうしよう$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "{JPN}ポケモンが こおってしまうと\n"
	.string "{JPN}まったく うごけなく なる\p"
	.string "{JPN}こおりは バトルご も つづく\n"
	.string "{JPN}こおりなおしで とかそう$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "{JPN}べんきょうしない せいとには\n"
	.string "{JPN}わたしの せんせいのツメを\l"
	.string "{JPN}あじあわせてあげる\p"
	.string "{JPN}きみが よい せいとか どうかは\n"
	.string "{JPN}この どうぐの つかいかたで\lわかるだろう$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "{JPN}せんせいのツメを もたせた\n"
	.string "{JPN}ポケモンは ときどき すばやく\l"
	.string "{JPN}うごいて あいてより さきに\l"
	.string "{JPN}こうげき できる\p"
	.string "{JPN}ポケモンに もたせる どうぐは\n"
	.string "{JPN}たくさん ある\p"
	.string "{JPN}それだけでも べんきょうする\nことが たくさん あるぞ!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "{JPN}いま ともだちと ポケモンの\n"
	.string "{JPN}こうかんを している ところ$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "{JPN}ずっと タネボーが ほしくて\n"
	.string "{JPN}やっと てに いれられる!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "{JPN}ポケモンは どうぐを もてるけど\n"
	.string "{JPN}きずぐすりや どくけしなど\l"
	.string "{JPN}にんげんが つくった ものは\lつかえない$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "{JPN}ポケモンの わざには あいてを\n"
	.string "{JPN}こんらんさせる ものが ある\p"
	.string "{JPN}こんらんした ポケモンは\n"
	.string "{JPN}じぶんで じぶんを こうげき\l"
	.string "{JPN}してしまうことが ある\p"
	.string "{JPN}でも バトルが おわると\nもとに もどる$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "{JPN}きのみを もっている ポケモンは\n"
	.string "{JPN}じぶんで かいふくする...\p"
	.string "{JPN}ポケモンが もてる どうぐは\n"
	.string "{JPN}いろんな しゅるいが ある...\p"
	.string "{JPN}ノートを とるのって\n"
	.string "{JPN}けっこう たいへんだなあ...$"
RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "{JPN}この せいとの ノートだ...\p"
	.string "{JPN}ポケモンは モンスターボールで\n"
	.string "{JPN}つかまえる.\p"
	.string "{JPN}トレーナーは ポケモンを\n"
	.string "{JPN}6ひきまで つれて あるける.\p"
	.string "{JPN}トレーナーとは ポケモンを\n"
	.string "{JPN}つかまえて そだてて\l"
	.string "{JPN}たたかわせる ひとの こと.\p"
	.string "{JPN}トレーナーの しめいは\n"
	.string "{JPN}ポケモンジムで まっている\l"
	.string "{JPN}つよい トレーナーを たおすこと.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "{JPN}あれ? まえに あったことが\n"
	.string "{JPN}ない? カナズミシティで\p"
	.string "{JPN}じこしょうかい しよう\n"
	.string "{JPN}わたしは エニシダ\p"
	.string "{JPN}すばらしい トレーナーを\n"
	.string "{JPN}さがして たびを している\p"
	.string "{JPN}くわしくいうと ポケモンバトルの\n"
	.string "{JPN}エキスパートを さがしている\p"
	.string "{JPN}きみは なぜ この スクールに?\n"
	.string "{JPN}きみも トレーナー?\p"
	.string "{JPN}まず ポケモンに いあいぎりを\n"
	.string "{JPN}おぼえさせることだ\p"
	.string "{JPN}たしか この まちの だれかが\n"
	.string "{JPN}いあいぎりを もっていた$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "{JPN}エニシダ: うーん...\p"
	.string "{JPN}ここの せいとたちの のうりょくは\n"
	.string "{JPN}みちすう だな. かのうせいは ある.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "{JPN}エニシダ: おお それは?\p"
	.string "{JPN}ストーンバッジじゃないか\n"
	.string "{JPN}なかなか すごいじゃないか\p"
	.string "{JPN}しかし きみの バトルを\n"
	.string "{JPN}みたかった\p"
	.string "{JPN}リーグバッジだけでは\n"
	.string "{JPN}トレーナーとしての うでまえは\lわからない$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "{JPN}あれ? まえに あったことが\n"
	.string "{JPN}ない? カナズミシティで\p"
	.string "{JPN}じこしょうかい しよう\n"
	.string "{JPN}わたしは エニシダ\p"
	.string "{JPN}すばらしい トレーナーを\n"
	.string "{JPN}さがして たびを している\p"
	.string "{JPN}くわしくいうと ポケモンバトルの\n"
	.string "{JPN}エキスパートを さがしている\p"
	.string "{JPN}おお それは?\n"
	.string "{JPN}ストーンバッジじゃないか\p"
	.string "{JPN}しんまいトレーナーにしては\n"
	.string "{JPN}なかなか すごいじゃないか\p"
	.string "{JPN}しかし きみの バトルを\n"
	.string "{JPN}みたかった\p"
	.string "{JPN}リーグバッジだけでは\n"
	.string "{JPN}トレーナーとしての うでまえは\lわからない$"

