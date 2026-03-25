.set LOCALID_LEAGUE_LANCE, 1
.set LOCALID_LEAGUE_MARY, 2
.set LOCALID_LEAGUE_OAK, 3

PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChampionRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	special DoPokemonLeagueLightingEffect
	end

ChampionRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, ChampionRoom_CloseDoor
	.2byte 0

ChampionRoom_CloseDoor::
	lock
	setflag FLAG_TEMP_2
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, ChamionRoom_Movement_Enter
	waitmovement 0
	setvar VAR_TEMP_0, 1
	release
	end

ChamionRoom_Movement_Enter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ChampionRoom_Trigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

PokemonLeague_WillsRoom_EventScript_Lance::
	lockall
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_WillsRoom_EventScript_LanceRematch
	msgbox PokemonLeague_ChampionsRoom_Text_BattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_1, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto

PokemonLeague_WillsRoom_EventScript_LanceRematch::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchBattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_2, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto

PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 40
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 60
	msgbox PokemonLeague_ChampionsRoom_Text_MaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME, 0
	releaseall
	end

PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 40
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 60
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME, 0
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest
	waitmovement 0
	return

PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast:
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth:
	walk_left
	walk_down
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest:
	walk_down
	walk_left
	face_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceMoveOver:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_2
	walk_in_place_fast_down
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryMoveOver:
	walk_left
	face_right
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryInterview:
	walk_fast_up
	walk_in_place_fast_right
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceAnxious:
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_left
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceLeave:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PokemonLeague_ChampionsRoom_Text_RematchBattleIntro:
    .string "{JPN}ワタル: おかえり!\p"
	.string "{JPN}きみは ジョウトで\n"
    .string "{JPN}じぶんの ちからを しょうめいし\p"
	.string "{JPN}8つの バッジを すべて しゅとくし\n"
    .string "{JPN}わたしを いちど やぶった.\p"
	.string "{JPN}しかし いまや きみは\n"
    .string "{JPN}おおきな リーグに いる.\p"
	.string "{JPN}カントー リーグだ!\p"
    .string "{JPN}この ちいきには どくじの\n"
	.string "{JPN}しれんと チャンピオンが いる.\p"
    .string "{JPN}ここでは わたしが さいごの\n"
	.string "{JPN}ちょうせんで いぜんより つよい\l"
    .string "{JPN}チームで たたかう.\p"
	.string "{JPN}これが しんの しけんで\n"
    .string "{JPN}カントーの チャンピオンを\n"
	.string "{JPN}きめる たたかいだ.\p"
    .string "{JPN}この あたらしい ちょうせんに\n"
	.string "{JPN}たちむかう じゅんびは いいか?\p"
    .string "{JPN}もういちど じぶんの ちからを\n"
	.string "{JPN}しょうめいする きは あるか?\nジョウトを せいふくした\nちからを みせてくれ チャンピオン!$"

PokemonLeague_ChampionsRoom_Text_BattleIntro:
    .string "{JPN}ワタル: きみをまっていたよ.\p"
	.string "{JPN}{PLAYER}!\p"
    .string "{JPN}きみならその うでまえで\n"
	.string "{JPN}かならず ここまで やってくると\n"
    .string "{JPN}おもっていた.\p"
	.string "{JPN}もう なにも いうことはない.\p"
    .string "{JPN}ふたりの うち どちらが\n"
	.string "{JPN}つよいか はっきりさせよう.\n"
    .string "{JPN}さいきょうの トレーナーとして\n"
	.string "{JPN}ポケモンリーグ チャンピオンとして...\p"
    .string "{JPN}りゅうつかい ワタル\nきみの ちょうせんを うけて たつ!$"

