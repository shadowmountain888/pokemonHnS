.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Engineer5::
	msgbox BattleFrontier_OutsideWest_Text_Reparations5, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer6::
	msgbox BattleFrontier_OutsideWest_Text_Reparations6, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer7::
	msgbox BattleFrontier_OutsideWest_Text_Reparations7, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer8::
	msgbox BattleFrontier_OutsideWest_Text_Reparations8, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_Reparations5:
	.string "{JPN}しゅうりは もうすぐ おわるよ.\p"
	.string "{JPN}カイリキーが おもい いわを\n"
    .string "{JPN}もちあげるのを てつだって\lくれて ほんとうに たすかった.$"

BattleFrontier_OutsideWest_Text_Reparations6:
    .string "{JPN}あしもとに きをつけて!\n"
	.string "{JPN}じめんが まだ ふあんていなんだ.\p"
    .string "{JPN}ワンリキーチームが がれきを\n"
	.string "{JPN}かたづけるのを てつだって\lくれて よかったよ.$"

BattleFrontier_OutsideWest_Text_Reparations7:
    .string "{JPN}しゅうりが おわるまでは\n"
	.string "{JPN}あの きのはしが ただひとつの\lわたりみちなんだ.$"

BattleFrontier_OutsideWest_Text_Reparations8:
    .string "{JPN}どうくつは まだ ふあんていなので\n"
	.string "{JPN}きでできた かりばしを つくったんだ.\p"
    .string "{JPN}じょうぶだと おもう...たぶん.$"
BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "{JPN}ここは バトルタワー!\n"
	.string "{JPN}さいきょうの トレーナーとして\l"
	.string "{JPN}れんしょうを つづけよう!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "{JPN}ここは バトルパレス!\n"
	.string "{JPN}ポケモンバトルに めを\lこらせ!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "{JPN}ここは バトルアリーナ!\n"
	.string "{JPN}さいきょうチームを\nあつめよう!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "{JPN}ここは バトルピラミッド!\n"
	.string "{JPN}バトルクエストを\nすすんでいこう!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "{JPN}バトルフロンティア ランキングホール\n"
	.string "{JPN}あたらしい きろくを\lめざそう!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "{JPN}バトルポイント こうかんサービスコーナー\n"
	.string "{JPN}バトルポイントを こうかんして\l"
	.string "{JPN}ほかの トレーナーと\lとりひきしよう!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "{JPN}わあ!\n"
	.string "{JPN}おおきいなあ!\p"
	.string "{JPN}バトルタワーって とくべつな\n"
	.string "{JPN}かんじがするよ.\lほかとは ちがうんだ.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "{JPN}おれの おおきな ゆめは\n"
	.string "{JPN}バトルフロンティアと ポケモンリーグの\l"
	.string "{JPN}りょうほうを せいはすることなんだ.\p"
	.string "{JPN}そして ゆめが かなったら...\p"
	.string "{JPN}となりの ミミちゃんに\n"
	.string "{JPN}ともだちに なってもらえるか\lきいてみるんだ!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "{JPN}バトルピラミッドは きびしすぎる!\n"
	.string "{JPN}てっぺんまで いけないよ!\p"
	.string "{JPN}もう ほかに ほうほうが ないから\n"
	.string "{JPN}そとがわを のぼってみようかな...$"
BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "{JPN}わたしは やみで いきている...\n"
	.string "{JPN}そう... わたしに ふさわしいのは?\l"
	.string "{JPN}バトルピラミッド いがいにない...\p"
	.string "{JPN}やみの なかを さまよい\n"
	.string "{JPN}ぜつぼうに くれることを\lどう おもう?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "{JPN}いっしゅうかん ねむらなかったけど\n"
	.string "{JPN}さいきょうの チームを\l"
	.string "{JPN}くみあげたぜ!\p"
	.string "{JPN}まける きが しないね \nほんとに.\lバトルアリーナに のりこむぞ!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "{JPN}エニシダが きみも ここに\n"
	.string "{JPN}つれてきたのかい?\p"
	.string "{JPN}ちがう?\p"
	.string "{JPN}でも きっと かれのことは\n"
	.string "{JPN}しってるよね!\p"
	.string "{JPN}あいつは いったい なんなんだ?\p"
	.string "{JPN}のうりょくの あるトレーナーを\n"
	.string "{JPN}みつけるのが うまいらしいが...\pじっさいに たたかっているのを\nみたことが ないんだ.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "{JPN}ジグザグマ!\n"
	.string "{JPN}きみを しんじてるよ \l"
	.string "{JPN}こいつ!\p"
	.string "{JPN}かったら すきな おいしい\nおやつを つくってあげるからね!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "{JPN}ジグザグマの めが\nうつろに みえる...$"
BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "{JPN}みんな わたしを おせっかいって\n"
	.string "{JPN}いうけど やめられないのよ.\p"
	.string "{JPN}ぼうしが まがってるわ!\n"
	.string "{JPN}あら ごみが おちてる!\l"
	.string "{JPN}あっ もう ゆうごはんの じかん!\p"
	.string "{JPN}バトルパレスで ただ みてるだけ\n"
	.string "{JPN}なんて たえられそうに ないわ...$"
BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "{JPN}いまは たいしたことないように\n"
	.string "{JPN}みえるかもしれないけど\l"
	.string "{JPN}むかし ジムリーダーに かったんだ.\p"
	.string "{JPN}もういちど えいこうに\nちょうせんしてみようかな.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "{JPN}じてんしゃも はやいし\n"
	.string "{JPN}バトルも はやいんだ.\p"
	.string "{JPN}しゅんかんで しょうぶを\n"
	.string "{JPN}きめるよ!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "{JPN}ぼく おとうさんより\n"
	.string "{JPN}ポケモンが じょうずなの.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "{JPN}いけ かわいい ぼうや!\n"
	.string "{JPN}パパのために かちまくって\l"
	.string "{JPN}おいで!\p"
	.string "{JPN}ママに そっくりだから\nつよいはずよ!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "{JPN}ここまで くるのは たいへん\n"
	.string "{JPN}だったけど バトルアリーナに\l"
	.string "{JPN}びじんがいるって きいてたんだ.\p"
	.string "{JPN}でも そのかわりに なにを\n"
	.string "{JPN}みつけたと おもう?\p"
	.string "{JPN}あせくさくて げんしてきな\n"
	.string "{JPN}ぶどうかの おおぜいの\lおとこたちだよ!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "{JPN}ときどき とても えらそうな\n"
	.string "{JPN}おじいさんが はいっていくのを\l"
	.string "{JPN}みるんだ.\p"
	.string "{JPN}すごい ポケモンを もってて\nやさしそうな ひとだよ.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "{JPN}しってるかい?\n"
	.string "{JPN}バトルピラミッドの でんせつを?\p"
	.string "{JPN}じしんまんまんの トレーナーが\n"
	.string "{JPN}おうごんの ちょうじょうを\l"
	.string "{JPN}めざすとき そこに ひとりの\l"
	.string "{JPN}だんせいが あらわれる.\p"
	.string "{JPN}その でんせつを しらない?\n"
	.string "{JPN}あたりまえだよ!\l"
	.string "{JPN}いま でっちあげたんだから!\p"
	.string "{JPN}どういう いみかって?\nそれは わからないなあ!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "{JPN}まいったなあ! おお まいった!\n"
	.string "{JPN}いままで いちども まけた\l"
	.string "{JPN}ことなかったのに!\p"
	.string "{JPN}ぜんぜん いいところなしで\n"
	.string "{JPN}やられちゃったよ!\p"
	.string "{JPN}それで さいのうが ないって\nいわれるし! まいったなあ!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "{JPN}こいつは バトルタワーで\n"
	.string "{JPN}とんでもなく つよい トレーナーに\l"
	.string "{JPN}であったらしいぜ.\p"
	.string "{JPN}それで こんなふうに...\n"
	.string "{JPN}バトルタワーに いくときは\n"
	.string "{JPN}ちゅういが ひつようだな.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "{JPN}やった!\n"
	.string "{JPN}ついに じゅうぶんな\l"
	.string "{JPN}バトルポイントが たまった!\p"
	.string "{JPN}また おおきな ぬいぐるみと\nこうかんしようかな!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "{JPN}おお そうか!\n"
	.string "{JPN}ここが ランキングホール\n"
	.string "{JPN}なんだな!\p"
	.string "{JPN}すーぱーちゃんぴおんとして\n"
	.string "{JPN}れきしに なまえを のこして\lこうせいに つたえたいなあ.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "{JPN}きみが そばにいれば\nなんでも できるよ.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "{JPN}ああ だーりん きみって\n"
	.string "{JPN}ほんとうに すてきなの!\p"
	.string "{JPN}もう まちきれないわ!\p"
	.string "{JPN}いますぐ マルチバトルルームに\n"
	.string "{JPN}いきましょう!\p"
	.string "{JPN}バトルサロンで いっしょになれば\n"
	.string "{JPN}わたしたちの あいの ちからで\l"
	.string "{JPN}みんなに かてるわ.\p"
	.string "{JPN}わたしたちの まえでは だーりん \nすべてが ドミノのように\lたおれていくのよ!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "{JPN}バトルフロンティアは つよい\n"
	.string "{JPN}トレーナーだけの ものじゃない.\p"
	.string "{JPN}とくべつな のうりょくを もった\n"
	.string "{JPN}ひとたちも しょうたいされてる\l"
	.string "{JPN}ようだね.\n"
	.string "{JPN}エニシダという おとこ...\n"
	.string "{JPN}もっと おおきな もくてきの ために\nここを つくったのかも しれない...$"
BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "{JPN}すまんが わかいの.\n"
	.string "{JPN}めは よいかね?\p"
	.string "{JPN}ここの さきに へんな きがあって\n"
	.string "{JPN}わしの つかれた めには\lゆれて みえるのじゃが.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "{JPN}すみません わかいかた.\n"
	.string "{JPN}きおくりょくは よいですか?\p"
	.string "{JPN}このさきに むかし\n"
	.string "{JPN}へんなきが あったような\lきがするのですが.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "{JPN}ぼ... ぼくは みたんだ!\p"
	.string "{JPN}ながい しっぽの ねばねばした\n"
	.string "{JPN}ポケモンが むこうに いた!\p"
	.string "{JPN}iわの したに かくれて\n"
	.string "{JPN}じっと こっちを みてたんだ!$"
	.string ""
