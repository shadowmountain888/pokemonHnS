GoldenrodCity_RadioTower_2F_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3 GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4 GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5 GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26 GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena2::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "{JPN}ブエナ:え?きょうの\n"
	.string "{JPN}あいことばって?\lもちろん たすけて よ!$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "{JPN}ラジオはどこでもきけるよ\nチューンインしてね！$"
GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "{JPN}ここからさきは\nたちいりきんしです$"
GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "{JPN}ラジオのこもりうたで\nポケモンがねちゃうかも$"
GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "{JPN}なぜラジオとうを\nのっとろうとするのかしら？$"
GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "{JPN}プリンプリン.$"
GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "{JPN}すみません かんけいしゃいがい\nたちいりきんしです\pまえはこんなじゃなかったのに\pきょくちょうのようすが\nなんかおかしくて.$"
GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "{JPN}どこでもじゆうに\nみてまわってください\pきょくちょうもまえのように\nやさしくなりましたから$"
GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "{JPN}さんねんまえロケットだんは\nかいさんさせられた\pだがここでふっかつするぜ！$"
GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "{JPN}ぐわあ！ちょうしにのるなよ！$"
GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "{JPN}オレたちのふっかつけいかくを\nじゃまはさせないぞ！$"
GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "{JPN}オレたちはロケットだん\nポケモンをあくようするだんたい\pあくじがすきなんだ！こわいか？$"
GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "{JPN}じぶんがヒーローだとおもってるのか？$"
GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "{JPN}オレたちはいつもあくじゃない\nすきなようにやってるだけさ$"
GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "{JPN}おいおい！じゃまするんじゃねえ！$"
GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "{JPN}あ-あ まいったよ$"
GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "{JPN}オレたちのかんぶたちが\nここをのっとろうとしてる\pなにかおおきなけいかくがあるらしい\nいったいなんだろうな？$"
GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "{JPN}ははは!\p"
	.string "{JPN}つまらないね.ここを\n"
	.string "{JPN}のっとるのは あまりにも\l"
	.string "{JPN}かんたんだったよ!\pさあ わたしを\nたのしませてよ!$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "{JPN}だ だれなのよあんた？$"
GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "{JPN}わたしにかつなんて\nわすれないからね！$"
GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "{JPN}ブエナ:あいことばしょうを\nきいてくださいね！$"
GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "{JPN}2F えいぎょうぶ$"
GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "{JPN}オーキドはかせの\pポケモンこうざ\pでんぱにのってるいちばんの\nにんきばんぐみ！$"
GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "{JPN}どこでもいつでもポケモンラジオ$"