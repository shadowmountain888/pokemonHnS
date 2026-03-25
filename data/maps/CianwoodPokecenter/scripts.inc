.set LOCALID_NURSE, 1

CianwoodPokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "{JPN}みずポケモンなら\nメノクラゲがだんぜん\lいちばんだぜ！$"
CianwoodPokemoncenter_Text_Fisher2:
	.string "{JPN}きみはみずポケモンが\nひつようそうだね\pこいつをもっていきなよ\nたくさんもってるからさ$"
CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "{JPN}ぬおぉぉー！\n"
	.string "{JPN}はげしくながれおちるたきが\l"
	.string "{JPN}わしのあたまのうえに\l"
	.string "{JPN}ズドドドド..ってコラー！\p"
	.string "{JPN}かってにみずをとめるなー！\n"
	.string "{JPN}わしのしゅぎょうの\l"
	.string "{JPN}じゃまをしおってー！\p"
	.string "{JPN}いっとくがわしはつよいぞ！\n"
	.string "{JPN}こうやってまいにち\l"
	.string "{JPN}たきにうたれているからな！\p"
	.string "{JPN}なに？\n"
	.string "{JPN}ポケモンとはかんけいない？\p"
	.string "...\n"
	.string "{JPN}それもそうだ\p"
	.string "...\n"
	.string "...\p"
	.string "{JPN}ではしょうぶといくかぁ！$"

CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "{JPN}このまちのポケモンジムは\nあらくれものばかり！\pそばにいるとオレまで\nふっとばされそうだ\pだからここでアドバイス\nジムリーダーがつかうのは\nかくとうタイプ！\pだったらこっちは\nエスパーポケモンでまどわしてやれ！\pあいてがパワーをはっきするまえに\nたおしてやるんだ！\pそれからジムのまんなかの\nいわのことだが\pただしくうごかさないと\nジムリーダーにたどりつけない\pつまったらそとにでるんだ$"
CianwoodCity_Text_GymGuideWin:
	.string "{JPN}{PLAYER}！かったな！\nみればわかるぜ！$"
CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "{JPN}じぶんのポケモンって\nひとにみせたくなるよね！\pそうおもわない？\pたくさんバトルして\nぼくのポケモンをみせびらかすぞ！$"