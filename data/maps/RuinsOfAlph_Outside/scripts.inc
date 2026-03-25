RuinsOfAlph_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "{JPN}ヌオー: ヌオー ヌオー$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "{JPN}ん? それは ポケモンずかん\n"
	.string "{JPN}ですね?\n"
	.string "{JPN}みせて もらえますか?\p"
	.string "{JPN}とても たくさんの しゅるいの\n"
	.string "{JPN}ポケモンが いるんですね.\p"
	.string "{JPN}ん? これは?\p"
	.string "{JPN}この ポケモンは なんでしょう?\p"
	.string "{JPN}いせきの かべに かいてある\n"
	.string "{JPN}ふしぎな もじに\p"
	.string "{JPN}にているようですが.\p"
	.string "{JPN}もし あの えが ほんとうに\n"
	.string "{JPN}ポケモンなら もっと たくさん\n"
	.string "{JPN}iるはずです.\p"
	.string "{JPN}そうだ! あなたの ポケモンずかんを\nパワーアップして あげましょう.\nついてきて ください.$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "{JPN}なんの ようだい? けんきゅうちゅう\n"
	.string "{JPN}なんだ-- じゃまするな!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "{JPN}ごめん...\n"
	.string "{JPN}ぼくらの りかいが たりなくて\p"
	.string "{JPN}くやしいよ...$"
RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "{JPN}アルフのいせきは やく1500ねん\n"
	.string "{JPN}まえの ものなんだ.\p"
	.string "{JPN}だれが つくったのかは\n"
	.string "{JPN}だれも しらない.\p"
	.string "{JPN}ポケモンの せきぞうに いみが\n"
	.string "{JPN}あるのかも わからないんだ.\pすべてが なぞに つつまれて\nいるよ...$"
RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "{JPN}うーん... ここは ふしぎな\nばしょだ.$"
RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "{JPN}...$"
RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "{JPN}ここで かんがえごとを するのが\nすきなんだ.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "{JPN}なぞの いしばん のへや$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "{JPN}アルフの いせき\n"
	.string "{JPN}けんがく じゆう$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "{JPN}アルフのいせき けんきゅうセンター\p"
	.string "{JPN}アルフのいせきの\n"
	.string "{JPN}けんきゅうきかん$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "{JPN}いせきを たんけんしていたら\n"
	.string "{JPN}きゅうに へんな けはいがしたんだ.\p"
	.string "{JPN}みんな こわくなって\n"
	.string "{JPN}にげちゃったよ.\nきみも きをつけたほうが いいよ.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "{JPN}アルフのいせきには おおきな\n"
	.string "{JPN}ひみつが かくされているんだ!\p...たぶん...$"
RuinsOfAlph_Outside_Text_Youngster1:
	.string "{JPN}アンノーンには いろんな かたちが\n"
	.string "{JPN}あるから ひみつの あんごうに\nつかってるんだ.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "{JPN}A... H... E... A... D... うーん...\p"
	.string "{JPN}なに?\p"
	.string "{JPN}あんごうを かいどく してるんだ!$"
