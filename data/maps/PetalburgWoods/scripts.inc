.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4
.set LOCALID_CELEBI, 17
.set LOCALID_OLD_MAN, 15
.set LOCALID_DUSCLOPS, 16

PetalburgWoods_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

PetalburgWoods_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_unset FLAG_EXTRA_LEGENDARIES, PetalburgWoods_SwitchToOld
	call_if_unset FLAG_SYS_GAME_CLEAR, PetalburgWoods_NoCelebiEvent
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods_YesCelebiEvent
	end

PetalburgWoods_SwitchToOld::
	setmaplayoutindex LAYOUT_PETALBURG_WOODS_OLD
	setflag FLAG_OLD_MAN_AND_DUSCLOPS
	removeobject LOCALID_OLD_MAN
	removeobject LOCALID_DUSCLOPS
	return
	end

PetalburgWoods_NoCelebiEvent::
	checkflag FLAG_GARBAGEFLAG
	call_if_unset FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEvent_End
	end

PetalburgWoods_YesCelebiEvent::
	checkflag FLAG_DEFEATEDCELEBI
	call_if_set FLAG_DEFEATEDCELEBI, PetalburgWoods_CelebiEvent_End
	call_if_unset FLAG_DEFEATEDCELEBI, PetalburgWoods_YesCelebiEvent2
	end

PetalburgWoods_YesCelebiEvent2::
	setflag FLAG_GARBAGEFLAG
	end

PetalburgWoods_CelebiEvent::
	lock
	playse SE_SUDOWOODO_SHAKE
	waitse
	msgbox Text_PetalburgWoods_Celebi0, MSGBOX_SIGN
	closemessage
	checkflag FLAG_GARBAGEFLAG
	call_if_unset FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEvent_End
	call_if_set FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEventGo
	end

PetalburgWoods_CelebiEventGo::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PetalburgWoods_Celebi1
	waitmovement 0
	msgbox Text_PetalburgWoods_Celebi1, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_RAIKOU, PetalburgWoods_CelebiEvent_Continue1
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_Continue1::
	msgbox Text_PetalburgWoods_Celebi2, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_ENTEI, PetalburgWoods_CelebiEvent_Continue2
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_Continue2::
	msgbox Text_PetalburgWoods_Celebi3, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_SUICUNE, PetalburgWoods_CelebiBattle
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_End::
	releaseall
	end

PetalburgWoods_CelebiBattle::
	faceplayer
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PetalburgWoods_Celebi1
	waitmovement 0
	msgbox Text_PetalburgWoods_Celebi4, MSGBOX_DEFAULT
	setwildbattle SPECIES_CELEBI, 50
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves
	waitmovement 0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_CelebiEvent_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PetalburgWoods_CelebiEvent_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_CelebiEvent_Ran
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_CelebiEvent_Ran
	releaseall
	end

PetalburgWoods_CelebiEvent_Won::
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves2
	waitmovement 0
	setflag FLAG_DEFEATEDCELEBI
	clearflag FLAG_GARBAGEFLAG
	end

PetalburgWoods_CelebiEvent_Ran::
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves2
	waitmovement 0
	end

PetalburgWoods_EventScript_CelebiMoves:
	delay_16
	delay_16
	delay_16
	walk_down
	set_visible
	step_end

PetalburgWoods_EventScript_CelebiMoves2:
	set_invisible
	walk_up
	step_end

Text_PetalburgWoods_Celebi0:
	.string "{JPN}きが ゆれている.\p"
	.string "{JPN}だれかに みられているような\n"
	.string "{JPN}きがする...\p"
	.string "{JPN}でも... ポケモンは\nみえない...$"
Text_PetalburgWoods_Celebi1:
	.string "{JPN}. . . \p"
	.string "{JPN}. . . \p"
	.string "{JPN}かすかな こえが きこえる.\p"
	.string "{JPN}か..ん .. ..り  . . .デン キ. ポケ\p"
	.string "{JPN}. . . \n"
	.string "{JPN}かんでん ポケモンを みせて...$"
Text_PetalburgWoods_Celebi2:
	.string "{JPN}. . . \p"
	.string "{JPN}. . . \p"
	.string "{JPN}み.. せて .かざん . ..モン$"

