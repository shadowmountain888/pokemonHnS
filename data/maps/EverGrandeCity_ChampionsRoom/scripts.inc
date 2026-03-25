.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	goto_if_set FLAG_WALLACE_REMATCH, EverGrandeCity_ChampionsRoom_EventScript_WallaceRematch
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_WallaceRematch::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRETA_BF_BRAIN, EverGrandeCity_ChampionsRoom_Text_Defeat2
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated2
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated2::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit2
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit2
	waitmovement 0
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_STEVEN_REMATCH
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_GARBAGEFLAG
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit2:
	walk_up
	delay_16
	walk_up
	delay_8
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit2:
	walk_up
	delay_8
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "{JPN}ミクリ: よくきたな {PLAYER}{KUN}.\p"
	.string "{JPN}ルネシティでの\n"
	.string "{JPN}あの じけん...\l"
	.string "{JPN}ひとりで あの きききを\n"
	.string "{JPN}おさめるとは みごとだった.\p"
	.string "{JPN}おっと!\p"
	.string "{JPN}きみ ひとりで きききを\n"
	.string "{JPN}おさめたと いうのは\n"
	.string "{JPN}こうへいじゃないな.\p"
	.string "{JPN}きみは ポケモンと\n"
	.string "{JPN}こころを ひとつにして\n"
	.string "{JPN}こんなんな じょうきょうを\n"
	.string "{JPN}のりこえたのだ.\p"
	.string "{JPN}わたしたち トレーナーは\n"
	.string "{JPN}ポケモンに どうぐを あたえたり\n"
	.string "{JPN}たたかいの わざを おしえたりして\n"
	.string "{JPN}ポケモンを そだてる.\p"
	.string "{JPN}しかし わたしたち じしんも\n"
	.string "{JPN}ポケモンから おおくの ことを\n"
	.string "{JPN}まなんでいるのだ.\p"
	.string "{JPN}そして ここは きみの せいかが\nほかの ものたちの せいかと\nくらべて ためされる ばしょ.\pさあ!\pだれが いちばん ゆうがに\nホウエンで じぶんの ポケモンと\nおどることが できるのか?\pいますぐ ここで みせて くれ!$"

EverGrandeCity_ChampionsRoom_Text_IntroSpeech2:
	.string "{JPN}ミクリ: よくきたな {PLAYER}{KUN}.\n"
	.string "{JPN}また あえて とても うれしいよ.\p"
	.string "{JPN}ひと めで わかる.\n"
	.string "{JPN}きみは まえとは ちがう.\n"
	.string "{JPN}つよく なったのか?\p"
	.string "{JPN}そうだ... そうだな. おお...\n"
	.string "{JPN}その めざしが つたわってくる...\p"
	.string "{JPN}よし きみは すでに\n"
	.string "{JPN}この たたかいの じゅんびが\n"
	.string "{JPN}できているのが わかった.\p"
	.string "{JPN}きみが わたしの リズムで\n"
	.string "{JPN}おどれるか みせて もらおう.\pきみが ホウエンで いちばん\nつよい ポケモントレーナーだと\nしょうめいして みせろ!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "{JPN}わたし チャンピオンが\n"
	.string "{JPN}はいぼく した...\p"
	.string "{JPN}みごとな たたかいだった.\n"
	.string "{JPN}きみは ゆうがで いらだたしく\n"
	.string "{JPN}そして まったく すばらしかった!\p"
	.string "{JPN}でかした {PLAYER}{KUN}!\p"
	.string "{JPN}きみは しんに きこうな\nポケモントレーナーだ!$"

