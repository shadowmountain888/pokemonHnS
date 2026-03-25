GoldenrodCity_RadioTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6 GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7 GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8 GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SKILL_SWAP, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SKILL_SWAP
	setflag FLAG_GOT_SKILL_SWAP
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "{JPN}カードキーのさしこみぐちだ$"
GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{JPN}{PLAYER}は\nカードキーをさしこんだ！$"
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "{JPN}ゲートがひらいた！$"
GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "{JPN}3F しょくいんしつ$"
GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "{JPN}ポケモンミュージック\nパーソナリティ DJベン$"
GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "{JPN}いままでにはっけんされた\nポケモンのなきごえを\lぜんぶろくおんしてるんだ\pだいたい400しゅるい\nぐらいあるよ$"
GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "{JPN}トレーナーにとってポケモンは\nたいせつなパートナーだ\pロケットだんがポケモンを\nしはいしようなんてひどいぞ！$"
GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "{JPN}24じかんたいせいで\nたのしいばんぐみをおとどけ！\pわたしも24じかん\nがんばってはたらくぞ！$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "{JPN}ロケットだんのボスが\nじぶんをとじこめちゃった\pでもきょくちょうなら\nひらけるのよ\p5かいにいるの\pたすけて！$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "{JPN}きょくちょうはぶじかしら？$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "{JPN}ありがとう！\nあなたってヒーローね！\pおれいのしるしよ$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "{JPN}スキルスワップよ\nポケモンのとくせいを\nいれかえるのよ$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "{JPN}あなたってすばらしいわ！$"
GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "{JPN}おれはめいれいをうけている\pロケットだんにたてつくやつは\nみんなたたきつぶせとな！$"
GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "{JPN}なんだと！？$"
GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "{JPN}しっぱいしちまった..\pアポロにおこられるぜ..$"
GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "{JPN}ポケモンにあくじを\nめいれいするのは\nサイコーだぜ！$"
GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "{JPN}うそだろ！$"
GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "{JPN}まけて きぶんが わるいぜ!\p"
	.string "{JPN}ちくしょう! やくにたたない\nポケモンなんて だいきらいだ!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "{JPN}なぜシャッターがあいた？\nおまえがなにか\nしたのか？$"
GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "{JPN}やられた！$"
GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "{JPN}なに？！ちかつうろの\nおれたちをやぶったって？\pそんなバカな！$"
GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "{JPN}しらないこどもが\nうろついているな？\pきみはだれだ？$"
GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "{JPN}ちっ！あまくみていた！$"
GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "{JPN}ぶわはははは.\pここからならひつような\nだけつよいでんぱを\nそうしんできるぞ！$"