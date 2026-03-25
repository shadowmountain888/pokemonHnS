.set LOCALID_NURSE, 1

GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "{JPN}だいとしに すんでるのって\n"
	.string "{JPN}サイコーね!\l"
    .string "{JPN}あなたみたいに わかい\lトレーナーのころに ひっこして\lきたのよ!$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "{JPN}ここは とくべつな\n"
	.string "{JPN}ポケモンセンターなんだ.\lやねが きんで できてるんだよ!$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "{JPN}おにいちゃんに やねが\n"
	.string "{JPN}ほんものの きんで できてるって\l"
	.string "{JPN}いったんだ. なんでも\lしんじちゃうんだよね!$"

GoldenrodCity_PokemonCenter_LassText:
    .string "{JPN}レベルの たかい ポケモンが\n"
	.string "{JPN}いつも かつとは かぎらないの.\p"
    .string "{JPN}だって タイプで ふりに\n"
	.string "{JPN}なることも あるもの.\p"
    .string "{JPN}いちばん つよい ポケモンなんて\n"
	.string "{JPN}いないと おもうわ.$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "{JPN}{PLAYER}さんですね?\p"
	.string "{JPN}おめでとう ございます!\p"
    .string "{JPN}とくべつ サービスで\n"
	.string "{JPN}GSボールを おとどけしました!\p"
    .string "{JPN}どうぞ おうけとりください!$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "{JPN}また いらしてくださいね!$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "{JPN}まあ! おもい にもつね!\p"
	.string "{JPN}あら! もしかして\n"
    .string "{JPN}イーオンメールって いうもの\l"
	.string "{JPN}もってない?\p"
    .string "{JPN}むすめが ほしがってるのよ.\pひとつ ゆずってくれる?$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "{JPN}イーオンメールを わたす?$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "{JPN}あら! ステキ! ありがとう!\p"
	.string "{JPN}はい! これは おれいよ!$"
    .string ""

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "{JPN}むすめが よろこぶわ!$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "{JPN}あら? もってないの?\nざんねんね.$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "{JPN}ああ... そうですか.\nそれでは また こんど.$"
GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{JPN}{PLAYER}は イーオンメールを\nわたした.$"
