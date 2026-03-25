FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_LOIS, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_RAY, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_CHARLES, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_CHUCK_2, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_JIN, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}よう ちょうしはどうだい \n"
	.string "{JPN}チャンピオンを めざす {PLAYER}!\p"
	.string "{JPN}ヒワマキジムリーダーの ナギは\n"
	.string "{JPN}ひこうタイプの ポケモンの\l"
	.string "{JPN}たつじんだよ.\p"
	.string "{JPN}かいてんドアの おくで\n"
	.string "{JPN}きみを まっている.\p"
	.string "{JPN}はばたこうとする\n"
	.string "{JPN}あたらしい ちょうせんしゃを\lまっているんだ!\pよし がんばれ!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}やったな!\n"
	.string "{JPN}りりく せいこうだ!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "{JPN}とりポケモンの\n"
	.string "{JPN}エレガントな たたかいスタイルを\lみるがいい!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "{JPN}きみは...\n"
	.string "{JPN}きみは つよい...$"
FortreeCity_Gym_Text_JaredPostBattle:
	.string "{JPN}トレーナーは よそくできない\n"
	.string "{JPN}できごとに ついていくために\l"
	.string "{JPN}かしこくなければ ならない.\p"
	.string "{JPN}われらのリーダーまで\nたどりつく あたまは\lきみに あるのかな?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "{JPN}とりポケモンを あいする ものたちが\n"
	.string "{JPN}このジムに はいることを\l"
	.string "{JPN}あこがれているのだ.\p"
	.string "{JPN}ヒワマキジムの いちいんとして\nまけることは ゆるされない!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "{JPN}わたしには おもすぎる\n"
	.string "{JPN}あいてだった...$"
FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "{JPN}せかいは ひろくて\n"
	.string "{JPN}かぞえきれないほどの\l"
	.string "{JPN}つよいトレーナーが いる.\p"
	.string "{JPN}おれは くんれんを つづけて\nもっと つよくなるつもりだ.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "{JPN}われらのジムリーダー ナギが\n"
	.string "{JPN}きみの あいてを する\l"
	.string "{JPN}ひつようなんて ない!\pおれで じゅうぶんだ!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "{JPN}ナギ! ぼくは...\n"
	.string "{JPN}ぼくは まけた!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "{JPN}ナギは かわいくて つよい.\n"
	.string "{JPN}さいこうの リーダーだ!\p"
	.string "{JPN}てれる...$"
FortreeCity_Gym_Text_AshleyIntro:
	.string "{JPN}ナギが じきじきに\n"
	.string "{JPN}おしえてくれたのよ!\nかんたんには かてないわ!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "{JPN}まけてしまった...$"
