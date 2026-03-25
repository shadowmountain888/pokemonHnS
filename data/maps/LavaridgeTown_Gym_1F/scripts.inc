.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_RUSSELL, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_COREY, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_JIM, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_RUSSELL, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_COREY, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_JIM, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_PING, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_GARBAGEVAR, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_PING, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COREY, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JIM, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_RUSSELL, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KOGA_2, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "{JPN}よう ちょうしはどうだい\n"
	.string "{JPN}チャンピオンをめざす\l"
	.string "{JPN}{PLAYER}よ?\p"
	.string "{JPN}フエンタウンのジムリーダー\n"
	.string "{JPN}アスナは ほのおタイプの\l"
	.string "{JPN}ポケモンをつかうぞ!\p"
	.string "{JPN}ポケモンへのじょうねつは\n"
	.string "{JPN}かざんよりも あつく もえている\l"
	.string "{JPN}んだ!\pちかづきすぎると やけどするぞ!\nみずでけしてから\lアタックだ!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "{JPN}うわあ! あっついバトルだったぜ!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "{JPN}あついあついあつい!\n"
	.string "{JPN}うわあ あつい!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "{JPN}あせがめにはいって\nまえがみえない...$"
LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "{JPN}あつい すなに うまると\n"
	.string "{JPN}けつえきじゅんかんが よくなるんだ\p"
	.string "{JPN}かんせつの いたみを なおすのに\n"
	.string "{JPN}こうかてきなんだぞ$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "{JPN}おれは ストレスかいしょうちゅうだ\n"
	.string "{JPN}じゃまして ストレスをあたえるな!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "{JPN}アスナに もえつくされろ!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "{JPN}はあああ... ふう...\p"
	.string "{JPN}あついすなにながいあいだ\n"
	.string "{JPN}うもれてると つかれちゃうよ...$"
LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "{JPN}きみも つかれたろう\n"
	.string "{JPN}あつい すなで やすみたいだろ?\p"
	.string "{JPN}でも いしりょくを たもつことは\n"
	.string "{JPN}すべての トレーナーにとって\l"
	.string "{JPN}たいせつな のうりょくなんだ$"
	.string ""

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "{JPN}ひであそんで ひにやけた...$"
LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "{JPN}きみのうではほんものだ...\n"
	.string "{JPN}でもぼくらのリーダー アスナはつよい\p"
	.string "{JPN}きをつけないと\n"
	.string "{JPN}ひどくやけどするぞ$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "{JPN}きみの ポケモンは 200どの\n"
	.string "{JPN}あつさに たえられるかな?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "{JPN}じゅうぶんにあつく\nもえなかった...$"
LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "{JPN}マグマの おんどは 200ど\n"
	.string "{JPN}きみの ポケモンが かったから\l"
	.string "{JPN}マグマでも いきのこれるだろうな$"
	.string ""

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "{JPN}えーと...\n"
	.string "{JPN}よし あなたとたたかうわ$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "{JPN}あら でも きみは つよすぎるわ$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "{JPN}わたし アスナみたいに\n"
	.string "{JPN}きれいで つよい トレーナーに\lなるのよ$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "{JPN}さあ やるぞ!\n"
	.string "{JPN}きもちが さめないうちに\lいこうぜ!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "{JPN}こんなにあついのに\n"
	.string "{JPN}こころはこおりにつつまれてる...$"
LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "{JPN}きみの なかに もえる\n"
	.string "{JPN}たたかいの こころ...\l"
	.string "{JPN}リーダーに かてるかもな$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "{JPN}ほのおが はげしく もえてるだろ?\n"
	.string "{JPN}おれの しょうりを きたいして\lもえてるんだ!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "{JPN}なにかが うまくいかなかった$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "{JPN}だからなんだっていうんだ!\n"
	.string "{JPN}おれはあついたんのうえを\n"
	.string "{JPN}はだしであるけるぞ!\pぜったいにまねしようと\nおもうなよ!$"
LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "{JPN}やまが だいすきだけど\n"
	.string "{JPN}とくに かざんが すきなんだ$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "{JPN}うーん いちども ゆうせいに\n"
	.string "{JPN}たてなかった みたいだ$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "{JPN}アスナの ちからに あこがれて\n"
	.string "{JPN}ここに いるんだ\p"
	.string "{JPN}へへへへ$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "{JPN}ようこそ... いや ちがう\p"
	.string "{JPN}よわっちいトレーナー\n"
	.string "{JPN}ここまできてくれてうれしいよ!\n"
	.string "{JPN}わたしはまかされて... いや ちがう\p"
	.string "{JPN}わたしアスナ!\n"
	.string "{JPN}ここのジムリーダーよ!\n"
	.string "{JPN}えーと...\n"
	.string "{JPN}リーダーになって まだみじかいけど\n"
	.string "{JPN}あなどっちゃだめよ!\n"
	.string "{JPN}おじいちゃんからうけついだ\n"
	.string "{JPN}わざで このとちできたえた\n"
	.string "{JPN}あついうごきをみせてあげる!$"
	.string ""

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "{JPN}あー...\n"
	.string "{JPN}ちょっとがんばりすぎちゃった...\n"
	.string "{JPN}わたし... さいきん\n"
	.string "{JPN}ジムリーダーになったばかりなの\p"
	.string "{JPN}じぶんらしくない\n"
	.string "{JPN}ひとになろうとしすぎた\p"
	.string "{JPN}しぜんなやりかたで\n"
	.string "{JPN}やらなきゃだめね\n"
	.string "{JPN}そうしないと ポケモンが\n"
	.string "{JPN}まよっちゃうもの\nそれをおしえてくれて ありがとう\nそのおれいに これをあげる$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{JPN}{PLAYER}は アスナから\n"
	.string "{JPN}ヒートバッジを もらった!$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "{JPN}ヒートバッジが あれば\n"
	.string "{JPN}レベル50まで ほかの ひとから\l"
	.string "{JPN}こうかんで もらった ポケモンも\l"
	.string "{JPN}かんぜんに いうことをきくわ\p"
	.string "{JPN}それに ひでんマシン かいりきを\n"
	.string "{JPN}せんとう いがいでも つかえるのよ\p"
	.string "{JPN}これは かんしゃの しるし\n"
	.string "{JPN}えんりょしないで もらって!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "{JPN}そのわざマシン50は オーバーヒート\p"
	.string "{JPN}あいてに おおきな ダメージを\n"
	.string "{JPN}あたえる わざよ\p"
	.string "{JPN}でも つかった ポケモンの\n"
	.string "{JPN}とくこうが おおきく さがるの\l"
	.string "{JPN}ながい バトルには むかないかも$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "{JPN}ポケナビに ジムリーダー\n"
	.string "{JPN}アスナを とうろく しました$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "{JPN}あなたのちからって\n"
	.string "{JPN}だれかにそっくり...\n"
	.string "{JPN}あ! わかった! あなた\nトウカジムリーダーの\nセンリみたいにたたかうのね$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "{JPN}フエンタウン ポケモンジム$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "{JPN}フエンタウン ポケモンジム\p"
	.string "{JPN}アスナこうにん トレーナー\n"
	.string "{JPN}{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "{JPN}アスナ: たたかいにまけても\n"
	.string "{JPN}きがめいったりしない\p"
	.string "{JPN}ポケモンがすき\n"
	.string "{JPN}たたかうのがすき\n"
	.string "{JPN}そして... このジムがすき!\n"
	.string "{JPN}もういちど ちょうあつい\n"
	.string "{JPN}うごきをかわそうよ!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "{JPN}ふう!\n"
	.string "{JPN}ふんかする ちょくぜんよ!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "{JPN}フランネリー: しあいには\n"
	.string "{JPN}まけちゃったけど\l"
	.string "{JPN}まんぞくよ.\p"
	.string "{JPN}こんなに あつい\n"
	.string "{JPN}たたかいを たのしめるなんて\l"
	.string "{JPN}めったに ないもの.\pまた こんども\nこんな しあいを\lしましょうね!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "{JPN}アスナ: たたかいにまけても\n"
	.string "{JPN}きがめいったりしない\p"
	.string "{JPN}ポケモンがすき\n"
	.string "{JPN}たたかうのがすき\n"
	.string "{JPN}そして... このジムがすき!\n"
	.string "{JPN}もういちど ちょうあつい\n"
	.string "{JPN}うごきをかわそうよ!\p"
	.string "{JPN}あ ちょっとまって\n"
	.string "{JPN}たたかえるポケモンが\n"
	.string "{JPN}1ひきしかいないの?\p"
	.string "{JPN}いいにくいんだけど\nわたしにあいにくるときは\nすくなくとも 2ひき\nつれてきてね$"
