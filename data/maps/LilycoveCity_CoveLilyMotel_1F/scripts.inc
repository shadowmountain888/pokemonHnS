.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "{JPN}ふーん ポケモンを\n"
	.string "{JPN}みりょくにして\l"
	.string "{JPN}きゃくすうが にばいに\n"
	.string "{JPN}なったのか?\p"
	.string "{JPN}そうだなあ うちの やどにも\n"
	.string "{JPN}かわいい ポケモンを\lマエニシダにして みようかな.\pそうすれば もっと おおくの\nおきゃくさんが きて\lくれるかも しれないなあ?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "{JPN}あ すまない すまない!\n"
	.string "{JPN}テレビに みいって いたよ!\p"
	.string "{JPN}アクアだんが まちに きてから\n"
	.string "{JPN}かんこうきゃくが\lちかよらなくなって しまってね.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "{JPN}おい まえに いるやつ!\n"
	.string "{JPN}テレビが みえないぞ!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "{JPN}すごいな! ポケモンが\n"
	.string "{JPN}だれかの おとしものを\n"
	.string "{JPN}みつけたって いうのかい?\p"
	.string "{JPN}そいつは すごい.\n"
	.string "{JPN}もし うちにも そんな\n"
	.string "{JPN}かしこい ポケモンが いたら...\pおきゃくさんの\nわすれものでも\nなんでも みつけられるのに...$"
LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "{JPN}おっと ごめんごめん!\n"
	.string "{JPN}テレビに みいって しまって!\p"
	.string "{JPN}アクアだんの アジトが\n"
	.string "{JPN}つぶされたって きいたよ.\p"
	.string "{JPN}そのおかげで だいにんずうの\n"
	.string "{JPN}よやくが はいったんだ.\p"
	.string "{JPN}たしか... ゲームなんとかって\n"
	.string "{JPN}かいしゃだったかな...$"
LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "{JPN}すごいな! るすばんをしてた\n"
	.string "{JPN}ポケモンが どろぼうを\n"
	.string "{JPN}つかまえたって?\p"
	.string "{JPN}そいつは すごい.\n"
	.string "{JPN}もし うちにも つよい ポケモンが\n"
	.string "{JPN}けいびいんとして いたら...\pおきゃくさんに もっと\nあんぜんな サービスを\nていきょうできるのに.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "{JPN}あ すまない すまない!\n"
	.string "{JPN}テレビに みいって いたよ.\p"
	.string "{JPN}そうそう.さっき おおきな\n"
	.string "{JPN}グループの おきゃくさんが\l"
	.string "{JPN}とうちゃく したんだ.\p"
	.string "{JPN}ゲームフリークという なまえで\n"
	.string "{JPN}よやくして いるから\l"
	.string "{JPN}ゲームを つくっている ひとたち\nなんだろうね.\pおっと かれらの ばんごはんの\nじゅんびを しなくちゃ!$"