FortreeCity_Gym_Text_AshleyPostBattle:
	.string "{JPN}ナギの おかげで\n"
	.string "{JPN}ヒワマキの ひとたちは\lふあんなく くらせるのよ.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "{JPN}ナギが たたかうとき かのじょの\n"
	.string "{JPN}かおは うつくしい けついで\l"
	.string "{JPN}かがやく...\p"
	.string "{JPN}そんな すてきな すがたを\nきみには みせないぞ!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "{JPN}うっ!\n"
	.string "{JPN}とめられなかった.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "{JPN}きを つけたほうが いいぞ!\n"
	.string "{JPN}ナギを みつめて きが\l"
	.string "{JPN}ちってしまわないように!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "{JPN}ひこうタイプの ポケモンには\n"
	.string "{JPN}いろんな しゅるいが いることを\l"
	.string "{JPN}しっているだろうな?\pしってるよな?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "{JPN}きみは よく しっているようだ!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "{JPN}たしかに きみに まけたよ.\n"
	.string "{JPN}しかし きを つけろよ! われらの\l"
	.string "{JPN}リーダー ナギの ポケモンは\lほんきだからな.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "{JPN}わたしは ナギ.ヒワマキジムの\n"
	.string "{JPN}リーダーです.\p"
	.string "{JPN}とりポケモンと ひとつになり\n"
	.string "{JPN}そらを まいあがってきました...\p"
	.string "{JPN}どんなに きびしい たたかいでも\n"
	.string "{JPN}ゆうがに しょうりしてきました...\p"
	.string "{JPN}とりポケモンと わたしの\n"
	.string "{JPN}うつくしい れんけいを みよ!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "{JPN}わたしより ゆうがに ポケモンを\n"
	.string "{JPN}しきする トレーナーを みたのは\l"
	.string "{JPN}はじめてです...\p"
	.string "{JPN}あなたの ちからを みとめ\n"
	.string "{JPN}この ジムバッジを おわたしします.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{JPN}{PLAYER}は ナギから\n"
	.string "{JPN}フェザーバッジを てにいれた!$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "{JPN}フェザーバッジが あれば レベル70\n"
	.string "{JPN}までの ポケモンは こうかんで\l"
	.string "{JPN}もらったものでも いうことをききます.\p"
	.string "{JPN}ひこうタイプの ポケモンなら\n"
	.string "{JPN}そのわざを おぼえていなくても\l"
	.string "{JPN}そらをとぶが つかえるように\l"
	.string "{JPN}なります.\p"
	.string "{JPN}そして これは...\n"
	.string "{JPN}わたしからの おくりものです.$"
	.string ""

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "{JPN}わざマシン40には つばめがえしが\n"
	.string "{JPN}はいっています.\p"
	.string "{JPN}そのスピード...\n"
	.string "{JPN}どんなポケモンも よけられません.\p... ... ... ... ... ...$"
FortreeCity_Gym_Text_RegisteredWinona:
	.string "{JPN}ジムリーダー ナギを\n"
	.string "{JPN}ポケナビに とうろくした.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "{JPN}あなたに やぶれたけれど\n"
	.string "{JPN}とりポケモンへの あいを\lわすれることは ありません.$"

FortreeCity_Gym_Text_GymStatue:
	.string "{JPN}ヒワマキシティ ポケモンジム$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "{JPN}ヒワマキシティ ポケモンジム\p"
	.string "{JPN}ナギ こうにん トレーナー:\n"
	.string "{JPN}{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "{JPN}ナギ: わたしたち にんげんは\n"
	.string "{JPN}じゅうりょくに ひかれて\l"
	.string "{JPN}ちじょうから のがれられない.\p"
	.string "{JPN}でも たかい りそうを\n"
	.string "{JPN}めざすことで そらに\l"
	.string "{JPN}はばたく ちからを てに\l"
	.string "{JPN}いれることが できるの!\p"
	.string "{JPN}あなたは ちょうじょうを\nきわめて チャンピオンの\lざに ついている.\pどうか あなたの ちからを\nぜんりょくで みせて\lくださいな!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "{JPN}また あなたの たかさに\nとどかなかった...$"
FortreeCity_Gym_Text_WinonaPostRematch:
	.string "{JPN}ナギ: まけてしまったけれど\n"
	.string "{JPN}こころの つばさは\l"
	.string "{JPN}おれていません.\p"
	.string "{JPN}また たちあがって\n"
	.string "{JPN}そらに はばたくことが\lできるの.\nそう しんじています!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "{JPN}ナギ: わたしたち にんげんは\n"
	.string "{JPN}じゅうりょくに しばられ じめんを\l"
	.string "{JPN}はなれることが できません.\p"
	.string "{JPN}でも たかみを めざすことで\n"
	.string "{JPN}そらを まう ちからを\l"
	.string "{JPN}もつことができるのです!\p"
	.string "{JPN}あなたは チャンピオンとして\n"
	.string "{JPN}ちょうじょうに たっています.\p"
	.string "{JPN}ぜひとも あなたの ちからを\n"
	.string "{JPN}ぜんりょくで みせてください!\p"
	.string "{JPN}あら... ポケモンが 1ぴきしか\n"
	.string "{JPN}いないのですか?\pさいていでも 2ひきは つれて\nきてくださいね.$"
