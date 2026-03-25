.set LOCALID_CERULEAN_WOMAN, 2
.set LOCALID_CERULEAN_SLOWBRO, 3

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "{JPN}ここは ハナダのどうくつ だよ.\p"
	.string "{JPN}ものすごく つよい ポケモンが\n"
    .string "{JPN}すんでいるんだ.\p"
	.string "{JPN}とくべつな トレーナーじゃ\n"
    .string "{JPN}ないと なかに はいれないよ.\p"
	.string "{JPN}まずは カントーポケモンリーグの\l"
    .string "{JPN}チャンピオンに なれるくらい\l"
	.string "{JPN}つよくないと だめだね.\p"
    .string "{JPN}そして すばらしい じっせきを\n"
	.string "{JPN}のこしていないと いけないんだ.$"

CeruleanCity_Text_CooltrainerM1:
	.string "{JPN}カントーのはつでんしょなら\n"
	.string "{JPN}ひがしにのびている\l"
	.string "{JPN}9ばんどうろのさきだよ\p"
	.string "{JPN}じこがあったらしいけどね$"
CeruleanCity_Text_CooltrainerM2:
	.string "{JPN}ほほう！\n"
	.string "{JPN}すべてのポケモンをあつめてる？\p"
	.string "{JPN}たいへんだろうが\n"
	.string "{JPN}やりがいもあるんだろうな$"
CeruleanCity_Text_SuperNerd:
	.string "{JPN}きたにあるみさきは\n"
	.string "{JPN}おんなのこたちににんきの\l"
	.string "{JPN}デートスポットさ！\p"
	.string "{JPN}ここだけのはなし..\p"
	.string "{JPN}ジムリーダーのカスミちゃんも\n"
	.string "{JPN}みさきのあたりでときどき\l"
	.string "{JPN}もくげきされているとか..\p"
	.string "{JPN}だいショーック！！$"
CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "{JPN}やーあ？$"
CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "{JPN}わたしとヤドランのコンビ\n"
	.string "{JPN}すごいんだから！\p"
	.string "{JPN}さあヤドラン\n"
	.string "{JPN}サイコキネシスだすのよ！\p"
	.string "{JPN}...！！\p"
	.string "{JPN}ヤドランの\n"
	.string "{JPN}サイコキネシスさくれつ！$"
CeruleanCity_Text_CooltrainerF2:
	.string "{JPN}ヤドラン! ねんりきを\nみせて!$"

CeruleanCity_Text_CooltrainerF3:
	.string "{JPN}...$"
CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "{JPN}ハナダジムのカスミちゃん！\n"
	.string "{JPN}ぼくだいファンなんだ！$"
CeruleanCity_Text_Fisher_RocketTip:
	.string "{JPN}くろいふくのあやしいやつが\n"
	.string "{JPN}みさきのほうへにげていったよ！$"
CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "{JPN}まちの きたにある どうくつには\n"
	.string "{JPN}とてつもなく つよい ポケモンが\nいるんだって!$"

CeruleanCity_Text_Youngster2:
	.string "{JPN}あれ?\p"
	.string "{JPN}どうぐファインダーが はんのう してるよ...$"
CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "{JPN}ハナダシティ\p"
	.string "{JPN}しんぴてきな あおいオーラに\nつつまれた まち$"

CeruleanCity_Text_GymSign:
	.string "{JPN}ハナダシティポケモンジム\n"
	.string "{JPN}リーダーカスミ\l"
	.string "{JPN}おてんばにんぎょ$"
CeruleanCity_Text_BikeShopSign:
	.string "{JPN}おしらせが あるよ...\p"
	.string "{JPN}じてんしゃやさんは\n"
	.string "{JPN}コガネシティに ひっこししました...$"
CeruleanCity_Text_PoliceSign:
	.string "{JPN}..チラシがはってある！\p"
	.string "{JPN}ドロボーはやめましょう\n"
	.string "{JPN}みんななかよくあかるいまち\l"
	.string "{JPN}..ハナダけいさつより$"
CeruleanCity_Text_CapeSign:
	.string "{JPN}ハナダのみさき\n"
	.string "{JPN}さき$"

CeruleanCity_Text_LockedDoor:
	.string "{JPN}..カギがかかっている！$"
