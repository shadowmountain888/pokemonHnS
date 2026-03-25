.set LOCALID_ROUTE25_MISTY, 10
.set LOCALID_ROUTE25_MAN, 11
.set LOCALID_ROUTE25_SUICUNE, 16
.set LOCALID_ROUTE25_EUSINE, 15
.set LOCALID_CAPE_MISTY, 20

Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route25_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, Route25_EventScript_SetSuicuneSceneMid
	end

Route25_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_ROUTE25_EUSINE, 65, 9
	end

Route25_EventScript_MistyRematch::
    lock
    faceplayer
    msgbox Route25_Text_Misty, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CAPE_MISTY
    removeobject LOCALID_CAPE_MISTY
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_MISTY
    release
    end

Route25_Text_Misty:
    .string "{JPN}カスミ: ここの ゆうやけって\n"
	.string "{JPN}さいこう!\l"
	.string "{JPN}がんばる きもちに なるの!\p"
	.string "{JPN}そうよ!\p"
	.string "{JPN}ほんきで みずタイプの きょうい\n"
	.string "{JPN}をみせつけてやるから\lかくとうどうじょうに きなさい!$"

Route25_EventScript_Dudley::
	trainerbattle_single TRAINER_DUDLEY Route25_Text_SchoolboyDudleySeen, Route25_Text_SchoolboyDudleyBeaten
	msgbox Route25_Text_SchoolboyDudleyAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Ellen::
	trainerbattle_single TRAINER_ELLEN Route25_Text_LassEllenSeen, Route25_Text_LassEllenBeaten
	msgbox Route25_Text_LassEllenAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joe::
	trainerbattle_single TRAINER_JOE Route25_Text_SchoolboyJoeSeen, Route25_Text_SchoolboyJoeBeaten
	msgbox Route25_Text_SchoolboyJoeAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA Route25_Text_LassLauraSeen, Route25_Text_LassLauraBeaten
	msgbox Route25_Text_LassLauraAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD Route25_Text_CamperLloydSeen, Route25_Text_CamperLloydBeaten
	msgbox Route25_Text_CamperLloydAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON Route25_Text_LassShannonSeen, Route25_Text_LassShannonBeaten
	msgbox Route25_Text_LassShannonAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Pat::
	trainerbattle_single TRAINER_PAT Route25_Text_SupernerdPatSeen, Route25_Text_SupernerdPatBeaten
	msgbox Route25_Text_SupernerdPatAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kevin::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE25_GOT_NUGGET, Route25_EventScript_KevinAfter
	msgbox Route25_Text_CooltrainerKevinNugget, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE25_GOT_NUGGET
	msgbox Route25_Text_CooltrainerKevinSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KEVIN, Route25_Text_CooltrainerKevinBeaten
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_KevinAfter::
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_NPC
	end

Route25_EventScript_BillsHouseSign::
	msgbox Route25_Text_BillsHouseSign, MSGBOX_SIGN
	end

Route25_Trigger_MistyRight::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveRight
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route25_EventScript_Misty
Route25_Trigger_MistyLeft::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveLeft
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route25_EventScript_Misty
Route25_EventScript_Misty::
	msgbox Route25_Text_MistyDate, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_MISTY
	removeobject LOCALID_ROUTE25_MAN
	setflag FLAG_HIDE_ROUTE25_MISTY
	clearflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	setflag FLAG_HIDE_CERULEAN_GYM_POKEMON
	setvar VAR_CERULEAN_CITY_STATE, 3
	release
	end

Route25_Trigger_SuicuneLeft::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_Trigger_SuicuneRight::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_EventScript_SuicuneMerge::
	clearflag FLAG_HIDE_ROUTE25_EUSINE
	addobject LOCALID_ROUTE25_EUSINE
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route25_Text_Eusine1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineSide
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Route25_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SUICUNE_ENCOUNTERS, 7
	release
	end
	
