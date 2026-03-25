.set LOCALID_NURSE, 1

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges::
	lock
	goto_if_unset FLAG_DEFEATED_RED, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NotYet
	msgbox BattleFrontier_PokemonCenter_1F_Text_DisableChallenges, MSGBOX_NPC
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit, EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror, EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief, EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive, EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType, EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit, EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer, EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer, EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal
	switch VAR_RESULT
	case 0, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit_Ask
	case 1, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror_Ask
	case 2, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief_Ask
	case 3, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive_Ask
	case 4, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType_Ask
	case 5, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit_Ask
	case 6, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer_Ask
	case 7, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer_Ask
	case 8, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal_Ask
	closemessage
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NotYet::
	msgbox BattleFrontier_PokemonCenter_1F_Text_DisableChallenges_NotYet, MSGBOX_NPC
	closemessage
	release
	end

BattleFrontier_PokemonCenter_1F_Text_DisableChallenges_NotYet::
	.string "{JPN}まだ ゲームを クリアして\n"
	.string "{JPN}いないね!\p"
	.string "{JPN}の トレーナーを たおすまで\nチャレンジを むこうに できないよ$"

BattleFrontier_PokemonCenter_1F_Text_DisableChallenges:
	.string "{JPN}ゲーム クリア おめでとう!\p"
	.string "{JPN}よかったら いくつかの\n"
	.string "{JPN}チャレンジを むこうに できるよ\p"
	.string "{JPN}ただし いちど むこうにすると\n"
	.string "{JPN}もう もどせないから きをつけてね\p"
	.string "{JPN}また チャレンジが ゆうこうでない\n"
	.string "{JPN}ばあいは むこうにしようとしても\l"
	.string "{JPN}なにも おこらないよ$"

BattleFrontier_PokemonCenter_1F_Text_Done:
	.string "{JPN}できた!$"

@evo limit
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_EvoLimit:
	callnative DisableChallengesAfterBeatingGameEvoLimit
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit:
	.string "{JPN}しんかせいげん$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_EvoLimit_Disable:
	.string "{JPN}しんかせいげんを むこうにする?$"

@mirror
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Mirror:
	callnative DisableChallengesAfterBeatingGameMirror
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror:
	.string "{JPN}ミラー$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_Mirror_Disable:
	.string "{JPN}ミラーチャレンジを むこうにする?$"

@mirror thief
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_MirrorThief:
	callnative DisableChallengesAfterBeatingGameMirrorThief
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief:
	.string "{JPN}ミラーシーフ$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_MirrorThief_Disable:
	.string "{JPN}ミラーシーフチャレンジを\nむこうにする?$"

@Expensive Challenge
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_Expensive:
	callnative DisableChallengesAfterBeatingGameExpensiveChallenge
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive:
	.string "{JPN}ウルトラこうか!$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_Expensive_Disable:
	.string "{JPN}ウルトラこうかを むこうにする?$"

@one type
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_OneType:
	callnative DisableChallengesAfterBeatingGameOneType
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType:
	.string "{JPN}ワンタイプチャレンジ$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_OneType_Disable:
	.string "{JPN}ワンタイプチャレンジを\nむこうにする?$"

@party limit
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PartyLimit:
	callnative DisableChallengesAfterBeatingGamePartyLimit
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit:
	.string "{JPN}パーティーせいげん$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_PartyLimit_Disable:
	.string "{JPN}パーティーせいげんを\nむこうにする?$"

@no item player
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemPlayer:
	callnative DisableChallengesAfterBeatingGameNoItemPlayer
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer:
	.string "{JPN}アイテムなし(プレイヤー)$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemPlayer_Disable:
	.string "{JPN}アイテムなし(プレイヤー)を\nむこうにする?$"

@no item TRAINER
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_NoItemTrainer:
	callnative DisableChallengesAfterBeatingGameNoItemTrainer
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer:
	.string "{JPN}アイテムなし(プレイヤー)$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_NoItemTrainer_Disable:
	.string "{JPN}アイテムなし(プレイヤー)を\nむこうにする?$"

@pkcenter challenge
BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal_Ask:
	msgbox EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal_Disable, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	end

BattleFrontier_PokemonCenter_1F_EventScript_DisableChallenges_PokecenterChal:
	callnative DisableChallengesAfterBeatingGamePkmCenterChallenge
	msgbox BattleFrontier_PokemonCenter_1F_Text_Done, MSGBOX_NPC
	closemessage
	release
	end

EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal:
	.string "{JPN}ポケモンセンターチャレンジ$"

EventScript_MultichoiceDisableChallenge_Text_Challenge_PokecenterChal_Disable:
	.string "{JPN}ポケモンセンターチャレンジを\nむこうにする?$"

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "{JPN}ここに みたことのない\n"
	.string "{JPN}ポケモンを つかっている ひとが\n"
	.string "{JPN}いたんだ\p"
	.string "{JPN}トレーナーズスクールでも\n"
	.string "{JPN}ならわなかったよ\p"
	.string "{JPN}ああいう ポケモンって\nどこで つかまえられるのかな$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "{JPN}よし! つぎは バトルアリーナ!\n"
	.string "{JPN}パソコンから ただしい ポケモンを\l"
	.string "{JPN}だしておかなくちゃ$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "{JPN}くすくす... このこだけで\n"
	.string "{JPN}ぜんぶのちゃれんじを\lクリアしちゃうんだから!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "{JPN}エネコ: みゃー みゃーん!$"

