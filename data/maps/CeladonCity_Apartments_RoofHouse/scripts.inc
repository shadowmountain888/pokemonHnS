CeladonCity_Apartments_RoofHouse_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_REST, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_REST
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "{JPN}おそろしいはなしを\nきかせてあげよう...$"
CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "{JPN}それにしても まだ\n"
	.string "{JPN}そとが あかるいうちは\l"
	.string "{JPN}それほど こわくないね.\pゆうひが しずんだあと \nまた きてくれる?$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "{JPN}むかしむかし あるところに\n"
	.string "{JPN}あたらしいじてんしゃを\l"
	.string "{JPN}もらったおとこのこがいた...\p"
	.string "{JPN}そのこは すぐにでも\n"
	.string "{JPN}のりたくてたまらなかった...\p"
	.string "{JPN}とてもたのしくて\n"
	.string "{JPN}ひがくれるのもきづかずに\l"
	.string "{JPN}のりつづけていた...\p"
	.string "{JPN}まっくらなよるみちを\n"
	.string "{JPN}いえにかえろうとすると\l"
	.string "{JPN}jてんしゃがとつぜんおもく!\p"
	.string "{JPN}ペダルがこげなくなった!\p"
	.string "{JPN}こぐのをやめると\n"
	.string "{JPN}じてんしゃはうしろに\l"
	.string "{JPN}すべりはじめた!\p"
	.string "{JPN}まるでじてんしゃに\n"
	.string "{JPN}のろいがかかって\l"
	.string "{JPN}やみにひきずりこまれそう!\p"
	.string "{JPN}...\p"
	.string "{JPN}...\p"
	.string "{JPN}キャーーーーッ!\p"
	.string "{JPN}そのおとこのこは\n"
	.string "{JPN}サイクリングロードの\l"
	.string "{JPN}のぼりざかをはしっていたのだ!\p...\nちゃんちゃん!\pさいごまでよくきいてくれた\nきみにこれをあげよう\lわざマシン44ばんだ!$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "{JPN}わざマシン44は ねむるよ.\p"
	.string "{JPN}たたかいの さいちゅうに\n"
	.string "{JPN}ポケモンを ねむらせて\l"
	.string "{JPN}たいりょくを かいふく\l"
	.string "{JPN}させることが できるんだ.\pでも あの おそろしい\nはなしの あとじゃ \lねむるのも たいへんだろうね!$"

