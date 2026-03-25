MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_GARBAGEVAR
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_CARLENE, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}やあ げんきかい?\n"
	.string "{JPN}チャンピオンをめざす\n"
	.string "{JPN}{PLAYER}くん!\p"
	.string "{JPN}キンセツジムのリーダー\n"
	.string "{JPN}テッセンは\n"
	.string "{JPN}でんきタイプのポケモンを\n"
	.string "{JPN}つかうんだ!\p"
	.string "{JPN}みずタイプのポケモンで\n"
	.string "{JPN}ちょうせんすると\nびりびりやられちゃうよ!\pそれに スイッチで\nあやつるドアを\nジムじゅうにつけてるんだ!\nへんてこなやつだ!\pがんばれ!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}わあ でんげきてきだ!\n"
	.string "{JPN}ドアがあいたよ!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "{JPN}おれのでんきのこころが\n"
	.string "{JPN}きみのゆめを\nばらばらにするぜ!\nうおー イエーイ!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "{JPN}それはプラグイン \n"
	.string "{JPN}アンプアップ \nオーバードライブな\nでんきだったぜ!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "{JPN}ポケモンとロック \n"
	.string "{JPN}すべてはハートだ!\nうおー イエー!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "{JPN}おれはテッセンのもとで\n"
	.string "{JPN}しゅぎょうしたんだ!\nかんたんにはまけないぞ!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "{JPN}でんげんが きれちゃった...$"
MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "{JPN}ジムリーダーのテッセンは\n"
	.string "{JPN}ながい ながいあいだ\n"
	.string "{JPN}ここにいるんだ.\p"
	.string "{JPN}きみのおとうさんがうまれる\nまえからたたかってたんだぜ.\nつよいじいさんだ.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "{JPN}このジムにはパズルがあるよ!\n"
	.string "{JPN}たのしくない?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "{JPN}まけるのは つまらないな...$"
MauvilleCity_Gym_Text_BenPostBattle:
	.string "{JPN}テッセンはスイッチをつかった\n"
	.string "{JPN}ちいさなしかけをつくるのが\nすきなんだって.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "{JPN}わたしのみりょくと\n"
	.string "{JPN}ポケモンのわざで\nびっくりするわよ!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "{JPN}あなたのつよさに\nびっくりしたわ!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "{JPN}キンセツシティは\n"
	.string "{JPN}テッセンがつくったって\n"
	.string "{JPN}きいたわ.\p"
	.string "{JPN}わたしたちがトレーナーに\n"
	.string "{JPN}なるまえから\nトレーナーだったのよ.\lいろんなことをしってるのね!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "{JPN}ぼく ひかるもの\nだいすき!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "{JPN}ああ...\n"
	.string "{JPN}めが まわっちゃった...$"
MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "{JPN}キンセツジムのテッセンの\n"
	.string "{JPN}おでこはひかってるよ.\nうれしいなあ!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "{JPN}まちをかいぞうするけいかくは\n"
	.string "{JPN}あきらめたのじゃ.\p"
	.string "{JPN}それで ジムにドアの\n"
	.string "{JPN}しかけをつくることに\n"
	.string "{JPN}じかんをかけておるのじゃ.\p"
	.string "{JPN}おお?なにをしにきたのじゃ?\p"
	.string "{JPN}なに?わしのしかけドアを\n"
	.string "{JPN}ぜんぶとおりぬけてきた\n"
	.string "{JPN}というのか?\p"
	.string "{JPN}わははははは!\n"
	.string "{JPN}これはおもしろい!\pならば このテッセン \nキンセツジムのリーダーが\nきみをびりびりにしてやる!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "{JPN}わははははは!\n"
	.string "{JPN}まいった まいった!\p"
	.string "{JPN}きみはわしをどきどき\n"
	.string "{JPN}させてくれたわい!\nこのバッジをうけとりなさい!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{JPN}{PLAYER}は テッセンから\n"
	.string "{JPN}ダイナモバッジを もらった!$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "{JPN}ダイナモバッジが あれば\n"
	.string "{JPN}いわくだきを せんとうがいでも\l"
	.string "{JPN}つかえるように なるんじゃ\p"
	.string "{JPN}それに きみの ポケモンも\n"
	.string "{JPN}すこし はやくなるぞい\p"
	.string "{JPN}うーむ...\nこれも もっていくがよい!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "{JPN}そこの わざマシン34には\n"
	.string "{JPN}10まんボルトが はいっとる\p"
	.string "{JPN}ぜったいに はずれない\n"
	.string "{JPN}しんらいできる わざじゃ!\p... ... ... ... ... ...$"
MauvilleCity_Gym_Text_RegisteredWattson:
	.string "{JPN}ジムリーダー テッセンを\n"
	.string "{JPN}ポケナビに とうろくした!$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "{JPN}きみのようなゆうぼうな\n"
	.string "{JPN}わかいトレーナーをみると\nきぼうでいっぱいじゃよ!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "{JPN}わははははは!\n"
	.string "{JPN}がんばるんじゃぞ わかいの!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "{JPN}キンセツシティ ポケモンジム$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "{JPN}キンセツシティ ポケモンジム\p"
	.string "{JPN}テッセンこうにんトレーナー:\n"
	.string "{JPN}{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "{JPN}テッセン:おお!やっときたか!\n"
	.string "{JPN}なにがしたいかわかるぞい.\l"
	.string "{JPN}わしのポケモンとたたかいたい\n"
	.string "{JPN}のじゃろう!\p"
	.string "{JPN}わははははは!\p"
	.string "{JPN}きみをびりびりにしてやるぞ!\nけいこくしたからな!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "{JPN}うう...\n"
	.string "{JPN}でんちが きれてしまった...$"
MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "{JPN}テッセン:また でんちを\n"
	.string "{JPN}じゅうでんしなおさんとな.\p"
	.string "{JPN}じゅうでんがかんりょうしたら\n"
	.string "{JPN}よろこんでちょうせんをうけよう.\p"
	.string "{JPN}また きてくれるじゃろう?$"
	.string ""

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "{JPN}テッセン:おお!やっときたか!\n"
	.string "{JPN}なにがしたいかわかるぞい.\l"
	.string "{JPN}わしのポケモンとたたかいたい\n"
	.string "{JPN}のじゃろう!\p"
	.string "{JPN}わははははは!\p"
	.string "{JPN}おっと!まてまて!\n"
	.string "{JPN}ポケモンをひとひきしか\n"
	.string "{JPN}もってないじゃないか!\nにひきいじょうもってきて\nくれんかの?$"

