PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "{JPN}ニビのジムにはいった？\p"
	.string "{JPN}いわタイプのポケモンをつかう\n"
	.string "{JPN}ジムリーダーがいるわよ！$"
PewterCity_Text_BugCatcher:
	.string "{JPN}よるになるとおつきみやまに\n"
	.string "{JPN}ピッピがやってくるらしいよ\p"
	.string "{JPN}まいにちじゃないみたいだけど$"
PewterCity_Text_Gramps:
	.string "{JPN}ほう！\n"
	.string "{JPN}ジョウトからはるばるきたのか！\p"
	.string "{JPN}うむなつかしいの\n"
	.string "{JPN}わしもわかいころジョウトで\l"
	.string "{JPN}トレーナーしゅぎょうをしてたのだ\p"
	.string "{JPN}きみにはしたしみがわくよ\n"
	.string "{JPN}ジョウトでみつけたこのはね\l"
	.string "{JPN}きみにおゆずりしようぞ！$"
PewterCity_Text_Gramps_GotSilverWing:
	.string "{JPN}いろんなところへいき\n"
	.string "{JPN}いろんなはっけんをする\l"
	.string "{JPN}それがたびのだいごみなんだ$"
PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "{JPN}ニビシティ\n"
	.string "{JPN}いしのいろの まち$"

PewterCity_Text_GymSign:
	.string "{JPN}ニビシティポケモンジム\n"
	.string "{JPN}リーダータケシ\l"
	.string "{JPN}つよくてかたいいしのおとこ$"
PewterCity_Text_MuseumSign:
	.string "{JPN}ニビかがくはくぶつかん$"
PewterCity_Text_MtMoonGiftShopSign:
	.string "{JPN}おしらせが はってある...\p"
	.string "{JPN}おつきみやま ギフトショップ\nオープンしました!$"

PewterCity_Text_WelcomeSign:
	.string "{JPN}ようこそニビシティへ！$"
