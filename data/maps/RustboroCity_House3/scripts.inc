RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "{JPN}わたしは じぶんの ポケモンに\n"
	.string "{JPN}ぴったりの ニックネームを\n"
	.string "{JPN}つけているのよ!\p"
	.string "{JPN}これは わたしの どくそうせい\nっていうか...\nオリジナリティよ そうよ!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "{JPN}でも ピカチュウに ペカチュウって\n"
	.string "{JPN}なまえを つけるのは\n"
	.string "{JPN}いみが ないわよね\p"
	.string "{JPN}わかりやすい なまえを つかうのは\nいいことだと おもうけど...$"
RustboroCity_House3_Text_Pekachu:
	.string "{JPN}ペカチュウ: ペカ!$"

