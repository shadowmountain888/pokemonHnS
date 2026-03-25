.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "{JPN}ああ まいにち たいへん\n"
	.string "{JPN}なのよ...\p"
	.string "{JPN}なにが たいへんかって?\n"
	.string "{JPN}きかなくても わかるでしょ?\p"
	.string "{JPN}まいにち こんだてを\n"
	.string "{JPN}かんがえるのが たいへんなの.\p"
	.string "{JPN}まいにち しょくじの\nじゅんびって ほんと たいへん.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "{JPN}あ こんにちは!\n"
	.string "{JPN}ペッパーけに\l"
	.string "{JPN}ようこそ.\p"
	.string "{JPN}きみに しつもんが\n"
	.string "{JPN}あるんだ.\p"
	.string "{JPN}こどものおもりを\n"
	.string "{JPN}したことはある?\p"
	.string "{JPN}じつは わたし\n"
	.string "{JPN}はじめてのパパなんだ.\p"
	.string "{JPN}それで もんだいが\n"
	.string "{JPN}あるんだ.\p"
	.string "{JPN}むすめのワルダが\nあまりわらわないんだ.\pなにか おもしろいことを\nいえばわらってくれると\lおもうんだけど...\pなにかおもしろいことばや\nフレーズを\lしっているかい?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "{JPN}さいきん{STR_VAR_1}って\n"
	.string "{JPN}いってるんだけど...\p"
	.string "{JPN}もっといいことばや\n"
	.string "{JPN}フレーズをしらない?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "{JPN}おお それはすばらしい!\n"
	.string "{JPN}じゃあ きかせてくれ.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "{JPN}ああ そうなのか.\p"
	.string "{JPN}もしいいアイデアが\n"
	.string "{JPN}うかんだら\lぜひおしえてくれ.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "{JPN}なるほど.\n"
	.string "{JPN}じゃあ ためしてみよう.$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{JPN}{STR_VAR_1}.\n"
	.string "{JPN}{STR_VAR_1}.\p"
	.string "{JPN}おお!わらっているぞ!\n"
	.string "{JPN}わたしもうれしくて\lしかたがない!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "{JPN}なるほど.\n"
	.string "{JPN}じゃあ ためしてみよう.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{JPN}{STR_VAR_1}.\n"
	.string "{JPN}{STR_VAR_1}.\p"
	.string "{JPN}うーん... ぜんぜん\n"
	.string "{JPN}わらってくれないわね.\nワルダって まじめな\nこなのかしら...$"
RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "{JPN}あら いい ことばを\n"
	.string "{JPN}しらないのね.\n"
	.string "{JPN}じぶんで かんがえましょう.\p"
	.string "{JPN}うーん...\n"
	.string "{JPN}{STR_VAR_1}は\lどうかしら?\nうまくいくかしらね.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{JPN}{STR_VAR_1}.\n"
	.string "{JPN}{STR_VAR_1}.\p"
	.string "{JPN}うーん... ぜんぜん\n"
	.string "{JPN}わらってくれないわね.\nワルダって まじめな\nこなのかしら...$"
RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "{JPN}そうか いいことばを\n"
	.string "{JPN}しらないのか.\p"
	.string "{JPN}じゃあ まえにつかった\n"
	.string "{JPN}ことばでためしてみよう.\p"
	.string "{JPN}もしいいアイデアが\nうかんだら\lいつでもおしえてくれよ.$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "{JPN}ありがとう!\p"
	.string "{JPN}きみのおかげで\n"
	.string "{JPN}だいじなワルダが\l"
	.string "{JPN}わらってくれた!\p"
	.string "{JPN}じつは わたし\n"
	.string "{JPN}デボンコーポレーションの\l"
	.string "{JPN}トップけんきゅうしゃなんだ.\p"
	.string "{JPN}そのおれいに\n"
	.string "{JPN}なにかしてあげよう.\p"
	.string "{JPN}パソコンのポケモン\n"
	.string "{JPN}ボックスのかべがみを\l"
	.string "{JPN}ついかしてあげる.\p"
	.string "{JPN}かべがみメニューで\n"
	.string "{JPN}フレンドをえらんでみて.\p"
	.string "{JPN}あたらしいかべがみが\nつかえるようになるよ.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "{JPN}ポケモンのぬいぐるみだ!$"

