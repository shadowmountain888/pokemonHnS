LavenderTown_SoulHouse_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "{JPN}フジろうじん: ようこそ.\p"
	.string "{JPN}ふむ... あなたは ポケモンを\n"
	.string "{JPN}やさしく あいじょうをもって\l"
	.string "{JPN}そだてているようじゃな.\p"
	.string "{JPN}ポケモンを あいする ひとたちが\n"
	.string "{JPN}ここへ きて なくなった\l"
	.string "{JPN}ポケモンに おいのりするのじゃ.\n"
	.string "{JPN}なくなった ポケモンの たましいに\n"
	.string "{JPN}ついとうを ささげてくだされ.\p"
	.string "{JPN}そうすれば ポケモンたちも\n"
	.string "{JPN}きっと よろこんでくれるじゃろう.$"

SoulHouse_Text_Teacher:
	.string "{JPN}ここには ほかにも ポケモンの\n"
	.string "{JPN}おはかが あると おもいます.\p"
	.string "{JPN}フジろうじんしか はいれない\n"
	.string "{JPN}へやが たくさん あります.$"

SoulHouse_Text_Lass:
	.string "{JPN}おかあさんと いっしょに\n"
	.string "{JPN}ポケモンの おはかに\lおまいりに きました...$"
SoulHouse_Text_Granny:
	.string "{JPN}わたしと いっしょに くらしていた\n"
	.string "{JPN}ポケモンたち...\p"
	.string "{JPN}まごのように\nかわいがっていました...$"
