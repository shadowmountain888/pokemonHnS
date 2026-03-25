EcruteakCity_Gym_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "{JPN}エンジュシティポケモンジム$"
EcruteakCity_Gym_Text_GymStatueCertified:
	.string "{JPN}エンジュシティポケモンジム\p"
	.string "{JPN}ジムリーダーマツバ\nにんていトレーナー!\l{PLAYER}$"

MortyIntroText:
	.string "{JPN}マツバ: よくきたね\p"
	.string "{JPN}ここエンジュでは\nむかしからポケモンを\lかみさまとしてまつっていた\p"
	.string "{JPN}そしてしんのじつりょくを\nそなえたトレーナーのまえに\l"
	.string "{JPN}でんせつのポケモンはまいおりる\lそうつたえられている...\p"
	.string "{JPN}ぼくはそのいいつたえをしんじ\nうまれたときからここで\l"
	.string "{JPN}ひみつのしゅぎょうをしてきた\p"
	.string "{JPN}そのおかげで\nほかのひとにはみえないものも\lみえるようになった...\p"
	.string "{JPN}ぼくにみえるのは\nこのちにでんせつのポケモンを\l"
	.string "{JPN}よびよせるじんぶつのかげ...\p"
	.string "{JPN}ぼくはそれがぼくじしんだと\nしんじているよ!\p"
	.string "{JPN}そしてそのためのしゅぎょう\nきみにも\lきょうりょくしてもらおう!\p$"

MortyWinLossText:
	.string "{JPN}マツバ: しょうぶのじつりょくでは\nそれほどまけていないはず!\p"
	.string "{JPN}けれどきみには\nそれだけではないなにかが...\p"
	.string "{JPN}わかった\nこのバッジはきみのものだよ!\p$"

Text_ReceivedFogBadge:
	.string "{JPN}{PLAYER}は マツバから\nファントムバッジを もらった!$"

MortyText_FogBadgeSpeech:
	.string "{JPN}マツバ: ファントムバッジがあれば\nひとからもらったポケモンでも\l"
	.string "{JPN}レベル50までのポケモンなら\lきみのいうことにしたがうはずだ\p"
	.string "{JPN}それだけじゃないぞ\nなみのりというわざが\lつかえるようになるんだ!\p"
	.string "{JPN}それから...\nこれもきみにゆずろう\p$"

MortyText_ShadowBallSpeech:
	.string "{JPN}マツバ: なかみはシャドーボール\p"
	.string "{JPN}ただこうげきするだけでなく\nまれにとくしゅぼうぎょもさげる\p"
	.string "{JPN}きにいったらつかうといいよ$"

MortyFightDoneText:
	.string "{JPN}マツバ: そうか...\p"
	.string "{JPN}このあいだまいこさんたちが\nいってたのはきみのこと...\p"
	.string "{JPN}あ!いやいやなんでもない\nきにしないでくれよ\p"
	.string "{JPN}それだけのつよさをもつ\nきみならうみをわたっても\l"
	.string "{JPN}だいじょうぶそうだね\p"
	.string "{JPN}ここからにしへいき\nさらにみなみへくだっていくと\lアサギシティがある"
	.string "{JPN}\lそちらへいってごらん...$"

MortyRematchText:
	.string "{JPN}おお ジョウトの チャンピオン!\n"
	.string "{JPN}よく きてくれた.\p"
	.string "{JPN}きみの つよさと わざまえは\n"
	.string "{JPN}しっているが ぜんかい\l"
	.string "{JPN}たたかってから せいちょうしたかな?\p"
	.string "{JPN}それいらい ゴーストタイプの\n"
	.string "{JPN}ポケモンたちと しゅぎょうを\l"
	.string "{JPN}つづけてきた.\p"
	.string "{JPN}もういちど やみを のりこえる\n"
	.string "{JPN}ことが できるかな.\nさいせんを したいか?$"

Morty_RematchDefeatText:
	.string "{JPN}まだまだ しゅぎょうが\n"
	.string "{JPN}たりないな...\p"
	.string "{JPN}きみは わたしが みたことも\n"
	.string "{JPN}ない ものを みてきた.\pうらやましい かぎりだ...$"

SageJeffreySeenText:
	.string "{JPN}はるを ポケモンと ともに\n"
	.string "{JPN}すごした.\p"
	.string "{JPN}それから なつ あき ふゆ...\p"
	.string "{JPN}そして また はるが きた.\n"
	.string "{JPN}ながい あいだ いっしょだった.$"

SageJeffreyBeatenText:
	.string "{JPN}しょうりも はいぼくも\n"
	.string "{JPN}どちらも あじわってきた.$"

SageJeffreyAfterBattleText:
	.string "{JPN}ポケモンは どこから\nきたのだろうな?$"

SagePingSeenText:
	.string "{JPN}わしらの ポケモンに\n"
	.string "{JPN}ダメージを あたえることが\lできるかな?$"

SagePingBeatenText:
	.string "{JPN}ああ! みごとじゃ!$"

SagePingAfterBattleText:
	.string "{JPN}わしらは ゴーストタイプの\n"
	.string "{JPN}ポケモンを つかう.\p"
	.string "{JPN}ノーマルタイプの わざでは\nきずつけることが できん!$"

MediumMarthaSeenText:
	.string "{JPN}わたしが かちます!$"

MediumMarthaBeatenText:
	.string "{JPN}わ... わた... わたしが\nまけるなんて!$"

MediumMarthaAfterBattleText:
	.string "{JPN}いちばん かちたい きもちの\n"
	.string "{JPN}つよい ひとが かつのです!$"

MediumGraceSeenText:
	.string "{JPN}くらい ろうかに まよった?\n"
	.string "{JPN}ヒントが ほしければ\lわたしを たおしなさい!$"

MediumGraceBeatenText:
	.string "{JPN}な... なんですって?$"

MediumGraceAfterBattleText:
	.string "{JPN}いいでしょう.かげの ひみつを\n"
	.string "{JPN}おしえて あげます.\p"
	.string "{JPN}みちは あなたの めのまえに\n"
	.string "{JPN}あるのよ!$"

EcruteakCity_GymGuideText:
	.string "{JPN}おーす!\nみらいのチャンピオン!\p"
	.string "{JPN}このジムのトレーナーたちは\nゴーストタイプのポケモンを\l"
	.string "{JPN}じざいにあやつってくる!\p"
	.string "{JPN}ゴーストとはぼうれい\nそしてまぼろしのようなもの...\p"
	.string "{JPN}ちからまかせにぶつかっても\nききめはないはずだ!$"

EcruteakCity_GymGuideWinText:
	.string "{JPN}ふはー{PLAYER}\nよくかてたな!\p"
	.string "{JPN}おれなんかこわくて\nすみっこでふるえてたぜ$"

EcruteakCity_GymClosedText:
	.string "{JPN}なんじゃジムリーダーにようか?\p"
	.string "{JPN}リーダーのマツバは\nいまやけたとうにでかけとる\p"
	.string "{JPN}すまんがおひきとりねがおうかの\nほっほっほっほ\p$"
