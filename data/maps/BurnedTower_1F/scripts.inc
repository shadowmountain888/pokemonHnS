.set LOCALID_BURNED_TOWER_SILVER, 3
.set LOCALID_BURNED_TOWER_EUSINE, 1

BurnedTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "{JPN}ミナキ: わたしはミナキ\p"
	.string "{JPN}スイクンというなのポケモンを\nさがしてたびをしている\p"
	.string "{JPN}きみは...\n{PLAYER}というのかよろしく\p"
	.string "{JPN}ここにスイクンがいるときいて\nやってきたのだが...\p"
	.string "{JPN}そこのゆかにあいたあなから\nちかしつをのぞいてごらん\p"
	.string "{JPN}そうだ\nスイクンたちがみえるだろう?\p"
	.string "{JPN}したへおりていってもいいんだが\nかれらはすぐにどこかへ\l"
	.string "{JPN}はしりさってしまうんだ\p"
	.string "{JPN}わたしはなんども\nためしているからね...$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "{JPN}ミナキ: どうやらきみにも\nいろいろわけがありそうだね...$"

BurnedTower_1FMortyText:
	.string "{JPN}マツバ: ぼくはマツバ\nエンジュのジムリーダーだよ\p"
	.string "{JPN}ふるいゆうじんのミナキくんが\nスイクンをさがしにきているので\l"
	.string "{JPN}ついでだからいっしょに\lこのとうのことをしらべてるんだ\p"
	.string "{JPN}エンジュにはむかしから\nスイクンエンテイライコウという\l"
	.string "{JPN}でんせつのポケモンにまつわる\lいいつたえがある\p"
	.string "{JPN}エンジュのジムリーダーは\nきちんとそのことを\l"
	.string "{JPN}しっておかなければならないんだ$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "{JPN}.........\p"
	.string "{JPN}...なんだおまえか\p"
	.string "{JPN}どうせここにあらわれるという\nでんせつのポケモンをつかまえて\l"
	.string "{JPN}じぶんをつよくみせようと\lおもってるんだろう\p"
	.string "{JPN}だがそれはむりなはなしさ\p"
	.string "{JPN}いいかでんせつのポケモンは\nさいきょうのトレーナーになると\l"
	.string "{JPN}ちかったオレにこそにあうんだ\p"
	.string "{JPN}おまえはせいぜい\nロケットだんのしたっぱにでも\l"
	.string "{JPN}あそんでもらうのがおにあいさ!\p$"

BurnedTowerSilver_WinText:
	.string "{JPN}...フン!\nつかえないポケモンだぜ\p"
	.string "{JPN}...いいかおまえがかてたのは\nオレのポケモンがよわかったからさ$"

BurnedTowerSilver_AfterText1:
	.string "{JPN}...まあいいさ\p"
	.string "{JPN}おまえにでんせつのポケモンが\nつかまえられるはずないからな\p$"

BurnedTowerSilver_LossText:
	.string "{JPN}...フン!\nじかんのむだだったか$"

BurnedTowerSilver_AfterText2:
	.string "{JPN}ちっ!\n"
	.string "{JPN}あなに おちるなんて\n"
	.string "{JPN}ばかじゃないの!\p"
	.string "{JPN}ざまあみろ!$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "{JPN}しんぱい するな!\p"
	.string "{JPN}かえんほうしゃの おれたちは\n"
	.string "{JPN}ひの ちからを だれよりも\lよく しってるんだ!$"
BurnedTower_Text_NardBeaten:
	.string "{JPN}あつい たたかいを ありがとう!$"
BurnedTower_Text_NardAfter:
	.string "{JPN}このとうが やけたのは\n"
	.string "{JPN}かみなりが おちたからだ.\p"
	.string "{JPN}おれが はく ほのおなんて\n"
	.string "{JPN}ちっぽけな ものさ...$"

BurnedTower_Text_RichardoSeen:
	.string "{JPN}やけたとうで どろぼうの\n"
	.string "{JPN}れんしゅうを してるんだ!\l"
	.string "{JPN}いえでは やっちゃ だめだぞ!$"
BurnedTower_Text_RichardoBeaten:
	.string "{JPN}ぷっしゅー.$"
BurnedTower_Text_RichardoAfter:
	.string "{JPN}はんざいしゃの じんせいは\n"
	.string "{JPN}むいてないのかも...$"
