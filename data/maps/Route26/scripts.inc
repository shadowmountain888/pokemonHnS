Route26_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "{JPN}ポケモンリーグへの\n"
	.string "{JPN}さいしゅうじゅんびを\nしているところだ$"

Route26_Text_CooltrainermJakeBeaten:
    .string "{JPN}しっぱいした!$"

Route26_Text_CooltrainermJakeAfter:
    .string "{JPN}リーグで かつのは\n"
	.string "{JPN}きびしそうだな\p"
    .string "{JPN}もっと しゅぎょうが\n"
	.string "{JPN}ひつようだ\p"
    .string "{JPN}リーグの してんのうは\nジムリーダーより\nつよいときいている$"

Route26_Text_CooltrainermGavenSeen:
    .string "{JPN}きびしい たたかいを\n"
	.string "{JPN}けいけんすることで\nちからが みにつく$"

Route26_Text_CooltrainermGavenBeaten:
    .string "{JPN}ぐあー! じんせいは\nもっと きびしい!$"

Route26_Text_CooltrainermGavenAfter:
    .string "{JPN}ポケモンリーグに いくには\n"
	.string "{JPN}チャンピオンロードを\n"
    .string "{JPN}とおらなければならない\p"
	.string "{JPN}だが チャンピオンロードは\nきびしいぞ\pほとんど だれも\nそこには いかない!$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "{JPN}ここまで きたきみは\n"
	.string "{JPN}つよいにちがいない\p"
    .string "{JPN}この たたかいに\n"
	.string "{JPN}すべてを かけるよ!$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "{JPN}いや! しんじられない!$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "{JPN}8にんの ジムリーダーを\n"
	.string "{JPN}たおしたから\n"
    .string "{JPN}じしんが あったのに\pこんどは もっと\nがんばらなきゃ$"

Route26_Text_CooltrainerfBethSeen:
    .string "{JPN}{RIVAL}っていう\n"
	.string "{JPN}トレーナーにまけちゃった.\p"
	.string "{JPN}かれはとてもつよかったけど...\p"
	.string "{JPN}ぜったいにかたなきゃいけない\n"
    .string "{JPN}っていうかんじだった.\pかれのポケモンが\nかわいそうになったの.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "{JPN}ポケモンは せんそうの\nどうぐじゃない$"

Route26_Text_CooltrainerfBethAfter:
    .string "{JPN}ポケモンは かけがえのない\n"
	.string "{JPN}いっしょうの パートナーよ$"

Route26_Text_PsychicRichardSeen:
    .string "{JPN}わあ たくさんの バッジ!\n"
	.string "{JPN}かんしんするね\p"
    .string "{JPN}でも ただ あつめるだけで\n"
	.string "{JPN}まんぞくしてないよね?$"

Route26_Text_PsychicRichardBeaten:
    .string "{JPN}いい たたかいだった!$"

Route26_Text_PsychicRichardAfter:
    .string "{JPN}ひとも ポケモンも\n"
	.string "{JPN}けいけんから せいちょうする\p"
    .string "{JPN}なまけて まんぞくしては\nいけないよ$"

Route26_Text_Sign:
    .string "{JPN}26ばんどうろ\p"
	.string "{JPN}ポケモンリーグ\n"
    .string "{JPN}うけつけゲート$"

