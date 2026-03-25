BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "{JPN}これは サンプル メッセージです.$"

gText_BattlePyramidConfirmRest::
	.string "{JPN}バトルピラミッドの ちょうせんを\n"
	.string "{JPN}セーブして いったん やめますか?$"
	.string ""

gText_BattlePyramidConfirmRetire::
	.string "{JPN}ピラミッドの ちょうせんを\n"
	.string "{JPN}やめますか?$"

BattlePyramid_Text_ExitHintUp1::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}その ほうこうです: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}その ほうこうです: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}その ほうこうです: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}その ほうこうです: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}{UP_ARROW} の ほうこうです.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}{LEFT_ARROW} の ほうこうです.$"

BattlePyramid_Text_ExitHintRight2::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}{RIGHT_ARROW} の ほうこうです.$"

BattlePyramid_Text_ExitHintDown2::
	.string "{JPN}このフロアの でぐちは\n"
	.string "{JPN}{DOWN_ARROW} の ほうこうです.$"

BattlePyramid_Text_ExitHintUp3::
	.string "{JPN}でぐちは あの\n"
	.string "{JPN}{UP_ARROW} の ほうです.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "{JPN}でぐちは あの\n"
	.string "{JPN}{LEFT_ARROW} の ほうです.$"

BattlePyramid_Text_ExitHintRight3::
	.string "{JPN}でぐちは あの\n"
	.string "{JPN}{RIGHT_ARROW} の ほうです.$"

BattlePyramid_Text_ExitHintDown3::
	.string "{JPN}でぐちは あの\n"
	.string "{JPN}{DOWN_ARROW} の ほうです.$"

BattlePyramid_Text_ExitHintUp4::
	.string "{JPN}このフロアでは でぐちは\n"
	.string "{JPN}{UP_ARROW} の ほうこうに あります.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "{JPN}このフロアでは でぐちは\n"
	.string "{JPN}{LEFT_ARROW} の ほうこうに あります.$"

BattlePyramid_Text_ExitHintRight4::
	.string "{JPN}このフロアでは でぐちは\n"
	.string "{JPN}{RIGHT_ARROW} の ほうこうに あります.$"

BattlePyramid_Text_ExitHintDown4::
	.string "{JPN}このフロアでは でぐちは\n"
	.string "{JPN}{DOWN_ARROW} の ほうこうに あります.$"

BattlePyramid_Text_ExitHintUp5::
	.string "{JPN}でぐち?\n"
	.string "{JPN}あの {UP_ARROW} の ほうだよ.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "{JPN}でぐち?\n"
	.string "{JPN}あの {LEFT_ARROW} の ほうだよ.$"

BattlePyramid_Text_ExitHintRight5::
	.string "{JPN}でぐち?\n"
	.string "{JPN}あの {RIGHT_ARROW} の ほうだよ.$"

BattlePyramid_Text_ExitHintDown5::
	.string "{JPN}でぐち?\n"
	.string "{JPN}あの {DOWN_ARROW} の ほうだよ.$"

BattlePyramid_Text_ExitHintUp6::
	.string "{JPN}でぐちは たまたま\n"
	.string "{JPN}{UP_ARROW} の ほうこうに あります.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "{JPN}でぐちは たまたま\n"
	.string "{JPN}{LEFT_ARROW} の ほうこうに あります.$"

BattlePyramid_Text_ExitHintRight6::
	.string "{JPN}しゅつぐちは\n"
	.string "{JPN}{RIGHT_ARROW}のほうこうにあるよ$"

BattlePyramid_Text_ExitHintDown6::
	.string "{JPN}しゅつぐちは\n"
	.string "{JPN}{DOWN_ARROW}のほうこうにあるよ$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ8このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ7このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ6このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ5このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ4このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ3このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ2このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_OneItemRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}まだ1このどうぐが\n"
	.string "{JPN}のこっているよ$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "{JPN}どうぐをさがしているの?\p"
	.string "{JPN}もうなにも\n"
	.string "{JPN}のこっていないよ!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}ここには8このどうぐが\nおちているよ$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}まだ7このどうぐが\nおちているよ$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}まだ6このどうぐが\nおちているよ$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}まだ5このどうぐが\nおちているよ$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}まだ4このどうぐが\nおちているよ$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}まだ3このどうぐが\nおちているよ$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}まだ2このどうぐが\nおちているよ$"

