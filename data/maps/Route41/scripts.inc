Route41_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "{JPN}ここの みずは あったかいね.\n"
	.string "{JPN}からだも ほぐれて きもちいいよ.\p"
	.string "{JPN}よし きみと しょうぶだ!$"

Route41_Text_SwimmermCharlieBeaten:
	.string "{JPN}うわあ! ゆびが しわしわに\nなっちゃったよ!$"

Route41_Text_SwimmermCharlieAfter:
	.string "{JPN}こうやって ぷかぷか\n"
	.string "{JPN}うかんでるだけで きもちいいね.$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "{JPN}ちょっと つかれちゃった.\n"
	.string "{JPN}もし ぼくが かったら\nきみの ポケモン かして.$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "{JPN}はあ はあ...$"
Route41_Text_SwimmermGeorgeAfter:
	.string "{JPN}タンバシティまで とおいなあ.\p"
	.string "{JPN}でも アサギシティに かえるのも\n"
	.string "{JPN}たいへんだし.\p"
	.string "{JPN}どうしようかな?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "{JPN}うずまきで ふうじられてる\n"
	.string "{JPN}しまじま みえるでしょ?\p"
	.string "{JPN}ぜったい ひみつが あるはずだ!$"

Route41_Text_SwimmermBerkeBeaten:
	.string "{JPN}きみの つよさの ひみつは\n"
	.string "{JPN}なんなんだ?$"

Route41_Text_SwimmermBerkeAfter:
	.string "{JPN}あれは あらしの よるのことでした...\p"
	.string "{JPN}おおきな ポケモンが しまから\n"
	.string "{JPN}とんでくるのを みたんです.\p"
	.string "{JPN}ぎんいろの はねから\n"
	.string "{JPN}はねを ちらしていました$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "{JPN}ここは なみが はげしいね.\p"
	.string "{JPN}およいでると つかれちゃうよ.$"
	.string ""

Route41_Text_SwimmermKirkBeaten:
	.string "{JPN}まいったよ!$"

Route41_Text_SwimmermKirkAfter:
	.string "{JPN}かいりゅうが つよくて\n"
	.string "{JPN}あの しまに たどりつけないよ.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "{JPN}きみも うずまきじまの\n"
	.string "{JPN}ひみつを さがしてるの?$"

Route41_Text_SwimmermMathewBeaten:
	.string "{JPN}おお すごい たいりょくだね!$"

Route41_Text_SwimmermMathewAfter:
	.string "{JPN}うずまきじまの ひみつを\n"
	.string "{JPN}おしえてあげよう...\pなかは まっくらなんだ!$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "{JPN}わたし うずまきじまに\n"
	.string "{JPN}いくところなの.\pともだちと たんけんしに いくのよ.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "{JPN}そういう ほうほうなのね?$"

Route41_Text_SwimmerfKayleeAfter:
	.string "{JPN}うずまきじまの おくふかくに\n"
	.string "{JPN}おおきな ポケモンが いるって\n"
	.string "{JPN}うわさよ.\pいったい なんの ポケモンかしら?$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "{JPN}ポケモンに のって\n"
	.string "{JPN}ゆうがに およいでるのね.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "{JPN}まけちゃった...$"
Route41_Text_SwimmerfSusieAfter:
	.string "{JPN}むかし ラプラスに のった\n"
	.string "{JPN}おとこのこの うたが\nはやったって きいたことある.$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "{JPN}こんなに てんきが よくて\n"
	.string "{JPN}ぼーっと しちゃうわ!$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "{JPN}あらら!$"

Route41_Text_SwimmerfDeniseAfter:
	.string "{JPN}ひやけは はだに よくないけど\n"
	.string "{JPN}ひやけどめは つかわないの.\p"
	.string "{JPN}みずを よごしたく ないからね.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "{JPN}つかれたら その ばで\n"
	.string "{JPN}ばたあし するのよ.\p"
	.string "{JPN}そうすれば たいりょくが\n"
	.string "{JPN}かいふくして つづけられるわ.$"

Route41_Text_SwimmerfKaraBeaten:
	.string "{JPN}あら! あなたのほうが\nげんきね.$"

Route41_Text_SwimmerfKaraAfter:
	.string "{JPN}しまの おくから\n"
	.string "{JPN}うなりごえが きこえたの.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "{JPN}よるに なると スターミーが\n"
	.string "{JPN}みずめんに あつまってくるのよ.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "{JPN}あらあら...$"
Route41_Text_SwimmerfWendyAfter:
	.string "{JPN}スターミーの むれが\n"
	.string "{JPN}いっせいに ひかりだすの.\p"
	.string "{JPN}とても きれいで ちょっと\nこわいくらいよ.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "{JPN}テンタクルエル: クルオー...$"

Route41_Text_TentacruelAttack:
	.string "{JPN}テンタクルエル: クルオオオオオ!$"

Route41_Text_TentacruelHeal:
	.string "{JPN}テンタクルエルは じこさいせいを\n"
	.string "{JPN}つかった!\nたいりょくが かいふくした!$"
