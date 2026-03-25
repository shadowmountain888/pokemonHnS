UnionCave_B1F_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_SecretPower::
	finditem ITEM_TM_SECRET_POWER
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "{JPN}ひとを みるのは\n"
	.string "{JPN}ひさしぶりだなあ.\p"
	.string "{JPN}えんりょ しないで\nバトル しようぜ!$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "{JPN}うううう...$"
UnionCave_B1F_Text_HikerPhillipAfter:
	.string "{JPN}ながいあいだ みちに\n"
	.string "{JPN}まよってるんだよ...\p"
	.string "{JPN}ここも わるくないけど\nおなかが すいて しょうがない!$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "{JPN}おお! きゃくさんじゃ\nないか!$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "{JPN}わはははっ! きみは\nつよいやつだな!$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "{JPN}わしは ここに\n"
	.string "{JPN}すんでおるんじゃ.\p"
	.string "{JPN}きみも よかったら\nすんでみるかい?\pばしょは たくさん\nあるからのう.$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "{JPN}だれだ?\p"
	.string "{JPN}ぼくと ぼくの ポケモンを\nほっといてくれ!$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "{JPN}あっち... あっちいけ!$"
UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "{JPN}ぼくと ポケモンだけの\n"
	.string "{JPN}じかん. うれしくて\nとうが たっているよ.$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "{JPN}ポケモンけんきゅうの\n"
	.string "{JPN}ために ここまで\n"
	.string "{JPN}きたんだ.\p"
	.string "{JPN}じっせんバトルで\nけんきゅう せいかを\nはっぴょう するぜ!$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "{JPN}ぼくの ほうが\nじっけんされちゃったよ!$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "{JPN}けんきゅう けっかを\n"
	.string "{JPN}まとめて はっぴょう\n"
	.string "{JPN}しなくちゃ.\p"
	.string "{JPN}うまくいけば ウツギ\nはかせみたいに ゆう\nめいに なれるかも.$"
