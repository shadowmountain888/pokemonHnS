SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE, 9, 3
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE, 9, 3
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	releaseall
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "{JPN}サファリゾーンを\n"
	.string "{JPN}このまま しゅうりょう しますか?$"

SafariZone_Text_TimesUp:
	.string "{JPN}ピンポーン! じかん でーす!\n"
	.string "{JPN}サファリゲームを しゅうりょう します$"

SafariZone_Text_OutOfBalls:
	.string "{JPN}サファリボールを つかいきったので\n"
	.string "{JPN}サファリゲームを しゅうりょう します$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "{JPN}ポロックおきばに\n"
	.string "{JPN}ポロックを おきますか?$"

SafariZone_Text_PokeblockStillHere:
	.string "{JPN}まだ {STR_VAR_1}が のこっています$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{JPN}{STR_VAR_1}を\n"
	.string "{JPN}おきました!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "{JPN}サファリゾーンへ ようこそ!\p"
	.string "{JPN}ここでは ホウエンでは なかなか\n"
	.string "{JPN}みることの できない ポケモンを\p"
	.string "{JPN}しぜんの すがたの まま\n"
	.string "{JPN}めに することが できます\p"
	.string "{JPN}また ポケモントレーナーの\n"
	.string "{JPN}ようぼうに おこたえ して\p"
	.string "{JPN}ポケモンを\n"
	.string "{JPN}つかまえる ことも できます!\p"
	.string "{JPN}サファリゾーンを たのしんで いってね!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "{JPN}サファリゾーンへ ようこそ!\n"
	.string "{JPN}サファリゾーンは はじめて ですか?$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "{JPN}サファリゾーンを たのしんで いってね!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "{JPN}サファリゾーンでは\n"
	.string "{JPN}30この サファリボールを つかって\l"
	.string "{JPN}ポケモンを つかまえる ことが できます\p"
	.string "{JPN}サファリボールを つかいきるか\n"
	.string "{JPN}500ぽ あるくと\p"
	.string "{JPN}ゲームは しゅうりょう です\p"
	.string "{JPN}サファリゾーンを たのしんで いってね!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "{JPN}サファリゾーンへ ようこそ!\p"
	.string "{JPN}500えんで ポケモン つかまえほうだい!\n"
	.string "{JPN}サファリゲームに さんか しますか?$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "{JPN}そうですか\n"
	.string "{JPN}こんど ぜひ さんか してください!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "{JPN}おかねが たりませんよ!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "{JPN}それでは 500えん いただきます$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "{JPN}では サファリボールを どうぞ!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{JPN}{PLAYER}は サファリボールを\n"
	.string "{JPN}30こ うけとった!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "{JPN}じかんに なりましたら\n"
	.string "{JPN}こちらから おしらせ しますので\p"
	.string "{JPN}ぞんぶんに おたのしみ ください!\n"
	.string "{JPN}では いってらっしゃい!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_PCIsFull:
	.string "{JPN}おきゃくさん!\n"
	.string "{JPN}ボックスが いっぱい ですよ!$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "{JPN}あ! おきゃくさん\n"
	.string "{JPN}ポロックケースを おもちで ないですね?\p"
	.string "{JPN}サファリゾーンは ポロックを つかうと\n"
	.string "{JPN}より おたのしみ いただけますので\p"
	.string "{JPN}ぜひ ポロックケースを\n"
	.string "{JPN}おもちに なって おこし ください\p"
	.string "{JPN}ポロックケースは\n"
	.string "{JPN}ミナモシティの コンテストかいじょうで\l"
	.string "{JPN}うけとることが できますよ$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "{JPN}まだ じかんが のこっていますが\n"
	.string "{JPN}サファリゾーンを やめますか?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "{JPN}では ひきつづき おたのしみ ください!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "{JPN}わかりました\p"
	.string "{JPN}それでは のこりの サファリボールを\n"
	.string "{JPN}おあずかり します\p"
	.string "{JPN}おつかれさまでした\n"
	.string "{JPN}また ごりよう ください$"

SafariZone_South_Text_GoodLuck:
	.string "{JPN}それでは いってらっしゃい!\l"
	.string "{JPN}なにか ありましたら\n"
	.string "{JPN}わたしに こえを かけて くださいね$"

SafariZone_South_Text_Boy:
	.string "{JPN}しってた?\p"
	.string "{JPN}あの しかくい はこに ポロックを おくと\n"
	.string "{JPN}ポケモンが あつまって くるんだよ!$"

SafariZone_South_Text_Man:
	.string "{JPN}この さきに いきたい けど\n"
	.string "{JPN}じてんしゃ もって くるの わすれた...\p"
	.string "{JPN}おくに めずらしい ポケモンが\n"
	.string "{JPN}いそうな きが するのに!$"

