.set LOCALID_GRUNT, 1

SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt::
	lockall
	goto_if_eq VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1, SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort::
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep:
	.string "{JPN}おい!\n"
	.string "{JPN}おまえのかお みおぼえが\n"
	.string "{JPN}あるぞ!\p"
	.string "{JPN}ここにいるってことは\n"
	.string "{JPN}またオレたちのじゃまを\n"
	.string "{JPN}するつもりだな!\p"
	.string "{JPN}おまえみたいなガキが\n"
	.string "{JPN}アクアだんに かてると\n"
	.string "{JPN}おもってるのか?\p"
	.string "{JPN}1ちょうねんはやいぜ!\p"
	.string "{JPN}おまえはマグマだんの\n"
	.string "{JPN}やつらにおにあいだな!\p"
	.string "{JPN}そういえばマグマだんが\n"
	.string "{JPN}トクサネのちかくで\nmokugekiされたらしいぜ!\pあのバカどもは うみのちかくじゃ\nにあわないよな!$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort:
	.string "{JPN}おまえみたいなガキが\n"
	.string "{JPN}アクアだんに かてると\n"
	.string "{JPN}おもってるのか?\p"
	.string "{JPN}1ちょうねんはやいぜ!\p"
	.string "{JPN}おまえはマグマだんの\n"
	.string "{JPN}やつらにおにあいだな!\p"
	.string "{JPN}そういえばマグマだんが\n"
	.string "{JPN}トクサネのちかくで\n"
	.string "{JPN}mokugekiされたらしいぜ!\p"
	.string "{JPN}あのバカどもは うみのちかくじゃ\nにあわないよな!$"