Route25_Text_Eusine1:
	.string "{JPN}ミナキ: はあ はあ...\n"
	.string "{JPN}きみには... かなわない.\p"
	.string "{JPN}...やはり そうだったか.\n"
	.string "{JPN}...\l"
	.string "{JPN}... いけ.\p"
	.string "{JPN}やけたとうで きみと であった\n"
	.string "{JPN}ときから なんとなく\l"
	.string "{JPN}スイクンは きみを えらぶと\l"
	.string "{JPN}おもっていた.$"

Route25_Text_Eusine2:
	.string "{JPN}みてみろ!\p"
	.string "{JPN}スイクンが きみを まっている!\n"
	.string "{JPN}じぶんを まかせられる ふさわしい\l"
	.string "{JPN}トレーナーとの たたかいを\l"
	.string "{JPN}まっているのだ!$"

Route25_Text_Eusine3:
	.string "{JPN}{PLAYER}...\n"
	.string "{JPN}きみたち ふたりは すばらしい...\p"
	.string "{JPN}これほど はくねつの たたかいを\n"
	.string "{JPN}みたことがない!\l"
	.string "{JPN}こうかいは まったく ない...\p"
	.string "{JPN}さらばだ スイクン!\n"
	.string "{JPN}さらば... {PLAYER}!$"

Route25_EventScript_Eusine::
	msgbox Route25_Text_Eusine2, MSGBOX_NPC
	end

Route25_EventScript_Suicune::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route25_EventScript_SuicuneRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE25_SUICUNE
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 8, Route25_EventScript_SuicunePostGame
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 66, Route25_AdjustPlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_ROUTE25_EUSINE, DIR_NORTH
	msgbox Route25_Text_Eusine3, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_EUSINE
	setflag FLAG_HIDE_ROUTE25_EUSINE
	clearflag FLAG_HIDE_CELADON_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 8
	release
	end

Route25_EventScript_SuicuneRan::
	release
	end

Route25_AdjustPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_EventScript_SuicunePostGame::
	release
	end

Route25_Movement_EusineLeave:
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_Movement_EusineSide:
	walk_slow_left
	walk_slow_up
	step_end

Route25_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_slow_up
	step_end

Route25_Movement_Suicune1:
	jump_in_place_down
	step_end

Route25_Movement_WalkToSuicune:
	walk_up
	walk_up
	step_end

Route25_Movement_MistyLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_ManLeaveRight:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route25_Movement_ManLeaveLeft:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route25_Movement_MistyWalkToPlayerRight:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
Route25_Movement_MistyWalkToPlayerLeft:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Route25_Text_MistyDate:
	.string "{JPN}カスミ: もう! どうして こんな\n"
	.string "{JPN}ときに じゃましに くるのよ!\p"
	.string "{JPN}あなたみたいな ひとのことを\n"
	.string "{JPN}なんて いうか しってる?\p"
	.string "{JPN}じゃまむし! そのとおりよ \n"
	.string "{JPN}じゃまむし!\p"
	.string "{JPN}...\p"
	.string "{JPN}...あら? そのバッジ...\n"
	.string "{JPN}ジョウトの ジムバッジね?\p"
	.string "{JPN}8こ もってるなら きっと\n"
	.string "{JPN}つよいのね.\p"
	.string "{JPN}じゃあ ハナダジムに\n"
	.string "{JPN}きなさい.\n"
	.string "{JPN}よろこんで あいてしてあげる.\p"
	.string "{JPN}わたし カスミ.ハナダジムの\nジムリーダーよ.$"

Route25_Text_SchoolboyDudleySeen:
	.string "{JPN}6にんの トレーナーに かって\n"
	.string "{JPN}すてきな しょうひんを ゲット!\p"
	.string "{JPN}やる きもちは あるかい?$"

Route25_Text_SchoolboyDudleyBeaten:
	.string "{JPN}うわあ! つよいなあ.$"

