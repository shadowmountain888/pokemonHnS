.set LOCALID_VICTORYROAD_SILVER, 13

VictoryRoadKanto_1F_MapScripts::
	.byte 0

VictoryRoadKanto_1F_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
VictoryRoadKanto_1F_EventScript_Item_MaxEther::
	finditem ITEM_MAX_ETHER
	end
VictoryRoadKanto_1F_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

VictoryRoadKanto_1F_Trigger::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	delay 5
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	addobject LOCALID_VICTORYROAD_SILVER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 27, VictoryRoadKanto_1F_EventScript_SilverEnterLeft
	call_if_eq VAR_TEMP_0, 28, VictoryRoadKanto_1F_EventScript_SilverEnterMid
	call_if_eq VAR_TEMP_0, 29, VictoryRoadKanto_1F_EventScript_SilverEnterRight
	msgbox VictoryRoad_Text_RivalBefore, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, VictoryRoadKanto_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, VictoryRoadKanto_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, VictoryRoadKanto_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	msgbox VictoryRoad_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverLeave
	waitmovement 0
	removeobject LOCALID_VICTORYROAD_SILVER
	fadedefaultbgm
	release
	setvar VAR_ROUTE27_STATE, 3
	end

VictoryRoadKanto_1F_EventScript_SilverEnterLeft::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterLeft
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterMid::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterMid
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return

VictoryRoadKanto_1F_EventScript_SilverEnterRight::
	applymovement2 LOCALID_VICTORYROAD_SILVER, VictoryRoadKanto_1F_Movement_SilverEnterRight
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement LOCALID_VICTORYROAD_SILVER
	return


VictoryRoadKanto_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_5, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_5, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_5, VictoryRoad_Text_RivalDefeat
	return

VictoryRoadKanto_1F_Movement_SilverEnterLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterMid:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverEnterRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end
VictoryRoadKanto_1F_Movement_SilverLeave:
	walk_down
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
	walk_left
	step_end

VictoryRoad_Text_RivalBefore:
    .string "{JPN}まて.\p"
	.string "{JPN}おまえ ポケモンリーグに\n"
	.string "{JPN}ちょうせん するつもりか?\p"
	.string "{JPN}はっ... わらわせるな.\p"
	.string "{JPN}おまえなんて おれより\n"
	.string "{JPN}ずっと よわいくせに.\p"
    .string "{JPN}おれは まえとは ちがう.\p"
	.string "{JPN}いまは さいきょうの ポケモンを\n"
    .string "{JPN}つれて いるからな.\p"
	.string "{JPN}おれに かてるやつなんて\n"
    .string "{JPN}いないぜ!\p{PLAYER}!\nしょうぶだ!$"

VictoryRoad_Text_RivalDefeat:
    .string "{JPN}...まけた...\p"
	.string "{JPN}ぜんりょくで たたかったのに...\p"
	.string "{JPN}おまえが もっていて\n"
	.string "{JPN}おれに たりないもの...\p"
    .string "{JPN}りゅうつかいの おやじが\nいっていた いみが\nわかってきた...$"
VictoryRoad_Text_RivalAfter:
    .string "{JPN}...さいきょうの トレーナーに\n"
	.string "{JPN}なることを あきらめたりしない.\p"
	.string "{JPN}なぜ かてないのか りゆうを\n"
	.string "{JPN}みつけて つよくなる.\p"
	.string "{JPN}そのときは また おまえに\n"
	.string "{JPN}ちょうせんする.\p"
    .string "{JPN}こんどこそ ぜんりょくで\n"
	.string "{JPN}たたきのめしてやる.\p...ふん! それまで\nがんばってろよ.$"
