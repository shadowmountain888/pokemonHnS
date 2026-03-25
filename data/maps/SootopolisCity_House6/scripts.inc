SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "{JPN}こんにちは! ひさしぶりの\n"
	.string "{JPN}おきゃくさんですね.\p"
	.string "{JPN}あなたがきてくれて うれしいので\n"
	.string "{JPN}おおきな ホエルコにんぎょうを\nさしあげます!$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "{JPN}たいせつにしてくださいね!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "{JPN}あら ほしいけど いますぐは\n"
	.string "{JPN}いらないのですね?\nわかりました.とっておきますね.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "{JPN}ほんとうに だいじょうぶですか?\n"
	.string "{JPN}このにんぎょうは いりませんか?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "{JPN}わたし ぬいぐるみにんぎょうが\nだいすきなんです!$"

