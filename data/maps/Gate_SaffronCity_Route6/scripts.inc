Gate_SaffronCity_Route6_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "{JPN}ヤマブキシティへ ようこそ!\n"
	.string "{JPN}リニアモーターカーの まちです!\p"
	.string "{JPN}...っていつもなら いうんだが\n"
	.string "{JPN}リニアモーターカーは\l"
	.string "{JPN}いま うごいてないんだ.\p"
	.string "{JPN}はつでんしょに なにか\n"
	.string "{JPN}もんだいが あって\l"
	.string "{JPN}でんきが きてないからね.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "{JPN}リニアモーターカーは\n"
	.string "{JPN}ヤマブキシティの\lいちばん ゆうめいな\lものだよ.$"
