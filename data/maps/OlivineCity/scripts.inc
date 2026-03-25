.set LOCALID_OLIVINE_SILVER, 4

OlivineCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_Baoba:
	.string "{JPN}{PLAYER}！\pわしはサファリゾーンの\nえんちょうのバオバじゃ！\pおまたせしてすまなかった！\nついにサファリゾーンが\lオープンしたんじゃ！\pばしょはわかるかな？\pタンバシティのどうくつの\nなかのゲートをしっておるか？\pそこをとおってすこしあるくと\nサファリゾーンがみえてくる！\pすこしはなれておるが\nぜひあそびにきてくれ！$"
OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0
	
	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "{PLAYER} ...\p"
	.string "{JPN}..またおまえかよ\p"
	.string "{JPN}なにそのきになってんだ？\n"
	.string "{JPN}オレはおまえみたいな\l"
	.string "{JPN}よわいやつはあいてにしない\p"
	.string "{JPN}..よわいといえば\n"
	.string "{JPN}ここのジムリーダーもいないぜ\p"
	.string "{JPN}よわったポケモンのせわをしに\n"
	.string "{JPN}とうだいへいってるんだとよ\p"
	.string "{JPN}..フン！ばかばかしい\n"
	.string "{JPN}よわったポケモンなんか\l"
	.string "{JPN}ほっときゃいいのさ\p"
	.string "{JPN}たたかえないポケモンに\n"
	.string "{JPN}なんのかちもないからな\p"
	.string "{JPN}おまえとうだいで\n"
	.string "{JPN}しゅぎょうしてみたらどうだ？\p"
	.string "{JPN}すこしはいちにんまえの\n"
	.string "{JPN}トレーナーらしく\l"
	.string "{JPN}なれるかもしれないぜ$"
OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_Shockwave::
	finditem ITEM_TM_SHOCK_WAVE
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "{JPN}アサギしょくどう\nちからじまんのせんいんが\lたべるけんこうりょうり$"
OlivineCity_Text_EonTicketWoman1:
	.string "{JPN}わたしマリーよ！\pなーんてね！マリーちゃんの\nラジオだいすきなの！$"
OlivineCity_Text_EonTicketWoman2:
	.string "{JPN}あなたが{PLAYER}ね！\pまあ！チャンピオン！\pマリーちゃんのラジオで\nきいたのよ！\pはい！これをどうぞ！$"
OlivineCity_Text_EonTicketWoman3:
	.string "{JPN}チャンピオンにあえるなんて\nしんじられない！$"
OlivineCity_Text_Sailor1:
	.string "{JPN}くらいよみちはきけん！\n"
	.string "{JPN}くらいうみもきけんがいっぱい！\p"
	.string "{JPN}とうだいのあかりがないと\n"
	.string "{JPN}ふねはうごけないんだ$"
OlivineCity_Text_YoungsterPokegear:
	.string "{JPN}きみのもってるそれって\n"
	.string "{JPN}ポケギアだろ？\l"
	.string "{JPN}いいなあかっこいいなあ$"
OlivineCity_Text_YoungsterPokedex:
	.string "{JPN}きみのもってるそれって\n"
	.string "{JPN}ポケモンずかんだろ？\l"
	.string "{JPN}いいなあかっこいいなあ$"
OlivineCity_Text_Sailor2:
	.string "{JPN}リーグはミカンちゃんを\n6ばんめにつよい\lジムリーダーってしてるぜ！\pはっ！そんなのデタラメだ！\pヤナギじいさんじゃミカンの\nはがねタイプポケモンには\lかてっこないぜ！\pかんりょうしゅぎってやつだな！\pミカンちゃんはおそろしく\nつよいんだぞ！$"
OlivineCity_Text_Sign:
	.string "{JPN}ここはアサギシティ\pしおかぜかおるみなとまち$"
OlivineCity_Text_PortSign:
	.string "{JPN}ここはアサギみなと\n"
	.string "{JPN}こうそくせんのりば$"
OlivineCity_Text_GymSign:
	.string "{JPN}アサギシティポケモンジム\n"
	.string "{JPN}リーダーミカン\l"
	.string "{JPN}てっぺきガードのおんなのこ$"
OlivineCity_Text_LighthouseSign:
	.string "{JPN}ここはアサギのとうだい\p"
	.string "{JPN}べつめいかがやきのとうだい\n"
	.string "{JPN}とよばれています$"
OlivineCity_Text_BattleTowerSign:
	.string "{JPN}トレーナーヒルと\nバトルテントさき\pただいまオープン！$"
OlivineCity_Text_Machoke:
	.string "{JPN}ゴーリキー:チョー！$"