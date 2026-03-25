DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_DICK, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_HARVEY, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_DICK, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_AZALEA_TOWN_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_DICK, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_HARVEY, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AZALEA_TOWN_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "{JPN}やあ ちょうし どうだい \n"
	.string "{JPN}チャンピオンを めざす {PLAYER}!\p"
	.string "{JPN}ムロタウンの ジムリーダー\n"
	.string "{JPN}トウキは かくとうタイプの\l"
	.string "{JPN}ポケモンを つかうぞ!\p"
	.string "{JPN}ノーマルタイプの ポケモンで\n"
	.string "{JPN}たたかうのは やばいぞ!\p"
	.string "{JPN}かくとうポケモンは ノーマル\n"
	.string "{JPN}ポケモンを ぼこぼこに\l"
	.string "{JPN}してしまうからな!\p"
	.string "{JPN}しかも このジムは うみの\n"
	.string "{JPN}そこみたいに まっくらだ!\p"
	.string "{JPN}でも みちを はばむ\n"
	.string "{JPN}トレーナーたちを たおせば\lあかるくなるぞ!\pよし がんばれよ!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "{JPN}わあ! ここ あかるすぎるぞ!\p"
	.string "{JPN}きみの みらいも\nあかるいな!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "{JPN}ちからこそ せいぎだ!\n"
	.string "{JPN}かかってこい!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "{JPN}ちからが たりない...$"
DewfordTown_Gym_Text_TakaoPostBattle:
	.string "{JPN}きみの ぎじゅつが おれの\n"
	.string "{JPN}ちからに かったな!\nりっぱな わざまえだ!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "{JPN}トウキに でてもらう\n"
	.string "{JPN}ひつようは ないわ!\p"
	.string "{JPN}あなたを つぶしてあげる!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "{JPN}そんな... どうして?\n"
	.string "{JPN}どうして こんなに かんたんに\nまけちゃうの?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "{JPN}このまけを むだにしないわ.\n"
	.string "{JPN}しゅぎょうの やるきに かえるの!\p"
	.string "{JPN}いつか わたしが ジムリーダーに\n"
	.string "{JPN}なってやる...\p"
	.string "{JPN}いえ ポケモンリーグの\nチャンピオンに なるのよ!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "{JPN}あたしを みくびっちゃ だめよ!\n"
	.string "{JPN}ないても しらないからね!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "{JPN}わああああん!\n"
	.string "{JPN}まけちゃった!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "{JPN}くらやみで たたかうのは こころを\n"
	.string "{JPN}つよくする ためなの.\p"
	.string "{JPN}でも くらいから トウキの かおが\n"
	.string "{JPN}ぜんぜん みえないのよね...$"
DewfordTown_Gym_Text_LilithIntro:
	.string "{JPN}うふふ...\n"
	.string "{JPN}くらやみで まよってるの?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "{JPN}あら あなた...\n"
	.string "{JPN}しりたくないわ!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "{JPN}あなたは まいごに なって\n"
	.string "{JPN}いりぐちに もどっちゃえば\lいいのよ!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "{JPN}うみのおとこの こんじょうを\n"
	.string "{JPN}みせてやるぜ!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "{JPN}どうして こうなった?\n"
	.string "{JPN}こんなまけかた おれらしく\lないぞ!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "{JPN}ああ! きみなら ジムリーダーに\n"
	.string "{JPN}あう かちが あるな!$"

DewfordTown_Gym_Text_CristianIntro:
	.string "{JPN}とおりたければ おれを\n"
	.string "{JPN}たおしてからだ!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "{JPN}ぐああああ!\n"
	.string "{JPN}ちからの さが ありすぎる!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "{JPN}きみの かちだ!\n"
	.string "{JPN}バッジを とりに いけ!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "{JPN}おれは トウキ!\n"
	.string "{JPN}ムロタウンの ジムリーダーだ!\p"
	.string "{JPN}このへんの あらなみに もまれて\n"
	.string "{JPN}まっくらな ほらあなで\l"
	.string "{JPN}きたえあげてきた!\p"
	.string "{JPN}おれに ちょうせん したいのか?\n"
	.string "{JPN}きみの ちからを みせてくれ!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "{JPN}おお! よそうより ずっと\n"
	.string "{JPN}でっかい なみを たててくれた!\p"
	.string "{JPN}おれは のまれちまったよ!\p"
	.string "{JPN}まいった まいった!\n"
	.string "{JPN}このジムバッジを とってくれ!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{JPN}{PLAYER}は トウキから\n"
	.string "{JPN}ナックルバッジを もらった!$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "{JPN}ナックルバッジが あれば\n"
	.string "{JPN}レベル30まで の ポケモンは\l"
	.string "{JPN}こうかんした ポケモンでも\n"
	.string "{JPN}いうことを きくように なる!\p"
	.string "{JPN}それに ひでんマシンの\n"
	.string "{JPN}フラッシュが たたかいがいでも\l"
	.string "{JPN}つかえるように なるぞ!\pよかったら この\nわざマシンも つかってくれ!$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "{JPN}そのわざマシン08には ビルドアップが\n"
	.string "{JPN}はいってる.\p"
	.string "{JPN}こうげきと ぼうぎょの りょうほうを\n"
	.string "{JPN}あげる わざだよ.\p... ... ... ... ... ...$"
DewfordTown_Gym_Text_RegisteredBrawly:
	.string "{JPN}ポケナビに ジムリーダー\n"
	.string "{JPN}トウキを とうろくした!$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "{JPN}きみの さいのうが いつか\n"
	.string "{JPN}おおきな なみと なって\l"
	.string "{JPN}トレーナーたちを おどろかせる\nあらしを おこすのが みえるよ!$"

DewfordTown_Gym_Text_GymStatue:
	.string "{JPN}ムロタウン ポケモンジム$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "{JPN}ムロタウン ポケモンジム\p"
	.string "{JPN}トウキ こうにん トレーナー:\n"
	.string "{JPN}{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "{JPN}トウキ: なみは ひいても かならず\n"
	.string "{JPN}きしべに もどってくる.\n"
	.string "{JPN}きみのような おおきな さいのうの\n"
	.string "{JPN}なみは... もどってくると\n"
	.string "{JPN}おもってたよ!\p"
	.string "{JPN}どれだけ たかく のぼったか\nみせてくれ!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "{JPN}すげえ!\n"
	.string "{JPN}また のまれちまった!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "{JPN}トウキ: たたかいは ひろくて ふかい!\n"
	.string "{JPN}そこは みえないんだ!\l"
	.string "{JPN}まるで ホウエンの うみのように!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "{JPN}トウキ: なみは ひいても かならず\n"
	.string "{JPN}きしべに もどってくる.\n"
	.string "{JPN}きみのような おおきな さいのうの\n"
	.string "{JPN}なみは... もどってくると\n"
	.string "{JPN}おもってたよ!\p"
	.string "{JPN}あれ? たたかえる ポケモンが\n"
	.string "{JPN}いっぴき しか いないのかい.\p"
	.string "{JPN}わるいけど すくなくとも\nにひきは つれてきて ほしいな.$"
