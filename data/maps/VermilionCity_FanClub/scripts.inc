.set LOCALID_FAN_CLUB_CLEFAIRY_DOLL, 5

VermilionCity_FanClub_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "{JPN}わたしは ポケモンファンクラブの\n"
	.string "{JPN}かいちょうです.\p"
	.string "{JPN}わたしは 150ひきいじょうの\n"
	.string "{JPN}ポケモンを そだててきました.\p"
	.string "{JPN}ポケモンに かんしては とても\n"
	.string "{JPN}うるさいんです.\p"
	.string "{JPN}わたしの ポケモンの はなしを\nききに きたのですか?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "{JPN}よし! それなら きいて くれ!\p"
	.string "{JPN}おれの だいすきな ギャロップ\n"
	.string "{JPN}なんだが...\p"
	.string "{JPN}そいつは... かわいくて... すてきで\n"
	.string "{JPN}... かしこくて...\l"
	.string "{JPN}たまらなく...\l"
	.string "{JPN}それに... すごくて... ああ...\l"
	.string "{JPN}きみも そう おもうだろう?...\l"
	.string "{JPN}すばらしすぎて... やせいてきで...\n"
	.string "{JPN}うつくしくて...\l"
	.string "{JPN}やさしくて...\l"
	.string "{JPN}あいしてる!\p"
	.string "{JPN}だきしめると... ねている ときに\n"
	.string "{JPN}... あたたかくて...\l"
	.string "{JPN}ふわふわで...\lああ... それに... みごとで...\lうっとりするほど... しんぴてき\nで...\pおっと! じかんを みろ!\nながく ひきとめて すまない!$"

PokemonFanClub_Text_Chairman_Gift:
	.string "{JPN}はなしを きいてくれて\n"
	.string "{JPN}ありがとう.\lこれを もっていきなさい!$"

PokemonFanClub_Text_Chairman_Candy:
	.string "{JPN}ポケモンを つよくする\n"
	.string "{JPN}ふしぎなアメです.\p"
	.string "{JPN}わたしは せんとうで ポケモンを\n"
	.string "{JPN}つよくするのが すきなので\l"
	.string "{JPN}あなたに あげましょう.$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "{JPN}やあ {PLAYER}!\p"
	.string "{JPN}また おれの ポケモンの はなし\n"
	.string "{JPN}を ききに きたのかい?\p"
	.string "{JPN}ちがう? ああ... まだまだ はな\n"
	.string "{JPN}したい ことが あったのに...$"
PokemonFanClub_Text_Chairman_Disappointed:
	.string "{JPN}ざんねんだ...\p"
	.string "{JPN}きく きが あったら また おい\nで.$"

PokemonFanClub_Text_Receptionist:
	.string "{JPN}かいちょうは ポケモンの ことに\n"
	.string "{JPN}なると ねっしんに なるんです...$"
@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "{JPN}ピッピが ゆびをふって\n"
	.string "{JPN}ゆびをふるを つかおうと\l"
	.string "{JPN}するときの すがたが だいすき!\p"
	.string "{JPN}とっても かわいいんだ!$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "{JPN}ピッピが だいすきなんだけど\n"
	.string "{JPN}つかまえられないんだ.\p"
	.string "{JPN}だから みつけた ピッピにんぎょうで\n"
	.string "{JPN}がまんしてるんだ.$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "{JPN}ああ そうか. この ポケモン\n"
	.string "{JPN}にんぎょうを なくした おんな\n"
	.string "{JPN}のこが かなしんでいるのか...\p"
	.string "{JPN}わかった. この ポケモン\n"
	.string "{JPN}にんぎょうを その かわいそうな\n"
	.string "{JPN}おんなのこに かえして くれる?\pおれは いつか ほんものの ピッ\nピを ともだちに するんだ.\nしんぱい いらない!$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "{JPN}みてろよ.ほんものの ピッピを\n"
	.string "{JPN}ともだちに するからな.$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "{JPN}わたしの かわいい ベイリーフを\n"
	.string "{JPN}みて!\pあたまの はっぱが とっても\nかわいいのよ!$"

PokemonFanClub_Text_ClefairyDoll:
	.string "{JPN}ピッピだ! あれ?\p"
	.string "{JPN}ああ そうか.ピッピの\n"
	.string "{JPN}ポケモンにんぎょうね.$"

PokemonFanClub_Text_Bayleef:
	.string "{JPN}ベイリーフ: リー フィー!$"

PokemonFanClub_Text_Listen:
	.string "{JPN}みんなで ほかの トレーナーの\n"
	.string "{JPN}はなしを しずかに ききましょう.$"

PokemonFanClub_Text_Bragging:
	.string "{JPN}だれかが じまんしたら\n"
	.string "{JPN}じまんしかえせ!$"
