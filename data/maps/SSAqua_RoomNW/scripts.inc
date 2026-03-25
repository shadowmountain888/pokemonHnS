.set LOCALID_SSAQUA_SLEEPYSAILOR, 1

SSAqua_RoomNW_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "{JPN}そうさ おれは\n"
	.string "{JPN}ふなのりだ.\p"
	.string "{JPN}さぼってたわけじゃ\n"
	.string "{JPN}ないぞ!\p"
	.string "{JPN}このキャビンが\nからっぽだったから\nちょっと ひるねを\nしただけだ!\pあー もう いい!\nしょうぶだ!$"

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "{JPN}すまん! おれが\nわるかった!$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "{JPN}ふなのりは からだを\n"
	.string "{JPN}つかう しごとだから\nつかれるんだ!$"

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "{JPN}おお こまった.\n"
	.string "{JPN}とても だいじな ものを\nなくして しまった.$"

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "{JPN}わ... わたしは それを\nみつけられない...$"
SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "{JPN}あきらめます.\n"
	.string "{JPN}さがさなくても\n"
	.string "{JPN}いいですよ.\pわすれて ください!$"

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "{JPN}イーハー! ついてる!$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "{JPN}なんて ついてない!\nまけちまった!$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "{JPN}ここで きれいな コインを\n"
	.string "{JPN}みつけたよ.\pだれかが おとしたんだろうな...$"
