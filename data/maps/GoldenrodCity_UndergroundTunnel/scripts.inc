.set LOCALID_GOLDENROD_UNDERGROUND_KIMONO, 12

GoldenrodCity_UndergroundTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end
	
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 60
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 60
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
	.string "{JPN}くろいふくをきたロケットだんが\nはしりまわっていたが.\pいったいなにがあったのか\nきになっていたのだ\lきみがロケットだんと！\pでんせつのポケモンと\nたたかえるかもしれんな.$"
GoldenrodCity_UndergroundTunnel_Text_Kimono2:
	.string "{JPN}ははは！きにするな\nわたしはいくとしよう$"
GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
	.string "{JPN}ポケモンサロンへようこそ！\pわたしはカットきょうだいの\nおとうとです\pやすくて300えんで\nポケモンをきれいにします\pどうですか？$"
GoldenrodUnderground_Text_YoungerBrotherAskWhich:
	.string "{JPN}はい！どのポケモンに\nしますか？$"
GoldenrodUnderground_Text_YoungerBrotherLookCool:
	.string "{JPN}よ-し！かっこよくして\nあげるからね！$"
GoldenrodUnderground_Text_YoungerBrotherAllDone:
	.string "{JPN}はい！できあがり！$"
GoldenrodUnderground_Text_YoungerBrotherDisappointed:
	.string "{JPN}だめ？ざんねんだな-！$"
GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
	.string "{JPN}おかねがちょっと\nたりないみたいだよ$"
GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
	.string "{JPN}1にちに1ぴきしか\nカットできないんだ\pごめんね！きょうは\nもうおしまいなんだ$"
GoldenrodUnderground_Text_OlderBrotherOffer:
	.string "{JPN}いらっしゃいませ！\pここはポケモンビューティー\nサロンでございます！\pわたくしはカットブラザーズの\nあにでございます\pあなたのポケモンを500えんで\nうつくしくいたします\pいかがでしょうか？$"
GoldenrodUnderground_Text_OlderBrotherAskWhich:
	.string "{JPN}どちらのポケモンを\nカットいたしましょう？$"
GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
	.string "{JPN}はい！うつくしくなるのを\nごらんください！$"
GoldenrodUnderground_Text_OlderBrotherAllDone:
	.string "{JPN}はい！できあがりです！$"
GoldenrodUnderground_Text_OlderBrotherThatsAShame:
	.string "{JPN}そうですか？\nそれはざんねんです！$"
GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
	.string "{JPN}おかねがたりませんね$"
GoldenrodUnderground_Text_OlderBrotherOnePerDay:
	.string "{JPN}1にち1ぴきしか\nカットしておりません\nきょうはもうおしまいです$"
GoldenrodUnderground_Text_SupernerdEricSeen:
	.string "{JPN}ゲームコーナーから\nつまみだされちゃった\pポケモンをつかって\nいかさましようとしたら.$"
GoldenrodUnderground_Text_SupernerdEricBeaten:
	.string "{JPN}..ぶつぶつ..$"
GoldenrodUnderground_Text_SupernerdEricAfterBattle:
	.string "{JPN}せいせいどうどうと\nやらなきゃだめか.$"
GoldenrodUnderground_Text_SupernerdTeruSeen:
	.string "{JPN}きみはバトルでタイプの\nあいしょうをかんがえるか？\pタイプのゆうりをしっていれば\nバトルでゆうりになるぞ！$"
GoldenrodUnderground_Text_SupernerdTeruBeaten:
	.string "{JPN}いたたたた！$"
GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
    .string "{JPN}ぼくは ポケモンの\n"
	.string "{JPN}タイプの あいしょうを\nしっているよ.\pでも ひとつの タイプの\nポケモンしか つかわないんだ.$"

GoldenrodUnderground_Text_PokemaniacIssacSeen:
	.string "{JPN}ぼくのポケモンさっき\pさんぱつしてもらったんだ！\pどのくらいつよくなったか\nみせてやる！$"
GoldenrodUnderground_Text_PokemaniacIssacBeaten:
	.string "{JPN}ぎゃー！$"
GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
	.string "{JPN}ポケモンにさんぱつしてやると\nきみをもっとすきになるよ$"
GoldenrodUnderground_Text_PokemaniacDonaldSeen:
	.string "{JPN}きみめずらしいポケモンを\nもってそうだな\pちょっとみせてくれよ！$"
GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
	.string "{JPN}がーん！まけた！むかつく！$"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "{JPN}きのうのよるじてんしゃやの\nちかくをあるいてたら\lやねのうえからみられてる\nきがしたんだ..$"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
	.string "{JPN}きみポケモンずかんつくってる？\nいいじょうほうおしえてやる\p33ばんどうろのやまおとこの\nアンソニーはいいやつだ\pめずらしいポケモンをみつけたら\nでんわしてくれるぞ$"
GoldenrodUnderground_Text_DoorsLocked:
	.string "{JPN}ドアにかぎがかかっている..$"
GoldenrodUnderground_Text_DoorIsOpen:
	.string "{JPN}ドアはひらいている$"
GoldenrodUnderground_Text_KeyOpenedDoor:
	.string "{JPN}ちかしつのカギでドアがひらいた$"
GoldenrodUnderground_Text_NoEntry:
	.string "{JPN}ここからさきはたちいりきんし$"