BattlePyramid_Text_OneItemRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}まだ1このどうぐが\nおちているよ$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "{JPN}きみがかったから\n"
	.string "{JPN}ちょっとしたひみつを\n"
	.string "{JPN}おしえてあげる!\p"
	.string "{JPN}もうなにも\nのこっていないよ$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "{JPN}どうぐのざいこは\n"
	.string "{JPN}daijoubu?\p"
	.string "{JPN}このかいには\nまだ8このどうぐが\nあるとおもうよ$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "{JPN}どうぐのざいこは\n"
	.string "{JPN}daijoubu?\p"
	.string "{JPN}このかいには\nまだ7このどうぐが\nあるとおもうよ$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "{JPN}どうぐのざいこは\n"
	.string "{JPN}daijoubu?\p"
	.string "{JPN}このかいには\nまだ6このどうぐが\nあるとおもうよ$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "{JPN}どうぐのざいこは\n"
	.string "{JPN}daijoubu?\p"
	.string "{JPN}このかいには\nまだ5このどうぐが\nあるとおもうよ$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "{JPN}どうぐのざいこは\n"
	.string "{JPN}daijoubu?\p"
	.string "{JPN}このかいには\nまだ4このどうぐが\nあるとおもうよ$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "{JPN}どうぐの ざいこは だいじょうぶかい?\p"
	.string "{JPN}このかいには まだ みっつ どうぐが\n"
	.string "{JPN}のこっているようだね$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "{JPN}どうぐの ざいこは だいじょうぶかい?\p"
	.string "{JPN}このかいには まだ ふたつ どうぐが\n"
	.string "{JPN}のこっているようだね$"

BattlePyramid_Text_OneItemRemaining3::
	.string "{JPN}どうぐの ざいこは だいじょうぶかい?\p"
	.string "{JPN}このかいには まだ ひとつだけ\n"
	.string "{JPN}どうぐが のこっているようだね$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "{JPN}どうぐの ざいこは だいじょうぶかい?\p"
	.string "{JPN}このかいには もう どうぐは\n"
	.string "{JPN}のこっていないようだ\l"
	.string "{JPN}きをつけて がんばるんじゃよ!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ やっつ どうぐが\n"
	.string "{JPN}おちているようだ$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ ななつ どうぐが\n"
	.string "{JPN}おちているようだ$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ むっつ どうぐが\n"
	.string "{JPN}おちているようだ$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ いつつ どうぐが\n"
	.string "{JPN}おちているようだ$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ よっつ どうぐが\n"
	.string "{JPN}おちているようだ$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ みっつ どうぐが\n"
	.string "{JPN}おちているようだ$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ ふたつ どうぐが\n"
	.string "{JPN}おちているようだ$"

BattlePyramid_Text_OneItemRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんに まだ ひとつだけ\n"
	.string "{JPN}どうぐが おちているようだ$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "{JPN}きみは つよいから\n"
	.string "{JPN}ひんとを あげよう!\p"
	.string "{JPN}じめんには もう どうぐは\n"
	.string "{JPN}おちていないようだ$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}8このアイテムがあるらしい...$"
BattlePyramid_Text_SevenItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}7このアイテムがあるらしい...$"
BattlePyramid_Text_SixItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}6このアイテムがあるらしい...$"
BattlePyramid_Text_FiveItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}5このアイテムがあるらしい...$"
BattlePyramid_Text_FourItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}4このアイテムがあるらしい...$"
BattlePyramid_Text_ThreeItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}3このアイテムがあるらしい...$"
BattlePyramid_Text_TwoItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}2このアイテムがあるらしい...$"
BattlePyramid_Text_OneItemRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}1このアイテムがあるらしい...$"
BattlePyramid_Text_ZeroItemsRemaining5::
	.string "{JPN}このピラミッドのフロアには\n"
	.string "{JPN}アイテムがないらしい...$"
