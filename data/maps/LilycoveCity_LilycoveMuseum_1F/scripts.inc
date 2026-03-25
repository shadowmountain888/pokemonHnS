.set LOCALID_CURATOR, 2
.set LOCALID_ARTIST_2, 8

LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "{JPN}ミナモびじゅつかんへ\n"
	.string "{JPN}ようこそ.\p"
	.string "{JPN}ポケモンをテーマにした\n"
	.string "{JPN}すばらしいさくひんを\lゆっくりとおたのしみ\lください.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "{JPN}わたしはこのびじゅつかんの\n"
	.string "{JPN}かんちょうです.\p"
	.string "{JPN}こんなにもわかいあなたが\n"
	.string "{JPN}びじゅつかんにきてくれて\l"
	.string "{JPN}うれしいですよ.\p"
	.string "{JPN}もうかいがのコレクションは\nごらんになりましたか?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "{JPN}あ それではおじゃましません.\n"
	.string "{JPN}どうぞごゆっくりと.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "{JPN}おや? あなたは\n"
	.string "{JPN}ポケモントレーナーの\l"
	.string "{JPN}ようですね.\p"
	.string "{JPN}かいがにもきょうみが\nおありですか?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "{JPN}そうですか...\p"
	.string "{JPN}それなのに わざわざ おこしくださって\n"
	.string "{JPN}ありがとうございます.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "{JPN}ああ すばらしい!\n"
	.string "{JPN}かいががおすきなのですね!\p"
	.string "{JPN}では いっしょに\nきてもらえませんか?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "{JPN}とてもふるいかいがだ.\n"
	.string "{JPN}とこどころえのぐが\lはがれている.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "{JPN}きみょうでふしぎな\n"
	.string "{JPN}けしきがえがかれた\lかいがだ.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "{JPN}うつくしくほほえむじょせいが\n"
	.string "{JPN}ポケモンをひざにのせて\lいるかいがだ.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "{JPN}はるかむかしの\n"
	.string "{JPN}でんせつのポケモンが\l"
	.string "{JPN}えがかれている.\p"
	.string "{JPN}がかはそうぞうで\nこのえをかいたのだ.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "{JPN}かぜにゆれる\n"
	.string "{JPN}くさタイプのポケモンが\l"
	.string "{JPN}えがかれている.\p"
	.string "{JPN}やさしいかぜのあいぶを\nたのしんでいるようだ.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "{JPN}おいしそうなきのみの\n"
	.string "{JPN}かいがだ.\p"
	.string "{JPN}このえをみていると\nおなかがすいてきそうだ!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "{JPN}ゆうめいなちょうこくの\n"
	.string "{JPN}レプリカだ.\pこだいのとりポケモンが\nえがかれている.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "{JPN}くろいいしでつくられた\n"
	.string "{JPN}おおきなモンスターボールだ.\p"
	.string "{JPN}むかしはおまつりで\n"
	.string "{JPN}つかわれていたらしい.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "{JPN}おおきないしのばんに\n"
	.string "{JPN}ポケモンとこまかい\l"
	.string "{JPN}こだいもじがびっしりと\l"
	.string "{JPN}きざまれているが\lよめない.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "{JPN}うーん...\n"
	.string "{JPN}なんて すばらしい さくひんでしょう...$"
LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "{JPN}ポケモンとのバトルも\n"
	.string "{JPN}たのしいでしょうが\p"
	.string "{JPN}びじゅつへのあいも\n"
	.string "{JPN}わすれてはいけませんよ.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "{JPN}この びじゅつかんは... すてきな\n"
	.string "{JPN}かいがを たくさん みることが できます.\p"
	.string "{JPN}そして かんちょうさんも\n"
	.string "{JPN}すばらしい かたです.\p"
	.string "{JPN}わたしのような げいじゅつかにとって\nこの びじゅつかんは れいかんの みなもとです.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "{JPN}このおねえさん きれい!\n"
	.string "{JPN}ママみたい!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "{JPN}このポケモンかわいい!\n"
	.string "{JPN}うちのぼうやみたい!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "{JPN}このびじゅつかんに\n"
	.string "{JPN}あたらしいかいががきたって\l"
	.string "{JPN}きいたんです.\p"
	.string "{JPN}それで いそいで\n"
	.string "{JPN}やってきたんですよ.\pあたらしいかいがは\n2かいにかざってあるんですか?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "{JPN}さいきん かんちょうさんが\n"
	.string "{JPN}めずらしくごきげんなんです.\p"
	.string "{JPN}なにかいいことが\n"
	.string "{JPN}あったんでしょうね.\lきっと.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "{JPN}ここでたくさんの\n"
	.string "{JPN}すばらしいかいがをみて\l"
	.string "{JPN}べんきょうしたいんです.\p"
	.string "{JPN}いつかわたしのさくひんも\nここにかざってもらうのが\lyめなんです.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "{JPN}びじゅつかんは にんきの\n"
	.string "{JPN}かんこうちに なったんだ.\p"
	.string "{JPN}ミナモシティに とって...\n"
	.string "{JPN}いや  ホウエンちほう ぜんたいに とって すばらしいことだよ!\p"
	.string "{JPN}きいた はなしだと ひとりの トレーナーが\n"
	.string "{JPN}2かいの かいがを ぜんぶ あつめたらしい.$"