PokemonLeague_ChampionsRoom_Text_BattleWin:
    .string "{JPN}おわったな.\p"
	.string "{JPN}しかし ふしぎな きもちだ.\p"
    .string "{JPN}まけたことに たいして\n"
	.string "{JPN}いかりは かんじない.\n"
    .string "{JPN}むしろ うれしいくらいだ.\p"
	.string "{JPN}あたらしい チャンピオンの\nたんじょうを みることが\nできて よかった!$"

PokemonLeague_ChampionsRoom_Text_BattleAfter:
    .string "{JPN}ふう.\p"
	.string "{JPN}{PLAYER}よ\n"
    .string "{JPN}きみは ほんとうに つよくなった.\p"
	.string "{JPN}きみの ポケモンたちが\n"
    .string "{JPN}きみの まっすぐな こころに\n"
	.string "{JPN}こたえているのだ.\p"
    .string "{JPN}トレーナーとして きみは\nポケモンとともに\nさらに せいちょうしていくだろう.$"

PokemonLeague_ChampionsRoom_Text_MaryOhNoOak:
    .string "{JPN}メアリー: たいへん!\n"
	.string "{JPN}もう おわっちゃった!\pオーキドはかせが\nのろまだから...$"
PokemonLeague_ChampionsRoom_Text_OakCongratulations:
    .string "{JPN}オーキドはかせ: おお {PLAYER}!\p"
	.string "{JPN}ながい あいだだったな.\p"
    .string "{JPN}きみは たしかに りっぱに\n"
	.string "{JPN}なったようだ.\n"
    .string "{JPN}ジョウト リーグの せいふくは\n"
	.string "{JPN}じつに すばらしい!\p"
    .string "{JPN}きみの でんしん しんらいと\n"
	.string "{JPN}ポケモンへの あいが これを\l"
    .string "{JPN}かのうに したのだ.\p"
	.string "{JPN}きみの ポケモンたちも\n"
    .string "{JPN}すばらしかった.\pかれらが きみを トレーナーと\nしんじていたからこそ\lがんばりぬけたのだ.\pおめでとう {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations:
    .string "{JPN}オーキドはかせ: おお {PLAYER}!\p"
	.string "{JPN}ウツギはかせが きみを\n"
    .string "{JPN}たびだたせてから ずっと\l"
	.string "{JPN}きみの しんぽを みてきた.\p"
    .string "{JPN}きみは たしかに りっぱに\n"
	.string "{JPN}なったな.\n"
    .string "{JPN}ジョウトと いまや カントー\n"
	.string "{JPN}りょうほうの リーグを\l"
    .string "{JPN}せいふくするとは なみたいてい\n"
	.string "{JPN}ではない.\p"
    .string "{JPN}きみは じつに よく やった!\p"
	.string "{JPN}きみの ポケモンが きみを\n"
    .string "{JPN}しんらいしていることは\l"
	.string "{JPN}あきらかで\p"
    .string "{JPN}その しんらいが きみの\n"
	.string "{JPN}せいこうの きばんに なった.\p"
    .string "{JPN}しかし おぼえておけ\nトレーナーの たびは けっして\lほんとうに おわることは ない.\nしょうりを おめでとう\n{PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_MaryInterview:
    .string "{JPN}メアリー: あたらしい ジョウト\n"
	.string "{JPN}チャンピオンに インタビュー\lしましょう!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryInterview:
    .string "{JPN}メアリー: あたらしい カントー\n"
	.string "{JPN}チャンピオンに インタビュー\lしましょう!$"

PokemonLeague_ChampionsRoom_Text_Noisy:
    .string "{JPN}ワタル: すこし\n"
	.string "{JPN}うるさく なってきたな...\p"
	.string "{JPN}{PLAYER}よ\nわたしと いっしょに きてくれるか?$"

PokemonLeague_ChampionsRoom_Text_MaryNoInterview:
    .string "{JPN}メアリー: あっ ちょっと!\n"
	.string "{JPN}インタビューが まだでした!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview:
    .string "{JPN}メアリー: もう! また インタビューを\n"
	.string "{JPN}すっぽかすなんて だめよ!$"

