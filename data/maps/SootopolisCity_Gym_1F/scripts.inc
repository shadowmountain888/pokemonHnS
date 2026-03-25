SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 6
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "{JPN}よお! ちょうしは どうだい\n"
	.string "{JPN}チャンピオンを めざす {PLAYER}!\p"
	.string "{JPN}ルネジムリーダー アダンは\n"
	.string "{JPN}みずタイプの ポケモンの たつじん\n"
	.string "{JPN}なんだ!\p"
	.string "{JPN}それに アダンに たどりつくには\n"
	.string "{JPN}こおりの ゆかが きみの じゃまを\n"
	.string "{JPN}するだろう...\p"
	.string "{JPN}わるいが これいじょうの\n"
	.string "{JPN}アドバイスは できないんだ!\pここから さきは きみ じしんで\nがんばって すすむしかないよ!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "{JPN}やったな!ホウエンで いちばん つよい\n"
	.string "{JPN}といわれた アダンにも かったんだ!\p"
	.string "{JPN}よし!トレーナーカードを\n"
	.string "{JPN}みてみろよ.\p"
	.string "{JPN}バッジを ぜんぶ あつめたなら \nポケモンリーグに いどめるぞ!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "{JPN}きみに ききたいことが ある.\n"
	.string "{JPN}しっているかね?\l"
	.string "{JPN}ああ はぐらかしては いけないな.\p"
	.string "{JPN}ミクリに ポケモンの すべてを\n"
	.string "{JPN}おしえたのは この わたしなのだ.\p"
	.string "{JPN}かつて わたしは ジムリーダーの\n"
	.string "{JPN}ちいを しりぞいた.\p"
	.string "{JPN}わたしの かわりに ミクリに\n"
	.string "{JPN}ジムを まかせた.\p"
	.string "{JPN}しかし やむをえない りゆうで\n"
	.string "{JPN}ふっきする ことになったのだ.\p"
	.string "{JPN}ああ だが むだばなしは\n"
	.string "{JPN}このくらいに しよう.\p"
	.string "{JPN}きみには われわれの げいじゅつを\n"
	.string "{JPN}みてもらおう.\p"
	.string "{JPN}ポケモンと わたしが つくりだす\n"
	.string "{JPN}みずの だいげんそう!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "{JPN}あはははは すばらしい!\n"
	.string "{JPN}みごとだ きみの かちだ!\p"
	.string "{JPN}きみからは すべてを のりこえる\n"
	.string "{JPN}かがやく わざの かがやきを\n"
	.string "{JPN}かんじるよ!\p"
	.string "{JPN}しかし わたしや ミクリに\n"
	.string "{JPN}くらべれば きみには じょうひんさが\n"
	.string "{JPN}たりないね!\p"
	.string "{JPN}わたしの ようふくを かしてあげ\n"
	.string "{JPN}ようかな?\p"
	.string "{JPN}... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ...\p"
	.string "{JPN}はははは ただの じょうだんだよ!\pふくより むしろ ほうびとして\nこれを あげよう レインバッジを!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{JPN}{PLAYER}は アダンから\n"
	.string "{JPN}レインバッジを もらった!$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "{JPN}レインバッジを もてば きみの\n"
	.string "{JPN}ポケモンは すべて きみの めいれいに\n"
	.string "{JPN}かんぜんに したがってくれるよ!\p"
	.string "{JPN}レインバッジは ひでんマシン\n"
	.string "{JPN}たきのぼりを つかって\n"
	.string "{JPN}たきを のぼることも かのうにする!\p"
	.string "{JPN}そして われわれの たたかいを\n"
	.string "{JPN}わすれないよう これを もっていけ...$"
SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "{JPN}きみに わたした わざマシンには\n"
	.string "{JPN}みずのはどうが はいっている!\p"
	.string "{JPN}つかえば ちょうおんぱで あいてを\n"
	.string "{JPN}こんらん させることが あるんだ!\p"
	.string "{JPN}... ... ... ... ... ...$"
SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "{JPN}ジムリーダー アダンを\n"
	.string "{JPN}ポケナビに とうろくした.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "{JPN}ホウエンちほうの ジムバッジを\n"
	.string "{JPN}すべて あつめた トレーナーは\l"
	.string "{JPN}さいしゅうてきちへ むかうがよい.\p"
	.string "{JPN}ポケモンリーグだ.\p"
	.string "{JPN}ホウエンの いちばん ひがしにある\n"
	.string "{JPN}ダイゴのしまへ いくがよい.\p"
	.string "{JPN}そこに ポケモンリーグが ある.$"
	.string ""

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "{JPN}ホウエンちほうには あと ひとつ\n"
	.string "{JPN}バッジが のこっている.\p"
	.string "{JPN}ポケモンリーグに いどむなら\n"
	.string "{JPN}ヒワマキシティの ジムで\l"
	.string "{JPN}さいごの バッジを てにいれるのだ.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "{JPN}ルネシティ ポケモンジム$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "{JPN}ルネシティ ポケモンジム\p"
	.string "{JPN}アダンこうにん トレーナー:\n"
	.string "{JPN}{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "{JPN}アダン: ああ このジムは いつもの\n"
	.string "{JPN}しずけさを とりもどして いたのに...\p"
	.string "{JPN}でも わかい たいふうが もどってきて\n"
	.string "{JPN}また われわれを しれんに かけるのか!\p"
	.string "{JPN}よし ともよ! もちろんだとも!\p"
	.string "{JPN}きみが のぞむかぎり なんどでも\n"
	.string "{JPN}よろこんで おどろうではないか!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "{JPN}あははは きみの かちだ!\n"
	.string "{JPN}またしても やぶれてしまったよ!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "{JPN}アダン:わたしの でしに ならないかと\n"
	.string "{JPN}いったところで ことわるだろうな.\p"
	.string "{JPN}わたしの コートを きみに\n"
	.string "{JPN}ゆずりたいのだが.\p"
	.string "{JPN}それも やはり ことわるだろう.\n"
	.string "{JPN}そう おもう.\p"
	.string "{JPN}それこそ わがともよ きみの\n"
	.string "{JPN}こうけつさの あかしなのだ!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "{JPN}アダン: ああ このジムは いつもの\n"
	.string "{JPN}しずけさを とりもどして いたのに...\p"
	.string "{JPN}でも わかい たいふうが もどってきて\n"
	.string "{JPN}また われわれを しれんに かけるのか!\p"
	.string "{JPN}よし ともよ! もちろんだとも!\n"
	.string "{JPN}よろこんで きみと おどろう...\p"
	.string "{JPN}あ いや いや いや\n"
	.string "{JPN}きみは ポケモンを 1ひきしか\n"
	.string "{JPN}つれていない!\p"
	.string "{JPN}2ひき できれば もっと おおくの\nポケモンを つれて きてくれたまえ!$"

