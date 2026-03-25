MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "{JPN}わしが わかかった ころは\n"
	.string "{JPN}ポケモントレーナーとして\l"
	.string "{JPN}せかいを たびしておったのう.\p"
	.string "{JPN}いまでは としよりに なって\n"
	.string "{JPN}しまい わかい トレーナーの\lたたかいを みるのが たのしみじゃ.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "{JPN}ドアに かぎが かかっている\nようだ.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "{JPN}{STR_VAR_1}という トレーナーが\n"
	.string "{JPN}わしの いえに きておる.\p"
	.string "{JPN}{STR_VAR_1}に ちょうせん\n"
	.string "{JPN}してみるかね?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "{JPN}たたかわないの?きみの\n"
	.string "{JPN}たたかいが みられなくて\pざんねんだよ...$"
RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "{JPN}おお それは いいのう!\p"
	.string "{JPN}しかし わしの いえは それほど\n"
	.string "{JPN}じょうぶでは ないのじゃ.\p"
	.string "{JPN}3たい3の しょうぶに して\nもらえるかのう?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "{JPN}ふたりが たたかう まえに\n"
	.string "{JPN}レポートを かいておくのが\lよいじゃろう.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "{JPN}いい しょうぶを みせて\nくれることを きたいしておる!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "{JPN}なるほど ひきわけか.\p"
	.string "{JPN}どちらも いっぽも ゆずらない\n"
	.string "{JPN}すばらしい しょうぶじゃった!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "{JPN}それは すばらしかった!\p"
	.string "{JPN}まるで わかい ころの わしを\n"
	.string "{JPN}みているようじゃった!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "{JPN}ああ ざんねんじゃったのう!\p"
	.string "{JPN}しかし いい しょうぶじゃった.\n"
	.string "{JPN}こんどは かてるよう がんばれ.$"
