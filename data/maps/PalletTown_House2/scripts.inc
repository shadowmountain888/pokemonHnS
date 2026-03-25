PalletTown_House2_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "{JPN}わたしのおとうと\n"
	.string "{JPN}トキワシティのジムリーダー\p"
	.string "{JPN}しょっちゅうジムをるすにして\n"
	.string "{JPN}みんなをこまらせてるみたい$"
PalletTown_House2_Text_OfferGrooming:
	.string "{JPN}デイジー: こんにちは!\n"
	.string "{JPN}ちょうど いい タイミングね.\l"
	.string "{JPN}これから おちゃを のもうと\l"
	.string "{JPN}おもってたの.\p"
	.string "{JPN}いっしょに のまない?\pあら あなたの ポケモン\nすこし よごれてるわね.\pわたしが きれいに して\nあげましょうか?$"

PalletTown_House2_Text_WhichMon:
	.string "{JPN}どのポケモンにする？$"
PalletTown_House2_Text_Alright:
	.string "{JPN}デイジー: はい すぐに\n"
	.string "{JPN}きれいに してあげるわね.$"

PalletTown_House2_Text_AllDone:
	.string "{JPN}はい！\n"
	.string "{JPN}とってもきれいになったわ！\p"
	.string "{JPN}うふふ\n"
	.string "{JPN}かわいいポケモンね！$"
PalletTown_House2_Text_AlreadyGroomed:
	.string "{JPN}このじかんは\n"
	.string "{JPN}まいにちおちゃをしているの\l"
	.string "{JPN}またきてね！$"
PalletTown_House2_Text_Refused:
	.string "{JPN}けづくろいしないの？\n"
	.string "{JPN}じゃあおちゃにしましょう$"
PalletTown_House2_Text_CantGroomEgg:
	.string "{JPN}うふふ！\n"
	.string "{JPN}タマゴはけづくろいできないわ$"