@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "{JPN}このポケモンは まえに ここで\n"
	.string "{JPN}ビューティーコンテストに\l"
	.string "{JPN}かったことが あるのよ.\p"
	.string "{JPN}それが なんと きょうは\n"
	.string "{JPN}かしこさコンテストでも\lかっちゃったの!\pわたしの うでまえ じぶんでも\nこわくなっちゃうわ...$"
LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "{JPN}わたし たくさんの コンテスト に\n"
	.string "{JPN}さんか したから しくみ が\l"
	.string "{JPN}わかって きた よ\p"
	.string "{JPN}かっこよさ コンテスト なら\n"
	.string "{JPN}かっこいい わざ が アピール に\l"
	.string "{JPN}こうか てきめん なんだ\pでも かしこさ や かわいさ の\nわざ は ぜんぜん だめ なんだって$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "{JPN}さっき かった あの わかもの\n"
	.string "{JPN}いろんな ポロック を\l"
	.string "{JPN}いっぱい もって いたね\p"
	.string "{JPN}そんなに たくさん あれば\nかてる もの なの?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "{JPN}わあ ここって すっごく\n"
	.string "{JPN}おおきいのね!\p"
	.string "{JPN}くうきが はりつめてるわ...\nいなかの コンテストかいじょうとは\lぜんぜん ちがうのね.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "{JPN}MC: よし! かしこい ポケモン と\n"
	.string "{JPN}トレーナー の みなさん\l"
	.string "{JPN}じゅんび は いい ですか?!\p"
	.string "{JPN}さいこう の パフォーマンス を\nみせて ください!\lアピール スタート!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "{JPN}しんぱんいん: この コンテスト\n"
	.string "{JPN}たのしんで いただけ ましたか?\p"
	.string "{JPN}こんど は 3にん の おともだち と\nいっしょ に さんか して みて\lください ね!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "{JPN}あやややや...\n"
	.string "{JPN}まちがった コンテストに\l"
	.string "{JPN}さんか しちゃった.\p"
	.string "{JPN}この たくましい ポケモンを\n"
	.string "{JPN}かしこさコンテストに\l"
	.string "{JPN}だしちゃったのよ...\pさあ かしこそうに みえる\nいわくだきで みんなを\lびっくり させましょう.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "{JPN}わたし は ながい あいだ\n"
	.string "{JPN}ちえ を しぼって この ポケモン を\l"
	.string "{JPN}かしこく そだてて きました\p"
	.string "{JPN}そこら の わかぞう の ポケモン\n"
	.string "{JPN}なんか に は まけません よ\p"
	.string "{JPN}つま よ みて おれ!$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "{JPN}よし きた!\p"
	.string "{JPN}つぎ に わが ポケモン が\n"
	.string "{JPN}かしこい わざ を だせば\lかんきゃく の ねつき は\lさいこうちょう です!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "{JPN}あら たいへん!\p"
	.string "{JPN}かわいい ズバット の\n"
	.string "{JPN}すいとる が あまりに かわいくて\l"
	.string "{JPN}なんども つかって しまったの!\p"
	.string "{JPN}でも この ひとたち\nりかい して くれない のね!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "{JPN}きゃー! おじいちゃん\nうつくしい わ!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "{JPN}おなじ しゅるい の ポケモン でも\n"
	.string "{JPN}トレーナー が ちがう と\l"
	.string "{JPN}アピール で つかう わざ も\l"
	.string "{JPN}ちがって くる みたい だね\p"
	.string "{JPN}バトル で ひとり ひとり\nスタイル が ちがう のと\lおなじ だ ね$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "{JPN}ポケモン の ほう が\n"
	.string "{JPN}トレーナー より かしこそう に\lみえる ね ずっと$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "{JPN}やっぱり わたしは\n"
	.string "{JPN}かしこさコンテストが\l"
	.string "{JPN}dいすき.\p"
	.string "{JPN}あの ちてきな みどりいろ...\nとても... とても... かっこいいの.$"
LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "{JPN}MC: あなた も うつくしさ\n"
	.string "{JPN}コンテスト に さんか ですか?\lがんばって ください!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "{JPN}しんぱんいん: ああ ここ に いる\n"
	.string "{JPN}ポケモン は みんな\l"
	.string "{JPN}かんぺき な うつくしさ です ね!\pあやうく てんすう つける の を\nわすれる ところ でした!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "{JPN}これほど うつくしい ポケモン...\n"
	.string "{JPN}ほかには いないわ.\p"
	.string "{JPN}みんなの めが わたしの\n"
	.string "{JPN}うつくしさに くぎづけに\lなるでしょうね.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "{JPN}わああああん!\p"
	.string "{JPN}この コンテストのために\n"
	.string "{JPN}ていねいに ブラシを かけて\l"
	.string "{JPN}グルーミングしたのに...\p"
	.string "{JPN}やりすぎちゃった...\n"
	.string "{JPN}ポケモンの けが ぼさぼさに\lなっちゃったの...\pどうしよう?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "{JPN}この オーロラビームは\n"
	.string "{JPN}まぶしすぎて しんさいんには\l"
	.string "{JPN}みえないでしょうね.\p"
	.string "{JPN}あ ちょっと まって...\nそれじゃあ いみが ないじゃない!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "{JPN}この きれいな ポケモン\n"
	.string "{JPN}わたし の わかい ころ に\l"
	.string "{JPN}そっくり だわ\p"
	.string "{JPN}そう いった とたん しゅじん が\n"
	.string "{JPN}のんで いた コーヒー を\lふきだして しまったの\pなにか おかしい こと いった?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "{JPN}うつくしさ コンテスト で かつ と\n"
	.string "{JPN}うれしい の よ\l"
	.string "{JPN}いつも より ずっと ね$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "{JPN}わははは!\p"
	.string "{JPN}あの きれいな ポケモン たち を\n"
	.string "{JPN}みて みろ よ!\l"
	.string "{JPN}こういう はなやか な の が\lだいすき なんだ!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "{JPN}うつくしさ だけ じゃ\n"
	.string "{JPN}かてない ときも ある のよ\p"
	.string "{JPN}わたし の ポケモン みたいに\n"
	.string "{JPN}つやつや に みがいて\lそだてる こと が たいせつ ね$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "{JPN}MC: あ! こんにちは!\n"
	.string "{JPN}いま コンテスト の さいちゅう\l"
	.string "{JPN}なんです!\p"
	.string "{JPN}うけつけ で エントリー して から\nでて きて くださいね!$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "{JPN}しんぱんいん: ああ なんて\n"
	.string "{JPN}みりょくてき で かわいい\l"
	.string "{JPN}アピール でしょう!\p"
	.string "{JPN}まあ! なんて かんぺき な\nみずあそび の アピール!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "{JPN}ああ いやだ... わたしの\n"
	.string "{JPN}かわいい マリルが ほかの\lポケモンに きを とられてるわ.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "{JPN}わたし の ポケモン バトル じゃ\n"
	.string "{JPN}かった こと ない けど\nコンテスト なら まかせて!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "{JPN}わが ポケモン の はなびらのまい は\n"
	.string "{JPN}ゆうが その もの です\p"
	.string "{JPN}だれにも じゃま させません よ$"
	.string ""

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "{JPN}みんなの ポケモンは\n"
	.string "{JPN}とても かわいいわね.\p"
	.string "{JPN}でも もし わたしの ポケモンが\n"
	.string "{JPN}かわいい アピールを したら...\p"
	.string "{JPN}きっと ほかの こたちより\nずっと かわいく みえるはずよ.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "{JPN}わたし の こども が この\nコンテスト に でて います$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "{JPN}がんばれ! あなた の ポケモン が\n"
	.string "{JPN}いちばん よ!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "{JPN}あそこ の おんなのこ が\n"
	.string "{JPN}いちばん かわいい と おもう な\p"
	.string "{JPN}え? ポケモン の みため を\n"
	.string "{JPN}しんさ して るって?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "{JPN}うう こんなに かわいい ポケモン\n"
	.string "{JPN}みて たら じぶん も\l"
	.string "{JPN}ほしく なって きちゃった!\nつかまえ に いって くる!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "{JPN}うつくしさ コンテスト ステージ\n"
	.string "{JPN}うつくしい ポケモン に\lみとれて ください!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "{JPN}かわいさ コンテスト ステージ\n"
	.string "{JPN}かわいい ポケモンに\nみとれよう!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "{JPN}かしこさ コンテスト ステージ\n"
	.string "{JPN}かしこい ポケモンに\nかんどうしよう!$"

