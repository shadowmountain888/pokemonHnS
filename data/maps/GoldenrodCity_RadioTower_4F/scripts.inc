GoldenrodCity_RadioTower_4F_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28 GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9 GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2 GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "{JPN}プロトン: ちょっと まてよ!\p"
	.string "{JPN}おまえは やどんのいどで\n"
	.string "{JPN}じゃまを した やつじゃないか?\p"
	.string "{JPN}そうか... おまえは おれを\n"
	.string "{JPN}おこらせる ために やってるんだな.\l"
	.string "{JPN}きを つけろよ!\p"
	.string "{JPN}だが おまえが のぞむなら\n"
	.string "{JPN}ロケットだんかんぶの いかりの\l"
	.string "{JPN}すべてを みせて やる!$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "{JPN}ふう..$"
GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "{JPN}ワタルこんかいは\nまけたかもしれん..\pだがロケットだんの\nいかりをますだけだぞ！$"
GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "{JPN}いせきでラジオを\nきいていたんだ\pへんなほうそうが\nきこえてきたよ$"
GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "{JPN}メアリーなんで？\nなんでわたしが\nこんなめにあうの？\pニャース！たすけて！$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "{JPN}メアリーあら！\nちいさなきゅうせいしゅね！\pおれいにこれをうけとって？$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "{JPN}メアリーてきのこうげきを\nかわすのにやくだつのよ$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "{JPN}メアリーオ-キドはかせの\nポケモンこうざに\nチューニンしてね！$"
GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "{JPN}ニャースニャース..$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "{JPN}きみは きょくちょうを\n"
	.string "{JPN}たすけに きたのか?\p"
	.string "{JPN}そんなことは させないぞ!\nきみを やっつけて やる!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "{JPN}そんな！しんじられん！$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "{JPN}しんじられん！まけたなんて！$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "{JPN}まて！おれはロケットだんの\nようさいとよばれているんだ！\pいっぽもとおさせんぞ！$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "{JPN}ようさいがくずれた！$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "{JPN}きみをみとめる\nだからちゅうこくしてやろう\pまだまにあう\nひきかえしたほうがいいぞ$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "{JPN}ポケモンがかわいいかって？\pわたしのポケモンはかわいいわ\pあなたのをたおしたあとにね！$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "{JPN}あーあ! つかえない やつらね!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "{JPN}うつくしいわたしがだいすき！\pポケモンなんてどうでもいいわ$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "{JPN}すばらしい\pこのラジオとうで\nわれわれのだいけいかくを$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "{JPN}むむ..\pだいけいかくにもしっぱいはつきものか$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "{JPN}ほんきでロケットだんを\nとめられるとおもっているのか？$"
GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "{JPN}4かい せいさくしつ$"
GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "{JPN}4かい スタジオ2$"