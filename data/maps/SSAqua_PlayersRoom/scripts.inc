SSAqua_PlayersRoom_MapScripts::
	.byte 0

SSAquaRooms_EventScript_Bed::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSAquaRooms_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox SSAquaRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

SSAquaRooms_EventScript_Bed_PokecenterChallenge::
	msgbox SSAquaRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end


SSAquaRooms_Text_TakeRestOnBed_PokecenterChallenge:
	.string "{JPN}すみません あなたは\n"
	.string "{JPN}ポケモンセンターチャレンジを\nプレイちゅうです!$"

SSAquaRooms_Text_TakeRestOnBed:
	.string "{JPN}ベッドが ある...\n"
	.string "{JPN}やすんでいこう$"