BattlePyramid_Text_EightItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ やっつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ ななつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ むっつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ いつつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ よっつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ みっつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ ふたつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_OneItemRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには まだ ひとつ どうぐが\n"
	.string "{JPN}あると おもうよ$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "{JPN}どうぐは あつめたかい?\p"
	.string "{JPN}このかいには もう どうぐは\n"
	.string "{JPN}ないと おもうよ$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "{JPN}きみは ほんとうに すごかった!\p"
	.string "{JPN}でも わたしいがいに まだ ななにん\n"
	.string "{JPN}つよいトレーナーが いるよ!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "{JPN}きみは ほんとうに すごかった!\p"
	.string "{JPN}でも わたしいがいに まだ ろくにん\n"
	.string "{JPN}つよいトレーナーが いるよ!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "{JPN}きみは ほんとうに すごかった!\p"
	.string "{JPN}でも わたしいがいに まだ ごにん\n"
	.string "{JPN}つよいトレーナーが いるよ!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "{JPN}きみって ほんとうに すごいね!\p"
	.string "{JPN}でも わたし いがいに まだ\n"
	.string "{JPN}よんにんの つよい トレーナーが いるよ!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "{JPN}きみって ほんとうに すごいね!\p"
	.string "{JPN}でも わたし いがいに まだ\n"
	.string "{JPN}さんにんの つよい トレーナーが いるよ!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "{JPN}きみって ほんとうに すごいね!\p"
	.string "{JPN}でも わたし いがいに まだ\n"
	.string "{JPN}ふたりの つよい トレーナーが いるよ!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "{JPN}きみって ほんとうに すごいね!\p"
	.string "{JPN}でも わたし いがいに まだ\n"
	.string "{JPN}ひとりの つよい トレーナーが いるよ!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "{JPN}きみって ほんとうに すごいね!\p"
	.string "{JPN}もう きみに かてる ひとは\n"
	.string "{JPN}だれも のこって いないよ!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも まだ ななにんの トレーナーが\n"
	.string "{JPN}のこってる! だれかが きみを たおすさ!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも まだ ろくにんの トレーナーが\n"
	.string "{JPN}のこってる! だれかが きみを たおすさ!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも まだ ごにんの トレーナーが\n"
	.string "{JPN}のこってる! だれかが きみを たおすさ!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも まだ よにんの トレーナーが\n"
	.string "{JPN}のこってる! だれかが きみを たおすさ!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも まだ さんにんの トレーナーが\n"
	.string "{JPN}のこってる! だれかが きみを たおすさ!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも まだ ふたりの トレーナーが\n"
	.string "{JPN}のこってる! だれかが きみを たおすさ!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも まだ ひとりの トレーナーが\n"
	.string "{JPN}のこってる! きっと やられるよ!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "{JPN}くやしい!\p"
	.string "{JPN}でも もう きみと たたかえる\n"
	.string "{JPN}トレーナーは のこって いないよ!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}でも このかいには まだ ななにんの\n"
	.string "{JPN}トレーナーが いるよ みんな たおせる?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}でも このかいには まだ ろくにんの\n"
	.string "{JPN}トレーナーが いるよ みんな たおせる?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}でも このかいには まだ ごにんの\n"
	.string "{JPN}トレーナーが いるよ みんな たおせる?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}でも このかいには まだ よにんの\n"
	.string "{JPN}トレーナーが いるよ みんな たおせる?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}でも このかいには まだ さんにんの\n"
	.string "{JPN}トレーナーが いるよ みんな たおせる?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}でも このかいには まだ ふたりの\n"
	.string "{JPN}トレーナーが いるよ りょうほう たおせる?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}でも このかいには まだ ひとりの\n"
	.string "{JPN}トレーナーが いるよ かてるかな?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "{JPN}なかなか やるじゃない!\p"
	.string "{JPN}このかいの トレーナー\n"
	.string "{JPN}ぜんぶ たおしたね$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "{JPN}このかいに のこった ななにんの\n"
	.string "{JPN}トレーナーを ぜんぶ たおせるかも$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "{JPN}このかいに のこった ろくにんの\n"
	.string "{JPN}トレーナーを ぜんぶ たおせるかも$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "{JPN}このかいに のこった ごにんの\n"
	.string "{JPN}トレーナーを ぜんぶ たおせるかも$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "{JPN}このかいに のこった よにんの\n"
	.string "{JPN}トレーナーを ぜんぶ たおせるかも$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "{JPN}このかいに のこった\n"
	.string "{JPN}3にんの トレーナーを\nいっきに たおせるかも しれないね$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "{JPN}このかいに のこった\n"
	.string "{JPN}2にんの トレーナーを\nいっきに たおせるかも しれないね$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "{JPN}このかいに のこった\n"
	.string "{JPN}さいごの トレーナーで\nそうなめを かんせい できそうだね$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "{JPN}もうきみにかてるひとは\n"
	.string "{JPN}だれもいないよ...$"
BattlePyramid_Text_SevenTrainersRemaining5::
	.string "{JPN}のこった 7にんの\n"
	.string "{JPN}エキスパート トレーナーを\nたおす ちからが きみには あるかも$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "{JPN}のこった 6にんの\n"
	.string "{JPN}エキスパート トレーナーを\nたおす ちからが きみには あるかも$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "{JPN}のこった 5にんの\n"
	.string "{JPN}エキスパート トレーナーを\nたおす ちからが きみには あるかも$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "{JPN}のこった 4にんの\n"
	.string "{JPN}エキスパート トレーナーを\nたおす ちからが きみには あるかも$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "{JPN}のこった 3にんの\n"
	.string "{JPN}エキスパート トレーナーを\nたおす ちからが きみには あるかも$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "{JPN}のこった 2にんの\n"
	.string "{JPN}エキスパート トレーナーを\nたおす ちからが きみには あるかも$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "{JPN}のこった 1にんの\n"
	.string "{JPN}エキスパート トレーナーを\nたおす ちからが きみには あるかも$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "{JPN}きみの うでまえは もんくなしだ\p"
	.string "{JPN}ここには もう きみに かてる\n"
	.string "{JPN}かのうせいの ある トレーナーは\nいない$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "{JPN}のこった 7にんの トレーナーに\n"
	.string "{JPN}かちつづける ことが\nできるだろうか?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "{JPN}のこった 6にんの トレーナーに\n"
	.string "{JPN}かちつづける ことが\nできるだろうか?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "{JPN}のこった 5にんの トレーナーに\n"
	.string "{JPN}かちつづける ことが\nできるだろうか?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "{JPN}のこった 4にんの トレーナーに\n"
	.string "{JPN}かちつづける ことが\nできるだろうか?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "{JPN}のこった 3にんの トレーナーに\n"
	.string "{JPN}かちつづける ことが\nできるだろうか?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "{JPN}のこった 2にんの トレーナーに\n"
	.string "{JPN}かちつづける ことが\nできるだろうか?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "{JPN}さいごに のこった トレーナーに\n"
	.string "{JPN}かちつづける ことが\nできるだろうか?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "{JPN}もうきみにたちむかえる\n"
	.string "{JPN}トレーナーはいないよ...$"