SafariZone_Southwest_Text_Woman:
	.string "{JPN}ポケモンに ポロックを なげても\n"
	.string "{JPN}しらんぷり される ときが あるのよ\p"
	.string "{JPN}ポケモンにも すききらいが あるのかしら?$"

SafariZone_Northwest_Text_Man:
	.string "{JPN}ぜぇ... ぜぇ...\n"
	.string "{JPN}やっと ここまで きたけど...\p"
	.string "{JPN}つかれちゃって ポケモン つかまえる\n"
	.string "{JPN}げんきも のこって ないよ...$"

SafariZone_North_Text_Fisherman:
	.string "{JPN}ホウエンに いない みずポケモンを\n"
	.string "{JPN}さがしに きたんだけど...\p"
	.string "{JPN}みずうみは どこにあるのか\n"
	.string "{JPN}きみ しってるかい?$"

SafariZone_North_Text_Man:
	.string "{JPN}ここで めずらしい ポケモンを\n"
	.string "{JPN}たくさん つかまえて\l"
	.string "{JPN}ともだちと こうかん するんだ!$"

SafariZone_South_Text_Youngster:
	.string "{JPN}ポロックおきばに おいた ポロックが\n"
	.string "{JPN}いつのまにか なくなっていた...\p"
	.string "{JPN}しらない うちに\n"
	.string "{JPN}ポケモンが たべちゃったのかな?$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_TrainerTip:
	.string "{JPN}サファリゾーンの おとくな じょうほう!\p"
	.string "{JPN}であった ポケモンに\n"
	.string "{JPN}ポロックを なげると にげにくく なります!$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "{JPN}あるき つかれたら ちょっと ひといき!\n"
	.string "{JPN}みんなの きゅうけいじょ$"

SafariZone_RestHouse_Text_Youngster:
	.string "{JPN}おれ ポロック もってないけど\n"
	.string "{JPN}ポケモン たくさん つかまえたよ\p"
	.string "{JPN}ちかづいて ボールを なげる だけで\n"
	.string "{JPN}けっこう つかまえられる もんだよ!$"

SafariZone_RestHouse_Text_PsychicM:
	.string "{JPN}ポロックを つかうと いつもより\n"
	.string "{JPN}ちょっぴり にげにくく なるみたい\p"
	.string "{JPN}だから にげにくい ポケモンに つかっても\n"
	.string "{JPN}あんまり いみが ないかもね$"

SafariZone_RestHouse_Text_FatMan:
	.string "{JPN}ポロックおきばに ポロック おいて\n"
	.string "{JPN}ポケモンを つかまえると\p"
	.string "{JPN}おなじ ような せいかくの ポケモンが\n"
	.string "{JPN}あつまる きが するなあ$"

SafariZone_South_Text_AreaOffLimits1:
	.string "{JPN}このさきは ただいま こうじちゅう のため\n"
	.string "{JPN}たちいり きんしに なっています$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "{JPN}サファリゾーンの かくちょう こうじが\n"
	.string "{JPN}しゅうりょう しました\p"
	.string "{JPN}あたらしい エリアも\n"
	.string "{JPN}たのしんで くださいね!$"

SafariZone_South_Text_AreaOffLimits2:
	.string "{JPN}このさきは ただいま こうじちゅう のため\n"
	.string "{JPN}たちいり きんしに なっています$"

SafariZone_Southeast_Text_LittleGirl:
	.string "{JPN}わーい わーい!\n"
	.string "{JPN}はじめて みる ポケモンが いっぱい!$"

SafariZone_Southeast_Text_FatMan:
	.string "{JPN}このへんに いる ポケモンは\n"
	.string "{JPN}はじめて みるやつ ばっかりだ!\p"
	.string "{JPN}そんな めずらしい ポケモンが\n"
	.string "{JPN}つかまえ ほうだい だなんて すげー!$"

SafariZone_Southeast_Text_RichBoy:
	.string "{JPN}このへんに いる ポケモンは\n"
	.string "{JPN}ホウエンちほう いがいの とちに\l"
	.string "{JPN}すんでる ポケモン らしいぜ$"

SafariZone_Northeast_Text_Boy:
	.string "{JPN}サファリボールが あと すこししか\n"
	.string "{JPN}のこって ないんだよ\l"
	.string "{JPN}なにを つかまえるか まよっちゃうなあ$"

SafariZone_Northeast_Text_Woman:
	.string "{JPN}ピカチュウが ここで みられるって\n"
	.string "{JPN}きいたんだけど どこに いるのかしら$"

SafariZone_Northeast_Text_Girl:
	.string "{JPN}あーん ポケモンが\n"
	.string "{JPN}なかなか つかまらないわっ!\p"
	.string "{JPN}このままじゃ にゅうじょうりょうの\n"
	.string "{JPN}モトが とれないわっ!$"
