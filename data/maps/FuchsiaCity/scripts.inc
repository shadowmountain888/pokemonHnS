FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 VAR_FUCHSIA_CITY_STATE, 0,  FuchsiaCity_EventScript_BaobaCall
	.2byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	end

FuchsiaCity_Text_Baoba:
	.string "{JPN}えんちょう バオバ: {PLAYER}!\p"
	.string "{JPN}わしは えんちょう バオバじゃ.\p"
	.string "{JPN}たいへんな ことが おきたのじゃ!\n"
	.string "{JPN}セキチクシティの わしの\l"
	.string "{JPN}ふるい サファリゾーンが\l"
	.string "{JPN}かいしゅうされて さいかいえん\l"
	.string "{JPN}したのじゃ!\p"
	.string "{JPN}そして どうやら しんしゅの\n"
	.string "{JPN}ポケモンが いるらしいのじゃ!\p"
	.string "{JPN}わしの しょうばいの じゃまを\n"
	.string "{JPN}しておるのじゃ!\p"
	.string "{JPN}{PLAYER}よ あたらしい サファリ\n"
	.string "{JPN}ゾーンに いって ポケモンを\l"
	.string "{JPN}つかまえて わしに みせて\lくれんか.その 'しんしゅの'\lポケモンに ついて しりたいのじゃ.\pたのむ {PLAYER}よ わしの\nしょうばいが かかっておるのじゃ!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "{JPN}いまのしてんのうのひとりは\n"
	.string "{JPN}セキチクジムの\l"
	.string "{JPN}ジムリーダーだったんだぜ！$"
FuchsiaCity_Text_PokefanM:
	.string "{JPN}げんざいのジムリーダーは\n"
	.string "{JPN}してんのうになった\l"
	.string "{JPN}キョウさんのむすめさんだよ！$"
FuchsiaCity_Text_Teacher:
	.string "{JPN}サファリゾーンは あたらしい\n"
	.string "{JPN}けいえいしゃに かわったのよ.\p"
	.string "{JPN}そして あたらしい ポケモンが\nたくさん いるのよ!$"

FuchsiaCity_Text_Sign:
	.string "{JPN}セキチクシティ\p"
	.string "{JPN}みよ! じょうねつの ピンクを!$"

FuchsiaCity_Text_GymSign:
	.string "{JPN}セキチクシティポケモンジム\n"
	.string "{JPN}リーダーアンズ\l"
	.string "{JPN}どくのことならなんでもござれ$"
FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "{JPN}ここに おしらせが...\p"
	.string "{JPN}サファリゾーン じむしょは\n"
	.string "{JPN}とうぶんの あいだ へいてんです$"

FuchsiaCity_Text_SafariZone:
	.string "{JPN}サファリゾーン\n"
	.string "{JPN}げんざい デボン\l"
	.string "{JPN}コーポレーション\lしょゆう$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "{JPN}えんちょうは かいがい りょこう\n"
	.string "{JPN}ちゅうです.\p"
	.string "{JPN}そのため サファリゾーンは\nへいえん しております.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "{JPN}ごみの ぽいすて きんし.\p"
	.string "{JPN}ごみは おもちかえり\nください.$"