Route25_Text_SchoolboyDudleyAfter:
	.string "{JPN}ベストを つくした.\n"
	.string "{JPN}こうかいは ない.$"

Route25_Text_LassEllenSeen:
	.string "{JPN}わたしは 2ばんめ.\n"
	.string "{JPN}ここからが ほんばん!$"

Route25_Text_LassEllenBeaten:
	.string "{JPN}どうして まけちゃうの?$"

Route25_Text_LassEllenAfter:
	.string "{JPN}ベストを つくした.\n"
	.string "{JPN}こうかいは ない.$"

Route25_Text_SchoolboyJoeSeen:
	.string "{JPN}3ばんめの とうじょう!\n"
	.string "{JPN}そう かんたんじゃ ないぞ.$"

Route25_Text_SchoolboyJoeBeaten:
	.string "{JPN}いたた! ぺしゃんこだ!$"

Route25_Text_SchoolboyJoeAfter:
	.string "{JPN}ベストを つくした.\n"
	.string "{JPN}こうかいは ない.$"

Route25_Text_LassLauraSeen:
	.string "{JPN}4ばんめの わたし!\n"
	.string "{JPN}つかれてきた?$"

Route25_Text_LassLauraBeaten:
	.string "{JPN}わたしも まけちゃった...$"
Route25_Text_LassLauraAfter:
	.string "{JPN}ベストを つくした.\n"
	.string "{JPN}こうかいは ない.$"

Route25_Text_CamperLloydSeen:
	.string "{JPN}よし! 5ばんめの おれが\n"
	.string "{JPN}やっつけてやる!$"

Route25_Text_CamperLloydBeaten:
	.string "{JPN}うわあ! つよすぎる.$"

Route25_Text_CamperLloydAfter:
	.string "{JPN}ベストを つくした.\n"
	.string "{JPN}こうかいは ない.$"

Route25_Text_LassShannonSeen:
	.string "{JPN}さいごの わたしだけど\n"
	.string "{JPN}つよいわよ!$"

Route25_Text_LassShannonBeaten:
	.string "{JPN}うそでしょ.$"

Route25_Text_LassShannonAfter:
	.string "{JPN}ベストを つくした.\n"
	.string "{JPN}こうかいは ない.$"

Route25_Text_SupernerdPatSeen:
	.string "{JPN}ムフフフ...\p"
	.string "{JPN}ぼくは 6にんしゅうの\n"
	.string "{JPN}トレーナーとは かんけいないよ.\p"
	.string "{JPN}きみが たくさんの しあいで\n"
	.string "{JPN}つかれたところを まってたんだ.$"
	.string ""

Route25_Text_SupernerdPatBeaten:
	.string "{JPN}ぜんぜん つかれてないの?$"

Route25_Text_SupernerdPatAfter:
	.string "{JPN}ごめん... もう ずるいことは\n"
	.string "{JPN}しないよ...$"
Route25_Text_CooltrainerKevinNugget:
	.string "{JPN}よていより ひとつ おおく\n"
	.string "{JPN}たたかったけど かったね.\p"
	.string "{JPN}やくそくどおり しょうひんだ.$"
	.string ""

Route25_Text_CooltrainerKevinSeen:
	.string "{JPN}でも きみの たたかいぶりを\n"
	.string "{JPN}みて ぼくも たたかいたく\l"
	.string "{JPN}なった.\p"
	.string "{JPN}どうだい? あいてに なってくれ.$"

Route25_Text_CooltrainerKevinBeaten:
	.string "{JPN}こんなに いい たたかいは\n"
	.string "{JPN}はじめてだ!$"

Route25_Text_CooltrainerKevinAfter:
	.string "{JPN}すばらしい たたかいだった!\p"
	.string "{JPN}きみと きみの ポケモンは\n"
	.string "{JPN}ほんとうに すごいよ!$"

Route25_Text_BillsHouseSign:
	.string "{JPN}うみべの コテージ\n"
	.string "{JPN}マサキの いえ$"

