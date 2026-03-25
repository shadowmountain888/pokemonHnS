.set LOCALID_CURATOR, 1

LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad:
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
	copyvar VAR_GARBAGEVAR, 1
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
	.string "{JPN}ここが とくべつ てんじしつです$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
	.string "{JPN}ごらんのとおり ここには\n"
	.string "{JPN}えが いっぽんも\l"
	.string "{JPN}かざられていません.\p"
	.string "{JPN}ここでは いわゆる こてんてきな\n"
	.string "{JPN}げいじゅつさくひんを\l"
	.string "{JPN}かざるつもりは ありません.\p"
	.string "{JPN}そのような こてんさくひんは\n"
	.string "{JPN}1かいで みることが\l"
	.string "{JPN}できますから.\p"
	.string "{JPN}わたしが かざりたいのは\n"
	.string "{JPN}こてんとは まったく ちがう\l"
	.string "{JPN}さくひんです.\p"
	.string "{JPN}げいじゅつとは けっして ふるくて\n"
	.string "{JPN}ゆうめいな さくひんに\lかぎられるものでは ありません!\pこの てんじしつを みたしたいのは...\pモダンで いきいきとした\nポケモンの げいじゅつさくひん.\lまるで いますぐにも\lとびだしてきそうな さくひんを!$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
	.string "{JPN}しつれいしました.ひとりで\n"
	.string "{JPN}しゃべりすぎてしまいました.\p"
	.string "{JPN}さて あなたは わかいのに\n"
	.string "{JPN}あきらかに たびなれて\l"
	.string "{JPN}いらっしゃいますね...\p"
	.string "{JPN}いきいきとした ポケモンや\n"
	.string "{JPN}それを えがいた げいじゅつを\l"
	.string "{JPN}みかけることも あるでしょう.\p"
	.string "{JPN}もし そのような えに であったら\n"
	.string "{JPN}さっかの きょかを もらって\lここに てんじさせて\lいただけませんか?$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
	.string "{JPN}この てんじしつを\n"
	.string "{JPN}げんだいてきで いきいきした\l"
	.string "{JPN}ポケモンの えで みたしたいのです$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
	.string "{JPN}あなたの おかげで あたらしい\n"
	.string "{JPN}えを コレクションに くわえることが\l"
	.string "{JPN}できました!\p"
	.string "{JPN}あなたの ポケモンを えがいたものと\n"
	.string "{JPN}ききました すばらしい!\pほんとうに ほんとうに\nありがとうございます!$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
	.string "{JPN}あ! あなたは!\n"
	.string "{JPN}{PLAYER}さん!$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
	.string "{JPN}なんて すばらしいんでしょう!\n"
	.string "{JPN}この えの コレクション!\p"
	.string "{JPN}どれも かんぺきで\n"
	.string "{JPN}どれが いちばん なんて いえません!\p"
	.string "{JPN}これらの えが びじゅつかんに\n"
	.string "{JPN}もっと おきゃくさんを よんで\l"
	.string "{JPN}くれました\p"
	.string "{JPN}{PLAYER}さん\nしんけんに かんしゃいたします\lわたしの ゆめが かないました!$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
	.string "{JPN}これは わたしの かんしゃの\nきもちです$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
	.string "{JPN}つぎに おあいできるまで\n"
	.string "{JPN}おあずかりしておきます$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
	.string "{JPN}あ {PLAYER}さん!\n"
	.string "{JPN}おあいできて うれしいです!\p"
	.string "{JPN}おいそがしい たびのとちゅうで\n"
	.string "{JPN}おたちよりいただき こうえいです\p"
	.string "{JPN}どうぞ ごゆっくり\nおたのしみください$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
	.string "{JPN}ピンクいろの かざりが ついた\n"
	.string "{JPN}がくぶちだ$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
	.string "{JPN}きいろの かざりが ついた\n"
	.string "{JPN}がくぶちだ$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
	.string "{JPN}あおいろの かざりが ついた\n"
	.string "{JPN}がくぶちだ$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
	.string "{JPN}あかいろの かざりが ついた\n"
	.string "{JPN}がくぶちだ$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
	.string "{JPN}みどりいろの かざりが ついた\n"
	.string "{JPN}がくぶちだ$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
	.string "{JPN}ポケモンの えだ$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
	.string "{JPN}しばらく りゅうしゅしていたから\n"
	.string "{JPN}あたらしい えが あって びっくり\l"
	.string "{JPN}したよ.\p"
	.string "{JPN}だれか わたしの ポケモンも\nこんなに きれいに かいて\lくれないかなあ.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
	.string "{JPN}そうですか... ここが\n"
	.string "{JPN}はなだいの ポケモンの えを\l"
	.string "{JPN}てんじしている ばしょですね.\p"
	.string "{JPN}なるほど あたらしい えは\nたしかに なかなか\lおもしろいですね.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
	.string "{JPN}へえ そうなの?\n"
	.string "{JPN}この えは あなたの ポケモンなのね\p"
	.string "{JPN}トレーナーとして さいこうの\n"
	.string "{JPN}よろこびじゃない?$"

