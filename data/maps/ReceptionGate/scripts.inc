.set LOCALID_INDIGOJUNCTION_POLICEMAN, 1
.set LOCALID_INDIGOJUNCTION_JANINE, 4

ReceptionGate_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
    .string "{JPN}アンズ: おとうさんの おうちに\n"
	.string "{JPN}おべんとう もっていく ところなの.\p"
    .string "{JPN}エリートよんは ひるも よるも\n"
	.string "{JPN}やすむ じかんが ないのよ.\l"
    .string "{JPN}ほんとに たいへんな しごとなの.\p"
	.string "{JPN}また たたかう きもちが あるなら\n"
    .string "{JPN}あとで どうじょうで まってるわ.$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 20
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "{JPN}ちからを みとめられた\n"
	.string "{JPN}トレーナーしか とおれません.$"

VictoryRoadGate_Text_Kimono:
    .string "{JPN}ごめんなさい こどもさん\n"
	.string "{JPN}でんせつの ポケモンを\l"
    .string "{JPN}なんとか してくれるまで\nここは とおれません...$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "{JPN}あなたは ジョウトちほうの\n"
	.string "{JPN}ジムバッジを ぜんぶ もってませんね.\p"
    .string "{JPN}もうしわけないですが\n"
	.string "{JPN}とおす ことは できません.$"

VictoryRoadGate_Text_EightBadges:
    .string "{JPN}おお! ジョウトちほうの\n"
	.string "{JPN}はっつの バッジですね!\pどうぞ とおって ください!$"

VictoryRoadGate_Text_LeftBlackBelt:
    .string "{JPN}こちらは シロガネやまへの\n"
	.string "{JPN}みちです.\p"
    .string "{JPN}とても つよい ポケモンが\nいますよ.$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "{JPN}ポケモンリーグへ いくのですね?\p"
	.string "{JPN}エリートよんは おそろしいほど\n"
    .string "{JPN}つよくて あなたを まってますよ!$"