Text_PetalburgWoods_Celebi3:
	.string "{JPN}. . . \p"
	.string "{JPN}. . . \n"
	.string "{JPN}オー..ラ ポケモンを みせ..$"
Text_PetalburgWoods_Celebi4:
	.string "{JPN}. . . \n"
	.string "{JPN}なにかが ちかづいて くる...\p"
	.string "{JPN}. . . $"

Text_PetalburgWoods_Celebi_Donthave:
	.string "{JPN}. . . \n"
	.string "{JPN}..れを も.て い..い\n"
	.string "{JPN}それを もって いない...$"
Movement_PetalburgWoods_Celebi1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

PetalburgWoods_Dusclops::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	msgbox PetalburgWoods_Text_Dusclops, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgWoods_Text_Dusclops:
	.string "{JPN}ダスキー: やみ やみ!$"

PetalburgWoods_Celebi_Sign::
	faceplayer
	goto_if_unset FLAG_ROBERTO1, PetalburgWoods_Celebi_SignFirstTime
	goto_if_set FLAG_DEFEATEDCELEBI, PetalburgWoods_Celebi_SignEventFinished
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods_Celebi_SignChampion
	msgbox Text_PetalburgWoods_Celebi_Sign, MSGBOX_NPC
	end

PetalburgWoods_Celebi_SignFirstTime::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignFirstTime, MSGBOX_NPC
	setflag FLAG_ROBERTO1
	end

PetalburgWoods_Celebi_SignEventFinished::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignEventFinished, MSGBOX_NPC
	end

PetalburgWoods_Celebi_SignChampion::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignEventChampion, MSGBOX_NPC
	end

Text_PetalburgWoods_Celebi_Sign:
	.string "{JPN}やあ トレーナー.\p"
	.string "{JPN}きけん? いや いや.しんぱい\l"
	.string "{JPN}しなくても だいじょうぶ.\l"
	.string "{JPN}ダスキーが まわりを みはってる.\p"
	.string "{JPN}きみは? ぼうけんの ちょうしは\nどう?$"

Text_PetalburgWoods_Celebi_SignFirstTime:
	.string "{JPN}おお  わかいの...\p"
	.string "{JPN}こんな くらい もりで\n"
	.string "{JPN}なにを しとるんじゃ?\p"
	.string "{JPN}. . .\p"
	.string "{JPN}ああ そうか.とおりすがり\n"
	.string "{JPN}なんじゃな.\p"
	.string "{JPN}なに? ああ わし?\p"
	.string "{JPN}わしは いつものように\n"
	.string "{JPN}きの ほこらに みずを やっとる.\p"
	.string "{JPN}ああ もりの まんなかにある\n"
	.string "{JPN}ふつうの きに なぜ みずを\l"
	.string "{JPN}やるのか ふしぎに おもうじゃろ?\p"
	.string "{JPN}じつは この きは とくべつ\n"
	.string "{JPN}なんじゃ.この もりには\l"
	.string "{JPN}でんせつの ポケモンが おる.\p"
	.string "{JPN}もりの しゅごしゃ なんじゃ.\p"
	.string "{JPN}わしは にじゅうねん いじょう\n"
	.string "{JPN}この きに みずを やり つづけた.\p"
	.string "{JPN}この はなしは わしらが\n"
	.string "{JPN}すう くうきと おなじくらい\l"
	.string "{JPN}ほんとうの ことじゃ.\p"
	.string "{JPN}もりの しゅごしゃは ちいさくて\n"
	.string "{JPN}みどりいろで みているだけで...\p"
	.string "{JPN}もりの せいれいを みているような\n"
	.string "{JPN}きもちに なるんじゃ.\l"
	.string "{JPN}ざんねんながら さいごに みたのは\l"
	.string "{JPN}ずいぶん むかしの ことじゃが...\p"
	.string "{JPN}しゅごしゃは どこに いるんじゃ\n"
	.string "{JPN}ろうか?\p"
	.string "{JPN}わしが もっと つよく なれば\nあらわれて くれるかも\lしれんのう...\pとしを とって よわく なって\nしまった わしが なさけない\nのう.\pとにかく  わしは つづけるぞ.\nまた あおうな わかいの.$"

