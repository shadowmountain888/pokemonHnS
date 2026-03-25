.set LOCALID_MRPOKEMON, 2
.set LOCALID_ROUTE30_OAK, 3
.set LOCALID_MRPOKEMON2, 1

Route30_MrPokemonsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 60
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, TRUE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "{JPN}やあやあ! きみが\n"
	.string "{JPN}{PLAYER}くんだね.\p"
	.string "{JPN}ウツギはかせから\n"
	.string "{JPN}きてくれるって きいてたよ.$"

MrPokemonHouse_Text_Intro2:
	.string "{JPN}ウツギはかせに\n"
	.string "{JPN}しらべてほしいものというのは\l"
	.string "{JPN}これなんだよー$"
MrPokemonHouse_Text_GotEgg:
	.string "{JPN}{PLAYER}は ふしぎなタマゴを\nうけとった!$"

MrPokemonHouse_Text_Intro3:
	.string "{JPN}ポケモンの そだてやを\n"
	.string "{JPN}やってる ふうふがいるんだ.\p"
	.string "{JPN}そのひとたちが このタマゴを\n"
	.string "{JPN}くれたんだよ.\p"
	.string "{JPN}きになったから ウツギはかせに\n"
	.string "{JPN}てがみを だしたんだ.\p"
	.string "{JPN}ポケモンの しんかについては\nウツギはかせが だいいちにんしゃだからね.$"


MrPokemonHouse_Text_Intro4:
	.string "{JPN}ここにいる オーキドはかせも\n"
	.string "{JPN}それは みとめているよ.$"

MrPokemonHouse_Text_Intro5:
	.string "{JPN}わたしの よそうが あたっていれば\n"
	.string "{JPN}ウツギはかせなら わかるはずだ.$"

MrPokemonHouse_Text_Heal:
	.string "{JPN}きみはまたウツギはかせの\n"
	.string "{JPN}ところまでもどるんだろ？\p"
	.string "{JPN}すこしポケモンを\n"
	.string "{JPN}やすませていくといいよー！$"
MrPokemonHouse_Text_DependingOnYou:
	.string "{JPN}きみに たのんだよ!$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "{JPN}よのなかはおもしろいねえ！\n"
	.string "{JPN}いろんなはっけんがあるから！$"
MrPokemonHouse_Text_OakIntro:
	.string "{JPN}オーキド: おお! きみが {PLAYER} だね!\p"
	.string "{JPN}わたしは オーキド!\n"
	.string "{JPN}ポケモンけんきゅうしゃ だよ.\p"
	.string "{JPN}ふるい ともだちの ポケモンじいさんを\n"
	.string "{JPN}たずねて きていたんだ.\p"
	.string "{JPN}ウツギはかせの おつかいを\n"
	.string "{JPN}していると きいたので\n"
	.string "{JPN}まっていたんだよ.\p"
	.string "{JPN}おお! これは めずらしい\n"
	.string "{JPN}ポケモンじゃないか!\p"
	.string "{JPN}みせてもらおう...\n"
	.string "{JPN}ふむ なるほど!\p"
	.string "{JPN}ウツギはかせが この おつかいに\n"
	.string "{JPN}ポケモンを もたせた りゆうが\n"
	.string "{JPN}わかったよ.\p"
	.string "{JPN}ウツギはかせと わたしのような\n"
	.string "{JPN}けんきゅうしゃにとって\n"
	.string "{JPN}ポケモンは ともだちなんだ.\n"
	.string "{JPN}かれは きみが ポケモンを\n"
	.string "{JPN}あいじょうを もって\n"
	.string "{JPN}そだてると みぬいたんだね.\p"
	.string "{JPN}...ああ!\p"
	.string "{JPN}きみは しんらいできそうだ.\n"
	.string "{JPN}わたしを てつだってくれないか?\p"
	.string "{JPN}これを みてごらん.さいしんばんの\nポケモンずかんだよ.\pであったり つかまえた ポケモンの\nデータを じどうてきに\nきろくするんだ.\nハイテクな ひゃっかじてんさ!\pすみかや しんかのしかた \nおぼえる わざが わかるんだよ.$"

MrPokemonHouse_Text_GetDex:
	.string "{JPN}{PLAYER}は ポケモンずかんを\nうけとった!$"

MrPokemonHouse_Text_OakParting:
	.string "{JPN}いろんな ポケモンに であって\n"
	.string "{JPN}ポケモンずかんを かんせいさせるんじゃ!\p"
	.string "{JPN}しかし ながいしていたな.\p"
	.string "{JPN}コガネシティの ラジオばんぐみに\n"
	.string "{JPN}いかなければ ならん.\p"
	.string "{JPN}{PLAYER}よ! たのんだぞ!$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "{JPN}ん？そのウロコは？\n"
	.string "{JPN}なぬ！あかいギャラドス！？\p"
	.string "{JPN}そっそれはめずらしい！\n"
	.string "{JPN}ほほしいのう..\p"
	.string "{JPN}{PLAYER}くん\n"
	.string "{JPN}オーキドはかせからもらった\l"
	.string "{JPN}このがくしゅうそうちと\l"
	.string "{JPN}こうかんしてもらえんかなー？$"
MrPokemonHouse_Text_Disappointed:
	.string "{JPN}そうかそりゃざんねんだ\n"
	.string "{JPN}かなりめずらしいモノなんだが..$"
MrPokemonHouse_Text_ExpShare:
	.string "{JPN}きみに とくべつな どうぐも\n"
	.string "{JPN}あげよう.$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "{JPN}せかいじゅうのざっしが\n"
	.string "{JPN}いっぱいならんでいる！\p"
	.string "...\n"
	.string "{JPN}タイトルがよめない..$"
MrPokemonHouse_Text_BrokenComputer:
	.string "{JPN}おおきなコンピュータ！\n"
	.string "{JPN}..こわれてるみたい$"
MrPokemonHouse_Text_StrangeCoins:
	.string "{JPN}みたことのないコインが\n"
	.string "{JPN}いっぱいちらばってる！\l"
	.string "{JPN}どこかのくにのおかねかな？$"
MrPokemonHouse_Text_GotExpShare:
	.string "{JPN}{PLAYER}は がくしゅうそうちを\nうけとった!$"
