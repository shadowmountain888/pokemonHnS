.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9

MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_GARBAGEFLAG
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "{JPN}へへへ!\p"
	.string "{JPN}この いんせきが あれば\n"
	.string "{JPN}えんとつやまの あいつが...$"
MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "{JPN}へへ?\p"
	.string "{JPN}だれだかしらないが マグマだん\n"
	.string "{JPN}のじゃまをするなら ようしゃは\l"
	.string "{JPN}しないぞ!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "{JPN}まて そこだ マグマだん!\p"
	.string "{JPN}せかいをじぶんたちのおもうがまま\n"
	.string "{JPN}にできるとおもったら だいまちがい\lだ!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "{JPN}へへへ!\n"
	.string "{JPN}アクアだんも やってきたか!\p"
	.string "{JPN}だが きさまらの あいてを\n"
	.string "{JPN}している ひまは ない...\p"
	.string "{JPN}へっ どうでも いいや!\p"
	.string "{JPN}いんせきは てに いれた!\n"
	.string "{JPN}えんとつやまに いくぞ!\p"
	.string "{JPN}へへへ! また あおうぜ\n"
	.string "{JPN}アクアだんの まぬけども!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "{JPN}アオギリ: おまえ どこかで\n"
	.string "{JPN}あったことが あるな?\n"
	.string "{JPN}カイナの はくぶつかんで?\p"
	.string "{JPN}ああ {PLAYER}と いうのか\p"
	.string "{JPN}あの ときは マグマだんの\n"
	.string "{JPN}いちみかと おもったが...\p"
	.string "{JPN}ふん...\n"
	.string "{JPN}へんな がきだな\p"
	.string "{JPN}マグマだんは きけんな\n"
	.string "{JPN}きょうしんてき しゅうだんだ\p"
	.string "{JPN}りくちを ひろげる といって\n"
	.string "{JPN}はかいを くりかえしている\p"
	.string "{JPN}われら うみを あいする\nアクアだんの てきだ!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "{JPN}ボス マグマだんを\n"
	.string "{JPN}おいかけましょう...$"
MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "{JPN}アオギリ:そのとおりだ そうとも!\n"
	.string "{JPN}いそがなければ.\p"
	.string "{JPN}マグマだんが えんとつやまで\n"
	.string "{JPN}なにをするか わからないからな!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "{JPN}アオギリ:{PLAYER}よ おまえも\n"
	.string "{JPN}マグマだんにきをつけるんだ.\p"
	.string "{JPN}それでは さらばだ!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "{JPN}わ... わたしは コズモ...\n"
	.string "{JPN}はかせを やっています...\p"
	.string "{JPN}マグマだんに たのまれて\n"
	.string "{JPN}りゅうせいのたきまで\n"
	.string "{JPN}あんないしました...\p"
	.string "{JPN}でも だまされたのです\n"
	.string "{JPN}わたしの いんせきまで\n"
	.string "{JPN}うばわれてしまって...\p"
	.string "{JPN}それから にたような\n"
	.string "{JPN}アクアだんも あらわれて\p"
	.string "{JPN}そのあとは...\n"
	.string "{JPN}なにが なんだか...\p"
	.string "{JPN}でも あの マグマだんは...\pえんとつやまで いんせきを\nつかって なにを するつもり\nなのでしょうか?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "{JPN}コズモはかせ: でも あの\n"
	.string "{JPN}マグマだんは...\p"
	.string "{JPN}えんとつやまで いんせきを\nつかって なにを するつもり\nなのでしょうか?$"