Text_PetalburgWoods_Celebi_SignEventFinished:
	.string "{JPN}. . . \p"
	.string "{JPN}しんじられない!\n"
	.string "{JPN}きみが しゅごしんと たたかったの!?\p"
	.string "{JPN}この しゅんかんを ぜったいに\n"
	.string "{JPN}わすれない.みらいに また\l"
	.string "{JPN}もどってくるまで この ほこらに\lみずを やりつづけよう.$"

Text_PetalburgWoods_Celebi_SignEventChampion:
	.string "{JPN}また あったな わかいの.\p"
	.string "{JPN}しゅごしゃの きに へんかが\n"
	.string "{JPN}あったようじゃ.\p"
	.string "{JPN}なんじかん も ちいさな つぶやきが\n"
	.string "{JPN}きこえて おる.\p"
	.string "{JPN}かみなりや かざんや オーロラの\n"
	.string "{JPN}ポケモンの ことを いっとる\n"
	.string "{JPN}ようじゃが...\p"
	.string "{JPN}まて... その せつめい\n"
	.string "{JPN}しっとる きが する...\n"
	.string "{JPN}さんびきの けものの ことか?\p"
	.string "{JPN}でも... この ちほうの では\n"
	.string "{JPN}ないな? どこの だったかな?\n"
	.string "{JPN}ギオト? ホウジョウ? ジョウノ?\n"
	.string "{JPN}ジョウト?\p"
	.string "{JPN}もし やつらが ここ ホウエンに\nおるなら... じぶんたちの\ltokuちょうに あった ばしょに\lかくれとるかも しれんな.\pもし じかんが あったら\nsagaして みては どうじゃ?$"

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TONY, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TONY, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_GARBAGEVAR, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_RIVAL_CYNDAQUIL_4, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_RIVAL_CYNDAQUIL_4
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_RIVAL_CYNDAQUIL_4
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_RIVAL_CYNDAQUIL_4
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_RIVAL_CYNDAQUIL_4, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "{JPN}うーん...\n"
	.string "{JPN}ひとつも みつからんな...$"
PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "{JPN}こんにちは このへんで\n"
	.string "{JPN}キノココという ポケモンを\l"
	.string "{JPN}みかけませんでしたか?\pあの ポケモンが だいすきなんです.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "{JPN}まちぶせ してやろうと おもってたのに\n"
	.string "{JPN}おまえ トウカのもりで いつまでも\l"
	.string "{JPN}ぐずぐず してるんだもん!\p"
	.string "{JPN}まつのに あきたから でてきたぜ!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "{JPN}おまえ! デボンの けんきゅういん!\p"
	.string "{JPN}その しょるいを わたせ!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "{JPN}あいえええ!\p"
	.string "{JPN}きみ ポケモントレーナーだろう?\n"
	.string "{JPN}たすけて くれよ おねがいだ!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "{JPN}はん? なにしてるつもりだ?\n"
	.string "{JPN}なに そいつを まもるって?\p"
	.string "{JPN}アクアだんに さからうやつには\n"
	.string "{JPN}ようしゃしねえぞ こどもでもな!\p"
	.string "{JPN}かかってこい!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "{JPN}うそだろ! つええじゃねえか!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "{JPN}ぐぬぬ... アクアだんに\n"
	.string "{JPN}よくも でしゃばって くれたな!\l"
	.string "{JPN}もういちど しょうぶしてやる!\p"
	.string "{JPN}そう いいたいが ポケモンが\n"
	.string "{JPN}いないんじゃ...\p"
	.string "{JPN}それに おれたち アクアだんも\n"
	.string "{JPN}カナズミシティで やることが\n"
	.string "{JPN}あるんでな.\pきょうは みのがして やる!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "{JPN}ふう...\n"
	.string "{JPN}あぶなかった!\p"
	.string "{JPN}きみの おかげで だいじな\n"
	.string "{JPN}しょるいを とられずに すんだよ.\p"
	.string "{JPN}おれいに スーパーボールを\n"
	.string "{JPN}あげよう!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "{JPN}あの アクアだんのやつ \n"
	.string "{JPN}カナズミでも なにかを\l"
	.string "{JPN}ねらってるって いってなかった?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "{JPN}あ! たいへんだ!\n"
	.string "{JPN}じかんを むだに できない!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "{JPN}どうぐを たくさん もってるね.\n"
	.string "{JPN}この スーパーボールは わたせないよ.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "{JPN}ポケモンを たくさん つかまえたぞ!\p"
	.string "{JPN}いけ いけ いけ!\n"
	.string "{JPN}ぼくの むしポケモンチーム!$"

