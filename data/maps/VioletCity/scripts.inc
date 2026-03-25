.set LOCALID_VIOLETCITY_EARL, 4
.set LOCALID_VIOLET_KIMONO, 31

VioletCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VioletCity_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VioletCity_OnFrame::
	map_script_2 VAR_VIOLET_CITY_KIMONO_GIRL, 1, VioletCity_EventScript_Kimono_Girl
	map_script_2 VAR_VIOLET_CITY_STATE, 3, VioletCity_EventScript_ElmCall_Trigger
	.2byte 0

VioletCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

VioletCity_EventScript_Trigger::
	@LOCAL FLAGHEAP
	clearflag FLAG_RECEIVED_TOGEPI_EGG
	clearflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	clearflag FLAG_HIDE_SPROUT_TOWER_SILVER
	clearflag FLAG_HIDE_JOHTO_GYM_LEADERS
	clearflag FLAG_HOOH_BROUGHT
	clearflag FLAG_OMANYTE_BROUGHT
	clearflag FLAG_AERODACTYL_BROUGHT
	clearflag FLAG_KABUTO_BROUGHT
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_GOT_HARD_STONE
	clearflag FLAG_GOT_POISON_BARB
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_GOT_BLACK_GLASSES
	
	setvar VAR_SLOWPOKE_TAIL, 0
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 0
	setvar VAR_RUINSOFALPH_STATE, 0
	
	setflag FLAG_ITEM_GS_BALL
	setflag FLAG_ITEM_DOME_FOSSIL
	setflag FLAG_ITEM_HELIX_FOSSIL
	setflag FLAG_ITEM_OLD_AMBER
	setflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_VISITED_VIOLET_CITY
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	
	setvar VAR_SPROUT_TOWER, 0
	setvar VAR_VIOLET_CITY_STATE, 1
	end

VioletCity_EventScript_Earl::
	lock
	faceplayer
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	faceplayer
	msgbox VioletCity_Text_EarlAsksIfYouBeatFalkner MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_EventScript_EarlTrainerSchool
	msgbox VioletCity_Text_VeryNiceIndeed, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_EarlTrainerSchool::
	msgbox VioletCity_Text_FollowEarl, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	switch VAR_FACING
	case DIR_NORTH, VioletCity_EventScript_EarlTrainerSchoolSouth
	case DIR_WEST, VioletCity_EventScript_EarlTrainerSchoolEast
	release
	end

VioletCity_EventScript_EarlTrainerSchoolSouth::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_South_Adjustment
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_South_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolEast::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_East_Adjustment
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_East_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolTransition:
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Walk_To_School
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Walk_To_School
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	turnobject LOCALID_VIOLETCITY_EARL, DIR_WEST
	msgbox VioletCity_Text_HereTeacherIAm, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Walk_Inside
	delay 20
	opendoor 39, 36
	waitdooranim
	waitmovement 0
	setflag FLAG_HIDE_VIOLET_CITY_EARL
	removeobject LOCALID_VIOLETCITY_EARL
	closedoor 39, 36
	waitdooranim
	clearflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	fadedefaultbgm
	release
	end

VioletCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox VioletCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Boy::
	lock
	faceplayer
	msgbox VioletCity_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox VioletCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Pichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PICHU, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Pichu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Bellsprout::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BELLSPROUT, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Bellsprout, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Rattata::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Rattata, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_ElmCall_Trigger::
	lock
	pokenavcall VioletCity_Text_Elm_Call
	waitmessage
	delay 30
	clearflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	setvar VAR_VIOLET_CITY_STATE, 4
	release
	end

VioletCity_EventScript_Kimono_Girl::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	playse SE_PIN
	applymovement LOCALID_VIOLET_KIMONO, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_1
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_2
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_3
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl3, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_4
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_5
	waitmovement 0
	fadedefaultbgm
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 2
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	removeobject LOCALID_VIOLET_KIMONO
	release
	end


VioletCity_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

VioletCity_EventScript_ItemPechaBerry::
	finditem ITEM_PECHA_BERRY
	end

VioletCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

VioletCity_Movement_Earl_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

VioletCity_Movement_Earl_East_Adjustment:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VioletCity_Movement_Player_East_Adjustment:
	walk_down
	walk_down
	walk_left
	walk_down
	face_right
	step_end

VioletCity_Movement_Earl_South_Adjustment:
	walk_right
	walk_down
	walk_down
	walk_down
	face_right
	step_end

VioletCity_Movement_Player_South_Adjustment:
	walk_down
	walk_down
	step_end

VioletCity_Movement_Walk_To_School:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
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

VioletCity_Movement_Walk_To_School_Player:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VioletCity_Movement_Earl_Walk_Inside:
	walk_up
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_1:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

