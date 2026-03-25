BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "{JPN}やあやあ! バトルフロンティアの\n"
	.string "{JPN}じょうほうなら おれが いちばんさ.\p"
	.string "{JPN}おれのことは\n"
	.string "{JPN}フロンティアマニアとでも\l"
	.string "{JPN}よんでくれ.\p"
	.string "{JPN}ちょっと かくにんするけど\n"
	.string "{JPN}きみは トレーナーだよね?\p"
	.string "{JPN}バトルフロンティアで あつめた\nあついじょうほうを きょうゆう\lするよ!$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "{JPN}やあやあ! さいしんじょうほうを\n"
	.string "{JPN}ききに きたのかい? よし!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "{JPN}どうだい? どうだい? どうだい?\p"
	.string "{JPN}おれの じょうほうは\n"
	.string "{JPN}やくに たっているだろう?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "{JPN}そうですね...\p"
	.string "{JPN}{STR_VAR_1}が\n"
	.string "{JPN}いちばんあついばしょの\nようですね$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "{JPN}そうですね...\p"
	.string "{JPN}バトルタワー{STR_VAR_1}が\n"
	.string "{JPN}いちばんあついようです$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "{JPN}これ しってた?\p"
	.string "{JPN}エニシダが フロンティアブレーン\n"
	.string "{JPN}とよぶ トップトレーナーが\l"
	.string "{JPN}そこにいるんだ.\p"
	.string "{JPN}その ばしょを しきっているのは\nサロンメイデンという\lしんぴてきな トレーナーなんだ.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "{JPN}サロンメイデンと たたかったこと\n"
	.string "{JPN}ある?\p"
	.string "{JPN}あいてを はかっているときは\n"
	.string "{JPN}こんな ポケモンを つかうらしい:\p"
	.string "{JPN}エスパータイプの ねんりき ポケモン \n"
	.string "{JPN}ほのおタイプの かざん ポケモン \lそして ノーマルタイプの ねむり\lポケモンさ.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "{JPN}サロンメイデンが ほんきのとき\n"
	.string "{JPN}たたかったこと ある?\p"
	.string "{JPN}ぜんりょくで たたかうときは\n"
	.string "{JPN}こんな ポケモンを つかうらしい:\p"
	.string "{JPN}ドラゴン エスパータイプの むげん\l"
	.string "{JPN}ポケモン でんきタイプの かみなり\l"
	.string "{JPN}ポケモン そして ノーマルタイプの\lねむり ポケモンさ.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "{JPN}これ しってた?\p"
	.string "{JPN}エニシダが フロンティアブレーン\n"
	.string "{JPN}とよぶ トップトレーナーが\l"
	.string "{JPN}そこにいるんだ.\p"
	.string "{JPN}その ばしょを しきっているのは\nドームエースという\lはでな トレーナーなんだ.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "{JPN}ドームエースと たたかったこと\n"
	.string "{JPN}ある?\p"
	.string "{JPN}あいてを かるく みているときは\n"
	.string "{JPN}この 3ひきを つかう:\p"
	.string "{JPN}ドラゴン ひこうタイプの ドラゴン\l"
	.string "{JPN}ポケモン みず じめんタイプの\lどろうお ポケモン そして\lほのお ひこうタイプの かえん\lポケモンさ.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "{JPN}ドームエースが ほんきのとき\n"
	.string "{JPN}たたかったこと ある?\p"
	.string "{JPN}せんじゅつを みせつけるときは\n"
	.string "{JPN}この 3ひきを つかう:\p"
	.string "{JPN}ドラゴン ひこうタイプの むげん\l"
	.string "{JPN}ポケモン みず じめんタイプの\l"
	.string "{JPN}どろうお ポケモン そして\l"
	.string "{JPN}はがね エスパータイプの てつあし\lポケモンさ.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "{JPN}これ しってた?\p"
	.string "{JPN}エニシダが フロンティアブレーン\n"
	.string "{JPN}とよぶ トップトレーナーが\l"
	.string "{JPN}そこにいるんだ.\p"
	.string "{JPN}その ばしょを しきっているのは\nファクトリーヘッドという\lきみょうな トレーナーなんだ.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "{JPN}ファクトリーヘッドと\n"
	.string "{JPN}たたかったことはありますか?\p"
	.string "{JPN}そうですね... かれがたたかうとき\n"
	.string "{JPN}レンタルポケモンを 3ひきだけ\n"
	.string "{JPN}もらうんです\p"
	.string "{JPN}きみとほぼおなじじょうけんで\nたたかっているんですよ$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "{JPN}ファクトリーヘッドが ほんきの\n"
	.string "{JPN}とき たたかったこと ある?\p"
	.string "{JPN}ほんきで たたかうときでも\n"
	.string "{JPN}かれは 3ひきの レンタル\l"
	.string "{JPN}ポケモンを もらうんだ.\n"
	.string "{JPN}きみと ほとんど おなじ\nじょうけんで たたかうのさ.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "{JPN}これ しってた?\p"
	.string "{JPN}エニシダが フロンティアブレーン\n"
	.string "{JPN}とよぶ トップトレーナーが\l"
	.string "{JPN}そこにいるんだ.\p"
	.string "{JPN}その ばしょを しきっているのは\nチューブクイーンという\lこわい トレーナーなんだ.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "{JPN}チューブクイーンと まえに\n"
	.string "{JPN}たたかったこと ある?\p"
	.string "{JPN}きげんが いいときは\n"
	.string "{JPN}この 3ひきを つかうらしい:\p"
	.string "{JPN}どくタイプの きばへび ポケモン \n"
	.string "{JPN}むし いわタイプの かび ポケモン \l"
	.string "{JPN}そして みずタイプの やさしい\lポケモンさ.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "{JPN}チューブクイーンが ほんきの\n"
	.string "{JPN}とき たたかったこと ある?\p"
	.string "{JPN}ほんとうに おこっているときは\n"
	.string "{JPN}この 3ひきを つかうらしい:\p"
	.string "{JPN}どくタイプの きばへび ポケモン \n"
	.string "{JPN}はがね じめんタイプの てつへび\l"
	.string "{JPN}ポケモン そして みず ひこう\l"
	.string "{JPN}タイプの きょうあく ポケモンさ.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "{JPN}これ しってた?\p"
	.string "{JPN}エニシダが フロンティアブレーン\n"
	.string "{JPN}とよぶ トップトレーナーが\l"
	.string "{JPN}そこにいるんだ.\p"
	.string "{JPN}その ばしょを しきっているのは\nアリーナキャプテンという\lかわいい トレーナーなんだ.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "{JPN}アリーナキャプテンと まえに\n"
	.string "{JPN}たたかったこと ある?\p"
	.string "{JPN}てきの のうりょくを はんだん\n"
	.string "{JPN}しているときは こんな ポケモンを\l"
	.string "{JPN}つかうらしい:\p"
	.string "{JPN}むし かくとうタイプの ひとつの\l"
	.string "{JPN}ポケモン あくタイプの げっこう\lポケモン そして むし ゴースト\lタイプの ぬけがら ポケモンさ.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "{JPN}アリーナキャプテンが ほんきの\n"
	.string "{JPN}とき たたかったこと ある?\p"
	.string "{JPN}ほんきで たたかうときは\n"
	.string "{JPN}こんな ポケモンを つかうらしい:\p"
	.string "{JPN}あくタイプの げっこう ポケモン \n"
	.string "{JPN}ゴースト どくタイプの かげ\l"
	.string "{JPN}ポケモン そして くさ かくとう\l"
	.string "{JPN}タイプの キノコ ポケモンさ.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "{JPN}これ しってた?\p"
	.string "{JPN}エニシダが フロンティアブレーン\n"
	.string "{JPN}とよぶ トップトレーナーが\l"
	.string "{JPN}そこにいるんだ.\p"
	.string "{JPN}その ばしょを しきっているのは\nパレスガーディアンという\lぶきみな トレーナーなんだ.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "{JPN}パレスガーディアンと まえに\n"
	.string "{JPN}たたかったこと ある?\p"
	.string "{JPN}あいての こころを ためすとき\n"
	.string "{JPN}こんな ポケモンを つかうらしい:\p"
	.string "{JPN}どく ひこうタイプの コウモリ\l"
	.string "{JPN}ポケモン ノーマルタイプの\l"
	.string "{JPN}なまけ ポケモン そして みず \lこおりタイプの うんぱん ポケモン\lさ.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "{JPN}パレスガーディアンが ほんきの\n"
	.string "{JPN}とき たたかったこと ある?\p"
	.string "{JPN}ぜんりょくを たたかいに そそぐ\n"
	.string "{JPN}ときは こんな ポケモンを\l"
	.string "{JPN}つかうらしい:\p"
	.string "{JPN}ほのおタイプの でんせつ ポケモン \n"
	.string "{JPN}ノーマルタイプの なまけ ポケモン \lそして みずタイプの オーロラ\lポケモンさ.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "{JPN}これ しってた?\p"
	.string "{JPN}エニシダが フロンティアブレーン\n"
	.string "{JPN}とよぶ トップトレーナーが\l"
	.string "{JPN}そこにいるんだ.\p"
	.string "{JPN}その ばしょを しきっているのは\nピラミッドキングという\nあつい トレーナーなんだ.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "{JPN}ピラミッドキングと まえに\n"
	.string "{JPN}たたかったこと ある?\p"
	.string "{JPN}てきの ちからを たしかめる\n"
	.string "{JPN}ときは こんな ポケモンを\l"
	.string "{JPN}つかうらしい:\p"
	.string "{JPN}いわタイプの がんせき ポケモン \n"
	.string "{JPN}こおりタイプの ひょうざん\lポケモン そして はがねタイプの\lてつ ポケモンさ.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "{JPN}ピラミッドキングが ほんきの\n"
	.string "{JPN}とき たたかったこと ある?\p"
	.string "{JPN}あつい パワーで もりあがって\n"
	.string "{JPN}いるときは こんな ポケモンを\l"
	.string "{JPN}つかうらしい:\n"
	.string "{JPN}こおり ひこうタイプの フリーズ\l"
	.string "{JPN}ポケモン でんき ひこうタイプの\l"
	.string "{JPN}でんき ポケモン そして ほのお \lひこうタイプの かえん ポケモン\lさ.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "{JPN}たしかに ダブルバトルが\n"
	.string "{JPN}できる ばしょは いくつかある.\p"
	.string "{JPN}でも バトルタワーの\n"
	.string "{JPN}ダブルバトルルームは きほん\l"
	.string "{JPN}ちゅうの きほんさ!\p"
	.string "{JPN}バトルフロンティアでの\n"
	.string "{JPN}ダブルバトルの やりかたを\lまなぶなら そこが いちばんだ.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "{JPN}ここでの たたかいは きを\n"
	.string "{JPN}つけろよ.\p"
	.string "{JPN}ダブルバトル せんよう の\n"
	.string "{JPN}せんじゅつを かいはつした\lトレーナーが いるって きいたぞ.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "{JPN}ここでのダブルバトルに\n"
	.string "{JPN}じしんがもててきたら\l"
	.string "{JPN}ほかのばしょの\l"
	.string "{JPN}ダブルバトルにも\lちょうせんしてみたらどう?$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "{JPN}バトルサロンには\n"
	.string "{JPN}いろんなトレーナーが\l"
	.string "{JPN}あつまってくるのよ\p"
	.string "{JPN}ともだちやフォロワーに\n"
	.string "{JPN}であえるかもしれないわ!\lよくみてみなさい!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "{JPN}ともだちといっしょなら\n"
	.string "{JPN}つうしんマルチバトルルームへ\l"
	.string "{JPN}いってみなさい\p"
	.string "{JPN}つよいともだちといっしょなら\nきょうてきにであえるはずよ!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "{JPN}すごいじょうほうしゅうしゅう\n"
	.string "{JPN}りょく!\nしししょうはさいこうです!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "{JPN}すごいかんさつりょく!\n"
	.string "{JPN}しししょうはさいこうです!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "{JPN}すごいせっとくりょく!\n"
	.string "{JPN}しししょうはさいこうです!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "{JPN}...ここはなんのばしょ?\n"
	.string "{JPN}こわいよ...$"