PetalburgWoods_Text_ICouldntWin:
	.string "{JPN}これだけ ポケモンが いるのに\n"
	.string "{JPN}かてなかった...$"
PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "{JPN}ポケモンを たくさん つかまえた.\n"
	.string "{JPN}もう モンスターボールが ない.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "{JPN}むしポケモンを がっこうに もってくと\n"
	.string "{JPN}すぐに にんきものに なれるんだ!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "{JPN}まけちゃったら にんきもの\nじゃなくなっちゃう.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "{JPN}おおきな むしポケモンを もってると\n"
	.string "{JPN}みんなが そんけいしてくれるんだ.$"

PetalburgWoods_Text_IWantRematch1:
	.string "{JPN}ぼくの むしポケモンが そだったら\n"
	.string "{JPN}リベンジしたいな!\p"
	.string "{JPN}ポケナビに とうろく させてもらうよ!$"

PetalburgWoods_Text_IWantRematch2:
	.string "{JPN}ぼくの むしポケモンが そだったら\n"
	.string "{JPN}リベンジしたいな!\p"
	.string "{JPN}ポケナビに とうろく させてもらうよ!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "{JPN}ぼくの むしポケモンが そだった.\n"
	.string "{JPN}また にんきものに なれるぞ.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "{JPN}まけちゃったら にんきもの\nじゃなくなっちゃう.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "{JPN}つよい ポケモンを もってれば\n"
	.string "{JPN}にんきものに なれるよね?\l"
	.string "{JPN}だから いっしょうけんめい\lとれーにんぐ してるんだ.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "{JPN}よお!\n"
	.string "{JPN}きみの ポケモン げんきか?\p"
	.string "{JPN}ポケモンが よわくて たたかいを\n"
	.string "{JPN}さけたいなら たかい くさむらには\l"
	.string "{JPN}はいらない ほうが いいぞ.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "{JPN}ときどき みえなくても\n"
	.string "{JPN}じめんに ものが おちてる\l"
	.string "{JPN}ことが あるんだ.\p"
	.string "{JPN}だから いつも あるいてるところを\nちぇっく してるのさ.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "{JPN}おお すごいね!\n"
	.string "{JPN}それは カナズミジムの バッジだ!\p"
	.string "{JPN}きみは トレーナーなんだね.\n"
	.string "{JPN}この どうぐを つかってみて.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "{JPN}それは きせきのタネだよ.\n"
	.string "{JPN}ポケモンが そのどうぐを もつと \l"
	.string "{JPN}くさタイプの わざが つよくなる.\p"
	.string "{JPN}きせきのタネの ほかにも \n"
	.string "{JPN}ポケモンに もたせると\l"
	.string "{JPN}べんりな どうぐが あるよ.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "{JPN}トレーナーの こころえ\p"
	.string "{JPN}バトルで いちどでも でてきた\n"
	.string "{JPN}ポケモンには けいけんちが はいる.\p"
	.string "{JPN}よわい ポケモンを そだてるには \n"
	.string "{JPN}てもちの いちばんひだりに おく.\p"
	.string "{JPN}バトルが はじまったら すぐに\n"
	.string "{JPN}こうたいする.きずつかずに\l"
	.string "{JPN}けいけんちが もらえるぞ.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "{JPN}トレーナーの こころえ\p"
	.string "{JPN}ポケモンには たいりょく(HP)の\n"
	.string "{JPN}ほかに わざを つかうための\l"
	.string "{JPN}パワー(PP)が ある.\p"
	.string "{JPN}PPが なくなったら ポケモンセンター\n"
	.string "{JPN}に つれていこう.$"

