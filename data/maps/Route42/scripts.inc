.set LOCALID_ROUTE42_EUSINE, 19
.set LOCALID_ROUTE42_SUICUNE, 17

Route42_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route42_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route42_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route42_MapScript_HideTrigger::
	setvar VAR_TEMP_0, 1
	return

Route42_EventScript_Suicune_Trigger::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune3
	applymovement OBJ_EVENT_ID_PLAYER, Route42_Movement_Player
	playse SE_LEDGE
	delay 60
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE42_SUICUNE
	waitmovement 0
	delay 60
	removeobject LOCALID_ROUTE42_SUICUNE
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_HIDE_ROUTE42_EUSINE
	addobject LOCALID_ROUTE42_EUSINE
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine1
	waitmovement 0
	msgbox Route42_Text_EusineAdmireSuicune, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE42_EUSINE, DIR_WEST
	msgbox Route42_Text_EusineJealous, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE42_EUSINE, DIR_EAST
	msgbox Route42_Text_EusineWontGiveUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine2
	waitmovement 0
	setflag FLAG_HIDE_ROUTE42_EUSINE
	removeobject LOCALID_ROUTE42_EUSINE
	setvar VAR_TEMP_0, 1
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 2, Route42_EventScript_DoneJohtoSuicune
	release
	end

Route42_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

Route42_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	step_end

Route42_Movement_Suicune2:
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_up
	step_end

Route42_Movement_Suicune3:
	jump_in_place_up
	delay_2
	face_up
	jump_2_up
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

Route42_Movement_Player:
	lock_facing_direction
	delay_2
	jump_2_up
	unlock_facing_direction
	step_end

Route42_Movement_Eusine1:
	walk_down
	walk_down
	walk_left
	face_right
	step_end

Route42_Movement_Eusine2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route42_Text_EusineAdmireSuicune:
	.string "{JPN}スイクン..\n"
	.string "{JPN}なんといさましく\l"
	.string "{JPN}なんとみずみずしく\l"
	.string "{JPN}なんとうつくしく\l"
	.string "{JPN}なんとすばしっこいのだ！$"
Route42_Text_EusineJealous:
	.string "{JPN}{PLAYER}！\n"
	.string "{JPN}きみはいつもスイクンが\l"
	.string "{JPN}あらわれるところにいるんだな\p"
	.string "{JPN}まあいいさ\n"
	.string "{JPN}スイクンをおいもとめるきもちは\l"
	.string "{JPN}わたしのほうがうえなんだ\p"
	.string "{JPN}わたしのそふは..\n"
	.string "{JPN}でんせつにくわしいひとでね\l"
	.string "{JPN}とくにスイクンのことは\l"
	.string "{JPN}こどものころから\l"
	.string "{JPN}なんどもきかされていたんだ$"
Route42_Text_EusineWontGiveUp:
	.string "{JPN}スイクン..\p"
	.string "{JPN}おまえがどこにむかっているのか\n"
	.string "{JPN}それをみとどけるまで\l"
	.string "{JPN}わたしはおいつづけるぜ..\p"
	.string "{JPN}いいな！$"

Route42_EventScript_Tully::
	trainerbattle_single TRAINER_TULLY Route42_Text_FisherTullySeen, Route42_Text_FisherTullyBeaten
	msgbox Route42_Text_FisherTullyAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Ben::
	trainerbattle_single TRAINER_BENJAMIN Route42_Text_HikerBenjaminSeen, Route42_Text_HikerBenjaminBeaten
	msgbox Route42_Text_HikerBenjaminAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE Route42_Text_PokemaniacShaneSeen, Route42_Text_PokemaniacShaneBeaten
	msgbox Route42_Text_PokemaniacShaneAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign::
	lock
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_MortarSign::
	lock
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end
Route42_EventScript_Item_Mint::
	finditem ITEM_MODEST_MINT
	end
Route42_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route42_Text_FisherTullySeen:
	.string "{JPN}おれが つった ポケモンの\n"
	.string "{JPN}ちからを みせて やる!$"

Route42_Text_FisherTullyBeaten:
	.string "{JPN}なんだと? そんな ばかな.\n"
	.string "{JPN}しんじられない!$"

Route42_Text_FisherTullyAfter:
	.string "{JPN}じぶんで つった ポケモンで\n"
	.string "{JPN}チャンピオンに なりたいんだ.\l"
	.string "{JPN}それが つりの だいごみさ!\p"
	.string "{JPN}それが つりの さいこうの\nたのしみ なんだよ!$"

Route42_Text_HikerBenjaminSeen:
	.string "{JPN}ああ  そとは きもちが いいな!\n"
	.string "{JPN}じゆうを かんじるよ!$"

Route42_Text_HikerBenjaminBeaten:
	.string "{JPN}がははは! いい しょうぶ\n"
	.string "{JPN}だった!$"

Route42_Text_HikerBenjaminAfter:
	.string "{JPN}おおきな そらを みあげれば\n"
	.string "{JPN}まけても たいした ことじゃ\lないって おもえるよ!$"

Route42_Text_PokemaniacShaneSeen:
	.string "{JPN}おい!\p"
	.string "{JPN}ここは おれの ひみつの\n"
	.string "{JPN}ばしょだ!\lよそものは うせろ!$"

Route42_Text_PokemaniacShaneBeaten:
	.string "{JPN}つきのいしを つかえば\n"
	.string "{JPN}よかった...$"
Route42_Text_PokemaniacShaneAfter:
	.string "{JPN}ポケモンずかんを つくってる\n"
	.string "{JPN}のか?\p"
	.string "{JPN}わあ  きっと めずらしい\n"
	.string "{JPN}ポケモンを しってるんだな!\p"
	.string "{JPN}ちょっと みせて くれない?\nおねがい!$"

Route42_Text_Sign1:
	.string "{JPN}ここは42ばんどうろ\n"
	.string "{JPN}ひがしチョウジタウン$"
Route42_Text_MtMortarSign1:
	.string "{JPN}スリバチやま\n"
	.string "{JPN}なかはおおたきのどうくつ$"