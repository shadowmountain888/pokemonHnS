.set LOCALID_ECRUTEAK_GRAMPS, 4
.set LOCALID_ECRUTEK_SILVER, 33

EcruteakCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "{JPN}{STR_VAR_1}どんッ！$"
EcruteakCity_Text_Silver2:
	.string "{JPN}{RIVAL} なんでなんで..\n"
	.string "{JPN}なんでオレはかてないんだ..\p"
	.string "{JPN}あいては\n"
	.string "{JPN}ただのまいこさんじゃないか..$"
EcruteakCity_Text_Silver3:
	.string "{JPN}{RIVAL} みてたのか{PLAYER}..\p"
	.string "{JPN}そうだよオレはかてなかった\n"
	.string "{JPN}まいこさん5にんぬきなんて\l"
	.string "{JPN}かんたんだとおもったのに..\l"
	.string "{JPN}コテンパンにされちまった\p"
	.string "...\p"
	.string "{JPN}どうせおまえもまいこさんに\n"
	.string "{JPN}ちょうせんしにきたんだろ？\p"
	.string "{JPN}ロケットだんをつぶしたからって\n"
	.string "{JPN}あんまりちょうしにのるなよ\l"
	.string "{JPN}ここのまいこさんたち\l"
	.string "{JPN}ばかみてーにつよいからな\p"
	.string "{JPN}さあいけよ\p"
	.string "{JPN}やってみろよ\p"
	.string "{JPN}オレはなかにはもどらない\n"
	.string "{JPN}おまえがかつところなんて\l"
	.string "{JPN}みたくないからな$"
EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "{JPN}イーブイブイー！$"
EcruteakCity_Text_Vulpix:
	.string "{JPN}ロコンロコーン！$"
EcruteakCity_Text_UnusedMissingDaughter:
	.string "{JPN}あらたいへん..\pむすめがいないの..\pまさか\nやけたとうになんて..\pちかづいちゃダメっていったのに..\pひとがいなくなるうわさが..\pどうしたらいいのかしら..？$"
EcruteakCity_Text_Gramps1:
	.string "{JPN}エンジュにはにしとひがしに\n"
	.string "{JPN}2つのとうがあったらしいが..$"
EcruteakCity_Text_Gramps2:
	.string "{JPN}ほうぼうや\nまいこさんのようにおどれるかね？\pおどりばにいけばかわったじいさんが\nなにかいいものをくれるそうじゃ\l$"
EcruteakCity_Text_Lass1:
	.string "{JPN}これからおどりばで\n"
	.string "{JPN}おどりのれんしゅうするの\l"
	.string "{JPN}よかったらあなたもどう？$"
EcruteakCity_Text_Lass2:
	.string "{JPN}ここにあったとう..\pおばあちゃんがいってたけど\nもっとたかかったのよ\pいまはおばけがでるらしいわ$"
EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "{JPN}3ひきのおおきなポケモン\n"
	.string "{JPN}あちこちにはしりさっていったわ\l"
	.string "{JPN}なんだったのかしら？$"
EcruteakCity_Text_Fisher:
	.string "{JPN}あさぎのとうだいで\nうわさをきいたぞ\pとうだいのあかりになってる\nポケモンがびょうきらしい\lたいへんなことになってるぞ$"
EcruteakCity_Text_Fisher_JasmineReturned:
	.string "{JPN}ぐあいがわるかった\n"
	.string "{JPN}アサギシティのポケモン\l"
	.string "{JPN}すっかりなおったんだって！\p"
	.string "{JPN}これでよるでもふねが\n"
	.string "{JPN}だせるようになったってよ！$"
EcruteakCity_Text_Youngster:
	.string "{JPN}いかりのみずうみで\nポケモンがあばれてるらしいぞ$"
EcruteakCity_Text_Gramps3:
	.string "{JPN}むかしむかし..\pこのとうはかじでやけた3びきの\nなまえしらずのポケモンがしんだ\pにじいろのポケモンがそらから\nまいおりてよみがえらせたのじゃ\pエンジュジムリーダーにつたわる\nでんせつじゃよ\pわしか？\pむかしはトレーナーじゃった\nホホホ！$"
EcruteakCity_Text_SageGym:
	.string "{JPN}ジムリーダーのマツバは\nいまいません\lやけたとうにいるでしょう$"
EcruteakCity_Text_Sign:
	.string "{JPN}ここはエンジュシティ\n"
	.string "{JPN}れきしがながれるまち$"
EcruteakCity_Text_TinTowerSign:
	.string "{JPN}スズのとう\pでんせつのポケモンが\nすんでいるといわれる$"
EcruteakCity_Text_OfficeSign:
	.string "{JPN}スズのとうへのせきしょ\n"
	.string "{JPN}しかくなきものとおしはせぬ$"
EcruteakCity_Text_GymSign:
	.string "{JPN}エンジュシティポケモンジム\n"
	.string "{JPN}リーダーマツバ\l"
	.string "{JPN}せんりがんをもつしゅげんじゃ$"
EcruteakCity_Text_DanceTheaterSign:
	.string "{JPN}ここはエンジュおどりば\n"
	.string "{JPN}ただしいよびかたはかぶれんじょう$"
EcruteakCity_Text_BurnedTowerSign:
	.string "{JPN}このやけたとうは\n"
	.string "{JPN}なぞのおおかじでやけました\p"
	.string "{JPN}きけんなにおいがするので\n"
	.string "{JPN}あまりちかよらないでください$"