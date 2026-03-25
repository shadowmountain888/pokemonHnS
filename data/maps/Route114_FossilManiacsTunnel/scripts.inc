.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "{JPN}わたしは かせきマニア...\n"
	.string "{JPN}かせきが だいすきな\l"
	.string "{JPN}やさしい おとこなんだ...\p"
	.string "{JPN}かせきが ほしいかい?\p"
	.string "{JPN}でも このあたりの かせきは\n"
	.string "{JPN}ぜんぶ わたしのものだ...\l"
	.string "{JPN}きみには あげられないよ...\p"
	.string "{JPN}どうしても かせきが ほしけりゃ\n"
	.string "{JPN}さばくで いわや すなのなかを\lさがしてみるといい...\lかせきが かくれてるかもよ...$"
Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "{JPN}かせきを みつけたんだね?\n"
	.string "{JPN}それは すばらしい...\l"
	.string "{JPN}ゆめみたいだ...\p"
	.string "{JPN}その かせきを どうするつもり\n"
	.string "{JPN}なんだい?\p"
	.string "{JPN}うわさに きいたところだと\n"
	.string "{JPN}デボンが かせきから ポケモンを\l"
	.string "{JPN}ふっかつさせる けんきゅうを\l"
	.string "{JPN}してるらしいよ...\pわたしは かせきを あいしてるから\nそんなことは ぜったい\lしないけどね...$"
Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "{JPN}かせきって... すばらしい...\n"
	.string "{JPN}ほんとうに ゆめみたいだ...$"
Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "{JPN}おお...\n"
	.string "{JPN}そっちは きけんだよ...\p"
	.string "{JPN}わたしが ほっていたら...\n"
	.string "{JPN}かべが ぜんぶ くずれて\l"
	.string "{JPN}しまったんだ...\p"
	.string "{JPN}したに おおきな ほらあなが\n"
	.string "{JPN}できちゃったみたいだね...\p"
	.string "{JPN}でも かせきは ないとおもうから\nほうっておいてるんだ...$"