VioletCity_Movement_Kimono_Girl_2:
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_3:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

VioletCity_Movement_Kimono_Girl_4:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	step_end

VioletCity_Movement_Kimono_Girl_5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end	

VioletCity_EventScript_LiquidJustice::
	msgbox VioletCity_Text_LiquidJustice, MSGBOX_NPC
	end

VioletCity_EventScript_GymSign::
	msgbox VioletCity_Text_GymSign, MSGBOX_SIGN
	end

VioletCity_Text_LiquidJustice:
	.string "{JPN}まわりをみてごらん！\pその ちいきに どんな\nポケモンが いるかが\lいちにちじゅう くさむらを\lはしりまわらなくても わかるよ！$"
VioletCity_Text_EarlAsksIfYouBeatFalkner:
	.string "{JPN}はーいあなたトレーナーですね\n"
	.string "{JPN}ジムリーダーにはかてましたかあ？$"
VioletCity_Text_VeryNiceIndeed:
	.string "{JPN}それはすーごいですねー！$"
VioletCity_Text_FollowEarl:
	.string "{JPN}そーですかー\n"
	.string "{JPN}それではべんきょーするですよ\l"
	.string "{JPN}ではついてくるですよー$"
VioletCity_Text_HereTeacherIAm:
	.string "{JPN}ワタシここのせんせー！\p"
	.string "{JPN}あなたここで\n"
	.string "{JPN}べんきょーするといいねー$"
VioletCity_Text_Lass:
	.string "{JPN}マダツボミのとうには\nおばけがでるって うわさよ\pゴーストタイプの わざなら\nイワークや イシツブテみたいな\pかたい ポケモンの ぼうぎょを\nとっぱできるんですって$"
VioletCity_Text_Boy:
	.string "{JPN}おっ きみ ポケモン\nトレーナーなの？\pアカデミーに いけば\nなにか あたらしいことを\nまなべるかもよ！$"
VioletCity_Text_Gramps:
	.string "{JPN}キキョウポケモンジムの\n"
	.string "{JPN}ハヤトはすごうでのトレーナー！\p"
	.string "{JPN}ちちおやのあとをついで\n"
	.string "{JPN}りっぱにジムをまもっとるぞ！$"
VioletCity_Text_Youngster:
	.string "{JPN}さっき ゆれてる きを\nみつけたんだ！\pさわると クネクネして\nおどるんだぜ！ すげーよ！$"
VioletCity_Text_Sign:
	.string "{JPN}ここはキキョウシティ\n"
	.string "{JPN}なつかしいかおりのまち$"
VioletCity_Text_GymSign:
	.string "{JPN}キキョウシティポケモンジム\n"
	.string "{JPN}リーダーハヤト\l"
	.string "{JPN}かれいなるひこうポケモンつかい！$"
VioletCity_Text_SproutTowerSign:
	.string "{JPN}ここはマダツボミのとう\p"
	.string "{JPN}ポケモンしゅぎょうをつうじて\n"
	.string "{JPN}まよいをたちきりなされよ$"
VioletCity_Text_EarlsAcademySign:
	.string "{JPN}アールの ポケモン アカデミー$"
VioletCity_Text_Pichu:
	.string "{JPN}ピチュー: ちゅーう！$"
VioletCity_Text_Bellsprout:
	.string "{JPN}マダツボミ: まだつぼみー$"
VioletCity_Text_Rattata:
	.string "{JPN}コラッタ: ころころった！$"
VioletCity_Text_Elm_Call:
	.string "{JPN}ウツギはかせ: もしもし {PLAYER}くん?\n"
	.string "{JPN}タマゴについて はっけんが あったんじゃ!\p"
	.string "{JPN}わたしの じょしゅが キキョウシティの\n"
	.string "{JPN}ポケモンセンターに いるんじゃ\p"
	.string "{JPN}かれと はなしてくれるかな?$"

VioletCity_Text_Kimono_Girl1:
.string "{JPN}あれまそのタマゴは..！$"
VioletCity_Text_Kimono_Girl2:
	.string "{JPN}ふんふんなるほど..\n"
	.string "{JPN}ポケモンじいはんから\l"
	.string "{JPN}ウツギはんへ\p"
	.string "{JPN}そしてウツギはんから\n"
	.string "{JPN}あんさんへ\p"
	.string "{JPN}そうどすかあ..$"
VioletCity_Text_Kimono_Girl3:
	.string "{JPN}それはほんまにだいじな\n"
	.string "{JPN}タマゴやさかいに\l"
	.string "{JPN}しっかりそだてておくれやす\p"
	.string "{JPN}よろしおすな？$"
VioletCity_Text_Kimono_Girl4:
.string "{JPN}ほなたのんますえー$"