EverGrandeCity_ChampionsRoom_Text_Defeat2:
	.string "{JPN}わたし チャンピオンが\n"
	.string "{JPN}はいぼく した...\p"
	.string "{JPN}またしても! すばらしい.\n"
	.string "{JPN}みごとな たたかいだった.\n"
	.string "{JPN}きみは ゆうがで いらだたしく\n"
	.string "{JPN}そして まったく すばらしかった!\n"
	.string "{JPN}ふたたび でかした {PLAYER}{KUN}!\pきみは まさに ホウエンで\nsいこうの ポケモントレーナーだ!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "{JPN}ミクリ: きみが たたかいに\n"
	.string "{JPN}おくりだした ポケモンたちは...\p"
	.string "{JPN}ときには はるかぜの ように\n"
	.string "{JPN}まい ときには いなずまの\n"
	.string "{JPN}ように うちこんだ.\p"
	.string "{JPN}かろやかでいて しかも\n"
	.string "{JPN}あしどり しっかりと\n"
	.string "{JPN}ゆうがに ポケモンを みちびいた.\n"
	.string "{JPN}わたしも きみの みごとな\n"
	.string "{JPN}えんぎに みとれて しまった!\n"
	.string "{JPN}きみは いま ポケモンリーグの\n"
	.string "{JPN}えいこうな ちょうてんに\n"
	.string "{JPN}たって いる.\nわたしは きみを あたらしい\nホウエンちほうの...$"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech2:
	.string "{JPN}ミクリ: きみが たたかいに\n"
	.string "{JPN}おくりだした ポケモンたちは...\p"
	.string "{JPN}せかいじゅうで わたしが\n"
	.string "{JPN}ならった さまざまな ダンスを\n"
	.string "{JPN}おもいださせる.\n"
	.string "{JPN}かれらの うごきは まばゆく\n"
	.string "{JPN}えんぎは それ いじょうだった.\n"
	.string "{JPN}きみは いま ふたたび\n"
	.string "{JPN}ポケモンリーグの えいこうな\n"
	.string "{JPN}ちょうてんに たって いる!\n"
	.string "{JPN}わたしは きみを あたらしい\n"
	.string "{JPN}ホウエンちほう チャンピオンと\nせんげん しよう...!\nすでに チャンピオンで\nなければの はなしだが!$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "{JPN}ハルカ: {PLAYER}{KUN}!\p"
	.string "{JPN}チャンピオンに ちょうせんする\n"
	.string "{JPN}まえに アドバイスが あるの...$"
EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "{JPN}ハルカ: えっ?\n"
	.string "{JPN}なに なに なに?\p"
	.string "{JPN}{PLAYER}{KUN}...\n"
	.string "{JPN}もしかして...\n"
	.string "{JPN}もう おわったの?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "{JPN}ユウキ: {PLAYER}!\p"
	.string "{JPN}チャンピオンに ちょうせんする\n"
	.string "{JPN}まえに アドバイスが ほしいか?...$"
EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "{JPN}ユウキ: {PLAYER}...\p"
	.string "{JPN}もしかして きみ...\n"
	.string "{JPN}チャンピオンに かったのか?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "{JPN}オダマキはかせ: ほら?\n"
	.string "{JPN}いった とおりでしょ シルバー?\p"
	.string "{JPN}{PLAYER}{KUN}の ことは\n"
	.string "{JPN}しんぱい いらないって\n"
	.string "{JPN}いった でしょ?\n"
	.string "{JPN}... ... ... ... ... ... ... ...\n"
	.string "{JPN}{PLAYER}{KUN} ついに やったね.\n"
	.string "{JPN}カナズミジムで じぶんの\n"
	.string "{JPN}ちちおやを たおしたと きいて\n"
	.string "{JPN}もしかしたらと おもったが...\n"
	.string "{JPN}まさか ほんとうに\n"
	.string "{JPN}チャンピオンに なるとは!\n"
	.string "{JPN}ああ そうだ!\n"
	.string "{JPN}ポケモンずかんは どう なった?\nちょっと みせて くれるかい.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "{JPN}オダマキはかせ: とにかく \n"
	.string "{JPN}おめでとう!\p"
	.string "{JPN}さあ どうどうと さいごの\nへやに いくんじゃ!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "{JPN}ミクリ: {PLAYER}{KUN}...\p"
	.string "{JPN}いや きちんと いいなおそう.\n"
	.string "{JPN}あたらしい チャンピオン!\n"
	.string "{JPN}わたしと いっしょに きて くれ.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "{JPN}ミクリ: すまないが...\p"
	.string "{JPN}ここから さきは チャンピオンに\n"
	.string "{JPN}なった トレーナーだけが\n"
	.string "{JPN}はいることが できる.\n"
	.string "{JPN}オダマキはかせと いっしょに\nそとで まっていて くれ.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "{JPN}ハルカ: うう...\n"
	.string "{JPN}... ... ... ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ... ... ...\n"
	.string "{JPN}じょうだんよ! だいじょうぶ!\n"
	.string "{JPN}それが ルールなんだもん!\n"
	.string "{JPN}{PLAYER}{KUN}!\n"
	.string "{JPN}ほんとうに おめでとう!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "{JPN}ユウキ: えええええ?! ... ... ... ... ...\n"
	.string "{JPN}... ... ... ... ... ... ... ...\n"
	.string "{JPN}ルールなら しかたないな.\n"
	.string "{JPN}{PLAYER} やったじゃないか!\n"
	.string "{JPN}おめでとう!$"

